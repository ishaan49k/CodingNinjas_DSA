int length(char input[]){
    int len = 0;
    int i = 0;
    while(input[i] != '\0'){
        len+=1;
        i+=1;
    }
    return len;
}

void pairStar(char input[]) {

    if(input[0] == '\0'){
        return;
    }
    

    pairStar(input+1);
    
    // small calculation: 
    int len = length(input);
    if(input[0]==input[1]){
        int i = len;
        while(i>=1){
            input[i+1] = input[i];
            i-=1;
        }
        input[1] = '*';
    }
}
