#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BANNER "Bienvenido, La CTF de CiberCampanillas 2020 te espera. Estas preparado?"

int main(int argc, char **argv) {
  struct {
    char buffer[64];
    volatile int cambiame;
  } locales;

  char *vble_entorno;

  printf("%s\n", BANNER);

  vble_entorno = getenv("Pillin");
  if (vble_entorno == NULL) {
    errx(1, "Es necesario que definas la variable de entorno Pillin");
  }

  locales.cambiame = 0;
  strcpy(locales.buffer, vble_entorno);

  if (locales.cambiame == 0x0d0a090a) {
    puts("Enhorabuena, Has modificado correctamente cambiame! Nivel 1 Completado!!");
  } else {
    printf("Casi! cambiame actualmente es 0x%08x, y nosotros queremos 0x0d0a090a\n",
        locales.cambiame);
  }

  exit(0);
}