## Euler's totient function

> [!NOTE]
> - A Multiplicative function is defined as $f(A * B * C) = f(A) * f(B) * f(C)$
> - $PHI(P^k) = P^k - (p^k/p)$ where P is prime and k is positive integer
<br/>

- Problem is that you have to find number of X $(1 <= X < N)$ such that N and X are coprime -> gcd(X, N) = 1
- This can be done using Euler's Totient Funtion
- $PHI(N) = PHI(P_1^k1 * P_2^k2 * ...... * P_m^Km)$ PHI is a multiplicative function.
  then $PHI(N) = PHI(P_1^k1) * PHI(P_2^k2) * ......... * PHI(P_m^km)$
- You will get $PHI(N) = (N - (N / p1)) * (N - (N / p2)) * ....... * (N  - (N / pm))$
