#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 37;
    // *Aproach 1 TC = n SC = 1
    int count = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (n % i == 0)
    //     {
    //         count++;
    //     }
    // }
    // if (count == 2)
    // {
    //     cout << "yes";
    // }
    // else
    //     cout << "No";
    // *Aproach 2 TC = sqrtN SC = 1
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i != i)
            {
                count++;
                count++;
            }
            else
            {
                count++;
            }
        }
    }
    if (count == 2)
    {
        cout << "yes";
    }
    else
        cout << "No";

    return 0;
}