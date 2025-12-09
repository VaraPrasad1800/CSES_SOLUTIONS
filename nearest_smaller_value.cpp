#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin >> v[i];
    vector<int> ans(n,0);
    stack<int> st;

    for(int i = n-1;i>=0;i--){
        while(!st.empty() && v[i] < v[st.top()]){
            ans[st.top()] = i+1;
            st.pop();
        }
        st.push(i);
    }
    for(int i = 0;i<n;i++) cout << ans[i] << " ";
    cout << endl;
}