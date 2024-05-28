#include<iostream>
using namespace std;

class time {
    int hours;
    int minutes;

public:
    time() {

    }

    time(int t) {
        hours = t/60;
        minutes = t%60;
    }

    void print() {
        cout<<"time is "<<hours<<" hours and "<<minutes<<" minutes "<<endl;
    }
};

int main() {

    time T;
    
    int duration = 85;
    
    T = duration;
    T.print();

    return 0;
}

int main(int argc, char** argv) {


    return 0;
}