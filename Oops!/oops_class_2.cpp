#include<iostream>
#include<cstring>
using namespace std;

class car {
private: // can't access it outside class
    int price;

public: // jo bhi iske andar variables hai hum usko class ke bahar bhi access kar sakte hai 
    // char name[100]; // static memory allocation
    char* name; 

    // int price; // moved to private
    int seats;
    float modelNo;

    car(){ // default operator
        cout<<"Default constructor is called"<<endl;

        name = NULL;

    }

    car(char* n, int price, int s, float mn): seats(s), modelNo(mn){ // Car C // seats(s) is initializing list
        cout<<"Inside parameterised constructor"<<endl;

        name = new char[strlen(n) +1]; // DMA // +1 for NULL at the end of the array

		strcpy(name, n);
        this->price = price; // this is used to differnetiate between two price
        // seats = s; // instead of here, assigned above in initializing list
        // modelNo = mn;
    } 

    // copy constructor

    car(car &x){ // jo call karta h vo argument me jaata hai  // in x we have car c

        cout<<"In copy constructor"<<endl;

        name = new char[strlen(x.name) +1];  // D ke liye new memory create kari shallow copy se bachne ke liye
        strcpy(name, x.name); // deep copy --> Change only in D, not in C

        // name = x.name;
        price = x.price;
        seats = x.seats;
        modelNo = x.modelNo;
    }

    // copy assignment operator

    void operator = (car x){
         cout<<"In copy assignment constructor"<<endl;

        name = new char[strlen(x.name) +1];  // D ke liye new memory create kari shallow copy se bachne ke liye
        strcpy(name, x.name); // deep copy --> Change only in D, not in C

        // name = x.name;
        price = x.price;
        seats = x.seats;
        modelNo = x.modelNo;
    }



    void printInfo(){  // constant member functions
        cout<<"Name of car is: "<<name<<endl;
        cout<<"Price of car is: "<<price<<endl;
        cout<<"Seats in car is: "<<seats<<endl;
        cout<<"Model number of car is: "<<modelNo<<endl;

        cout<<endl;
    }

    void update(char* n){  // ye function name me value update karega

        if(name != NULL){
            delete[] name;
            name = NULL;
        }

        name = new char[strlen(n) +1]; // memory allocate ho gyi
        strcpy(name, n); // allocated memory me value daal di

    }
    void setPrice(int p){
        if(p < 200){
            price = 200;
        }
        else{
            price = p;
        }
        
    }

    int getPrice(){
        return price;
    }

    // destructor
    ~car(){  // deletes all the cars
        if(name != NULL) { // we have to delete the dynamically declared data
            delete [] name;
        }
        cout<<"destructor for car "<<name<<" called"<<endl;
    }

};

int main(){

    car A;
    // strcpy(A.name, "Vitara Brezza");

    A.update("BMW");

    // A.price = 800000;

    A.setPrice(20); // setter

    A.seats = 5;
    A.modelNo = 2020.555;

    A.update("qwerty");

    A.printInfo();

    car B;
    // strcpy(B.name,"Mercedes");

    B.update("Mercedes");

    // B.price = 7000000;

    B.setPrice(75000);

    B.seats = 5;
    B.modelNo = 2022.978;

    cout<<"Price of car is: "<<B.getPrice()<<endl; // getter

    B.printInfo();

    car C("Renault Duster", 500000, 7, 2018.6450);
    C.printInfo();

    // car D = C; // copy constructor
    car D(C); // both works same
    D.printInfo();

    // deep and shallow copy

    D.name[0] = 'M'; // ye change dono C and D me ho jayega

    C.printInfo(); // shallow copy --> 2 pointers same location ko point ka rhe hai, to avoid this, we make deep copy by creating new char array

    D.printInfo(); 


    // copy assignment operator

    car E;
    E = A; // operator overloading // = is defined for primitive data types only

    cout<<"Car E details are: "<<endl;
    E.printInfo();

    

    int a = 10;
    int b;

    b = a;
    

    return 0;
}