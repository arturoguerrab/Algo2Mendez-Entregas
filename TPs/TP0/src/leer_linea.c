#include "leer_linea.h"
#include <stdio.h>
#define BLOQUE_MEMORIA 6

char *leer_linea() {
  size_t tamanio = BLOQUE_MEMORIA;
  int ml;
  char *ptr = malloc(sizeof(char) * tamanio);

  if (ptr != NULL) {
    ml = leer_linea_ptr(&ptr, &tamanio);
    if (ml == -1) {
      free(ptr);
      ptr = NULL;
    }
  } else
    ptr = NULL;

  return ptr;
}

int leer_linea_ptr(char **ptr, size_t *tamanio) {
  int ml = 0;
  int entrada = getchar();
  char *aux = NULL;

  while (entrada != '\n' && entrada != EOF && ml != -1) {
    if (ml >= (int)*tamanio - 1) {
      aux = realloc(*ptr, sizeof(char) * ((*tamanio) * 2));
      if (aux != NULL) {
        *ptr = aux;
        (*tamanio) = (*tamanio) * 2;
      } else
        ml = -1;
    }

    if (ml != -1) {
      (*ptr)[ml] = (char)entrada;

      ml++;
      entrada = getchar();
    }
  }

  if (ml != -1)
    (*ptr)[ml] = '\0';

  return ml;
}
