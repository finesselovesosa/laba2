#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int mas[15000];
FILE* fp;
double start, end;


void qs(int* items, int left, int right) //вызовфункции: qs(items, 0, count-1); 
{
	int i, j;
	int x, y;

	i = left; j = right;
	/* выбор компаранда */
	x = items[(left + right) / 2];
	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;
		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);
	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);

}

void shell(int* items, int count)
{
	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

int cmp(const void* a, const void* b) { //функциясравненияэлементовмассива
	{
		return *(int*)a - *(int*)b; // Если результат вычитания равен 0, то числа равны
	}
}

void sort(int* items) {
	printf("\nСортировкаШелла:\t");
	fprintf(fp, "\nСортировка Шелла:\t");
	start = clock();
	shell(items, 15000);
	end = clock();
	printf("%20lf", (end - start) / CLOCKS_PER_SEC);
	fprintf(fp, "%20lf", (end - start) / CLOCKS_PER_SEC);

	printf("\nБыстрая сортировка:\t");
	fprintf(fp, "\nБыстрая сортировка:\t");
	start = clock();
	qs(items, 0, 15000 - 1);
	end = clock();
	printf("%20lf", (end - start) / CLOCKS_PER_SEC);
	fprintf(fp, "%20lf", (end - start) / CLOCKS_PER_SEC);

	printf("\nФункция быстрой сортировки:\t");
	fprintf(fp, "\nФункция быстрой сортировки:\t");
	start = clock();
	qsort(items, 15000, sizeof(int), cmp);
	end = clock();
	printf("%12lf", (end - start) / CLOCKS_PER_SEC);
	fprintf(fp, "%12lf", (end - start) / CLOCKS_PER_SEC);
}

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int i, j;
	fp = fopen("lab2.2.txt", "w");

	printf("Случайные числа\n ");
	fprintf(fp, "Случайные числа\n ");
	for (i = 0; i < 15000; i++) {
		mas[i] = rand() % 100 + 1;
	}
	sort(mas);

	printf("\n\nВозрастающая последовательность\n ");
	fprintf(fp, "\n\nВозрастающая последовательность\n ");
	for (i = 0; i < 15000; i++) {
		mas[i] = i;
	}
	sort(mas);

	printf("\n\nУбывающая последовательность\n ");
	fprintf(fp, "\n\nУбывающая последовательность\n ");
	for (i = 0; i < 15000; i++) {
		mas[i] = 15000 - i;
	}
	sort(mas);

	printf("\n\nВозрастающе-убывающая последовательность\n ");
	fprintf(fp, "\n\nВозрастающе-убывающая последовательность\n ");
	for (i = 0; i < 7500; i++) {
		mas[i] = mas[i - 1] + 1;
	}
	for (i = 7500; i < 15000; i++) {
		mas[i] = 15000 - i;
	}
	sort(mas);
	fclose(fp);

	getch();
	return(0);
}