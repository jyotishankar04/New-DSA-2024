#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 36;
    vector<int> resultArr;
    //    * Approach 1
    // for (int i = 1; i < num; i++)
    // {
    //     if (num % i == 0)
    //     {
    //         resultArr.push_back(i);
    //     }
    // }

    // *   Approach 2 TC = sqrtN SC = demand
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            if (num / i != i)
            {
                resultArr.push_back(i);
                resultArr.push_back(num / i);
            }
            else
            {

                resultArr.push_back(i);
            }
        }
    }
    for (auto it : resultArr)
    {
        cout << it << "  ";
    }

    return 0;
}