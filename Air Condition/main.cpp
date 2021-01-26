/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
* Question Link : https://codeforces.com/problemset/problem/1304/C
******************************************/

/*
EXPLANATION: -
Since the range of temperatures can be large, it is impossible to consider all possible cases. However, we only need to find any case that can satisfy all customers, so let's try to maximize the possible range for each customer in the order of their visit time.

Let's define two variables mn and mx, each representing the minimum and maximum possible temperature that can be set now. Initially they are both m and the current time is 0. After K minutes, we can see that the possible range is [mn−K,mx+K]. This means if a customer that visits after K minutes has preferred temperature range [L,R] that intersects with this range (inclusive), Gildong can satisfy that customer. In other words, mn−K≤R and L≤mx+K must be satisfied. Then we can reset mn and mx to fit this intersected range: mn=max(mn−K,L) and mx=min(mx+K,R).

If this can be continued until the last customer, the answer is "YES". Otherwise, the answer is "NO".

Time complexity: O(n) for each test case.

*/


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
	ll int n, temp;
	cin >> n >> temp;
	vector<vector<ll int> > customer(n, vector<ll int>(3));
	for (ll int i = 0; i < n; i++) {
		cin >> customer[i][0] >> customer[i][1] >> customer[i][2];
		// customer[0] : time at which customer will arrive
		// customer[1] : lower range of desired customer temp range
		// customer[2] : upper range of desired customer temp range
	}
	// mn and mx tells us the range of temprature we can be in at time (time)
	ll int mn=temp;  // Initial Range
	ll int mx=temp;
	ll int time=0;
	for(int i=0;i<n;i++){
		mn-=(customer[i][0]-time);   // Range of temprature we can have till customer i arrives
		mx+=(customer[i][0]-time);
		if(customer[i][2]<mn||customer[i][1]>mx){  // If the customer desired range does'nt overlap with our attainable range
			cout<<"NO"<<endl;
			return;
		}
		mn=max(mn,customer[i][1]);  // since we will be in the range of customer i
		mx=min(mx,customer[i][2]);
		time=customer[i][0];
	}
	cout<<"YES"<<endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}