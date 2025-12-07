#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x1,y1,x2,y2,x3,y3;
        cin  >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        long long dx1 = x2 - x1;
        long long dy1 = y2 - y1;
        long long dx2 = x3 - x1;
        long long dy2 = y3 - y1;

       long long ans = dx1 * dy2 - dx2 * dy1;

        if(ans == 0) cout << "TOUCH" << endl;
        else if(ans<0) cout << "RIGHT" << endl;
        else cout << "LEFT" << endl;

    }
}