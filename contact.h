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
//���͵Ķ���
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char age[MAX_AGE];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;
//ͨѶ¼�ṹ
typedef struct Contact
{
	PeoInfo data[MAX];//�����ӽ����˵���Ϣ
	int sz;//��ǰͨѶ¼����Ч��Ϣ�ĸ���
}contact;

//��ʼ��ͨѶ¼
void InitContact(contact* pc);
//������ϵ��
void AddContact(contact* pc);
//��ӡ��ϵ����Ϣ
void PrintContact(const contact* pc);
//ɾ���˵���Ϣ
void DelContact(contact* pc);
//�����˵���Ϣ
void SearchContact(contact* pc);
//�޸��˵���Ϣ
void ModifyContact(contact* pc);
//���˵���Ϣ����
void SortContact(contact* pc);
