#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& ans){

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int findMaximum(vector<int>& nums ){
    int ans = INT_MIN;
    int index = -1;
    for(int i=0;i<nums.size();i++){
        if( nums[i] >= ans ){
            ans = nums[i];
            index=i;
        }
    }
    nums[index] = -1;
    return ans;
}

int maxProduct(vector<int>& nums){
    if( nums.size() == 0 ){
        return 0;
    }
    if( nums.size() < 2 ){
        return nums[0];
    }
    int maxElement = findMaximum(nums);
    int secondMaxElement = findMaximum(nums);
    return (maxElement-1)*(secondMaxElement-1);

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

    cout<<maxProduct(nums)<<endl;
    return 0;
}


/*

k=1

1 2 3
4 5 6
7 8 9


12 21 16


*/