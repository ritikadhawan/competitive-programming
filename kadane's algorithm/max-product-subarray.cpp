//Question: Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
//Question Link: (leetcode) https://leetcode.com/problems/maximum-product-subarray

//Code:
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int maxEndingHere = 0, minEndingHere = 0, maxProduct = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] > 0) {
                maxEndingHere = maxEndingHere == 0 ? nums[i] : maxEndingHere * nums[i];
                minEndingHere = min(0, minEndingHere*nums[i]);
            } else if(nums[i] < 0) {
                int temp = maxEndingHere;
                maxEndingHere = minEndingHere*nums[i];
                minEndingHere = temp == 0 ? nums[i] : temp*nums[i];
            } else {
                maxEndingHere = 0;
                minEndingHere = 0;
            }
            
            maxProduct = max(maxProduct, maxEndingHere);
        }
        return maxProduct;
    }

};
