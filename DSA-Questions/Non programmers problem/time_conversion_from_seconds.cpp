#include<bits/stdc++.h>
using namespace std;

int main(){

	long long int sec;
	cin>>sec;

	long long int hour, minute = 0;
	//Hour conversion
	hour = sec/3600;
	sec = sec%3600;

	//Min conversion
	minute = sec / 60;
	sec = sec%60;

	cout<<hour<<":"<<minute<<":"<<sec<<endl;

	return 0;
}
