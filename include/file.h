#ifndef FILE_H
#define FILE_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

#include"./config.h"

/**
 * @file file.h
 * @brief 包含文件操作函数声明的头文件。
 *
 * 该文件声明了文件操作的函数，如获取文件大小、打开文件、将诗保存到文件、将字符串保存到文件、
 * 遍历目录中的诗歌、查找诗歌和删除诗歌。
 */


/**
 * @brief 获取文件大小的函数声明
 *
 * 该函数用于获取指定文件的大小。
 *
 * @param filename 文件名
 * @return 文件大小
 */
extern long int Get_file_size(char* filename);

/**
 * @brief 打开文件的函数声明
 *
 * 该函数用于打开指定文件。
 *
 * @param filename 文件名
 * @return 文件指针
 */
extern FILE *File_open(char* filename);

/**
 * @brief 将诗保存到文件的函数声明
 *
 * 该函数用于将诗保存到指定文件中。
 *
 * @param head 诗的头节点指针
 * @param filename 文件名
 */
extern void Save_poem_to_file(poem* head,char* filename);

/**
 * @brief 将字符串保存到文件的函数声明
 *
 * 该函数用于将字符串保存到指定文件中。
 *
 * @param poem 字符串
 * @param filename 文件名
 */
extern void Save_string_to_file( char* poem, char* filename);

/**
 * @brief 遍历目录中的诗歌的函数声明
 *
 * 该函数用于遍历指定目录中的诗歌。
 */
extern void List_poems_throgh_dir();

/**
 * @brief 查找诗歌的函数声明
 *
 * 该函数用于查找诗歌。
 */
extern void find_poem();

/**
 * @brief 删除诗歌的函数声明
 *
 * 该函数用于删除诗歌。
 */
extern void delete_poem();


#endif //FILE_H
