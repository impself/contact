#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "contact.h"
#include<assert.h>

//ͨѶ¼
//1.ͨѶ¼�п��Դ��1000���˵���Ϣ��ÿ������Ϣ�������֣����䣬�Ա𣬵绰����ַ
//2.�����˵���Ϣ
//3.ɾ���˵���Ϣ
//4.�޸��˵���Ϣ
//5.�����˵���Ϣ
//6.������Ϣ
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
	//����ͨѶ¼
	contact con;//ͨѶ¼
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��:");
		
		scanf_s("%d", &in_put);
		assert(in_put >= 0 && in_put <= 6);
		switch (in_put)
		{
		case ADD:
			//�����˵���Ϣ
			AddContact(&con);
			break;
		case DEL:
			//ɾ���˵���Ϣ
			DelContact(&con);
			break;
		case MODIFY:
			//�޸��˵���Ϣ
			ModifyContact(&con);
			break;
		case PRINT:
			//��ӡ�˵���Ϣ
			PrintContact(&con);
			break;
		case SORT:
			//���˵���Ϣ����������
			SortContact(&con);
			break;
		case SEARCH:
			//�����˵���Ϣ
			SearchContact(&con);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("������ѡ��");
		}
	} while (in_put);
	return 0;
}