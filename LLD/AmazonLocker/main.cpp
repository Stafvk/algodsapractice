#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/*
 * Enum to represent Locker Size
 * Used for both Lockers and Packages
 */
enum class LockerSize {
    SMALL = 0,
    MEDIUM = 1,
    LARGE = 2
};

/*
 * Package Class: Represents a delivery package
 */
class Package {
private:
    string id;
    LockerSize size;

public:
    Package(string id, LockerSize size) {
        this->id = id;
        this->size = size;
    }

    string getId() const {
        return id;
    }

    LockerSize getSize() const {
        return size;
    }
};

/*
 * Locker Class: Represents a single locker
 */
class Locker {
private:
    string id;
    LockerSize size;
    bool occupied;
    Package* storedPackage;

public:
    Locker(string id, LockerSize size) {
        this->id = id;
        this->size = size;
        this->occupied = false;
        this->storedPackage = nullptr;
    }

    string getId() const {
        return id;
    }

    LockerSize getSize() const {
        return size;
    }

    bool isOccupied() const {
        return occupied;
    }

    bool canFit(LockerSize packageSize) const {
        // Convert enum to int to compare sizes (SMALL < MEDIUM < LARGE)
        int lockerSizeValue = static_cast<int>(this->size);
        int packageSizeValue = static_cast<int>(packageSize);

        if (lockerSizeValue >= packageSizeValue) {
            return true;
        } else {
            return false;
        }
    }

    bool assignPackage(Package* package) {
        if (this->occupied == false && this->canFit(package->getSize()) == true) {
            this->storedPackage = package;
            this->occupied = true;
            return true;
        } else {
            return false;
        }
    }

    void removePackage() {
        this->storedPackage = nullptr;
        this->occupied = false;
    }

    Package* getStoredPackage() const {
        return this->storedPackage;
    }
};

/*
 * LockerManager: Controls the assignment and pickup logic.
 */
class LockerManager {
private:
    // Group lockers by size for easier lookup
    // unordered_map is chosen for O(1) average-time access by LockerSize
    unordered_map<LockerSize, vector<Locker*>> lockersBySize;

    // Maps package ID to the Locker storing it
    // unordered_map is used for fast lookup on package ID
    unordered_map<string, Locker*> packageToLockerMap;

public:
    void addLocker(Locker* locker) {
        LockerSize size = locker->getSize();

        // If no entry for this size exists, create an empty vector first
        if (lockersBySize.find(size) == lockersBySize.end()) {
            lockersBySize[size] = vector<Locker*>();
        }

        lockersBySize[size].push_back(locker);
    }

    string assignLockerToPackage(Package* package) {
        LockerSize packageSize = package->getSize();

        // Try fitting into smallest possible locker that can accommodate this package
        for (int i = static_cast<int>(packageSize); i <= static_cast<int>(LockerSize::LARGE); i++) {
            LockerSize currentSize = static_cast<LockerSize>(i);

            if (lockersBySize.find(currentSize) != lockersBySize.end()) {
                vector<Locker*>& lockerList = lockersBySize[currentSize];

                for (int j = 0; j < lockerList.size(); j++) {
                    Locker* locker = lockerList[j];

                    if (locker->isOccupied() == false) {
                        bool assigned = locker->assignPackage(package);

                        if (assigned == true) {
                            packageToLockerMap[package->getId()] = locker;
                            cout << "Assigned Package " << package->getId()
                                 << " to Locker " << locker->getId() << endl;
                            return locker->getId();
                        }
                    }
                }
            }
        }

        // No locker was available
        cout << "No locker available for Package " << package->getId() << endl;
        return "";
    }

    bool pickupPackage(string packageId) {
        // Check if this package is mapped to a locker
        if (packageToLockerMap.find(packageId) != packageToLockerMap.end()) {
            Locker* locker = packageToLockerMap[packageId];
            locker->removePackage();
            packageToLockerMap.erase(packageId);

            cout << "Picked up Package " << packageId
                 << " from Locker " << locker->getId() << endl;

            return true;
        } else {
            cout << "Package " << packageId << " not found in any locker." << endl;
            return false;
        }
    }

    string getLockerForPackage(string packageId) {
        if (packageToLockerMap.find(packageId) != packageToLockerMap.end()) {
            Locker* locker = packageToLockerMap[packageId];
            return locker->getId();
        } else {
            return "Not found";
        }
    }
};

/*
 * Main function for demo/testing
 */
int main() {
    LockerManager manager;

    // Create lockers (normally would come from config or database)
    Locker l1("L1", LockerSize::SMALL);
    Locker l2("L2", LockerSize::MEDIUM);
    Locker l3("L3", LockerSize::LARGE);

    // Register lockers with manager
    manager.addLocker(&l1);
    manager.addLocker(&l2);
    manager.addLocker(&l3);

    // Create packages
    Package p1("P1", LockerSize::SMALL);
    Package p2("P2", LockerSize::MEDIUM);
    Package p3("P3", LockerSize::LARGE);
    Package p4("P4", LockerSize::LARGE);  // This will fail because no more large lockers

    // Assign lockers
    manager.assignLockerToPackage(&p1);  // Should go to L1
    manager.assignLockerToPackage(&p2);  // Should go to L2
    manager.assignLockerToPackage(&p3);  // Should go to L3
    manager.assignLockerToPackage(&p4);  // Should print "No locker available"

    // Try to pickup and reassign
    manager.pickupPackage("P2");

    Package p5("P5", LockerSize::MEDIUM);
    manager.assignLockerToPackage(&p5);  // Should reuse L2

    return 0;
}
