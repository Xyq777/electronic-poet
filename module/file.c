/*
    �ļ����ƣ�file.c
    �ļ����ߣ�ϯӦ��
    �ļ����ܣ��ļ�����
*/

#include "../include/file.h"

FILE *File_open(char *filepath)
{
    FILE *file = fopen(filepath, "r");
    if (file == NULL)
    {
        printf("�o�����_�ļ�%s\n", filepath);
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
        fseek(file, 0, SEEK_END); // ���ļ�ָ��Ƅӵ��ļ�ĩβ
        size = ftell(file);       // �@ȡ�ļ�ָᘵĮ�ǰλ�ã����ļ���С
        rewind(file);             // ���ļ�ָ����õ��ļ��_�^
    }
    fclose(file);
    return size;
}
void Save_poem_to_file(poem *head, char *filename)
{

    char filepath[100]; // ���O�ļ�·��������L�Ȟ�100
    snprintf(filepath, sizeof(filepath), "./poem/poem_%s", filename);
    struct stat buffer;
    if (stat(filepath, &buffer) != -1)
    {
        printf("ͬ����Ԋ�Ѵ��ڣ��Ƿ��w��(Y/N)");
        getchar();
        char c;
        scanf("%c", &c);
        // printf("c:%c\n", c);
        if (c == 'Y' || c == 'y')
        {
            FILE *file = fopen(filepath, "w");
            if (file == NULL)
            {
                printf("����ʧ��");
                return;
            }

            poem *current = head->next;
            while (current != NULL)
            {
                fprintf(file, "%s\n", current->data); // ���ڵ�����д���ļ�
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
            printf("����ʧ��");
            return;
        }

        poem *current = head->next;
        while (current != NULL)
        {
            fprintf(file, "%s\n", current->data); // ���ڵ�����д���ļ�
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
        printf("���_Ŀ�ʧ��");
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
    printf("Ոݔ��Ԋ����");
    char poemname[100];
    scanf("%s", poemname);
    char filename[100];
    sprintf(filename, "./poem/poem_%s", poemname);
    FILE *poem_file = fopen(filename, "r");
    if (poem_file == NULL)
    {
        printf("�Ҳ����@��Ԋ��\n");
        return;
    }
    // ��ȡ����ʾ�ļ�����
    char line[100];
    while (fgets(line, sizeof(line), poem_file) != NULL)
    {
        printf("%s", line);
    }
    fclose(poem_file);
}
void delete_poem()
{
    printf("Ոݔ��Ԋ����");
    char poemname[100];
    scanf("%s", poemname);
    char filename[100];
    sprintf(filename, "./poem/poem_%s", poemname);
    FILE *poem_file = fopen(filename, "r");
    if (poem_file == NULL)
    {
        printf("�Ҳ����@��Ԋ��\n");
        return;
    }
    fclose(poem_file);
    remove(filename);
    printf("�h���ɹ�\n");
}
void Save_string_to_file(char *poem, char *filename)
{

    char filepath[100]; // ���O�ļ�·��������L�Ȟ�100
    snprintf(filepath, sizeof(filepath), "./poem/poem_%s", filename);
    struct stat buffer;
    if (stat(filepath, &buffer) != -1)
    {

        printf("ͬ����Ԋ�Ѵ��ڣ��Ƿ��w��(Y/N)");
        char c;
        scanf("%c", &c);
        // printf("c:%c\n", c);
        if (c == 'Y' || c == 'y')
        {
            FILE *file = fopen(filepath, "w");
            if (file == NULL)
            {
                printf("����ʧ��");
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
            printf("����ʧ��");
            return;
        }

        fprintf(file, "%s\n", poem);

        fclose(file);
    }
}