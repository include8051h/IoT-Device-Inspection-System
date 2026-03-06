/*********************
 * file name:   engineer_file.h
 * desc:    将工程师链表中的信息保存到文件中的代码头文件
 * author & create time:    林子钦---2025/9/29
 * author & modi time:  
 ********************/

#ifndef _ENGINEER_FILE_H__
#define _ENGINEER_FILE_H__

/*********引用区*********/
#include "engineer.h"

/*********声明区*********/
/*********************
 * func name:   E_write_file
 * args:    Engineer engineer 工程师类型结构体
 * return:  int(写入结构体个数)
 * desc:    将工程师链表中的信息存入文件中（在文件中追加新内容）
 * author & create time:    林子钦 2025/9/29
 * author & modi time:  
 ********************/
int E_write_file(Engineer engineer);

/*********************
 * func name:   E_read_file
 * args:    pEngineer engineers 工程师类型结构体数组
 * return:  int(从文件中读取出的结构体个数)
 * desc:    将文件中的信息存入工程师链表中
 * author & create time:    林子钦 2025/9/29
 * author & modi time:  
 ********************/
int E_read_file(pEngineer engineers);

/*********************
 * func name:   E_write_file_del
 * args:    pEngineer engineers 工程师类型结构体数组
 *          unsigned int new_count 数组中的新个数
 * return:  int
 * desc:    将工程师链表的信息存入文件中（更新整个文件）
 * author & create time:    林子钦 2025/9/29
 * author & modi time:  
 ********************/
int E_write_file_del(pEngineer engineers, unsigned int new_count);

#endif