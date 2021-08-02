int sumOfDigits(int n) {
    if(n<=9){
        return n;
    }
    int last_num = n%10;
    
    int rec_sum = sumOfDigits(n/10);
    
    return rec_sum + last_num;
}


