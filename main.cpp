#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    //Punteros de la estructura FILE, para el archivo de entrada (origen) y salida (destino)
    FILE *fe, *fs;
    unsigned char buffer[2048]; // Buffer de 2 Kbytes
    int bytesLeidos;

    // Constante  para la dirección que se genera por default de los archivos que van a utilizar.
    char *dir = "D:/DOCUMENTOS/ITL/6TO SEMESTRE/LyA1/";
    // Constante para la extensión (txt) para usar solamente archivos de texto.
    char *ext = ".txt";

    // Declarar e inicializar los variables que tendrán el PATH, NOMBRE y EXTENSIÓN de los archivos que ingresará el usuario
    char origen[255] = "";
    char destino[255] = "";

    // Declarar los variables que tendrán solamente los nombres de los archivos que ingresará el usuario
    char nombreOrigen[25];
    char nombreDestino[25];

    // Ingresar nombre del archivo de origen
    cout << "Ingrese el nombre del archivo de origen (Este archivo debe de existir): ";
    cin >> nombreOrigen;

    // Concatenar la dirección y extensión del archivo de origen
    // Nota -> El archivo de origen debe existir
    strcat(origen, dir);
    strcat(origen, nombreOrigen);
    strcat(origen, ext);

    cout << origen << "\n";

    // Se bedrá abrir el archivo de origen en lectura y binario el método fopen(), mandando como parámetros el nombre
    // y el modo "rb" ( lectura y binario)
    // el método fopen() regresa una estructura FILE que será apuntada por fe

    fe = fopen(origen, "rb");

    if(!fe) {
        // comprobar que el archivo existe, si no existe se muestra un mensaje de error y se regresa un 1
        printf("El fichero %s no existe o no puede ser abierto.\n", origen);
        return 1;
    }

    // Ingresar nombre del archivo de destino
    cout << "Ingrese el nombre del archivo de destino(Este archivo se va a crear): ";
    cin >> nombreDestino;

    // Concatenar la dirección y extensión del archivo de destino
    // Nota -> El archivo de destino, se va a crear
    strcat(destino, dir);
    strcat(destino, nombreDestino);
    strcat(destino, ext);

    // Crear o sobreescribir el fichero de salida en binario también con el método fopen(), mandando
    //nombre y modo (w = write y b = binario)

    fs = fopen(destino, "wb");

    if(!fs) {
        // comprobar que el archivo existe, si no existe se muestra un mensaje de error y se regresa un 1
        printf("El fichero %s no puede ser creado.\n", destino);
        fclose(fe);
        return 1;
    }
    // Bucle de copia:
    // Una vez creados loa archivos, se hace la copia
    // fread = regresa el número de registros/bytes leídos
    // se define bytesLeidos con el número de registros leídos del archivo de entrada u origen hasta 2048
    // se escriben en el archivo de salida o destino todos los bytes leídos
    while((bytesLeidos = fread(buffer, 1, 2048, fe)))
        fwrite(buffer, 1, bytesLeidos, fs);
    // Cerrar ficheros:
    fclose(fe);
    fclose(fs);

    // se termina la copia y se regresa un 0
    cout << "\nTodo Correcto, el archivo fue copiado!\n";
    return 0;
}

/*int main(int argc, char **argv)
{
    // Declarar archivo de entrada (origen) y salida (destino)
    FILE *fe, *fs;
    unsigned char buffer[2048]; // Buffer de 2 Kbytes
    int bytesLeidos;

    if(argc != 3) {
        printf("Usar: copia <fichero_origen> <fichero_destino>\n");
        return 1;
    }

    // Abrir el fichero de entrada en lectura y binario
    fe = fopen(argv[1], "rb");
    if(!fe) {
        printf("El fichero %s no existe o no puede ser abierto.\n", argv[1]);
        return 1;
    }
    // Crear o sobreescribir el fichero de salida en binario
    fs = fopen(argv[2], "wb");
    if(!fs) {
        printf("El fichero %s no puede ser creado.\n", argv[2]);
        fclose(fe);
        return 1;
    }
    // Bucle de copia:
    while((bytesLeidos = fread(buffer, 1, 2048, fe)))
        fwrite(buffer, 1, bytesLeidos, fs);
    // Cerrar ficheros:
    fclose(fe);
    fclose(fs);
    return 0;
}*/
