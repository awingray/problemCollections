#include <stdio>
#include <math.h>
#include <string>


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

int digit(int n)
{
	int count = 0;

	while (n != 0)
	{
		n /= 10;
		++count;
	}
	return count;
}

string decimaltoBinary(int n)
{
	string bin;
	int rem, i = 1, binary = 0;

	while (n != 0)
	{
		rem = n % 2;
		n /= 2;
		binary += rem*i;
		i *= 10;
	}
	bin = to_string(binary);
	return bin;
}

int main()
{
	int n;
	int size;
	int i = 0;
	char binary[];
	char temp[] = "";

	cout << "Enter value of N : ";
	cin >> n;

	size = n * 2;

	while (temp.size() < size)
	{
		temp += "1";
	}

	binary = (decimaltoBinary(i));

	while (binary != temp)
	{
		i++;
		binary = (decimaltoBinary(i));

		while (binary.size() < size)
		{
			binary = "0" + binary;
		}

		if (takuzu(binary))
		{
			cout << binary << endl;
		}
	}
	return 0;
}
