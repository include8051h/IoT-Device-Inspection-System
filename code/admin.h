/*********************
 * file name:   admin.h
 * desc:    管理员相关功能代码头文件
 * author & create time:    林子钦---2025/9/26
 * author & modi time:  
 ********************/

 #ifndef _ADMIN_H__
 #define _ADMIN_H__

 /************引用区*************/
#include "tools.h"



/************声明区*************/
typedef struct Admin//管理员结构体
{
    char id[15];//管理员的账号属性

    char pwd[15];//管理员的密码属性
}Admin, *pAdmin;//定义别名Admin等同于struct Admin，pAdmin等同于struct Admin *

/*********************
 * func name:   admin_login
 * args:    无
 * return:  Status(int)
 * desc:    用于检测输入的账号和密码正确与否
 * author & create time:    林子钦 2025/9/26
 * author & modi time:  
 ********************/
Status admin_login();

#endif
