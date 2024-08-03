#include <bits/stdc++.h>
using namespace std;

//Backward recursion
int firstOcc(vector<int>& nums, int n, int key){
	//base condition
	if(n < 0){
		return -1;
	}
	int ans = firstOcc(nums, n-1, key);
	if( nums[n] == key ){
		return n;
	}
}

int lastOcc(vector<int> nums, int n, int key){

	if(n < 0){
		return -1;
	}

	if(nums[n] == key){
		return n;
	}
	return lastOcc(nums, n-1, key);
}


int main(){

	int n; cin>>n;

	vector<int> nums;

	for(int i=0;i<n;i++){
		int temp; cin>>temp;
		nums.push_back(temp);
	}

	int key; cin>>key;

	cout<<firstOcc(nums, n, key)<<" "<<lastOcc(nums, n, key)<<endl;

	return 0;
}