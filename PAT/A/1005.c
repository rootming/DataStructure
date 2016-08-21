#include <stdio.h>
#include <string.h>
char *number[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main()
{
    int sum = 0;
    char buffer[100];
    char result[100];
    scanf("%s", buffer);
    for(int i = 0; i < strlen(buffer); i++){
        sum += buffer[i] - '0';
    }
    sprintf(result, "%d", sum);
    for(int i = 0; i < 100; i++){
        printf("%s", number[result[i] - '0']);
        if(result[i + 1] == '\0')
            break;
        printf(" ");
    } 
    return 0;

}
