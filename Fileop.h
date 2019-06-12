#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include "EXP.h"

class Fileop //文件读写类
{
public:
    EXP *readfile(EXP *head); //读出文件内容
    EXP *writefile(EXP *head); //写入文件
};

#endif // FILE_H_INCLUDED
