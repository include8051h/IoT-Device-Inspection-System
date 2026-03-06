/*********************
 * file name:   engineer.h
 * desc:    工程师相关功能代码头文件
 * author & create time:    林子钦 2025/9/26
 * author & modi time:  林子钦 2025/9/29
 ********************/

 #ifndef _ENGINEER_H__
 #define _ENGINEER_H__

/**************引用区************/
#include "tools.h"
//#include "linklist.h"

/************声明区*************/
struct pELNod;//工程师链表结构体前向声明

typedef struct fix_history//设备维修记录结构体
{
    char time[10];//维修时间

    char place[10];//维修地点
}fix_history, *pfix_history;//fix_history等同于struct fix_history,pfix_history等同于struct fix_history*

typedef struct Engineer//工程师结构体
{
    char name[30];//工程师姓名

    char num[15];//工程师编号

    char sex[5];//工程师性别

    char id[20];//工程师账号

    char pwd[20];//工程师密码

    char state[15];//工程师状态

    fix_history history[5];//工程师维修设备记录
}Engineer, *pEngineer;//Engineer等同于struct Engineer,pEngineer等同于struct Engineer *

 #endif