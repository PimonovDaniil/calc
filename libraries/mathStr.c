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
char* plus(char* str1, char* str2){
    char* s1;
    char* s2;
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
