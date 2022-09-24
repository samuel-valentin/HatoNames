#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_FILE_PATH_LEN 25
#define MAX_STUDENT_NAME_LEN 25
int replay = 0;

int random_function(int students){
    int random [students];
    int generator = 0, j = 0;
    time_t t;
    srand((unsigned )time(&t));
    generator = (rand() % students);
    random [j] = generator;
    j++;
    /*for (int i = 0; i < j; ++i) {
        if (random [i] == generator ){
            return 0x73;
        }
    }*/
        replay ++;
        return generator;
}

int main(int argc,char *argv[]) {

    char file_path[MAX_FILE_PATH_LEN];
    int student_count = 0, select = 0;

    if (argc < 2) {
        printf("ERROR: No se definio el archivo\n");
        return 0xF1;
    }

    FILE *file = fopen(argv[1], "r");
    char buffer[MAX_STUDENT_NAME_LEN];

    while (fgets(buffer, MAX_STUDENT_NAME_LEN, file))
        student_count++;

    char **hatOfnames = malloc((sizeof(char *) * student_count));
    rewind(file);
    int i = 0;

    while (fgets(buffer, MAX_STUDENT_NAME_LEN, file)){
// ya queremos guardar los nombres en el arreglo
        hatOfnames[i] = malloc((sizeof(char) * MAX_STUDENT_NAME_LEN));
        //hatOfnames[i] = malloc((sizeof(char) * strlen(buffer)));
        strcpy(hatOfnames[i], buffer);
        i++;
    }

    // Para leer un solo caracter de la terminal (stdin)
    printf("Para iniciar a usar el programa y obtener nombres de manera aleatoria, escribe 'f'>\n");
    printf("Para ver la lista de nombres de tu archivo, escribe 'r'>\n");
    printf("Una ves dentro del programa si quiere salir, presione cualqier otra tecla>\n");

    time_t t;
    srand((unsigned )time(&t));

    /*while (1){
        char choice = fgetc(stdin);
        fflush(stdin);
        generator = (rand() % student_count);
        replay ++;
        if (replay > student_count){
            printf("End of the list no more names available");
            return 0xFF;
        }
            printf("%s",hatOfnames[generator]);
        generator = 0;
    }*/

    while(1){
        char choice = fgetc(stdin);
        fflush(stdin);
        if((choice != 'f') & (choice != 'r')){
            printf("ERROR JAJAJA BYE pusiste la que no se podia\n");
            return 0xE1;
        }
        switch (choice) {
            case 'f':
                select = random_function(student_count);
                if (select == 0x73)
                    select = random_function(student_count);
                if (replay > student_count){
                    printf("End of the list no more names available");
                    return 0xFF;
                } else {
                    printf("%s",hatOfnames[select]);
                }
                break;
            case 'r':
                for (int j = 0; j < student_count; ++j) {
                    printf("%s",hatOfnames[j]);
                }
                break;
        }
        printf("You Know what to do\n");
    }

    return 0;
}