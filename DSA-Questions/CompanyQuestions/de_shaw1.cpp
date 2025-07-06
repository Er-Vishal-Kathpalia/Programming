#include <bits/stdc++.h>
using namespace std;

int countSortedSubarrays(vector<int>& arr) {
    int n = arr.size();
    
    vector<bool> left(n+2);
    vector<bool> right(n+2);

    left[0] = true;
    right[n+1] = true;

    for(int i=0;i<n;i++){
        left[i+1] = (left[i] && (i==0 || arr[i-1]<=arr[i]));
    }

    for(int i=n-1;i>=0;i--){
        right[i+1] = (right[i+2] && (i==n-1 || arr[i]<=arr[i+1]));
    }


    int count = 0;
    for (int i = 1,j=1;i <= n; ++i) {
        while(j<=n and (right[j] == false || j<=i || (i!=1 and arr[i-2] > arr[j-1]))){
            j++;
        }
        if(left[i-1] == true){
            count += n+2-j;
        }
    }
    
    return count-1;
}



int main(){

    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<countSortedSubarrays(arr)<<endl;
    return 0;
}