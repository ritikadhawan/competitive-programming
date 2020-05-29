//Question: Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//complexity: time: O(n) space: O(1)

//Question link: (leetcode) https://leetcode.com/problems/product-of-array-except-self

//Code:
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        
        //maintaining left product in ans array
        for(int i=0;i<nums.size()-1;i++) {
            ans[i+1] = ans[i] * nums[i];
        }
        
        //rightProduct variable to calculate right product and updating ans array
        int rightProduct = 1;
        for(int i=nums.size()-1;i>=0;i--) {
            ans[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        
        return ans;
    }
};
