#include<iostream>

using namespace std;

/// this function tells whether we can place the queen in given x,y position
/// in current board.
bool canQueenBePlaced(int board[10][10],int x ,int y,int n){
    /// checking  colums
    for(int i=0;i<x;i++){
        if(board[i][y]){
            ///cout <<"colums\n";
            return false;
        }
    }
    /// checking left diagnal
    int row = x;
    int col = y;
    while(row>=0 && col>=0){
        if(board[row][col]){
            ///cout << row << col ;
            ///cout <<"left dia\n";
            return false;
        }
        row--;col--;
    }
    row = x;
    col = y;
    /// checking right diagnal
    while(row>=0 && col<n){
        if(board[row][col]){
            ///cout <<"right dia\n";
            return false;
        }
        row--;col++;
    }
    /// if none of above condition satisfies that means we can place queen in x,y position.
    return true;
}

bool canPlace(int board[10][10],int i,int j,int n){
    /// check the column
    for(int k = 0;k<n;k++){
        if(board[k][j]){
            ///cout << "Column returned false\n";
            return false;
        }

    }
    int x = i;
    int y = j;
    /// check left diagnal
    while(x>=0 && y>=0){
        if(board[x][y]){
            ///cout << "left\n";
            return false;
        }

        x--;
        y--;
    }
    x = i;
    y = j;
    while(x>=0 && y<n){
        if(board[x][y]){
            ///cout << "right\n";
            return false;
        }

        x--;
        y++;
    }
    /// check right diagnal
    return true;

}
/// prints the solution board.
void printSolutionBoard(int board[10][10],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j])
                cout <<'Q' <<" ";
            else
                cout <<'_' <<" ";
        }
        cout << "\n";
    }
    cout << "\n";
}
bool Nqueen(int board[10][10],int n,int i){
    int j;
    /// we have placed n queen now we must print solution board.
    /// and we must return false for algo to find all other solutions
    /// if we return true algo will stop at first solution.
    if(i==n){
        printSolutionBoard(board,n);
        return false;
    }
    /// I place the queen in one of the column
    for(j=0;j<n;j++){
        if(canPlace(board,i,j,n)){
        	/// I first ask canQueenBePlaced function to tell me whether the queen can be placed
        	/// in (i,j) position if yes then I place the queen at (i,j) by putting one there.
            board[i][j] = 1;
            /// then I ask recursion to place all other queens
            /// if can we return true
            if(Nqueen(board,n,i+1))
                return true;
            /// if recursion can't place the other queen I remove queen from (i,j) position.
            /// and of cource for loop will incremnet j and check for other possiblities.
            else{
                board[i][j] = 0;
            }
        }
    }
    /// the below condition means queen can't be placed in ith row
    if(j==n)
        return false;
}
int main(){
    int board[10][10]  = {0};
    int n;
    cin >> n;
    Nqueen(board,n,0);

	return 0;
}
