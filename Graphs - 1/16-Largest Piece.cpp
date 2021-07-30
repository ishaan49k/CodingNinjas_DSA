#include <iostream>
#include <vector>
using namespace std;


int DFS(vector<vector<int>> &cake, vector<vector<bool>> &visited, int x, int y, int n){
    if(visited[x][y]){
        return 0;
    }
    
    visited[x][y] = true;
    
    int count = 1; // count stores answer of recursion. initialize with 1 cuz the first 1 is the 1 we started on
    
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};
    
    // move in all 4 directions of starting 1 and call recursion
    for (int i=0; i<4; i++){
        int X = x + dx[i];
        int Y = y + dy[i];
        
        // check if X,Y is a valid call
        if(X>=0 && X<n && Y>0 && Y<n && cake[X][Y] == 1){
            count += DFS(cake, visitd, X, Y, n)
        }
    }
    
    return count;
}



int getBiggestPieceSize(vector<vector<int>> &cake, int n){
    int biggestPieceSize = 0; // this is the final answer we need to return. assume it to be of size 0
    
    // create a visited array
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    // iterate over all the indexes of the cake:
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cake[i][j] == 1 && visited[i][j] = false){
                int recAns = DFS(cake, visitd, i, j, n);
                if(recAns > biggestPieceSize){
                    biggestPieceSize = recAns;
                }
            }
        }
    }
    
    return biggestPieceSize;
}
