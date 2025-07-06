#include <bits/stdc++.h>
using namespace std;

// Bottom Up Approach + Reduce more space complexity
// Space Complexity= O(1) and Time Complexity = O(N), Linear
// Matrix Exponentiation
int fibo_space_optimized(int n){

	if( n==0 || n==1 ){
		return n;
	}
	int a = 0;
	int b = 1;
	int c;

	for(int i=2;i<=n;i++){
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

//Bottom Up Approach
// Space Complexity= O(N) and Time Complexity = O(N), Linear
int fibo_with_dp_bottom_up(int n){

	int dp[n+1];
	for(int i=0;i<n+1;i++){
		dp[i] = 0;
	}
	dp[1] = 1;

	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1]+dp[i-2];
	}

	return dp[n];
}


//Top Down Approach
// Space Complexity= O(N) and Time Complexity = O(N), Linear
int fibo_with_dp(int n, int dp[]){
	
	//Base condition
	if(n==0 || n==1){
		return n;
	}
	//Lookup and return from dp
	if(dp[n] != 0){
		return dp[n];
	}

	int ans;
	ans = fibo_with_dp(n-1, dp)+fibo_with_dp(n-2, dp);
	//store in dp as well
	return dp[n] = ans;
}


// Space Complexity= O(N) and Time Complexity = O(2^N), Linear
int fibo(int n){
	
	//Base condition
	if(n==0 || n==1){
		return n;
	}
	int ans = fibo(n-1)+fibo(n-2);
	return ans;
}


int main(){

	int n;
	cin>>n;

	int dp[n+1];
	for(int i=0;i<n+1;i++){
		dp[i] = 0;
	}

	cout<<fibo(n)<<endl;
	cout<<fibo_with_dp(n,dp)<<endl;
	cout<<fibo_with_dp_bottom_up(n)<<endl;
	cout<<fibo_space_optimized(n)<<endl;

	return 0;
}