int length(char input[]){
    int i = 0;
    int len = 0;
    while(input[i]!= '\0'){
        len+=1;
        i+=1;
    }
    return len;
}


void removeX(char input[]) {

    if(input[0]=='\0'){
        return;
    }

    removeX(input+1);
    

    if(input[0]=='x'){
        int len = length(input);
        int i = 0;
        while(i<=len-1){
            input[i] = input[i+1];
            i+=1;
        }
        
    }
}
