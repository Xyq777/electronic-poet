/*
    文件名称：file.c
    文件作者：席应情
    文件功能：文件操作
*/

#include "../include/file.h"

FILE *File_open(char *filepath)
{
    FILE *file = fopen(filepath, "r");
    if (file == NULL)
    {
        printf("無法打開文件%s\n", filepath);
        exit(1);
    }
    return file;
}

long int Get_file_size(char *filepath)
{
    FILE *file = File_open(filepath);
    long int size = 0;
    if (file != NULL)
    {
        fseek(file, 0, SEEK_END); // 將文件指針移動到文件末尾
        size = ftell(file);       // 獲取文件指針的當前位置，即文件大小
        rewind(file);             // 將文件指針重置到文件開頭
    }
    fclose(file);
    return size;
}
void Save_poem_to_file(poem *head, char *filename)
{

    char filepath[100]; // 假設文件路徑的最大長度為100
    snprintf(filepath, sizeof(filepath), "./poem/poem_%s", filename);
    struct stat buffer;
    if (stat(filepath, &buffer) != -1)
    {
        printf("同名的詩已存在，是否覆蓋？(Y/N)");
        getchar();
        char c;
        scanf("%c", &c);
        // printf("c:%c\n", c);
        if (c == 'Y' || c == 'y')
        {
            FILE *file = fopen(filepath, "w");
            if (file == NULL)
            {
                printf("保存失敗");
                return;
            }

            poem *current = head->next;
            while (current != NULL)
            {
                fprintf(file, "%s\n", current->data); // 将节点数据写入文件
                current = current->next;
            }

            fclose(file);
            return;
        }
    }
    else
    {
        FILE *file = fopen(filepath, "w");
        if (file == NULL)
        {
            printf("保存失敗");
            return;
        }

        poem *current = head->next;
        while (current != NULL)
        {
            fprintf(file, "%s\n", current->data); // 将节点数据写入文件
            current = current->next;
        }

        fclose(file);
        return;
    }
}

void List_poems_throgh_dir()
{
    DIR *dir;
    struct dirent *entry;
    const char *prefix = "poem_";

    dir = opendir("./poem");
    if (dir == NULL)
    {
        printf("打開目錄失敗");
        return;
    }

    int count = 1;
    while ((entry = readdir(dir)) != NULL)
    {
        if (strncmp(entry->d_name, prefix, strlen(prefix)) == 0)
        {
            printf("%d. %s\n", count, entry->d_name + strlen(prefix));
            count++;
        }
    }
    closedir(dir);
}
void find_poem()
{
    printf("請輸入詩名：");
    char poemname[100];
    scanf("%s", poemname);
    char filename[100];
    sprintf(filename, "./poem/poem_%s", poemname);
    FILE *poem_file = fopen(filename, "r");
    if (poem_file == NULL)
    {
        printf("找不到這首詩。\n");
        return;
    }
    // 读取并显示文件内容
    char line[100];
    while (fgets(line, sizeof(line), poem_file) != NULL)
    {
        printf("%s", line);
    }
    fclose(poem_file);
}
void delete_poem()
{
    printf("請輸入詩名：");
    char poemname[100];
    scanf("%s", poemname);
    char filename[100];
    sprintf(filename, "./poem/poem_%s", poemname);
    FILE *poem_file = fopen(filename, "r");
    if (poem_file == NULL)
    {
        printf("找不到這首詩。\n");
        return;
    }
    fclose(poem_file);
    remove(filename);
    printf("刪除成功\n");
}
void Save_string_to_file(char *poem, char *filename)
{

    char filepath[100]; // 假設文件路徑的最大長度為100
    snprintf(filepath, sizeof(filepath), "./poem/poem_%s", filename);
    struct stat buffer;
    if (stat(filepath, &buffer) != -1)
    {

        printf("同名的詩已存在，是否覆蓋？(Y/N)");
        char c;
        scanf("%c", &c);
        // printf("c:%c\n", c);
        if (c == 'Y' || c == 'y')
        {
            FILE *file = fopen(filepath, "w");
            if (file == NULL)
            {
                printf("保存失敗");
                return;
            }

            fprintf(file, "%s\n", poem);

            fclose(file);
        }
    }
    else
    {
        FILE *file = fopen(filepath, "w");
        if (file == NULL)
        {
            printf("保存失敗");
            return;
        }

        fprintf(file, "%s\n", poem);

        fclose(file);
    }
}