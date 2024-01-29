# Sieve of Eratosthenes

void sieve(int n){

    <-- 1 --> Prime -->
    <-- 0 --> nonPrime -->
    vector<int>prime(n + 1, 1);
    prime[1] = 0;
    for(int i = 2; i<= n; i++){
    
        if(prime[i] == 0) continue;
        for(int j = i * i; j<= n; j+=i){
            prime[j] = 0;
        }
    }
    
}
