/*********************
 * file name:   link_list.h
 * desc:    链表相关功能代码头文件
 * author & create time:    林子钦---2025/9/26
 * author & modi time:  林子钦 2025/9/29
 ********************/

 #ifndef _LINK_LIST_H__
 #define _LINK_LIST_H__

/************引用区*************/
 #include "tools.h"
#include "engineer.h"


/************宏定义区*************/
#define NAME 1
#define SEX 2
#define ID 3
#define PWD 4
#define A_MODI_EXIT 5

/************声明区*************/
typedef struct ELNod    //工程师链表
{
    Engineer data;  //工程师链表数据域，存储单个工程师的相关信息

    struct ELNod *next; //工程师链表指针域，指向下一个节点的指针
}ELNod, *pELNod;//struct ELNod == ELNod, pELNod == ELNod *

/*********************
 * func name:   E_linklist_init
 * args:    pELNod *head  指向工程师链表头指针的指针
 *          unsigned int toll  工程师链表的表长
 * return:  Status(int)
 * desc:    用于初始化工程师链表
 * author & create time:    林子钦 2025/9/26
 * author & modi time:  林子钦 2025/9/28
 ********************/
Status E_linklist_init(pELNod *head, unsigned int toll);

/*********************
 * func name:   E_linklist_insert
 * args:    pELNod head  指向工程师链表头指针
 *          int pos  表示新的工程师信息要加入到链表中的位置
 * return:  Status(int)
 * desc:    用于管理员添加工程师信息
 * author & create time:    林子钦 2025/9/26
 * author & modi time:  林子钦 2025/9/29
 ********************/
Status E_linklist_insert(pELNod head);

/*********************
 * func name:   E_linklist_del
 * args:    pELNod head  指向工程师链表头指针
 *          char *num     要修改的工程师的编号
 * return:  Status(int)
 * desc:    用于管理员从工程师链表中删除工程师信息
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  林子钦 2025/9/29
 ********************/
Status E_linklist_del(pELNod head, char *num);

/*********************
 * func name:   E_linklist_show
 * args:    pELNod head  指向工程师链表头指针
 * return:  void
 * desc:    用于给显示管理员所有工程师信息
 * author & create time:    林子钦 2025/9/26
 * author & modi time:  
 ********************/
void E_linklist_show(pELNod head);

/*********************
 * func name:   E_linklist_modi
 * args:    pELNod head  指向工程师链表头指针
 *          char *pos     要修改的工程师的编号
 * return:  Status(int)
 * desc:    用于管理员修改工程师信息
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  林子钦 2025/9/29
 ********************/
Status E_linklist_modi(pELNod head, char *pos);

/*********************
 * func name:   E_linklist_locate
 * args:    pELNod head  指向工程师链表头指针
 *          char *num     要修改的工程师的编号
 * return:  Status(int)
 * desc:    用于管理员查询工程师信息
 * author & create time:    林子钦 2025/9/26
 * author & modi time:  
 ********************/
void E_linklsit_locate(pELNod head, char *num);

 #endif