#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "libraries/pimStr.h"
#include "libraries/calcLyb.h"
/*https://github.com/PimonovDaniil/calc*/

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



int main()
{
    setlocale(LC_CTYPE,"RUSSIAN");
    printf("������� ���������: ");
    //char* s = readLine();
    //printf("%s",calc(s));
    char* s="lol";
    s++;
    printf("%s",minusStrChisl("10","15"));
    //printf("%d",bolsheChisl("1230","321"));
    return 0;
}
