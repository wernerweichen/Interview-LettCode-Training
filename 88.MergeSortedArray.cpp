/*///////////////////////////////////////////////////////////////////////////////
Link To Qustion  https://leetcode.com/problems/merge-sorted-array/description/
///////////////////////////////////////////////////////////////////////////////*/
#include<vector>
#include<algorithm>
using namespace std;

/*
Solution idea 1 : Since the array is using the stl container, try to utilize the std library for sorting
Thus, we merge the two arrays together then start sorting them using the std::sort
However, the drawback of this solution is relatively long process time due to the fact that std::sort could be expensive
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int index_2 = 0 ; index_2 < n ; index_2++){
            nums1[m+index_2] = nums2[index_2];
        }
         std::sort (nums1.begin(), nums1.end());
    }
};

/*
Key Note : std::sort has a complexity of O(n log n)
*/


/*
Solution idea 2 : Since we are given two arrays and asked to provide element relatively manipulation.
Consider the chance of using two or more pointers to keep track of elements
Note that we might find it fails if we set the index to start from 0, but on the other hand, try to set it to end and traverse backward
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m-1;
        int index2 = n-1;
        int current_pos = m+n-1;
        while(index2 >= 0){
            if(index1 >= 0 && nums1[index1] > nums2[index2]){
                nums1[current_pos--] = nums1[index1--];
            }
            else{
                nums1[current_pos--] = nums2[index2--];
            }
        }
    }
};

/*
Key Note : 
1. using index++ or index-- within the line can make the code cleaner, but make sure they are readible
2. make sure that you use nameings within meanings, you can use i, j, k for all the ints, but doing that will ends up within confusion
*/