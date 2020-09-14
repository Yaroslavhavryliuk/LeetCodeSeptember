

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> answ;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if ((nums[i] + nums[j]) == target)
                {
                    answ.push_back(j);
                    answ.push_back(i);
                    return answ;
                }
                else
                {
                    continue;
                }
            }
            
        }
        answ.push_back(-1);
        return answ;
    }
    
};

int main()
{
    vector<int> num = { 5, 10, 4, 77 };
    Solution sl;
    vector<int> answer;
    answer=sl.twoSum(num, 84);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
    return 0;
}

