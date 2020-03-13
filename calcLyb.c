#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "pimStr.h"
#include "calcLyb.h"

/**Основные функции в программе "калькулятор"*/

/**Проверяем что используются только допустимые символы, для работы калькулятора.*/
int checkSymStr(char* s){
    int res = 1;
    for(int i = 0;s[i] != '\0';i++){
        if(!(((s[i]>=48) && (s[i]<=57))||(s[i]=='-')||(s[i]=='+')||(s[i]=='*')||(s[i]=='/'))){
            res=0;
        }
    }
    return res;
}
