#include <stdio.h>
#include <stdlib.h>
int** restoreMatrix(int* rowSum, int rowSumSize, int* colSum, int colSumSize, int* returnSize, int** returnColumnSizes) {
    int n = rowSumSize, m = colSumSize;
    int** ans = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        ans[i] = (int*)malloc(m * sizeof(int));
    }
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    *returnSize = n;
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = m;
        for (int j = 0; j < m; j++) {
            ans[i][j] = fmin(rowSum[i], colSum[j]);
            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];
        }
    }

    return ans;
}
