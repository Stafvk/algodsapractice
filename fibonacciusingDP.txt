#include<iostream>
#include <vector>
using namespace std;

int helper(vector <int> &dp,int n){
  // for(int i:dp)cout<<i;
  if(n<=1){
   return n;
  // cout<<"n th value\n"<<dp[n];
  }
  if(dp[n]!=-1){
    return dp[n];
  }

dp[n]= helper(dp,n-1)+helper(dp,n-2);
return dp[n];
}
    int fibonacci(int n){
    vector <int> dp(n+1,-1);
       return helper(dp,n);
     
    }
int main(){
    int final=fibonacci(6);
    cout<<"fibonacci is"<<final;
}