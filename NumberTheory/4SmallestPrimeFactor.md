# Smallest Prime factor

> [!NOTE]
> - The idea is the same as the sieve of Eratosthenes
> - Complexity is also the same
> - we are just marking the smallest prime factor to every number.

<hr/>

void smallestPrimeFactor(int N){

    vector<int>smallestPrime(N + 1);
    for(int i = 2; i <= N; i++) smallestPrime[i] = i;

    for(int i = 2; i <= N; i++){
        if(smallestPrime[i] != i) continue;
        for(int j = i * i; j <= N; j += i){
            if(smallestPrime[j] == j)
            smallestPrime[j] = i;
        }
    }

}
