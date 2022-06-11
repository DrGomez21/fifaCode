/**
 * Codigo para obtener los codigos fifa de las selecciones
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RUTA "archivos/Codigos.csv"
#define LECTURA "r"
#define CANT_CARACTERES 70
#define LONG_COD 4

typedef struct s_registroArchivo
{
    char pais[CANT_CARACTERES];
    char codigo[LONG_COD];
} RegistroArchivo;

FILE *abrirArchivo(char [], char[]);
void procesarArchivo(FILE *);
void buscarCodigo(FILE* , char []);
RegistroArchivo leerRegistros(FILE *);
void cerrarArchivo(FILE *);


int main(void){

    FILE *director = abrirArchivo(RUTA, LECTURA);

    procesarArchivo(director);

    cerrarArchivo(director);

    return 0;
}

FILE *abrirArchivo(char ruta[], char operacion[]){
    FILE *fd = fopen(ruta, operacion);
    //Verificamos que el archivo exista.
    if(!fd){
        printf("No se pudo abrir el archivo de la ruta %s...\n", ruta);
        exit(-1);
    }

    return fd;
}

void procesarArchivo(FILE *archivo){
    
    char pais[CANT_CARACTERES];

    printf("De cual pais quieres su codigo?\n");
    scanf("%[^\n]", pais);

    buscarCodigo(archivo, pais);

}

void buscarCodigo(FILE *archivo, char pais[]){
    
    RegistroArchivo regArchivo;
    int cont = 0;

    while(!feof(archivo)){
        
        regArchivo = leerRegistros(archivo);
        
        if(strcmp(regArchivo.pais, pais) == 0){
            printf("****\nSu codigo es: %s\n****\n", regArchivo.codigo);
            return;
        }
    }

}


RegistroArchivo leerRegistros(FILE *archivo){
    RegistroArchivo r;

    fscanf(archivo, " %[^,], %s", r.pais, r.codigo);
    fgetc(archivo);

    return r;
}

void cerrarArchivo(FILE *archivo){
    if(archivo){
        fclose(archivo);
    }
}
