#include<bits/stdc++.h>
using namespace std;

// //Adjacency list
// void addEdge(vector<int> adj[], int u, int v){
// 	adj[u].push_back(v);
// 	adj[v].push_back(u);
// }


// void print(vector<int> adj[], int v){
// 	for(int i=0;i<v;i++){
// 		cout<<"adjancy matrix of vertex "<<i<<" "<<endl;
// 		for(auto x: adj[i]){
// 			cout<<x<<" ";
// 		}
// 		cout<<endl;
// 	}
// }


//Adjacency Matrix
void print(vector<int> adj[], int m, int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}


int main(){

	// int v;
	// cin>>v;
	// cout<<"Is directed"<<endl;
	// bool isDirected;
	// cin>>isDirected;

	// vector<int> adj[v];
	// addEdge(adj,0,1);
	// addEdge(adj,0,4);
	// addEdge(adj,1,2);
	// addEdge(adj,1,3);
	// addEdge(adj,1,4);
	// addEdge(adj,2,3);
	// addEdge(adj,3,4);

	// print(adj,v);


	int m,n,u,v;
	cin>>m>>n;

	vector<int> adj[n];

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	print(adj,m,n);

	return 0;
}





















