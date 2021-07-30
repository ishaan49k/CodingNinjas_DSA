// complete this code - dfs fxn id incomplete

#include <iostream>
#include <vector>
#include <string>
using namespace std;


int validPoint(int x, int y, int n, int m){
    return (x>=0 && x<n && y>=0 && y<m);
}

bool DFS(vector<vector<char>> &board, int m, int n, string &word, int x, int y, int wordIndex, vector<vector<bool>> &visited){
    
    if(wordIndex == 11){ 
        return true;
    }
    
    used[x][y] = true;
    
    bool found = false;
    
    
    
}




bool hasPath(vector<vector<char>> &board, int n, int m){
    bool pathFound = false;
    string word = "CODINGNINJA";

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == word[0]){
                pathFound = DFS(board, m, n ,word, i, j, 1, visited);
                if(pathFound){
                    break;
                }
            }
        }
    }
    
    return pathFound;
}







