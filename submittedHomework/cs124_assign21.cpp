#include <iostream>
#include <iomanip>
using namespace std;

// block 1
int promptDevalue(int cost){
return 0;
}

int promptInsurance(int cost){
return 0;
}

int promptParking(int cost){
return 0;
}
int getPeriodicCost(int costPeriodic, int cost){
 promptDevalue(cost);
 promptInsurance(cost);
 promptParking(cost);
return 0;
}
// block 2
int promptMileage(int mileage){
return 0;
}

int promptGas(int cost){
return 0;
}

int promptRepairs(int cost){
return 0;
}

int promptTires(int cost){
return 0;
}

int getUsageCost(int costUsage, int cost ,int mileage){
   promptMileage(mileage);
   promptGas(cost);
   promptRepairs(cost);
   promptTires(cost);
   return 0;
}
// display part
void display (int costUsage, int costPeriodic){
cout << "Success\n";
}


// main part
int main(){
int costUsage;
int costPeriodic;
display(costUsage,costPeriodic);
return 0;
}