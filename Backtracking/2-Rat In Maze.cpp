#include <iostream>
#include <cstring>
using namespace std;


void printPath(int** solution, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << solution[i][j] << " ";
        }
    }
    
    cout << endl; // cuz we print every path in a new line
}






void ratInMazeHelper(int maze[][20], int n, int** solution, int x, int y){
    // if we reach destination, print the path
    if(x == n-1 && y == n-1){
        // first include x,y in the solution and then print the path
        solution[x][y] = 1;
        printPath(solution, n);
        // after printing solution, again make the final detination 0
        solution[x][y] = 0;
        return;
    }
    

    
    // if any of these conditions are true, we cant include x,y in out solution.
    // solution[x][y] == 1 means that x,y is already part of out path. hence we cant use it again
    if(x>=n || x<0, || y>=n, || y<0, || maze[x][y] == 0 || solution[x][y] == 1){
        return;
    }
    
    // include the current position we are on in the solution and call in all 4 directions
    solution[x][y] = 1;
    ratInMazeHelper(maze, n, solution, x-1, y);
    ratInMazeHelper(maze, n, solution, x+1, y);
    ratInMazeHelper(maze, n, solution, x, y-1);
    ratInMazeHelper(maze, n, solution, x, y+1);
    solution[x][y] = 0; // after exploring all paths from x,y we mark the path as 0 ie move back from x,y to whichever cell we were on before it
    
}






// given n*n maze
void ratInMaze(int[][20], int n){
    // create a solution matrix which stores path
    int** solution = new int*[n];
    for(int i=0; i<n; i++){
        solution[i] = new int*[n];
        // intialize all the columns with 0
        for(int j=0; j<n; j++){
            memset(solution[i], 0, n*sizeOf(int));
        }
        memset(maze, n, solution, 0, 0); // part of initializing it solution matrix with 0. you can do it your own way
    }
    
    ratInMazeHelper(maze, n, solution, 0, 0);
    
}







 
