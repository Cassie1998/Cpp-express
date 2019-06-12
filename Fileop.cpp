#include <iostream>
#include <fstream>
#include<string>
#include <cstring>
#include <stdlib.h>
# include <windows.h>
#include<conio.h>
#include<io.h>
#include "staff.h"
#include "EXP.h"
#include "File.h"
#include "date.h"

EXP *Fileop::readfile(EXP *head)
{
    EXP *node = NULL;
	EXP *p = head;
	CDate date;
	ifstream file;
	string today=date.format("DDD");
    file.open(today+".txt",ios::in); //���Ե�������������txt�ļ�
    if(!file){
         ofstream SaveFile(today+".txt",ios::trunc); //���ļ����������½��ļ����Ե�����������
    }
	ifstream iFile(today+".txt", ios::in | ios::binary ); //�Զ����Ʒ�ʽ���ļ�����
	string str;

	do
	{
		node = new EXP;
		getline(iFile,str);
		int intStr2 = atoi(str.c_str()); //�����ļ��������ַ���ת��Ϊint��
		node->eid = intStr2;

		getline(iFile,str);
		node->company = str;

		getline(iFile,str);
		node->rname = str;

		getline(iFile,str);
		//long long str = atoi(str.c_str());
		char* endptr = NULL;
		long long intstr=strtoll(str.c_str(), &endptr, 10);
		node->rphone=intstr;

		getline(iFile,str);
		node->raddress = str;

		getline(iFile,str);
		node->rpcode = str;

		getline(iFile,str);
		node->sname =str;

		getline(iFile,str);
		node->sphone = str;

		getline(iFile,str);
		node->saddress = str;

		getline(iFile,str);
		node->spcode = str;

		getline(iFile,str);
		int intStr3 = atoi(str.c_str());
		node->status = intStr3;

		getline(iFile,str);
		int intStr = atoi(str.c_str());
		node->number = intStr;


		p ->next =  node;
		p = node;
		node = node->next;
	} while (!iFile.eof());
	iFile.close();

	return node;
}

EXP *Fileop::writefile(EXP *head)
{
    CDate date;
	string today=date.format("DDD");
    cout<<"--���ڼ�¼��--"<<endl;
    ofstream SaveFile(today+".txt",ios::trunc);
    EXP *node;
    node=head->next;
    if(head==NULL){
        cout<<"��¼Ϊ��"<<endl;
    }
    while(node){
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
        node=node->next;

    }
    cout << "--д��ɹ���--" << endl;
    SaveFile.close();
	return head;
}
