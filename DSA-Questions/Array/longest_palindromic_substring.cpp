#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j){

    while(i<=j){
        if( s[i] != s[j] ){
            return false;
        }
        i++, j--;
    }
    return true;
}

string longestPalindrome(string s) {
    int l = 0, r = s.length()-1;

    int i = 0, j = r;
    while( l <= r ){
        if( isPalindrome(s,l,r) ){
            i = l,j = r;
            break;
        } else {
            i++, j--;
        }
        l++;
        r--;
    }

    cout<<"i is "<<i<<" "<<j<<endl;

    string common = "";
    if( i > j ){
        return common;
    }

    int k = 0;
    while(i<=j){
        common[k] = s[i];
        k++;
        i++;
    }

    return common;

}


int main(){

    string s;
    cin>>s;

    cout<<longestPalindrome(s)<<endl;

    return 0;
}