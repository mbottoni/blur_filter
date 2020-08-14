
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include "imageprocessing.h"
#include "cronometro.h"
#define N 10

int main() {


  clock_t ct0, ct1, dct; /* Medida de tempo baseada no clock da CPU */
  struct timeval rt0, rt1, drt; /* Tempo baseada em tempo real */
  void *P;
  gettimeofday(&rt0, NULL);
  ct0 = clock();





  imagem img;
  img = abrir_imagem("data/lena.jpg");
  filtro(&img, N);
  salvar_imagem("out.jpg", &img);
  liberar_imagem(&img);





  ct1 = clock();
  gettimeofday(&rt1, NULL);
  timersub(&rt1, &rt0, &drt);
  printf("real: %ld.%06ld \n", drt.tv_sec, drt.tv_usec);
  printf("user: %f \n", (double)(ct1-ct0)/CLOCKS_PER_SEC);
  printf("\n");


  return 0;
}
