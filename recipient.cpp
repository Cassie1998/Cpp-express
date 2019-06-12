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
    EXP *e; //新建EXP快件对象结点
    e=head->next;
    if(head==NULL){
        cout << "记录为空" << endl;
    }

    while(e){
        if(e->rphone==phone){ //循环利用if语句找出与输入号码相符的快件，显示取件情况和取件号
            cout<<"------------------------------"<<endl;
            cout<<"取件情况："<<e->status<<"(1-已取件 0-未取件)"<<endl;
            cout<<"取件号："<<e->number<<endl;
            cout<<"------------------------------"<<endl;
            e = e->next;
        }else{
            //指向下一结点
            if(e==NULL) //遍历结束，结点为空，快件不存在
            {
                 cout<<"不存在此快件"<<endl;
            }
            e=e->next;
        }
    }
    return head;
}

void *Recipient::take(EXP *head,int number)
{
    EXP *e; //新建EXP快件对象结点
    e=head->next;
    if(head==NULL){
        cout << "记录为空" << endl;
    }

    while(e){
        if(e->number==number){
            e->status=1;
            cout<<"取件成功"<<endl;
            break;
        }else{
            e = e->next; //指向下一结点
            if(e==NULL) //遍历结束，结点为空，快件不存在
            {
                 cout<<"不存在此快件"<<endl;
            }
        }
    }
    return head;
}

Recipient::~Recipient()
{

}
