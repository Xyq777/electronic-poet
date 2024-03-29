/*
	�ļ����ƣ�util.c
	�ļ����ߣ�ϯӦ��
	�ļ����ܣ����ߺ���
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
	printf("Ոݔ��Ԋ����Д�\n");
	int n = scanf("%d", &line);
	if (!n || line <= 0)
	{
		printf("�����ʽ����ȷ������������!\n");
		return -1;
	}
	return line;
}
int Scan_paragraph_of_poem()
{
	int p = 0;
	printf("Ոݔ��Ԋ��ĶΔ�\n");
	int n = scanf("%d", &p);
	if (!n || p <= 0)
	{
		printf("�����ʽ����ȷ�����������룡\n");
		return -1;
	}
	return p;
}
char *Scan_name_of_poem()
{
	char *name = malloc(sizeof(char) * 100);
	if (name == NULL)
	{
		printf("�ڴ����ʧ�ܣ�\n");
		return NULL;
	}
	printf("Ո��Ԋ����\n");
	int n = scanf("%99s", name);
	if (n != 1)
	{
		printf("�����ʽ����ȷ�����������룡\n");
		free(name);
		return NULL;
	}
	return name;
}
