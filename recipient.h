#ifndef RECIPIENT_H_INCLUDED
#define RECIPIENT_H_INCLUDED
#include<string>
#include "EXP.h"

using namespace std;

class Recipient{
private:
    string name;
    long long phone;
public:
    Recipient(); //���캯��
    void *search(EXP *head,long long phone); //�ռ��˸����ֻ��Ų��ҿ��
    void *take(EXP *head,int number); //ȡ����
    ~Recipient(); //��������
};


#endif // RECIPIENT_H_INCLUDED
