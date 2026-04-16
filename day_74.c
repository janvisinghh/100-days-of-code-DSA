#include <stdio.h>
#include <string.h>

struct Candidate {
    char name[100];
    int count;
};

int main() {
    int n;
    scanf("%d", &n);

    char votes[n][100];
    for(int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    struct Candidate c[n];
    int size = 0;

    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < size; j++) {
            if(strcmp(c[j].name, votes[i]) == 0) {
                c[j].count++;
                found = 1;
                break;
            }
        }
        if(!found) {
            strcpy(c[size].name, votes[i]);
            c[size].count = 1;
            size++;
        }
    }

    char winner[100];
    int maxVotes = 0;

    for(int i = 0; i < size; i++) {
        if(c[i].count > maxVotes) {
            maxVotes = c[i].count;
            strcpy(winner, c[i].name);
        } else if(c[i].count == maxVotes) {
            if(strcmp(c[i].name, winner) < 0) {
                strcpy(winner, c[i].name);
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}