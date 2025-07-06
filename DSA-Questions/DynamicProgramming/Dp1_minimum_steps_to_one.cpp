#include <bits/stdc++.h>
using namespace std;

//Bottom Up Approach - DP
int min_coins_to_one_dp_bottom_up(int n){
	
	//Build DP
	int dp[100] = {0};
	dp[1] = 0;

	for(int i=2;i<=n;i++){
		int x=INT_MAX,y = INT_MAX,z = INT_MAX;
		if(i%3 == 0){
			x = dp[i/3];
		} 
		if(i%2 == 0){
			y = dp[i/2];
		}
		z = dp[i-1];
		dp[i] = min(min(x,y),z)+1;
	}
	return dp[n];

}


//Top Down Approach - DP
int min_coins_to_one_dp_top_down(int n, int dp[]){

	//Base condition
	if(n == 1){
		return 0;
	}

	//Lookup
	if(dp[n] != -1){
		return dp[n];
	}

	int x = INT_MAX;
	int y = INT_MAX;
	int z = INT_MAX;	
	if(n%3 == 0){
		x = min_coins_to_one_dp_top_down(n/3,dp)+1;
	} 
	if(n%2 == 0){
		y =  min_coins_to_one_dp_top_down(n/2,dp)+1;
	} 
	z = min_coins_to_one_dp_top_down(n-1,dp)+1;
	return dp[n] = min(min(x,y),z);
}


//Recursion
int min_coins_to_one(int n){

	//Base condition
	if(n == 1){
		return 0;
	}

	int x = INT_MAX;
	int y = INT_MAX;
	int z = INT_MAX;	
	if(n%3 == 0){
		x = min_coins_to_one(n/3)+1;
	} 
	if(n%2 == 0){
		y =  min_coins_to_one(n/2)+1;
	} 
	z = min_coins_to_one(n-1)+1;
	return min(min(x,y),z);
}


int main(){

	int n;
	cin>>n;

	int dp[n+1];
	for(int i=0;i<n+1;i++){
		dp[i] = -1;
	}

	cout<<min_coins_to_one(n)<<endl;
	cout<<min_coins_to_one_dp_top_down(n, dp)<<endl;
	cout<<min_coins_to_one_dp_bottom_up(n)<<endl;

	return 0;
}