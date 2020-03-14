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



/**Делит(целочисленно) одно положительное число на другое(Важен порядок!!! s1/s2)*/
char* delenie(char* str1, char* str2){
    char* chisl="0";
    char* s1 = str1;
    char* s2 = str2;
    char* mass = (char*)realloc(mass,((0)*sizeof(char)));

    while(1){
        chisl=plusStrChisl(chisl,"9999999999999999999");
        printf("%s\n",chisl);
    }
    return chisl;
}

int main()
{
    setlocale(LC_CTYPE,"RUSSIAN");
    printf("Введите выражение: \n");
    //char* s = readLine();
    //printf("%s",calc(s));
   // printf("|%s|\n",s);
    //printf("%d\n",bolsheChisl("311", "10"));
    printf("%s",delenie("1999999999321","1999999999321"));
    //printf("%d",bolsheChisl("1230","321"));
    return 0;
}
