#pragma once
#pragma warning(disable : 6031)
#include<string.h>
#include<stdio.h>
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX 1000
#define MAX_AGE 5
//类型的定义
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char age[MAX_AGE];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;
//通讯录结构
typedef struct Contact
{
	PeoInfo data[MAX];//存放添加进来人的信息
	int sz;//当前通讯录中有效信息的个数
}contact;

//初始化通讯录
void InitContact(contact* pc);
//增加联系人
void AddContact(contact* pc);
//打印联系人信息
void PrintContact(const contact* pc);
//删除人的信息
void DelContact(contact* pc);
//查找人的信息
void SearchContact(contact* pc);
//修改人的信息
void ModifyContact(contact* pc);
//将人的信息排序
void SortContact(contact* pc);
