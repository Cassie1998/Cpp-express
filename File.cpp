#include <iostream>
#include <fstream>
#include<string>
#include <cstring>
#include <stdlib.h>
# include <windows.h>
#include<conio.h>
#include "staff.h"
#include "EXP.h"
#include "File.h"

EXP *File::readfile(EXP *head)
{
    EXP *node = NULL;
	EXP *p = head;
	ifstream iFile("cpp-home.txt", ios::in | ios::binary);
	//const int LINE_LENGTH = 1000;
	//char str[LINE_LENGTH];
	string str;

	do
	{
		node = new EXP;
		//iFile.getline(str, LINE_LENGTH);
		getline(iFile,str);
		int intStr2 = atoi(str.c_str());
		cout << intStr2 << endl;
		node->eid = intStr2;

		//iFile.getline(str, LINE_LENGTH);
		getline(iFile,str);
		cout << str << endl;
		node->company = str;

		//iFile.getline(str, LINE_LENGTH);
		getline(iFile,str);
		cout << str << endl;
		node->rname = str;

		//iFile.getline(str, LINE_LENGTH);
		getline(iFile,str);
		int intStr1 = atoi(str.c_str());
		cout << intStr1 << endl;
		node->rphone=intStr1;
		//cout<<int(node->rphone)<<endl;

		//iFile.getline(str, LINE_LENGTH);
		getline(iFile,str);
		cout << str << endl;
		node->raddress = str;

		//iFile.getline(str, LINE_LENGTH);
		getline(iFile,str);
		cout << str << endl;
		node->rpcode = str;

		//iFile.getline(str, LINE_LENGTH);
		getline(iFile,str);
		cout << str << endl;
		node->sname =str;

		//iFile.getline(str, LINE_LENGTH);
		getline(iFile,str);
		cout << str << endl;
		node->sphone = str;

		//iFile.getline(str, LINE_LENGTH);
		getline(iFile,str);
		cout << str << endl;
		node->saddress = str;

		//iFile.getline(str, LINE_LENGTH);
		getline(iFile,str);
		cout << str << endl;
		node->spcode = str;

		//iFile.getline(str, LINE_LENGTH);
		getline(iFile,str);
		cout << str << endl;
		node->status = str;


		//iFile.getline(str, LINE_LENGTH);
		getline(iFile,str);
		int intStr = atoi(str.c_str());
		cout << intStr << endl;
		node->number = intStr;


		//iFile.getline(str, LINE_LENGTH);

		p ->next =  node;
		p = node;
		node = node->next;
	} while (!iFile.eof());
	iFile.close();

	return node;
}

EXP *File::writefile(EXP *head)
{
    ofstream SaveFile("cpp-home.txt",ios::app);
    EXP *e;
    EXP *node=new EXP;
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
    cout << "--Ð´Èë³É¹¦£¡--" << endl;
	return head;
}
