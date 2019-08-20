#include <stdio.h>

#define MAXSIZE 6
int adjustArray(int s[], int l, int r)
{
	int pivot = s[l];
	while(l < r)
	{
		while(l < r && s[r] >= pivot)
		{
			--r;
		}
		s[l] = s[r];
		while(l < r && s[l] <= pivot)
		{
			++l;
		}
		s[r] = s[l];
	}
	s[l] = pivot;
	return l;
}
void QuickSort(int s[], int l, int r)
{
	if(l < r)
	{
		int pivot = adjustArray(s, l, r);
		QuickSort(s, l, pivot-1);
		QuickSort(s, pivot+1, r);
	}
}
int main()
{
	int s[MAXSIZE], i;
	printf("Input %d numbers: \n", MAXSIZE);
	for(i = 0; i < MAXSIZE; i++)
	{
		 scanf("%d", &s[i]);
	}
	printf("the rank of before sort:\n");
	for(i = 0; i < MAXSIZE; i++)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
	QuickSort(s, 0, MAXSIZE - 1);
	printf("the rank of after sort:\n");
	for(i = 0; i < MAXSIZE; i++)
	{
		printf("%d ", s[i]);
	}
	return 0;
}

