/*********************
 * file name:   admin.c
 * desc:    管理员相关功能代码源文件
 * author & create time:    林子钦---2025/9/26
 * author & modi time:  
 ********************/

/************引用区*************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "admin.h"
#include "tools.h"
#include "engineer.h"
#include "linklist.h"
#include "menu.h"



/************具体功能实现区*************/
Status admin_login()//管理员登录功能实现函数
{
     while(1)
    {
        system("cls");//清屏

        char temp_admin_id[15];//接收管理员输入的账号

        char temp_admin_pwd[15];//接收管理员输入的密码

        printf("请输入管理员账号\n");

        scanf("%s", temp_admin_id);

        printf("请输入管理员密码\n");

        scanf("%s", temp_admin_pwd);

        if(!(0 == strcmp(temp_admin_id, "admin") && 0 == strcmp(temp_admin_pwd, "123456")))//如果输入的账号和密码不正确
        {
            printf("登录失败，账号或密码输入有误。\n");

            system("pause");

            continue;
        }
        printf("登录成功！\n");

        break;
    }
    system("pause");
}