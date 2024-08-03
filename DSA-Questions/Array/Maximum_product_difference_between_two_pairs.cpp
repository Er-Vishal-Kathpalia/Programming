#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int findMaximum(vector<int>& nums){
    int ans = INT_MIN;
    int index = -1;
    for(int i=0;i<nums.size();i++){
        if( nums[i]>0 && nums[i] >= ans ){
            ans = nums[i];
            index=i;
        }
    }
    nums[index] = -1;
    return ans;
}

int findMinimum(vector<int>& nums){
    int ans = INT_MAX;
    int index = -1;
    for(int i=0;i<nums.size();i++){
        if( nums[i]>0 && nums[i] <= ans ){
            ans = nums[i];
            index=i;
        }
    }
    nums[index] = -1;
    return ans;
}

int maxProductDifference(vector<int>& nums) {

    if( nums.size() < 4 ){
        return -1;
    }

    int minimum = findMinimum(nums);
    int secondMinimum = findMinimum(nums);

    int maximum = findMaximum(nums);
    int secondMaximum = findMaximum(nums);

    return (maximum*secondMaximum)-(minimum*secondMinimum);
}


int main(){

    int n;
    cin>>n;

    vector<int> nums;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    cout<<maxProductDifference(nums);
    return 0;
}


/*

k=1

1 2 3
4 5 6
7 8 9


12 21 16


*/