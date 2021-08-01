int sum(int input[], int n) {
    if(n<=0){
        return 0;
    }
    int smaller_sum = sum(input+1, n-1);  // this is the sum of all elements except 0th
    return input[0] + smaller_sum;
}


