#include <iostream>

const int N = 5;
int testMatrix[][N] = {
						{ 0,5,6,0,4 },
						{ 0,0,0,0,0 },
						{ 1,0,0,0,0 },
						{ 1,0,0,0,0 },
						{ 0,2,0,0,1 }
};

struct Unit
{
    int row, col;
    int value;
    struct Unit *right;
    struct Unit *down;
    union {
        struct Unit *next;
        int value;

    } tag;
};

Unit *initMatrix(int raw[][N])
{
    Unit *list[N];
    Unit *head, *temp , *pos;
    head = new Unit;
    head->row = N;
    head->col = N;
    temp = head;
    for(int i = 0; i < N; i++){
        list[i] = new Unit;
        list[i]->right = list[i]->down = list[i];
        temp->tag.next = list[i];
        temp = list[i];
    }
    temp->tag.next = head;
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            if(raw[y][x] != 0){
                temp = new Unit; 
                temp->row = y;
                temp->col = x;
                temp->tag.value = raw[y][x];
                pos = list[y];
                while(pos->right != list[y] && pos->right->col < x)
                    pos = pos->right;
                temp->right = pos->right;
                pos->right = temp;
                pos = list[x];
                while(pos->down != list[x] && pos->down->row< y)
                    pos = pos->down;
                temp->down = pos->down;
                pos->down = temp;
            }
        }
    }
    return head;
}

void DisplayMatrix(Unit *head)
{
    Unit *p, *q;
    std::cout <<"Row:" << head->row;
    std::cout <<"Col:" << head->col << "\n";
    p = head->tag.next;
    while(p != head){
        q = p->right; 
        while(p != q){
            std::cout << q->row << " "<< q->col << " " << q->tag.value << "\n";
            q = q->right;
        }
        p = p->tag.next;
    }

}

int main(void)
{
	DisplayMatrix(initMatrix(testMatrix));
	return 0;
}
