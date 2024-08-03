#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int> >& ans){

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int setRowBoundry(int n, int low, int high){
    if( n < 0 ){
        return 0;
    }
    if( n >= high-1 ){
        return high-1;
    }
    return n;
}

int setColBoundry(int n, int low, int high){
    if( n < 0 ){
        return 0;
    }
    if( n >= low-1 ){
        return low-1;
    }
    return n;
}

vector<vector<int> > matrixBlockSum(vector<vector<int> >& mat, int k) {

    vector<vector<int> > ans;
    int low = mat.size();
    for(int i=0;i<low;i++){
        vector<int> temp;
        int high = mat[i].size();
        for(int j=0;j<high;j++){
            int r1 = setColBoundry(i - k, low, high);
            int r2 = setColBoundry(i + k, low, high);
            int c1 = setRowBoundry(j - k, low, high);
            int c2 = setRowBoundry(j + k, low, high);
            int element = 0;
            for(int x=r1;x<=r2;x++){
                for(int y=c1;y<=c2;y++){
                    element += mat[x][y];
                }
            }
            temp.push_back(element);
        }
        ans.push_back(temp);
    }
    return ans;
}


int main(){

    int n,m;
    cin>>m>>n;

    vector<vector<int> > mat;
    for(int i=0;i<m;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            int t;
            cin>>t;
            temp.push_back(t);
        }
        mat.push_back(temp);
    }

    int k;
    cin>>k;

    vector<vector<int> > ans = matrixBlockSum(mat,k);
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