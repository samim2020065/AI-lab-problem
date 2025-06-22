#include<bits/stdc++.h>
using namespace std;
bool isSafe(int row,int col,vector<string>board,int n){
	int duprow = row;
	int dupcol = col;
	while(row>=0 && col>=0){
		if(board[row][col]=='Q'){
			return false;
		}
		
			row--;
			col--;
		
	}
	row = duprow;
	col = dupcol;
	while(col>=0){
		if(board[row][col]=='Q'){
			return false;
		}
			col--;
		
	}
	row = duprow;
	col = dupcol;
	while(row<n && col>=0){
		if(board[row][col]=='Q'){
			return false;
		}
		
			col--;
			row++;
		
	}
	return true;

}
void solve(int col, vector<string>&board, vector<vector<string>>&ans, int n){
	if(col==n){
		ans.push_back(board);
		return;
	}
	for(int row=0;row<n;row++){
		if(isSafe(row,col,board,n)){
			board[row][col]='Q';
			solve(col+1,board,ans,n);
			board[row][col]='.';
		}
	}
}
vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
        	board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;

}
int main()
{
	int n;
	cin>>n;
	vector<vector<string>>res = solveNQueens(n);
	cout<<res.size()<<endl;
    
    for (auto& solution : res) {
        for (auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
	
}


//for only one solution
// #include <bits/stdc++.h>
// using namespace std;

// bool isSafe(int row, int col, vector<string>& board, int n) {
//     // upper-left diagonal
//     for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
//         if (board[i][j] == 'Q') return false;

//     // left row
//     for (int j = col; j >= 0; --j)
//         if (board[row][j] == 'Q') return false;

//     // lower-left diagonal
//     for (int i = row, j = col; i < n && j >= 0; ++i, --j)
//         if (board[i][j] == 'Q') return false;

//     return true;
// }

// bool solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
//     if (col == n) {
//         ans.push_back(board);
//         return true; // Found one solution, stop
//     }

//     for (int row = 0; row < n; ++row) {
//         if (isSafe(row, col, board, n)) {
//             board[row][col] = 'Q';
//             if (solve(col + 1, board, ans, n)) {
//                 return true; // Stop after first successful path
//             }
//             board[row][col] = '.'; // backtrack
//         }
//     }
//     return false; // No solution found in this path
// }

// vector<vector<string>> solveNQueens(int n) {
//     vector<vector<string>> ans;
//     vector<string> board(n, string(n, '.'));
//     solve(0, board, ans, n);
//     return ans;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<vector<string>> res = solveNQueens(n);
//     cout << "One Solution Found:\n\n";

//     for (auto& row : res[0]) {
//         cout << row << endl;
//     }

//     return 0;
// }
