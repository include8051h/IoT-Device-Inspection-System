/*********************
 * file name:   devise_linklist.h
 * desc:    设备链表相关功能代码头文件
 * author & create time:    林子钦---2025/9/28
 * author & modi time:  
 ********************/

 #ifndef DEVISE_LINKLIST_H__
 #define DEVISE_LINKLIST_H__
/***********引用区*********/
#include "devise.h"
#include "tools.h"



/**********声明区*********/
 typedef struct DLNod//定义设备链表结构体
 {
    Devise data;//设备链表数据域

    struct DLNod *next;//设备链表指针域
 }DLNod, *pDLNod;//定义别名DLNod等同于struct DLNod，pDLNod等同于struct DLNod *

/*********************
 * func name:   D_linklist_init
 * args:    pDLNod *head 设备链表头指针的指针
 *          unsigned int count设备链表容量
 * return:  Status(int)
 * desc:    用于初始化设备链表
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  
 ********************/
 Status D_linklist_init(pDLNod *head, unsigned int count);

/*********************
 * func name:   D_linklist_insert
 * args:    pDLNod head 设备链表头指针
 * return:  Status(int)
 * desc:    用于添加设备信息
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  
 ********************/
 Status D_linklist_insert(pDLNod head);

/*********************
 * func name:   D_linklist_modi
 * args:    pDLNod head 设备链表头指针
 *          char *num 要修改的设备的设备号
 * return:  Status(int)
 * desc:    用于修改设备信息
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  
 ********************/
Status D_linklist_modi(pDLNod head, char *num);

/*********************
 * func name:   D_linklist_locate
 * args:    pDLNod head 设备链表头指针
 *          char *num 要查找的设备的设备号
 * return:  Status(int)
 * desc:    用于查找设备信息
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  
 ********************/
Status D_linklsit_locate(pDLNod head, char *num);

 /*********************
 * func name:   D_linklist_show
 * args:    pDLNod head 设备链表头指针
 * return:  无
 * desc:    用于向管理员展示所有设备信息
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  
 ********************/
 void D_linklist_show(pDLNod head);

 /*********************
 * func name:   D_linklist_del
 * args:    pDLNod head 设备链表头指针
 *          char *id 要删除的设备的设备号
 * return:  Status(int)
 * desc:    用于删除设备信息
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  
 ********************/
 Status D_linklist_del(pDLNod head, char *id);

 #endif