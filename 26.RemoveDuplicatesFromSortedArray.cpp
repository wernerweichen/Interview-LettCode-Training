/*///////////////////////////////////////////////////////////////////////////////
Link To Qustion https://leetcode.com/problems/remove-duplicates-from-sorted-array
///////////////////////////////////////////////////////////////////////////////*/
#include<vector>
using namespace std;

/*
Solution idea : It's the same as 27. returning a single modified array with another integer as result.
Ideally no other variable used.
Since we only care about the first few elements that are useful, try to set them progressly
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int result = 0;
        for(int index = 1 ; index < nums.size() ; index++){
            if(nums[index] != nums[result]){
                result++;
                nums[result] = nums[index];
            }
        }
        return result+1;
    }
};

/*
Key Note : Make sure that when you are returning the index, you aren't messing it up with the count or size
*/