#include <bits/stdc++.h>
using namespace std;

void print(vector<int> ans){
	int s = sizeof(ans)/sizeof(ans[0]);
	for(int i=0;i<s;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return;
}

vector<int> getMaximumXor(vector<int>& nums, int maximumBit){
	
	int maxBitNo = 1;
	while( maximumBit > 0){
		maxBitNo = 2*maxBitNo;
		maximumBit--;
	}
	maxBitNo = maxBitNo-1;

	int n = nums.size();
	
	int ans[n];
	ans[0] = nums[0];
	for(int i=1;i<n;i++){
		ans[i] = ans[i-1]^nums[i];
	}

	for(int i=0;i<n;i++){
		ans[i] = ans[i]^maxBitNo;
	}
	vector<int> ans2;
	for(int i=0;i<n;i++){
		ans2.push_back(ans[i]);
	}
	reverse(ans2.begin(), ans2.end());
	return ans2;
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
	int maximumBit;
	cin>>maximumBit;

	vector<int> ans = getMaximumXor(nums,maximumBit);
	print(ans);
	return 0;
}

/*
2^3 = 8
1<<8

*/
