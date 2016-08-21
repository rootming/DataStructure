#include <stdio.h>
#include <string.h>
#include <malloc.h>

int weight[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
char mask[] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
int main()
{
    int sum = 0;
    char input[20];
    int flag = 0;
    int count;
    int pos = 0;
    char *list[100];
    scanf("%d", &count);
    for(int j = 0; j < count; j++){
        scanf("%s", input);
        for(int i = 0; i < 17; i++){
            sum += weight[i] * (input[i] - '0');
        }
        if(mask[sum % 11] != input[17]){
            //printf("%s\n", input);
            list[pos] = (char *)malloc(sizeof(char) * 20);
            memcpy(list[pos++], input, 20);
            flag = 1;
        }
        sum = 0;
    }
    if(flag == 0)
        printf("All passed");
    else
        for(int i = 0; i < pos; i++)
            printf("%s\n", list[i]);
    return 0;
}
