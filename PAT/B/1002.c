#include <stdio.h>
#include <stdint.h>
#include <string.h>
static char *list[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char num1[100+1];
char num2[100+1];

int main(int argc, char **argv)
{
	int i, stop;
	int sum;
	scanf("%s", num1);
	stop = strlen(num1);
	//printf("%d\n", stop);
	for(i = 0; i < stop; i++)
		sum += num1[i] - '0';
	stop = sprintf(num2, "%d", sum);
	//printf("%d\n", sum);
	//printf("%d\n", stop);
	for(i = 0; i < stop - 1; i++){
		printf("%s ", list[num2[i] - '0']);
	}
	printf("%s", list[num2[i] - '0']);
	return 0;	
}