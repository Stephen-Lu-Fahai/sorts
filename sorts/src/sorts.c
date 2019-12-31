/*
 ============================================================================
 Name        : sorts.c
 Author      : Stephen_Lu
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */
#include "sorts.h"


void bubule_sort(int data[], int len)
{
	int i, j, temp;

	for(i = 0; i < len-1; i++)
	{
		for (j = i+1; j < len; j++)
		{
			if (data[j] < data[i])
			{
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
}

void quick_sort(int data[], int left, int right)
{
	if (left > right)
		return;

	int i = left, j = right;
	int base = data[i], temp;

	while (i != j)
	{
		while ((data[j] >= base) && (j > i))
			j--;
		while ((data[i] <= base) && (j > i))
			i++;

		if (i < j)
		{
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	data[left] = data[i];
	data[i] = base;

	quick_sort(data, left, i-1);
	quick_sort(data, i+1, right);
}

void selection_sort(int data[], int len)
{
	int i, j, temp, min_index;

	for (i = 0; i < len-1; i++)
	{
		min_index = i;
		for (j = i+1; j < len; j++)
		{
			min_index = (data[j] < data[min_index]) ? j : min_index;
		}

		temp = data[min_index];
		data[min_index] = data[i];
		data[i] = temp;
	}
}

void insertion_sort(int data[], int len)
{
	int i, pre_index, current;

	for(i = 1; i < len; i++)
	{
		pre_index = i - 1;
		current = data[i];

		while((pre_index >= 0) && (data[pre_index] > current))
		{
			data[pre_index+1] = data[pre_index];
			pre_index--;
		}
		data[pre_index+1] = current;
	}
}

void shell_sort(int data[], int len)
{
	int i, j, current, gap;

	for (gap = len / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < len; i++)
		{
			j = i;
			current = data[i];

			while(((j - gap) >= 0) && (current < data[j-gap]))
			{
				data[j] = data[j-gap];
				j = j - gap;
			}
			data[j] = current;
		}
	}
}
