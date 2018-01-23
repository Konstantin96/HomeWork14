#include <iostream>
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>
int sum_1j(int a[8][5]);
int sum_2i(int a[8][5]);
int *findSum(int **A, int n, int m);
using namespace std;

int main()
{
start:
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int nz;
	cout << "Vvedite nomer zadaniya: ";
	cin >> nz;
	cout << endl;
	switch (nz)
	{

	case 1:
	{
		/*  Дан целочисленный квадратный массив 10×10. Найти сумму элементов  каждой строки.*/
		int mas[10][10], sum = 0;

		for (int i = 0; i < 10; i++)
		{
			sum = 0;
			for (int j = 0; j < 10; j++)
			{
				mas[i][j] = 10 + rand() % 90;
				sum += mas[i][j];
				cout << mas[i][j] << "  ";
			}

			cout << "= " << sum << endl << endl;
		}
		cout << endl;
	}
	break;

	case 2:
	{
		/*  Дан целочисленный квадратный массив 4×4. Найти строку с наименьшей суммой элементов*/
		int mas[4][4], sum = 0;

		for (int i = 0; i < 4; i++)
		{
			sum = 0;
			for (int j = 0; j < 4; j++)
			{
				mas[i][j] = 10 + rand() % 90;
				sum += mas[i][j];
				cout << mas[i][j] << "  ";
				if (mas[i][j] < sum)
					cout << mas[i][j] << "  ";
			}


		}
		cout << endl;
	}
	break;

	case 3:
	{
		/*  Дана целочисленная матрица  6× 8. Найти произведение положительных элементов первого столбца.*/
		const int n = 6, m = 8;
		int proizv = 1;
		int a[n][m];
		int i, j;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			{
				a[i][j] = 1 + rand() % 9;
			}
		j = 0;
		for (i = 0; i < n; i++)
			if (a[i][j] > 0)
				proizv = a[i][j] * proizv;
		cout << "Произведение = " << proizv;
		cout << endl;
	}
	break;

	case 4:
	{
		/*Составить программу, которая заполняет квадратную матрицу порядка n натуральными числами 1, 2, 3, .. ., n2, записывая их в нее "по спирали" по часовой стрелке.*/
		cout << "Введите ширину матрицы:  ";
		int nX;
		cin >> nX;
		cout << "Введите длину матрицы:   ";
		int nY;
		cin >> nY;

		int **massiv = new int*[nX];
		for (int tmp = 0; tmp < nX; tmp++)  massiv[tmp] = new int[nY];

		int i = 0, j = 0, c = 0, d = 1;
		int a = nX;
		int b = nY;
		int nLastNumber = 1;
		int maxNumber = nY*nX;

		while (true) {
			a--;
			b--;

			while (j < b) {
				massiv[i][j] = nLastNumber;
				nLastNumber++;
				j++;
			}
			if (nLastNumber == maxNumber) break;

			while (i < a) {
				massiv[i][j] = nLastNumber;
				nLastNumber++;
				i++;
			}
			if (nLastNumber == maxNumber) break;

			j = b;
			i = a;

			while (j > c) {
				massiv[i][j] = nLastNumber;
				nLastNumber++;
				j--;
			}
			if (nLastNumber == maxNumber) break;

			while (i > d) {

				massiv[i][j] = nLastNumber;
				nLastNumber++;
				i--;
			}
			if (nLastNumber == maxNumber)  break;

			j = c;
			i = d;
			c++;
			d++;


		}
		massiv[i][j] = maxNumber;

		for (j = 0; j < nY; j++) {
			cout << "\n";
			for (i = 0; i < nX; i++) {
				cout << massiv[i][j] << "\t";
			}
		}

		for (i = 0; i < nX; i++) delete[] massiv[i];
		delete[] massiv;
		cout << "\n";
		system("pause");
	}
	break;

	case 5:
	{
		/* Дан двухмерный целочисленный массив A(M,N). Составить  одномерный массив B из номеров строк этого массива*/
		int B[100];
		int n, m, i;
		cout << "Введите размер массива :";
		cin >> n;
		for (i = 0; i < n; i++)
		{
			B[i] = i;
			cout << B[i] << " ";
		}
	}
	break;

	case 6:
	{
		/* Написать программу, которая в матрице чисел A(N,M) находит все элементы, превышающие по абсолютной величине заданное число B. Подсчитать число таких элементов и записать их в массив C. */
		int n = 0, m = 0; 
		int **A; 
		int *sum; 
		
		cout << "Введите размеры массива\nКол-во столбцов : ";
		cin >> n;
		cout << "Кол-во строк : ";
		cin >> m;
		
		A = new int*[n];
		for (int i = 0; i<n; i++)
			A[i] = new int[m];
	
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++)
			{
				A[i][j] = 1 + rand() % 9;
			}
		
		sum = findSum(A, n, m);
		for (int i = 0; i<n; i++)
			cout << i << "-я строка, сумма = " << sum[i] << endl; 
																
		delete[]sum;
		for (int i = 0; i<n; i++)
			delete[]A[i];
		delete[]A;
	}
	break;

	case 7:
	{
		/*  Дана целочисленная матрица размера 8х5. Определить:
a.	сумму всех элементов второго столбца массива;
b.	сумму всех элементов 3-й строки массива
*/
		int i, j;
		int a[8][5];
		srand(time(0));

		for (i = 0; i < 8; i++) {
			for (j = 0; j < 5; j++) {
				a[i][j] = rand() % 20;
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "Сумма всех элементов второго столбца массива = " << sum_1j(a) << endl << endl;
		cout << "Сумма всех элементов 3-й строки массива = " << sum_2i(a) << endl << endl;


		return 0;
	}
	break;

	case 8:
	{
		/*  Дана целочисленная прямоугольная матрица размера M·N. Сформировать одномерный массив, состоящий из элементов, лежащих в интервале [1,10].
		Найти произведение елементов полученного одномерного массив*/
		int k = 0, i;
		const int m = 5, n = 7;
		int a[m][n], b[m];
		for (int i = 0; i < n; i++)
			for (int j = 0; i < m; j++)
				if (a[i][j] > -3.0 && a[i][j] <= 5.0)
					b[k++] = a[i][j];
		/*ya zaputalsya!!!!!!!!!!*/
	}
	break;

	case 9:
	{
		/*  Дана целочисленная квадратная матрица. Указать столбец (назвать его номер), где минимальное количество элементов, кратных сумме индексов*/
		const int M = 9, N = 7;
		int A[N][M], i, j, x, count, min = N;
		srand(time(NULL));
		for (i = 0; i < N; i++, putchar('\n'))
			for (j = 0; j < M; j++)
				printf("%4d", A[i][j] = rand() % 144);
		putchar('\n');
		for (j = 0; j < M; j++, putchar('\n')) {
			printf("Column ", j);
			for (i = 0, count = 0; i < N; i++) {
				if (i || j) {
					if (A[i][j] % (i + j) == 0) {
						cout << "A; " << i << j << i + j;
						count++;
					}
				}
			}
			if (count < min && count > 0) {
				min = count;
				x = j;
			}
		}
		cout << "\nColumn %d has minimal number elements multiple sum its indices: %d;\n" << x << min;
		return 0;
	}
	break;

	case 10:
	{
		/* Дана целочисленная квадратная матрица. Найти сумму элементов матрицы, лежащих выше главной диагонали*/
		int i, j;
		int a[3][3];
		cout << "Матрица" << endl;
		for (int i = 0; i<3; i++)
			for (j = 0; j<3; j++)
				a[i][j] = rand() % 20;
				
		for (i = 0; i<3; i++) {
			for (j = 0; j<3; j++)
				cout << a[i][j]<<" ";
			cout << endl;
		}
		int sum = 0;
		for (int i = 1; i<3; i++)
			for (int j = 0; j<i; j++)
				sum += a[i][j];
		cout << "сумма элементов лежащих ниже диагонали=" << sum << endl;
		int p = 1;
		for (int i = 0; i<3 - 1; i++)
			for (int j = 3 - 1; j>i; j--)
				p *= a[i][j];
		cout << "произведение эл.лежащих выше главной диагонали=" << p << endl;
		return 0;

	}
	break;
	}
}

int sum_1j(int a[8][5])
{
	int i, j;
	int s = 0;

	for (i = 0; i < 8; i++)
		s += a[i][1];

	return s;
}

int sum_2i(int a[8][5])
{
	int i, j;
	int s = 0;

	for (j = 0; j < 5; j++)
		s += a[2][j];

	return s;
}
int *findSum(int **A, int n, int m)
{
	int *sumArr = new int[n]; // массив который будет хранить суммы строк ( сумм-массив )
	int temp = 0; // "временная" сумма
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
			temp = temp + A[i][j]; //складываем все элементы одной строки и пишем их в temp
		sumArr[i] = temp; // потом перекидываем эту сумму в i-й элемент сумм-массива
		temp = 0; // обнуляем временную сумму
	}
	return sumArr; //возвращаем указатель на сумм-массив
}
