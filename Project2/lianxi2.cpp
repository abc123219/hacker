//#pragma warning(disable:4996)
#include <stdio.h>//C语言的输出的头文件
#include <iostream>//C++输出头文件，包含C语言的
#include <string>//字符串string的头文件
#include <windows.h>
#include <conio.h>
#include "hacker.h"


//#include <cmath>	//sqrt函数的头文件
//#include "stdio.h"
using namespace std;//使用命名空间std

#define MAX  80
#define MINI 28

void login();//声明iogin函数
void printing();//选项
int choice();//声明功能选择函数
void attack404();
void with();//篡改
void record();//记录
void repair();//修复
void windows();//设置终端窗口大小
void yinPwd();//隐藏密码函数

int main(void)
{
	windows();//设置终端窗口大小

	login();//调用登录login函数

	
	while (1)
	{
		printing();//菜单显示

		int n = choice();//功能选择

		switch (n)
		{
		case 1:
			attack404();//404攻击
			break;
		case 2:
			with();//篡改攻击
			break;
		case 3:
			record();//攻击记录
			break;
		case 4:
			repair();//修复
			break;
		case 5:
			return 0;
		default:
			cout << "输入的选项错误,请按要求输入." << endl;
			break;

		}
	}
	system("pause");

	return 0;
}

//隐藏密码
void yinPwd(char pwd[],int size)
{
	char c;//保存字符
	int i = 0;

	while (1)
	{
		c = _getch();//输入字符不回显

		if (c == '\r')
		{
			pwd[i] = 0;//'\0'结束符
			break;
		}
		pwd[i++] = c;
		cout << '*';

	}
	cout << endl;

}

//登录函数封装
void login(void)
{
	string name;
	char pwd[64];
	while (true)
	{
		system("cls");		//清除窗口
		cout << "请输入用户名:";
		cin >> name;

		cout << "请输入密码:";
		//cin >> pwd;
		yinPwd(pwd,sizeof(pwd));//隐藏密码函数

		//判断用户名和密码是否正确
		if (name =="54hk" &&  strcmp(pwd ,"003a")==0)
		{
			break;
		}
		cout << "用户名或密码错误,请重新输入" << endl;
		//暂停
		system("pause");
	}
}
//居中
void jvzhong(string mag)
{
	//计算出前面要打印的空格数
	int leng = (MAX - mag.length()) / 2;//控制台的宽度-字符串的长度 / 2 等于空格数

	for (int i = 0; i < leng; i++)//空格数
	{
		cout << " ";
	}
	cout << mag << endl;

}

//输出打印函数封装
void printing(void)
{
	string prin[] = {
		"1_网站404攻击",
		"2_网站篡改攻击",
		"3_网站攻击记录",
		"4_网站攻击修复",
		"5_退出"
	};
	//菜单的长度
	int max = 0;
	//字符串的内存个数
	int neicun = sizeof(prin) / sizeof(prin[0]);

	//循环求出最大的字符串的长度
	for (int i = 0; i < neicun; i++)
	{
		//判断出最大的字符串的长度
		if ( (prin[i].length()) > max)
		{
			max = prin[i].length();
		}
	}

	system("cls");

	jvzhong("----黑客攻击系统----");

	//计算出前面要打印的空格数
	int leng = (MAX - max) / 2;//控制台的宽度-字符串的长度 / 2 等于空格数

	for (int i = 0; i < neicun; i++)//行数
	{
		for (int i = 0; i < leng; i++)//空格数
		{
			cout << " ";
		}
		cout << prin[i] << endl;//输出选项
	}
}

//功能选择函数
int choice()
{
	//输入选项
	int n;

	while (1) 
	{
		cout << "请输入选择:";
		cin >> n;
		if (cin.fail())
		{
			cin.clear();//清除错误标志
			cin.sync();//清空输入缓冲区
			cout << "输入失败." << endl;;
			system("puase");
		}
		else 
		{
			break;
		}

	}

	return n;
}

//404攻击
void attack404()
{
	
	//cout << "网站404攻击" << endl;

	
	char id[64];			//攻击的网站id
	char response[4096];	//返回的攻击结果

	system("cls");
	
	cout << "请输入要攻击的id:";
	scanf_s("%s", id, sizeof(id));

	system("cls");

	hk_404(id, response);//调用hk_404函数来攻击

	string ret = UTF8ToGBK(response);//转换编码格式,UTF_8->GBK

	cout << ret << endl;//输出结果
	

	system("pause");
}
//篡改
void with()
{
	//system("cls");
	//cout << "网站篡改攻击" << endl;

	char id[64];
	char response[4096];
	string para;

	system("cls");

	cout << "请输入要攻击的id:";
	cin >> id;

	cout << "输入要修改的内容:";
	cin >> para;

	system("cls");

	GBKToUTF8(para);//将写入的内容转换为UTF_8格式

	//实现篡改攻击
	hk_tamper(id, (char *)para.c_str(), response);//将string类型的字符串转换char*类型

	string ret = UTF8ToGBK(response);//转换编码格式,UTF_8->GBK

	cout << ret << endl;//输出结果

	system("pause");
}
//记录
void record()
{
	//system("cls");
	//cout << "攻击记录" << endl;

	char id[64];
	char response[4096];

	cout << "输入要查看的Id:";
	cin >> id;

	hk_record(id, response);

	string ret = UTF8ToGBK(response);//转换编码格式,UTF_8->GBK

	cout << ret << endl;//输出结果

	system("pause");
}
//修复
void repair()
{
	//system("cls");
	//cout << "网站攻击修复" << endl;

	char id[64];
	char response[4096];//结果

	cout << "输入要查看的Id:";
	cin >> id;

	hk_restore(id, response);

	string ret = UTF8ToGBK(response);//转换编码格式,UTF_8->GBK

	cout << ret << endl;//输出结果


	system("pause");
}

//设置终端窗口大小
void windows(void)
{
	char Size[128];
	sprintf_s(Size, "mode con cols=%d lines=%d", MAX, MINI);
	system(Size);
	
}

