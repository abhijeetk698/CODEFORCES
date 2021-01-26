#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void answer(int n,int c,vector<int>&s,vector<int>&e){
	vector<int> dp0;
	vector<int> dp1;
	dp0.assign(n,INT_MAX);
	dp1.assign(n,INT_MAX);
	dp0[0]=0;
	dp1[0]=c;
	for(int i=1;i<n;i++){
		dp0[i]=min(dp0[i],dp0[i-1]+s[i-1]);
		dp0[i]=min(dp0[i],dp1[i-1]+s[i-1]);
		dp1[i]=min(dp1[i],dp0[i-1]+e[i-1]+c);
		dp1[i]=min(dp1[i],dp1[i-1]+e[i-1]);
	}	
	for(int i=0;i<n;i++){
		cout<<min(dp0[i],dp1[i])<<" ";
	}
	cout<<endl;
	return;
}

int main(){
	int n,c;
	cin>>n>>c;
	vector<int> s(n-1);
	vector<int> e(n-1);
	for(int i=0;i<n-1;i++){
		cin>>s[i];
	}
	for(int i=0;i<n-1;i++){
		cin>>e[i];
	}
	answer(n,c,s,e);
	return 0;
}