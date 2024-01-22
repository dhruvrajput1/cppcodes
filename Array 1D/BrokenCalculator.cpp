#include <iostream>
using namespace std;

void multiply(int fact[], int x, int &idx)
{

    int carry = 0;
    for (int i = 0; i <= idx; i++)
    {
        int value = fact[i] * x + carry;
        fact[i] = value % 10;
        carry = value / 10;
    }

    while (carry > 0)
    {
        idx++;

        fact[idx] = carry % 10;
        carry = carry / 10;
    }
}

int main()
{
    int N;
    cin >> N;

    int fact[2000] = {0};
    int idx = 0;
    fact[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        multiply(fact, i, idx);
    }

    for (int i = idx; i >= 0; i--)
    {
        cout << fact[i];
    }

    return 0;
}