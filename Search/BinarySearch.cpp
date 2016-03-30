#include <iostream>

using namespace std;

int array[] = { 1, 2, 3, 4, 5, 6 };

bool binarySearch(const int *array, const int length, const int target)
{
    int left, right;
    int mid;
    left = 0;
    right = length - 1;
    while(left <= right){
        mid = (left + right) / 2;
        if(array[mid] < target){
            left = mid + 1;
        }
        else if(array[mid] == target){
            return true;
        }
        else{
            right = mid - 1; 
        }
    }
    return false;
}

int main()
{
    for(int i = 1; i < 7; i++)
        binarySearch(array, 6, i) ? cout << "found\n" : cout << "Not found\n";
    binarySearch(array, 6, 11) ? cout << "found\n" : cout << "Not found\n";
}
