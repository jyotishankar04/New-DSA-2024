#include <bits/stdc++.h>
using namespace std;

class basicString
{
public:
    void reverseString(vector<char> &);
    bool isPalindrome(string &);
};

void basicString::reverseString(vector<char> &s)
{
    int n = s.size();
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

bool basicString::isPalindrome(string &s)
{
    int size = s.length();
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int main()
{

    basicString obj;
    vector<char> v = {'h', 'e', 'l', 'l', 'o'};
    obj.reverseString(v);
    cout << "Reversed string: ";
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    string s1 = "zyz";
    string result = obj.isPalindrome(s1) ? "True" : "False";
    cout << "Check Palindrome: " << result << endl;

    return 0;
}