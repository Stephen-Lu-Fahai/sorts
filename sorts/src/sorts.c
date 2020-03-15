/*
 ============================================================================
 Name        : sorts.c
 Author      : stephen
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(int data[], int len)
{
	int i, j, flag = 1;

	for (i = 0; i < len-1 && flag; i++)
	{
		flag = 0;
		for (j = len-1; j >= i; j--)
			if (data[j] > data[j+1])
			{
				swap(&data[j], &data[j+1]);
				flag = 1;
			}

	}
}

void quick_sort(int data[], int left, int right)
{
	if (left >= right)
		return;

	int i = left, j = right;
	int base = data[i];

	while (i != j)
	{
		while (data[j] >= base && j > i)
			j--;
		while (data[i] <= base && j > i)
			i++;

		if (j > i)
			swap(&data[i], &data[j]);
	}
	data[left] = data[i];
	data[i] = base;

	quick_sort(data, left, i-1);
	quick_sort(data, i+1, right);
}

void selection_sort(int data[], int len)
{
	int i, j, min_index;

	for (i = 0; i < len-1; i++)
	{
		min_index = i;
		for (j = i+1; j < len; j++)
			min_index = (data[min_index] > data[j]) ? j :min_index;

		if (min_index != i)
			swap(&data[i], &data[min_index]);
	}
}

void insertion_sort(int data[], int len)
{
	int i, pre_index;
	int current;

	for (i = 1; i < len; i++)
	{
		current = data[i];
		pre_index = i - 1;

		while(data[pre_index] > current && pre_index >= 0)
		{
			data[pre_index+1] = data[pre_index];
			pre_index--;
		}
		data[pre_index+1] = current;
	}
}

void shell_sort(int data[], int len)
{
	int i, j, gap, current;

	for (gap = len / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < len; i++)
		{
			j = i;
			current = data[i];

			while (j-gap >= 0 && current < data[j-gap])
			{
				data[j] = data[j-gap];
				j -= gap;
			}
			data[j] = current;
		}

	}
}


int main(void) {
	int data[] = {86, 6, 34, 22, 40, 9, 84, 55, 97, 27, 85,
					53, 59, 32, 37, 15, 29, 64, 56, 51, 87,
					61, 83, 30, 67, 35, 73, 39, 49, 13, 96,
					11, 38, 93, 79, 48, 31, 71, 81, 58, 90,
					26, 23, 5, 80, 1, 50, 63, 41, 92};
	int i, len = sizeof(data) / sizeof(int);
	int left = 0, right = len - 1;


	selection_sort(data, len);


	for(i = 0; i < len; i++)
	{
		printf("%d ", data[i]);
		if (i % 10 == 0)
			printf("\n");
	}

	return EXIT_SUCCESS;
}
