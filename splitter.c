/* file: splitter.c */
/* author: Awin Gray (email: a.gray@student.rug.nl) */
/* date: Tue 18th October 2016 */
/* version: 1.0 */

#include <stdio.h>
#include <stdlib.h>

int checkSplit(int n, int len, int arr[]) {

    int left = 0;
    int right = 0;

    // count from first element to the n-value splitter
    for(int i = 0; arr[i] != n; i++) {
        left++;
    }

    // count from last element to the n-value splitter
    for(int j = len - 1; arr[j] != n; j--) {
        right++;
    }

    // if number of elements from elements less than and more than n-value splitter is equal then n is a balanced splitter (returns 1)
    return (left == right);

}

int main(int argc, char *argv[]) {

    int *hist = (int*)calloc(100, sizeof(int));
    int num;

    int k = 0;
    int len = 0;
    int n = 0;

    // creates a histogram from the input
    while(hist[0] == 0) {
        scanf("%d", &num);
        hist[num]++;
        len++;
    }

    len = len - 1;
    int *arr = malloc(len*sizeof(int));

    // creates a new array with sorted elements using the histogram
    for(int i = 1; i < 100; i++) {
        if(hist[i] != 0) {
            for(int j = 0; j < hist[i]; j++) {
                arr[k] = i;
                k++;
            }
        }
    }

    for(int i = 0; i < len; i++) {
        if(checkSplit(arr[i], len, arr)) {
            // balanced splitter is found thus break out of loop
            n = arr[i];
            break;
        }
    }

    // If n is 0 then no balanced splitter has been found
    if(n != 0) {
        printf("%d\n", n);
    } else {
        printf("UNBALANCED\n");
    }

    // free used memory
    free(arr);
    return 0;
}
