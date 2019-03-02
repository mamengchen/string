//1.ʵ��strcpy 
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
//void print(char *arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//}
//
//void print1(char *p)
//{
//	while (*p)
//	{
//		printf("%c ",*p);
//		p++;
//	}
//}
//
//
//
//char *my_strcpy(char*dest, const char*src)
//{
//	char *ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while ((*dest++ = *src++))
//	{
//		;
//	}
//	return ret;
//}
//
//
//
//char *my_strcpy(char *arr, char *arr1,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr1[i] = arr[i];
//
//	}
//	return arr1;
//}
//
//int my_strlen(const char *str)
//{
//	int count = 0;
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//��������ʱ�����ķ���
//int my_strlen(const char*str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(str + 1);
//	}
//}
//
//int my_strlen(const char*str)
//{
//	const char *p = str;
//	while (*p != '\0')
//	{
//		p++;
//	}
//	return p - str;
//}
//
//char *my_strcat(char*dest, const char*src)
//{
//    char *ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest)
//	{
//		dest++;
//	}
//	while ((*dest++ = *src++))
//	{
//		;
//	}
//	return ret;
//}
//
//char *my_strstr(const char *dest, char *src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//
//	char *cp = (char*)dest;
//	char *substr = (char*)src;
//	char *s1 = NULL;
//
//	if (*src == '\0')
//	{
//		return NULL;
//	}
//	
//	while (*cp)
//	{
//		s1 = cp;
//		substr = src;
//		while (*s1&&*substr&&*s1 == *substr)
//		{
//			s1++;
//			substr++;
//		}
//		if (*substr == '\0')
//		{
//			return cp;
//		}
//		cp++;
//	}
//}
//
//char *my_strchr(const char *dest, char a)
//{
//	char *add = 0;
//	while (*dest)
//	{
//		if (*dest == a)
//		{
//			add = dest;
//		}
//		dest++;
//	}
//	return add;
//}
//
//int my_strcmp(const char *src, const char *dst)
//{
//	int ret = 0;
//	while (!(ret = *(unsigned char *)src - *(unsigned char*)dst) && *dst)
//	{
//		++src;
//		++dst;
//	}
//	if (ret < 0) {
//		ret = -1;
//	}
//	else if (ret > 0) {
//		ret = 1;
//	}
//	return ret;
//}
//
//
//
//int main()
//{
//	char arr[10] = "abcdef";
//	
//	char arr1[10];
//	char x = "m";
//	int sz = my_strlen(arr);//���ַ����ĳ���
//
//	print(arr, sz);
//	printf("\n");
//	my_strcpy(arr,arr1,sz);
//	my_strcpy(arr1, arr);//�ַ����Ŀ���
//	print(arr1, sz);
//	char*p = my_strcat(arr1, arr);//�ַ���������
//	printf("\n");
//	print1(p);
//	printf("\n");
//	if (my_strstr(p, arr))
//	{
//		printf("���Ӵ�");
//	}
//	else
//	{
//		printf("�����Ӵ�");
//	}
//	printf("\n");
//	if ( my_strchr(arr1, x))//�ж��ַ�����
//	{
//		printf("shi");
//	}
//	else
//	{
//		printf("bushi");
//	}
//	printf("\n");
//	if (strcmp(arr1, arr) == 0)
//	{
//		printf("һ����");
//	}
//	if (strcmp(arr1, arr) >= 0)
//	{
//		printf("arr1��");
//
//	}
//	if (strcmp(arr1, arr) <= 0)
//	{
//		printf("arr��");
//	}
//	system("pause");
//	return 0;
//}


//void *mymemcpy(void *dst, const void *src, size_t num)
//{
//	assert((dst != NULL) && (src != NULL));
//	int wordnum = num / 4;//�����ж��ٸ�32λ����4�ֽڿ���  
//	int slice = num % 4;//ʣ��İ��ֽڿ���  
//	int * pintsrc = (int *)src;
//	int * pintdst = (int *)dst;
//	while (wordnum--)*pintdst++ = *pintsrc++;
//	while (slice--)*((char *)pintdst++) = *((char *)pintsrc++);
//	return dst;
//}


#include <stdio.h>
#include <string.h>

void MyMemMove(char *pDst, char *pSrc, size_t tLen);
int main(int argc, char **argv)
{
	char pStr[64] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char pStr1[64] = "0123456789abcdefghijklmnopqrstuvwxyz";

	printf("%s\n", pStr);
	MyMemMove(pStr + 3, pStr, 5);
	memmove(pStr1 + 3, pStr1, 5);
	printf("%s\n%s\ncom:%d\n", pStr, pStr1, strcmp(pStr, pStr1));
	return 0;
}

void MyMemMove(char *pDst, char *pSrc, size_t tLen)
{
	/* ��Ŀ���ַ�������ͷ��Դ�ַ������ص�ʱ����Ҫ���⴦��
	* ������Դ�ַ�������[s,S]��Ŀ���ַ�������[d,D]
	*       s  d    S  D
	*/
	if ((pDst>pSrc) && (pDst<(pSrc + tLen)))
	{
		// ���⴦��
		char* p = pSrc + tLen - 1;
		char* q = pDst + tLen - 1;
		while (p >= pSrc)
		{
			*q-- = *p--;
		}
	}
	else
	{
		// ����Ҫ���⴦���ֱ����memcpy
		memcpy(pDst, pSrc, tLen);
	}
}