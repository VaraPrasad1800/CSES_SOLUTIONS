#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int left=0,right=0;
    int sum = 0;
    int cnt = 0;
    while(right<n){
            sum+=v[right];
        if(sum==x){
            sum-=v[left];
            cnt++;
            left++;
        }
        if(sum>x){
            while(sum>x){
                sum-=v[left];
                left++;
            }
            if(sum==x){
                cnt++;
                sum-=v[left];
                left++;
            }
        }
        right++;
    }

    cout << cnt << endl;
}