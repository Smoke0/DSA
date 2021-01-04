#include<iostream>
using namespace std;

/// gfg verified search google for what is spiral form of matrix
void printMatrixSpiral(int arr[][10],int n,int m){

    int rowStart=0,rowEnd=n-1,colStart=0,colEnd=m-1;

    while(1){

        /// print startrow
    for(int i=colStart;i<=colEnd;i++)
        cout << arr[rowStart][i] << " ";
    rowStart++;

    if(rowStart>rowEnd)
        break;
    /// print end column
    for(int i=rowStart;i<=rowEnd;i++)
        cout << arr[i][colEnd] << " ";
    colEnd--;
    if(colStart > colEnd)
        break;
    /// print endRow
    for(int i=colEnd;i>=colStart;i--)
        cout << arr[rowEnd][i] << " ";
    rowEnd--;
    if(rowStart>rowEnd)
        break;
    /// print srart column
    for(int i=rowEnd;i>=rowStart;i--)
        cout << arr[i][colStart] << " ";
    colStart++;
    if(colStart > colEnd)
        break;
    }

}

/// gfg verified
void rotateSqMatrix90AntiClockwise(int arr[][50],int n){

    int sr=0,sc = 0,er=n-1,ec=n-1;
    /// i is the ith layer of matrix a sq. matrix has n/2 layer where n is it's side
    for(int i=0;i<n/2;i++){
        /// j here is no of group of 4 element we are processing we are hardcoding the swaping of
        /// 4 elements this loop completly process a layer
        for(int j=0;j<n-1-2*i;j++){

            int pre=arr[sr][sc+j],cur; /// top left element

            cur = arr[er-j][sc]; /// bottom left
            arr[er-j][sc] = pre;
            pre = cur;

            cur = arr[er][ec-j];  /// bottom right
            arr[er][ec-j] = pre;
            pre = cur;

            cur = arr[sr+j][ec];   /// top right
            arr[sr+j][ec] = pre;
            pre = cur;

            arr[sr][sc+j] = pre;
        }
        sr++; er--; sc++; ec--; /// rows and colums for next layer are updated
    }
}

/// gfg verified
void transposeSquareMatrix(int arr[][100],int n){

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            swap(arr[i][j],arr[j][i]);
    }
}

void printMatrix(int arr[][100],int n,int m ){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout << arr[i][j] << " ";
        cout <<  "\n";
    }
}

int main() {
    int arr[4][100] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
    transposeSquareMatrix(arr,4);

    printMatrix( arr,4,4);
	return 0;
}
