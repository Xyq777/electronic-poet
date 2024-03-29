/* 
    �ļ����ƣ�menu.c
    �ļ����ߣ�ϯӦ��
    �ļ����ܣ��˵�
*/

#include "../include/menu.h"

int Menu()
{
    // ��������
    clear_screen(); // �����Ļ
    // ���������Ϣ
    char programName[] = "���Ԋ��";
    char version[] = "1.0";
    char copyright[] = "@ 2024 xyq";

    printf("\033[1;34m"); // ��ɫ
    printf("=========================================\n");
    printf("               %s �汾��%s\n", programName, version);
    printf("=========================================\n");
    printf("\033[0m"); // �ָ�Ĭ����ɫ
    printf("%s\n\n", copyright);

    // ������ѭ��
    int choice;
    while (1)
    {
        display_menu();
        printf("��ѡ��˵��");
        scanf("%d", &choice);

        if (choice == 8)
        {
            printf("\033[1;32m"); // ��ɫ
            printf("�˳�����\n");
            printf("\033[0m"); // �ָ�Ĭ����ɫ
            break;
        }

        execute_menu_item(choice);
    }

    return 0;
}

// �����Ļ
void clear_screen()
{
    printf("\033[H\033[2J"); // ʹ��ANSIת���������Ļ
}

// ��ʾ�˵�
void display_menu()
{
    printf("\033[1;33m"); // ��ɫ
    printf("�˵���\n");
    printf("=========================================\n");
    printf("\033[0m"); // �ָ�Ĭ����ɫ

    printf("\033[1;36m"); // ��ɫ
    printf("  1. ����\n");
    printf("  2. ����\n");
    printf("  3. ������\n");
    printf("  4. �����Ҿ���������ʫ��\n");
    printf("  5. �鿴�ѱ����Ԋ\n");
    printf("  6. ����ʫ\n");
    printf("  7. �h��ʫ\n");
    printf("  8. �˳�\n");
    printf("\033[0m"); // �ָ�Ĭ����ɫ

    printf("\033[1;33m"); // ��ɫ
    printf("=========================================\n");
    printf("\033[0m"); // �ָ�Ĭ����ɫ
}

// ִ�в˵���
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
        printf("�Ƿ�Ը������һ����������ʫY/N\n");
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
        printf("\033[1;31m"); // ��ɫ
        printf("��Ч��ѡ�������ѡ��\n");
        printf("\033[0m"); // �ָ�Ĭ����ɫ
    }
}

// ��ʾ������Ϣ
void display_about()
{
    printf("\033[1;34m"); // ��ɫ
    printf("�������ƣ����Ԋ��\n");
    printf("�汾��Ϣ:1.0\n");
    printf("����ʱ��:2024��\n");
    printf("��������Ϣ��\n");
    printf("  ������ϯӦ��\n");
    printf("  ѧ��:8008123299\n");
    printf("  רҵ:���������\n");
    printf("  �༶:2311��\n");
    printf("\033[0m"); // �ָ�Ĭ����ɫ
}

// ��ʾ������Ϣ
void display_help()
{
    printf("\033[1;34m"); // ��ɫ
    printf("����˵����\n");
    printf("  1. ���ڣ���ʾ����Ļ�����Ϣ�Ϳ�������Ϣ��\n");
    printf("  2. ��������ʾ����Ĺ���˵����ʹ��˵����\n");
    printf("  3. ������\n");
    printf("  4. �����Ҿ���������ʫ:����ʫ��������Ͷ���������ʫ\n");
    printf("  5. �鿴�ѱ����ʫ:poem������poem_ǰ׺���ļ�\n");
    printf("  6. ����ʫ:��poem�¼���ʫ\n");
    printf("  7. �h��Ԋ\n");
    printf("  8. �˳�\n");
    printf("\033[0m"); // �ָ�Ĭ����ɫ
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
    // ����Ԋ��
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
        // printf("����Ԋ��\n");
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
        printf("\n�Ƿ񱣴��������ԊY/N\n");
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
        // printf("������Ԋ��\n");
        getchar();
        printf("\n�Ƿ񱣴�ԊY/N\n");
        save_poem(poem_head);
    }
}