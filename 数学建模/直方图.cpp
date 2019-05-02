
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

struct histogram {

	std::string name_x;
	std::string number_y;
};


int max(std::vector<histogram> array, int len)
{
	int maxvalue = 0;
	int i = 0;
	for (i = 0; i < len; i++)
	{
		int number = atoi(array[i].number_y.c_str());
		number = number / 1000;
		if (number > maxvalue)
		{
			maxvalue = number;
		}
	}
	return maxvalue;
}

void vertical(std::vector<histogram> it, int len)
{
	int maxValue = max(it, 10);
	int i;
	int j;
	printf(" y/number_y¡ü\n");
	for (i = maxValue + 1; i > 0; i--)
	{
		printf("%8d|_  ", i);
		for (j = 0; j < 10; j++)
		{
			int array_data = atoi(it[j].number_y.c_str());
			array_data = array_data / 1000;
			if (array_data == i)
			{
				printf(" ___    ");
			}
			else if (array_data >= i)
			{
				printf("|   |   ");
			}
			else if (array_data == i - 1)
			{
				printf(" (%d)    ", array_data);
			}
			else
			{
				printf("        ");
			}
		}
		printf("\n");
	}
	printf("       0");
	for (i = 0; i < 10; i++)
	{
		printf("|___|___");
	}
	printf("|___¡ú\n");
	for (i = 0; i < (2 * 10); i++)
	{
		printf("\t");
	}
	printf("\tx/name_x\n\t ");
	for (i = 0; i < 10; i++)
	{
		printf("    %s", it[i].name_x.c_str());
	}
	printf("\n\n");
}


void Print_histogram()
{
	histogram coordinate;
	int ch = 1;
	std::string mm_buffer;
	char* bp = new char;
	FILE* fp = fopen("./oneboat.txt", "r");
	std::vector<histogram> mm_coordinate;
	while (ch)
	{
		while (ch)
		{
			ch = fread(bp, 1, 1, fp);
			if (*bp == '\n')
			{
				break;
			}

			mm_buffer.push_back(*bp);
		}
		//std::cout << mm_buffer << std::endl;
		size_t a = mm_buffer.find_last_of(':');
		size_t b = mm_buffer.find_first_of(';');
		std::string res1 = mm_buffer.substr(a + 1, b - a - 1);
		//std::cout << res1 << std::endl;
		coordinate.number_y = res1;
		a = mm_buffer.find_first_of('[');
		b = mm_buffer.find_first_of(']');
		std::string res2 = mm_buffer.substr(a + 1, b - a - 1);
		coordinate.name_x = res2;
		//std::cout << res2 << std::endl;
		res1.clear();
		res2.clear();
		mm_buffer.clear();
		mm_coordinate.push_back(coordinate);
	}
	vertical(mm_coordinate, mm_coordinate.size());
}

int main1()
{
	Print_histogram();
	system("pause");
	return 0;
}