// helper fxn takes in start index of the input array
int subsetSumToKHelper(int input[], int n, int si, int output[][50], int k){
    if(si==n){
        if(k==0){
            output[0][0] = 0;
            return 1;
        }else{
            return 0;
        }
    }
    int smallout1[1000][50];
    int smallout2[1000][50];
    
 
    int size1 = subsetSumToKHelper(input, n, si+1, smallout1, k);
    int size2 = subsetSumToKHelper(input, n, si+1, smallout2, k-input[si]);
    

    int row = 0;
    for(int i=0; i<size1; i+=1){ 
        for(int j=0; j<=smallout1[i][0]; j+=1){ 
            output[row][j] = smallout1[i][j];
        }
        row+=1;
    }
    
    for(int i=0; i<size2; i+=1){ 
        output[row][0] = smallout2[i][0] + 1;
        output[row][1] = input[si];
        for(int j=2; j<=smallout2[i][0]+1; j+=1){
            output[row][j] = smallout2[i][j-1];
        }
        row+=1;
    }
    return row;  
} 






int subsetSumToK(int input[], int n, int output[][50], int k) {
    return subsetSumToKHelper(input, n, 0, output, k);
}

















