/* file: lexicographic.c */
/* author: Awin Gray (email: a.gray@student.rug.nl) */
/* date: Tue 18th October 2016 */
/* version: 1.0 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this function swaps two character variables
void swap(char *a, char *b){
    char h = *a;
    *a = *b;
    *b = h;
}

// find the index of the character that acts as a pivot
int getPivot(char str[], char pivot, int l, int h){
    int idx = l;
    for (int i = l + 1; i <= h; i++) {
        if (str[i] > pivot && str[i] < str[idx])
            idx = i;
    }
    return idx;
}

// sort string in lexicographical order starting at nth element
void sortString(int n, int len, char str[]) {
    int i;
    for (; n < len - 1; n++){
        for (i = n + 1; i < len; i++){
            if (str[n] > str[i]){
                swap(&str[n], &str[i]);
            }
        }
    }
}

int main(int argc, char *argv[]) {

    // creates a string with initial size of 100
    char *str = malloc(100*sizeof(char));
    char c;
    int cnt = 0;

    // inputs a character until the series is terminated by a dot '.'
    while((c = getchar()) != '.') {
        // if the input size gets over 100 characters, reallocate the string with size cnt+1
        if(cnt > 100) {
            str = realloc(str, (1+cnt)*sizeof(char));
        }
        str[cnt] = c;
        cnt++;
    }

    int len = strlen(str);
    int i;

    // next permutation is determined by finding the index of a character which is smaller than its next character
    for (i = len - 2; i >= 0; --i) {
        if (str[i] < str[i+1])
            break;
    }

    // if there is no such character, then the string is the next permutation
    if(i == -1) {
        printf("%s\n", str);
    } else {
        // find the pivot character that is, the smallest character greater than it
        int idx = getPivot(str, str[i], i + 1, len - 1);
        swap(&str[i], &str[idx]);
        // sort the string in a lexicographical order from the pivot index
        sortString(i + 1, len, str);
        printf("%s\n", str);

    }

    // free used memory
    free(str);
    return 0;
}
