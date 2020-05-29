//Question Link: (codechef) https://www.codechef.com/problems/VOTERS
//Code:
#include <iostream>
#include<map>
using namespace std;

int main() {
	// your code goes here
	int n1, n2, n3;
	cin>>n1>>n2>>n3;
	int count = 0;
	map<int, int> freq; //to store the frequency of voter ids in sorted order
	for(int i=0; i<n1+n2+n3; i++) {
	    int voterId;
	    cin>>voterId;
	    
	    freq[voterId]++;
	    if(freq[voterId] == 2){ //appearing for 2nd time
	        count++;
	    }
	}
	
	map<int, int> ::iterator it = freq.begin();
	//printing no of voters
	cout<<count<<endl;
	while(it != freq.end()) {
	    if(it->second > 1) {
	        cout<<it->first<<endl;
	    }
	    it++;
	}

	
	return 0;
}
