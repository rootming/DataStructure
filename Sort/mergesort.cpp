//rootming@live.cn
#include <iostream>

using namespace std;

void merge(int *data, int first, int mid, int last, int *temp)
{
    int i, j, k, m, n;
    i = first;
    j = mid + 1;
    m = mid;
    n = last;
    k = 0;
    while(i <= m && j <= n){
        if(data[i] <= data[j])
            temp[k++] = data[i++];
        else
            temp[k++] = data[j++];
    }
    //做点后续工作
    while(i <= m)
        temp[k++] = data[i++];
    while(j <= n)
        temp[k++] = data[j++];

    for(i = 0; i < k; i++)
        data[first + i] = temp[i];


}

void sort(int *raw, int first, int last, int *temp)
{

    if(first < last){
        int mid = (first + last) / 2;
        sort(raw, first, mid, temp);
        sort(raw, mid + 1, last, temp);
        merge(raw, first, mid, last, temp);
    }
}

int main(void)
{
    int value[] = { 1, 2, 1, 0, 7, 9, 3 };
    size_t length = sizeof(value) / sizeof(int);
    int *temp = new int[length];
    cout <<  "Before:\n";
    for(auto it: value)
        cout << it <<"\n";
    cout <<  "After:\n";
    sort(value, 0, length - 1, temp);
    for(auto it: value)
        cout << it <<"\n";
    delete []temp;
    return 0;
}
