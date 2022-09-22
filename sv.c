#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//FILE *names;
#define MAX_SIZE 25

int main() {
    int v =0;
    FILE *nombres = NULL;
    char buffer [MAX_SIZE];
            //fopen("archivo a leer","accion a realizar");
    nombres = fopen("../names.txt", "r");

    if (nombres == NULL){
        printf("No se pudo abrir el archivo\n");
        return 0xFF;
    }
 //fscanf(archivo a leer,"tipo de dato",direccion de donde vamos a guardar);
    fscanf(nombres,"%s",&buffer);
    v = rand();
    v = v/5;
    v = fgetc(nombres);
    putchar(v);
    //printf("%s\n",buffer[v]);

    // Cualqueira de estas dos funciones sirve, pero la que se esta utilizando es el do while
    /*do {
        printf("%s",buffer);
    } while (fgets(buffer,MAX_SIZE,nombres));*/

   /*while ((v= fgetc(nombres))!= EOF)
    {
        putchar(v);
    }*/

    return 0;
}