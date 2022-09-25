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
	//memset();�ڴ����ã����ֽ�Ϊ��λ
	memset(pc->data, 0, sizeof(pc->data));
}
void AddContact(contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("ͨѶ¼�������޷����");
		return;
	}
	//����һ���˵���Ϣ
	printf("������һ���˵����� :");
	scanf_s("%s", pc->data[pc->sz].name,100);
	printf("�������Ա� :");
	scanf_s("%s", pc->data[pc->sz].sex, 100);
	printf("���������� :");
	scanf_s("%s", pc->data[pc->sz].age,100);
	printf("������绰 :");
	scanf_s("%s", pc->data[pc->sz].tele,100);
	printf("�������ַ :");
	scanf_s("%s", pc->data[pc->sz].addr,100);

	pc->sz++;
	printf("���ӳɹ���\n");
}
void PrintContact(const contact* pc)
{
	int i = 0;
	//��ӡ����
	printf("%-10s\t%-5s\t%-5s\t%-12s\t%-15s\n","����","�Ա�","����","�绰","��ַ");
	//��ӡ����
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
//ɾ��
void DelContact(contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
		return;
	}
	printf("������Ҫɾ�����˵�����:");
	scanf("%s", name);
	//1.������û����Ҫɾ������
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//2.ɾ��
	else
	{
		for (int i = pos; i < pc->sz-1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("ɾ���ɹ�!\n\n");
	}
}
//�����˵���Ϣ
void SearchContact(contact* pc)
{
	printf("������Ҫ���ҵ��˵�����:");
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos >= 0)
	{
		printf("�ҵ��ˣ���Ϣ���£�\n");
		printf("����\t%s\n�Ա�\t%s\n����\t%s\n�绰\t%s\nסַ\t%s\n",
			pc->data[pos].name,
			pc->data[pos].sex,
			pc->data[pos].age,
			pc->data[pos].tele,
			pc->data[pos].addr);
		printf("\n\n\n");
	}
	else
	{
		printf("ͨѶ¼�����ڸ��˵���Ϣ!\n");
	}
}
void ModifyContact(contact* pc)
{
	char name[MAX_NAME] = {0};
	printf("������Ҫ�޸ĵ��˵�����:");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else
	{
		int in_put;
		printf("**********************************\n");
		printf("********   1. ����  2.�Ա�*********\n");
		printf("********   3. ����  4.�绰*********\n");
		printf("********       5. ��ַ    *********\n");
		printf("***********************************\n");
		printf("�����޸�������Ϣ��?\n");
		scanf_s("%d", &in_put);
		switch (in_put)
		{
		case NAME:
			printf("���������� :");
			scanf("%s", pc->data[pos].name);
			break;
		case SEX:
			printf("�������Ա� :");
			scanf("%s", pc->data[pos].sex);
			break;
		case AGE:
			printf("���������� :");
			scanf("%s", pc->data[pos].age);
			break;
		case TELE:
			printf("������绰 :");
			scanf("%s", pc->data[pos].tele);
			break;
		case ADDR:
			printf("�������ַ :");
			scanf("%s", pc->data[pos].addr);
			break;
		}
		printf("�޸ĳɹ���\n");
	}
}
//���˵���Ϣ����
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
	printf("�����ִ�С��������ɹ�!\n");
}