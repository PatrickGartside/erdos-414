# Research log

## 2026-11-20

**Run to 10^8** (`results/run_1e8.txt`, about 2 seconds).

- Every n < 99,939,805 joins the orbit of 1 without leaving [1, 10^8].
  The 30,426 undecided numbers all sit just below the limit; their orbits
  leave the range before joining.
- Slowest to join so far: n = 46,771,839, after 118,100 steps.
- The orbit of 1 has 4,919,478 terms up to 10^8. Only 15 are perfect squares:
  1, 4, 9, 64, 81, 784, 1521, 29584, 34225, 132496, 136161, 4999696, 5076009,
  15492096, 15547249.
- Cross-check: an independent brute-force Python script gave the same record
  (55,167 at 1,261 steps) for n <= 10^5.

**Parity rule.** τ(n) is odd exactly when n is a perfect square. So an orbit
keeps its parity until it lands on a square, where it flips. After 1, the
squares on the orbit of 1 come in pairs: an even square (flip to odd), then an
odd square (flip back to even).

**Lead: a mod 4 trap** (later found to be known, see OEIS A165494 to A165499 in REFERENCES.md)**.** If n = 2m with m odd, then τ(n) = 2τ(m), which is a
multiple of 4 unless m is a square. So an orbit that is 2 mod 4 stays 2 mod 4
until it lands on twice an odd square. Even squares are 0 mod 4, so such an
orbit cannot hit a square in the meantime. This may explain why the orbit of 1
hits so few squares, and it means a naive "random" model of square hits is
wrong. Not yet checked in Lean.

**Open questions.**
- What is the full 2-adic structure (mod 8, mod 16, ...) of the orbits?
- How fast does the record number of steps grow?
- Literature: Spiro's original paper, OEIS A064491 references, prior AI attempts.

**Run to 10^9** (`results/run_1e9.txt`, GitHub Actions run 44872426667).

- Every n < 999,634,515 joins the orbit of 1 without leaving [1, 10^9].
- Slowest to join so far: n = 926,045,731, after 477,654 steps.
- The orbit of 1 has 43,942,603 terms up to 10^9, 17 of them perfect squares.
  The two new ones are again an even/odd pair: 299982400 and 300086329.

## 2026-11-20, literature check

The problem has had serious recent work that the erdosproblems.com page did
not show. Our findings so far reproduce known results.

- **E. Li, "Square-Annular Dynamics and Coalescence Frontiers for n+τ(n)"**,
  arXiv:2606.17926 (June 2026). Does not solve the problem. Proves the parity
  law, that opposite-parity orbits can only meet after a square, a bound of
  about log X on the number of separate components meeting [1, X], and
  sufficient criteria for the conjecture in terms of "exit sets" E_k at each
  square k^2 and transfer maps A_k between consecutive squares.
- **"Kernel-Checked Frontier Certificates for Erdős Problem 414"**,
  arXiv:2609.22298 (September 2026). Lean-certified: every pair below 10^8
  coalesces. A 10^9 ledger exists but is not certified (Lean build about a day).
  Measured for k <= 5000: |A_k(E_k)| = 1 only at k = 2, 3, 5, 315.
- **erdosproblemaday.com** reports coalescence for all starts up to 10^10.
- OEIS A165494 to A165499 (2009) already study orbits from 2(2n-1)^2 and
  divisibility by 4, so the "mod 4 trap" above is not new either.

**Where the wall is.** Two separate obstacles remain:
1. Parity switching: orbits of opposite parity can only merge through squares,
   and whether squares are hit often enough comes down to prime patterns near
   k^2 (for example k^2 - 2 prime), which are out of reach of current methods.
2. Same-parity merging: no method proves that two specific orbits of the same
   parity must meet.

**Consequence.** The plan's pivot rule (leads already known) is triggered.
