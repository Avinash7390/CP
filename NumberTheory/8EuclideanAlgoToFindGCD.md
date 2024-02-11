## Euclidean Algorithm to find GCD of two numbers.

> [!NOTE]
> - $gcd(a, b) = gcd(b, a) = gcd(a, b - a) = gcd(b, a - b) = gcd(a, b - k*b) = gcd(a, b + k * a)$

<br/>

    int gcd (int a, int b) {
          if (b == 0)
              return a;
          else
              return gcd (b, a % b);
    }
- Time Complexity : $O(log(min(a, b))$
