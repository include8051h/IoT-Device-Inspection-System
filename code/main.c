/*********************
 * file name:   main.c
 * desc:    作为所有功能入口的程序主文件
 * author & create time:    林子钦---2025/9/26
 * author & modi time:  林子钦 2025/9/29
 ********************/

/************引用区*************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "admin.h"
#include "tools.h"
#include "engineer.h"
#include "devise.h"
#include "devise_linklist.h"
#include "devise_file.h"
#include "linklist.h"
#include "engineer_file.h"


/************全局变量区*************/
Admin admin;//定义一个管理员结构体变量

//定义工程师链表头指针的指针
pELNod engineer_head_var = NULL;
pELNod *engineer_head = &engineer_head_var;//赋值语句不能在函数体外进行

//pDLNod *devise_head;//定义设备链表头指针的指针
pDLNod devise_head_var = NULL;
pDLNod *devise_head = &devise_head_var;

unsigned int E_toll = 50;//工程师链表存储容量为50人
unsigned int D_count = 50;//设备链表存储容量为50个
//admin.id = "admin";//id是字符数组，要对其赋值必须通过strcpy
//strcpy(admin.id, "admin");//变量声明可在函数体外进行，但函数调用不能



/************具体功能实现区*************/
/*********************
 * func name:   main
 * args:    无
 * return:  int
 * desc:    作为所有功能入口的主函数
 * author & create time:    林子钦 2025/9/26
 * author & modi time:  林子钦 2025/9/29
 ********************/
int main()
{
    int i = 0;//用于循环次数检测，无实义，下同

    int j = 0;

    unsigned int choice = 0; //用于接收用户输入的选项

    int d_temp_count = 0;//用于记录从文件中读取设备数量

    int e_temp_count = 0;//用于记录从文件中读取工程师数量

    pDLNod d_q = NULL;

    pELNod e_q = NULL;

    E_linklist_init(engineer_head, E_toll);//初始化工程师链表

    D_linklist_init(devise_head, D_count);//初始化设备链表

    d_q = devise_head_var;

    e_q = engineer_head_var;

    Devise temp_devises[50] = {0};//存储从文件中读取出来的设备数据

    Engineer temp_engineers[50] = {0};//存储从文件中读取出来的工程师数据

    FILE *d_fp;

    d_fp = fopen("Devises", "rb");//以只读方式打开Devises文件

    if(d_fp != NULL)//如果该文件存在的话
    {

        d_temp_count = D_read_file(temp_devises);//从文件中读取数据，数据存储到temp_devises数组中，读取的个数赋值给d_temp_count

        for(i = 0; i < d_temp_count; i++)//利用for循环将数组中的数据逐个赋值给链表
        {
            pDLNod d_p = NULL;//定义一临时节点，下同

            d_p = (pDLNod)malloc(sizeof(DLNod));//给临时节点分配空间，下同

            if(NULL == d_p)//如果空间分配失败，下同
            {
                printf("主函数：设备临时节点空间分配失败。\n");

                return ERROR;
            }

            d_p->next = NULL;//临时节点的指针域赋值为空，下同

            d_p->data = temp_devises[i];//将设备数组的数据赋值给链表节点的数据域

            d_q->next = d_p;//将上一节点的指针域指向新加入的临时节点使其与链表建立联系，下同

            d_p->next = NULL;//新节点的指针域赋值为空，因为它是最后一个节点，下同

            d_q = d_p;//将上一节点的指针指向新加入的临时节点，以便循环，下同
        }
    }

    FILE *e_fp;

    e_fp = fopen("Engineers", "rb");//以只读方式打开Engineers文件

    if(e_fp != NULL)
    {
        e_temp_count = E_read_file(temp_engineers);

        for(i = 0; i < e_temp_count; i++)
        {
            pELNod e_p = NULL;

            e_p = (pELNod)malloc(sizeof(ELNod));

            if(NULL == e_p)
            {
                printf("主函数：工程师临时节点空间分配失败。\n");

                return ERROR;
            }

            e_p->next = NULL;

            e_p->data = temp_engineers[i];//将工程师数组中的数据逐个赋值给工程师链表的节点

            e_q->next = e_p;

            e_p->next = NULL;

            e_q = e_p;
        }
    }


    while (choice != EXIT)//除非选择退出否则一直停留在该界面
    {
        choice = get_choice();//获取用户输入的选项

        switch (choice)
        {
            case ADMIN://选择管理员
                

                printf("已进入管理员界面\n");

                admin_login();//管理员登录
                
                A_main(engineer_head, devise_head);//管理员功能界面
                
                printf("已退出管理员界面\n");

                system("pause");

                break;

            case ENGINEER://选择工程师
                
                printf("已进入工程师界面\n\n");

                engineer_RorL(engineer_head_var, devise_head_var);//选择注册还是登录

                printf("已退出工程师界面\n");

                system("pause");

                break;

            case EXIT://退出

                printf("退出\n");

                system("pause");

                break;

            default:

                break;
        }
    }
}
