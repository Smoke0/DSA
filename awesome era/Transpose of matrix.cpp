#include<iostream>

using namespace std;

void transpose_square(int **arr,int **trans,int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            trans[j][i] = arr[i][j];
    }
}
int main(){
    cout <<"Enter dimensions of matrix row and column\n";
    int r,c,temp,**arr,**trans;
    cin >> r >> c;

    arr = (int**) malloc(r*sizeof(int));
    trans = (int**) malloc(c*sizeof(int));
    for(int i=0;i<r;i++)
        arr[i] = (int*)malloc(c*sizeof(int));

    for(int i=0;i<c;i++)
        trans[i] = (int*)malloc(r*sizeof(int));

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> temp;
            arr[i][j] = temp;
        }
    }
    transpose_square(arr,trans,r,c);
    cout << "The transpose of matrix is\n";
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            cout << trans[i][j] <<" ";
        }
        cout << "\n";
    }
    return 0;
}
