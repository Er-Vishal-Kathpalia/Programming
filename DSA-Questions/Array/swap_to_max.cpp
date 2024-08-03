#include<bits/stdc++.h>
using namespace std;

/*
You are given two arrays a1,a2,…,an and b1,b2,…,bn. In one operation, you can choose any integer i from 1 to n and swap the numbers a (ith) and b (ith).

Determine whether, after using any (possibly zero) number of operations, the following two conditions can be satisfied simultaneously:
1.  a(nth) = max(a1,a2,…,an)
2. b(nth) = max(b1,b2,…,bn)
Here max(c1,c2,…,ck) denotes the maximum number among c1,c2,…,ck. For example, max(3,5,4)=5, max(1,7,7)=7, max(6,2)=6

Input Format:

1. The first line contains an integer 'n' denoting the length of arrays.
2. The second line contains the elements of array 'a'.
3. The third line contains the elements of array 'b'.
Output Format:
If the above conditions can be met, print "YES" else print "NO".

Sample Input:


3

7 9 7

7 6 9

Sample Output:

"YES"

Explanation: You can swap the numbers a3 and b3 after which the array a becomes equal to [7,9,9] and the array b becomes equal to [7,6,7] and both conditions are met.

Constraints:

1≤n≤100

1≤ai≤10^4

1≤bi≤100^4
*/

int findMax(vector<int>& nums ){
	int mx = 0;
	for(int i=1;i<nums.size();i++){
		if( nums[i] > nums[mx] ){
			mx = i;
		}
	}
	return mx;
}

void solve(int n, vector<int>& a, vector<int>& b) {

	int aMaxIndex = findMax(a);
	int bMaxIndex = findMax(b);

	int aMax = a[aMaxIndex];
	int bMax = b[bMaxIndex];

	//swap the indexes for aMax

}


int main(){

	int n;
	cin>>n;

	vector<int> a;
	vector<int> b;
	for(int i=0;i<n;i++){
		int temp; cin>>temp;
		a.push_back(temp);
	}

	for(int i=0;i<n;i++){
		int temp; cin>>temp;
		b.push_back(temp);
	}

	if(solve(n,a,b)){
		cout<<"Yes"<<endl;
	} else{
		cout<<"No"<<endl;
	}
	return 0;
}

/*
3

7 9 7
7 6 9

*/