#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BANNER "Bienvenido, La CTF de CiberCampanillas 2020 te espera. Estas preparado?"

char *gets(char *);

void premio() {
  printf("Enhorabuena!, has completado el nivel 2 éxito :-)!\n");
  exit(0);
}

int main(int argc, char **argv) {
  struct {
    char buffer[64];
    volatile int (*fp)();
  } locales;

  printf("%s\n", BANNER);

  locales.fp = NULL;
  gets(locales.buffer);

  if (locales.fp) {
    printf("Llamando a la función situada en la dirección @ %p\n", locales.fp);
    fflush(stdout);
    locales.fp();
  } else {
    printf("No has modificado locales.fp :~( Mejor suerte la próxima!\n");
  }

  exit(0);
}