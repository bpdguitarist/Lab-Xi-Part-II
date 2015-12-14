//
//  Lab Xi Part II
//
//  Created by Edgar Esparza on 7/15/15.
//

#include <iostream>
#include <cmath>
using namespace std;

struct worker
{   int idNumber;
    int hoursWorked;
    double hourlyRate;
    double earned;
};             //<---NOTICE ";" after {BLOCK }

double income(worker);
void print(worker);
worker input();
int overtime(worker [], int);

int main() {
    int OLW;
    worker employee[3];
    for(int i=0;i<3;i++)
        employee[i]=input();
    for(int i=0;i<3;i++)
        employee[i].earned=income(employee[i]);
    for(int i=0;i<3;i++)
        print(employee[i]);
    OLW=overtime(employee,3);
    cout<<"Number of workers with overtime is: "<<OLW<<endl;
    
    return 0;
}

worker input(){
    worker temp;
    cout<<"Please enter the worker's ID number: ";
    cin >>temp.idNumber;
    cout<<"How many hours did the worker work: ";
    cin >>temp.hoursWorked;
    cout<<"How much does the worker make an hour: ";
    cin >>temp.hourlyRate;
    return temp;
}

double income(worker Edgar){
    if(Edgar.hoursWorked<=40){
        Edgar.earned=Edgar.hourlyRate*Edgar.hoursWorked;
        return Edgar.earned;
    }else{
            Edgar.earned=(Edgar.hourlyRate*40+(Edgar.hourlyRate*1.5*(Edgar.hoursWorked-40)));
            return Edgar.earned;
        }
    
}
void print(worker employee){
    cout<<"Worker ID: "<<employee.idNumber<<endl;
    cout<<"Hours worked: "<<employee.hoursWorked<<endl;
    cout<<"Hourly Rate: "<<employee.hourlyRate<<endl;
    cout<<"Worker income: "<<income(employee)<<endl;
    
}

int overtime(worker employee[], int s) {
    int count=0;
    for(int i=0;i<3;i++)
        if(employee[i].hoursWorked>40)
            count++;
    return count;
}