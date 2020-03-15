#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pimStr.h"


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


char* vichisl(char* s, int num){
    if(num==0){
        return s;
    }
    char* res;
    int i1=0;
    for(i1=num-1;i1>=0;i1--){
        res=copyStr(s,i1,num-1);

        if(checkZnack(res[0])){
            break;
        }
    }
    //printf("%d",i1);
    if((res[0]!='-')&&checkZnack(res[0])){
        i1++;
        res++;
    }

    char* res2;
    int j1=0;
    for(j1=num+1;s[j1]!='\0';j1++){
        res2=copyStr(s,num+1,j1);
        if(checkZnack(res2[lenStr(res2)-1]) && (j1!=num+1)){
            break;
        }
    }
    j1--;
    res2=copyStr(s,num+1,j1);
    char* str1="";
    if(i1>0){
        str1=copyStr(s,0,i1-1);
    }
    char* str2="";
    if(s[j1+1]!='\0'){
        str2=copyStr(s,j1+1,lenStr(s)-1);
    }
    //printf("\n|%s|\n|%s|\n",res,res2);
    return strPlus(str1,strPlus(deystv(res,s[num],res2),str2));
}
