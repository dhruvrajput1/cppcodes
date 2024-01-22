#include<iostream>
using namespace std;

class car{

public:
    string name;
    int price;
    int seats;
    float modelNo;

    car(){ // default operator
        cout<<"Default constructor is called"<<endl<<endl;
    }

    car(string n, int p, int s, float mn){
        name = n;
        price = p;
        seats = s;
        modelNo = mn;
    }

    car(string na, int pr){
        name = na;
        price = pr;
    }

    void printInfo(){
        cout<<"Name of car is: "<<name<<endl;
        cout<<"Price of car is: "<<price<<endl;
        cout<<"Seats in car is: "<<seats<<endl;
        cout<<"Model number of car is: "<<modelNo<<endl;

        cout<<endl;
    }

};

int main(){

    car A; // object instantiation
    A.name = "Vitara Brezza";
    A.price = 800000;
    A.seats = 5;
    A.modelNo = 2020.555;

    // A.printInfo();

    car B;
    B.name = "Mercedes";
    B.price = 7000000;
    B.seats = 5;
    B.modelNo = 2022.978;

    // B.printInfo();

    car C("Renault Duster", 500000, 7, 2018.6450);
    C.printInfo();


    car D("Maruti Suzuki 😊😊", 90000);
    D.printInfo();



    return 0;
}