#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin >> v[i];
    multiset<int> st1,st2;
    for(int i = 0;i<(k+1)/2;i++){
        st1.insert(v[i]);
    }
    for(int i=(k+1)/2;i<k;i++){
            auto pos = st1.rbegin();
            int val= *pos;
            if(val > v[i]){
                st1.erase(next(pos).base());
                st1.insert(v[i]);
                st2.insert(val);
            }
            else{
                st2.insert(v[i]);
            }  
    }
    cout << *st1.rbegin() << " ";

    for(int i = k;i<n;i++){
        if( st1.find(v[i-k]) != st1.end()){
            st1.erase(st1.find(v[i-k]));
        }
        else if(st2.find(v[i-k]) != st2.end()){
            st2.erase(st2.find(v[i-k]));  
        }

        st1.insert(v[i]);

        while(st1.size()>(k+1)/2){
            auto pos = st1.rbegin();
            int val= *pos;
            st1.erase(next(pos).base());
            st2.insert(val);
        }
            auto pos = st1.rbegin();
            int val= *pos; 
        while(!st2.empty() &&  val > *st2.begin()){
            int val2 = *st2.begin();
            st2.erase(st2.begin());
            st2.insert(val);
            st1.erase(next(pos).base());
            st1.insert(val2);
            pos = st1.rbegin();
            val = *pos;
        }
         cout << *st1.rbegin() << " ";
    }
    cout << endl;
}