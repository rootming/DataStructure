#include <stdio.h>
#include <string.h>

int main(void)
{
    char number[4];
    scanf("%s", number);
    switch(strlen(number)){
        case 1:
            if(number[0] != '0') 
                for(int i = 1; i <= number[0] - '0'; i++)
                    printf("%d", i);
            break;
        case 2:
            if(number[0] != '0')
                for(int i = 0; i < number[0] - '0'; i++)
                    printf("S");
            if(number[1] != '0') 
                for(int i = 1; i <= number[1] - '0'; i++)
                    printf("%d", i);
            break;
        case 3:
            if(number[0] != '0')
                for(int i = 0; i < number[0] - '0'; i++)
                    printf("B");
            if(number[1] != '0')
                for(int i = 0; i < number[1] - '0'; i++)
                    printf("S");
            if(number[2] != '0') 
                for(int i = 1; i <= number[2] - '0'; i++)
                    printf("%d", i);
            break;

    }
    return 0;
}




