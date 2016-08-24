#include <iostream>

const int MAX_UNIT = 20;
const int N = 5;

int testMatrix[][N] = {
						{ 0,5,6,0,4 },
						{ 0,0,0,0,0 },
						{ 1,0,0,0,0 },
						{ 1,0,0,0,0 },
						{ 0,2,0,0,1 }
};

struct unit
{
	int row;
	int col;
	int value;
};

int matrixTrans(int raw[][N], unit *after)
{
	int count = 1;
	int x, y;
	for (y = 0; y < N; y++) {
		for (x = 0; x < N; x++) {
			if (raw[y][x] != 0) {
				after[count].row = y;
				after[count].col = x;
				after[count].value = raw[y][x];
				count++;
			}
		}
	}
	after[0].row = N;
	after[0].col = N;
	after[0].value = count - 1;
	return count - 1;
}

int **matrixRecover(unit *after)
{
	int **row = new int*[N];
	for (int i = 0; i < N; i++) {
		row[i] = new int[5]();
	}
	for (int pos = 1; pos < after[0].value + 1; pos++) {
		row[after[pos].row][after[pos].col] = after[pos].value;
	}
	/*
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			std::cout << row[y][x] << " ";
		}
		std::cout << "\n";
	}
	*/
	return row;
}

int main(void)
{
	unit *list = new unit[MAX_UNIT];
	matrixTrans(testMatrix, list);
	matrixRecover(list);
	delete []list;
	std::cin.get();

	return 0;
}