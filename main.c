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
/*char* delenie(char* str1, char* str2){
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
        printf(" \b");///без этого не работает
    }
    return chisl;
}*/

/**Делит(целочисленно) одно положительное число на другое(Важен порядок!!! s1/s2)*/
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
    char* chisl= malloc(lenStr(s1)+1);
    copyStr2(chisl,s1);
    char* res="";//результат
    while(bolsheChisl(chisl,s2)){
        int i=0;
        for( i=0;lenStr(chisl);i++){
            if(bolsheChisl(copyStr(chisl,0,i),s2)){
                break;
            }
        }
        char* mem = copyStr(chisl,0,i);
        //printf("%s\n",mem);
        chisl+=lenStr(mem);
        char* resMem = "0";
        while(bolsheChisl(mem,s2)){
                printf(" \b");
            mem=minusStrChisl(mem,s2);
            printf(" \b");
            resMem=plusStrChisl(resMem,"1");
            printf(" \b");
        }
        res=strPlus(res,resMem);
        if(ravnStr(mem,"0")){
            mem++;
        }
        /**сколько нулей придётся дописать*/
        chisl=strPlus(mem,chisl);
        char* kol="";
        for(int i=lenStr(mem);chisl[i]!='\0';i++){
            if(bolsheChisl(copyStr(chisl,0,i),s2)){
                break;
            }else{
                kol=strPlus(kol,"0");
            }
        }
        res=strPlus(res,kol);
        //printf("%s\n",chisl);

    }

    return res;
}

int main()
{
    setlocale(LC_CTYPE,"RUSSIAN");
    printf("Введите выражение: \n");
    //char* s = readLine();
    //printf("%s",calc(s));
   // printf("|%s|\n",s);
    //printf("%d\n",bolsheChisl("311", "10"));
    printf("%s\n",delenie("123","8"));
    //printf("%d",bolsheChisl("1230","321"));
    return 0;
}
