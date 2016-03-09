#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define STACK_SIZE 10
#define bool _Bool

/*
 1.遇到操作数：直接输出（添加到后缀表达式中）
 2.栈为空时，遇到运算符，直接入栈
 3.遇到左括号：将其入栈
 4.遇到右括号：执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，左括号不输出。
 5.遇到其他运算符：加减乘除：弹出所有优先级大于或者等于该运算符的栈顶元素，然后将该运算符入栈
 6.最终将栈中的元素依次出栈，输出。
 */

char test_expr[] = "9+(3-1)*3+8/2";
int mark[256];

struct stack
{
    int pos;
    char node[STACK_SIZE];
};

void init_stack(struct stack *input)
{
    input->pos = -1;
}

bool is_empty(struct stack *input)
{
    if(input->pos == -1)
        return true;
    else
        return false;

}

bool push(struct stack *input, char value)
{
    if(input->pos < STACK_SIZE - 2){
        input->node[++(input->pos)] = value;
        return true;
    }
    else{
        return false;
    }
}

bool pop(struct stack *input, char *output)
{
    if(!is_empty(input)){
        *output = input->node[input->pos--];
        return true;
    }
    else{
        return false;
    }
}

bool top(struct stack *input, char *output)
{
    if(!is_empty(input)){
        *output = input->node[input->pos]; 
        return true;
    }
    else{
        return false;
    }
}

void set_mark()
{
    mark['+'] = 1;
    mark['-'] = 1;
    mark['*'] = 2;
    mark['/'] = 2;
    mark['('] = 1;
    mark[')'] = 3;
}

int pos = 0;
void putcx(char c)
{
	/*
	if (c == '*')
		printf("\n%d\n", pos);
	*/
    putchar(c);
}
void mid_to_after(const char *string, int length)
{
    struct stack test;
    char temp;
    init_stack(&test);
    while(pos < length){
        if(isdigit(string[pos])){
            putcx(string[pos]);
        }
        else{
            if(is_empty(&test)){
                push(&test, string[pos]);
            }
            else{
                top(&test, &temp);
                if(string[pos] == ')') {
                    pop(&test, &temp);
                    while(temp != '('){
                        putcx(temp);
                        pop(&test, &temp);
                    }
                }
                else if(mark[string[pos]] < mark[temp]){
                    pop(&test, &temp);
                    do{
                        putcx(temp);
                        if(!pop(&test, &temp))
                            break;
					} while (mark[string[pos]] <= mark[temp]);
                    push(&test, string[pos]);
                }
                else{
                    push(&test, string[pos]);
                }
            }
        }
        pos++;
    }
    while(!is_empty(&test)){
        pop(&test, &temp);
        putcx(temp);
    }

}


int main()
{
    set_mark();
    mid_to_after(test_expr, strlen(test_expr));
	getch();
    return 0;
} 

