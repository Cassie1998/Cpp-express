#include <iostream>
#include <fstream>
#include<string>
#include <cstring>
#include <stdlib.h>
# include <windows.h>
#include<conio.h>
#include <iomanip>

#include <time.h>
#include "staff.h"
#include "EXP.h"
#include "Fileop.h"
#include "date.h"

using namespace std;

Staff::Staff()
{
     account[0]="admin";
     password[0]="123";

}

int Staff::login()
{
    string acc,pwd;
    cout<<"�˻�:";
    cin>>acc;
    cout<<"���룺";
    cin>>pwd;
    cout<<endl;
    int flag;
    for(int i=0;i<5;i++)	//�����Ƿ���ڴ��û�
    {
        if(!strcmp(acc.c_str(),account[i].c_str())){	//���ʱΪ0�����ж�Ϊƥ��

            if(!strcmp(pwd.c_str(),password[i].c_str()))		//����ƥ��
            {
                cout<<"��½�ɹ���"<<endl;
                return i;

            }
            else
            {
                cout<<"�������"<<endl;
                return -1;

            }

        }
            cout<<"���û������ڣ�"<<endl;
                    return -1;

    }

}

EXP *Staff::addexp(EXP *head)
{
    CDate date;
	string today=date.format("DDD");
    ofstream SaveFile(today+".txt",ios::app); //���Ե�������������txt�ļ�����д�����
    EXP *e;
    EXP *node=new EXP;

    int randValue;
	srand(time(0));
    randValue=rand(); //�������������Ϊȡ����


    cout<<"��¼�������������Ϣ��"<<endl;
    cout<<"��ݵ��ţ�";
    cin>>node->eid;
    cout<<"��ݹ�˾��";
    cin>>node->company;
    cout<<"�ռ��ˣ�";
    cin>>node->rname;
    cout<<"�ռ�����ϵ�绰��";
    cin>>node->rphone;
    cout<<"�ռ��˵�ַ��";
    cin>>node->raddress;
    cout<<"�ռ����ʱࣺ";
    cin>>node->rpcode;
    cout<<"�ļ��ˣ�";
    cin>>node->sname;
    cout<<"�ļ�����ϵ�绰��";
    cin>>node->sphone;
    cout<<"�ļ��˵�ַ��";
    cin>>node->saddress;
    cout<<"�ļ����ʱࣺ";
    cin>>node->spcode;
    node->status=0;
    node->number=randValue;

    SaveFile << node->eid<<"\n";
    SaveFile << node->company<<"\n";
    SaveFile << node->rname<<"\n";
    SaveFile << node->rphone<<"\n";
    SaveFile << node->raddress<<"\n";
    SaveFile << node->rpcode<<"\n";
    SaveFile << node->sname<<"\n";
    SaveFile << node->sphone<<"\n";
    SaveFile << node->saddress<<"\n";
    SaveFile << node->spcode<<"\n";
    SaveFile << node->status<<"\n";
    SaveFile << node->number<<"\n";
    SaveFile.close();

    if(head){
        e=head;
        while(e->next){
            e=e->next;
        }
        node->next=NULL;
        e->next=node;
	}
	else{
        e=head;
        e->next=node;
        node->next=NULL;
	}
    cout << "--�ɹ���ӣ�--" << endl;
	return head;
}

void Staff::showall(EXP *head) //��ʾ���п����Ϣ
{

    EXP *e;
    e=head->next;
    if(head==NULL){
        cout << "��¼Ϊ��" << endl;
    }


    while(e){
        cout<<"---------------------------------------"<<endl;
        cout<<"��ݵ��ţ�"<<e->eid<<endl;
        cout<<"��ݹ�˾��"<<e->company<<endl;
        cout<<"�ռ��ˣ�"<<e->rname<<endl;
        cout<<"�ռ�����ϵ�绰��"<<e->rphone<<endl;
        cout<<"�ռ��˵�ַ��"<<e->raddress<<endl;
        cout<<"�ռ����ʱࣺ"<<e->rpcode<<endl;
        cout<<"�ļ��ˣ�"<<e->sname<<endl;
        cout<<"�ļ�����ϵ�绰��"<<e->sphone<<endl;
        cout<<"�ļ��˵�ַ��"<<e->saddress<<endl;
        cout<<"�ļ����ʱࣺ"<<e->spcode<<endl;
        cout<<"ȡ�����(0-δȡ�� 1-��ȡ��)��"<<e->status<<endl;
        cout<<"ȡ���ţ�"<<e->number<<endl;
        cout<<"---------------------------------------"<<endl;

        e = e->next;

    }
}

void *Staff::search2(EXP *head,long long phone) //�����ֻ��Ų�ѯ���
{

    EXP *e;
    e=head->next;
    if(head==NULL){
        cout<<"��¼Ϊ��"<<endl;
    }

    while(e){
        if(e->rphone==phone){
            cout<<"--------------------------------------"<<endl;
            cout<<"��ݵ��ţ�"<<e->eid<<endl;
            cout<<"��ݹ�˾��"<<e->company<<endl;
            cout<<"�ռ��ˣ�"<<e->rname<<endl;
            cout<<"�ռ�����ϵ�绰��"<<e->rphone<<endl;
            cout<<"�ռ��˵�ַ��"<<e->raddress<<endl;
            cout<<"�ռ����ʱࣺ"<<e->rpcode<<endl;
            cout<<"�ļ��ˣ�"<<e->sname<<endl;
            cout<<"�ļ�����ϵ�绰��"<<e->sphone<<endl;
            cout<<"�ļ��˵�ַ��"<<e->saddress<<endl;
            cout<<"�ļ����ʱࣺ"<<e->spcode<<endl;
            cout<<"ȡ�����(0-δȡ�� 1-��ȡ��)��"<<e->status<<endl;
            cout<<"ȡ���ţ�"<<e->number<<endl;
            cout<<"--------------------------------------"<<endl;
            e->status=1;
            e=e->next;

        }
        else{
            //e=e->next;
            if(e==NULL)
            {
                 cout<<"�����ڴ˿��"<<endl;
            }
            e=e->next;
        }

    }
	return head;
}

void *Staff::search(EXP *head,int number) //����ȡ���Ų�ѯ���
{
    EXP *e;
    e=head->next;
    if(head==NULL){
        cout<<"�����ڴ˿��"<<endl;
    }

    while(e){

        if(e->number==number){
            cout<<"--------------------------------------"<<endl;
            cout<<"��ݵ��ţ�"<<e->eid<<endl;
            cout<<"��ݹ�˾��"<<e->company<<endl;
            cout<<"�ռ��ˣ�"<<e->rname<<endl;
            cout<<"�ռ�����ϵ�绰��"<<e->rphone<<endl;
            cout<<"�ռ��˵�ַ��"<<e->raddress<<endl;
            cout<<"�ռ����ʱࣺ"<<e->rpcode<<endl;
            cout<<"�ļ��ˣ�"<<e->sname<<endl;
            cout<<"�ļ�����ϵ�绰��"<<e->sphone<<endl;
            cout<<"�ļ��˵�ַ��"<<e->saddress<<endl;
            cout<<"�ļ����ʱࣺ"<<e->spcode<<endl;
            cout<<"ȡ�����(0-δȡ�� 1-��ȡ��)��"<<e->status<<endl;
            cout<<"ȡ���ţ�"<<e->number<<endl;
            cout<<"--------------------------------------"<<endl;
            e->status=1;
            e=e->next;
        }
        else{
            //e=e->next;
            if(e==NULL)
            {
                 cout<<"�����ڴ˿��"<<endl;
            }
            e=e->next;
        }
    }
	return head;
}

void *Staff::search1(EXP *head,int eid) //���ݿ�ݵ��Ų��ҿ��������ɾ�����޸Ĺ���
{
    EXP *e;
    e=head->next;
    char c;
    int d;
    int flag=1;

    if(head==NULL){

        cout<<"�����ڴ˿��"<<endl;
    }
     while(e){

        if(e->eid==eid){
            cout<<"--------------------------------------"<<endl;
            cout<<"��ݵ��ţ�"<<e->eid<<endl;
            cout<<"��ݹ�˾��"<<e->company<<endl;
            cout<<"�ռ��ˣ�"<<e->rname<<endl;
            cout<<"�ռ�����ϵ�绰��"<<e->rphone<<endl;
            cout<<"�ռ��˵�ַ��"<<e->raddress<<endl;
            cout<<"�ռ����ʱࣺ"<<e->rpcode<<endl;
            cout<<"�ļ��ˣ�"<<e->sname<<endl;
            cout<<"�ļ�����ϵ�绰��"<<e->sphone<<endl;
            cout<<"�ļ��˵�ַ��"<<e->saddress<<endl;
            cout<<"�ļ����ʱࣺ"<<e->spcode<<endl;
            cout<<"ȡ�����(0-δȡ�� 1-��ȡ��)��"<<e->status<<endl;
            cout<<"ȡ���ţ�"<<e->number<<endl;
            cout<<"--------------------------------------"<<endl;
            cout<<endl;
            break;
        }
        else{
            e=e->next;
            if(e==NULL)
            {

                 cout<<"�����ڴ˿��"<<endl;
            }
        }
    }
    while(flag){
           cout<<"ɾ��(d)/�޸�(e)/�˳�(q):";
            cin>>c;
            switch(c){
            case 'd':
                delexp(head,e->eid);
                break;
            case 'e':
                while(flag){
                        cout<<"1.��ݵ���"<<endl;
                        cout<<"2.��ݹ�˾"<<endl;
                        cout<<"3.�ռ���"<<endl;
                        cout<<"4.�ռ�����ϵ�绰"<<endl;
                        cout<<"5.�ռ��˵�ַ"<<endl;
                        cout<<"6.�ռ����ʱ�"<<endl;
                        cout<<"7.�ļ���"<<endl;
                        cout<<"8.�ļ�����ϵ�绰"<<endl;
                        cout<<"9.�ļ��˵�ַ"<<endl;
                        cout<<"10.�ļ����ʱ�"<<endl;
                        cout<<"11.ȡ�����"<<endl;
                        cout<<"12.ȡ����"<<endl;
                        cout<<"13.������һ��"<<endl;
                        cout<<"����������Ҫ�޸ĵ���ţ�";
                        cin>>d;
                        switch(d){
                        case 1:
                            cout<<"�������µĿ�ݵ���:";
                            cin>>e->eid;
                            break;
                        case 2:
                            cout<<"�������µĿ�ݹ�˾:";
                            cin>>e->company;
                            break;
                        case 3:
                            cout<<"�������µ��ռ�������:";
                            cin>>e->rname;
                            break;
                        case 4:
                            cout<<"�������µ��ռ��˵绰����:";
                            cin>>e->rphone;
                            break;
                        case 5:
                            cout<<"�������µ��ռ��˵�ַ:";
                            cin>>e->raddress;
                            break;
                        case 6:
                            cout<<"�������µ��ռ����ʱ�:";
                            cin>>e->rpcode;
                            break;
                        case 7:
                            cout<<"�������µļļ�������:";
                            cin>>e->sname;
                            break;
                        case 8:
                            cout<<"�������µļļ��˵绰����:";
                            cin>>e->sphone;
                            break;
                        case 9:
                            cout<<"�������µļļ��˵�ַ:";
                            cin>>e->saddress;
                            break;
                        case 10:
                            cout<<"�������µļļ����ʱ�:";
                            cin>>e->spcode;
                            break;
                        case 11:
                            cout<<"�������µ�ȡ��״̬(0-δȡ�� 1-��ȡ��):";
                            cin>>e->status;
                            break;
                        case 12:
                            cout<<"�������µ�ȡ����:";
                            cin>>e->number;
                            break;
                        case 13:
                            f.writefile(head);
                            flag=0;
                            break;
                        }
                    }
                    cout<<"--�޸ĳɹ�--"<<endl;
                    flag=1;
                    break;
                case 'q':
                    f.writefile(head);
                    flag=0;
                    break;
            }
        }
	return head;
}

void Staff::delexp(EXP *head,int a) //ɾ�����
{
    cout<<"����"<<endl;
    EXP *e,*e1;
    e=e1=head;
    while(e!=NULL){
        if(e->eid==a){
            break;
        }
        else{
            e1=e;
            e=e->next;
        }

    }
    if(e){
        if(e==head){
            head=e->next;
            delete e;
        }else{
            e1->next=e->next;
            delete e;
        }
    }

    cout<<"�ɹ�ɾ��"<<endl;
}

void *Staff::select(EXP *head) //��ʾ����δȡ���
{
    EXP *e;
    e=head->next;
    if(head==NULL){
        cout<<"��¼Ϊ��"<<endl;
    }
    while(e){

        if(e->status==0){ //0δȡ 1��ȡ
            cout<<"------------------------------"<<endl;
            cout<<"��ݵ��ţ�"<<e->eid<<endl;
            cout<<"��ݹ�˾��"<<e->company<<endl;
            cout<<"�ռ��ˣ�"<<e->rname<<endl;
            cout<<"�ռ�����ϵ�绰��"<<e->rphone<<endl;
            cout<<"�ռ��˵�ַ��"<<e->raddress<<endl;
            cout<<"�ռ����ʱࣺ"<<e->rpcode<<endl;
            cout<<"�ļ��ˣ�"<<e->sname<<endl;
            cout<<"�ļ�����ϵ�绰��"<<e->sphone<<endl;
            cout<<"�ļ��˵�ַ��"<<e->saddress<<endl;
            cout<<"�ļ����ʱࣺ"<<e->spcode<<endl;
            cout<<"ȡ�������"<<e->status<<endl;
            cout<<"ȡ���ţ�"<<e->number<<endl;
            cout<<"------------------------------"<<endl;
             e=e->next;
        }
        else{
            e=e->next;
            if(e==NULL)
            {
                 cout<<"�����ڴ˿��"<<endl;
            }
        }
    }
	return head;
}
