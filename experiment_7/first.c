#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 26

struct FF { 
    char first[MAX], follow[MAX]; 
} ff[MAX];

char prod[MAX][MAX];
int n;

void add(char *set, char c) {
    if (!strchr(set, c)) {
        int len = strlen(set);
        set[len] = c;
        set[len + 1] = '\0';
    }
}

void first(char X) {
    for (int i = 0; i < n; i++) {
        if (prod[i][0] != X) continue;
        char *rhs = prod[i] + 2;
        for (int j = 0; rhs[j]; j++) {
            char s = rhs[j];
            if (s == '#') { add(ff[X - 'A'].first, '#'); break; }
            if (!isupper(s)) { add(ff[X - 'A'].first, s); break; }

            if (!ff[s - 'A'].first[0]) first(s);
            for (int k = 0; ff[s - 'A'].first[k]; k++)
                if (ff[s - 'A'].first[k] != '#')
                    add(ff[X - 'A'].first, ff[s - 'A'].first[k]);

            if (!strchr(ff[s - 'A'].first, '#')) break;
            if (!rhs[j + 1]) add(ff[X - 'A'].first, '#');
        }
    }
}

void follow(char X) {
    if (X == prod[0][0]) add(ff[X - 'A'].follow, '$');

    for (int i = 0; i < n; i++) {
        char *rhs = prod[i] + 2;
        for (int j = 0; rhs[j]; j++) {
            if (rhs[j] != X) continue;

            int k = j + 1, needLHS = 1;
            while (rhs[k]) {
                if (!isupper(rhs[k])) { 
                    if (rhs[k] != '#') add(ff[X - 'A'].follow, rhs[k]);
                    needLHS = 0; break; 
                }

                for (int m = 0; ff[rhs[k] - 'A'].first[m]; m++)
                    if (ff[rhs[k] - 'A'].first[m] != '#')
                        add(ff[X - 'A'].follow, ff[rhs[k] - 'A'].first[m]);

                if (!strchr(ff[rhs[k] - 'A'].first, '#')) { needLHS = 0; break; }
                k++;
            }

            if (needLHS) {
                if (!ff[prod[i][0] - 'A'].follow[0]) follow(prod[i][0]);
                for (int m = 0; ff[prod[i][0] - 'A'].follow[m]; m++)
                    add(ff[X - 'A'].follow, ff[prod[i][0] - 'A'].follow[m]);
            }
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter production %d: ", i + 1);
        scanf("%s", prod[i]);
    }

    for (int i = 0; i < n; i++) first(prod[i][0]);
    for (int i = 0; i < n; i++) follow(prod[i][0]);

    printf("\nFIRST sets:\n");
    for (int i = 0; i < MAX; i++)
        if (ff[i].first[0]) printf("FIRST(%c) = %s\n", 'A' + i, ff[i].first);

    printf("\nFOLLOW sets:\n");
    for (int i = 0; i < MAX; i++)
        if (ff[i].follow[0]) printf("FOLLOW(%c) = %s\n", 'A' + i, ff[i].follow);
    return 0;
}
