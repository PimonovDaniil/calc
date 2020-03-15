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
    if(checkSymStr(s)){//���� � ������ ���������� �������
        if(checkMathDeystvie(s)){//�������� �� ������������ ��������
            int flag=1;
            while(flag){//���� � ������� ������� ������� � ���������
                flag=0;
                for(int i=0;s[i]!='\0';i++){
                    if((s[i]=='/')||(s[i]=='*')){
                        flag=1;
                        s=vichisl(s,i);
                        //printf("%s\n",s);
                        break;
                    }
                }
            }
            flag=1;
            while(flag){//���� � ������� �������� � ���������
                flag=0;
                for(int i=0;s[i]!='\0';i++){
                    if(((s[i]=='+')||(s[i]=='-'))&&(i!=0)){
                        flag=1;
                        s=vichisl(s,i);
                        //printf("%s\n",s);
                        break;
                    }
                }
            }
            return s;
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
    printf("\n%s\n",calc("-22345+45656+1243*435*-5645+23434-23445"));
    return 0;
}
