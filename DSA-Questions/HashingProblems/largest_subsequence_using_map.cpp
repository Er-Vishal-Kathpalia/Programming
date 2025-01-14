#include<iostream>
#include <unordered_map>
using namespace std;

//Hashing 04 - Longest Consecutive Subsequence - I With Unordered Map
int findLargestSequence(int arr[], int n){

	unordered_map<int, int> m;// number, streak_len

	for(int i=0;i<n;i++){
		int no = arr[i];

		if(m.count(no-1)==0 and m.count(no+1)==0){
			m[no] = 1;
		} 
		else if(m.count(no-1) and m.count(no+1) ){
			int len1 = m[no-1];
			int len2 = m[no+1];
			int streak = len1+1+len2;
			m[no-len1] = streak;
			m[no+len2] = streak;		
		} 
		else if( m.count(no-1) and !m.count(no+1) ){
			int len = m[no-1];
			m[no-len] = len+1;
			m[no] = len+1;
		} 
		else{
			int len = m[no+1];
			m[no+len] = len+1;
			m[no] = len+1;
		}
	}

	int largest = 0;
	for(auto it: m){
		largest = max(largest,it.second);
	}
	return largest;

}

int main(){

	int arr[] = {14,5,1,2,6,3,7,8,9,13,15,11,12,13,17,10};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<findLargestSequence(arr,n)<<endl;

	return 0;
}