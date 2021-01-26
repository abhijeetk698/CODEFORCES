/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
******************************************/
#include <iostream>
#include <vector>
#include <climits>

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

class Graph{
	int n;
	vector<int>*adj;
	vector<int>*temp;
	bool**visited;
public:
	Graph(int N):n(N){
		adj=new vector<int>[n+1];
		temp=new vector<int>[n+1];
		visited=new bool*[n+1];
		for(int i=0;i<=n;i++){
			visited[i]=new bool[n+1];
		}
	}
	void addEdge(int a,int b){
		adj[a].push_back(b);
		temp[a].push_back(a);
		temp[b].push_back(b);
		visited[a][b]=true;
		return;
	}	

	int dfs(int src,bool*visited){
		if(visited[src]){
			return -1;
		}
		visited[src]=true;
		int a=0;
		for(int x:adj[src]){
			a+=dfs(x,visited);
		}
		return a;
	}
	void answer(){
		vector<int> dp(n+1);
		dp[1]=n-1;
		bool visited[n+1];
		for(int i=0;i<=n;i++){visited[i]=false;}
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				dp[1]+=dfs(i,visited);
			}
		}

	}


};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	Graph G(n);
	for(int i=0;i<(n-1);i++){
		int a,b;
		cin>>a>>b;
		G.addEdge(a,b);
	}
	G.answer();
	return 0;
}