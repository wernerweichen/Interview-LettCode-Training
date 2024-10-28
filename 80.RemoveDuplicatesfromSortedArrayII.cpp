/*///////////////////////////////////////////////////////////////////////////////
Link To Qustion 
///////////////////////////////////////////////////////////////////////////////*/

/*
Solution idea 
It's almost the same as 26. Noted that if this is a extended question, the solution might be easier than you think.
Since it's already a sorted array, there is actually no points to keep track of the occurrence of elements.
Just need to make sure to compare it with the one that's i element ahead
*/
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (j == 1 || nums[i] != nums[j - 2]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

/*
Solution idea bad example:
Overthinking about the question and keep track of the occurrence of elements
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int result = 0;
        int occurrence = 0;
        for(int index = 0; index < nums.size() ; index++){
            if(index == 0 || nums[result-1] != nums[index]){
                occurrence = 1;
            } else{
                occurrence ++;   
            }
            if(occurrence <= 2){
                nums[result++] = nums[index];
            }
        }
        return result;
    }
};
/*
Key Note : Make sure you think through the problem before implementing it. Like as the interviewer about how the variables can be set or is a magic number is allowed
*/