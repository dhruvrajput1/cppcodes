#include<iostream>
using namespace std;

class Box {
private:
    int length;

public:
    Box() {
        
    }

    Box(int len) : length(len) {}

    friend int printLen(Box); 
};

int printLen(Box x) {
    x.length += 10;
    return x.length;
}


int main() {

    Box b(10);

    cout<<printLen(b);
 
    return 0;
}