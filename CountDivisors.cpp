int countDivisers(int n){
    int ct = 0;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            ct++;

            if(i * i != n) ct++;
        }
    }
    return ct;
}
