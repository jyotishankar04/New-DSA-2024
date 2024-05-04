// #include <bits/stdc++.h>
// using namespace std;
// bool checkPrime(int n)
// {
//     int count = 0;
//     for (int i = 1; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             if (n / i != i)
//             {

//                 count++;
//                 count++;
//             }
//             else
//             {

//                 count++;
//             }
//         }
//     }
//     if (count == 2)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// int main()
// {
//     int num = 780;
//     vector<int> divisorArr;
//     vector<int> resultArr;
//     for (int i = 1; i * i <= num; i++)
//     {
//         if (num % i == 0)
//         {
//             if (num / i != i)
//             {
//                 divisorArr.push_back(i);
//                 divisorArr.push_back(num / i);
//             }
//             else
//             {

//                 divisorArr.push_back(i);
//             }
//         }
//     }

//     for (auto it : divisorArr)
//     {
//         if (checkPrime(it))
//         {
//             resultArr.push_back(it);
//         }
//     }
//     for (auto it : resultArr)
//     {
//         cout << it << " ";
//     }

//     return 0;
// }

// * Approach 2

// #include <bits/stdc++.h>
// using namespace std;
// bool checkPrime(int n)
// {
//     int count = 0;
//     for (int i = 1; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             if (n / i != i)
//             {

//                 count++;
//                 count++;
//             }
//             else
//             {

//                 count++;
//             }
//         }
//     }
//     if (count == 2)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// int main()
// {
//     int num = 7806;
//     vector<int> resultArr;
//     for (int i = 1; i * i <= num; i++)
//     {
//         if (num % i == 0)
//         {
//             if (num / i != i)
//             {
//                 if (checkPrime(i))
//                     resultArr.push_back(i);
//                 if (checkPrime(num / i))
//                     resultArr.push_back(num / i);
//             }
//             else
//             {

//                 if (checkPrime(i))
//                     resultArr.push_back(i);
//             }
//         }
//     }

//     for (auto it : resultArr)
//     {
//         cout << it << " ";
//     }

//     return 0;
// }
// Approach 3
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 780;
    vector<int> resultArr;
    for (int i = 2; i * i < num; i++)
    {
        if (num % i == 0)
        {
            resultArr.push_back(i);
            while (num % i == 0)
            {
                num = num / i;
            }
        }
    }
    if (num != 1)
        resultArr.push_back(num);

    for (auto it : resultArr)
    {
        cout << it << " ";
    }

    return 0;
}