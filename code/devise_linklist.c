/*********************
 * file name:   devise_linklist.c
 * desc:    设备链表相关功能代码源文件
 * author & create time:    林子钦---2025/9/28
 * author & modi time:  
 ********************/

 /************引用区*************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "devise.h"
#include "devise_linklist.h"
#include "menu.h"
#include "tools.h"
#include "devise_file.h"



/************具体功能实现区*************/
Status D_linklist_init(pDLNod *head, unsigned int count)//设备链表初始化
{   
    (*head) = (pDLNod)malloc(sizeof(DLNod) * count);//给头指针分配空间

    if(NULL == (*head))//判断空间分配是否成功
    {
        printf("设备链表初始化：头结点空间分配失败。\n");

        return ERROR;
    }

    (*head)->next = NULL;//将头结点的next指针指向NULL

   return OK;
}



Status D_linklist_insert(pDLNod head)//设备链表添加节点
{
    int i = 0;

    pDLNod q,p,temp_num;//q表示设备链表当前最后一个节点，p表示新加入的节点,temp_num用来检索是否出现重复的设备号

    temp_num = head;//让temp_num指向头结点

    p = NULL;

    q = head;//让q指向头结点

    while( NULL != q->next)//找到当前链表的最后一个节点
    {
        q = q->next;
    }

        system("cls");//清屏

        p = (pDLNod)malloc(sizeof(DLNod));//给新加入的节点分配空间

        if(NULL == p)//判断空间分配是否成功
        {
            printf("设备链表初始化：临时节点空间分配失败。\n");

            return ERROR;
        }

        while(1)
            {
                printf("请输入您要添加的设备号。\n");

                scanf("%s", p->data.id);

                while(1)//遍历链表判断新加的设备号是否重叠
                {
                    temp_num = temp_num->next;

                    if(NULL == temp_num)
                    {
                        break;
                    }
                    else if(0 == strcmp(temp_num->data.id, p->data.id))
                    {
                        break;
                    }
                }

                if(NULL == temp_num)//如果无重叠
                    {
                        printf("此设备号无重叠。\n");

                        break;
                    }
                else if(0 == strcmp(temp_num->data.id, p->data.id))//如果重叠
                    {
                        printf("此设备号重叠。\n");

                        continue;
                    }
                
            }

        strcpy(p->data.state, "未知");//每个设备刚加入时默认状态为未知

        for(i = 0; i < 5; i++)//将设备的5条维修记录全部赋值为空，避免输出时输出乱码
        {
            strcpy(p->data.history[i].time,"");

            strcpy(p->data.history[i].place,"");
        }

        q->next = p;//让q指向p

        q = p;

        q->next = NULL;

        printf("添加成功!\n");

        D_write_file(p->data);//以追加方式存入文件

        system("pause");

        return OK;
}



Status D_linklist_del(pDLNod head, char *id)//设备链表删除节点
{
    unsigned int i = 0;

    pDLNod q = NULL;

    pDLNod p = NULL;

    Devise temp_D_del_arr[50] = {0};//将进行删除操作后的链表信息存入数组以便存入文件

    q = head->next;

    while(NULL != q && 0 != strcmp(q->next->data.id, id))//查询要删除的设备号
    {
        q = q->next;
    }

    if(NULL == q)//如果查无此设备号
    {
        printf("您输入的删除位置错误。\n");

        return ERROR;
    }

    q->next = q->next->next;//将删除节点前一个节点的next指向删除节点下一个节点

    printf("删除成功！\n");

//将进行删除操作后的改动同步到存储在文件中的数据
    p = head->next;

    i = 0;

    while(NULL != p)//先将链表数据转移到数组中
    {
        temp_D_del_arr[i] = p->data;

        p = p->next;

        i++;
    }

    D_write_file_del(temp_D_del_arr, i);//再由数组将数据转移到文件中保存


    return OK;
}



Status D_linklist_modi(pDLNod head, char *num)//设备链表修改节点数据
{
    unsigned int i = 0;

    unsigned int choice = 0;//接收用户是要修改设备的状态还是维修记录的选项

    unsigned int modi_choice = 0;//用于接收用户输入的要修改设备维修记录还是退出的选项

    unsigned int modi_history_choice = 0;//用于接收用户输入的要修改哪条维修记录的选项

    Devise temp_D_modi_arr[50] = {0};//将链表中的数据暂存于数组，以便后面保存到文件中

    char temp_state[15] = {0};//接收用户输入的新的设备状态

    char temp_time[20] = {0};//接收用户输入的新的维修时间

    char temp_place[20] = {0};//接收用户输入的新的维修地点

    pDLNod p = head->next;

    while(1)//根据用户输入的设备号遍历链表，查询用户想要修改的设备
    {
        if(NULL == p)//如果查尽链表也无法找到
        {
            printf("未找到该设备。\n");

            system("pause");

            return ERROR;
        }
        else if(0 == strcmp(num, p->data.id))//找到与用户输入相同的设备号
        {
            printf("找到该设备！\n");

            system("pause");

            while (choice != 3)//除非用户选择退出否则一直循环
            {   
                modi_choice = 0;

                choice = A_modi_D_get_choice();//询问用户要修改设备状态还是设备的维修记录

                switch (choice)
                {
                    case 1://修改设备状态
    
                        printf("请输入设备的新状态\n");

                        scanf("%s", p->data.state);

                        printf("设备状态更新完成！\n");

                        break;

                    case 2://修改设备维修记录或退出

                        while(2 != modi_choice)
                        {
                            system("cls");

                            printf("1.修改设备维修记录\n");
                            printf("2.退出\n");

                            printf("请输入您想要修改的选项。\n");

                            scanf("%d", &modi_choice);
                            
                            if(modi_choice > 2 || modi_choice < 1)//判断用户是否正确输入选项
                            {
                                printf("请输入正确的数字！\n");

                                system("pause");

                                continue;
                            }

                            switch(modi_choice)
                            {
                                case 1://选择修改设备维修记录

                                    while(6 != modi_history_choice)
                                    {
                                        system("cls");

                                        printf("**************************\n");
                                        printf("*----设备维修记录汇总----*\n");
                                        printf("**************************\n");
                        
                                        printf("设备当前状态：%s\n", p->data.state);

                                        i = 0;

                                        while(i <5 )//每个设备有五条维修记录，需要用户输入要修改哪条维修记录
                                        {
                                            printf("---------第%d条维修记录-------------\n", i+1);
                                            
                                            printf("设备维修时间：%s\n", p->data.history[i].time);
                                            printf("设备维修地点：%s\n", p->data.history[i].place);
                                            i++;
                                        }

                                        printf("---------------------------------------\n");

                                        printf("您想要修改第几条维修记录或者输入6以退出？\n");
                                        
                                        scanf("%d", &modi_history_choice);

                                        if(modi_history_choice > 6 || modi_history_choice < 1)//判断用户是否正确输入
                                        {
                                            printf("请输入正确的数字！\n");

                                            system("pause");

                                            continue;
                                        }

                                        switch(modi_history_choice)
                                        {
                                            case 1://修改第一条维修记录，下同

                                            printf("请输入新的设备维修时间。\n");

                                            scanf("%s", temp_time);

                                            //清空接收用户输入的字符数组，下同
                                            memset(p->data.history[modi_history_choice-1].time, 0, sizeof(p->data.history[modi_history_choice-1].time));
                                            //将用户输入维修时间存入链表中，下同
                                            strcpy(p->data.history[modi_history_choice-1].time, temp_time);

                                            printf("设备维修时间更新完成！\n");

                                            printf("请输入新的设备维修地点。\n");

                                            scanf("%s", temp_place);
                                            //清空接收用户输入的字符数组，下同
                                            memset(p->data.history[modi_history_choice-1].place, 0, sizeof(p->data.history[modi_history_choice-1].place));
                                            //将用户输入维修地点存入链表中，下同
                                            strcpy(p->data.history[modi_history_choice-1].place, temp_place);

                                            printf("设备维修地点更新完成！\n");

                                            system("pause");

                                            break;

                                            case 2:

                                            printf("请输入新的设备维修时间。\n");

                                            scanf("%s", temp_time);

                                            memset(p->data.history[modi_history_choice-1].time, 0, sizeof(p->data.history[modi_history_choice-1].time));

                                            strcpy(p->data.history[modi_history_choice-1].time, temp_time);

                                            printf("设备维修时间更新完成！\n");

                                            printf("请输入新的设备维修地点。\n");

                                            scanf("%s", temp_place);

                                            memset(p->data.history[modi_history_choice-1].place, 0, sizeof(p->data.history[modi_history_choice-1].place));

                                            strcpy(p->data.history[modi_history_choice-1].place, temp_place);

                                            printf("设备维修地点更新完成！\n");

                                            system("pause");

                                            break;

                                            case 3:

                                            printf("请输入新的设备维修时间。\n");

                                            scanf("%s", temp_time);

                                            memset(p->data.history[modi_history_choice-1].time, 0, sizeof(p->data.history[modi_history_choice-1].time));

                                            strcpy(p->data.history[modi_history_choice-1].time, temp_time);

                                            printf("设备维修时间更新完成！\n");

                                            printf("请输入新的设备维修地点。\n");

                                            scanf("%s", temp_place);

                                            memset(p->data.history[modi_history_choice-1].place, 0, sizeof(p->data.history[modi_history_choice-1].place));

                                            strcpy(p->data.history[modi_history_choice-1].place, temp_place);

                                            printf("设备维修地点更新完成！\n");

                                            system("pause");

                                            break;

                                            case 4:

                                            printf("请输入新的设备维修时间。\n");

                                            scanf("%s", temp_time);

                                            memset(p->data.history[modi_history_choice-1].time, 0, sizeof(p->data.history[modi_history_choice-1].time));

                                            strcpy(p->data.history[modi_history_choice-1].time, temp_time);

                                            printf("设备维修时间更新完成！\n");

                                            printf("请输入新的设备维修地点。\n");

                                            scanf("%s", temp_place);

                                            memset(p->data.history[modi_history_choice-1].place, 0, sizeof(p->data.history[modi_history_choice-1].place));

                                            strcpy(p->data.history[modi_history_choice-1].place, temp_place);

                                            printf("设备维修地点更新完成！\n");

                                            system("pause");

                                            break;

                                            case 5:

                                           printf("请输入新的设备维修时间。\n");

                                            scanf("%s", temp_time);

                                            memset(p->data.history[modi_history_choice-1].time, 0, sizeof(p->data.history[modi_history_choice-1].time));

                                            strcpy(p->data.history[modi_history_choice-1].time, temp_time);

                                            printf("设备维修时间更新完成！\n");

                                            printf("请输入新的设备维修地点。\n");

                                            scanf("%s", temp_place);

                                            memset(p->data.history[modi_history_choice-1].place, 0, sizeof(p->data.history[modi_history_choice-1].place));

                                            strcpy(p->data.history[modi_history_choice-1].place, temp_place);

                                            printf("设备维修地点更新完成！\n");

                                            system("pause");

                                            break;

                                            case 6:

                                            break;

                                    }
                                    }    
                                    break;
                                case 2:
                                    break;
                            }
                        }

                        break;

                    case 3:

                        break;
                }

                system("pause");

                //return OK;
            }
            break;
        }

        p = p->next;
    }
    
    p = head->next;

    i = 0;

    while(NULL != p)//遍历链表，将所有链表数据存入数组
    {
        temp_D_modi_arr[i] = p->data;

        p = p->next;

        i++;
    }

    D_write_file_del(temp_D_modi_arr, i);//将数组数据存入文件（全覆盖）

    return OK;
}



void D_linklist_show(pDLNod head)//展示所有设备信息
{
    int i = 1;//用于遍历链表

    int j = 0;//用于遍历设备维修记录

    pDLNod p = head->next;

    while(NULL != p)//遍历链表，打印所有设备信息
    {
        printf("第%d个设备的设备号：%s\n", i, p->data.id);
        printf("第%d个设备的状态：%s\n", i, p->data.state);

        while(j < 5)//遍历设备维修记录，将其输出出来
        {
            printf("第%d个设备的维修时间：%s\n", i, p->data.history[j].time);

            printf("第%d个设备的维修地点：%s\n", i, p->data.history[j].place);

            j++;
        }

        p = p->next;

        i++;
        
        j = 0;

        printf("--------------------------------\n");
    }

    system("pause");

}



Status D_linklsit_locate(pDLNod head, char *num)//查询设备信息
{
    int j = 0;

    pDLNod p = head->next;

    if(NULL == p)//如果链表为空
    {
        printf("无设备信息可供查找。\n");

        system("pause");

        return ERROR;
    }

    while(1)//遍历链表查询用户想要查询的设备
    {
        if(NULL == p)//如果查尽链表都没找到
        {
            printf("查找失败。\n");

            system("pause");

            break;       
        }    
        else if(0 == strcmp(num, p->data.id))//找到与用户输入的设备号相同的设备
        {
            printf("查找成功！\n");

            //显示该设备的所有信息

            printf("设备号：%s\n", p->data.id);

            printf("设备状态：%s\n", p->data.state);

            while(j < 5)
            {
                printf("设备的维修时间：%s\n",  p->data.history[j].time);

                printf("设备的维修地点：%s\n",  p->data.history[j].place);

                j++;

            }
            system("pause");

            break;
        }
        
        p = p->next;
    }

    return OK;
}