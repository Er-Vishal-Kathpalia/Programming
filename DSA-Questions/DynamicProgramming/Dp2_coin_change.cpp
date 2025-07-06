#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount){

	//Base condition
	if(amount < 0){
		return -1;
	}

	for(int i=coins.size()-1;i>=0;i--){
		if(coins[i] <= amount){
			return coinChange(coins,amount-coins[i])+1;
		}
	}

	return -1;
}

/*
TC 
3
1 2 5
11
*/

int main(){

	int n;
	cin>>n;
	vector<int> coins;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		coins.push_back(temp);
	}

	int amount;
	cin>>amount;

	cout<<coinChange(coins,amount)<<endl;
	return 0;
}