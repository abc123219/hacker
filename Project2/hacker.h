#pragma once

#include <iostream>
#define MAXSIZE 4096

//��ָ�����룬ʹ��ʱ���ܵ�������
//#pragma execution_character_set("utf-8")  

//idָ��Ӧ��վ�Ķ˿ں�
// ���������صĽ����utf-8�����ʽ
int hk_404(char *id, char *response);

//�ָ���վ
int hk_restore(char *id, char *response);

//��ҳ�۸Ĺ�����para��ʾ�������
int hk_tamper(char *id, char *para, char *response);

//�鿴������¼
int hk_record(char *id, char *response);

// ��鹥���Ƿ�ɹ�
bool check_response(const char *response);

std::string UTF8ToGBK(const char* strUTF8);
void GBKToUTF8(std::string &strGBK);
