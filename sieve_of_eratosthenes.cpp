void sieve(int n){
    //lets say all are prime 
    vector<int>prime(n + 1, 1);

    //now unmark those are not prime..
    prime[1] = 0;
    for(int i = 2; i<= n; i++){
        if(prime[i] == 0) continue;

        for(int j = i * i; j<= n; j+=i){
            prime[j] = 0;
        }
    }
}
