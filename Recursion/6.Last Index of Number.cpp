int lastIndex(int input[], int size, int x) {
    if(size<1){
        return -1;
    }
    // recursive call
    int check_ahead = lastIndex(input+1, size-1, x);
    if(check_ahead != -1){
        return check_ahead + 1;
    }else{
        if(input[0] == x){
            return 0;
        }else{
            return -1;
        }
    }
}

