#include<bits/stdc++.h>
using namespace std;

void permute(char *in, int i){

	//base case
	if(in[i] == '\0'){
		cout<<in<<" ";
		return;
	}

	//recursive case
	for(int j=i;in[j]!='\0';j++){
		swap(in[i],in[j]);
		permute(in,i+1);
		//Backtracking
		swap(in[i],in[j]);
	}

}


int main(){

	char in[100];
	cin>>in;

	permute(in, 0);
	cout<<endl;

	return 0;
}