//rootming@live.cn
#include "../exprCalc/stack.h"
#include <iostream>

using namespace std;

char symbolTable[] = {'0', '1', '2', '3', '4',
                    '5', '6', '7', '8', '9',
                    'A', 'B', 'C', 'D', 'E', 'F'
};

string converter(const int &ns, const long int &value)
{
    long int tmp = value;
    Stack<int> store;
    string result;
    while(tmp != 0){
        store.push(tmp % ns);
        tmp /= ns;
    }
    while(!store.isEmpty())
        result.push_back(symbolTable[store.pop()]);

    return result;
}

int main(void)
{
    int ns;
    int input;
start:
    cout << "Please input number system:\n";
    cout << "(1) Bin;\n";
    cout << "(2) Oct;\n";
    cout << "(3) Hex;\n";
    cout << "(Ctrl-C) Exit program.\n";
    cin >> ns;
    cout << "Please input value:";
    cin >> input;
    for(;;){
        switch(ns){
            case 1:
                cout << "Result:\n";
                cout << converter(2, input);
                cout << "\n";
                break;
            case 2:
                cout << "Result:\n";
                cout << converter(8, input);
                cout << "\n";
                break;
            case 3:
                cout << "Result:\n";
                cout << converter(16, input);
                cout << "\n";
                break;
            default:
                cout << "Invalid input.\n";
        }
        goto start;
    }
    return 0;

}

