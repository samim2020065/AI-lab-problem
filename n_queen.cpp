#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void solveNqueensStep(vector<vector<int>>& board, int row, int n){
   if(row==n){
      printSolution();
      return true;
   }
   ll success=false;
   for()
}
void solveNqueens(ll n){
	vector<vector<ll>>board(n,vector<ll>(n,0))
	if(!solveNqueensStep(board,0,n)){
		cout<<"No solution exists";
	}
	
}
int main()
{
	ll n;
	cin>>n;
	cout<<solveNqueens(n)<<endl;
}