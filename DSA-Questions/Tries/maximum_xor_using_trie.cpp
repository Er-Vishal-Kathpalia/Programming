#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

class node{
public:
	node* left; // 0
	node* right; // 1
};

class Trie{
	node* root;

public:

	Trie(){
		root = new node();
	}
	//5 = 00000101

	void insert(int n){
		node* temp = root;
		for(int i=31;i>=0;i--){
			int bit = (n>>i)&1;
			if(bit == 0){
				if(temp->left == NULL){
					temp->left = new node();
				}
				temp = temp->left;
			} else{
				if(temp->right == NULL){
					temp->right = new node();
				}
				temp = temp->right;
			}
		}
	}

	//helper function to print the max xor
	int max_xor_helper(int value){
		int current_ans = 0;
		node* temp = root;
		for(int j=31;j>=0;j--){
			int bit = (value>>j)&1;
			if(bit == 0){
				if(temp->right != NULL){
					temp = temp->right;
					current_ans += (1<<j);
				} else{
					temp = temp->left;
				}
			} 
			else{
				if(temp->left != NULL){
					temp = temp->left;
					current_ans += (1<<j);
				} else{
					temp = temp->right;
				}
			}
		}
		return current_ans;
	}


	int max_xor(int *input,int n){
		int max_xor = 0;
		for(int i=0;i<n;i++){
			int val = input[i];
			insert(val);
			int current_xor = max_xor_helper(val);
			cout<<current_xor<<" ";
			max_xor = max(max_xor,current_xor);
		}
		cout<<endl;
		return max_xor;
	}

};


int main(){

	int input[] = {3,10,5,25,2,8};
	Trie t;
	cout<<t.max_xor(input,6)<<endl;

	return 0;
}