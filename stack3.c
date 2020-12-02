#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BANNER "Bienvenido, La CTF CiberCampanillas 2020 te espera. Estas preparado?"

char *gets(char *);

void premio() {
  printf("Enhorabuena!, has completado el nivel 3 éxito :-)!\n");
  exit(0);
}

void comenzamos() {
  char buffer[64];
  void *retorno;

  gets(buffer);

  retorno = __builtin_return_address(0);
  printf("al salir volveré a la dirección %p\n", retorno);
}

int main(int argc, char **argv) {
  printf("%s\n", BANNER);
  comenzamos();
}