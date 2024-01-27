void getAllfactors(ll N, vector<ll>&factors){

    for(ll i = 1; i * i <= N; i++){

        ll p = i;

        if(N % p == 0){

            ll q = N / p;

            if(p == q) factors.push_back(p);
            else{
                factors.push_back(p);
                factors.push_back(q);
            }
        }
    }
}
- Time complexity -- (sqrt(N)).

- factors occure in pairs.
N = 20;
1 * 20
2 * 10
4 * 5
5 * 4 -- repetation
10 * 2 -- rep
20 * 1 -- rep

i dont want the repetation...
  
how did i get the idea that i should only iterate upto sqrt(N)?
  Ans ->  if p is factor of N then  (N / p) is also the factor of N
          lets say q = N / p;
          p * q = N;
          since i dont want the repetation so i will iterate over p such that p <= q
          since p <= q
          p * p <= p * q
          p * q <= N;
          so, p * p <= p * q <= N;
          hence , p * p <= N;
                  p <= sqrt(N);
- calculate for a given No if no of factors will be even or odd in number?
  Ans -- for a perfect square No of factors = odd
         for rest of numbers No of factors = even 
         because factors occure in pair so for every No no of factors should be even but in case of perfect square 
         one pair has same numbers in it so it is counted once hence odd no of factors.
