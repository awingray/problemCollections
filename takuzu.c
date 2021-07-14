/* file: takuzu.c */
/* author: Awin Gray (email: a.gray@student.rug.nl) */
/* date: Tue 11th October 2016 */
/* version: 1.0 */
/*

input: 2

output:

0011
0101
0110
1001
1010
1100

*/

#include <stdio.h>
#include <stdlib.h>




int takuzu(int len, char str[])
{
	int zero = 0;
	int one = 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] == '0')
		{
			zero++;
			if (i + 2 < len)
			{
				if (str[i + 1] == '0' && str[i + 2] == '0')
					return 0;
			}
		}
		else if (str[i] == '1')
		{
			one++;
			if (i + 2 < len)
			{
				if (str[i + 1] == '1' && str[i + 2] == '1')
					return 0;
			}
		}
		else
			return 0;
	}

	return (one == zero);

}

int main(int argc, char *argv[]) {

    return 0;
}
