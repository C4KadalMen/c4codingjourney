// Win95 Key Generator, for the sake of learning coding in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int valid = 0;
int value, v1, v2, v3, v4, v5, v6, v7;
int failsafe;
int loop = 1;

int main()
{
	srand(time(0));

	while(valid != 1)
	{
		value = rand() %999 + 1;
		if(value > 99)
		{
			if(value != 333 || value != 444 || value != 555 || value != 666 || value != 777 || value != 888 || value != 999)
			{
				valid = 1;
			}
		}
	}
	valid = 0;
	while(valid != 1)
	{
		v1 = rand() %8 + 1;
		v2 = rand() %8 + 1;
		v3 = rand() %8 + 1;
		v4 = rand() %8 + 1;
		v5 = rand() %8 + 1;
		v6 = rand() %8 + 1;
		v7 = rand() %8 + 1;
		failsafe = (v1 + v2 + v3 + v4 + v5 + v6 + v7) % 7;
		if(failsafe == 0)
		{
			valid = 1;
		}
	}
	valid = 0;

	printf("[WINDOWS 95 KEY GENERATOR By. C4_KadalMen]\n=> ");
	printf("%d-%d%d%d%d%d%d%d\nKey Generated!\n", value, v1, v2, v3, v4, v5, v6, v7);
	return 0;
}
