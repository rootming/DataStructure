#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

bool fa[5];

void checkA1(int &a, const vector<int> &data)
{
    vector<int>::const_iterator it = data.cbegin();
    for(; it != data.end(); ++it){
        if(*it % 5 == false && *it % 2 == false){
            a += *it;
            fa[0] = true;
        }
    }
}

void checkA2(int &a, const vector<int> &data)
{
    int p = 1;
    vector<int>::const_iterator it = data.cbegin();
    for(; it != data.end(); ++it){
        if(*it % 5 == 1){
            a += *it * p;
            p *= -1;
            fa[1] = true;
        }
    }
}

void checkA3(int &a, const vector<int> &data)
{
    vector<int>::const_iterator it = data.cbegin();
    for(; it != data.end(); ++it)
        if(*it % 5 == 2){
            a++;
            fa[2] = true;
        }

}

void checkA4(float &a, const vector<int> &data)
{
    int count = 0;
    vector<int>::const_iterator it = data.cbegin();
    for(; it != data.end(); ++it)
        if(*it % 5 == 3){
            a += *it;
            count++;
        }
    if(count != 0){
        a /= count;
        fa[3] = true;
    }
}
void checkA5(int &a, const vector<int> &data)
{
    vector<int>::const_iterator it = data.cbegin();
    for(; it != data.end(); ++it)
        if(*it % 5 == 4)
            if(*it > a){
                a = *it;
                fa[4] = true;
            }
}

int main()
{
    int n, tmp;
    int a1, a2, a3, a5;
    float a4;
    a1 = 0;
    a2 = 0;
    a3 = 0;
    a4 = 0;
    a5 = 0;
    vector<int> data;
    for(auto i: fa)
        i = false;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        data.push_back(tmp);
    }
    checkA1(a1, data);
    checkA2(a2, data);
    checkA3(a3, data);
    checkA4(a4, data);
    checkA5(a5, data);
    if(fa[0] == false)
        cout << "N ";
    else
        cout << a1 << " ";
    if(fa[1] == false)
        cout << "N ";
    else
        cout << a2 << " ";
    if(fa[2] == false)
        cout << "N ";
    else
        cout << a3 << " ";
    if(fa[3] == false)
        cout << "N ";
    else
        cout << fixed << setprecision(1) << a4 << " ";
    cout.unsetf(ios::fixed);
    cout.precision(6); 
    if(fa[4] == false)
        cout << "N";
    else
        cout << a5;
    return 0;

}
