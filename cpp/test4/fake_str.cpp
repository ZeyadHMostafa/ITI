#include <iostream>
int str_len(char str[]){
    int i=0;
    for (i=0; str[i]!=0; i++){}
    return i;
}

int str_cmp(char str1[],char str2[]){
    int i;
    for (i=0; (str1[i]==str2[i])&&(str1[i]!=0)&&(str2[i]!=0); i++){}
    if (str1[i]==0 && str2[i]==0) return 0;
    return str1[i]-str2[i]; //str1[i]<str2[i] ? -1 : 1;
}

void str_concat(char str1[], char str2[], char str3[]){
    int i=0;
    for (i=0; str1[i]!=0; i++){
        str3[i]=str1[i];
    }
    for (int j=0; str2[j]!=0; j++){
        str3[i]=str2[j];
        i++;
    }
    str3[i]=0;
}

void str_tolower(char str[]){
    for (int i=0; str[i]!=0; i++){
        if (str[i]>='A' && str[i]<='Z'){
            str[i]-= 'A'-'a';
        }
    }
}

void str_tocapital(char str[]){
    for (int i=0; str[i]!=0; i++){
        if (str[i]>='a' && str[i]<='z'){
            str[i]+= 'A'-'a';
        }
    }
}

void str_cpy(char str1[],char str2[]){
    int i;
    for (i=0; str1[i]!=0; i++){
        str2[i]=str1[i];
    }
    str2[i]=str1[i];
}