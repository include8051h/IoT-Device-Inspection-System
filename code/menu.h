/*********************************
 * file name:   menu.h
 * desc:    物联网设备巡检管理系统菜单相关功能实现代码源头文件
 * author & create time: 林子钦   2025/09/26
 * author & modi time:  林子钦 2025/9/29
 *******************************/

#ifndef _MENU_H__
#define _MENU_H__



/************引用区*************/
#include "linklist.h"
#include "devise_linklist.h"

/************宏定义区*************/
#define ADMIN 1
#define ENGINEER 2
#define EXIT 3
#define A_ADD 1
#define A_DEL 2
#define A_MODI 3
#define A_LOCATE 4
#define A_SHOW 5
#define A_EXIT 6
#define A_ENGINEER 1
#define A_DEVISE 2
#define A_E_and_D_EXIT 3

/*********************
 * func name:   menu_show
 * args:    无
 * return:  无
 * desc:    展示菜单选项
 * author & create time:    林子钦 2025/9/26
 * author & modi time:  
 ********************/
void menu_show();

/*********************
 * func name:   get_choice
 * args:    无
 * return:  unsigned int
 * desc:    获取用户输入的选项并检测输入的选项是否合法
 * author & create time:    林子钦 2025/9/26
 * author & modi time:  
 ********************/
unsigned int get_choice();

/*********************
 * func name:   A_menu_show
 * args:    无
 * return:  无
 * desc:    展示管理员一级菜单选项
 * author & create time:    林子钦 2025/9/26
 * author & modi time:  林子钦 2025/9/28
 ********************/
void A_menu_show();

/*********************
 * func name:   A_menu_show_E
 * args:    无
 * return:  无
 * desc:    展示管理员管理工程师菜单选项
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  
 ********************/
void A_menu_show_E();

/*********************
 * func name:   A_menu_show_D
 * args:    无
 * return:  无
 * desc:    展示管理员管理设备菜单选项
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  
 ********************/
void A_menu_show_D();

/*********************
 * func name:   A_get_choice
 * args:    无
 * return:  unsigned int
 * desc:    在管理员功能界面获取管理员输入的选项并检测输入的选项是否合法
 * author & create time:    林子钦 2025/9/26
 * author & modi time:  
 ********************/
unsigned int A_get_choice();

/*********************
 * func name:   A_get_choice_two
 * args:    无
 * return:  unsigned int
 * desc:    在管理员管理工程师和设备界面获取管理员输入的选项并检测输入的选项是否合法
 * author & create time:    林子钦 2025/9/26
 * author & modi time:  
 ********************/
unsigned int A_get_choice_two(unsigned int choice);

/*********************
 * func name:   A_modi_menu_show
 * args:    无
 * return:  无
 * desc:    展示管理员修改工程师信息菜单选项
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  
 ********************/
void A_modi_menu_show();

/*********************
 * func name:   A_modi_get_choice
 * args:    无
 * return:  unsigned int
 * desc:    在管理员修改工程师信息界面获取管理员输入的选项并检测输入的选项是否合法
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  
 ********************/
unsigned int A_modi_get_choice();

/*********************
 * func name:   A_main
 * args:    无
 * return:  无
 * desc:    作为所有管理员功能函数的入口
 * author & create time:    林子钦 2025/9/26
 * author & modi time:  林子钦 2025/9/28
 ********************/
void A_main(pELNod *head, pDLNod *d_head);

/*********************
 * func name:   A_modi_D_menu_show
 * args:    无
 * return:  无
 * desc:    展示管理员修改设备信息菜单选项
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  
 ********************/
void A_modi_D_menu_show();

/*********************
 * func name:   A_modi_get_choice
 * args:    无
 * return:  unsigned int
 * desc:    在管理员修改设备信息界面获取管理员输入的选项并检测输入的选项是否合法
 * author & create time:    林子钦 2025/9/28
 * author & modi time:  
 ********************/
unsigned int A_modi_D_get_choice();

/*********************
 * func name:   engineer_RorL
 * args:    pELNod e_head 工程师链表头结点
 *          pDLNod head 设备链表头结点
 * return:  无
 * desc:    用于判断工程师选择注册还是登录
 * author & create time:    林子钦 2025/9/29
 * author & modi time:  
 ********************/
void engineer_RorL(pELNod e_head, pDLNod d_head);

/*********************
 * func name:   engineer_opration_menu_show
 * args:    pELNod head 工程师链表头结点
 *          pDLNod head 设备链表头结点
 *          char num[15] 工程师本人的编号
 * return:  无
 * desc:    提供工程师操作界面以及具体功能的入口
 * author & create time:    林子钦 2025/9/29
 * author & modi time:  
 ********************/
void engineer_opration_menu_show(pELNod head, pDLNod d_head, char num[15]);

#endif