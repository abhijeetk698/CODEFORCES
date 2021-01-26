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

bool comparator(ll int a, ll int b) {
    return (a > b);
}

void solve() {
    ll int n, m;
    cin >> n >> m;
    vector<ll int> a(n);
    ll int weight = 0;
    for (ll int i = 0; i < n; i++) {
        cin >> a[i];
        weight += a[i];
    }
    vector<ll int> b(n);
    for (ll int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<ll int> one;
    vector<ll int> two;
    for (ll int i = 0; i < n; i++) {
        if (b[i] == 1) {
            one.pb(a[i]);
        } else {
            two.pb(a[i]);
        }
    }
    sort(one.begin(), one.end(), comparator);
    sort(two.begin(), two.end(), comparator);
    if (weight < m) {
        cout << -1 << endl;
        return;
    }
    weight = 0;
    ll int i = 0;
    ll int j = 0;
    while (i < one.size() && weight < m) {
        weight += one[i++];
    } while (j < two.size() && weight < m) {
        weight += two[j++];
    }
    // i = number of regular apps
    // j = number of important apps
    ll int ans = i * 1 + j * 2;
    while (i >= 1 && weight >= m) {
        weight -= one[--i];
        while (j < two.size() && weight < m) {
            weight += two[j++];
        } if (weight >= m) {
            ans = min(ans, (i * 1 + j * 2));
        }
    }
    cout << ans << endl;
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}