#include<iostream>
using namespace std;


int binary_search( int n, int arr[], int key ){

	int start = 0;
	int end = n-1;
	while( start<=end ){
		int mid = (start+end)/2;
		if( arr[mid] == key ){
			return mid;
		}
		else if( arr[mid] > key ){
			end = mid-1;
		}
		else {
			start = mid+1;
		}

	} 
	return -1;
}


int main(){
	int n;
	cin>>n;
	int arr[n];
	for( int i=0;i<n;i++ ){
		cin>>arr[i];
	}
	int key;
	cin>>key;
	cout<<binary_search(n, arr, key )<<endl;	
}