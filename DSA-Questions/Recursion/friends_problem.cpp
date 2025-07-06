#include<bits/stdc++.h>
#define ll long long int
using namespace std;

/*
Given N, friends who want to go to a party on bikes. Each guy can go as single, or as a couple. 
Find the Number of ways in which N friends can go to the party.
N=3
Ways = 4
Solution is formula based
*/

//Memorize 
int noOfWaysToGoAtParty(int n){

	//base case
	if(n<0){
		return 0;
	}
	if(n==0){
		return 1;
	}
	if(n>0 && n<=2){
		return n;
	}

	int firstWay = noOfWaysToGoAtParty(n-1);
	int secondWay = noOfWaysToGoAtParty(n-2);
	return 1*firstWay+(n-1)*secondWay;
}

// Tabulation approach
int noOfWaysToGoAtPartyTabulation(int n) {
    if (n <= 2) return n;
    
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1]+(i-1)*dp[i - 2];
    }
    
    return dp[n];
}

int main(){

	int n;
	cin>>n;

	cout<<noOfWaysToGoAtParty(n)<<endl;
	cout<<noOfWaysToGoAtPartyTabulation(n)<<endl;	

	return 0;
}


/*

*/