#ifndef INIT_H
#define INIT_H

#include"./file.h"
#include"./config.h"



/**
 * 初始化单词数组
 * 
 * @param filename 文件名
 * @param _word_array 单词数组指针
 * @return void
 */
int init_word(char* filename, word_array* _word_array);

/**
 * 初始化句子链表
 * 
 * @param sentence_head 句子链表头指针
 * @return void
 */
void init_sentence(sentence** sentence_head);

/**
 * 初始化函数
 * 
 * @return void
 */
extern void Init();


#endif // INIT_H