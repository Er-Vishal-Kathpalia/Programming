#include<iostream>
#include <stack>
using namespace std;

void stockSpan(int prices[], int n, int span[]){

	stack<int> s;
	s.push(0);
	span[0]=1;
	for(int i=1;i<n;i++){
		int currentPrice = prices[i];

		while(!s.empty() && prices[s.top()]<=currentPrice){
			s.pop();
		}

		if(!s.empty()){
			int prev_highest = s.top();
			span[i] = i - prev_highest;
		} else{
			span[i] = i + 1;
		}
		s.push(i);
	}
	return;
}


int main(){

	int prices[] = {100,80,60,70,60,75,85};
	int n = sizeof(prices)/sizeof(prices[0]);
	int span[10000] = {0};

	stockSpan(prices,n,span);

	for(int i=0;i<n;i++){
		cout<<span[i]<<" ";
	}

	cout<<endl;
	return 0;
}

/*


*/