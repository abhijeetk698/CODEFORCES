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
    ll int a,b,k;
    cin>>a>>b>>k;
    vector<ll int> A(k);
    for(int i=0;i<k;i++){
        cin>>A[i];
    }vector<ll int> B(k);
    for(int i=0;i<k;i++){
        cin>>B[i];
    }
    set<pair<ll int,ll int> > S;
    for(int i=0;i<k;i++){
        S.insert(mp(A[i],B[i]));
    }
    ll int ans=0;
    ll int sum=S.size();
    vector<ll int> freq_boy(a+1,0);
    vector<ll int> freq_girl(b+1,0);
    vector<pair<ll int,ll int> > pairs; 
    for(auto x:S){
        freq_boy[x.F]++;
        freq_girl[x.S]++;
        pairs.pb(mp(x.F,x.S));
    }
    for(auto x:pairs){
        ll int boy=x.F;
        ll int girl=x.S;
        ans+=((sum-1)-(freq_boy[boy]-1)-(freq_girl[girl]-1));
        sum--;
        freq_girl[girl]--;
        freq_boy[boy]--;
    }
    cout<<ans<<endl;
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