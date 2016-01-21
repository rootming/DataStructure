#include <iostream>

using namespace std;

void sort(int *raw, int len)
{
    int head, i, j;
    int temp;
    for(head = len >> 1; head > 0; head >>= 1){
        for(i = head; i < len; i++){
            temp = raw[i];
            for(j = i - head; j >= 0 && raw[j] > temp; j -= head)
                raw[j + head] = raw[j];
            raw[j + head] = temp;
        }
    }
}

int main(void)
{
    int test[] = {1, 2, 1, 0, 5, 7, 3};
    cout << "Raw:\n";
    for(auto it:test)
        cout << it << endl;
    sort(test, 7);
    cout << "Sorted:\n";
    for(auto it:test)
        cout << it << endl;

    return 0;
}
