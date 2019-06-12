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
    Recipient(); //构造函数
    void *search(EXP *head,long long phone); //收件人根据手机号查找快件
    void *take(EXP *head,int number); //取件码
    ~Recipient(); //析构函数
};


#endif // RECIPIENT_H_INCLUDED
