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

class Graph{
	int n;
	vector<int> *adj;
public:
	Graph(int v):n(v){
		adj=new vector<int>[n+1];
	}
	void addEdge(int a,int b){
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int dfs(int src,bool*visited){
		visited[src]=true;
		int count=1;
		for(int x:adj[src]){
			if(!visited[x]){
				count+=dfs(x,visited);
			}
		}
		return count;
	}
	void dfsPrint(int src,bool*visited){
		visited[src]=true;
		cout<<src<<" ";
		for(int x:adj[src]){
			if(!visited[x]){;
				dfsPrint(x,visited);
			}
		}
		return ;	
	}
	bool answer(){
		bool visited[n+1];
		vector<vector<int> > v(4);
		for(int i=0;i<=n;i++){visited[i]=false;}
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				int count=dfs(i,visited);
				if(count>3){
					return false;
				}
				v[count].push_back(i);
			}
		}
		if(v[1].size()<v[2].size()){
			return false;
		}
		int N=v[2].size();
		for(int i=0;i<=n;i++){
			visited[i]=false;
		}
		for(int i=0;i<N;i++){
			dfsPrint(v[1][i],visited);
			dfsPrint(v[2][i],visited);
			cout<<endl;
		}	
		for(int i=N;i<v[1].size();i+=3){
			for(int j=i;j<i+3;j++){
				cout<<v[1][j]<<" ";
			}
			cout<<endl;
		}
		N=v[3].size();
		for(int i=0;i<N;i++){
			dfsPrint(v[3][i],visited);
			cout<<endl;
		}
		return true;
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,e;
	cin>>n>>e;
	Graph G(n);
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		G.addEdge(a,b);
	}
	if(!G.answer()){
		cout<<-1<<endl;
	}
	return 0;
}