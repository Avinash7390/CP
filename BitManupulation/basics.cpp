1. set ith bit -->  n | (1 << i);
2. unset ith bit --> n & (~(1 << i));
3. flip the ith bit --> n ^ (1 << i);
4. if(k & (k - 1) == 0) that means k is some power of 2.

4. right most set bit -- > n & (~ (n - 1));
5. left most set bit --> can use binary search...
left most set bit --> 31 - __builtin_clz(n)
for n = 0  this builtin fintion is undefined.
__bulitin_clz(n) gives the leading zeroes.
 this can be used to find  (2^i <= n);

5. count set bits --> __bulitin_popcount(n);

6. count trailing zeroes -->  __builtin_ctz(x);
eg. 1000001100000 --> ans = 5;
7. __builtin_parity(x): Checks the Parity of a number.
Returns true(1) if the number has odd parity(odd number of set bits) else
it returns false(0) for even parity(even number of set bits).

8. 



