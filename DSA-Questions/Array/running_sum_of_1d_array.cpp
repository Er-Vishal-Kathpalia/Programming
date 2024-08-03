#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums) {

	for(int i=1;i<nums.size();i++){
		nums[i] = nums[i]+nums[i-1];
	}

	return nums;
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

	vector<int> ans = runningSum(nums);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}