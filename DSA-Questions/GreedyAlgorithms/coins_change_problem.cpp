#include <bits/stdc++.h>
using namespace std;

int coins_change(int coins[], int n, int money){

	int ans = 0;
	while(money > 0){
		int idx = upper_bound(coins,coins+n,money) - 1 - coins;
		money = money - coins[idx];
		cout<<coins[idx]<<" + ";
		ans++;
	}
	cout<<endl;
	return ans;
}


int main(){

	int money;
	cin>>money;

	int coins[] = {1,2,5,10,20,50,100,200,500,2000};
	int n = sizeof(coins)/sizeof(coins[0]);

	cout<<coins_change(coins,n,money)<<endl;

	return 0;
}