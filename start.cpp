#include <iostream>
using namespace std;

void setSetBit(int x, int y, int l, int r)
{
    int n = y;
    int ans = 0;
    int product = 1;
    while (n)
    {
        int rem = n % 2;
        ans += rem * product;
        product *= 10;
        n /= 2;
    }

    string s = to_string(ans);

    string str;

    int k = 0;

    for (int i = l-1; i <= r-1; i++)
    {
        if (i >= s.size())
        {
            break;
        }
        str.push_back(s[i]);
    }

    cout << str << endl;

    int n1 = stoi(str);

    int prod2 = 1;
    int ans2 = 0;

    while(n1) {

        int rem = n1%10;
        ans2 += prod2*rem;
        prod2 *= 2;
        n1 /= 10;

    }

    cout<<x + ans2<<endl;

}

int main()
{

    int x = 44, y = 3;
    int l = 1, r = 5;

    setSetBit(x, y, l, r);

    return 0;
}