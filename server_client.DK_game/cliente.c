//
// Created by kenneth on 08/06/19.
//
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#define PORT 8080
int sock = 0, valread;
struct sockaddr_in serv_addr;
char *hello = "Hello from client";
char buffer2[1024] ;
/**
 * ESta funcion lo que realiza es conectar el socket
 * @return
 */
void * conectar_Socket(){
    printf("LOL");

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    while(1==1){
        memset(buffer2,0,1024)    ;
        valread = read( sock , buffer2, 1024);
        setvbuf(stdout,NULL,_IONBF,0);
        char* variable = buffer2;
        printf(buffer2);
        if(!strcmp1("main",buffer2)) {
            funcion();
            //LLAMAR LA FUNCION DE hacer que sea el oyente nada mas
            printf("SOY EL PRINCIPAL xd");
        }
        if(!strcmp1("oyente",buffer2)){
            escuchar();
            return ;
        }
        if(!strcmp1("get",buffer2)){
            char* cosas = "prueba";
            //TIENEN QUE DEFINIR QUE ES COSAS QUE ES EL MENSAJE QUE USTEDES OCUPAN ENVIAR CON LA INFo y asignar "cosas'
            valread= send(sock,cosas,strlen(cosas),0);

        }
        else{
            //LLAMAR ACA LA FUNCION DE PONER LA FUNCION QUE CREA BARRILES
//    parseBarril(buffer2);
        }
    }
}
/**
 * En esta funcion se escucha de forma continua al servidor
 */
void escuchar(){
    memset(buffer2,0,1024);
    valread = read( sock , buffer2, 1024);
    printf("VEA AQUI SE ENCONTRO Y SE PASO LO DEL MAE xd \n");
    printf(buffer2);
    //AQUI ES LA FUNCION QUE CARGA TODO POR PRIMERA VEZ
    while (1==1){
        memset(buffer2,0,1024)    ;
        valread = read( sock , buffer2, 1024);
        //AQUI VA LA QUE HACE QUE TODAS LAS COSAS SE MUEVAN
        if(valread==0){
            conectar_Socket();
            break;
        }
    }
}
void funcion(){
    printf("Este fue el primero");
}
void send_caracteristicas
/**
 * Compara los diferentes strings
 * @param s el string 1
 * @param p el string 2
 * @return
 */
int strcmp1(char *s, char *p){
    int indice = 0;
    while (1==1){
        if(p[indice]=='\0' && s[indice]=='\0' ){
            return 0;
        }
        if (p[indice]!= s[indice]){
            return 1;
        }
        if(p[indice]=='\0' ){
            return 1;
        }
        if(s[indice]=='\0' ){
            return 1;
        }
        indice++;
    }
}