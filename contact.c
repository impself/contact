#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable : 6031)
#include "contact.h"
#include<stdio.h>
enum Option
{
	NAME=1,
	SEX,
	AGE,
	TELE,
	ADDR
};
void InitContact(contact* pc)
{
	pc->sz = 0;
	//memset();内存设置，以字节为单位
	memset(pc->data, 0, sizeof(pc->data));
}
void AddContact(contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法添加");
		return;
	}
	//增加一个人的信息
	printf("请输入一个人的名字 :");
	scanf_s("%s", pc->data[pc->sz].name,100);
	printf("请输入性别 :");
	scanf_s("%s", pc->data[pc->sz].sex, 100);
	printf("请输入年龄 :");
	scanf_s("%s", pc->data[pc->sz].age,100);
	printf("请输入电话 :");
	scanf_s("%s", pc->data[pc->sz].tele,100);
	printf("请输入地址 :");
	scanf_s("%s", pc->data[pc->sz].addr,100);

	pc->sz++;
	printf("增加成功！\n");
}
void PrintContact(const contact* pc)
{
	int i = 0;
	//打印标题
	printf("%-10s\t%-5s\t%-5s\t%-12s\t%-15s\n","名字","性别","年龄","电话","地址");
	//打印数据
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5s\t%-5s\t%-12s\t%-15s\n",
			pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].addr);
	}
	printf("\n\n");
}
static int FindByName(contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
	}
	return -1;
}
//删除
void DelContact(contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空，无需删除\n");
		return;
	}
	printf("请输入要删除的人的名字:");
	scanf("%s", name);
	//1.查找有没有需要删除的人
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//2.删除
	else
	{
		for (int i = pos; i < pc->sz-1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("删除成功!\n\n");
	}
}
//查找人的信息
void SearchContact(contact* pc)
{
	printf("请输入要查找的人的姓名:");
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos >= 0)
	{
		printf("找到了！信息如下：\n");
		printf("姓名\t%s\n性别\t%s\n年龄\t%s\n电话\t%s\n住址\t%s\n",
			pc->data[pos].name,
			pc->data[pos].sex,
			pc->data[pos].age,
			pc->data[pos].tele,
			pc->data[pos].addr);
		printf("\n\n\n");
	}
	else
	{
		printf("通讯录不存在该人的信息!\n");
	}
}
void ModifyContact(contact* pc)
{
	char name[MAX_NAME] = {0};
	printf("请输入要修改的人的姓名:");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	else
	{
		int in_put;
		printf("**********************************\n");
		printf("********   1. 姓名  2.性别*********\n");
		printf("********   3. 年龄  4.电话*********\n");
		printf("********       5. 地址    *********\n");
		printf("***********************************\n");
		printf("你想修改哪项信息呢?\n");
		scanf_s("%d", &in_put);
		switch (in_put)
		{
		case NAME:
			printf("请输入名字 :");
			scanf("%s", pc->data[pos].name);
			break;
		case SEX:
			printf("请输入性别 :");
			scanf("%s", pc->data[pos].sex);
			break;
		case AGE:
			printf("请输入年龄 :");
			scanf("%s", pc->data[pos].age);
			break;
		case TELE:
			printf("请输入电话 :");
			scanf("%s", pc->data[pos].tele);
			break;
		case ADDR:
			printf("请输入地址 :");
			scanf("%s", pc->data[pos].addr);
			break;
		}
		printf("修改成功！\n");
	}
}
//将人的信息排序
void SortContact(contact* pc)
{
	PeoInfo t;
	for (int i = 0; i < pc->sz; i++)
	{
		for (int j = 0; j < pc->sz - i - 1; j++)
		{
			//printf("%s %s\n", pc->data[j].name, pc->data[j].name);
			//printf("%d", strcmp(pc->data[j].name, pc->data[j].name));
			if (strcmp(pc->data[j].name, pc->data[j+1].name) > 0)
			{
				t = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = t;
			}
		}
	}
	printf("按名字从小到大排序成功!\n");
}