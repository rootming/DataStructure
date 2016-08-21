#include <iostream>
#include <cstring>

using namespace std;


enum patchar { P  = 0, A , T , e, s, t};
int total[6];


int main()
{
        char *str = new char[10000];
        cin.getline(str, 10000);
        for(int i = 0; i < strlen(str); i++){

                switch(str[i]){
                        case 'P':
                                total[P]++;
                                break;
                        case 'A':
                                total[A]++;
                                break;
                        case 'T':
                                total[T]++;
                                break;
                        case 'e':
                                total[e]++;
                                break;
                        case 's':
                                total[s]++;
                                break;
                        case 't':
                                total[t]++;
                                break;
                }
        }
        int p;
        p = total[0];
        for(int i = 1; i < 6; i++)
                if(p < total[i])
                        p = total[i];
        for(int i = 0; i < p; i++){
                total[P]-- > 0 ? cout << "P" : cout << "";
                total[A]-- > 0 ? cout << "A" : cout << "";
                total[T]-- > 0 ? cout << "T" : cout << "";
                total[e]-- > 0 ? cout << "e" : cout << "";
                total[s]-- > 0 ? cout << "s" : cout << "";
                total[t]-- > 0 ? cout << "t" : cout << "";
        }


}
