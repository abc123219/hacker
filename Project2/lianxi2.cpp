//#pragma warning(disable:4996)
#include <stdio.h>//C���Ե������ͷ�ļ�
#include <iostream>//C++���ͷ�ļ�������C���Ե�
#include <string>//�ַ���string��ͷ�ļ�
#include <windows.h>
#include <conio.h>
#include "hacker.h"


//#include <cmath>	//sqrt������ͷ�ļ�
//#include "stdio.h"
using namespace std;//ʹ�������ռ�std

#define MAX  80
#define MINI 28

void login();//����iogin����
void printing();//ѡ��
int choice();//��������ѡ����
void attack404();
void with();//�۸�
void record();//��¼
void repair();//�޸�
void windows();//�����ն˴��ڴ�С
void yinPwd();//�������뺯��

int main(void)
{
	windows();//�����ն˴��ڴ�С

	login();//���õ�¼login����

	
	while (1)
	{
		printing();//�˵���ʾ

		int n = choice();//����ѡ��

		switch (n)
		{
		case 1:
			attack404();//404����
			break;
		case 2:
			with();//�۸Ĺ���
			break;
		case 3:
			record();//������¼
			break;
		case 4:
			repair();//�޸�
			break;
		case 5:
			return 0;
		default:
			cout << "�����ѡ�����,�밴Ҫ������." << endl;
			break;

		}
	}
	system("pause");

	return 0;
}

//��������
void yinPwd(char pwd[],int size)
{
	char c;//�����ַ�
	int i = 0;

	while (1)
	{
		c = _getch();//�����ַ�������

		if (c == '\r')
		{
			pwd[i] = 0;//'\0'������
			break;
		}
		pwd[i++] = c;
		cout << '*';

	}
	cout << endl;

}

//��¼������װ
void login(void)
{
	string name;
	char pwd[64];
	while (true)
	{
		system("cls");		//�������
		cout << "�������û���:";
		cin >> name;

		cout << "����������:";
		//cin >> pwd;
		yinPwd(pwd,sizeof(pwd));//�������뺯��

		//�ж��û����������Ƿ���ȷ
		if (name =="54hk" &&  strcmp(pwd ,"003a")==0)
		{
			break;
		}
		cout << "�û������������,����������" << endl;
		//��ͣ
		system("pause");
	}
}
//����
void jvzhong(string mag)
{
	//�����ǰ��Ҫ��ӡ�Ŀո���
	int leng = (MAX - mag.length()) / 2;//����̨�Ŀ��-�ַ����ĳ��� / 2 ���ڿո���

	for (int i = 0; i < leng; i++)//�ո���
	{
		cout << " ";
	}
	cout << mag << endl;

}

//�����ӡ������װ
void printing(void)
{
	string prin[] = {
		"1_��վ404����",
		"2_��վ�۸Ĺ���",
		"3_��վ������¼",
		"4_��վ�����޸�",
		"5_�˳�"
	};
	//�˵��ĳ���
	int max = 0;
	//�ַ������ڴ����
	int neicun = sizeof(prin) / sizeof(prin[0]);

	//ѭ����������ַ����ĳ���
	for (int i = 0; i < neicun; i++)
	{
		//�жϳ������ַ����ĳ���
		if ( (prin[i].length()) > max)
		{
			max = prin[i].length();
		}
	}

	system("cls");

	jvzhong("----�ڿ͹���ϵͳ----");

	//�����ǰ��Ҫ��ӡ�Ŀո���
	int leng = (MAX - max) / 2;//����̨�Ŀ��-�ַ����ĳ��� / 2 ���ڿո���

	for (int i = 0; i < neicun; i++)//����
	{
		for (int i = 0; i < leng; i++)//�ո���
		{
			cout << " ";
		}
		cout << prin[i] << endl;//���ѡ��
	}
}

//����ѡ����
int choice()
{
	//����ѡ��
	int n;

	while (1) 
	{
		cout << "������ѡ��:";
		cin >> n;
		if (cin.fail())
		{
			cin.clear();//��������־
			cin.sync();//������뻺����
			cout << "����ʧ��." << endl;;
			system("puase");
		}
		else 
		{
			break;
		}

	}

	return n;
}

//404����
void attack404()
{
	
	//cout << "��վ404����" << endl;

	
	char id[64];			//��������վid
	char response[4096];	//���صĹ������

	system("cls");
	
	cout << "������Ҫ������id:";
	scanf_s("%s", id, sizeof(id));

	system("cls");

	hk_404(id, response);//����hk_404����������

	string ret = UTF8ToGBK(response);//ת�������ʽ,UTF_8->GBK

	cout << ret << endl;//������
	

	system("pause");
}
//�۸�
void with()
{
	//system("cls");
	//cout << "��վ�۸Ĺ���" << endl;

	char id[64];
	char response[4096];
	string para;

	system("cls");

	cout << "������Ҫ������id:";
	cin >> id;

	cout << "����Ҫ�޸ĵ�����:";
	cin >> para;

	system("cls");

	GBKToUTF8(para);//��д�������ת��ΪUTF_8��ʽ

	//ʵ�ִ۸Ĺ���
	hk_tamper(id, (char *)para.c_str(), response);//��string���͵��ַ���ת��char*����

	string ret = UTF8ToGBK(response);//ת�������ʽ,UTF_8->GBK

	cout << ret << endl;//������

	system("pause");
}
//��¼
void record()
{
	//system("cls");
	//cout << "������¼" << endl;

	char id[64];
	char response[4096];

	cout << "����Ҫ�鿴��Id:";
	cin >> id;

	hk_record(id, response);

	string ret = UTF8ToGBK(response);//ת�������ʽ,UTF_8->GBK

	cout << ret << endl;//������

	system("pause");
}
//�޸�
void repair()
{
	//system("cls");
	//cout << "��վ�����޸�" << endl;

	char id[64];
	char response[4096];//���

	cout << "����Ҫ�鿴��Id:";
	cin >> id;

	hk_restore(id, response);

	string ret = UTF8ToGBK(response);//ת�������ʽ,UTF_8->GBK

	cout << ret << endl;//������


	system("pause");
}

//�����ն˴��ڴ�С
void windows(void)
{
	char Size[128];
	sprintf_s(Size, "mode con cols=%d lines=%d", MAX, MINI);
	system(Size);
	
}

