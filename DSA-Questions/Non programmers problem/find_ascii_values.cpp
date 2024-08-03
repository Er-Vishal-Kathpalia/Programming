#include<bits/stdc++.h>
using namespace std;

int main(){

	//find Ascii value of char
	// char c;
	// cin>>c;
	// int ans = (int) c;
	// cout<<ans<<endl;

	//find Ascii value of string
	string s;
	cin>>s;

	for(auto x:s){
		int asci = (int) x;
		cout<<asci<<" ";
	}
	cout<<endl;
	return 0;
}