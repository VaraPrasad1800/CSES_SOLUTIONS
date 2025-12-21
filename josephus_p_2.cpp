#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


int main(){
    int n,k;
    cin >> n >> k;
    ordered_set st;

    for(int i=1;i<=n;i++) st.insert(i);

    int idx = 0;
    while(!st.empty()){
        idx = (idx+k)%st.size();
        auto i = st.find_by_order(idx);
        cout << *i << " ";
        st.erase(i);
    }
    cout << endl;

}