/*********************
 * file name:   engineer_file.c
 * desc:    将工程师链表中的信息保存到文件中的代码源文件
 * author & create time:    林子钦---2025/9/29
 * author & modi time:  
 ********************/

/************引用区************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "engineer_file.h"
#include "engineer.h"



/*********具体功能实现区*****************/
int E_write_file(Engineer engineer)//以追加方式写入存储工程师信息文件
{
    int count = -1;
    FILE *fp;

    fp = fopen("Engineers", "ab");//以追加方式打开名为Engineers的二进制文件

    if(fp == NULL)//如果文件打开失败
    {
        perror("文件打开失败\n");

        fclose(fp);//关闭文件，下同

        return -1;
    }

    count = fwrite(&engineer, sizeof(Engineer), 1, fp);//将结构体engineer的数据写入Engineers文件，写入一块数据块，每块大小为sizeof（Engineer）
    //返回值为成功写入文件的块数
    if(count == 1)//如果成功写入文件
    {
        printf("保存成功！\n");

        fclose(fp);

        return 1;
    }

    fclose(fp);

    return -1;
}



int E_read_file(pEngineer engineers)//以只读方式从文件中读取数据
{
    int count = 0;//记录读取的数据块数

    int read_size = 0;//判断是否读到文件末尾

    FILE *fp;

    fp = fopen("Engineers", "rb");//以只读方式打开名为Engineers的二进制文件

    if(fp == NULL)//如果文件打开失败
    {
        perror("文件打开失败\n");

        fclose(fp);

        return -1;
    }

    while(1)
    {
        read_size = fread(&engineers[count], sizeof(Engineer), 1, fp);//以只读方式打开Engineers文件，将每块数据块存入engineers数组中，一次读取一块
        //每块大小为sizeof（Engineer）

        if(read_size < 1)//如果读取到文件末尾
        {
            break;
        }

        count++;
    }

    fclose(fp);
    
    return count;
}



int E_write_file_del(pEngineer engineers, unsigned int new_count)//以全覆盖方式写入存储工程师信息文件
{
    int count = -1;//接收成功写入的数据块数
    FILE *fp;

    fp = fopen("Engineers", "wb");//以只读的方式打开文件会清空文件的原有内容

    if(fp == NULL)//如果文件打开失败
    {
        perror("文件打开失败\n");

        fclose(fp);

        return -1;
    }

    count = fwrite(engineers, sizeof(Engineer), new_count, fp);//从数组engineers中取出new_count个数据并存入Engineers文件，每块数据块大小为sizeof（Engineer）

    if(count == 1)//如果成功写入
    {
        printf("保存成功！\n");

        fclose(fp);

        return 1;
    }

    fclose(fp);

    return -1;
}