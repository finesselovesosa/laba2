#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<locale.h>
int i = 0, j = 0, r;
const int N = 4000;
int a[N][N], b[N][N], c[N][N], elem_c;

int main(void)
{
	FILE* fp;
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setlocale(LC_ALL, "rus");

	srand(time(NULL)); // инициализируемпараметрыгенератораслучайныхчисел
	while (i < N)
	{
		while (j < N)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < N)
	{
		while (j < N)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}

	double start = clock();
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			elem_c = 0;
			for (r = 0; r < N; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	double end = clock();
	fp = fopen("lab2.txt", "a");
	printf("Количество элементов: %d\n", N);
	fprintf(fp, "Количество элементов: %d\n", N);
	printf("Времявыполненияпрограммы: %f\n", (end - start) / CLOCKS_PER_SEC);
	fprintf(fp, "Времявыполненияпрограммы: %f\n", (end - start) / CLOCKS_PER_SEC);
	fclose(fp);
	getch();
	return(0);
}