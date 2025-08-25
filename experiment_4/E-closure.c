#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 20
#define MAX_TRANS 50

typedef struct {
    int from;
    char sym;
    int to;
} Transition;

int state_count, trans_count;
Transition trans[MAX_TRANS];
bool closure[MAX_STATES][MAX_STATES];

void dfs_epsilon(int state, bool visited[]) {
    visited[state] = true; 
    for (int i = 0; i < trans_count; i++) {
        if (trans[i].from == state && trans[i].sym == 'e' && !visited[trans[i].to]) {
            dfs_epsilon(trans[i].to, visited);
        }
    }
}

int main() {
    printf("Enter the number of states : ");
    scanf("%d", &state_count);
    printf("Enter the number of transitions : ");
    scanf("%d", &trans_count);
    printf("Enter the transitions : ");
    for (int i = 0; i < trans_count; i++) {

        scanf("%d %c %d", &trans[i].from, &trans[i].sym, &trans[i].to);
    }

    for (int s = 0; s < state_count; s++) {
        bool visited[MAX_STATES] = {false};
        dfs_epsilon(s, visited);
        for (int i = 0; i < state_count; i++) {
            closure[s][i] = visited[i];
        }
    }

    for (int s = 0; s < state_count; s++) {
        printf("E-closure(%d) = {", s);
        for (int i = 0; i < state_count; i++) {
            if (closure[s][i]) {
                printf(" %d", i);
            }
        }
        printf(" }\n");
    }

    return 0;
}
