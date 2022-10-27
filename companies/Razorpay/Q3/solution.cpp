#include <bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node *prev;
	Node *next;
	Node() : val(0), prev(NULL), next(NULL) {}
	Node(int v) : val(v), prev(NULL), next(NULL) {}
};

void insert(Node *&curr, int val){
	curr -> next = new Node(val);
	curr -> next -> prev = curr;
	curr = curr -> next;
}

vector<int> solve(vector<int> &arr, vector<vector<int>> &queries){
	Node *root = new Node();
	Node *curr = root;
	
	for(auto x: arr)
		insert(curr, x);
	
	curr = root -> next;
	for(auto q: queries){
		int id = q[0];
		int mov = q[1];
		if(id == 1){
			while(mov--){
				curr = curr -> prev;
			}
		}
		else if(id == 2){
			while(mov--){
				curr = curr -> next;
			}
		}
		else if(id == 3){
			Node *last = curr;
			Node *temp = curr->next->next;
			delete curr->next;
			
			insert(curr, q[1]);
			insert(curr, q[2]);
			
			curr->next = temp;
			if(curr->next)
				curr->next->prev = curr;
			
			curr = last;
		}
	}
	vector<int> res;
	curr = root -> next;
	while(curr){
		res.push_back(curr -> val);
		curr = curr -> next;
	}
	return res;
}

int main(){
	int n, q; cin>>n>>q;
	vector<int>arr(n);
	for(int &x: arr) cin>>x;
	
	vector<vector<int>>queries;
	while(q--){
		int x,y,z; cin>>x;
		if(x == 1){
			cin>>y;
			queries.push_back({x,y});
		}
		else if(x == 2){
			cin>>y;
			queries.push_back({x,y});
		}
		else if(x == 3){
			cin>>y>>z;
			queries.push_back({x,y,z});
		}
	}
	
	vector<int>res = solve(arr, queries);
	for(int &x: res) cout<<x<<" ";
	return 0;
}
