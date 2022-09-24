#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_PATH_LEN 255
#define MAX_STUDENT_NAME_LEN 255

int main(int argc,char *argv[]) {

char file_path[MAX_FILE_PATH_LEN];
    int student_count = 0;

        if (argc < 2) {
            printf("ERROR: No se definio el archivo\n");
            return 0xF1;
        }
    FILE *file = fopen("../names.txt", "r");
    //FILE *file = fopen(argv[1], "r");
    char buffer[MAX_STUDENT_NAME_LEN];

        while (fgets(buffer, MAX_STUDENT_NAME_LEN, file))
            student_count++;

    printf("tenemos %d alumnos\n", student_count);
    char **hatOfnames = malloc((sizeof(char *) * student_count));
    rewind(file);
    int i = 0;

    while (fgets(buffer, MAX_STUDENT_NAME_LEN, file)){
// ya queremos guardar los nombres en el arreglo
// hatOfnames[i] = malloc((sizeof(char) * MAX_STUDENT_NAME_LEN));
        hatOfnames[i] = malloc((sizeof(char) * strlen(buffer)));
        strcpy(hatOfnames[i], buffer);
        i++;
    }
    for(i = 0; i < student_count; i++){
        printf("[%d] - %s", i, hatOfnames[i]);
    }
    return 0;
}