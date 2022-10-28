#include <bits/stdc++.h>
using namespace std;

int compute(int S, int X){
    int A = (S - X) / 2;
    int a = 0, b = 0;
    for (int i=0; i < 32; i++){
        int Xi = (X & (1 << i));
        int Ai = (A & (1 << i));
        if((Xi == 0) && (Ai == 0)){
        }
        else if((Xi == 0) && (Ai > 0)){
            a = ((1 << i) | a);
            b = ((1 << i) | b);
        }
        else if((Xi > 0) && (Ai == 0)){
            a = ((1 << i) | a);
        }
        else{
            return 0;
        }
    }
    return 2 * b + 3 * a;
}

int main(){
    int n; cin>>n;
    vector<int>A(n), B(n);

    for(int &x: A) cin>>x;
    for(int &x: B) cin>>x;

    vector<int>C;
    for(int i=0; i<n; i++)
        C.push_back(compute(A[i], B[i]));
    
    for(int &x: C)
        cout<<x<<endl;

    return 0;
}