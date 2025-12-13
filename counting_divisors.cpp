#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int maxE = *max_element(v.begin(),v.end());
    vector<long long> pre_comput(maxE+1,0);
    int size = pre_comput.size();
    for(int i=1;i<size;i++){
        for(int j=i;j<size;j+=i){
           pre_comput[j]++;
        }
    }
    for(int i=0;i<n;i++){
       cout << pre_comput[v[i]] << endl;
    }
    
}