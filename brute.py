#!/usr/bin/env python3
"""Brute-force pi(N) by trial division — reference for small-N verification."""
import sys


def pi_brute(n: int) -> int:
    cnt = 0
    for k in range(2, n + 1):
        prime = True
        d = 2
        while d * d <= k:
            if k % d == 0:
                prime = False
                break
            d += 1 if d == 2 else 2
        if prime:
            cnt += 1
    return cnt


if __name__ == "__main__":
    print(pi_brute(int(sys.argv[1])))
