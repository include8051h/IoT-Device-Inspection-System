/*********************
 * file name:   devise_file.c
 * desc:    将设备链表中的信息保存到文件中的代码源文件
 * author & create time:    林子钦---2025/9/28
 * author & modi time:  
 ********************/

/************引用区************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "devise_file.h"
#include "devise.h"



/*********具体功能实现区*****************/
int D_write_file(Devise devise)//以追加方式写入存储设备信息文件
{
    int count = -1;
    FILE *fp;

    fp = fopen("Devises", "ab");//打开Devises二进制文件，将新内容加入到文件末尾

    if(fp == NULL)//如果文件打开失败
    {
        perror("文件打开失败\n");

        fclose(fp);//关闭文件

        return -1;
    }

    count = fwrite(&devise, sizeof(Devise), 1, fp);//将设备结构体变量devise写入到Devises文件中，写入1块，每块大小为sizeof（Devise）

    //count为fwrite函数返回的成功写入的块数

    if(count == 1)//如果写入成功
    {
        printf("保存成功！\n");

        fclose(fp);

        return 1;
    }

    fclose(fp);

    return -1;
}



int D_read_file(pDevise devises)//从设备信息存储文件中读取数据
{
    int count = 0;

    int read_size = 0;//用来判断是否读到文件末尾

    FILE *fp;

    fp = fopen("Devises", "rb");//以只读的方式打开Devises文件

    if(fp == NULL)
    {
        perror("文件打开失败\n");

        fclose(fp);

        return -1;
    }

    while(1)
    {
        read_size = fread(&devises[count], sizeof(Devise), 1, fp);//从Devises文件中读取数据块，每次读取一块
        //每块大小为sizeof（Devise），存储到数组devises中

        if(read_size < 1)//如果读取到文件末尾
        {
            break;
        }

        count++;
    }

    fclose(fp);
    
    return count;
}



int D_write_file_del(pDevise devises, unsigned int new_count)//以全覆盖方式写入存储设备信息文件
{
    int count = -1;
    FILE *fp;

    fp = fopen("Devises", "wb");//以只写的方式打开文件会清空文件的原有内容

    if(fp == NULL)
    {
        perror("文件打开失败\n");

        fclose(fp);

        return -1;
    }

    count = fwrite(devises, sizeof(Devise), new_count, fp);//打开Devises文件，从数组devises中取出数据，存入new_count块，每块大小为sizeof(Devise)
    //返回成功写入的块数

    if(count == 1)//如果写入成功
    {
        printf("保存成功！\n");

        fclose(fp);

        return 1;
    }

    fclose(fp);

    return -1;
}