#include <bits/stdc++.h>
using namespace std;

class basicString
{
public:
    void reverseString(vector<char> &);
    bool isPalindrome(string &);
    string largestSubStringNumber(string &);
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

string basicString::largestSubStringNumber(string &s)
{
    int n = s.length();
    int j = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if ((s[i] - '0') % 2 == 1)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return "";

    int i = 0;
    while (i < n)
    {
        if (s[i] != '0')
            break;
        i++;
    }
    return s.substr(i, j - i + 1);
}

int main()
{

    basicString obj;
    // vector<char> v = {'h', 'e', 'l', 'l', 'o'};
    // obj.reverseString(v);
    // cout << "Reversed string: ";
    // for (auto it : v)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // string s1 = "zyz";
    // string result = obj.isPalindrome(s1) ? "True" : "False";
    // cout << "Check Palindrome: " << result << endl;

    // string s2 = "00093838";
    // string result = obj.largestSubStringNumber(s2);
    // cout << "Largest Substring Number: " << result << endl;

    return 0;
}