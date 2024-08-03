#include<bits/stdc++.h>
using namespace std;

int main(){

	string s;
	getline(cin, s, '.');

	string ans = "";
	string temp = "";
	int j=-1;
	for( auto x:s){
		j++;
		temp[0] = to_string(x);
		if( x == ' ' ){
			ans = temp;
			cout<<"her"<<endl;
			j = 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
