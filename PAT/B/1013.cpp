#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int a)
{
        for(int i=2;i<=sqrt(a);i++)
                    if(a%i==0) return false;
                return true;
}

int main()
{
    int min, max;
    int count = 0;
    cin >> min;
    cin >> max;
    int i = 3;
    int k = 0;
    while(k != min - 1){
        if(isPrime(i))
            k++;
        i++;
    }
    i--;
    while(k < max){
        if(isPrime(i)){
            cout << i;
            count++;
            k++;
            if(count % 10 == 0)
                cout << "\n";
            else if(k != max)
                cout << " ";
        }
        i++;
    }
    return 0;
}
