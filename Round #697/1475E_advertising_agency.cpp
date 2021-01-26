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

bool comparator(pair<ll int,ll int> a,pair<ll int,ll int> b){
    return a.F>b.F;
}

unsigned long long power(unsigned long long x, 
                                  int y, int p)
{
    unsigned long long res = 1; 
    x = x % p; 
 
    while (y > 0) 
    {
     
        if (y & 1)
            res = (res * x) % p;
 
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
unsigned long long modInverse(unsigned long long n,  
                                            ll int p)
{
    return power(n, p - 2, p);
}

unsigned long long nCrModPFermat(unsigned long long n,
                                 ll int r, ll int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
 
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

void solve(){
    ll int n,k;
    cin>>n>>k;
    map<ll int,ll int> freq;
    for(int i=0;i<n;i++){
        ll int a;
        cin>>a;
        freq[a]++;
    }
    vector<pair<ll int,ll int> > v;
    for(auto x:freq){
        v.pb(x);
    }
    sort(v.begin(),v.end(),comparator);
    n=(int)v.size();
    for(int i=0;i<n;i++){
        if(k>v[i].S){
            k-=v[i].S;
        }else{
            cout<<nCrModPFermat(v[i].S,k,MOD)<<endl;
            return;
        }
    }
    return ;
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