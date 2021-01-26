/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
* Question link : https://codeforces.com/problemset/problem/1307/C
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
	string s;
	cin >> s;
	int n = s.size();
	vector<ll int> freq1(26, 0);
	vector<vector<ll int> >freq2(26, vector<ll int>(26, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			freq2[j][(s[i] - 'a')] += freq1[j];
		}
		freq1[s[i] - 'a']++;
	}
	ll int ans = 0;
	for (int i = 0; i < 26; i++) {
		ans = max(ans, freq1[i]);
	} for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			ans = max(ans, freq2[i][j]);
		}
	}
	cout << ans << endl;
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}