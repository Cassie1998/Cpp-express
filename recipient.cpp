#include <iostream>
#include<string>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <typeinfo>
#include "recipient.h"
#include "EXP.h"

using namespace std;

Recipient::Recipient()
{
    name="0";
    phone=0;
}

void *Recipient::search(EXP *head,long long phone)
{
    EXP *e; //�½�EXP���������
    e=head->next;
    if(head==NULL){
        cout << "��¼Ϊ��" << endl;
    }

    while(e){
        if(e->rphone==phone){ //ѭ������if����ҳ��������������Ŀ������ʾȡ�������ȡ����
            cout<<"------------------------------"<<endl;
            cout<<"ȡ�������"<<e->status<<"(1-��ȡ�� 0-δȡ��)"<<endl;
            cout<<"ȡ���ţ�"<<e->number<<endl;
            cout<<"------------------------------"<<endl;
            e = e->next;
        }else{
            //ָ����һ���
            if(e==NULL) //�������������Ϊ�գ����������
            {
                 cout<<"�����ڴ˿��"<<endl;
            }
            e=e->next;
        }
    }
    return head;
}

void *Recipient::take(EXP *head,int number)
{
    EXP *e; //�½�EXP���������
    e=head->next;
    if(head==NULL){
        cout << "��¼Ϊ��" << endl;
    }

    while(e){
        if(e->number==number){
            e->status=1;
            cout<<"ȡ���ɹ�"<<endl;
            break;
        }else{
            e = e->next; //ָ����һ���
            if(e==NULL) //�������������Ϊ�գ����������
            {
                 cout<<"�����ڴ˿��"<<endl;
            }
        }
    }
    return head;
}

Recipient::~Recipient()
{

}
