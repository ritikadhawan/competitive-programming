//Question: You are given an array A with size N (indexed from 0) and an integer K. Let's define another array B with size N · K as the array that's formed by concatenating K copies of array A.

//For example, if A = {1, 2} and K = 3, then B = {1, 2, 1, 2, 1, 2}.

//You have to find the maximum subarray sum of the array B. Fomally, you should compute the maximum value of Bi + Bi+1 + Bi+2 + ... + Bj, where 0 ≤ i ≤ j < N · K.

//Question Link: (codechef)  https://www.codechef.com/problems/KCON

//Code:
#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--) {
	    long long n, k;
	    cin>>n>>k;
	    vector<int> a(n);
	    long long sum = 0;
	    long long maxSoFar = 0, max1 = INT_MIN;
	    for(int i=0;i<n;i++) {
	        cin>>a[i];
	        sum += a[i];
	        
	        maxSoFar += a[i];
	        
	        if(maxSoFar > max1){
	            max1 = maxSoFar;
	        }
	        if(maxSoFar < 0) {
	            maxSoFar = 0;
	        }
	    }
	    
	    if(k == 1 ) {
	        cout<<max1<<endl;
	    } else {
	        long long suffixSum = 0, prefixSum = 0;
	        long long maxSuffixSum = 0, maxPrefixSum = 0;
	        bool prefixNotNull = false, suffixNotNull = false;
	        
	        for(int i=0;i<n;i++) {
	            prefixSum += a[i];
	            if(prefixSum > maxPrefixSum) {
	                maxPrefixSum = prefixSum;
	                prefixNotNull = true;
	            }
	        }
	        
	        for(int i=n-1;i>=0;i--) {
	            suffixSum += a[i];
	            if(suffixSum > maxSuffixSum) {
	                maxSuffixSum = suffixSum;
	                suffixNotNull = true;
	            }
	        }
	        
	        if( sum < 0 ){
	            long long max2 = suffixNotNull && prefixNotNull ? maxSuffixSum+maxPrefixSum : INT_MIN;
	            max1 = max(max1, max2);
	        } else {
	            long long max2 = maxSuffixSum + maxPrefixSum + (k-2)*sum;
	            max1 = max(max1, max2);
	        }
	        cout<<max1<<endl;
	    }
	    
	}
	return 0;
}
