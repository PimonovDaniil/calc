#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "libraries/pimStr.h"
#include "libraries/calcLyb.h"
#include "libraries/mathStr.h"



/**https://github.com/PimonovDaniil/calc*/

char* calc(char* mass){
    char* s = NULL;
    s = (char*)realloc(s,((lenStr(mass)+1)*sizeof(char)));
    copyStr2(s,mass);
    s = delSpace(s); //������� ��� �������, ����� �� ������
    //printf("|%s|",s);
    if(checkSymStr(s)){//���� � ������ ���������� �������
        if(checkMathDeystvie(s)){//�������� �� ������������ ��������
            return "����";
        }else{
            return "���� ������� ������������ ��� ����� ������������ ��������!";
        }
    }else{
        return "���� ������� ������������ �������!";
    }
    return "����� �� ������ ���� ���������!!!";
}



/**�����(������������) ���� ������������� ����� �� ������(����� �������!!! s1/s2)*/
char* delenie(char* str1, char* str2){
    int max=-1;
    if(lenStr(str1)>lenStr(str2)){
        max=lenStr(str1);
    }else{
        max=lenStr(str2);
    }
    char* s1=malloc(max+1);
    char* s2=malloc(max+1);
    s1=str1;
    s2=str2;
    char* chisl="0";
    while(bolsheChisl(s1,s2)){
        chisl=plusStrChisl(chisl,"1");
        s1=minusStrChisl(s1,s2);
        printf(" \b");
    }
    return chisl;
}

int main()
{
    setlocale(LC_CTYPE,"RUSSIAN");
    printf("������� ���������: \n");
    //char* s = readLine();
    //printf("%s",calc(s));
   // printf("|%s|\n",s);
    //printf("%d\n",bolsheChisl("311", "10"));
    printf("%s",delenie("1234599","1"));
    //printf("%d",bolsheChisl("1230","321"));
    return 0;
}
