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

**Lead: a mod 4 trap.** If n = 2m with m odd, then τ(n) = 2τ(m), which is a
multiple of 4 unless m is a square. So an orbit that is 2 mod 4 stays 2 mod 4
until it lands on twice an odd square. Even squares are 0 mod 4, so such an
orbit cannot hit a square in the meantime. This may explain why the orbit of 1
hits so few squares, and it means a naive "random" model of square hits is
wrong. Not yet checked in Lean.

**Open questions.**
- What is the full 2-adic structure (mod 8, mod 16, ...) of the orbits?
- How fast does the record number of steps grow?
- Literature: Spiro's original paper, OEIS A064491 references, prior AI attempts.
