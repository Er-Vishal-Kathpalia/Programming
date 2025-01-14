#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int x){

	if(s.empty()){
		s.push(x);
		return;
	}

	int data = s.top();
	s.pop();
	insertAtBottom(s,x);
	s.push(data);

}

void reverseStack(stack<int> &s){
	//base case
	if(s.empty()){
		return;
	}

	int x = s.top();
	s.pop();
	reverseStack(s);
	insertAtBottom(s,x);
}

int main(){
	int n;
	cin>>n;

	stack<int> s;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		s.push(data);
	}

	reverseStack(s);

	while(!s.empty()){
		cout<<s.top()<<", ";
		s.pop();
	}
	cout<<endl;
	return 0;
}