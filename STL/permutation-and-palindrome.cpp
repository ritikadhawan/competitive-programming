//Question Link: https://www.codechef.com/FEB18/problems/PERMPAL
//Code:
#include <iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--) {
	    string s;
	    cin>>s;
	    unordered_map<char, vector<int>> charIndex;
	    for(int i=0;i<s.length();i++) {
	        charIndex[s[i]].push_back(i);
	    }
	    
	    unordered_map<char, vector<int>> ::iterator it = charIndex.begin();
	    char oddChar = '\0';
	    bool isPalindrome = true;
	    while(it != charIndex.end()) {
	        if(it->second.size() % 2 != 0) {
	            if(oddChar == '\0') {
	                oddChar = it->first;
	            } else {
	                isPalindrome = false;
	                break;
	            }
	        }
	        it++;
	    }
	    if(isPalindrome) {
	        vector<int> ans(s.length());
	        
	        int i=0, j=s.length()-1;
	        it = charIndex.begin();
	        while(it != charIndex.end()) {
	            int count = it->second.size()/2;
	            int index = 0;
	            while(count--){
	                ans[i] = it->second[index]+1;
	                index++;
	                ans[j] = it->second[index]+1;
	                index++;
	                i++; j--;
	            }
	            it++;
	        }
	        if(oddChar != '\0') {
	            ans[s.length()/2] = charIndex[oddChar][charIndex[oddChar].size()-1]+1;
	        }
	        
	        for(int index=0;index<ans.size();index++) {
	            cout<<ans[index];
	            if(index != ans.size()-1){
	                cout<<" ";
	            }
	        }
	        
	    } else {
	        cout<<-1;
	    }
	    cout<<endl;
	}
	return 0;
}
