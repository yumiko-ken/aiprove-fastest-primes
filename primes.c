/* fastest-primes: read N on stdin, print pi(N) = number of primes <= N.
 *
 * Odd-only sieve of Eratosthenes over a byte array: index i represents the
 * odd number 2i+1 (index 0 = 1, pre-marked). For N = 5,000,000 this needs
 * 2.5 MB and runs in a few milliseconds; correctness is checked against the
 * official cases.json and a brute-force counter for small N.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    long n;
    if (scanf("%ld", &n) != 1) return 1;
    if (n < 2) { puts("0"); return 0; }

    long half = (n + 1) / 2;              /* indices 0..half-1 -> 1,3,5,... */
    unsigned char *comp = calloc((size_t)half, 1);
    if (!comp) return 1;
    comp[0] = 1;                          /* 1 is not prime */

    long r = 0;
    while ((r + 1) * (r + 1) <= n) r++;    /* r = floor(sqrt(n)) */
    for (long p = 3; p <= r; p += 2) {
        if (!comp[p / 2]) {
            for (long j = p * p; j <= n; j += 2 * p)
                comp[j / 2] = 1;
        }
    }

    long cnt = 1;                         /* the prime 2 */
    for (long i = 1; i < half; i++)
        if (!comp[i]) cnt++;

    printf("%ld\n", cnt);
    free(comp);
    return 0;
}
