#include <iostream>
using namespace std;
int main()
{
    // program to find palindrome
    int n, rev = 0, temp;
    cout << "Enter a number: ";
    cin >> n;
    temp = n;
    while (n != 0)
    {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }
    if (temp == rev)
        cout << "The number is a palindrome";
    else
        cout << "The number is not a palindrome";
    return 0;
}