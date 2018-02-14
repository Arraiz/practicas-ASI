/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: osboxes
 *
 * Created on 07 February 2018, 09:37
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

/*
 * 
 */

int pid_monitor;
int pid_padre = 0;
int pid1 = 0;
int pid2 = 0;
int cont;
int loop =0;

void enviaSignal(int pid, int signal) {

    kill(pid, signal);
}

void sig_handler() {

    printf("sen recibida \n");
    enviaSignal(pid_monitor, SIGUSR2);
    printf("sen enviada desde el handler\n");

}

void ejer2() {
    printf("secreto 2\n");
    enviaSignal(pid_monitor, SIGUSR1);
    enviaSignal(pid_monitor, SIGUSR2);
    //jerarquia
    if (pid1 = fork() == 0) {

    } else {
        if (pid2 = fork() == 0) {
            signal(SIGUSR2, sig_handler);
            while(1);
        }else{
            while(1);
            //enviaSignal(pid_monitor,SIGUSR2);
        }
    }


}

void ejer3() {
    //jerarquia
    enviaSignal(pid_monitor, SIGUSR1);
    sleep(1);
    if (pid1 = fork() == 0) {

    } else {
        if (pid2 = fork() == 0) {


        }
    }
    enviaSignal(pid_monitor, SIGUSR1);
}

void crea_hilos() {

    printf("HILO NUEVO\n");
    sleep(20);

}

void hilos() {
    printf("sig recibida creado hilo\n");
    pthread_t th;
    long t;
    //pthread_create(&th, NULL, crea_hilos, (void *) t);

}

void ejer4() {
    printf("secreto 4\n");
    if (pid1 = fork() == 0) {
        signal(SIGUSR2, hilos);
        while(1);

    } else {
        if (pid2 = fork() == 0) {
            while (1);

        }else{
            while(1);
        }
    }
}

void contar() {
    printf("sig recibida en hijo2\n");
    enviaSignal(pid_monitor, SIGUSR2);
}
void func1() {
    printf("1\n");
    loop++;
}

void func2() {
    cont++;
    enviaSignal(pid_monitor,SIGUSR2);
}
void ejer5() {
    printf("ejercico 5\n");


    if (pid1 = fork() == 0) {
        printf("creado 1 %d\n", getpid());

    } else {
        if (pid2 = fork() == 0) {
            printf("creado 2 %d\n", getpid());
            signal(SIGUSR1, func1);
            signal(SIGUSR2, func2);
            while(loop<2){
                printf("rec %d\n",cont);
                pause();
            }
        } else {
            enviaSignal(pid_monitor, SIGUSR1);
        }
    }
}

void ejer6(){
    enviaSignal(pid_monitor,SIGUSR1);
    sleep(2);
    enviaSignal(pid1,SIGKILL);
    enviaSignal(pid_monitor,SIGKILL);
    
}

void ejer1() {
    //secreto 1
    printf("secreto1\n");
    enviaSignal(pid_monitor, SIGUSR1);
    printf("enviada s1\n");
    sleep(2);
}

int main(int argc, char** argv) {

    //guardamos el primer parametro introducido al programa
    pid_monitor = atoi(argv[1]);

    printf("pid monitor:  %d \n", pid_monitor);
    getchar();
    ejer6();
    getchar();




}




