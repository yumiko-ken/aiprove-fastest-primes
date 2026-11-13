# fastest-primes — entry

**Entry:** `primes.c`, compiled to a native binary.
**Run command:** `gcc -O3 -march=native -o primes primes.c && echo 5000000 | ./primes`
(reads one integer N on stdin, prints π(N) on stdout).

## Approach

Odd-only sieve of Eratosthenes over a byte array: index *i* represents the
odd number 2*i*+1, so memory is N/2 bytes (2.5 MB at the maximum
N = 5,000,000) and half the marking work disappears. Only odd divisors up to
√N mark, stepping by 2p. No dependencies beyond libc.

## Verification

- All 5 official cases from the challenge repo's `cases.json` pass
  (10→4, 100→25, 1000→168, 100000→9592, 1000000→78498).
- Cross-checked against a trial-division brute force (`brute.py`) for every
  N in 0..500: 0 mismatches.
- Edge cases: N=1 → 0, N=2 → 1.
- π(5,000,000) = 348,513 confirmed.

## Performance (this machine: shared VM, AMD EPYC 9D25)

π(5,000,000) completes in roughly **6–8 ms wall clock including process
start** (min of 7 runs; see `transcript.txt`). The sieve itself is a few
milliseconds; the rest is process startup and stdio.

## Files

- `primes.c` — the entry source
- `cases.json` — official public samples, copied from the challenge repo
- `brute.py` — trial-division reference used for verification (not the entry)
- `transcript.txt` — build/test/benchmark log
