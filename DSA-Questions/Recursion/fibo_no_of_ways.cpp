#include <bits/stdc++.h>
using namespace std;

#define llint long long int


llint ways(llint n){

    if(n == 0 || n == 1){
        return 1;
    }

    return ways(n-1) + ways(n-2);

}


int main(){

    llint n;

    cin>>n;

    cout<<ways(n)<<endl;

    return 0;
}