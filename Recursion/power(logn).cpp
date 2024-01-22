#include<iostream>
using namespace std;

 double myPow(double x, int n) {
        // base case
        if(n == 0){
            return 1;
        }
        
        
        // recursive case
        if(n >= 0){
            double halfKaAns = myPow(x, n/2);
            if(n%2 == 0){
                return halfKaAns*halfKaAns;
            }
            else{
                return halfKaAns*halfKaAns*x;
            }
        }
        else{
            double halfAns = myPow(x, abs(n/2));
            if(n%2 == 0){
                return (1/halfAns)*(1/halfAns);
            }
            else{
                return (1/halfAns)*(1/halfAns)*(1/x);
            }
        }
 }

int main(){
    
    double x;
    int n;
    cin>>x>>n;

    cout<<myPow(x, n)<<endl;
    
    return 0;
}