#include <stdio.h>

struct node {
    unsigned dist[20];
    unsigned from[20];
} rt[10];

int main() {
    int demat[20][20];
    int n, i, j, k, count = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the cost matrix (999 for no link):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &demat[i][j]);
            if (i == j)
                demat[i][j] = 0;
            rt[i].dist[j] = demat[i][j];
            rt[i].from[j] = j;
        }
    }

    do {
        count = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < n; k++) {
                    if (rt[i].dist[j] > demat[i][k] + rt[k].dist[j]) {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0);

    for (i = 0; i < n; i++) {
        printf("\n\nState value for router %d is\n\n", i + 1);
        for (j = 0; j < n; j++) {
            printf("\tNode %d via %d Distance %d\n", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }
    printf("\n\n");
    
    return 0;
}

