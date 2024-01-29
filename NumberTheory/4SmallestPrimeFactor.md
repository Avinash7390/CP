# Smallest Prime factor

> [!NOTE]
> - Idea is same as sieve of eratosthenes
> - Complexity is also same
> - we are just marking the smallest prime factor to every number.

<hr/>

void smallestPrimeFactor(int N){

    vector<int>smallestPrime(N + 1);
    for(int i = 2; i <= N; i++) smallestPrime[i] = i;

    for(int i = 2; i <= N; i++){
        if(smallestPrime[i] != i) continue;
        
        for(int j = i * i; j <= N; j += i){
            smallestPrime[j] = i;
        }
    }

}
