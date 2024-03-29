#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/config.h"




/**
 * @brief 生成一首诗。
 * @param pargraphyNum 诗的段落数
 * @param lineOfPoem 每段诗的行数
 * @param head 诗的头部指针
 */
extern void Generate_poem(int pargraphyNum, int lineOfPoem, poem *head);

 char *select_sentence();
 char *select_noun();
 char *select_adj();
 char *select_onom();
 char *select_vt();
 char *select_vi();