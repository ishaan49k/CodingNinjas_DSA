void printSubsetsOfArrayHelper(int input[], int n, int output[], int m){
    if(n==0){
        for(int i=0; i<m; i+=1){
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    printSubsetsOfArrayHelper(input+1,n-1, output, m);
    output[m]=input[0]; 
    printSubsetsOfArrayHelper(input+1,n-1,output,m+1);
}





void printSubsetsOfArray(int input[], int size){
    int output[1000];
    int m = 0;
    printSubsetsOfArrayHelper(input, size, output, m);
    return;
}


