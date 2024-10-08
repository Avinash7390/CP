## Euler's totient function

> [!NOTE]
> - A Multiplicative function is defined as $f(A * B * C) = f(A) * f(B) * f(C)$ and $GCD(A, B, C) = 1$
> - $PHI(P^k) = P^k - (p^k/p)$ where P is prime and k is positive integer
<br/>

- Problem is that you have to find the number of X $(1 <= X < N)$ such that N and X are coprime -> gcd(X, N) = 1
- This can be done using Euler's Totient Funtion
- $PHI(N) = PHI(P_1^k1 * P_2^k2 * ...... * P_m^Km)$ PHI is a multiplicative function.
  then $PHI(N) = PHI(P_1^k1) * PHI(P_2^k2) * ......... * PHI(P_m^km)$
- You will get $PHI(N) = N*[(1 - (1 / p1)) * (1 - (1 / p2)) * ....... * (1  - (1 / pm))]$
- If you know all the prime factors of N then it can be calculated easily, the number of X $(1 <= X < N)$ such that N and X are coprime or gcd(X, N) = 1 and it is Nothing but $PHI(N)$

  <hr/>

> [!NOTE]
> - Euler's Theorem :  $[a ^ Φ(m)] MOD m = 1$,  if $GCD(a, m) = 1$
> - Fermat's Theorem : [a ^ (m - 1)] % m = 1 , if m is a prime No.
> - Cool Problem on Fermat's Theorem : [https://cses.fi/problemset/task/1712]
