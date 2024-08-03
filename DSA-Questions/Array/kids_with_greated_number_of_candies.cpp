#include <bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
	vector<bool> ans;

	int maximumCandy = INT_MIN; 
	for(int i=0;i<candies.size();i++){
		maximumCandy = max(maximumCandy,candies[i]);
	}

	for(int i=0;i<candies.size();i++){
		int updatedCandy = candies[i]+extraCandies;
		if( updatedCandy < maximumCandy ){
			ans.push_back(false);
		} else{
			ans.push_back(true);
		}
	}

	return ans;
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
	int extraCandies;
	cin>>extraCandies;

	vector<bool> ans = kidsWithCandies(nums,extraCandies);
	for(int i=0;i<ans.size();i++){
		if(ans[i]){
			cout<<"true"<<" ";
		} else{
			cout<<"false"<<" ";
		}
	}
	cout<<endl;
	return 0;
}