/*********************
 * file name:   devise_file.h
 * desc:    设备文件相关功能代码头文件
 * author & create time:    林子钦---2025/9/29
 * author & modi time:  
 ********************/

#ifndef _DEVISE_FILE_H__
#define _DEVISE_FILE_H__

/*********引用区*********/
#include "devise.h"

/*********声明区*********/
/*********************
 * func name:   D_write_file
 * args:    Devise devise 设备类型结构体
 * return:  int(写入结构体个数)
 * desc:    将设备链表中的信息存入文件中（在文件中追加新内容）
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  
 ********************/
int D_write_file(Devise devise);

/*********************
 * func name:   D_read_file
 * args:    pDevise devises 设备类型结构体数组
 * return:  int(从文件中读取出的结构体个数)
 * desc:    将文件中的信息存入设备链表中
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  
 ********************/
int D_read_file(pDevise devises);

/*********************
 * func name:   D_write_file_del
 * args:    pDevise devises 设备类型结构体数组
 *          unsigned int new_count 数组中的新个数
 * return:  int
 * desc:    将设备链表的信息存入文件中（更新整个文件）
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  
 ********************/
int D_write_file_del(pDevise devises, unsigned int new_count);

#endif