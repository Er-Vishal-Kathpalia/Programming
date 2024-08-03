#include<bits/stdc++.h>
using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sum =0;
    for(int i=0; i<nums.size(); i+=2){
        sum +=min(nums[i], nums[i+1]);
    }
    return sum;
}


int main(){

	int n;
	cin>>n;
	vector<int> nums(n,0);

	for(int i=0;i<n;i++){
		int temp; cin>>temp;
		nums[i] = temp;
	}

	cout<<arrayPairSum(nums)<<endl;

	return 0;
}