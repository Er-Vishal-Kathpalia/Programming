#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int minMovesToSeat(vector<int>& seats, vector<int>& students){

    int n = seats.size() > students.size() ? seats.size() : students.size();
    sort(seats.begin(),seats.end());
    sort(students.begin(),students.end());

    int ans = 0;
    for(int i=0;i<n;i++){
        int diff = abs(seats[i] - students[i]);
        ans += diff;
    }

    return ans;

}


int main(){

    int n;
    cin>>n;

    vector<int> seats;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        seats.push_back(temp);
    }

    vector<int> students;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        students.push_back(temp);
    }
    cout<<minMovesToSeat(seats, students);
    return 0;
}


/*

k=1

1 2 3
4 5 6
7 8 9


12 21 16


*/