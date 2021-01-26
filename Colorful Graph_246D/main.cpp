/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
******************************************/
#include <iostream>
#include <map>
#include <climits>
#include <vector>
#include <unordered_set>
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

vector<int> clr;

class Graph{
	int n;
	vector<int>*adj;
public:
	Graph(int v):n(v){
		adj=new vector<int>[n+1];
	}
	void addEdge(int a,int b){
		adj[b].push_back(a);
		adj[a].push_back(b);
	}
	void dfs(int src,bool*visited,map<int,int>&color,map<int,unordered_set<int> >&div){
		visited[src]=true;
		for(int x:adj[src]){
			if(!visited[x]){
				dfs(x,visited,color,div);
			}
			if(clr[x]!=clr[src]){
				if(div[clr[src]].find(clr[x])==div[clr[src]].end()){
				div[clr[src]].insert(clr[x]);
				color[clr[x]]++;
				}
			}
		}
		return;
	}
	int  answer(){
		bool visited[n+1];
		map<int,int> color;
		map<int,unordered_set<int> >div; 
		for(int i=1;i<=n;i++){
			visited[i]=false;
			color[clr[i]]=0;
		}
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				dfs(i,visited,color,div);
			}
		}
		int maxValue=0;
		for(auto x:color){
			maxValue=max(maxValue,x.second);
		}
		int minValue=INT_MAX;
		for(auto x:color){
			if(x.second==maxValue){
				minValue=min(minValue,x.first);
			}
		}
		return minValue;
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,e;
	cin>>n>>e;
	clr.reserve(n+1);
	for(int i=1;i<=n;i++){
		cin>>clr[i];
	}	
	Graph G(n);
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		G.addEdge(a,b);
	}
	cout<<G.answer()<<endl;
	return 0;
}