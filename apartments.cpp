#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> applicant(n);
    vector<int> apartment(m);
    for(int i = 0;i<n;i++){
        cin >> applicant[i];
    }
    for(int i = 0;i<m;i++){
        cin >> apartment[i];
    }
    sort(applicant.begin(),applicant.end());
    sort(apartment.begin(),apartment.end());

    int i = 0,j=0;
    int cnt = 0;
    while(i<n && j<m){
       if(apartment[j]<(applicant[i]-k)) j++;
       else if(apartment[j]>(applicant[i]+k)) i++;
       else{
        i++;
        j++;
        cnt++;
       }
    }
    cout << cnt << endl;
}