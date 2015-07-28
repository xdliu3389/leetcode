/*C++ version
* We set the nums as two part.One is bigger than the kth number,and another is smaller than kth number.
* If the bigger number count is bigger than k,than the kth number must be in the bigger number group,than we can recursion
* call the function to reach the ans.
* Else if the bigger nmber count is smaller than k,than the kth number must be in the smaller group.And the kth number
* must be in the k-bigger.size() place in the smaller group.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int cur=nums[k-1];
        vector<int> bigger;
        vector<int> smaller;
        for(size_t i=0; i<nums.size(); ++i){
            if(i==k-1) continue;
            if(nums[i]>=cur) bigger.push_back(nums[i]);
            else smaller.push_back(nums[i]);
        }
        if(bigger.size()==k-1) return cur;
        if(bigger.size()>k-1) return findKthLargest(bigger,k);
        if(bigger.size()<k-1) return findKthLargest(smaller,k-bigger.size()-1);
    }
};

/****C version
* For example:3 5 4 1 7 8.We have k times outside loop and numsSize-i times innerside loop(i=0:k)
* First loop,the nums become:8 5 4 1 7 3
* Second loop, the nums become:8 7 4 1 5 3(the innerside loop is begin from nums[1] while not nums[0] because nums[0] is the 
* 1st largest number through the first loop.
* ...
*/
int findKthLargest(int* nums, int numsSize, int k) 
{
    int temp;
    int i,j;
    int max;
    int q;
    for(i=0; i<k; i++)
    {
        max = nums[i];
        q = i;
        for(j=i+1; j<numsSize; j++)
        {
            if(nums[j] > max)
            {
                max = nums[j];
                q = j;
            }
        }
        temp = nums[i];
        nums[i] = nums[q];
        nums[q] = temp;
    }
    return nums[k-1];
}
