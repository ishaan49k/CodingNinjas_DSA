void printSubsetKHelper(int input[], int si, int size, int output[], int os, int k){
    if(si==size){
        if(k==0){
            for(int i=0; i<os; i+=1){
                cout << output[i] << " ";
            }
            cout << endl;
            return;
            
        }else{
            return;
        }
    }
    
    printSubsetKHelper(input, si+1, size, output, os, k);
    
    int smallout[1000];  //Since we dont want to affect output, create a separate array
    if(k>0){
    	int i=0;
		for(i=0; i<os; i+=1){        	
       		smallout[i] = output[i];
    	}
		smallout[i] = input[si]; 
		printSubsetKHelper(input, si+1, size, smallout, os+1, k-input[si]);     
    }
    
}




void printSubsetSumToK(int input[], int size, int k) {
    int output[1000];
    printSubsetKHelper(input, 0, size, output, 0, k);
}















