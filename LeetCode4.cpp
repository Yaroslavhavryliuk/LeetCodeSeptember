
#include <iostream>
#include <vector>
using namespace std;

void choicesSort(vector<int>& arrayPtr, int length_array);

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        for (int i = 0; i < nums2.size(); i++)
        {
            nums1.push_back(nums2[i]);
        }
        choicesSort(nums1, nums1.size());
        if ((nums1.size() % 2) != 0)
        {
            return (double)nums1[nums1.size() / 2];
        }
        else
        {
            return (double)(nums1[nums1.size() / 2] + nums1[(nums1.size() / 2) - 1]) / 2;
        }
    }
};

void choicesSort(vector<int>& arrayPtr, int length_array) // сортировка выбором
{
    for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++)
    {
        int temp = arrayPtr[0]; // временная переменная для хранения значения перестановки
        for (int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++)
        {
            if (arrayPtr[repeat_counter] > arrayPtr[element_counter])
            {
                temp = arrayPtr[repeat_counter];
                arrayPtr[repeat_counter] = arrayPtr[element_counter];
                arrayPtr[element_counter] = temp;
            }
        }
    }
}

int main()
{
    vector<int> num1 = { 3, 11, 8, 13 }, num2 = { 5, 4, 9 };
    choicesSort(num1, num1.size());
    choicesSort(num2, num2.size());
    Solution sl;
    cout << sl.findMedianSortedArrays(num1, num2) << endl;
    return 0;
}

