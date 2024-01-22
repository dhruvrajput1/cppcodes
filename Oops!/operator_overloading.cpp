#include<iostream>
#include<utility>
using namespace std;

class pairr{
public:
    int u;
    int v;
    pairr(int a, int b){
        u = a;
        v = b;
    }

    bool operator >(pairr Y){
        if(u > Y.u and v > Y.v){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){

    pairr X(30, 40);

    pairr Y(20, 30);

    // cout<<X.u<<endl;
    // cout<<X.v<<endl;

    if(X > Y){  // operator ke left wala call karta hai // argument me operator ka right side wala jaata hai
        cout<<"X is greater"<<endl;
    }
    else{
        cout<<"X is smaller"<<endl;
    }

    // inbuilt pair

    pair<int, char>p;

    p.first = 70;
    p.second = 'D';
    cout<<p.first<<" "<<p.second<<endl;

 
    return 0;
}