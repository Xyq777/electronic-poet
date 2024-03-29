/*
    文件名称：config.c
    文件作者：王航锐
    文件功能：全局变量

*/
#include "../include/config.h"

word_array Adj_array;
word_array Vi_array;
word_array Onom_array;
word_array Vt_array;
word_array Noun_array;
sentence *Sentence_head;
int Line[6] = {0}; // 0.名詞行數；1.形容詞行數；2.擬聲詞行數；3.及物動詞行数；4.不及物動詞函數；5.句試行數
