#include <bits/stdc++.h>
using namespace std;
int val = 1000000007;
int dou_val = 500000004;

int main(){
	long long n;
    cin >> n;

	long long total = 0;
	long long i = 1;
	while (i<= n) {
		long long k = n/i;
		long long last = n /k;
        long long sum = ((((last-i+1)%val)*((last+i)%val) %val)*dou_val%val);
		total = (total + (k*sum)%val)%val;
		i = last+1;
	}
	cout << total << endl;
}