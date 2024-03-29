/* 
    文件名称：menu.c
    文件作者：席应情
    文件功能：菜单
*/

#include "../include/menu.h"

int Menu()
{
    // 启动界面
    clear_screen(); // 清空屏幕
    // 定义程序信息
    char programName[] = "電子詩人";
    char version[] = "1.0";
    char copyright[] = "@ 2024 xyq";

    printf("\033[1;34m"); // 蓝色
    printf("=========================================\n");
    printf("               %s 版本：%s\n", programName, version);
    printf("=========================================\n");
    printf("\033[0m"); // 恢复默认颜色
    printf("%s\n\n", copyright);

    // 主程序循环
    int choice;
    while (1)
    {
        display_menu();
        printf("请选择菜单项：");
        scanf("%d", &choice);

        if (choice == 8)
        {
            printf("\033[1;32m"); // 绿色
            printf("退出程序。\n");
            printf("\033[0m"); // 恢复默认颜色
            break;
        }

        execute_menu_item(choice);
    }

    return 0;
}

// 清空屏幕
void clear_screen()
{
    printf("\033[H\033[2J"); // 使用ANSI转义码清空屏幕
}

// 显示菜单
void display_menu()
{
    printf("\033[1;33m"); // 黄色
    printf("菜单：\n");
    printf("=========================================\n");
    printf("\033[0m"); // 恢复默认颜色

    printf("\033[1;36m"); // 青色
    printf("  1. 关于\n");
    printf("  2. 帮助\n");
    printf("  3. 清屏。\n");
    printf("  4. 后来我就念了两首诗。\n");
    printf("  5. 查看已保存的詩\n");
    printf("  6. 查找诗\n");
    printf("  7. 刪除诗\n");
    printf("  8. 退出\n");
    printf("\033[0m"); // 恢复默认颜色

    printf("\033[1;33m"); // 黄色
    printf("=========================================\n");
    printf("\033[0m"); // 恢复默认颜色
}

// 执行菜单项
void execute_menu_item(int choice)
{
    poem *poem_head = (poem *)malloc(sizeof(poem));
    switch (choice)
    {
    case 1:
        display_about();
        break;
    case 2:
        display_help();
        break;
    case 3:
        clear_screen();
        break;
    case 4:

        poem_head->next = NULL;
        poem_head->data = NULL;
        write_poem(poem_head);
        printf("是否愿意多给我一分来升級下诗Y/N\n");
        upgrade_poem(poem_head);
        free_poem(poem_head);
        break;
    case 5:
        List_poems_throgh_dir();
        break;
    case 6:
        find_poem();
        break;
    case 7:
        delete_poem();
        break;
    default:
        printf("\033[1;31m"); // 红色
        printf("无效的选项，请重新选择。\n");
        printf("\033[0m"); // 恢复默认颜色
    }
}

// 显示关于信息
void display_about()
{
    printf("\033[1;34m"); // 蓝色
    printf("程序名称：電子詩人\n");
    printf("版本信息:1.0\n");
    printf("开发时间:2024年\n");
    printf("开发者信息：\n");
    printf("  姓名：席应情\n");
    printf("  学号:8008123299\n");
    printf("  专业:计算机二类\n");
    printf("  班级:2311班\n");
    printf("\033[0m"); // 恢复默认颜色
}

// 显示帮助信息
void display_help()
{
    printf("\033[1;34m"); // 蓝色
    printf("功能说明：\n");
    printf("  1. 关于：显示程序的基本信息和开发者信息。\n");
    printf("  2. 帮助：显示程序的功能说明和使用说明。\n");
    printf("  3. 清屏。\n");
    printf("  4. 后来我就念了两首诗:输入诗句的行数和段数以生成诗\n");
    printf("  5. 查看已保存的诗:poem下所有poem_前缀的文件\n");
    printf("  6. 查找诗:从poem下检索诗\n");
    printf("  7. 刪除詩\n");
    printf("  8. 退出\n");
    printf("\033[0m"); // 恢复默认颜色
}
void write_poem(poem *poem_head)
{
    int l;
    while ((l = Scan_line_of_poem()) == -1)
    {
        while ((getchar()) != '\n')
            ;
    };
    int p;
    while ((p = Scan_paragraph_of_poem()) == -1)
    {
        while ((getchar()) != '\n')
            ;
    };
    // 生成詩句
    Generate_poem(p, l, poem_head);
}
void save_poem(poem *poem_head)
{
    char c;
    scanf("%c", &c);
    if (c == 'Y' || c == 'y')
    {
        char *filename;
        while ((filename = Scan_name_of_poem()) == NULL)
            ;
        Save_poem_to_file(poem_head, filename);
    }
}
void free_poem(poem *poem_head)
{
    for (poem *i = poem_head; i != NULL;)
    {
        poem *next = i->next;
        free(i);
        i = next;
    }
}
void upgrade_poem(poem *poem_head)
{
    getchar();
    char c;
    scanf("%c", &c);
    // printf("%c", c);
    if (c == 'Y' || c == 'y')
    {
        // printf("升級詩句\n");
        char *poem_string = (char *)malloc(sizeof(char) * 10000);
        poem *p = poem_head->next;
        while (p != NULL)
        {
            strcat(poem_string, p->data);
            p = p->next;
        }
        GoString poem_gostring = {poem_string, strlen(poem_string)};
        char *newPoem;
        newPoem = upgradePoem(poem_gostring);
        getchar();
        printf("\n是否保存升級后的詩Y/N\n");
        char c;
        scanf("%c", &c);
        if (c == 'Y' || c == 'y')
        {
            char *filename;
            while ((filename = Scan_name_of_poem()) == NULL)
                ;
            Save_string_to_file(newPoem, filename);
        }
        free(poem_string);
    }
    else
    {
        // printf("不升級詩句\n");
        getchar();
        printf("\n是否保存詩Y/N\n");
        save_poem(poem_head);
    }
}