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

    return 0;
}