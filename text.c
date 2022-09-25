#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "contact.h"
#include<assert.h>

//通讯录
//1.通讯录中可以存放1000个人的信息，每个人信息包含名字，年龄，性别，电话，地址
//2.增加人的信息
//3.删除人的信息
//4.修改人的信息
//5.查找人的信息
//6.排序信息
void menu()
{
	printf("***************************************\n");
	printf("********   1. add     2. del***********\n");
	printf("********   3. search  4. modify********\n");
	printf("********   5. sort    6. print*********\n");
	printf("********   0. exit            *********\n");
	printf("***************************************\n");
}
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};
int main()
{
	int in_put = 0;
	//创建通讯录
	contact con;//通讯录
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:");
		
		scanf_s("%d", &in_put);
		assert(in_put >= 0 && in_put <= 6);
		switch (in_put)
		{
		case ADD:
			//增加人的信息
			AddContact(&con);
			break;
		case DEL:
			//删除人的信息
			DelContact(&con);
			break;
		case MODIFY:
			//修改人的信息
			ModifyContact(&con);
			break;
		case PRINT:
			//打印人的信息
			PrintContact(&con);
			break;
		case SORT:
			//将人的信息按姓名排序
			SortContact(&con);
			break;
		case SEARCH:
			//查找人的信息
			SearchContact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("请重新选择！");
		}
	} while (in_put);
	return 0;
}