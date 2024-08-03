#include<bits/stdc++.h>
using namespace std;

/*
Given two sorted arrays nums1 and nums2 of sizes m and n respectively, return the median of the two sorted arrays. You have to return an integer kind of value.

The overall run time complexity should be O(log (m+n)).

Example:

Input:

nums1 = [1,3], nums2 = [2]
Output:

2
Explanation:
Merged array = [1,2,3] and the median is 2.

Input:

nums1 = [1,2], nums2 = [3,4]
Output:

2
Explanation:
Merged array = [1,2,3,4] and the median is (2 + 3) / 2 = 2.5 but you have to return (2+3)/2 which will give the final output as 2, so basically return the floor(median).

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/

int getMedian(int ar1[], int ar2[], int n, int m){
	
	int total_size = n+m;
	int i,j,k=0;
	int temp[total_size];
	while(i<n && j<n){
		if( ar1[i] <= ar2[j] ){
			temp[k++] = ar1[i++];
		} else{
			temp[k++] = ar2[j++];
		}
	}

	while(i<n){
		temp[k++] = ar1[i++];
	}

	while(j<n){
		temp[k++] = ar2[j++];
	}

	int mid = total_size/2;

	if( total_size%2 == 0 ){
		return (temp[mid]+temp[mid-1])/2;
	}
	return temp[mid];
}


int main(){

	int n,m;
	cin>>m>>n;
	int ar1[n];
	int ar2[m];

	for(int i=0;i<m;i++){
		int temp; cin>>temp;
		ar1[i] = temp;
	}


	for(int i=0;i<n;i++){
		int temp; cin>>temp;
		ar2[i] = temp;
	}

	cout<<getMedian(ar1, ar2, n, m)<<endl;

	return 0;
}

/*
1 2 3 4

4/2 = 2 == 3

1 2 3

3/2 == 1


*/