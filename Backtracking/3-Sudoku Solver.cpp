#include <iostream>
#include <cstring>
using namespace std;

#define N 9; // in code wherever N is there, it will get replaced with 9

// takes in a grid and referance variables row and column
// if we find empty location, return true, else false
bool findEmptyLocation(int grid[N][N], int &row, int &col){
    // iterate over the entire sudoku to find empty location
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    
    return false;
}




// checks if num is already present in row
bool isSafeInRow(int grid[N][N], int row, int num){
    for(int i=0; i<N; i++){ // for row, run a loop to check all cells in that row
        if(grid[row][i] == num){
            return false;
        }
    }
    
    return true;
}






// checks if num is already present in col
bool isSafeInCol(int grid[N][N], int col, int num){
    for(int i=0; i<N; i++){
        if(grid[i][col] == num){
            return false;
        }
    }
    
    return true;
}





// checks is num is already present in the 3*3 grid it is in
bool isSafeInGrid(int grid[N][N], int row, int col, int num){
    int rowFactor = row - row%3;
    int colFactor = col - col%3;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(grid[i+rowFactor][j+colFactor] == num){
                return false;
            }
        }
    }
    
    return true;
    
}






// return true if it is allowed to place num at grid[row][col]
bool isSafe(int grid[N][N], int row, int col, int num){
// isSafe depends on 3 things - if num is unique in row, col and its 3*3 grid
    if(isSafeInRow(grid, row, num) && isSafeInCol(grid, col, num), isSafeInGrid(grid, row, col, num)){
        return true;
    }else{
        return false;
    }
    
}





// on solving the sudoku, return true
bool solveSudoku(int grid[N][N]){
    // find empty location
    // initialize row & col. we pass them in findEmptyLocation fxn as referance variables and if we find an empty location, update the value of the referance variables which will reflect in this fxn also
    int row;
    int col;
    if(findEmptyLocation(grid, row, col) == false){
        return true;
    }
    
    // we found empty location. start filling it with suitable values
    for(int i=1; i<=N; i++){
        // check if it is safe to fill this row,col with i
        if(isSafe(grid, row, col, i)){
            grid[row][col] = i;
            if(solveSudoku(grid)){ // if by placing i at row,col, we are able to solve the remaing sudoku, return true cuz we have found the correct no. for row,col.
                return true;
            }else{   // with i at row,col if we were not able to solve the sudoku, then mark row,col as unresolved by marking it with 0. this is the backtracking step
                grid[row][col] = 0;
            }
        }
        
    }
    
    return false;    // if we were not able to solve sudoku for any value from 1-9, return false
    
    
}





int main(){
    // create the sudoku grid
    int grid[N][N];
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<s.length(); j++){    // add all the numbers of the string to the matrix
            grid[i][j] = s[i] - '0';
        }
    }
    
    // now the sudoku grid is made
    solveSudoku(grid);
    
    // print the sudoku
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl; // after printing one row, move to next line
    }
    
    
    
}


