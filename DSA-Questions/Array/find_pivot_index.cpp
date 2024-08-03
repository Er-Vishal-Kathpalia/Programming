#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums){

	int n = nums.size();
	int left[n+1];
	int right[n+1];

	int cs = 0;
	left[0] = cs;
	for(int i=1;i<n;i++){
		left[i] = left[i-1] + nums[i-1];
	}

	cs = 0;
	right[n-1] = 0;
	for(int i=n-2;i>=0;i--){
		right[i] = right[i+1] + nums[i+1];	
	}

	for(int i=0;i<n;i++){
		if( left[i] == right[i] ){
			return i;
		}
	}
	return -1;
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

	cout<<pivotIndex(nums)<<endl;
	return 0;
}
