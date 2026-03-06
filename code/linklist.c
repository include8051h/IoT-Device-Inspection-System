/*********************
 * file name:   link_list.c
 * desc:    链表相关功能代码源文件
 * author & create time:    林子钦 2025/9/26
 * author & modi time:  林子钦 2025/9/29
 ********************/

/************引用区*************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "engineer.h"
#include "linklist.h"
#include "menu.h"
#include "engineer_file.h"



/************具体功能实现区*************/
Status E_linklist_init(pELNod *head, unsigned int toll)//工程师链表初始化
{   
    (*head) = (pELNod)malloc(sizeof(ELNod) * toll);//给头结点分配空间

    if(NULL == (*head))//如果空间分配失败
    {
        printf("工程师链表初始化：头结点空间分配失败。\n");

        return ERROR;
    }

    (*head)->next = NULL;//将头结点指针域赋值为空

   return OK;
}



Status E_linklist_insert(pELNod head)//工程师链表添加新工程师
{
    int i = 0;

    pELNod q,p,temp,temp_num;//q表示工程师链表当前最后一个节点，p表示新加入的节点,temp用来检索是否出现重复的账号
    //temp_num用来检测是否有重复的工程师编号

    temp = head;

    temp_num = head;

    p = NULL;

    q = head;

    while( NULL != q->next)//找到该链表的最后一个节点
    {
        q = q->next;
    }

        system("cls");

        p = (pELNod)malloc(sizeof(ELNod));//临时节点空间分配

        if(NULL == p)//临时节点空间分配失败
        {
            printf("工程师链表初始化：临时节点空间分配失败。\n");

            return ERROR;
        }

        printf("请输入您要添加的工程师姓名。\n");

        scanf("%s", p->data.name);

        printf("请输入您要添加的工程师性别。\n");

        scanf("%s", p->data.sex);

            while(1)//利用循环遍历链表，查看输入的新工程师编号是否与已存在的工程师编号重复
            {
                printf("请输入您要添加的工程师编号。\n");

                scanf("%s", p->data.num);

                while(1)
                {
                    temp_num = temp_num->next;

                    if(NULL == temp_num)//查到链表末尾退出循环
                    {
                        break;
                    }
                    else if(0 == strcmp(temp_num->data.num, p->data.num))//在链表中找到重复的工程师编号
                    {
                        break;
                    }
                }

                if(NULL == temp_num)//如果没有找到重复的编号退出循环
                    {
                        printf("此编号无重叠。\n");

                        break;
                    }
                else if(0 == strcmp(temp_num->data.num, p->data.num))//如果找到了重复的编号则重新输入编号
                    {
                        printf("此编号重叠。\n");

                        continue;
                    }
                
            }

        if(NULL == head->next)//如果是一个空链表，则无需判断账号是否重复
        {
            printf("请输入您要添加的工程师账号。\n");

            scanf("%s", p->data.id);
        }
        else//如果不是空链表，则需要对新输入的账号进行重复检测
        {
            while(1)
            {
                printf("请输入您要添加的工程师账号。\n");

                scanf("%s", p->data.id);

                while(1)
                {
                    temp = temp->next;
                    if(temp == NULL)//如果读到链表末尾退出循环
                    {
                        break;
                    }
                    else if(0 == strcmp(temp->data.id, p->data.id))//如果找到重复的账号退出循环
                    {
                        printf("账号重叠，请重新输入。\n");

                        system("pause");

                        break;
                    }
                }

                if(temp == NULL)//如果新输入的账号没有重复就退出循环
                    {
                        break;
                    }
                else if(0 == strcmp(temp->data.id, p->data.id))//如果新输入的账号重复了，则重新输入
                    {
                        continue;
                    }
                
            }
        }
        
        printf("请输入您要添加的工程师密码。\n");

        scanf("%s", p->data.pwd);

        strcpy(p->data.state, "离线");

        for(i = 0; i < 5; i++)//遍历该工程师的维修记录并将其赋值为空，避免打印出乱码
        {
            strcpy(p->data.history[i].time,"");

            strcpy(p->data.history[i].place,"");
        }
        q->next = p;

        q = p;

        q->next = NULL;

    printf("添加成功!\n");

    E_write_file(q->data);//存入文件

    system("pause");

    return OK;
}



Status E_linklist_del(pELNod head, char *num)//工程师链表删除工程师
{
    unsigned int i = 0;

    unsigned int end = 0;//判断链表节点个数

    Engineer temp_E_del_arr[50] = {0};//将进行删除操作后的工程师链表信息存到这个数组里

    pELNod q = NULL;

    q = head->next;

    while(NULL != q)
    {
        q = q->next;

        end++;
    }

    q = head;

    while(NULL != q->next && 0 != strcmp(q->next->data.num, num))//如果读到链表末尾或查找到要删除的工程师编号就退出循环
    {
        q = q->next;

    }

    if(NULL == q)//如果读到链表末尾都没找到要删除的工程师编号，说明这个编号是错的
    {
        printf("您输入的删除编号错误。\n");

        return ERROR;
    }

    if(1 == end)//如果链表只有一个节点
    {
        head->next = NULL;
    }
    else
    {
    q->next = q->next->next;//将删除节点的上一个节点的指针域指向删除节点的下一个节点
    }

    printf("删除成功！\n");

    q = head->next;

    i = 0;

    while(NULL != q)//遍历链表，并将每个节点的数据存入数组中
    {
        temp_E_del_arr[i] = q->data;

        q = q->next;

        i++;
    }

    E_write_file_del(temp_E_del_arr, i);//再由数组将数据存入文件

    return OK;
}



Status E_linklist_modi(pELNod head, char *num)//修改工程师链表中的工程师信息
{
    unsigned int i = 0;

    unsigned int choice;

    pELNod p = head->next;

    char temp_id[20] = {0};

    Engineer temp_E_modi_arr[50] = {0};//将进行修改操作后的链表信息存入这个数组中

    while(1)
    {
        if(NULL == p)//如果读到链表末尾
        {
            printf("未找到该工程师。\n");

            system("pause");

            return ERROR;
        }
        else if(0 == strcmp(num, p->data.num))//如果找到与修改工程师编号相同的编号
        {
            printf("找到该工程师！\n");

            system("pause");

            while (choice != A_MODI_EXIT)
            {
                choice = A_modi_get_choice();//获取工程师输入的修改选项

                switch (choice)
                {
                    case NAME://修改工程师姓名
    
                    printf("请输入姓名\n");

                    scanf("%s", p->data.name);

                    printf("姓名修改完成！\n");

                    system("pause");

                    break;

                case SEX://修改工程师性别
                    
                    printf("请输入性别\n");

                    scanf("%s", p->data.sex);

                    printf("性别修改完成！\n");
                    
                    system("pause");

                    break;
                case ID://修改工程师账号

                while(1)//利用循环，除非修改的账号不重复否则一直修改账号
                {
                    pELNod q = head->next;

                    printf("请输入新账号\n");

                    memset(temp_id, 0, sizeof(temp_id));

                    scanf("%s", temp_id);

                    while(q != NULL && 0 != strcmp(temp_id, q->data.id))
                    {
                        q= q->next;
                    }

                    if(q == NULL)//如果修改的账号不重复
                    {
                        printf("账号修改完成！\n");

                        strcpy(p->data.id, temp_id);
                    
                        system("pause");

                        break;
                    }
                    else if(0 == strcmp(temp_id, q->data.id))//如果修改的账号重复了
                    {
                        printf("修改的账号重复，请重新输入。\n");

                        system("pause");

                        continue;
                    }
                    

                }

                    break;

                case PWD://修改工程师密码

                    printf("请输入密码\n");

                    scanf("%s", p->data.pwd);

                    printf("密码修改完成！\n");
                    
                    system("pause");

                    break;

                case A_MODI_EXIT://退出

                    printf("退出\n");

                    break;

                default://其他输入

                    break;
                }
            }
            system("pause");

            break;

            //return OK;
        }
        p = p->next;//读取下一个链表节点
    }

    p = head->next;

    i = 0;

    while(NULL != p)//遍历链表节点，将每个节点信息存入数组
    {
        temp_E_modi_arr[i] = p->data;

        p = p->next;

        i++;
    }

    E_write_file_del(temp_E_modi_arr, i);//再由数组存入文件

    return OK;
}



void E_linklist_show(pELNod head)//展示所有工程师信息
{
    int i = 1;

    int j = 0;

    pELNod p = head->next;

    while(NULL != p)//遍历工程师链表，将所有工程师信息打印出来
    {
        printf("第%d个工程师的姓名：%s\n", i, p->data.name);
        printf("第%d个工程师的性别：%s\n", i, p->data.sex);
        printf("第%d个工程师的编号：%s\n", i, p->data.num);
        printf("第%d个工程师的账号：%s\n", i, p->data.id);
        printf("第%d个工程师的密码：%s\n", i, p->data.pwd);
        printf("第%d个工程师的状态：%s\n", i, p->data.state);
        while(j < 5)
        {
            printf("第%d个工程师的维修时间：%s\n", i, p->data.history[j].time);

            printf("第%d个工程师的维修地点：%s\n", i, p->data.history[j].place);

            j++;
        }

        p = p->next;

        i++;
        
        j = 0;

        printf("--------------------------------\n");
    }

    system("pause");

}



void E_linklsit_locate(pELNod head, char *num)//搜索工程师
{
    int j = 0;

    pELNod p = head->next;

    if(NULL == p)//如果工程师链表为空
    {
        printf("无工程师信息可供查找。\n");

        system("pause");

        return;
    }

    while(1)//利用循环遍历链表根据工程师编号查找工程师
    {
        if(NULL == p)//读到链表末尾
        {
            printf("查找失败。\n");

            system("pause");

            break;       
        }    
        else if(0 == strcmp(num, p->data.num))//如果找到工程师，将其信息打印出来
        {
            printf("查找成功！\n");

            printf("工程师姓名：%s\n", p->data.name);
            printf("工程师性别：%s\n", p->data.sex);
            printf("工程师编号：%s\n", p->data.num);
            printf("工程师账号：%s\n", p->data.id);
            printf("工程师密码：%s\n", p->data.pwd);
            printf("工程师状态：%s\n", p->data.state);

            while(j < 5)
            {
                printf("工程师的维修时间：%s\n",  p->data.history[j].time);

                printf("工程师的维修地点：%s\n",  p->data.history[j].place);

                j++;

            }
            system("pause");

            break;
        }
        
        p = p->next;//读取下一个链表节点
    }

    return;
}