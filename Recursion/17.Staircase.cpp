/* 
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways 
the child can run up to the stairs. You need to return number of possible ways W.  
*/




int staircase(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int x = staircase(n-1); // if first step is one then ways to take remaing n-1 steps is x
    int y = staircase(n-2);
    int z = staircase(n-3);
    
    return x+y+z;
}
