#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define r1 1
#define r2 11
int main() {
	char elec;
	int cartaJ,cartaC,cartasJ,cartasC,bandJ,bandC,bandJuego;
	bandJ=bandC=bandJuego=0;
	cartaJ=cartaC=0;
	cartasJ=cartasC=0;
	srand(time(NULL));
	cartaJ=rand()%(r2-r1+1)+r1;
	cartasJ=cartasJ+cartaJ;
	printf("\nTus cartas: %d\nTotal: %d", cartaJ, cartasJ);
	cartaC=rand()%(r2-r1+1)+r1;
	cartasC=cartasC+cartaC;
	printf("\nLas cartas del casino: %d", cartasC);
	while(bandJuego==0){
		/*Inicio del juego*/
		while(cartasJ<21&&bandJ==0){ /* Inicio jugador */
		printf("\nDesea pedir una carta? S para sí, N para no: ");
		scanf("%c", &elec);
		if(elec=='S'||elec=='s'){
			cartaJ=rand()%(r2-r1+1)+r1;
			cartasJ=cartasJ+cartaJ;
			printf("\nTus cartas: %d\nTotal: %d", cartaJ, cartasJ);
		} else if(elec=='N'||elec=='n'){
			bandJ=1;
			}
		if(cartasJ==21){
			bandJuego=1;
		}
		}/* Fin del jugador */
		printf("\nTus cartas: %d", cartasJ);
		
		while(bandC==0){ /* Inicia juego casino BandC=2 supera los 16 y corta el ciclo bandC=3 El casino pierde por tener más de 21 */
			cartaC=rand()%(r2-r1+1)+r1;
			cartasC=cartasC+cartaC;
			if(cartasC==21){
				bandC=1;
				bandJuego=1;
			} else if (cartasC>=16&&cartasC<21){
				bandC=2;
				bandJuego=1;
			} 
			else if(cartasC>21){
				bandC=3;
				bandJuego=1;
			}
		} /* Fin turno del casino */
		printf("\nCartas del casino: %d", cartasC);
	} /*Fin ciclo del juego*/
	/* Inicio comparacion cartas jugador con el casino */
	if(bandC==3){
		printf("\nGanaste, el casino tiene más de 21.");
	} else if(cartasJ==21){
		printf("\nBlackjack, ganaste");
	} else if(cartasJ>21){
		bandJ=2;
		printf("\nPierdes, tienes más de 21");
	} else if(bandC==2&&cartasJ<cartasC){
		printf("\nPierdes, el casino tiene mayor puntuación que usted");
	} else if(bandC==2&&cartasJ>cartasC){
		printf("\nGanaste, tienes más puntuación que el casino");
	}
	return 0;
}

