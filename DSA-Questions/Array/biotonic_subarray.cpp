#include<bits/stdc++.h>
using namespace std;

int biotonic_subarray(int arr[], int n){

	int ans = 0;

	for(int i=0;i<n;i++){
		if( arr[i-1] <= arr[i] ){
			ans++;
		} 
	}

}

int main(){

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<biotonic_subarray(arr, n)<<endl;
	}
	return 0;
}