/*  ��Ŀ���ƣ�����ʫ��
    ��Ŀ���ܣ��������ʫ���J
    ��Ŀ���ߣ�ϯӦ��
    ��Ŀʱ�䣺2024-1-3
    ��Ŀ�汾��v1.0
    */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/file.h"
#include "./include/init.h"
#include "./include/config.h"
#include "./include/util.h"
#include "./include/poem.h"
#include "./include/menu.h"
#include "./cgo/cgo_poem.h"

int main()
{
    srand(time(NULL));
    // ��ʼ���ⲿ�ļ����ڴ�
    Init();
    // �˵�
    Menu();
    // ����
    End_program();

    return 0;
}
