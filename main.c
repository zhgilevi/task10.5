#include <stdio.h>
#include <stdlib.h>
#include<string.h>



void task1(char *str,FILE * output_file){

char* p=strtok(str," ");

while(p!=NULL){
    fprintf(output_file,"%s",p);
    p=strtok(NULL," ");
    if (p!=NULL && strcmp(".",p)!=0){
        fprintf(output_file," ");
    }
}

}



char* task2(char* str,FILE * output_file){
char* str1;
char* last;
last=(char*)malloc(sizeof(char)*256);
str1=(char*)malloc(sizeof(char)*256);

strcpy(str1,str);
char *p=strtok(str," .");
while (p!=NULL){
    last=p;
    p=strtok(NULL," .");
}

char *q=strtok(str1," .");



while (q!=NULL){
    if (strcmp(q,last)!=0){
            fprintf(output_file,"%s ",q);
    }
    q=strtok(NULL," .");
}
return last;

}


void task3(char* str,char *last,FILE * output_file){
unsigned long long l_cur,i;
int flag;



char *p=strtok(str," .");
while (p!=NULL){
    l_cur=strlen(p);
    flag=0;
    if (strcmp(last,p)!=0){
    for (i=1;i<l_cur;i++){
        if(p[0]==p[i])
            flag=1;
    }

    if (flag)
        fprintf(output_file,"%s ",p);


}
p=strtok(NULL," .");
}
}





int main(int argc,char** argv)
{

    FILE * input_file=fopen(argv[1],"r");
    FILE * output_file=fopen(argv[2],"w");
    //task1();
    char *s,*s1,*s2;
    s=(char*)malloc(sizeof(char)*256);
    s1=(char*)malloc(sizeof(char)*256);
    s2=(char*)malloc(sizeof(char)*256);
    //printf("vvedite stroku\n");
    fgets(s,256,input_file);
    strcpy(s1,s);
    strcpy(s2,s);
    fprintf(output_file,"stroka bez lishnich probelov\n");
    task1(s,output_file);
    fprintf(output_file,"\nslova ne sovpadayushie s poslednym\n");
    char* last=task2(s1,output_file);
    fprintf(output_file,"\nslova u kotoryh pervaya bukva vstrechaetsa v slove bolche odnogo raza(zadanie3)\n");
    task3(s2,last,output_file);
    printf("vivod v faile %s",argv[2]);
    return 0;
}
