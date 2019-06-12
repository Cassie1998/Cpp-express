#include <iostream>
#include <fstream>
#include<string.h>
#include "staff.h"
#include "EXP.h"
#include "recipient.h"
#include "Fileop.h"
#include "date.h"

using namespace std;


int main()
{
        int c,n,flag=1;
        int eid,number,Number;
        long long rphone,phone;
        char d,a,h,g;
        Staff s; //Staff类对象实例
        Recipient r; //Recipient类对象实例
        Fileop f; //Fileop类对象实例
        EXP *head; //EXP类对象实例
        head=new EXP; //为结点开辟内存空间
        head->next=NULL;
		EXP *k;
        k = f.readfile(head); //从文件读取数据

        while(flag){
            cout<<endl;
            cout<<"*******************欢迎使用快件管理系统***********************"<<endl;
            cout<<endl;
            cout<<"***                 姓名：武文静                          ***"<<endl;
            cout<<"***                 学号：2016336711089                   ***"<<endl;
            cout<<endl;
            cout<<"*************************************************************"<<endl;
            cout<<"***1.管理员"<<endl;
            cout<<"***2.用户"<<endl;
            cout<<endl;
            cout<<"*************************************************************"<<endl;
            cout<<"\n请输入选择：";
            cin>>c;
            cout<<endl;
            switch(c)
            {
            case 1:
                n=s.login();
                if(n==-1)
				break;
                while(flag)
                {
                    cout<<"************************"<<endl;
                    cout<<"* 1.录入快件信息       *"<<endl;
                    cout<<"* 2.查看已录入快件信息 *"<<endl;
                    cout<<"* 3.查询快件           *"<<endl;
                    cout<<"* 4.查询所有未取快件   *"<<endl;
                    cout<<"* 5.返回主菜单         *"<<endl;
                    cout<<"************************"<<endl;
                    cout<<endl;
                    cout<<"请输入选择：";
                    cin>>d;
                    cout<<endl;
                    switch(d)
                    {
                    case '1':
                        s.addexp(head);
                        break;
                    case '2':
                        s.showall(head);
                        break;
                    case '3':
                        while(flag)
                        {
                            cout<<"**************************"<<endl;
                            cout<<"* 1.使用手机号码进行查找 *"<<endl;
                            cout<<"* 2.使用取件号进行查找   *"<<endl;
                            cout<<"* 3.使用快递单号进行查找 *"<<endl;
                            cout<<"* 4.返回上一级           *"<<endl;
                            cout<<"**************************"<<endl;
                            cout<<"请选择一种方法：";
                            cin>>a;
                            switch(a)
                            {
                            case '1':
                                cout<<"请输入收件人电话号码进行查找：";
                                cin>>rphone;
                                s.search2(head,rphone);
                                cout<<endl;
                                break;
                            case '2':
                                cout<<"请输入取件号进行查找：";
                                cin>>number;
                                s.search(head,number);
                                cout<<endl;
                                break;
                            case '3':
                                cout<<"请输入快递单号进行查找：";
                                cin>>eid;
                                s.search1(head,eid);
                                break;
                            case '4':
                                f.writefile(head);
                                flag=0;
                                break;
                            }
                        }
                        flag=1;
                        break;
                    case '4':
                        cout<<"以下是所有未取快件："<<endl;
                        s.select(head);
                        break;
                    case '5':
                        f.writefile(head);
                        flag=0;
                        break;
                    }
				}
                flag=1;
                break;
            case 2:
                while(flag){
                    cout<<"***************"<<endl;
                    cout<<"* 1.查询快件   *"<<endl;
                    cout<<"* 2.取件       *"<<endl;
                    cout<<"* 3.返回主菜单 *"<<endl;
                    cout<<"***************"<<endl;
                    cout<<"请选择您的操作：";
                    cin>>g;
                    switch(g){
                    case '1':
                        cout<<"请输入电话号码进行查询：";
                        cin>>phone;
                        r.search(head,phone);
                        break;
                    case '2':
                        cout<<"请输入取件码：";
                        cin>>Number;
                        r.take(head,Number);
                        break;
                    case '3':
                        f.writefile(head);
                        flag=0;
                        break;
                    }
                }
                flag=1;
                break;
            default:
                cout<<"请输入1-2！"<<endl;
            }
        }
    return 0;
}
