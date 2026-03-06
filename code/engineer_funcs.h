/*********************
 * file name:   engineer_funcs.h
 * desc:    工程师相关功能代码头文件
 * author & create time:    林子钦 2025/9/29
 * author & modi time:  
 ********************/

#ifndef _ENGINEER_FUNCS_H__
#define _ENGINEER_FUNCS_H__

/************声明区***********/
#include "tools.h"
#include "linklist.h"
#include "engineer.h"

/*********************
 * func name:   engineer_register
 * args:    char *input_id 工程师输入的账号
 *          char *input_pwd 工程师输入的密码
 *          pELNod e_head_var 工程师链表头结点
 * return:  Status(int)
 * desc:    用于工程师注册账号
 * author & create time:    林子钦 2025/9/29
 * author & modi time:  
 ********************/
Status engineer_register(char *input_id, pELNod e_head_var);

/*********************
 * func name:   engineer_login
 * args:    pELNod head 工程师链表头结点
 *          pDLNod d_head 设备链表头结点
 * return:  Status(int)
 * desc:    用于工程师登录账号
 * author & create time:    林子钦 2025/9/29
 * author & modi time:  
 ********************/
Status engineer_login(pELNod head, pDLNod d_head);

/*********************
 * func name:   engineer_update_pwd
 * args:    pELNod head 工程师链表头结点
 * return:  Status(int)
 * desc:    用于工程师修改密码
 * author & create time:    林子钦 2025/9/29
 * author & modi time:  
 ********************/
Status engineer_update_pwd(pELNod head);

/*********************
 * func name:   engineer_check_devise_state
 * args:    pELNod head 工程师链表头结点
 * return:  Status(int)
 * desc:    用于工程师检查设备状态
 * author & create time:    林子钦 2025/9/29
 * author & modi time:  
 ********************/
Status engineer_check_devise_state(pDLNod head);

/*********************
 * func name:   engineer_fix_devise
 * args:    pDLNod head 设备链表头结点
 * return:  Status(int)
 * desc:    用于工程师检查或维修设备
 * author & create time:    林子钦 2025/9/29
 * author & modi time:  
 ********************/
Status engineer_fix_devise(pDLNod head);

#endif