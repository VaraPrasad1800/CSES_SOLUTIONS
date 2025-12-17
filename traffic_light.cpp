#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,p;
    cin >> x >> p;
    vector<int> v(p);
    for(int i=0;i<p;i++) cin >> v[i];

    set<pair<int,int>> range;
    multiset<int> len;

    range.insert({0,x});
    len.insert(x);

    for(int i = 0;i<p;i++){
        auto pos = range.upper_bound({v[i],0});
        pos--;
        int a = pos->first;
        int b = pos->second;
        range.insert({a,v[i]});
        range.insert({v[i],b});
        int l = b-a;
        range.erase({a,b});
        len.insert(v[i]-a);
        len.insert(b-v[i]);
        len.erase(len.find(l));
        cout << *len.rbegin() << " ";
    }
    cout << endl;
}