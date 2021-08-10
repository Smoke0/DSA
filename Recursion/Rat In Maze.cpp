/// this is recursive approach to solve rat in maze problem with custom row and column size.
#include<iostream>

using namespace std;

/// prints solution to maze in a cool way.
void PrintMaze(int **maze,int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(maze[i][j]==2)
                cout <<'X' <<" ";
            else
                cout <<maze[i][j] <<" ";
        }
        cout <<"\n";
    }
    cout <<"\n";
}
bool RatInMaze(int **maze,int r,int c,int i,int j){

    /// this if checks whether the (i,j) cell can be part of solution or not.
    if(i<r && j<c && maze[i][j]!=2)
        maze[i][j] = 1;

    /// either the cell is out of bound or cell is blocked so we return false.
    else
        return false;

    /// base case, the rat has reached the last cell so we print the maze and we set the destination to zero
    /// and return false so that we could find all other solutions.
    if(maze[r-1][c-1]==1){
        PrintMaze(maze,r,c);
        maze[r-1][c-1]=0;
        return false;
    }

    /// I ask recursion to step in right direction to reach the destination.
    if(RatInMaze(maze,r,c,i,j+1))
        return true;

    /// I ask recursion to step in downward direction to reach the destination if we can't move to destination
    /// if we go right.
    else if(RatInMaze(maze,r,c,i+1,j))
        return true;

    /// niether going left or right will lead us to destination so we mark cell(i,j) as zero and return false.
    else{
        maze[i][j] = 0;
        return false;
    }
}

int main(){
    int r,c;
    int **maze;
    cout <<"Enter rows and colums\n";
    cin >> r >> c;
    maze = (int**)malloc(r*sizeof(int));
    for(int i=0;i<r;i++)
        maze[i] = (int*)malloc(c*sizeof(int));

    cout <<"Now enter maze, put 0 for normal block and put 2 to indicate that block is blocked\n";
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin >> maze[i][j];
    cout <<"Solutions for maze are\n";
    RatInMaze(maze,r,c,0,0);
	return 0;
}
