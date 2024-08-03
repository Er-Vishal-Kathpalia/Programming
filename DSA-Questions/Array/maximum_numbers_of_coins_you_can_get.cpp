#include<bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>& piles) {

	//sort
	sort(piles.begin(), piles.end());
	
	int n = piles.size();
	
	int l = 0, r = n-2;
	int ans = 0;
	while(l<r){
		ans += piles[r];
		l++;
		r-=2;
	}

	return ans;
}


int main(){

	int n;
	cin>>n;
	vector<int> nums(n,0);

	for(int i=0;i<n;i++){
		int temp; cin>>temp;
		nums[i] = temp;
	}

	cout<<maxCoins
	(nums)<<endl;

	return 0;
}