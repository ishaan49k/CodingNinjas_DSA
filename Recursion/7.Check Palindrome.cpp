// HELPER FUNCTION
bool check_palindrome_helper(char input[], int start, int end){
    // base case: if it is a one or less letter string then return true cuz it is a palindrome
    if(start>=end){
        return true;
    }
    // small calculation:
    if(input[start] == input[end]){
        return check_palindrome_helper(input, start+1, end-1);
    }else{
        return false;
    }
}


// FUNCTION TO FIND THE LENGTH OF THE STRING
int length(char input[]){
    int i = 0;
    int length = 0;
    while(input[i] != '\0'){
        length+=1;
        i+=1;
    }
    return length;
}

// ORIGIONAL FUNCTION
bool checkPalindrome(char input[]) {
	int len = length(input);
    return check_palindrome_helper(input, 0, len-1);
}


