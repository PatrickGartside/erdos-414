# References

Everything this repository builds on. Results attributed below are theirs, not ours.

## The problem

1. T. F. Bloom, *Erdős Problem #414*, https://www.erdosproblems.com/414.
2. P. Erdős and R. L. Graham, *Old and New Problems and Results in Combinatorial
   Number Theory*, Monographies de L'Enseignement Mathématique 28, Geneva, 1980, p. 82.
3. C. Spiro, problem proposed at the West Coast Number Theory Meeting, 1977
   (as recorded in OEIS A064491).

## Prior work on the problem

4. E. Li, *Square-Annular Dynamics and Coalescence Frontiers for n + τ(n)*,
   arXiv:2606.17926, June 2026. https://arxiv.org/abs/2606.17926
   Parity law, squares as the only cross-parity gateway, component-count bound,
   exit sets and transfer maps, sufficient criteria for the conjecture.
5. I. Mian and S. Siddique, *Kernel-Checked Frontier Certificates for Erdős
   Problem 414*, arXiv:2609.22298, September 2026. https://arxiv.org/abs/2609.22298
   Lean-certified coalescence of every pair below 10^8.
6. P. White and Claude, *Erdős Problem a Day*, attempt log,
   https://erdosproblemaday.com/progress. Reports coalescence for all starts up to 10^10.

## Data and formal statement

7. OEIS Foundation, *The On-Line Encyclopedia of Integer Sequences*, sequence
   A064491 (orbit of 1), https://oeis.org/A064491, and A165494 to A165499
   (orbits from 2(2n-1)^2 and divisibility by 4).
8. Google DeepMind, *formal-conjectures*, `FormalConjectures/ErdosProblems/414.lean`,
   https://github.com/google-deepmind/formal-conjectures (Apache 2.0).

## What is ours

The code in `src/`, the runs in `results/` and the notes in `LOG.md`. As of
2026-11-20 these reproduce known results and contain nothing new.
