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
    if(checkSymStr(s)){//если в строке допустимые символы
        if(checkMathDeystvie(s)){//Праверка на допустимость действий
            int flag=1;
            while(flag){//ищем и считаем сначало деление и умножение
                flag=0;
                for(int i=0;s[i]!='\0';i++){
                    if((s[i]=='/')||(s[i]=='*')){
                        flag=1;
                        s=vichisl(s,i);
                        printf("%s\n",s);
                        break;
                    }
                }
            }
            flag=1;
            while(flag){//ищем и считаем сложение и вычитание
                flag=0;
                for(int i=0;s[i]!='\0';i++){
                    if(((s[i]=='+')||(s[i]=='-'))&&(i!=0)){
                        flag=1;
                        s=vichisl(s,i);
                        printf("%s\n",s);
                        break;
                    }
                }
            }
            return s;
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
    char* s=readLine();
    printf("Результат = %s\n",calc(s));
    //printf("%s",deystv("-234321",'+',"-324"));
    //723
    //printf("%s",minusStrChisl("723","324"));
    return 0;
}
