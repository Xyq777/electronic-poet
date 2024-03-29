/*  项目名称：电子诗人
    项目功能：随机生成诗句銳
    项目作者：席应情
    项目时间：2024-1-3
    项目版本：v1.0
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
    // 初始化外部文件到内存
    Init();
    // 菜单
    Menu();
    // 结束
    End_program();

    return 0;
}
