// Applications of catalan numbers
    // 1. Possible BSTs
    // 2. Paranthesis / bracket combinations
    // 3. Possible forests
    // 4. Ways of triangulation
    // 5. Possible paths in matrix
    // 6. Dividing a circle using N chrods
    // 7. Dyck words of given length 


// O(n^n)
int catalan(int n){
    if(n <= 1){
        return 1;
    }
    int res = 0;
    for(int i=0; i<n; i++){
        res += catalan(i) * catalan(n-i-1);
    }
    return res;
}