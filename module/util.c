/*
	文件名称：util.c
	文件作者：席应情
	文件功能：工具函数
*/

#include "../include/util.h"
void End_program()
{
	free(Adj_array);
	free(Vi_array);
	free(Onom_array);
	free(Vt_array);
	free(Noun_array);
	for (sentence *i = Sentence_head; i != NULL;)
	{
		sentence *next = i->next;
		free(i);
		i = next;
	}
}
int Scan_line_of_poem()
{
	int line = 0;
	printf("請輸入詩句的行數\n");
	int n = scanf("%d", &line);
	if (!n || line <= 0)
	{
		printf("输入格式不正确，请重新输入!\n");
		return -1;
	}
	return line;
}
int Scan_paragraph_of_poem()
{
	int p = 0;
	printf("請輸入詩句的段數\n");
	int n = scanf("%d", &p);
	if (!n || p <= 0)
	{
		printf("输入格式不正确，请重新输入！\n");
		return -1;
	}
	return p;
}
char *Scan_name_of_poem()
{
	char *name = malloc(sizeof(char) * 100);
	if (name == NULL)
	{
		printf("内存分配失败！\n");
		return NULL;
	}
	printf("請為詩命名\n");
	int n = scanf("%99s", name);
	if (n != 1)
	{
		printf("输入格式不正确，请重新输入！\n");
		free(name);
		return NULL;
	}
	return name;
}
