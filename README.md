# Erdős Problem #414

An open attempt on [Erdős Problem #414](https://www.erdosproblems.com/414).

**The problem.** Let h(n) = n + τ(n), where τ(n) is the number of divisors of n.
Start from any number and apply h repeatedly. Is it true that any two starting
numbers eventually reach a common value? Equivalently: does every orbit join
the orbit of 1 (1, 2, 4, 7, 9, 12, 18, 24, 32, ... , [OEIS A064491](https://oeis.org/A064491))?

Status: open. The formal Lean statement is `erdos_414` in
[google-deepmind/formal-conjectures](https://github.com/google-deepmind/formal-conjectures).

## What is here

- `src/explore.c`: for every n up to a limit, decides whether the orbit of n
  joins the orbit of 1 inside the range, and counts the steps.
- `results/`: raw output of each run.
- `LOG.md`: research log with findings, leads and open questions.
- `REFERENCES.md`: all prior work this builds on. Read this first: the problem
  has substantial recent literature, and our results so far reproduce it.

## Run it

    gcc -O2 -o explore src/explore.c -lm
    ./explore 100000000

Memory use is about 6 bytes per number (7 during the sieve).

## How this is being done

The project is steered by Patrick Gartside. The mathematics, code and Lean are
written by Claude (Anthropic). Nothing is claimed as proved unless it compiles in Lean.
Computations are evidence only: no finite computation can settle the problem.
