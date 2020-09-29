//Question: https://www.spoj.com/problems/DQUERY/
//Code: 

#include <bits/stdc++.h>
using namespace std;
 
int block;
 
class Query {
    public:
    int l, r, index;
};
bool compare(Query q1, Query q2) {
    //same block sort by right
    if(q1.l/block == q2.l/block) {
        return q1.r < q2.r;
    }
    //else sort by block
    return (q1.l/block) < (q2.l/block);
}
int main() {
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i=0; i<n; i++) {
        cin>>input[i];
    }
    block = (int)sqrt(n);
 
    int q;
    cin>>q;
    vector<Query> queries(q);
    for(int i=0; i<q; i++) {
        cin>>queries[i].l>>queries[i].r;
        queries[i].l--;
        queries[i].r--;
        queries[i].index = i;
    }
    sort(queries.begin(), queries.end(), compare);
 
    int start = queries[0].l, end = queries[0].l;
    unordered_map<int, int> freq;
    freq[input[start]]++;
    int count = 1;
    vector<int> ans(q);
    for(int i=0; i<q; i++) {
        int l = queries[i].l, r = queries[i].r;
        while(start < l) {
            //inc start and remove elements
            freq[input[start]]--;
            if(freq[input[start]] == 0) {
                count--;
            }
            start++;
        }
 
        while(start > l) {
            //dec start and add elements
            start--;
            freq[input[start]]++;
            if(freq[input[start]] == 1) {
                count++;
            }
            
        }
 
        while(end < r) {
            //inc end and add elements
            end++;
            freq[input[end]]++;
            if(freq[input[end]] == 1) {
                count++;
            }
            
        }
 
        while(end > r) {
            //dec end and remove elements
            freq[input[end]]--;
            if(freq[input[end]] == 0) {
                count--;
            }
            end--;
        }
 
        ans[queries[i].index] = count;
    }
 
    for(int a: ans) {
        cout<<a<<endl;
    }
    return 0;
} 
