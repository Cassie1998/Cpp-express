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
        Staff s; //Staff�����ʵ��
        Recipient r; //Recipient�����ʵ��
        Fileop f; //Fileop�����ʵ��
        EXP *head; //EXP�����ʵ��
        head=new EXP; //Ϊ��㿪���ڴ�ռ�
        head->next=NULL;
		EXP *k;
        k = f.readfile(head); //���ļ���ȡ����

        while(flag){
            cout<<endl;
            cout<<"*******************��ӭʹ�ÿ������ϵͳ***********************"<<endl;
            cout<<endl;
            cout<<"***                 ���������ľ�                          ***"<<endl;
            cout<<"***                 ѧ�ţ�2016336711089                   ***"<<endl;
            cout<<endl;
            cout<<"*************************************************************"<<endl;
            cout<<"***1.����Ա"<<endl;
            cout<<"***2.�û�"<<endl;
            cout<<endl;
            cout<<"*************************************************************"<<endl;
            cout<<"\n������ѡ��";
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
                    cout<<"* 1.¼������Ϣ       *"<<endl;
                    cout<<"* 2.�鿴��¼������Ϣ *"<<endl;
                    cout<<"* 3.��ѯ���           *"<<endl;
                    cout<<"* 4.��ѯ����δȡ���   *"<<endl;
                    cout<<"* 5.�������˵�         *"<<endl;
                    cout<<"************************"<<endl;
                    cout<<endl;
                    cout<<"������ѡ��";
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
                            cout<<"* 1.ʹ���ֻ�������в��� *"<<endl;
                            cout<<"* 2.ʹ��ȡ���Ž��в���   *"<<endl;
                            cout<<"* 3.ʹ�ÿ�ݵ��Ž��в��� *"<<endl;
                            cout<<"* 4.������һ��           *"<<endl;
                            cout<<"**************************"<<endl;
                            cout<<"��ѡ��һ�ַ�����";
                            cin>>a;
                            switch(a)
                            {
                            case '1':
                                cout<<"�������ռ��˵绰������в��ң�";
                                cin>>rphone;
                                s.search2(head,rphone);
                                cout<<endl;
                                break;
                            case '2':
                                cout<<"������ȡ���Ž��в��ң�";
                                cin>>number;
                                s.search(head,number);
                                cout<<endl;
                                break;
                            case '3':
                                cout<<"�������ݵ��Ž��в��ң�";
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
                        cout<<"����������δȡ�����"<<endl;
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
                    cout<<"* 1.��ѯ���   *"<<endl;
                    cout<<"* 2.ȡ��       *"<<endl;
                    cout<<"* 3.�������˵� *"<<endl;
                    cout<<"***************"<<endl;
                    cout<<"��ѡ�����Ĳ�����";
                    cin>>g;
                    switch(g){
                    case '1':
                        cout<<"������绰������в�ѯ��";
                        cin>>phone;
                        r.search(head,phone);
                        break;
                    case '2':
                        cout<<"������ȡ���룺";
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
                cout<<"������1-2��"<<endl;
            }
        }
    return 0;
}
