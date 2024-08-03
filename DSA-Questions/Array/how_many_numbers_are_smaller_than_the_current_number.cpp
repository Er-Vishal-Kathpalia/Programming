#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& ans){

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

    int n = nums.size();
    vector<int> arr;
    vector<int> ans;
    for(int i=0;i<nums.size();i++){
        arr.push_back(nums[i]);
    }
    sort(arr.begin(), arr.end()); // O(nlog(n))

    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(nums[i] == arr[j]){
                ans.push_back(j);
                break;
            }
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

    vector<int> ans = smallerNumbersThanCurrent(nums);
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