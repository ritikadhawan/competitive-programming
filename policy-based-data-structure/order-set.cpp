//Question link: https://www.spoj.com/problems/ORDERSET
//Reference link: https://codeforces.com/blog/entry/11080
//Code:

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;
using namespace std;


//using policy based data structure (pbds)
typedef tree<int,
            null_type, 
            less<int>, 
            rb_tree_tag, 
            tree_order_statistics_node_update> 

            ordered_set;
int main() {
    ordered_set s;
    int q;
    cin>>q;
    while(q--) {
        char type;
        int val;
        cin>>type;
        if(type == 'I') {
            cin>>val;
            s.insert(val);
        } else if(type == 'D') {
            cin>>val;
            s.erase(val);
        } else if(type == 'K') {
            int k;
            cin>>k;
            ordered_set::iterator ans = s.find_by_order(k-1);
            if(ans == s.end()) {
                cout<<"invalid"<<endl;
            } else {
                cout<<(*ans)<<endl;
            }
        } else {
            int x;
            cin>>x;
            int count = s.order_of_key(x);
            cout<<count<<endl;
        }
    }
    return 0;
}
