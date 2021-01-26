/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
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
	ll int n, k;
	cin >> n >> k;
	vector<ll int> height(n);
	for (ll int i = 0; i < n; i++) {
		cin >> height[i];
	}
	ll int m = height[0];
	ll int M = height[0] + k;
	for (ll int i = 1; i < (n - 1); i++) {
		ll int x = height[i];
		ll int y = min(height[i] + (k - 1) + k, M + k - 1);
		if (x >= M || m >= y) {
			cout << "NO" << endl;
			return ;
		}
		m=max(x,m-(k-1));
		M=min(y,M+(k-1));
	}
	if ((height[n - 1] >= M) || (m >= (height[n - 1] + k))) {
		cout << "NO" << endl;
		return;
	} cout << "YES" << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}