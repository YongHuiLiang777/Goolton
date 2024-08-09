#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int xi, yi, ri;
} Bomb;

int visited[100];

int distanceSquared(Bomb *a, Bomb *b) {
    return (a->xi - b->xi) * (a->xi - b->xi) + (a->yi - b->yi) * (a->yi - b->yi);
}

int dfs(Bomb *bombs, int index, int n) {
    int i, maxCount = 1;
    visited[index] = 1;

    for (i = 0; i < n; i++) {
        if (!visited[i] && distanceSquared(&bombs[index], &bombs[i]) <= (bombs[index].ri + bombs[i].ri) * (bombs[index].ri + bombs[i].ri)) {
            maxCount = max(maxCount, dfs(bombs, i, n) + 1);
        }
    }

    return maxCount;
}

int maxBombs(Bomb *bombs, int n) {
    int i, maxCount = 0;
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            maxCount = max(maxCount, dfs(bombs, i, n));
        }
    }
    return maxCount;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    Bomb bombs[] = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}};
    int n = sizeof(bombs) / sizeof(bombs[0]);

    printf("Maximum number of bombs that can be detonated: %d\n", maxBombs(bombs, n));

    return 0;
}
