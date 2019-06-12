#ifndef STAFF_H_INCLUDED
#define STAFF_H_INCLUDED
#include<string.h>
#include "EXP.h"
#include "Fileop.h"

using namespace std;

class Staff{

private:
    string account[10];
    string password[10];
    void delexp(EXP *head,int a);
    Fileop f;
public:
    Staff();
    int login();
    //EXP* getexp();
    EXP* addexp(EXP *head);
    void showall(EXP *head);
    void *search2(EXP *head,long long phone);
    void *search(EXP *head,int number);
    void *search1(EXP *head,int eid);
    void *select(EXP *head);

};

#endif // STAFF_H_INCLUDED
