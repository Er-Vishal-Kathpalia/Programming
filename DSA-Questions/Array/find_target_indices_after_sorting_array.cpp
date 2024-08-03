#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& ans){

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

vector<int> targetIndices(vector<int>& nums, int target) {
    vector<int> ans;
    
    int n = nums.size();
    sort(nums.begin(), nums.end()); //nlog(n)
    
    for(int i=0;i<n;i++){
        if( nums[i] == target ){
            ans.push_back(i);
        }
    }

    return ans;
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

    int target;
    cin>>target;
    vector<int> ans = targetIndices(nums,target);
    print(ans);
    return 0;
}


/*

k=1

1 2 3
4 5 6
7 8 9


12 21 16


*/