#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "libraries/pimStr.h"
#include "libraries/calcLyb.h"


char* calc(char* mass){
    char* s = NULL;
    s = (char*)realloc(s,((lenStr(mass)+1)*sizeof(char)));
    copyStr2(s,mass);
    s = delSpace(s); //Удаляем все пробелы, чтобы не мешали
    //printf("|%s|",s);
    if(checkSymStr(s)){//если в строке допустимые символы
        if(checkMathDeystvie(s)){//Праверка на допустимость действий
            return "стоп";
        }else{
            return "Были введены недопустимые для этого калькулятора действия!";
        }
    }else{
        return "Были введены недопустимые символы!";
    }
    return "Этого не должно было случиться!!!";
}

int main()
{
    setlocale(LC_CTYPE,"RUSSIAN");
    printf("Введите выражение: ");
    //char* s = readLine();
    //printf("%s",calc(s));
    char* s="lol";
    s++;
    printf("%s",plus("101","800"));
    //printf("%d",bolsheChisl("1230","321"));
    return 0;
}
