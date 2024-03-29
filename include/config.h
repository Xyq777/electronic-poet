#ifndef MODEL_H
#define MODEL_H

#include<stdio.h>
#include<stdlib.h>
#define FILE_NUM 5
typedef char** word_array;
typedef struct Sentence{
	char *data;
	struct Sentence *next;
}sentence;
typedef struct Poem{
	char *data;
	struct Poem *next;
}poem;
//全局變量
extern word_array Adj_array;
extern word_array Vi_array;
extern word_array Onom_array;
extern word_array Vt_array;
extern word_array Noun_array;
extern sentence *Sentence_head;
extern int Line[6];
#endif // MODEL_H