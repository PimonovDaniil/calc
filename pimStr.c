#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "pimStr.h"

/**Складывает две строки*/
char* strPlus(char* s1,char* s2){
    char* mass = NULL;
    mass=(char*)realloc(mass,((lenStr(s1)+lenStr(s2)+1)*sizeof(char)));
    int k=0;
    for(int i=0;s1[i]!='\0';i++){
        mass[k]=s1[i];
        k++;
    }
    for(int i=0;s2[i]!='\0';i++){
        mass[k]=s2[i];
        k++;
    }
    mass[k]='\0';
    return mass;
}

/**длина строки*/
int lenStr( char *str ){
    int len=0;
    if(str[0]=='\0'){
        return 0;
    }
    for(int i=0;str[i]!='\0';i++)
        len=i;
    return len+1;
}

/**ищет количество подстрок. (приложение к функции SearchPodstr)
Нужна просто чтобы повысить читаемость кода.*/
int kol(int* mass){
    return mass[0];
}

///Важно. Первый элемент возвращаемого массива это количество элементов!!!
int *SearchPodstr(char *s1/*строка*/,char *s2/*подстрока*/){
    int* mass = NULL;
    int len=0;
    mass=(int*)realloc(mass,((len+1)*sizeof(int)));
    mass[0]=len;
    int memInd=0;/*запоминаем индекс с первым совпадением*/
    int mem=0;/*Типо идём по подстроке*/
    for(int i=0;s1[i]!='\0';i++){
        if(s1[i] == s2[mem]){
            if(mem==0){
                memInd=i;
            }
            if(s2[mem+1]=='\0'){
                len++;
                mass=(int*)realloc(mass,((len+1)*sizeof(int)));
                mass[0]=len;
                mass[len]=memInd;
                mem=0;
                memInd=0;
            }else{
                mem++;
            }
        }else{
            mem=0;
            memInd=0;
            if(s1[i] == s2[mem]){ //Если вдруг это несовпадение,
                if(mem==0){       //является началом новой подстроки
                    memInd=i;
                }
                if(s2[mem+1]=='\0'){
                    len++;
                    mass=(int*)realloc(mass,((len+1)*sizeof(int)));
                    mass[0]=len;
                    mass[len]=memInd;
                    mem=0;
                    memInd=0;
                }else{
                    mem++;
                }
            }
        }
    }
    return mass;
}

/*возвращает подстроку с a по b индексы*/
char* copyStr(char* s,int a,int b){
    char* mass = NULL;
    mass=(char*)realloc(mass,((b-a+2)*sizeof(char)));
    mass[b-a+1]='\0';
    int k=0;
    for(int i=a;i<=b;i++){
        mass[k]=s[i]; k++;
    }
    return mass;
}

/**удаляет пробелы по краям строки*/
/*Возможно это самая плохая реализация trim что вы видели*/
char* trim(char* s){
    char* ltrim(char* s){
        int* podStr=SearchPodstr(s," ");
        if(kol(podStr)>=1){
            if(podStr[1]==0){
                return  ltrim(copyStr(s,1,lenStr(s)-1));
            }else{
                return s;
            }
        }else{
            return s;
        }
    }

    char* rtrim(char* s){
        int* podStr=SearchPodstr(s," ");
        if(kol(podStr)>=1){
            if(podStr[kol(podStr)]==lenStr(s)-1){
                return  rtrim(copyStr(s,0,lenStr(s)-2));
            }else{
                return s;
            }
        }else{
            return s;
        }
    }
    return ltrim(rtrim(s));
}



/*копирует одну строку в другую*/
void copyStr2(char *s1,char *s2){
    int k=0;
    while(s2[k]!='\0'){
        s1[k]=s2[k];
        k++;
    }
    s1[k]='\0';
}


/*Понятия не имею как я отладил эту функцию, но она работает*/
/*Для коректной работы необходимо наличие пробелов по бокам. Это не баг, а фича.*/
/**Функция возвращает массив строк и их количество*/
char **splitStr(char* s,int* N){
    /*Я беру два индекса вхождений в подстроку пробела*/
    /*Если между ними не пусто то добавляю строку*/
    s=strPlus(" ",s);
    s=strPlus(s," ");
    int len=0;
    int* podStr=SearchPodstr(s," ");
    char **mass= (char **)malloc((len)*sizeof(int*));
    char* mem=(char*)malloc((lenStr(copyStr(s,0,podStr[1]))+1)*sizeof(char));
    char* mem3=(char*)malloc((lenStr(copyStr(s,0,podStr[1]))+1)*sizeof(char));
    char* mem2=(char*)malloc((lenStr(copyStr(s,podStr[kol(podStr)],lenStr(s)-1)))*sizeof(char));
   if(kol(podStr)>=1){
        if(lenStr(trim(copyStr(s,0,podStr[1])))>0){
           // printf("*\n");
            len++;
            *mass= (char **)malloc((len)*sizeof(int*));
            mass[0]=(char*)malloc((lenStr(copyStr(s,0,podStr[1])+1)*sizeof(char)));
            copyStr2(mass[0],copyStr(s,0,podStr[1]));
            copyStr2(mem,mass[0]);
        }
        if(lenStr(trim(copyStr(s,podStr[kol(podStr)],lenStr(s)-1)))>0){
            //printf("-\n");
            copyStr2(mem2,copyStr(s,podStr[kol(podStr)],lenStr(s)-1));
        }
        for(int i=1;i<=kol(podStr)-1;i++){
            if(lenStr(trim(copyStr(s,podStr[i],podStr[i+1])))>0){
                //printf("1%s1 %d\n",trim(copyStr(s,podStr[i],podStr[i+1])),len-1);
                len++;
                *mass= (char **)malloc((len)*sizeof(int*));
                mass[len-1]=(char*)malloc((lenStr(copyStr(s,podStr[i],podStr[i+1])+1)*sizeof(char)));
                copyStr2(mass[len-1],trim(copyStr(s,podStr[i],podStr[i+1])));
                if(len-1==0){
                    copyStr2(mem3,mass[0]);
                }
            }
        }
        if(lenStr(trim(copyStr(s,podStr[kol(podStr)],lenStr(s)-1)))>0){
            len++;
            *mass= (char **)malloc((len)*sizeof(int*));
            mass[len-1]=(char*)malloc(((lenStr(copyStr(s,podStr[kol(podStr)],lenStr(s)-1)))*sizeof(char)));
            copyStr2(mass[len-1],trim(mem2));
        }
        if(lenStr(trim(copyStr(s,0,podStr[1])))>0){
            copyStr2(mass[0],mem);
        }else{
            copyStr2(mass[0],mem3);
        }
    }
    *N=len;
    return mass;
}

/*сравнивает 2 строки*/
int ravnStr(char s1[999], char s2[999]){
    int res=1;
    int k=0;
    while(s1[k]!='\0'){
        if(s1[k]!=s2[k]){
           res=0;
           break;
        }
        k++;
    }
    if(s1[k]!=s2[k]){
           res=0;
    }
    return res;
}

///возвращает одну, считанную с консоли, строку
char *readLine(){
    char *s = malloc(999);
    s[0]='\0';
    char mem;
    scanf("%c",&mem);
    for(int i=0;mem!='\n';i++){
        s[i]=mem;
        s[i+1]='\0';
        scanf("%c",&mem);
    }
    return s;
}

/**функция удаляет все пробелы в строке*/
char* delSpace(char* s){
    char* mass = NULL;
    mass = (char*)realloc(mass,((lenStr(s)+1)*sizeof(char)));
    int k = 0;
    for(int i = 0;i < lenStr(s);i++){
        if(s[i]!=' '){
            mass[k]=s[i];
            k++;
        }
    }
    return mass;
}
