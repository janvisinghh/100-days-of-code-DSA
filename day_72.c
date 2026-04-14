#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};
    int first_index[26];
    
    for (int i = 0; i < 26; i++)
        first_index[i] = -1;

    int result_index = 1000000;

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';
        freq[idx]++;
        if (freq[idx] == 1) {
            first_index[idx] = i;
        } else if (freq[idx] == 2) {
            if (i < result_index)
                result_index = i;
        }
    }

    if (result_index == 1000000) {
        printf("-1");
    } else {
        printf("%c", s[result_index]);
    }

    return 0;
}