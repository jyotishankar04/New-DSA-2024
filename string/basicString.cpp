#include <bits/stdc++.h>
using namespace std;

class basicString
{
private:
    static bool comparator(pair<int, char> p1, pair<int, char> p2)
    {
        if (p1.first > p2.first)
            return true;
        if (p1.first < p2.first)
            return false;
        return p1.second < p2.second;
    }

public:
    void reverseString(vector<char> &);
    bool isPalindrome(string &);
    string largestSubStringNumber(string &);
    bool rotateStringBrute(string &, string &);
    bool rotateStringOptimal(string &, string &);
    bool anagramStringsBrute(string &, string &);
    bool anagramStringsOptimal(string &, string &);
    vector<char> frequencySort(string &);
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
    int left = 0;
    int right = s.length() - 1;

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
        if ((s[i] - '0') % 2 == 1) // check if the character is an odd digit
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return "";

    int i = 0;
    while (i < n && s[i] == '0') // skip leading zeros
        i++;

    return s.substr(i, j - i + 1);
}

bool basicString::rotateStringBrute(string &s, string &goal)
{
    if (s.length() != goal.length())
        return false;
    if (s == goal)
        return true;

    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        string newStr = s.substr(i) + s.substr(0, i);
        if (newStr == goal)
        {
            return true;
        }
    }
    return false;
}

bool basicString::rotateStringOptimal(string &s, string &goal)
{
    if (s.length() != goal.length())
        return false;
    string newStr = s + s;
    return newStr.find(goal) != string::npos;
}

bool basicString::anagramStringsBrute(string &s, string &t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

bool basicString::anagramStringsOptimal(string &s, string &t)
{
    if (s.length() != t.length())
        return false;

    vector<int> count(26, 0);

    for (char c : s)
        count[c - 'a']++;

    for (char c : t)
        count[c - 'a']--;

    for (int i : count)
    {
        if (i != 0)
            return false;
    }

    return true;
}

vector<char> basicString::frequencySort(string &s)
{
    // your code goes here

    pair<int, char> freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i] = {0, i + 'a'};
    }
    for (char ch : s)
    {
        freq[ch - 'a'].first++;
    }

    sort(freq, freq + 26, comparator);

    vector<char> ans;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i].first > 0)
            ans.push_back(freq[i].second);
    }

    return ans;
}

int main()
{
    basicString obj;

    vector<char> v = {'h', 'e', 'l', 'l', 'o'};
    obj.reverseString(v);
    cout << "Reversed string: ";
    for (auto it : v)
    {
        cout << it;
    }
    cout << endl;

    string s1 = "zyz";
    cout << "Check Palindrome: " << (obj.isPalindrome(s1) ? "True" : "False") << endl;

    string s2 = "00093838";
    cout << "Largest Substring Number: " << obj.largestSubStringNumber(s2) << endl;

    string s3 = "abcde";
    string s4 = "cdeab";
    cout << "Check Rotate String Brute: " << (obj.rotateStringBrute(s3, s4) ? "True" : "False") << endl;
    cout << "Check Rotate String Optimal: " << (obj.rotateStringOptimal(s3, s4) ? "True" : "False") << endl;

    string s5 = "listen";
    string s6 = "silent";
    cout << "Check Anagram Strings Brute: " << (obj.anagramStringsBrute(s5, s6) ? "True" : "False") << endl;
    cout << "Check Anagram Strings Optimal: " << (obj.anagramStringsOptimal(s5, s6) ? "True" : "False") << endl;

    string s7 = "tree";
    vector<char> res = obj.frequencySort(s7);
    cout << "Frequency Sort: ";
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
