#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    char inpB[100];
    char arq[100];

    fgets(inpB, sizeof(inpB), stdin);
    fflush(stdin);

    inpB[strcspn(inpB, "\n")] = 0;

    if (strcmp(inpB, "run") == 0) {
        system("cls"); //limpa a pagina
        printf("run -- selecione um arquivo: ");
        fgets(arq, sizeof(arq), stdin);
        
        arq[strcspn(arq, "\n")] = 0;

        char base[100];
        strncpy(base, arq, sizeof(base));
        base[sizeof(base) - 1] = '\0';
        char *dot = strrchr(base, '.');
        if (dot) *dot = '\0';

        char cmd[512];
        system("md Saida");
        snprintf(cmd, sizeof(cmd), "gcc -Wall \"%s\" -o \"saida\\%s.exe\"", arq, base);

        int rc = system(cmd);
        if (rc != 0) {
            fprintf(stderr, "falha ao compilar: codigo %d\n", rc);
        }
    }
}