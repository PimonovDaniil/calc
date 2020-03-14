#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pimStr.h"
/**Библиотека позволяющая работать с числами как со строками*/


/**сравнивает 2 положительных числа(если они равны то выводит 1)*/
int bolsheChisl(char* s1,char* s2){
    int res=1;
    if(ravnStr(s1,s2)){
        return res;
    }
    if(lenStr(s1)>lenStr(s2)){
        return res;
    }else if(lenStr(s1)<lenStr(s2)){
        res=0;
        return res;
    }else{
        for(int i=0;i<lenStr(s1);i++){
            if(s1[i]>s2[i]){
                return res;
                break;
            }else if(s1[i]<s2[i]){
                res=0;
                return res;
                break;
            }
        }
    }
    return -1;
}

/**Складывает 2 положительных числа*/
char* plusStrChisl(char* str1, char* str2){
    int max=-1;
    if(lenStr(str1)>lenStr(str2)){
        max=lenStr(str1);
    }else{
        max=lenStr(str2);
    }
    char* s1=malloc(max+1);
    char* s2=malloc(max+1);
    if(bolsheChisl(revert(str1), revert(str2))){
        s1=revert(str1);
        s2=revert(str2);
    }else{
        s1=revert(str2);
        s2=revert(str1);
    }
    char nol[lenStr(s1)-lenStr(s2)+1];
    nol[lenStr(s1)-lenStr(s2)]='\0';
    for(int i=0;i<lenStr(s1)-lenStr(s2);i++){
        nol[i]='0';
    }
    s2=strPlus(s2,nol);//дописываем нули у меньшего числа
    int len=0;
    char* mass = (char*)realloc(mass,((len)*sizeof(char)));
    int chisl=0;//складываем 3 числа
    char mem='0';//запоминаем перенос разряда
    for(int i=0; s1[i]!='\0';i++){
        chisl=(s1[i]-48)+(s2[i]-48)+(mem-48);
        len++;
        mass=(char*)realloc(mass,((len)*sizeof(char)));
        mass[len-1]=(chisl%10)+48;
        chisl/=10;
        mem=chisl+48;
    }
    if(mem!='0'){
        len++;
        mass=(char*)realloc(mass,((len)*sizeof(char)));
        mass[len-1]=mem;
    }

    len++;
    mass=(char*)realloc(mass,((len)*sizeof(char)));
    mass[len-1]='\0';
    return revert(mass);
}

/**Умножает 2 положительных числа*/
char* multiply(char* str1, char* str2){
    if(ravnStr(str1,"0")||ravnStr(str2,"0")){
            return "0";
    }else{
        char* sum="0";
        char* nol="";
        int max=-1;
        if(lenStr(str1)>lenStr(str2)){
            max=lenStr(str1);
        }else{
            max=lenStr(str2);
        }
        char* s1=malloc(max+1);
        char* s2=malloc(max+1);
        if(bolsheChisl(revert(str1), revert(str2))){
            s1=revert(str1);
            s2=revert(str2);
        }else{
            s1=revert(str2);
            s2=revert(str1);
        }
        //Как сумма, только много раз
        for(int j=0;j<lenStr(s2);j++){
            int len=0;
            char* mass = (char*)realloc(mass,((len)*sizeof(char)));
            int chisl=0;//складываем 3 числа
            char mem='0';//запоминаем перенос разряда
            for(int i=0; s1[i]!='\0';i++){
                chisl=(s1[i]-48)*(s2[j]-48)+(mem-48);
                len++;
                mass=(char*)realloc(mass,((len)*sizeof(char)));
                mass[len-1]=(chisl%10)+48;
                chisl/=10;
                mem=chisl+48;
            }
            if(mem!='0'){
                len++;
                mass=(char*)realloc(mass,((len)*sizeof(char)));
                mass[len-1]=mem;
            }
            len++;
            mass=(char*)realloc(mass,((len)*sizeof(char)));
            mass[len-1]='\0';
            mass=strPlus(nol,mass);
            nol=strPlus(nol,"0");
            sum=plusStrChisl(sum,revert(mass));
        }
        return sum;
    }
}


/**вычитает 2 положительных числа. (из большего вычитает меньшее!!!)*/
char* minusStrChisl(char* str1, char* str2){
    int max=-1;
    if(lenStr(str1)>lenStr(str2)){
        max=lenStr(str1);
    }else{
        max=lenStr(str2);
    }
    char* s1=malloc(max+1);
    char* s2=malloc(max+1);
    if(bolsheChisl(revert(str1), revert(str2))){
        s1=revert(str1);
        s2=revert(str2);
    }else{
        s1=revert(str2);
        s2=revert(str1);
    }
    char nol[lenStr(s1)-lenStr(s2)+1];
    nol[lenStr(s1)-lenStr(s2)]='\0';
    for(int i=0;i<lenStr(s1)-lenStr(s2);i++){
        nol[i]='0';
    }
    s2=strPlus(s2,nol);//дописываем нули у меньшего числа
    int len=0;
    char* mass = (char*)realloc(mass,((len)*sizeof(char)));
    int chisl=0;
    for(int i = 0;s1[i]!='\0';i++){
        if(s1[i]==47){
            s1[i]=57;
            s1[i+1] = s1[i+1]-1;
        }
        if(((s1[i]-48)-(s2[i]-48))<0){
            s1[i]=s1[i]+10;
            s1[i+1] = s1[i+1]-1;
        }
        len++;
        mass=(char*)realloc(mass,((len)*sizeof(char)));
        mass[len-1]=(s1[i]-48)-(s2[i]-48)+48;
    }
    len++;
    mass=(char*)realloc(mass,((len)*sizeof(char)));
    mass[len-1]='\0';
    mass=revert(mass);
    while(mass[0]=='0'){
        mass++;
    }
    if(ravnStr(trim(mass),"")){
        mass=strPlus(mass,"0");
    }
    return mass;
}
