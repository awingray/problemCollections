/* file: surviving.c */
/* author: Awin Gray (email: a.gray@student.rug.nl) */
/* date: Tue 4th October 2016 */
/* version: 1.0 */

#include <stdio.h>

// Remove duplicate elements in the array
void avoidDup(int length, int arr[]) {
    int i, j, k;
    for(i = 0; i < length; i++) {
        for(j = i + 1; j < length;) {
            if(arr[j] == arr[i]) {
                for(k = j; k < length; k++) {
                    arr[k] = arr[k+1];
                }
                length--;
            } else {
                j++;
            }
        }
    }
}

// Remove elements with value 0 from the array
void newList(int length, int arr[]) {
    for(int i = 0; i < length; i++) {
        if(arr[i] == 0 && i != 0) {
            arr[i] = arr[i+1];
        }
    }
}

void removeNum(int length, int m, int arr[]) {

    for(int i = 0; i < length; i++) {
        if(i % m == 0) {
            arr[i] = 0;
        }
    }
    newList(length, arr);
    avoidDup(length, arr);
}


int main(int argc, char *argv[]) {

    int num[5001];
    int odd = 1;
    int i = 1;
    int m, n, input;
    num[0] = 0;

    //generate an array of positive odd numbers less than 10,000
    while(i < 5001) {
        num[i] = odd;
        odd += 2;
        i++;
    }


    scanf("%d", &input);

    for(n = 2; n <= 1118; n++) {
        m = num[n];
        removeNum(2000, m, num);

        if(n == input || input == 1) {
            break;
        }
    }

    printf("%d\n", num[input]);
    return 0;
}
