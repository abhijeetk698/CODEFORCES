/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
* Question Link : https://codeforces.com/problemset/problem/165/C
******************************************/


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second

void solve() {
	ll int k;
	cin >> k;
	string s;
	cin >> s;
	int n = s.size();
	vector<ll int> freq(n + 1, 0);
	for (int i = 0; i < n; i++) {
		freq[i + 1] = freq[i] + (s[i] == '1');
	}
	// number of 1's in the range [i,j] is freq[j+1]-freq[i]
	ll int ans = 0;
	map<ll int, ll int> count;
	for (int i = (n - 1); i >= 0; i--) {
		if (count.find(freq[i + 1]) == count.end()) {
			count[freq[i + 1]] = 0; // here we are storing (j+1)th value
		} count[freq[i + 1]]++;
		if (count.find(freq[i] + k) != count.end()) { // we are finding the count of values having freq[j+1] as freq[i]+k
			ans += count[freq[i] + k];
		}
	}
	cout << ans << endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}