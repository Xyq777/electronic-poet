/*
    文件名称：init.c
    文件作者：席应情
    文件功能：初始化
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
    // 將文件中的每一行存入word_array
    while (fgets(temp, sizeof(temp), file) != NULL)
    {
        // 去除每行末尾的换行符
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
        printf("無法打開文件\n");
    }

    // 讀取内容
    int count = 0;
    char temp[100];
    while (fgets(temp, sizeof(temp), file) != NULL)
    {
        // 去除行末換行符
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

    fclose(file); // 關閉文件
}
void Init()
{

    // 初始化加載單詞數組
    char *file_paths[FILE_NUM] = {
        "./data/word_noun",
        "./data/word_adjective",
        "./data/word_onomatopoeia",
        "./data/word_transitive_verb",
        "./data/word_intransitive_verb"};
    // 問題：不知道爲啥這樣初始化main函數裏面數組就沒數據
    /* word_array all_word_array[5] = {Noun_array,Adj_array,Onom_array,Vt_array,Vi_array};
     for (int i = 0; i < 5; i++){
         all_word_array[i] = (word_array)malloc(Get_file_size(file_paths[i])+10000);//防止可能的越界
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
    // 初始化加載句子鏈表
    Sentence_head = NULL;

    init_sentence(&Sentence_head);
}
