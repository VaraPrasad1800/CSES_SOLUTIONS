#include<bits/stdc++.h>
using namespace std;

bool check(int r,int c,vector<vector<char>>& v){
    if(v[r][c] == '*') return false;
    for(int i=r-1;i>=0;i--){
        if(v[i][c] == 'Q') return false;
    }
    int i = r-1,j = c+1;
    while(!(i < 0 || j >=8)){
        if(v[i][j] == 'Q') return false;
        i--;
        j++;
    }
     i = r-1;
     j = c-1;
    while(!(i < 0 || j <0)){
        if(v[i][j] == 'Q') return false;
        i--;
        j--;
    }
    return true;

}

void places(int& ans,int r,vector<vector<char>>& v){
    if(r==8){
        ans++;
        return;
    }

    for(int c=0;c<8;c++){
         if(check(r,c,v)){
            v[r][c] = 'Q';
            places(ans,r+1,v);
            v[r][c] = '.';
         }
    }
}


int main(){
    vector<vector<char>> v(8,vector<char>(8));

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin >> v[i][j];
        }
    }
    int ans = 0;
    places(ans,0,v);
    cout << ans << endl;

}