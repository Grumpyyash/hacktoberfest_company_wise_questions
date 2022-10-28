#include <bits/stdc++.h>
using namespace std;

int dp[100][100][100];

int dfs(vector<char>&crayons, int i, int j, int x){
    if(i > j) 
    	return 0;
    if(dp[i][j][x]!=0)
        return dp[i][j][x];
    
    int res= (x+1) * (x+1) + dfs(crayons, i + 1, j, 0);
    
    for(int k=i+1;k<=j;k++){
        if(crayons[i] == crayons[k]){
            res = max(res, dfs(crayons, i + 1, k - 1, 0) + dfs(crayons, k, j, x + 1));   
        }   
    }
    return dp[i][j][x] = res;
}

int solve(int N, vector<char>& crayons) {
    memset(dp, 0, sizeof(dp));
    return dfs(crayons, 0, N - 1, 0);
}

int main(){
    int n; cin>>n;
    vector<char>crayons;

    for(int i=0; i<n; i++){
        char x; cin>>x;
        crayons.push_back(x);
    }

    cout<<solve(n, crayons)<<endl;
    return 0;
}