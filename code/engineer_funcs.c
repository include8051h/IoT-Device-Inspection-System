/*********************
 * file name:   engineer_funcs.c
 * desc:    工程师相关功能代码源文件
 * author & create time:    林子钦 2025/9/29
 * author & modi time:  
 ********************/

 /************引用区***********/
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>

 #include "engineer.h"
 #include "tools.h"
 #include "linklist.h"
 #include "engineer_file.h"
 #include "menu.h"
 #include "devise_file.h"


 /**************具体功能实现区****************/
Status engineer_register(char *input_id, pELNod e_head_var)//工程师注册
{
    unsigned int i = 0;

    pELNod q = NULL;

    pELNod temp_num = e_head_var;//用于判断用户输入的工程师编号是否重叠

    q = e_head_var->next;

        if(NULL == q)//如果工程师链表为空
        {
            printf("账号无重叠。\n\n");

            pELNod p = NULL;//用于存储新注册的工程师的信息并与链表建立联系

            p = (pELNod)malloc(sizeof(ELNod));//给临时节点分配空间

            if(NULL == p)//空间分配失败
            {
                printf("工程师注册：临时节点空间分配失败。\n");

                return ERROR;
            }
            strcpy(p->data.id, input_id);//将注册账号存入临时节点，下同

            printf("请输入您的密码\n");

            scanf("%s", p->data.pwd);//将注册密码存入临时节点，下同

            strcpy(p->data.state, "离线");//新注册的工程师账号状态默认为离线，下同

            printf("请输入您的姓名。\n");

            scanf("%s", p->data.name);//将姓名存入临时节点，下同

            printf("请输入您的性别。\n");

            scanf("%s", p->data.sex);//将性别存入临时节点，下同

            while(1)//遍历链表查看新注册的工程师编号是否重叠，下同
            {
                printf("请输入您的编号。\n");

                scanf("%s", p->data.num);

                while(1)
                {
                    temp_num = temp_num->next;

                    if(NULL == temp_num)
                    {
                        break;
                    }
                    else if(0 == strcmp(temp_num->data.num, p->data.num))
                    {
                        break;
                    }
                }

                if(NULL == temp_num)//如果无重叠，下同
                    {
                        printf("此编号无重叠。\n");

                        break;
                    }
                else if(0 == strcmp(temp_num->data.num, p->data.num))//如果重叠，下同
                    {
                        printf("此编号重叠。\n");

                        continue;
                    }
                
            }

            for(i = 0; i < 5; i++)//给新注册工程师维修记录赋空值，避免其输出乱码，下同
            {
                strcpy(p->data.history[i].time,"");

                strcpy(p->data.history[i].place,"");
            }

            if(NULL == e_head_var->next)//如果为空链表，则直接接在头结点后面，下同
            {
                e_head_var->next = p;
            }
            else//否则接在上一节点q后面，下同
            {
                q->next = p;
            }
            

            p->next = NULL;//临时节点的指针域赋值为NULL

            printf("注册成功！\n");

            E_write_file(p->data);//写入文件

            return OK;
        }
        else
        {
            while(0 != strcmp(q->data.id,input_id) && NULL != q->next)//判断新注册的工程师账号是否重叠，并查找本链表最后一个节点
            {
            q = q->next;

            i++;
        }

        if(0 == strcmp(input_id, q->data.id))//如果输入的账号重叠
        {
            printf("您输入的账号已存在，请重新输入。\n");

            system("pause");

            return ERROR;
        }
        else//如果输入的账号无重叠
        {
            printf("账号无重叠。\n\n");

            pELNod p = NULL;//对用于存储新注册的工程师信息的临时节点p进行初始化

            p = (pELNod)malloc(sizeof(ELNod));

            if(NULL == p)
            {
                printf("工程师注册：临时节点空间分配失败。\n");

                return ERROR;
            }
            strcpy(p->data.id, input_id);

            printf("请输入您的密码\n");

            scanf("%s", p->data.pwd);

            strcpy(p->data.state, "离线");

            printf("请输入您的姓名。\n");

            scanf("%s", p->data.name);

            printf("请输入您的性别。\n");

            scanf("%s", p->data.sex);

            while(1)
            {
                printf("请输入您的编号。\n");

                scanf("%s", p->data.num);

                while(1)
                {
                    temp_num = temp_num->next;

                    if(NULL == temp_num)
                    {
                        break;
                    }
                    else if(0 == strcmp(temp_num->data.num, p->data.num))
                    {
                        break;
                    }
                }

                if(NULL == temp_num)
                    {
                        printf("此编号无重叠。\n");

                        break;
                    }
                else if(0 == strcmp(temp_num->data.num, p->data.num))
                    {
                        printf("此编号重叠。\n");

                        continue;
                    }
                
            }

            for(i = 0; i < 5; i++)
            {
                strcpy(p->data.history[i].time,"");

                strcpy(p->data.history[i].place,"");
            }

            if(NULL == e_head_var->next)
            {
                e_head_var->next = p;
            }
            else
            {
                q->next = p;
            }
            

            p->next = NULL;

            printf("注册成功！\n");

            E_write_file(p->data);

            return OK;
        }
        }
        
        
}



Status engineer_login(pELNod head, pDLNod d_head)//工程师登录
{
    pELNod q = head->next;

    char LorE[10] = {0};//用于接收工程师选择注册或登录的选项

    if(NULL == head->next)//如果工程师链表为空
    {
        printf("无工程师账号可登录，请去注册。\n");

        system("pause");

        return ERROR;
    }
    else//如果工程师链表不为空
    {
        while(1)//不断循环，即使登录失败仍然停留在此界面而不会退出
        {
            printf("登录（login）或退出（exit）\n");

            scanf("%s", LorE);

            if( 0 == strcmp(LorE, "login"))//如果工程师选择登录
            {
                
                
                    system("cls");

                    char temp_engineer_id[15];

                    char temp_engineer_pwd[15];

                    printf("请输入工程师账号\n");

                    scanf("%s", temp_engineer_id);

                    printf("请输入工程师密码\n");

                    scanf("%s", temp_engineer_pwd);

                    //对工程师输入的账号和密码进行校验
                    while(q != NULL && !(0 == strcmp(temp_engineer_id, q->data.id) && 0 == strcmp(temp_engineer_pwd, q->data.pwd)))
                    {
                        q = q->next;
                    }

                    if(NULL == q)//如果输入有误
                    {
                        printf("登录失败，账号或密码输入有误。\n");

                        q = head->next;

                        system("pause");

                        continue;
                    }
                    else//如果输入无误
                    {
                        printf("登录成功！\n\n");

                        strcpy(q->data.state, "在线");//一旦工程师登录成功默认将其账号状态设为在线

                        printf("已为您的账号设置为在线状态,您可在退出“工程师操作界面”时选择是否保留“在线”状态。\n\n");

                        system("pause");

                        engineer_opration_menu_show(head, d_head, q->data.num);//进入工程师功能界面
                    }
                
                break;
            }
            else if(0 == strcmp(LorE, "exit"))//如果工程师选择退出
            {
                break;
            }
            else//如果工程师输入非法信息
            {
                printf("请正确输入。\n");
                
                system("pause");

                continue;
            }
        }

        if(0 == strcmp(LorE, "exit"))//如果工程师选择退出
        {
            return ERROR;
        }

    }
}



Status engineer_update_pwd(pELNod head)//工程师修改密码
{   
    char temp_old_pwd[20] = {0};//用于接收工程师输入的旧密码

    pELNod q = head->next;

    Engineer temp_engineer_update_pwd_arr[50] = {0};//用于存储更新之后的工程师链表的数据

    unsigned int i = 0;

    while(1)
    {
        system("cls");

        printf("******************\n");
        printf("*----修改密码----*\n");
        printf("******************\n");

        printf("请输入您的旧密码。\n");//想要修改密码必须输入旧密码

        memset(temp_old_pwd, 0, sizeof(temp_old_pwd));//清空接收旧密码的数组

        scanf("%s", temp_old_pwd);

        while(!(0 == strcmp(temp_old_pwd, q->data.pwd)) && q->next != NULL)//只要输入正确的旧密码或旧密码输入错误就退出循环
        {
            q = q->next;
        }

        if(0 == strcmp(temp_old_pwd, q->data.pwd))//如果输入旧密码正确
        {
            printf("您输入的旧密码正确。\n\n");

            printf("请输入新密码。\n");

            memset(q->data.pwd, 0, sizeof(char));//清空存储在链表中的旧密码

            scanf("%s", q->data.pwd);//写入新密码

            q = head->next;

            i = 0;

            while(NULL != q)//只要没读到链表末尾就一直把链表里的数据赋值给数组
            {
                temp_engineer_update_pwd_arr[i] = q->data;

                q = q->next;

                i++;
            }

            E_write_file_del(temp_engineer_update_pwd_arr, i);//将数组里的数据存入文件

            printf("修改密码成功！\n");

            system("pause");

            return OK;
        }
        else if(NULL == q->next)
        {
            printf("您输入的旧密码错误，是否继续输入？\n");

            scanf("%s", temp_old_pwd);

            if(0 == strcmp("否", temp_old_pwd))
            {
                return ERROR;
            }

            //system("pause");

            continue;
        }
        
        else
        {
            printf("未知错误。\n");
        }
    }
    
}



Status engineer_check_devise_state(pDLNod head)//工程查看设备状态
{
    int i = 1;

    pDLNod p = head->next;

    printf("**********************\n");
    printf("*----检测设备状态----*\n");
    printf("**********************\n\n");

    if(NULL == p)//如果设备链表为空
    {
        printf("无设备可供查找。\n");

        system("pause");
    }
    else
    {
        printf("--------------------------------\n");

    while(NULL != p)//遍历设备链表打印所有设备信息
    {
        printf("第%d个设备的设备号：%s\n", i, p->data.id);
        printf("第%d个设备的状态：%s\n", i, p->data.state);

        printf("--------------------------------\n");

        p = p->next;

        i++;
    }
        system("pause");
    }

}



Status engineer_fix_devise(pDLNod head)//工程师检查和维修设备
{
    pDLNod q = NULL;

    pDLNod p = head->next;

    unsigned int i = 0;

    char in_conti[12] = {0};//用于询问工程师是否继续检查或维修设备

    char temp_fix_id[20] = {0};//用于搜索工程师维修的设备号

    char temp_dev_state[15] = {0};//用于接收工程师输入的新的设备状态

    char temp_fix_time[20] = {0};//用于接收工程师输入的新的维修时间

    char temp_fix_place[15] = {0};//用于接收工程师输入的新的维修地点

    Devise temp_chk_file_arr[50] = {0};//用于接收进行检查操作之后的设备链表信息的数组

    Devise temp_fix_file_arr[50] = {0};//用于接收信息维修操作之后的设备链表信息的数组

    q = head->next;

    if(NULL == q)//如果设备链表为空
    {
        printf("暂无设备可供检查或维修。\n");

        system("pause");

        return ERROR;
    }

    while(1)//如果失败链表不为空，利用循环使其除非输入退出否则一直停留在此界面
    {
        system("cls");

        printf("************************\n");
        printf("*----设备检查与维修----*\n");
        printf("************************\n\n");

        printf("请输入设备号或“退出”\n");

        scanf("%s", temp_fix_id);

        if(0 == strcmp(temp_fix_id, "退出"))//如果工程师输入退出
        {
            break;
        }

        while(NULL != q && (0 != strcmp(temp_fix_id, q->data.id)))//如果输入设备号，则遍历链表进行查询
        {
            q = q->next;
        }

        if(NULL == q)//如果没有找到匹配的设备
        {
            printf("查无此设备。\n\n");

            printf("“是”“否”继续？\n");

            scanf("%s", in_conti);

            if(0 == strcmp(in_conti, "是"))//如果工程师选择继续查询
            {
                continue;
            }
            else//如果工程师选择停止查询
            {
                break;
            }
        }
        else
        {
            if(0 == strcmp(q->data.state, "未知"))//如果查询的设备状态为未知
            {
                while(1)//循环询问工程师所检查的设备状态为什么
                {
                    system("cls");

                    printf("正在检查设备...\n");

                    sleep(3);//每个三秒询问一次

                    printf("该设备状态：“正在检查”、“损坏”、“正常”，请输入。\n");

                    scanf("%s", temp_dev_state);

                    if(0 == strcmp(temp_dev_state, "正在检查"))//如果是正在检查则继续循环
                    {
                        continue;
                    }
                    else
                    {
                        printf("该设备状态：%s\n", temp_dev_state);//工程师输入设备的新状态

                        strcpy(q->data.state, temp_dev_state);//将设备新状态写入链表

                        p = head->next;

                        unsigned int i = 0;

                        while(NULL != p)//将新链表信息写入数组
                        {
                            temp_chk_file_arr[i] = p->data;

                            p = p->next;

                            i++;
                        }

                        D_write_file_del(temp_chk_file_arr, i);//将数组信息写入文件

                        system("pause");

                        break;
                    }
                }
            }
            else if(0 == strcmp(q->data.state, "损坏"))//如果该设备损坏
            {
                while(1)//不断循环维修设备
                {
                    system("cls");

                    printf("正在维修设备...\n");

                    sleep(3);//每隔3秒询问一次设备状态

                    printf("该设备状态：“正在维修”、“损坏”、“正常”，请输入。\n");

                    scanf("%s", temp_dev_state);

                    if(0 == strcmp(temp_dev_state, "正在维修"))//如果正在维修则继续循环
                    {
                        continue;
                    }
                    else//如果确定设备状态，则将新状态写入设备链表中，并让工程师写入本次维修时间和维修地点
                    {
                        printf("该设备状态：%s\n", temp_dev_state);

                        strcpy(q->data.state, temp_dev_state);

                        printf("\n请输入本次维修时间：");

                        scanf("%s", temp_fix_time);

                        printf("\n请输入本次维修地点：");

                        scanf("%s", temp_fix_place);

                        for(i = 0; i <= 5; i++)//查询维修记录是否还有空的位置，有则填入
                        {
                            if(5 == i)
                            {
                                strcpy(q->data.history[1].time, temp_fix_time);

                                strcpy(q->data.history[1].place, temp_fix_place);

                                break;
                            }//如果维修记录被填满，则将新的维修记录覆盖到第一条维修记录上
                            if((0 == strcmp(q->data.history[i].time, "")) && (0 == strcmp(q->data.history[i].place, "")))
                            {
                                strcpy(q->data.history[i].time, temp_fix_time);

                                strcpy(q->data.history[i].place, temp_fix_place);

                                break;
                            }
                        }

                        p = head->next;

                        unsigned int i = 0;

                        while(NULL != p)//遍历链表，将所有链表数据存入数组中
                        {
                            temp_fix_file_arr[i] = p->data;

                            p = p->next;

                            i++;
                        }

                        D_write_file_del(temp_fix_file_arr, i);//再由数组将数据存入文件

                        system("pause");

                        break;
                    }
                }
            }
            else//如果设备正常
            {
                printf("该设备正常无需检查或修复。\n");

                system("pause");

                break;
            }
        }

    }

    return OK;
}