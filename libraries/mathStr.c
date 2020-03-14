#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pimStr.h"
/**���������� ����������� �������� � ������� ��� �� ��������*/


/**���������� 2 ������������� �����(���� ��� ����� �� ������� 1)*/
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

/**���������� 2 ������������� �����*/
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
    s2=strPlus(s2,nol);//���������� ���� � �������� �����
    int len=0;
    char* mass = (char*)realloc(mass,((len)*sizeof(char)));
    int chisl=0;//���������� 3 �����
    char mem='0';//���������� ������� �������
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

/**�������� 2 ������������� �����*/
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
        //��� �����, ������ ����� ���
        for(int j=0;j<lenStr(s2);j++){
            int len=0;
            char* mass = (char*)realloc(mass,((len)*sizeof(char)));
            int chisl=0;//���������� 3 �����
            char mem='0';//���������� ������� �������
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


/**�������� 2 ������������� �����. (�� �������� �������� �������!!!)*/
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
    s2=strPlus(s2,nol);//���������� ���� � �������� �����
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


/**�����(������������) ���� ������������� ����� �� ������(����� �������!!! s1/s2)*/
char* delenie(char* str1, char* str2){
    if(ravnStr(str1,"0")){
        return "0";
    }
    if(ravnStr(str2,"0")){
        return "\n������� �� 0!!!\n";
    }
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
    char* res="";//���������
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
        /**������� ����� ������� ��������*/
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
    }

    return res;
}
