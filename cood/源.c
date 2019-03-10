//#include<stdio.h>
//#include<stddef.h>
//
//size_t
//my_strnlen(char const *string, int size) {
//	register size_t    length;
//	for (length = 0; length < size; length += 1) {
//		if (*string++ == '\0') {
//			break;
//		}
//	}
//	return length;
//}

//#include<stdio.h>
//#include<time.h>
//#include<stdlib.h>
//
//#define N 10
//
//int main()
//{
//	srand(time(NULL));
//	char arr[] = { '9','8','7','6','5','4','3','2','1' };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int j = sz;
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] % 2 == 0)
//		{
//			if (arr[j] % 2 != 0)
//			{
//				int sum = 0;
//				sum = arr[j];
//				arr[j] = arr[i];
//				arr[i] = arr[j];
//			}
//			j--;
//			
//		}
//		if (i == j)
//		{
//			break;
//		}
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf(" %d ", arr[i]);
//
//	}
//	system("pause");
//	return 0;
//}



//有错误
//int my_strnlen(char arr, int sz)
//{
//	int* p = arr;
//	int length = 0;
//	for (length = 0;; length += 1) {
//		if (*p == '\0') {
//			break;
//		}
//	}
//	return length;
//}
//
//int main()
//{
//	char arr[] = { '1','2','3','4','5','6' };
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	printf("%d", my_strnlen(arr, sz) );
//	system("pause");
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#if 0
// 1.调整数组使奇数全部都位于偶数前面。
#define N 10
int arr[N];

void genArr(int n)
{
	for (int i = 0; i<n; i++)
		arr[i] = rand() % 1000 + 1;
}

void show(int n)
{
	for (int i = 0; i<n; i++) {
		printf("%d\t", arr[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
}

void  changeOddEven(int n)
{
	int i = 0;
	int j = n - 1;

	while (i < j) {
		while ((i < j) && (arr[i] % 2 != 0))
			i++;
		while ((i < j) && (arr[j] % 2 == 0))
			j--;

		arr[i] = arr[i] ^ arr[j];
		arr[j] = arr[i] ^ arr[j];
		arr[i] = arr[i] ^ arr[j];

		i++;
		j--;
	}
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	genArr(N);
	printf("before:\n");
	show(N);

	changeOddEven(N);
	printf("after:\n");
	show(N);

	return 0;
}
#endif 

#if 0
// 2. 杨氏矩阵
#define N 10

void show(int arr[N][N], int len)
{
	for (int i = 0; i< len; i++) {
		for (int j = 0; j<len; j++)
			printf("%3d ", arr[i][j]);
		printf("\n");
	}
}

void init(int arr[N][N], int len)
{
	for (int i = 0; i<len; i++) {
		for (int j = 0; j<len; j++) {
			arr[i][j] = (i + 1) * (j + 1) * 2;
		}
	}
}

// 找到返回1， 没找到返回0 
int find(int arr[N][N], int len, int val)
{
	int row = 0;
	int col = len - 1;

	while (1) {
		printf("(%d, %d): %d\n", row, col, arr[row][col]);
		if (arr[row][col] == val)
			return 1;
		else if (arr[row][col] > val) {
			col--;
			if (col < 0)
				break;
		}
		else if (arr[row][col] < val) {
			row++;
			if (row >= len)
				break;
		}
	}

	return 0;
}

int main(void)
{
	int arr[N][N] = {};
	init(arr, N);
	show(arr, N);

	printf("find num:");
	int num;
	scanf("%d", &num);
	if (find(arr, N, num)) {
		printf("找到了\n");
	}
	else {
		printf("没有找到\n");
	}

	return 0;
}


// 3. 分2舍3入
int main(void)
{
	double num;
	printf("请输入金额:");
	scanf("%lf", &num);

	int tmp = num * 100;

	if ((tmp % 10) >= 3) {
		tmp += 10;
		tmp -= ((int)(num * 100)) % 10;
	}
	else {
		tmp -= tmp % 10;
	}
	num = tmp / 100.0;

	printf("%.2lf\n", num);
}
#endif
// 判断数组是否有序

int isOrder(int *arr, int len)
{
	if (len == 1) return 1;
	if (len == 2) return arr[0] < arr[1];
	else return arr[len - 2] < arr[len - 1] && isOrder(arr, len - 1);
}

int main(void)
{
	int arr[5] = { 1,2,6,4,5 };
	printf("%d\n", isOrder(arr, 5));
}

