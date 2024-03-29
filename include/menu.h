#include <stdio.h>
#include "./util.h"
#include "./file.h"
#include "./poem.h"
#include "../cgo/cgo_poem.h"

/**
 * @brief 菜单函数声明
 */
extern int Menu();

/**
 * @brief 清屏函数声明
 */
void clear_screen();

/**
 * @brief 显示菜单函数声明
 */
void display_menu();

/**
 * @brief 执行菜单选项函数声明
 * @param choice 选项编号
 */
void execute_menu_item(int choice);

/**
 * @brief 显示关于信息函数声明
 */
void display_about();

/**
 * @brief 显示帮助信息函数声明
 */
void display_help();

/**
 * @brief 写诗函数声明
 * @param poem_head 诗歌链表头指针
 */
void write_poem(poem* poem_head);

/**
 * @brief 保存诗歌函数声明
 * @param poem_head 诗歌链表头指针
 */
void save_poem(poem* poem_head);

/**
 * @brief 释放诗歌内存函数声明
 * @param poem_head 诗歌链表头指针
 */
void free_poem(poem* poem_head);

/**
 * @brief 升级诗歌函数声明
 * @param poem_head 诗歌链表头指针
 */
void upgrade_poem(poem *poem_head);

