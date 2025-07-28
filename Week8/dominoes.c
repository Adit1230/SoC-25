#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int n, m;
int dp[2][1 << 11];  // Only need two rows: dp[cur][mask], dp[next][mask]

// Recursively try all ways to fill column
void generate(int row, int cur_mask, int next_mask, int n, int val, int* dp_next) {
    if (row == n) {
        dp_next[next_mask] = (dp_next[next_mask] + val) % MOD;
        return;
    }

    if ((cur_mask & (1 << row)) != 0) {
        // Current cell already filled, skip to next
        generate(row + 1, cur_mask, next_mask, n, val, dp_next);
    } else {
        // Try vertical domino
        generate(row + 1, cur_mask, next_mask | (1 << row), n, val, dp_next);

        // Try horizontal domino (only if next row exists and not filled)
        if (row + 1 < n && (cur_mask & (1 << (row + 1))) == 0) {
            generate(row + 2, cur_mask, next_mask, n, val, dp_next);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    dp[0][0] = 1;  // base case: empty grid has 1 way

    for (int col = 0; col < m; ++col) {
        int* cur = dp[col % 2];
        int* next = dp[(col + 1) % 2];

        // Clear next column's dp row
        memset(next, 0, (1 << n) * sizeof(int));

        for (int mask = 0; mask < (1 << n); ++mask) {
            if (cur[mask]) {
                generate(0, mask, 0, n, cur[mask], next);
            }
        }
    }

    printf("%d\n", dp[m % 2][0]);
    return 0;
}
