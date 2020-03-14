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


int main()
{
    setlocale(LC_CTYPE,"RUSSIAN");
    printf("������� ���������: \n");
    //char* s = readLine();
    //printf("%s",calc(s));
   // printf("|%s|\n",s);
    //printf("%d\n",bolsheChisl("311", "10"));
    printf("%s\n",deystv("-2",'+',"-1"));
    //printf("%d",bolsheChisl("1230","321"));
    return 0;
}
