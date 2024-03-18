#include <bits/stdc++.h>
using namespace std;
void createSieve(int n, vector<bool> &sieve)
{
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}
int countPrimes(int n)
{
    vector<bool> sieve(n + 1, true);
    createSieve(n, sieve);
    int cnt = 0;
    for (int i = 2; i < n; i++)
    {
        if (sieve[i] == true)
        {
            cnt++;
        }
    }
    return cnt;
}