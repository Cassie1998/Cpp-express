#ifndef EXP_H_INCLUDED
#define EXP_H_INCLUDED
#include<string>

using namespace std;

struct EXP
{
    int eid; //��ݵ���
    string company;//��ݹ�˾
    string rname;//�ռ�������
    long long rphone;//�ռ��˵绰����
    string raddress;//�ռ��˵�ַ
    string rpcode;//�ռ����ʱ�
    string sname;//�ļ�������
    string sphone;//�ļ��˵绰����
    string saddress;//�ļ��˵�ַ
    string spcode;//�ļ����ʱ�
    int number;//ȡ����
    int status;//����״̬
    EXP *next;//next���
};

#endif // EXP_H_INCLUDED
