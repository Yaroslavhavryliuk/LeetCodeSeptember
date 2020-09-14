
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
        {
            return 0;
        }
        int* arrMax=new int[s.length()];
        for (int i = 0; i < s.length(); i++)
        {
            int maxSub = 0;
            for (int j = i; j < s.length(); j++)
            {
                maxSub++;
                for (int k = i; k < j; k++)
                {
                    if (s[j] == s[k])
                    {
                        arrMax[i] = maxSub-1;
                        break;
                    }
                }
                if (arrMax[i] == maxSub-1)
                {
                    break;
                }
               
            }
            if (arrMax[i] != maxSub-1)
            {
                arrMax[i] = s.length() - i;
            }
        }
        int max = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (arrMax[i] > max)
            {
                max = arrMax[i];
            }
        }
        delete[]arrMax;
        return max;
    }
};

int main()
{
    Solution sl;
    cout << sl.lengthOfLongestSubstring("") << endl;
    return 0;
}

