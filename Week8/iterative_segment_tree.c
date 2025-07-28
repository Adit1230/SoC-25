#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    // Find the nearest power of 2 ≥ n
    int size = 1;
    while (size < n) size <<= 1;

    int tree_size = 2 * size;
    int* tree = malloc(tree_size * sizeof(int));

    // Initialize all to INT_MAX
    for (int i = 0; i < tree_size; ++i)
        tree[i] = INT_MAX;

    // Read input into leaf nodes
    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        tree[size + i] = val;
    }

    // Build the tree (bottom-up)
    for (int i = size - 1; i >= 1; --i) {
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }

    // Process queries
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        --l; --r;  // convert to 0-based index

        // Convert to leaf indices
        l += size;
        r += size;

        int res = INT_MAX;

        while (l <= r) {
            if (l % 2 == 1) res = min(res, tree[l++]);
            if (r % 2 == 0) res = min(res, tree[r--]);
            l /= 2;
            r /= 2;
        }

        printf("%d\n", res);
    }

    free(tree);
    return 0;
}
