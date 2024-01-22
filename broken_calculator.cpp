#include<iostream>
using namespace std;
void multiply(int fact[],int x,int &idx)
{
    int carry=0;
    for(int i=0;i<=idx;i++)
    {
        int val=fact[i] * x + carry;
        fact[i]=val%10;
        carry=val/10;
    }
    // after this loop ends, we still might have some residual carry value
    while(carry >0)
    {
        idx++;
        // ab new idx ki pos par aagye hai

        fact[idx]=carry%10;
        carry/=10;
    }

}
int main() {
    int n; cin>>n;

    int fact[2000]={0}; // 2000 is a good upper limit to store factorial of 500

    int idx=0;
    fact[0]=1;
    for(int i=1;i<=n;i++)
    {
        multiply(fact,i,idx);
    }
    // int a=11;
    // int &b=a;
    // cout<<&a<<endl;
    // cout<<&b<<endl;
    // cout<<b<<endl;
    for(int i=idx;i>=0;i--) cout<<fact[i];
    
	return 0;
}
