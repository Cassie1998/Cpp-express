#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include "EXP.h"

class Fileop //�ļ���д��
{
public:
    EXP *readfile(EXP *head); //�����ļ�����
    EXP *writefile(EXP *head); //д���ļ�
};

#endif // FILE_H_INCLUDED
