/*
    �ļ����ƣ�init.c
    �ļ����ߣ�ϯӦ��
    �ļ����ܣ���ʼ��
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/init.h"

int init_word(char *filename, word_array *_word_array)
{

    FILE *file = File_open(filename);

    char temp[100];
    int count = 0;
    // ���ļ��е�ÿһ�д���word_array
    while (fgets(temp, sizeof(temp), file) != NULL)
    {
        // ȥ��ÿ��ĩβ�Ļ��з�
        size_t len = strlen(temp);
        if (len > 0 && temp[len - 1] == '\n')
        {
            temp[len - 1] = '\0';
        }

        (*_word_array)[count] = strdup(temp);
        count++;
    }

    fclose(file);
    return count;
}
void init_sentence(sentence **Sentence_head)
{
    sentence *sentence_tail = NULL;
    *Sentence_head = sentence_tail = (sentence *)malloc(sizeof(sentence));

    FILE *file = File_open("./data/sentence");
    if (file == NULL)
    {
        printf("�o�����_�ļ�\n");
    }

    // �xȡ����
    int count = 0;
    char temp[100];
    while (fgets(temp, sizeof(temp), file) != NULL)
    {
        // ȥ����ĩ�Q�з�
        size_t len = strlen(temp);
        if (len > 0 && temp[len - 1] == '\n')
        {
            temp[len - 1] = '\0';
        }
        count++;
        sentence *sentence_node = (sentence *)malloc(sizeof(sentence));
        sentence_node->data = strdup(temp);
        sentence_node->next = NULL;
        sentence_tail->next = sentence_node;
        sentence_tail = sentence_node;
    }
    Line[5] = count;

    fclose(file); // �P�]�ļ�
}
void Init()
{

    // ��ʼ�����d���~���M
    char *file_paths[FILE_NUM] = {
        "./data/word_noun",
        "./data/word_adjective",
        "./data/word_onomatopoeia",
        "./data/word_transitive_verb",
        "./data/word_intransitive_verb"};
    // ���}����֪����ɶ�@�ӳ�ʼ��main�����Y�攵�M�͛]����
    /* word_array all_word_array[5] = {Noun_array,Adj_array,Onom_array,Vt_array,Vi_array};
     for (int i = 0; i < 5; i++){
         all_word_array[i] = (word_array)malloc(Get_file_size(file_paths[i])+10000);//��ֹ���ܵ�Խ��
         Line[i]=init_word(file_paths[i], &(all_word_array[i]));
     }*/
    Noun_array = (word_array)malloc(Get_file_size(file_paths[0]) + 10000);
    Line[0] = init_word(file_paths[0], &Noun_array);
    Adj_array = (word_array)malloc(Get_file_size(file_paths[1]) + 10000);
    Line[1] = init_word(file_paths[1], &Adj_array);
    Onom_array = (word_array)malloc(Get_file_size(file_paths[2]) + 10000);
    Line[2] = init_word(file_paths[2], &Onom_array);
    Vt_array = (word_array)malloc(Get_file_size(file_paths[3]) + 10000);
    Line[3] = init_word(file_paths[3], &Vt_array);
    Vi_array = (word_array)malloc(Get_file_size(file_paths[4]) + 10000);
    Line[4] = init_word(file_paths[4], &Vi_array);
    /*for (int i = 0; i < 5; i++)  printf("%s\n", all_word_array[i][0]); */
    // ��ʼ�����d����朱�
    Sentence_head = NULL;

    init_sentence(&Sentence_head);
}
