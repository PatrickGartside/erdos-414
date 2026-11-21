// Erdős Problem #414 explorer.
// h(n) = n + tau(n), tau = number of divisors.
// For every n <= LIM, decides whether the orbit of n joins the orbit of 1
// before leaving [1, LIM], and how many steps that takes.
// Usage: explore LIM
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define UNKNOWN 0xFFFFFFFFu

int main(int argc, char **argv) {
    if (argc < 2) { fprintf(stderr, "usage: %s LIM\n", argv[0]); return 1; }
    uint64_t LIM = strtoull(argv[1], NULL, 10);

    // Linear sieve for tau(n).
    uint16_t *tau = malloc((LIM + 1) * sizeof(uint16_t));
    uint8_t *ex = malloc(LIM + 1);            // exponent of smallest prime factor
    uint32_t pcap = (uint32_t)(1.3 * LIM / log((double)LIM)) + 1000;
    uint32_t *pr = malloc(pcap * sizeof(uint32_t));
    if (!tau || !ex || !pr) { fprintf(stderr, "out of memory\n"); return 1; }
    for (uint64_t i = 0; i <= LIM; i++) tau[i] = 0;
    uint32_t np = 0;
    tau[1] = 1; ex[1] = 0;
    for (uint64_t i = 2; i <= LIM; i++) {
        if (!tau[i]) { tau[i] = 2; ex[i] = 1; pr[np++] = (uint32_t)i; }
        for (uint32_t j = 0; j < np; j++) {
            uint64_t p = pr[j], m = i * p;
            if (m > LIM) break;
            if (i % p == 0) {
                ex[m] = ex[i] + 1;
                tau[m] = tau[i] / (ex[i] + 1) * (ex[m] + 1);
                break;
            }
            ex[m] = 1; tau[m] = tau[i] * 2;
        }
    }
    free(ex); free(pr);

    // steps[n] = number of steps until the orbit of n lands on the orbit of 1
    // (0 if n is on it), UNKNOWN if the orbit leaves [1, LIM] first.
    uint32_t *steps = malloc((LIM + 1) * sizeof(uint32_t));
    if (!steps) { fprintf(stderr, "out of memory\n"); return 1; }
    for (uint64_t i = 0; i <= LIM; i++) steps[i] = UNKNOWN;
    uint64_t main_len = 0, main_squares = 0, x = 1;
    printf("squares on the orbit of 1:");
    while (x <= LIM) {
        steps[x] = 0; main_len++;
        uint64_t r = (uint64_t)sqrtl((long double)x);
        while (r * r > x) r--;
        while ((r + 1) * (r + 1) <= x) r++;
        if (r * r == x) { main_squares++; printf(" %llu", (unsigned long long)x); }
        x += tau[x];
    }
    printf("\n");
    for (uint64_t n = LIM; n >= 1; n--) {
        if (steps[n] == 0) continue;
        uint64_t nx = n + tau[n];
        if (nx <= LIM && steps[nx] != UNKNOWN) {
            if (steps[nx] >= UNKNOWN - 1) { fprintf(stderr, "step counter overflow at %llu\n", (unsigned long long)n); return 2; }
            steps[n] = steps[nx] + 1;
        }
    }

    // Report.
    uint64_t first_unknown = 0, unknown = 0;
    for (uint64_t n = 1; n <= LIM; n++)
        if (steps[n] == UNKNOWN) { unknown++; if (!first_unknown) first_unknown = n; }
    printf("LIM = %llu\n", (unsigned long long)LIM);
    printf("orbit of 1: %llu terms <= LIM, %llu of them perfect squares\n",
           (unsigned long long)main_len, (unsigned long long)main_squares);
    printf("every n < %llu joins the orbit of 1 (verified)\n", (unsigned long long)first_unknown);
    printf("undecided n <= LIM (orbit leaves the range first): %llu\n", (unsigned long long)unknown);
    printf("record holders (n, steps to join), n below first undecided:\n");
    uint32_t best = 0;
    for (uint64_t n = 1; n < first_unknown; n++)
        if (steps[n] > best) { best = steps[n]; printf("%llu,%u\n", (unsigned long long)n, best); }
    return 0;
}
