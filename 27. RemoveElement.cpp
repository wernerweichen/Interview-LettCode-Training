/*///////////////////////////////////////////////////////////////////////////////
Link To Qustion https://leetcode.com/problems/remove-element/description
///////////////////////////////////////////////////////////////////////////////*/

/*
Solution idea : Since it's asking to return the answer with another integer, it's find to be using another int to keep track of the value
And it's using only one vector and you should make sure that you aren't doing many useless traversal
Thus, think of the way to make it done within one traversal should be optimal
*/
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};

/*
Solution idea(Fails) : When dealing with this type of question, make sure you are setting every index of nums to make sure there is no overwritting happens
The following solution is what I initially use, but it has potential issue when the data changes
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int found_occurrence = 0;
        for(int index = 0 ; index < nums.size() ; index++){
            if(nums[index] == val){
                found_occurrence++;
            }
            else{
                nums[index-found_occurrence] = nums[index];
            }
        }
        return nums.size() - found_occurrence;
    }
};

/*
Key Note :  For question that requires you to return arrays, make sure that you set all the essential elements accordingly.
*/