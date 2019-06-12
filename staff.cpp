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
    cout<<"账户:";
    cin>>acc;
    cout<<"密码：";
    cin>>pwd;
    cout<<endl;
    int flag;
    for(int i=0;i<5;i++)	//查找是否存在此用户
    {
        if(!strcmp(acc.c_str(),account[i].c_str())){	//相等时为0，此判断为匹配

            if(!strcmp(pwd.c_str(),password[i].c_str()))		//密码匹配
            {
                cout<<"登陆成功！"<<endl;
                return i;

            }
            else
            {
                cout<<"密码错误"<<endl;
                return -1;

            }

        }
            cout<<"此用户不存在！"<<endl;
                    return -1;

    }

}

EXP *Staff::addexp(EXP *head)
{
    CDate date;
	string today=date.format("DDD");
    ofstream SaveFile(today+".txt",ios::app); //打开以当天日期命名的txt文件进行写入操作
    EXP *e;
    EXP *node=new EXP;

    int randValue;
	srand(time(0));
    randValue=rand(); //产生随机数，作为取件号


    cout<<"情录入新增快件的信息："<<endl;
    cout<<"快递单号：";
    cin>>node->eid;
    cout<<"快递公司：";
    cin>>node->company;
    cout<<"收件人：";
    cin>>node->rname;
    cout<<"收件人联系电话：";
    cin>>node->rphone;
    cout<<"收件人地址：";
    cin>>node->raddress;
    cout<<"收件人邮编：";
    cin>>node->rpcode;
    cout<<"寄件人：";
    cin>>node->sname;
    cout<<"寄件人联系电话：";
    cin>>node->sphone;
    cout<<"寄件人地址：";
    cin>>node->saddress;
    cout<<"寄件人邮编：";
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
    cout << "--成功添加！--" << endl;
	return head;
}

void Staff::showall(EXP *head) //显示所有快件信息
{

    EXP *e;
    e=head->next;
    if(head==NULL){
        cout << "记录为空" << endl;
    }


    while(e){
        cout<<"---------------------------------------"<<endl;
        cout<<"快递单号："<<e->eid<<endl;
        cout<<"快递公司："<<e->company<<endl;
        cout<<"收件人："<<e->rname<<endl;
        cout<<"收件人联系电话："<<e->rphone<<endl;
        cout<<"收件人地址："<<e->raddress<<endl;
        cout<<"收件人邮编："<<e->rpcode<<endl;
        cout<<"寄件人："<<e->sname<<endl;
        cout<<"寄件人联系电话："<<e->sphone<<endl;
        cout<<"寄件人地址："<<e->saddress<<endl;
        cout<<"寄件人邮编："<<e->spcode<<endl;
        cout<<"取件情况(0-未取件 1-已取件)："<<e->status<<endl;
        cout<<"取件号："<<e->number<<endl;
        cout<<"---------------------------------------"<<endl;

        e = e->next;

    }
}

void *Staff::search2(EXP *head,long long phone) //根据手机号查询快件
{

    EXP *e;
    e=head->next;
    if(head==NULL){
        cout<<"记录为空"<<endl;
    }

    while(e){
        if(e->rphone==phone){
            cout<<"--------------------------------------"<<endl;
            cout<<"快递单号："<<e->eid<<endl;
            cout<<"快递公司："<<e->company<<endl;
            cout<<"收件人："<<e->rname<<endl;
            cout<<"收件人联系电话："<<e->rphone<<endl;
            cout<<"收件人地址："<<e->raddress<<endl;
            cout<<"收件人邮编："<<e->rpcode<<endl;
            cout<<"寄件人："<<e->sname<<endl;
            cout<<"寄件人联系电话："<<e->sphone<<endl;
            cout<<"寄件人地址："<<e->saddress<<endl;
            cout<<"寄件人邮编："<<e->spcode<<endl;
            cout<<"取件情况(0-未取件 1-已取件)："<<e->status<<endl;
            cout<<"取件号："<<e->number<<endl;
            cout<<"--------------------------------------"<<endl;
            e->status=1;
            e=e->next;

        }
        else{
            //e=e->next;
            if(e==NULL)
            {
                 cout<<"不存在此快件"<<endl;
            }
            e=e->next;
        }

    }
	return head;
}

void *Staff::search(EXP *head,int number) //根据取件号查询快件
{
    EXP *e;
    e=head->next;
    if(head==NULL){
        cout<<"不存在此快件"<<endl;
    }

    while(e){

        if(e->number==number){
            cout<<"--------------------------------------"<<endl;
            cout<<"快递单号："<<e->eid<<endl;
            cout<<"快递公司："<<e->company<<endl;
            cout<<"收件人："<<e->rname<<endl;
            cout<<"收件人联系电话："<<e->rphone<<endl;
            cout<<"收件人地址："<<e->raddress<<endl;
            cout<<"收件人邮编："<<e->rpcode<<endl;
            cout<<"寄件人："<<e->sname<<endl;
            cout<<"寄件人联系电话："<<e->sphone<<endl;
            cout<<"寄件人地址："<<e->saddress<<endl;
            cout<<"寄件人邮编："<<e->spcode<<endl;
            cout<<"取件情况(0-未取件 1-已取件)："<<e->status<<endl;
            cout<<"取件号："<<e->number<<endl;
            cout<<"--------------------------------------"<<endl;
            e->status=1;
            e=e->next;
        }
        else{
            //e=e->next;
            if(e==NULL)
            {
                 cout<<"不存在此快件"<<endl;
            }
            e=e->next;
        }
    }
	return head;
}

void *Staff::search1(EXP *head,int eid) //根据快递单号查找快件，包含删除、修改功能
{
    EXP *e;
    e=head->next;
    char c;
    int d;
    int flag=1;

    if(head==NULL){

        cout<<"不存在此快件"<<endl;
    }
     while(e){

        if(e->eid==eid){
            cout<<"--------------------------------------"<<endl;
            cout<<"快递单号："<<e->eid<<endl;
            cout<<"快递公司："<<e->company<<endl;
            cout<<"收件人："<<e->rname<<endl;
            cout<<"收件人联系电话："<<e->rphone<<endl;
            cout<<"收件人地址："<<e->raddress<<endl;
            cout<<"收件人邮编："<<e->rpcode<<endl;
            cout<<"寄件人："<<e->sname<<endl;
            cout<<"寄件人联系电话："<<e->sphone<<endl;
            cout<<"寄件人地址："<<e->saddress<<endl;
            cout<<"寄件人邮编："<<e->spcode<<endl;
            cout<<"取件情况(0-未取件 1-已取件)："<<e->status<<endl;
            cout<<"取件号："<<e->number<<endl;
            cout<<"--------------------------------------"<<endl;
            cout<<endl;
            break;
        }
        else{
            e=e->next;
            if(e==NULL)
            {

                 cout<<"不存在此快件"<<endl;
            }
        }
    }
    while(flag){
           cout<<"删除(d)/修改(e)/退出(q):";
            cin>>c;
            switch(c){
            case 'd':
                delexp(head,e->eid);
                break;
            case 'e':
                while(flag){
                        cout<<"1.快递单号"<<endl;
                        cout<<"2.快递公司"<<endl;
                        cout<<"3.收件人"<<endl;
                        cout<<"4.收件人联系电话"<<endl;
                        cout<<"5.收件人地址"<<endl;
                        cout<<"6.收件人邮编"<<endl;
                        cout<<"7.寄件人"<<endl;
                        cout<<"8.寄件人联系电话"<<endl;
                        cout<<"9.寄件人地址"<<endl;
                        cout<<"10.寄件人邮编"<<endl;
                        cout<<"11.取件情况"<<endl;
                        cout<<"12.取件号"<<endl;
                        cout<<"13.返回上一级"<<endl;
                        cout<<"请输入您想要修改的序号：";
                        cin>>d;
                        switch(d){
                        case 1:
                            cout<<"请输入新的快递单号:";
                            cin>>e->eid;
                            break;
                        case 2:
                            cout<<"请输入新的快递公司:";
                            cin>>e->company;
                            break;
                        case 3:
                            cout<<"请输入新的收件人姓名:";
                            cin>>e->rname;
                            break;
                        case 4:
                            cout<<"请输入新的收件人电话号码:";
                            cin>>e->rphone;
                            break;
                        case 5:
                            cout<<"请输入新的收件人地址:";
                            cin>>e->raddress;
                            break;
                        case 6:
                            cout<<"请输入新的收件人邮编:";
                            cin>>e->rpcode;
                            break;
                        case 7:
                            cout<<"请输入新的寄件人姓名:";
                            cin>>e->sname;
                            break;
                        case 8:
                            cout<<"请输入新的寄件人电话号码:";
                            cin>>e->sphone;
                            break;
                        case 9:
                            cout<<"请输入新的寄件人地址:";
                            cin>>e->saddress;
                            break;
                        case 10:
                            cout<<"请输入新的寄件人邮编:";
                            cin>>e->spcode;
                            break;
                        case 11:
                            cout<<"请输入新的取件状态(0-未取件 1-已取件):";
                            cin>>e->status;
                            break;
                        case 12:
                            cout<<"请输入新的取件号:";
                            cin>>e->number;
                            break;
                        case 13:
                            f.writefile(head);
                            flag=0;
                            break;
                        }
                    }
                    cout<<"--修改成功--"<<endl;
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

void Staff::delexp(EXP *head,int a) //删除快件
{
    cout<<"进入"<<endl;
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

    cout<<"成功删除"<<endl;
}

void *Staff::select(EXP *head) //显示所有未取快件
{
    EXP *e;
    e=head->next;
    if(head==NULL){
        cout<<"记录为空"<<endl;
    }
    while(e){

        if(e->status==0){ //0未取 1已取
            cout<<"------------------------------"<<endl;
            cout<<"快递单号："<<e->eid<<endl;
            cout<<"快递公司："<<e->company<<endl;
            cout<<"收件人："<<e->rname<<endl;
            cout<<"收件人联系电话："<<e->rphone<<endl;
            cout<<"收件人地址："<<e->raddress<<endl;
            cout<<"收件人邮编："<<e->rpcode<<endl;
            cout<<"寄件人："<<e->sname<<endl;
            cout<<"寄件人联系电话："<<e->sphone<<endl;
            cout<<"寄件人地址："<<e->saddress<<endl;
            cout<<"寄件人邮编："<<e->spcode<<endl;
            cout<<"取件情况："<<e->status<<endl;
            cout<<"取件号："<<e->number<<endl;
            cout<<"------------------------------"<<endl;
             e=e->next;
        }
        else{
            e=e->next;
            if(e==NULL)
            {
                 cout<<"不存在此快件"<<endl;
            }
        }
    }
	return head;
}
