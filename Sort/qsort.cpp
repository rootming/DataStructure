//rootming@live.cn
#include <iostream>
#include <vector>

using namespace std;

void quickSort(int *data, int left, int right)
{
    int i, j;
    int temp;
    if(left < right){
        i = left;
        j = right;
        temp = data[left];
        while(i < j){
            while(i < j && data[j] >= temp)
                j--;
            if(i < j)
                data[i++] = data[j];

            while(i < j && data[i] < temp)
                i++;
            if(i < j)
                data[j--] = data[i];
        }
        data[i] = temp;
        quickSort(data, left, right - 1);
        quickSort(data, left + 1, right);
    }

}

int main(void)
{
    int test[] = {1, 2, 1, 0, 5, 7, 3};
    cout << "Raw:\n";
    for(auto it:test)
        cout << it << endl;
    quickSort(test, 0, 6);
    cout << "Sorted:\n";
    for(auto it:test)
        cout << it << endl;

    return 0;
}
