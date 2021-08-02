//FXN TO FIND LENGTH OF ARRAY
int length(char input[]){
    int i = 0;
    int len = 0;
    while(input[i]!= '\0'){
        len+=1;
        i+=1;
    }
    return len;
}


void replacePi(char input[]) {
    
    int len = length(input);
    if(len<=1){
        return;
    }
    
    replacePi(input+1);
    
    int new_len = length(input);
    
    if(input[0]=='p' && input[1]=='i'){
        int i = new_len-1;
        while(i>=2){
            input[i+2] = input[i];
            i-=1;
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }
 
}

