// given an array, return all its subsets. the 0th row of the output 2D array contains the size of the subset in that row
// fxn returns the no. of subsets
/***
You need to save all the subsets in the given 2D output array and return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/


int subset(int input[], int n, int output[][20]) {

    if(n==0){
        output[0][0] == 0;
        return 1;
    }

    int smallout = subset(input+1, n-1, output); //call the same fxn on all elements except 1st element

    for(int i = 0; i<smallout; i+=1){
        int size = output[i][0] + 1; 
        output[i+smallout][0] = size; 
        // now copy the first element:
        output[i+smallout][1] = input[0];
        for(int j=2; j<=size; j+=1){
            output[i+smallout][j] = output[i][j-1]; 
        }
    }
    return smallout*2;
}








