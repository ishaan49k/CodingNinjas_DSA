#include <iostream>
#include <cstring>
using namespace std;


void printPath(int** solution, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << solution[i][j] << " ";
        }
    }
    
    cout << endl;
}






void ratInMazeHelper(int maze[][20], int n, int** solution, int x, int y){
    if(x == n-1 && y == n-1){

        solution[x][y] = 1;
        printPath(solution, n);
        solution[x][y] = 0;
        return;
    }
    

    
    if(x>=n || x<0, || y>=n, || y<0, || maze[x][y] == 0 || solution[x][y] == 1){
        return;
    }
    
    solution[x][y] = 1;
    ratInMazeHelper(maze, n, solution, x-1, y);
    ratInMazeHelper(maze, n, solution, x+1, y);
    ratInMazeHelper(maze, n, solution, x, y-1);
    ratInMazeHelper(maze, n, solution, x, y+1);
    solution[x][y] = 0; 
    
}







void ratInMaze(int[][20], int n){
    int** solution = new int*[n];
    for(int i=0; i<n; i++){
        solution[i] = new int*[n];

        for(int j=0; j<n; j++){
            memset(solution[i], 0, n*sizeOf(int));
        }
        memset(maze, n, solution, 0, 0); 
    }
    
    ratInMazeHelper(maze, n, solution, 0, 0);
    
}







 
