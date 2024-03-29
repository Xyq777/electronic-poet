/*
    文件名称：poem.c
    文件作者：席应情
    文件功能：生成诗句
*/


#include "../include/poem.h"

void Generate_poem(int pargraphyNum, int lineOfPoem, poem *head)
{
    // 段落框架初始化
    char *pa = (char *)malloc(sizeof(char) * 50 * lineOfPoem);
    memset(pa, 0, sizeof(char) * 50 * lineOfPoem);
    for (int i = 0; i < lineOfPoem; i++)
    {
        char *s = select_sentence();
        int len = strlen(s);
        s[len] = '\n';
        s[len + 1] = '\0';
        strcat(pa, s);
    }
    char lf[3] = "\n\n";
    strcat(pa, lf);

    // 填充段落框架
    for (int i = 0; i < pargraphyNum; i++)
    {
        char *poemStr = (char *)malloc(sizeof(char) * 100 * lineOfPoem);
        memset(poemStr, 0, sizeof(char) * 100 * lineOfPoem);

        for (char *p = pa; *p != '\0'; p++)
        {
            char *word;

            if (*p == 'N')
            {
                word = select_noun();
                printf("%s", word);
                strcat(poemStr, word);
            }
            else if (*p == 'A')
            {
                word = select_adj();
                printf("%s", word);
                strcat(poemStr, word);
            }
            else if (*p == 'O')
            {
                word = select_onom();
                printf("%s", word);
                strcat(poemStr, word);
            }
            else if (*p == 'T')
            {
                word = select_vt();
                printf("%s", word);
                strcat(poemStr, word);
            }
            else if (*p == 'I')
            {
                word = select_vi();
                printf("%s", word);
                strcat(poemStr, word);
            }
            else
            {
                printf("%c", *p);
                int len = strlen(poemStr);
                poemStr[len] = *p;
                poemStr[len + 1] = '\0';
            }
        }
        // 將内容存入内存
        poem *node = (poem *)malloc(sizeof(poem));
        node->data = strdup(poemStr);
        node->next = NULL;
        head->next = node;
        head = node;
        free(poemStr);
    }
}
char *select_sentence()
{
    int random = rand() % Line[5];
    int count = 0;

    for (sentence *i = Sentence_head->next; count <= random && i != NULL; i = i->next, count++)
    {
        if (count == random)
        {
            return i->data;
        }
    }

    return NULL;
}
char *select_noun()
{
    int random = rand() % Line[0];
    return Noun_array[random];
}
char *select_adj()
{
    int random = rand() % Line[1];
    return Adj_array[random];
}
char *select_onom()
{
    int random = rand() % Line[2];
    return Onom_array[random];
}
char *select_vt()
{
    int random = rand() % Line[3];
    return Vt_array[random];
}
char *select_vi()
{
    int random = rand() % Line[4];
    return Vi_array[random];
}