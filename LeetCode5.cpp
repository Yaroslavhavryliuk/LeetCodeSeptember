

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Palindrome;
class Solution;

class Palindrome
{
    friend Solution;
public:
    int getstrSize()
    {
        return strLong(str);
    }
private:
    vector<char>str;
    int strSize;
    int strLong(vector<char>& str)
    {
        return str.size();
    }
};

class Solution 
{
public:
    vector<char> longestPalindrome(string s)
    {
        if (s.length() == 0)
        {
            return {};
        }
        vector<Palindrome> palMax;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = s.length() - 1; j >= i; j--)
            {
                bool isPal = true;
                int count = 0;
                for (int k = i; k <= j; k++)
                {
                    
                    if (s[k] == s[j - count])
                    {
                        count++;
                        continue;
                    }
                    else
                    {
                        isPal = false;
                        break;
                    }
                    
                }
                if (isPal)
                {
                    Palindrome sToPalMax;
                    for (int l = i; l <= j; l++)
                    {
                        sToPalMax.str.push_back(s[l]);
                    }
                    palMax.push_back(sToPalMax);
                }
            }
        }
        int max = 0;
        for (int i = 0; i < palMax.size(); i++)
        {
            if (palMax[i].getstrSize() > max)
            {
                max = palMax[i].getstrSize();
            }
        }
        for (int i = 0; i < palMax.size(); i++)
        {
            if (palMax[i].getstrSize() == max)
            {
                return palMax[i].str;
            }
        }
        
    }
};



int main()
{
    Solution sl;
    vector<char> answ;
    answ=sl.longestPalindrome("msalaskr");
    for (int i = 0; i < answ.size(); i++)
    {
        cout << answ[i];
    }
    return 0;
}

