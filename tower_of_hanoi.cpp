#include<bits/stdc++.h>
using  namespace std;
void solve(int n,int l,int r,int m){
  if(n==1){
    cout << l << " " << r << endl;
    return ;
  }
  solve(n-1,l,m,r);
  cout << l << " " << r << endl;
  solve(n-1,m,r,l);

}
int main(){
    int n;
    cin >> n;
    cout << pow(2,n)-1 << endl;
    
    solve(n,1,3,2);
    
}
