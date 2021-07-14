// Program to print all permutations of a string in sorted order.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare (const void *a, const void * b){
    return (*(char *)a - *(char *)b );
}

void swap (char* a, char* b){
    char t = *a;
    *a = *b;
    *b = t;
}

// This function finds the index of the smallest character
// which is greater than 'first' and is present in str[l..h]
int findCeil (char str[], char first, int l, int h){
    // initialize index of ceiling element
    int ceilIndex = l;

    // Now iterate through rest of the elements and find
    // the smallest character greater than 'first'
    for (int i = l + 1; i <= h; i++)
      if (str[i] > first && str[i] < str[ceilIndex])
            ceilIndex = i;

    return ceilIndex;
}

void sortedPermutations (char str[]){

    int size = strlen(str);
    int i;

    // Find the rightmost character which is smaller than its next
    // character. Let us call it 'first char'
    for (i = size - 2; i >= 0; --i) {
        if (str[i] < str[i+1])
            break;
    }
    // Find the ceil of 'first char' in right of first character.
    // Ceil of a character is the smallest character greater than it
    int ceilIndex = findCeil(str, str[i], i + 1, size - 1);

    // Swap first and second characters
    swap(&str[i], &str[ceilIndex]);
    qsort(str + i + 1, size - i - 1, sizeof(str[0]), compare);
    printf ("%s\n", str);


}

int main(){
    char str[] = "BAC";
    sortedPermutations(str);
    return 0;
}
