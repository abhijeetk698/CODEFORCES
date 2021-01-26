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

void initialize(vector<ll int>&dp,ll int k){
	for(int i=0;i<k;i++){
		dp[i]=1;
	}for(int i=k;i<=100000;i++){
		dp[i]=(dp[i-1]+dp[i-k])%MOD;
	}
	return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll int t,k;
 	cin>>t>>k;
 	ll int n=100000;
 	vector<ll int> dp(n+1,0);
 	initialize(dp,k);
 	vector<ll int> preSum(n+2,0);
 	preSum[0]=0;
 	for(int i=0;i<=n;i++){
 		preSum[i+1]=(preSum[i]+dp[i])%MOD;
 	}
 	while(t--){
 		ll int a,b;
 		cin>>a>>b;
 		cout<<((preSum[b+1]%MOD-preSum[a]%MOD)+MOD)%MOD<<endl;
 	}
    return 0;
}