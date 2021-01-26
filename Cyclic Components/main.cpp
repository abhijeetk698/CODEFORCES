/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* QUESTION : https://codeforces.com/contest/977/problem/E *
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

class Graph{
	int n;
	vector<int>*adj;
public:
	Graph(int n){
		this->n=n;
		adj=new vector<int>[n+1];
	}	

	void addEdge(int a,int b){
		adj[a].pb(b);
		adj[b].pb(a);
	}

	bool isCyclicComponent(int src,vector<bool>&visited){
		visited[src]=true;
		bool isCyclic=(adj[src].size()==2);
		for(int x:adj[src]){
			if(!visited[x]){
				isCyclic=(isCyclicComponent(x,visited) && isCyclic);
			}
		}
		return isCyclic;
	}

	int numberOfCyclicComponents(){
		vector<bool> visited(n+1,false);
		int count=0;
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				if(isCyclicComponent(i,visited)){
					count++;
				}
			}
		}
		return count;
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	Graph G(n);
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		G.addEdge(a,b);
	}
	cout<<G.numberOfCyclicComponents()<<endl;
	return 0;
}