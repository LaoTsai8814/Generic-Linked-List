#include"ReadInput.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define CHARBUFFER 100
int * readInputInt(){
    int read;
    scanf("%d",&read);
    //printf("%d",read);
    int *returnint =(int *)malloc(sizeof(int));
    memcpy(returnint,&read,sizeof(int));
    //printf("%d",*returnint);
    return returnint;
}
double * readInputDouble(){
    double read;
    scanf("%lf",&read);
    double *returndouble =(double *)malloc(sizeof(double));
    memcpy(returndouble,&read,sizeof(double));
    return returndouble;
}
char * readInputChar(){
    
    char s[CHARBUFFER] ;
    s[CHARBUFFER-1] = '\0';
    char *str =  s;
    scanf("%s", str);  
    return str;
}
float * readInputFloat(){
    float read;
    scanf("%f",&read);
    float *returnfloat =(float *)malloc(sizeof(float));
    memcpy(returnfloat,&read,sizeof(float));
    return returnfloat;  
}
char read_side(){
    char read;
    printf("input side");
    fflush(stdin);
    scanf("%c",&read);
    
    printf("%c",read);
    return read;
}