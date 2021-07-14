#include <stdio.h>
#include <stdlib.h>

int isLeap(int year) {

	int leap = 0;

	if(year % 100 == 0) {

		leap = 0;

		if(year % 400 == 0) {

			leap = 1;
		}
	}

    if(year % 4 == 0) {

		leap = 1;
	}

	return leap;
}

int main(int argc, char *argv[]) {

	int year;
	int count = 0;

	scanf("%d", &year);

	for(int i = 1901; i < year; i++) {
        if(isLeap(i)){
            count += 2;
        } else {
            count += 1;
        }
	}

	count = count % 7;

	switch(count) {
		case 0: printf("Tuesday\n");
			break;
		case 1: printf("Wednesday\n");
			break;
		case 2: printf("Thursday\n");
			break;
		case 3: printf("Friday\n");
			break;
		case 4: printf("Saturday\n");
			break;
		case 5: printf("Sunday\n");
			break;
		case 6: printf("Monday\n");
			break;
		default:
			break;
	}

	return 0;
}
