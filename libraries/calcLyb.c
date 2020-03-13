#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pimStr.h"
#include "calcLyb.h"

/**��������� ����������� �� ������ � ����������� �����*/
int checkZnack(char s){
    int res;
    if ((s=='-')||(s=='+')||(s=='*')||(s=='/')){
        res = 1;
    }else{
        res = 0;
    }
    return res;
}

/**�������� ������� � ��������� "�����������"*/


/**��������� ��� ������������ ������ ���������� �������, ��� ������ ������������.*/
int checkSymStr(char* s){
    int res = 1;
    for(int i = 0;s[i] != '\0';i++){
        if(!(((s[i]>=48) && (s[i]<=57))||checkZnack(s[i]))){
            res=0;
        }
    }
    if(ravnStr(s,"")){
        res = 0;
    }
    return res;
}

/**��������� ��� ��� �������� ����������*/
int checkMathDeystvie(char* s){
    int res=1;
    char sym[lenStr(s)];
    sym[0]='\0';int k=0; int flag = 0;
    /*��������� ���������� ������ �������� � �������� ������*/
    for(int i = 0;i <= lenStr(s);i++){
        if(checkZnack(s[i])){
            flag=1;
            sym[k] = s[i];
            k++;
            sym[k] = '\0';
        }else{
            if((!(ravnStr(sym,"*") || ravnStr(sym,"/") || ravnStr(sym,"+") || ravnStr(sym,"-") || ravnStr(sym,"*-") || ravnStr(sym,"/-")))&&flag){
                res=0;
                break;
            }
            k=0;
            sym[0]='\0';
            flag=0;
        }
    }
    //��������� ����� ������
    if(checkZnack(s[lenStr(s)-1])){
        res=0;
    }
    //�������� ������ �����
    if((s[0]=='*') || (s[0]=='/')){
        res=0;
    }
    return res;
}
