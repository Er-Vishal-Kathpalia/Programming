#include <bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int>& gain) {

	int altitude = 0;
	int maxAltitude = 0;
	for(int i=0;i<gain.size();i++){
		altitude = altitude + gain[i];
		maxAltitude = max(altitude,maxAltitude);
	}

	return maxAltitude;
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

	cout<<largestAltitude(nums)<<endl;
	return 0;
}