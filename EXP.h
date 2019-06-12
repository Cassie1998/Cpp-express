#ifndef EXP_H_INCLUDED
#define EXP_H_INCLUDED
#include<string>

using namespace std;

struct EXP
{
    int eid; //快递单号
    string company;//快递公司
    string rname;//收件人姓名
    long long rphone;//收件人电话号码
    string raddress;//收件人地址
    string rpcode;//收件人邮编
    string sname;//寄件人姓名
    string sphone;//寄件人电话号码
    string saddress;//寄件人地址
    string spcode;//寄件人邮编
    int number;//取件号
    int status;//区间状态
    EXP *next;//next结点
};

#endif // EXP_H_INCLUDED
