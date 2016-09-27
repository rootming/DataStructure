#include <iostream>
using namespace std;

const static char number[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K' };

int main(void)
{
   string a, b;
   int c = 1;
   char result[20];
   int pos;
   cin >> a;
   cin >> b;
   pos = b.length() - a.length();
   for(int i = b.length() - 1; i >=0; i--){
       if(c % 2 == 1){
            result[c - 1] = number[(b[i] - '0' + a[i - pos] - '0') % 13];
       }
       else{
           result[c - 1] = number[b[i] - a[i - pos] - '0' - '0' < 0 ? b[i] - a[i - pos] - '0' - '0' : b[i] - a[i - pos] + 10 - '0' - '0'];
       }
       c++;

   }
   result[++c] = '\0';
   cout << result;
   return 0;
 

}
