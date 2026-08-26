|#include <stdio.h>
#include "leer_linea.h"

int main(int argc, char *argv[])
{
	printf("Ingresa tu nombre: ");
	char *nombre = leer_linea();
	printf("Hola %s", nombre);
	free(nombre);
	return 0;
}
