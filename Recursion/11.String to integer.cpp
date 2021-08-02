int length(char input[]){
    int len = 0;
    int i = 0;
    while(input[i] != '\0'){
        len+=1;
        i+=1;
    }
    return len;
}


int stringToNumber(char input[]) {
    if(input[1] == '\0'){
        int num = input[0] - '0';
        return num;
    }
    

    int rec_ans = stringToNumber(input+1);
    

    int len = length(input);
    int place_value = 1;
    int i = 1;
    while(i<=len-1){
        place_value*=10;
        i+=1;
    }
    
    int last_digit = input[0] - '0';
    rec_ans+= last_digit*place_value;
    
    return rec_ans;
}
