#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/**
* Codigo de gerador de cartelas de bingo e simulador de bingo
* Aviso: Windows Master Race
*/
int Q, V=0, E, NW=1, I, F, O[60], N[10], H[5];

struct cartela{
  int num[5][5];
  int s[5][5];
  int f;
  int sa;
}C[10];

void fazarray(int a, int b){
  int i, j = 0;
  for (i = a; i > b; i--){
    N[j] = i;
    j++;
  }
}

void arruma5(){
  int i, j, pos;
  for (j = 5; j > 0; j--) {
    pos = rand() % (7+j);
    while (N[pos] == 0){
      pos++;
    }
    H[j-1] = N[pos];
    N[pos] = 0;
  }
}

void bubblesort(){
  int i, j, aux, r;
  for(i=4; i >= 1; i--)
  {
    for(j=0; j < i ; j++)
    {
      if(H[j]>H[j+1])
      {
        aux = H[j];
        H[j] = H[j+1];
        H[j+1] = aux;
      }
    }
  }
}

void geracartelas(){
  int i, j, pos;
  srand (time(NULL));
  for (i = 0; i < Q; i++) {
    fazarray(12, 0);
    arruma5();
    bubblesort();
    for (j = 0; j < 5; j++) {
      C[i].num[j][0] = H[j];
    }
    fazarray(24, 12);
    arruma5();
    bubblesort();
    for (j = 0; j < 5; j++) {
      C[i].num[j][1] = H[j];
    }
    fazarray(36, 24);
    arruma5();
    bubblesort();
    for (j = 0; j < 5; j++) {
      C[i].num[j][2] = H[j];
    }
    fazarray(48, 36);
    arruma5();
    bubblesort();
    for (j = 0; j < 5; j++) {
      C[i].num[j][3] = H[j];
    }
    fazarray(60, 48);
    arruma5();
    bubblesort();
    for (j = 0; j < 5; j++) {
      C[i].num[j][4] = H[j];
      C[i].s[j][0] = 0;
      C[i].s[j][1] = 0;
      C[i].s[j][2] = 0;
      C[i].s[j][3] = 0;
      C[i].s[j][4] = 0;
    }
    C[i].f = 25;
    C[i].sa = 0;
  }
}

void imprimecartelas(){
  int i, j;
  for (i = 0; i < Q; i++) {
    printf("---------------------------%i - %i", i, C[i].f);
    if (C[i].sa == 1){
      printf(" S");
    }
    printf("\n");
    for (j = 0; j < 5; j++) {
      if (C[i].s[0][j] == 1){
        if (C[i].num[0][j] < 10){
          printf ("- %i- ", C[i].num[0][j]);
        } else {
          printf ("-%i- ", C[i].num[0][j]);
        }
      } else {
        if (C[i].num[0][j] < 10){
          printf ("  %i  ", C[i].num[0][j]);
        } else {
          printf (" %i  ", C[i].num[0][j]);
        }
      }
    }
    printf("\n");
    for (j = 0; j < 5; j++) {
      if (C[i].s[1][j] == 1){
        if (C[i].num[1][j] < 10){
          printf ("- %i- ", C[i].num[1][j]);
        } else {
          printf ("-%i- ", C[i].num[1][j]);
        }
      } else {
        if (C[i].num[1][j] < 10){
          printf ("  %i  ", C[i].num[1][j]);
        } else {
          printf (" %i  ", C[i].num[1][j]);
        }
      }
    }
    printf("\n");
    for (j = 0; j < 5; j++) {
      if (C[i].s[2][j] == 1){
        if (C[i].num[2][j] < 10){
          printf ("- %i- ", C[i].num[2][j]);
        } else {
          printf ("-%i- ", C[i].num[2][j]);
        }
      } else {
        if (C[i].num[2][j] < 10){
          printf ("  %i  ", C[i].num[2][j]);
        } else {
          printf (" %i  ", C[i].num[2][j]);
        }
      }
    }
    printf("\n");
    for (j = 0; j < 5; j++) {
      if (C[i].s[3][j] == 1){
        if (C[i].num[3][j] < 10){
          printf ("- %i- ", C[i].num[3][j]);
        } else {
          printf ("-%i- ", C[i].num[3][j]);
        }
      } else {
        if (C[i].num[3][j] < 10){
          printf ("  %i  ", C[i].num[3][j]);
        } else {
          printf (" %i  ", C[i].num[3][j]);
        }
      }
    }
    printf("\n");
    for (j = 0; j < 5; j++) {
      if (C[i].s[4][j] == 1){
        if (C[i].num[4][j] < 10){
          printf ("- %i- ", C[i].num[4][j]);
        } else {
          printf ("-%i- ", C[i].num[4][j]);
        }
      } else {
        if (C[i].num[4][j] < 10){
          printf ("  %i  ", C[i].num[4][j]);
        } else {
          printf (" %i  ", C[i].num[4][j]);
        }
      }
    }
    printf("\n");
  }
}

void shuffle() {
  srand (time(NULL));
  int i;
  for (i = 59; i > 0; i--) {
    int j = rand() % i;
    int t = O[j];
    O[j] = O[i];
    O[i] = t;
  }
  /*for (i = 0; i < 60; i++){
    printf("%i\n", O[i]);
  }*/
}

void fillO(){
  int i;
  for (i = 0; i < 60; i++){
    O[i] = i+1;
  }
  shuffle();
  shuffle();
  shuffle();
}

void sorteia(int J){
  int i, j, c;
  printf("Sorteado -> %i\n", O[J]);
  if (O[J] > 0 && O[J] <= 12)
    c = 0;
  if (O[J] > 12 && O[J]<= 24)
    c = 1;
  if (O[J] > 24 && O[J]<= 36)
    c = 2;
  if (O[J] > 36 && O[J]<= 48)
    c = 3;
  if (O[J] > 48 && O[J]<= 60)
    c = 4;
  for (i = 0; i < Q; i++) {
    for (j = 0; j < 5; j++) {
      if (C[i].num[j][c] == O[J]){
        C[i].s[j][c] = 1;
        C[i].f--;
        C[i].sa = 1;
      }
    }
  }
}

int main (){
  int i;
  printf("==========================================\n");
  printf(" Gerador e simulador de cartelas de Bingo\n");
  printf("==========================================\n");
  printf("Indique quantas cartelas deseja gerar:\n");
  scanf("%i", &Q);
  geracartelas();
  fillO();
  imprimecartelas();
  system("TIMEOUT 9 /nobreak");
  while (NW == 1){
    //system("TIMEOUT 2 /nobreak");
    system("CLS");
    sorteia(V);
    imprimecartelas();
    V++;
    for (i = 0; i < Q; i++) {
      C[i].sa = 0;
      if (C[i].f == 0){
        NW = 0;
      }
    }
  }
  printf("\nSorteados:\n");
  for (i = 0; i < V; i++){
    printf("%i ", O[i]);
  }
}
