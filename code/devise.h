/*********************
 * file name:   devise.h
 * desc:    设备相关功能代码头文件
 * author & create time:    林子钦---2025/9/28
 * author & modi time:  
 ********************/

#ifndef _DEVISE_H__
#define _DEVISE_H__

/**********声明区*********/
typedef struct Devise_fix_history//定义设备维修记录结构体
{
    char time[20];//维修时间

    char place[15];//维修地点
}Dfh, *pDfh;//定义别名Dfh等同于struct Devise_fix_history，pDfh等同于struct Devise_fix_history *

typedef struct Devise//定义设备结构体
{
    char id[20];//设备号

    char state[15];//设备状态

    Dfh history[5];//设备维修记录
}Devise, *pDevise;//定义别名Devise等同于struct Devise，pDevise等同于struct Devise *

#endif