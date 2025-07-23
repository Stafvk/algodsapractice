using namespace std;
#include<string>
#include<stdio.h>
#include<iostream>
enum class VehicleType{
    CAR, MOTORCYCLE,TRUCK,BUS
};
class Vehicle{
    string licensePlate;
    VehicleType type;
    string color;
public: Vehicle( string licensePlate,
    VehicleType type,
    string color): licensePlate(licensePlate),
    type(type),
    color(color){}

    string getLicensePlate(){
        return licensePlate;
    }
      VehicleType getType(){
        return type;
    }
      string getColor(){
        return color;
    }

    void displayInfo(){
        cout<<"Vehicle:"<<color<<" ";
        switch(type){
case VehicleType::BUS:cout<<"Bus";break;
case VehicleType::CAR:cout<<"Car";break;
case VehicleType::TRUCK:cout<<"Truck";break;
case VehicleType::MOTORCYCLE:cout<<"Motorcycle";break;

        }
        cout<<"License:"<<licensePlate<<endl;
    }
};
enum class SpotType{
    COMPACT, REGULAR, LARGE
};

class ParkingSpot{
    int spotNumber;
    Vehicle* vehicle;
    bool available;
    SpotType type;

    public:
    ParkingSpot(int spotNumber,
    SpotType type):spotNumber(spotNumber),
    vehicle(nullptr),
    available(true),
     type(type){}
     
     bool canFitVehicle(Vehicle* vehicle){
        if(!vehicle) return false;
        switch(vehicle->getType()){
            case VehicleType::MOTORCYCLE:
            return true;
            case VehicleType::CAR:
            return type !=SpotType::COMPACT;
            case VehicleType::BUS:
            case VehicleType::TRUCK:
            return type==SpotType::LARGE;
        }
 return false;
        }
        bool parkVehicle(Vehicle* vehicle){
if(!available || !canFitVehicle(vehicle)) return false;

this->vehicle=vehicle;
available=false;
return true;
        }

        Vehicle* removeVehicle(){
            if(!vehicle) return nullptr;
            
            available=true;

        }
     };
     class ParkingSpot{
        int capacity;
        int avaibaleSpots;
        ..
        ..
        
     };
