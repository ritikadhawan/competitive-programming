//Question: Hussain shows Hasan a multiset of integers. (A multiset is a collection of elements where there can be duplicates). In every move Hussain removes a maximum number from this multiset and divides it by 2 (integer division, which is rounded down).
//If after dividing, the number is still positive (greater than 0) he re-inserts it back into the multiset.
//Hussain asks Hasan, M questions. The i-th question will be denoted by Q[i], and Hasan must find the value of the number Hussain will be dividing (before he performs the division) after Q[i]-1 moves. That is, what is the value of the number on which the Q[i]-th division is performed?

//Question Link: (codechef) https://www.codechef.com/problems/COOK82C

//Code:
#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	long long*input = new long long[n];
	//maintaining queue as we don't want to make changes to array because of time constraints
	queue<long long> elements; 
	for(int i=0;i<n;i++){
	    cin>>input[i];
	}
	sort(input, input+n);
	int maxPointer = n-1; //variable pointing to max element in input array
	int qprev = 0;
	while(m--){
	    int q;
	    cin>>q;
	    int i = q-qprev;
	    long long ans = 0;
	    while(i){
    	    
    	    if(elements.size() == 0 && maxPointer >= 0) {
    	        ans = input[maxPointer];
    	        maxPointer--;
    	        
    	    } else if(maxPointer < 0) {
    	        ans = elements.front();
    	        elements.pop();
    	        
    	    } else if(maxPointer>=0 && elements.size()){
    	        ans = max(input[maxPointer], elements.front());
    	        if(ans == input[maxPointer]) {
    	            maxPointer--;
    	        } else {
    	            elements.pop();
    	        }
    	    }
    	    //inserting half to queue
    	    if(ans >= 2) {
    	       elements.push(ans/2);
    	    }
    	    i--;
	    }
	    qprev = q;
	    cout<<ans<<endl;
	}
	delete[]input;
	return 0;
}
