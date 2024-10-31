#include <bits/stdc++.h>
using namespace std;

class basicsMaths
{
public:
    int countDigitsOfNumber(int);
    int countDigitsOfNumberOptimal(int);
    int countTheNumberOfOddDigits(int);
    int reverseNumber(int);
    bool checkPalindrome(int);
    int largestDigitInNumber(int);
    int factorialNumber(int);
    int factorialNumberOptimal(int);
    bool isAmstrongNumber(int);
    bool perfectNumber(int);
    bool checkPrimeNumber(int);
    int countOfPrimeNumberTillN(int);
    int GCDbrute(int, int);
    int GCDbatter(int, int);
    int GCDoptimal(int, int);
    int LCMbrute(int, int);
    int LCMOptimal(int, int);
    vector<int> diviserOfANumberBrute(int);
    vector<int> diviserOfANumberOptimal(int);
};

int basicsMaths::countDigitsOfNumber(int number)
{

    if (number == 0)
        return 1;
    int count = 0;
    while (number)
    {
        number /= 10;
        count++;
    }
    return count;
}
int basicsMaths::countDigitsOfNumberOptimal(int number)
{

    if (number == 0)
        return 1;
    int count = log10(number) + 1;
    return count;
}
int basicsMaths::countTheNumberOfOddDigits(int number)

{

    int count = 0;
    while (number > 0)
    {
        int ld = number % 10;
        if (ld % 2 != 0)
        {
            count++;
        }
        number /= 10;
    }
    return count;
}

int basicsMaths::reverseNumber(int number)
{

    int reverse = 0;
    while (number > 0)
    {
        reverse = reverse * 10 + (number % 10);
        number = number / 10;
    }
    return reverse;
}

bool basicsMaths::checkPalindrome(int number)
{
    int reverse = reverseNumber(number);
    if (number == reverse)
    {
        return true;
    }
    return false;
}

int basicsMaths::largestDigitInNumber(int number)
{
    if (number == 0)
        return 0;
    int largest = -1;

    while (number > 0)
    {

        if (number % 10 > largest)
        {
            largest = number % 10;
        }
        number /= 10;
    }
    return largest;
}

int basicsMaths::factorialNumber(int number)
{
    if (number <= 1)
        return 1;
    int fact = 1;
    for (int i = 2; i <= number; i++)
    {
        fact = fact * i;
    }

    return fact;
}

int basicsMaths::factorialNumberOptimal(int number)
{
    if (number <= 1)
        return 1;
    return number * factorialNumberOptimal(number - 1);
}

bool basicsMaths::isAmstrongNumber(int number)
{
    int temp = number;
    int sum = 0;
    int count = 0;
    while (temp > 0)
    {
        count++;
        temp = temp / 10;
    }
    temp = number;
    while (temp > 0)
    {
        int ld = temp % 10;
        sum = sum + pow(ld, count);
        temp = temp / 10;
    }
    if (sum == number)
    {
        return true;
    }
    return false;
}

bool basicsMaths::perfectNumber(int number)
{
    //! Given a number, all its proper divisors(divisors that divide the number without leaving any remainder, excluding the number itself) can be found and summed up.Then, the sum can be compared with the number itself.If the sum is the same as the number, then it is a perfect number, otherwise, it is not .
    if (number == 1)
        return true;
    int result = 0;
    for (int i = 1; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            result += i;
            if (number / i != number && i != number / i)
            {
                result = result + number / i;
            }
        }
    }
    if (result == number)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool basicsMaths::checkPrimeNumber(int number)
{
    if (number < 1)
        return true;
    int count = 0;
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
            count++;
    }
    if (count != 0)
        return false;
    return true;
}
int basicsMaths::countOfPrimeNumberTillN(int number)
{
    if (number < 2)
        return 0;
    int count = 0;
    for (int i = 2; i <= number; i++)
    {
        if (checkPrimeNumber(i))
        {
            count++;
        }
    }
    return count;
}

int basicsMaths::GCDbrute(int n1, int n2)
{
    int gcd = 0;
    for (int i = 2; i <= min(n1, n2); i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}
int basicsMaths::GCDbatter(int n1, int n2)
{

    for (int i = min(n1, n2); i >= 1; --i)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            return i;
        }
    }
    return 0;
}

int basicsMaths::GCDoptimal(int n1, int n2)
{
    while (n1 > 0 && n2 > 0)
    {
        if (n1 < n2)
        {
            n2 = n2 % n1;
        }
        else
        {
            n1 = n1 % n2;
        }
    }
    if (n1 == 0)
        return n2;
    else
        return n1;
}

int basicsMaths::LCMbrute(int n1, int n2)
{
    int maxEl = max(n1, n2);
    int lcm = 0;
    int i = 1;
    while (1)
    {
        int mul = maxEl * i;
        if (mul % n1 == 0 && mul % n2 == 0)
        {
            lcm = mul;
            break;
        }
        i++;
    }
    return lcm;
}

int basicsMaths::LCMOptimal(int n1, int n2)
{
    int gcd = GCDoptimal(n1, n2);
    int lcm = (n1 * n2) / gcd;
    return lcm;
}

vector<int> basicsMaths::diviserOfANumberBrute(int number)
{
    vector<int> divisers;
    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            divisers.push_back(i);
        }
    }
    return divisers;
}

vector<int> basicsMaths::diviserOfANumberOptimal(int number)
{
    vector<int> result;
    for (int i = 1; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            result.push_back(i);
            if (i != number / i)
            {
                result.push_back(number / i);
            }
        }
    }
    sort(result.begin(), result.end());
    return result;
}

int main()
{
    basicsMaths obj = basicsMaths();
    // cout << "Count of a number: " << obj.countDigitsOfNumber(94350) << endl;
    // cout << "Count of a number Optimal : " << obj.countDigitsOfNumberOptimal(94350) << endl;
    // cout << "Count the number of odd digits : " << obj.countTheNumberOfOddDigits(432908) << endl;
    // cout << "Reverse of a number: " << obj.reverseNumber(432908) << endl;
    // string res = obj.checkPalindrome(101) ? "True" : "False";
    // cout << "Palindrome : " << res << endl;
    // cout << "Largest Digit: " << obj.largestDigitInNumber(48738) << endl;
    // cout << "Factorial: " << obj.factorialNumber(3) << endl;
    // cout << "Optimal Factorial: " << obj.factorialNumberOptimal(3) << endl;
    // string res = obj.isAmstrongNumber(153) ? "True" : "False";
    // cout << "Amstrong Number: " << res << endl;
    // string res = obj.perfectNumber(6) ? "True" : "False";
    // cout << "Perfect Number: " << res << endl;
    // string res = obj.checkPrimeNumber(6) ? "True" : "False";
    // cout << "Prime Number: " << res << endl;

    // int res = obj.countOfPrimeNumberTillN(20);
    // cout << "Count : " << res << endl;

    // cout << "GCD BRUTE: " << obj.GCDbrute(4, 8) << endl;
    // cout << "GCD BATTER: " << obj.GCDbatter(4, 8) << endl;
    // cout << "GCD OPTIMAL: " << obj.GCDoptimal(4, 8) << endl;

    // cout << "LCM Brute: " << obj.LCMbrute(4, 5) << endl;
    // cout << "LCM Optimal: " << obj.LCMOptimal(4, 30) << endl;

    vector<int> result = obj.diviserOfANumberBrute(36);
    cout << "Divisers: ";
    for (auto i : result)
    {

        cout << i << " ";
    }

    cout << endl;
    vector<int> optimalResult = obj.diviserOfANumberOptimal(36);
    cout << "Divisers: ";
    for (auto i : optimalResult)
    {

        cout << i << " ";
    }

    return 0;
}
