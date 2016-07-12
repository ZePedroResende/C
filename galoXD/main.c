#include <stdio.h>
#include <stdlib.h>

int naoAcabado(char *t)
{
  int i = 0;
	for ( i = 0; i + 2 < 9; ) {
		if (t[i] == t[i + 1] && t[i] == t[i + 2] && t[i+1] == t[i+2])
			return 0;
		i +=3;
	}
	i = 0;
	for (i = 0; i + 6 < 9; i++) {
		if (t[i] == t[i + 3] && t[i] == t[i + 6] && t[i+3] == t[i+6])
			return 0;
        }

	if (t[0] == t[4] && t[0] == t[8] && t[4] == t[8])
		return 0;

	if (t[2] == t[4] && t[2] == t[6] && t[4] == t[6])
		return 0;

	return 1;
}



int caracter_valido(char jogada)
{
	switch (jogada) {
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return 1;
	default:{
		return -1;
        printf("jogada invalida\n");
    }
	}
}

int validaJogada(char jogada, char *t)
{
  int r = caracter_valido(jogada);

  if (r) {
    int a = jogada - '0';
    if ((t[a - 1] - '0') != a){
        r = -1;
        printf("jogada invalida ");
    }
  }

  return r;
}

void fazJogada(char *t, char jogada, int jogador)
{
	int jogad = jogada - '0';
	if (jogador == 0) t[jogad - 1] = 'O';
	else t[jogad - 1] = 'X';
}

int main()
{
  char t[9] = { '1','2','3','4','5','6','7','8','9' };
  char jogada;
  int jogador = 0;

  while (naoAcabado(t)) {

    printf("\t-|-|-|-|-\n");
    printf("\t-|%c|%c|%c|- \n", t[0], t[1], t[2]);
    printf("\t-|-|-|-|-\n");
    printf("\t-|%c|%c|%c|- \n", t[3], t[4], t[5]);
    printf("\t-|-|-|-|-\n");
    printf("\t-|%c|%c|%c|- \n", t[6], t[7], t[8]);
    printf("\t-|-|-|-|-\n");
    printf("------->jogador %d <-------\n",jogador);
    
    //jogada = getchar();
    scanf("%c",&jogada);
   if (jogada != '\n' ){ 
    while (validaJogada(jogada, t) != 1){
      scanf("%c",&jogada);
    }
	       
		
    fazJogada(t, jogada, jogador);
    if (jogador == 1) jogador = 0;
    else jogador = 1;
   }
  }

  if (jogador == 1) jogador = 0;
  else jogador = 1;
  
  printf("ganhou o jogador %d\n", jogador);
  return 0;
}
