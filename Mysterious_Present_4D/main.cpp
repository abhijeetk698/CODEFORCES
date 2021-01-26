/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
******************************************/
#include <iostream>
#include <vector>
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

vector<pair<int,int> >v;

class Graph{
	short int n;
	vector<short int> *adj;
public:
	Graph(short int v):n(v){
		adj=new vector<short int>[n];
	}
	void addEdge(short int a,short int b){
		adj[a].push_back(b);
	}

	void dfs(short int src,vector<short int>&dist){
		dist[src]=1;
		short int m=0;
		for(short int x:adj[src]){
			if(dist[x]==-1){
				dfs(x,dist);
			}
			m=max(m,dist[x]);
		}
		dist[src]+=m;
		return;
	}
	void dfs_print(short int src,vector<short int>&dist){
		cout<<src+1<<" ";
		short int maxIndex=-1;
		short int m=0;
		for(short int x:adj[src]){
			if(dist[x]>m){
				m=dist[x];
				maxIndex=x;
			}
		}
		if(maxIndex==-1){
			return;
		}
		dfs_print(maxIndex,dist);
		return;
	}
	void answer(int w,int h){
		vector<short int> dist;
		dist.assign(n,-1);
		for(short int i=0;i<n;i++){
			if(dist[i]==-1){
				dfs(i,dist);
			}
		}
		short int maxAns=0;
		short int maxIndex=-1;
		for(int i=0;i<n;i++){
			if(w<v[i].first&&h<v[i].second){
				if(dist[i]>maxAns){
					maxAns=dist[i];
					maxIndex=i;
				}
			}
		}
		
		cout<<maxAns<<endl;
		if(maxAns!=0){
			dfs_print(maxIndex,dist);
			cout<<endl;
		}
		return ;
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	short int n;
	int w,h;
	cin>>n>>w>>h;
	v.reserve(n);
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		v[i]={a,b};
	}
	Graph G(n);
	for(short int i=0;i<n;i++){
		for(short int j=0;j<n;j++){
			if((v[i].first<v[j].first)&&(v[i].second<v[j].second)){
				G.addEdge(i,j);
			}
		}
	}
	G.answer(w,h);		
	return 0;
}