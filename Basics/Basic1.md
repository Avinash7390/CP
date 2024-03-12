
## Some basic things to know .

- 1) lower_bound return the iterator of the first index where arr[index] >= val.       code --> lower_bound(arr.begin(), - 
arr.end(), val).
- 2) upper_bound return the iterator of the first index where arr[index] > val.       code --> upper_bound(arr.begin(), arr.end(), val).
- 3) C++ STL function alternatives CF BLOG --- https://codeforces.com/blog/entry/107717
- 4) A good CF blog on PBDS(policy based data structure).
-https://codeforces.com/blog/entry/11080

<br/>

<h2>Whne you are takeing input a string with spaces on codeforces, You can use getline(cin, str)
  suppose you are reading m lines then you have to take a loop of m + 1 lines and for the first time you ingone the input.
  eg.
  <b/>
    
  5 ?
  4 a
  6 b
  123 ?
  12 c
  <br/>

  here m = 5;

  so here is the code 
  for(int i = 0; i < m + 1; i++){
      string s;
      getline(cin, s);
      if(i == 0) continue;
  }
</h2>

