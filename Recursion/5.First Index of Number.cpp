int firstIndex(int input[], int size, int x) {
    if(size<=0){
        return -1;
    }
    // check if 0th ele is required number.
    if(input[0] == x){
        return 0;
    }
    // if 0th is not x, then make recursive call to scan the remaining array to find the index of x
    int small_ans = firstIndex(input+1, size-1, x);
    if(small_ans == -1){
        return -1;
    }else{
        return small_ans + 1;
    }
}

