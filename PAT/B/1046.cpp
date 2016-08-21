#include <iostream>

using namespace std;

struct Part
{
        int x;
        int y;
        int xn;
        int yn;
};


int main()
{

        int sumX, sumY ,count;
        sumX=0;
        sumY=0;
        cin >> count;
        Part * list = new Part[count];
        for(int i = 0; i < count; i++){
                cin >> list[i].x >> list[i].xn >> list[i].y >> list[i].yn;
        }
        for(int i = 0; i < count; i++){
                if(list[i].x + list[i].y == list[i].xn && list[i].x + list[i].y == list[i].yn)
                        continue;
                if(list[i].x + list[i].y == list[i].xn)
                        sumY++;
                else if(list[i].x + list[i].y == list[i].yn)
                        sumX++;
        }

        cout << sumX << " " << sumY;
        return 0;


}
