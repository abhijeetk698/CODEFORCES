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

void solve(){
	int n,x;
	cin>>n>>x;
	int deg=0;
	for(int i=0;i<(n-1);i++){
		int a,b;
		cin>>a>>b;
		deg+=(a==x)+(b==x);
	}
	if(deg==1){
		cout<<"Ayush"<<endl;
		return;
	}
	if(n&1){
		cout<<"Ashish"<<endl;	
	}else{
		cout<<"Ayush"<<endl;
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
 	int t;
 	cin>>t;
 	while(t--){
 		solve();
 	}  
    return 0;
}