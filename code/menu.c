/*********************************
 * file name:   menu.c
 * desc:    物联网设备巡检管理系统菜单相关功能实现代码源文件
 * author & create time: 林子钦   2025/09/26
 * author & modi time:  
 *******************************/

 /************引用区*************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "linklist.h"
#include "engineer.h"
#include "tools.h"
#include "engineer_funcs.h"
#include "engineer_file.h"



/************具体功能实现区*************/
void menu_show()//身份选择界面
{
    printf("**************************\n");
    printf("*---物联网设备巡检系统---*\n");
    printf("**************************\n\n");

    printf("1.管理员\n");

    printf("2.工程师\n");

    printf("3.退出\n");

    printf("请输入您的选项：\n");
}



unsigned int get_choice()//在身份选择界面获取用户输入的选项
{
    unsigned int choice = 0;//选项里没有负数，所以使用unsigned char

    while (1)//利用循环，除非输入正确的选项，否则一直输入
    {
        system("cls");

        menu_show();

        scanf("%d", &choice);

        if(choice > 3 || choice < 1)
        {
            printf("请输入正确的选项\n");

            system("pause");

            continue;
        }

       break;
    }

    return choice;//返回选项，下同
}



void A_menu_show()//管理员界面显示
{
    printf("*************************************\n");
    printf("*-------欢迎来到管理员界面！--------*\n");
    printf("*************************************\n");

    printf("1.工程师\n");
    printf("2.设备\n");
    printf("3.退出\n");
}



void A_menu_show_E()//管理员管理工程师功能界面显示
{
    printf("***********************************************\n");
    printf("*-------欢迎来到管理员管理工程师界面！--------*\n");
    printf("***********************************************\n");

    printf("1.添加工程师\n");
    printf("2.删除工程师\n");
    printf("3.修改工程师信息\n");
    printf("4.查找工程师信息\n");
    printf("5.显示所有工程师信息\n");
    printf("6.返回\n");
}



void A_menu_show_D()//管理员管理设备功能界面显示
{
    printf("*********************************************\n");
    printf("*-------欢迎来到管理员管理设备界面！--------*\n");
    printf("*********************************************\n");

    printf("1.添加设备\n");
    printf("2.删除设备\n");
    printf("3.修改设备信息\n");
    printf("4.查找设备信息\n");
    printf("5.显示所有设备信息\n");
    printf("6.返回\n");
}



unsigned int A_get_choice()//接收管理员输入的选项并判断其要选择的功能（管理工程师还是管理设备）
{
    unsigned int choice = 0;//选项里没有负数，所以使用unsigned char

    while (1)
    {
        system("cls");

        A_menu_show();

        scanf("%d", &choice);

        if(choice > 3 || choice < 1)
        {
            printf("请输入正确的选项\n");

            system("pause");

            continue;
        }

       break;
    }

    return choice;
}



unsigned int A_get_choice_two(unsigned int choice)//接收管理员输入的选项并判断其想要进行的操作（增、删、改、查、显示）
{
    //unsigned int choice = 0;//选项里没有负数，所以使用unsigned char

    while (1)//循环判断
    {
        system("cls");

        if(A_ENGINEER == choice)
        {
            A_menu_show_E();//管理工程师功能界面
        }
        else
        {
            A_menu_show_D();//管理设备功能界面
        }
        
        scanf("%d", &choice);

        if(choice > 6 || choice < 1)//非法输入
        {
            printf("请输入正确的选项\n");

            system("pause");

            continue;
        }

       break;
    }

    return choice;
}



void A_main(pELNod *head,pDLNod *d_head)//作为管理员所有功能函数的入口函数
{
    unsigned int choice = 0; //用于接收用户输入的选项

    char num[15] = {0};//用于接收管理员输入的编号

    while (choice != A_E_and_D_EXIT)//循环判断
    {
        choice = A_get_choice();//获取管理员输入的选项并判断

        switch (choice)
        {
            case A_ENGINEER://选择管理工程师

                printf("已进入“工程师”\n");

                while (choice != A_EXIT)//循环判断
                {
                    choice = A_get_choice_two(A_ENGINEER);//获取管理员输入的选项并判断

                    switch (choice)
                {
                    case A_ADD://添加工程师

                        printf("已进入“添加工程师”\n");

                        E_linklist_insert((*head));//添加工程师功能实现函数
                            
                        printf("已退出“添加工程师”\n");

                        system("pause");

                        break;

                    case A_DEL://删除工程师
                            
                        printf("已进入“删除工程师”\n");

                        memset(num, 0, sizeof(num));//清空输入值的存储区

                        printf("请输入您想要删除的工程师的编号。\n");

                        scanf("%s", num);

                        E_linklist_del((*head), num);//删除工程师功能实现函数

                        printf("已退出“删除工程师”\n");

                        system("pause");

                        break;

                    case A_MODI://修改工程师信息

                        printf("已进入“修改工程师”\n");

                        memset(num, 0, sizeof(num));//清空输入值的存储区

                        printf("请输入您想要修改的工程师的编号。\n");

                        scanf("%s", num);

                        E_linklist_modi(*head, num);//修改工程师信息功能实现函数

                        printf("已退出“修改工程师”\n");

                        system("pause");

                        break;

                    case A_LOCATE://查找工程师

                        printf("已进入“查找工程师”\n");

                        memset(num, 0, sizeof(num));//清空输入值的存储区

                        printf("请输入您要查找的工程师编号。\n");

                        scanf("%s", num);

                        E_linklsit_locate((*head), num);//查找工程师功能实现函数

                        printf("已退出“查找工程师”\n");

                        break;

                    case A_SHOW://显示所有工程师信息

                        printf("已进入“显示所有工程师信息”\n");

                        E_linklist_show(*head);//显示所有工程师信息功能实现函数

                        system("cls");

                        printf("已退出“显示所有工程师信息”\n");
                            
                        system("pause");

                        break;

                    case A_EXIT://退出

                        break;
                            
                    default://未知输入

                        break;
                }
                }

                printf("已退出“工程师”\n");

                choice = 0;

                system("pause");

                break;

            case A_DEVISE://管理设备
                    
                printf("已进入“设备”\n");

                while (choice != A_EXIT)//循环判断
                {
                    choice = A_get_choice_two(A_DEVISE);//接收管理员输入并判断是否合法

                    switch (choice)
                    {
                        case A_ADD://添加设备

                        printf("已进入“添加设备”\n");

                        D_linklist_insert(*d_head);//添加设备功能实现函数
                            
                        printf("已退出“添加设备”\n");

                        system("pause");

                        break;

                    case A_DEL://删除设备
                            
                        printf("已进入“删除设备”\n");

                        memset(num, 0, sizeof(num));//清空输入值的存储区

                        printf("请输入您想要删除的设备号。\n");

                        scanf("%s", num);

                        D_linklist_del(*d_head, num);//删除设备功能实现函数

                        printf("已退出“删除设备”\n");

                        system("pause");

                        break;

                    case A_MODI://修改设备信息函数

                        printf("已进入“修改设备信息”\n");

                        memset(num, 0, sizeof(num));//清空输入值的存储区

                        printf("请输入您想要修改的设备的设备号。\n");

                        scanf("%s", num);

                        D_linklist_modi(*d_head, num);//修改设备信息功能实现函数

                        printf("已退出“修改设备信息”\n");

                        system("pause");

                        break;

                    case A_LOCATE://查找设备信息

                        printf("已进入“查找设备信息”\n");

                        memset(num, 0, sizeof(num));//清空输入值的存储区

                        printf("请输入您要查找的设备的设备号。\n");

                        scanf("%s", num);

                        D_linklsit_locate(*d_head, num);//查找设备信息功能实现函数

                        printf("已退出“查找设备信息”\n");

                        break;

                    case A_SHOW://显示所有设备信息

                        printf("已进入“显示所有设备信息”\n");

                        D_linklist_show(*d_head);//显示所有设备信息功能实现函数

                        system("cls");

                        printf("已退出“显示所有设备信息”\n");
                            
                        system("pause");

                        break;

                    case A_EXIT://退出

                        break;
                            
                    default:

                        break;
                }
                }

                printf("已退出“设备”\n");

                choice = 0;

                system("pause");

                break;

            case A_E_and_D_EXIT://退出

                break;
                    
            default:

                break;
            }
    }
}



void A_modi_menu_show()//管理员修改工程师信息菜单显示
{
    printf("*******************************************\n");
    printf("*------请输入您想要修改信息的选项！-------*\n");
    printf("*******************************************\n");

    printf("1.修改工程师姓名\n");
    printf("2.修改工程师性别\n");
    printf("3.修改工程师账号\n");
    printf("4.修改工程师密码\n");
    printf("5.返回\n");
}



unsigned int A_modi_get_choice()//在管理员修改工程师信息菜单界面获取其输入值并判断
{
    unsigned int modi_choice = 0;//选项里没有负数，所以使用unsigned char

    while (1)//循环判断
    {
        system("cls");

        A_modi_menu_show();//菜单显示

        scanf("%d", &modi_choice);

        if(modi_choice > 5 || modi_choice < 1)//判断是否为非法输入
        {
            printf("请输入正确的选项\n");

            system("pause");

            continue;
        }

       break;
    }

    return modi_choice;//返回输入值
}



void A_modi_D_menu_show()//管理员修改设备信息菜单显示
{
    printf("*******************************************\n");
    printf("*------请输入您想要修改信息的选项！-------*\n");
    printf("*******************************************\n");

    printf("1.修改设备状态\n");
    printf("2.修改设备维修历史\n");
    printf("3.返回\n");
}



unsigned int A_modi_D_get_choice()//在管理员修改失败信息菜单界面获取输入值并判断
{
    unsigned int modi_choice = 0;//选项里没有负数，所以使用unsigned char

    while (1)
    {
        system("cls");

        A_modi_D_menu_show();//菜单显示

        scanf("%d", &modi_choice);

        if(modi_choice > 3 || modi_choice < 1)//判断是否非法输入
        {
            printf("请输入正确的选项\n");

            system("pause");

            continue;
        }

       break;
    }

    return modi_choice;//返回选项
}



void engineer_RorL(pELNod e_head, pDLNod d_head)//判断工程师是要注册还是登录
{
    Status i = 0;
    char engineer_input[12] = {0};//接收工程师的选择

    char input_id[20] = {0};//接收工程师输入的账号

    char input_pwd[20] = {0};//接收工程师输入的密码

    while(1)//循环判断
    {
        system("cls");
    
    printf("您想要注册(register)还是登录(login)亦或者退出（exit）？请输入选项。\n");

    scanf("%s", engineer_input);

    if(0 == strcmp(engineer_input, "exit"))//退出
    {
        break;
    }
    else
    {

    while(1)
    {

        if(0 == strcmp(engineer_input, "register"))//注册
        {
            do
            {
                printf("请输入注册账号。\n");

                scanf("%s", input_id);;

                i = engineer_register(input_id, e_head);//注册功能实现函数
            }while(ERROR == i);
            
            break;
        }
        else if(0 == strcmp(engineer_input, "login"))//登录
        {
            engineer_login(e_head, d_head);//登录功能实现函数

            break;
        }
        else//非法输入
        {
            printf("请输入正确的选项！\n");

            system("pause");

            break;
        }
        }
        continue;
    }
}
    return;
}



void engineer_opration_menu_show(pELNod head, pDLNod d_head, char num[15])//工程师功能界面显示
{
    Engineer temp_engineers[50] = {0};

    unsigned int i = 0;
    
    unsigned int choice = 0;//接收工程师输入的选项

    pELNod q = head->next;

    char temp_egnineer_state[15] = {0};//接收工程师输入的设备状态

    while(choice != 4)//循环判断
    {

    system("cls");

    printf("************************\n");
    printf("*----工程师操作界面----*\n");
    printf("************************\n");
    
    printf("1.修改密码\n");
    printf("2.查看设备状态\n");
    printf("3.对设备检查维修\n");
    printf("4.退出\n");

    printf("请输入您的选项：");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1://修改密码

            engineer_update_pwd(head);//修改密码功能实现函数

            break;
        
        case 2://查看设备状态

            engineer_check_devise_state(d_head);//查看设备状态功能实现函数

            break;

        case 3://检查或维修设备

            engineer_fix_devise(d_head);//检查或维修设备功能实现函数

            break;

        case 4://退出

            

            while(0 != strcmp(num, q->data.num))//找到该工程师
            {
                q = q->next;
            }
            printf("请您输入“是”或“否”来决定是否要保留您的“在线”状态以便管理员查询？\n");

            scanf("%s", temp_egnineer_state);

            if(0 == strcmp(temp_egnineer_state, "否"))
            {
                strcpy(q->data.state, "离线");//存入链表
            }

            q = head->next;

            while(q != NULL)//存入数组
            {
                temp_engineers[i] = q->data;

                q = q->next;
                
                i++;
            }

            E_write_file_del(temp_engineers, i);//存入文件


            break;
        
        default://非法输入

            printf("请输入正确的选项。\n");

            break;

    }
    }
}


    