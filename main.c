/*
Демидов Сергей
3*** Требуется обойти конём шахматную доску размером N ? M, пройдя через все поля доски по одному разу.
Здесь алгоритм решения такой же, как и в задаче о 8 ферзях. Разница только в проверке положения коня.

Не знаю как насчет такого же алгоритма, что и в задаче о 8 ферзях, на мой взгляд - совершенно разные задачи.
Доска - массив целых чисел, где 0 - клетка ни разу не посещалась, n - номер хода коня.

Для доски 4х4 решений не существует. Приятно сначала самому проверить, а потом найти в инете :)
Для доски 5х5 найдены все решения, перечисленные в https://oeis.org/A165134 в секции Example,
там правда приведено количество маршрутов обхода, для каждой клетки, а мой алгоритм находит
только один.
Для доски 6х6 - мой старенький AMD считал 203 секунды.
Для доски 7х7 - маршрут с клетки 0,0 нашел быстро, а вот для следующей 0,1 так и не дождался
Доску 8х8 даже пробовать не стал.
*/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

// Для пошаговой отладки - присвоить true
volatile int Debug = false;

#define numRows 5
#define numCols 5


void Zero(int N, int M, int B[][numCols]);
void printChessBoard(int N, int M, int B[][numCols]);

/*
Основная рекурсивная функция. Проверяет существование маршрута обхода
оставшихся клеток доски из конкретного поля.
Первый параметр - номер хода
Второй и третий - координаты, проверяемой клетки
Возвращает true - если найден маршрут обхода.
*/
int KnightsMove(int Num, int x, int y, int N, int M, int B[][numCols]){

	B[x][y] = Num;
	if (Debug) {
		printChessBoard(N, M, B);
		getchar();
	};
	// условие выхода
	// поскольку мы прошли по всей доске, то количество ходов будет равно N*M
	if (Num == M*N) {
		//printChessBoard(5,5,B);
		return true;
	};
	// дальше идут проверки возможности выполнения одного из 8 ходов коня, в зависимости от того где он находится
	// наверняка можно переписать компактнее, зато так понятнее, что происходит
	// В инете видел решения где все возможные ходя коня записаны массивом.
	if ((x + 1 <= N - 1) && (y - 2 >= 0)) {
		if (B[x + 1][y - 2] == 0) {
			//B[x+1][y-2] = Num+1;
			//если следующий шаг вернул true, значит маршрут построен и дальше искать не надо
			if (KnightsMove(Num + 1, x + 1, y - 2, N, M, B)) {
				return true;
			}
			//перейдем к следующему ходу
		}
	};
	if ((x + 2 <= N - 1) && (y - 1 >= 0)) {
		if (B[x + 2][y - 1] == 0) {
			//B[x+2][y-1] = Num+1;
			//если следующий шаг вернул true, значит маршрут построен и дальше искать не надо
			if (KnightsMove(Num + 1, x + 2, y - 1, N, M, B)) {
				return true;
			}
			//перейдем к следующему ходу
		}
	};
	if ((x + 2 <= N - 1) && (y + 1 <= M - 1)) {
		if (B[x + 2][y + 1] == 0) {
			//B[x+2][y+1] = Num+1;
			//если следующий шаг вернул true, значит маршрут построен и дальше искать не надо
			if (KnightsMove(Num + 1, x + 2, y + 1, N, M, B)) {
				return true;
			}
			//перейдем к следующему ходу
		}
	};
	if ((x + 1 <= N - 1) && (y + 2 <= M - 1)) {
		if (B[x + 1][y + 2] == 0) {
			//B[x+1][y+2] = Num+1;
			//если следующий шаг вернул true, значит маршрут построен и дальше искать не надо
			if (KnightsMove(Num + 1, x + 1, y + 2, N, M, B)) {
				return true;
			}
			//перейдем к следующему ходу
		}
	};
	if ((x - 1 >= 0) && (y + 2 <= M - 1)) {
		if (B[x - 1][y + 2] == 0) {
			//B[x-1][y+2] = Num+1;
			//если следующий шаг вернул true, значит маршрут построен и дальше искать не надо
			if (KnightsMove(Num + 1, x - 1, y + 2, N, M, B)) {
				return true;
			}
			//перейдем к следующему ходу
		}

	};
	if ((x - 2 >= 0) && (y + 1 <= M - 1)) {
		if (B[x - 2][y + 1] == 0) {
			//B[x-2][y+1] = Num+1;
			//если следующий шаг вернул true, значит маршрут построен и дальше искать не надо
			if (KnightsMove(Num + 1, x - 2, y + 1, N, M, B)) {
				return true;
			}
			//перейдем к следующему ходу
		}

	};
	if ((x - 2 >= 0) && (y - 1 >= 0)) {
		if (B[x - 2][y - 1] == 0) {
			//B[x-2][y-1] = Num+1;
			//если следующий шаг вернул true, значит маршрут построен и дальше искать не надо
			if (KnightsMove(Num + 1, x - 2, y - 1, N, M, B)) {
				return true;
			}
			//перейдем к следующему ходу
		}

	};
	if ((x - 1 >= 0) && (y - 2 >= 0)) {
		if (B[x - 1][y - 2] == 0) {
			//B[x-1][y-2] = Num+1;
			//если следующий шаг вернул true, значит маршрут построен и дальше искать не надо
			if (KnightsMove(Num + 1, x - 1, y - 2, N, M, B)) {
				return true;
			}
			//перейдем к следующему ходу
		}

	};
	//мы проверили все возможные ходы конем с этого места и ни одно не вело к полному обходу
	B[x][y] = 0;
	return false;

}

// Обнулим массив
void Zero(int N, int M, int B[][numCols]){
	int i, j;
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++) {
			B[i][j] = 0;
		}
	}
}

// Напечатаем доску
void printChessBoard(int N, int M, int B[][numCols]){
	int i, j;
	printf("\n   ");
	for (i = 0; i < N; i++){
		printf("%3i", i);
	}
	printf("\n");

	for (i = 0; i < N; i++){
		printf("%3i", i);
		for (j = 0; j < M; j++) {
			printf("%3i", B[i][j]);
		};
		printf("\n");
	}

}

// проверим, что вся доска пройдена (true)
int CheckBoard(int N, int M, int B[][numCols]){
	int i, j;
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++) {
			if (B[i][j] == 0) return false;
		}
	}
	return true;
}

int main(int argc, char** argv)
{
	int i, j;
	int B[numRows][numCols];

	Zero(numRows, numCols, B);
	printChessBoard(numRows, numCols, B);

	//if(KnightsMove(1,0,0,numRows,numCols,B)) printChessBoard(numRows,numCols,B);
	if (KnightsMove(1, 2, 2, numRows, numCols, B)) printChessBoard(numRows, numCols, B);
	CheckBoard(numRows, numCols, B) ? printf("Route was found!\n") : printf("Route was NOT found!\n");

	for (i = 0; i < numRows; i++){
		for (j = 0; j < numCols; j++){
			printf("Check start cell: %3i, %3i\n", i, j);
			Zero(numRows, numCols, B);
			if (KnightsMove(1, j, i, numRows, numCols, B)) {
				printf("\nRoute for start cell: %3i, %3i", i, j);
				printChessBoard(numRows, numCols, B);
				puts("");
			}

		}
	}

	return 0;
}
