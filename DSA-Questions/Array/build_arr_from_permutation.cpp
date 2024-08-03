#include <bits/stdc++.h>
using namespace std;

//Approach 1 - Brute Force
/*
vector<int> buildArray(vector<int>& nums){
	vector<int> ans;
    int n = nums.size();

    for(int i=0;i<n;i++){
        int var = nums[i];
        ans.push_back(nums[var]);
    }

    return ans;
}
*/

//Approach 2 - Optimization
vector<int> buildArray(vector<int>& nums){

	int n = nums.size();
	
	for(int i=0;i<n;i++){
		nums[i] = nums[i] + (1000 * (nums[nums[i]]%1000));
	}

	for(int i=0;i<n;i++){
		nums[i] = nums[i]/1000;
	}

	return nums;
}


void print(vector<int> ans){
	int s = sizeof(ans)/sizeof(ans[0]);
	for(int i=0;i<s;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return;
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

	vector<int> ans = buildArray(nums);
	print(ans);

	return 0;
}