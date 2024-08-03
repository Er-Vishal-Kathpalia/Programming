#include <bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int>& encoded, int first) {

	int n = encoded.size();

	int second = first^encoded[0];
	encoded[0] = second;
	for(int i=1;i<n;i++){
		encoded[i] = encoded[i]^encoded[i-1];
	}
	encoded.resize(n+1);
	for(int i=n;i>=0;i--){
		encoded[i+1] = encoded[i];
	}
	encoded[0] = first;
	return encoded;
}

int main(){

	int n;
	cin>>n;

	vector<int> nums;

	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		nums.push_back(temp);
	}
	int first;
	cin>>first;

	vector<int> ans = decode(nums,first);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}