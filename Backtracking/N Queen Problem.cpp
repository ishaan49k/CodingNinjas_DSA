#include <iostream>
#include <cstring>
using namespace std;

int board[11][11];


bool isPossible(int n, int row, int col){

    for(int i=row-1, i>=0; i--){
        if(board[i][col] == 1){
            return false;
        }
    }

    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    for(int i=row-1, j=col+1; i>=0, j<n; i--, j++){
        if(board[i][j] == 1){
            return false;
        }
    }
    
    
    return true;
    
}

void nQueenHelper(int n, int row){
    if(row == n){ 
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << board[i][j] << " ";
            }
        }
        
        
        cout << endl;
        
    }

    for(int j=0; j<n; j++){
        if(isPossible(n, row, j)){ 
            board[row][j] = 1;  // place queen

            nQueenHelper(n, row+1);
            
         
            board[row][j] = 0; 
            
        }
        
    }

    
}






// given n queens, we need to print all ways of placing them on n*n chessboard
// constraint : 1<=n<=10
void placeNQueens(int n){
    memset(board, 0, 11*11*sizeOf(int));

}





int main(){
    placeNQueens(4); // call fxn to place 4 queens on 4 by 4 square
    
}
