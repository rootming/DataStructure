#include <stdio.h>
#include <string.h>

int main()
{
    int a, b;
    int count = 0;
    int pos = 0;
    char buffer[100];
    char result[100];
    int last;
    scanf("%d %d", &a, &b);
    sprintf(buffer, "%d", a + b);
    last = strlen(buffer);
    if((buffer[0] != '-' && last <= 3) || (buffer[0] == '-' && last <= 4)){
        printf("%s", buffer);
        return 0;
    }
    for(int i = last - 1; i >= 0; i--){
        result[pos++] = buffer[i];
        count++;
        if(count % 3 == 0 && i != 0 &&buffer[i - 1] != '-'){
            result[pos++] = ',';
        } 
    }

    for(int i = pos - 1; i >= 0 ;i--)
        printf("%c", result[i]);

    return 0;
}
