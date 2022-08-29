#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define r1 1
#define r2 7
int main() {
	int x,y,z,b,monedas,premio,elec;
	srand(time(NULL));
	b=0;
	premio=0;
	printf("\nEl precio para jugar son 25 monedas\n¿Desea jugar? 1 para si, 2 para no: ");
	scanf("%d", &elec);
	printf("\nIngresar cantidad de monedas: ");
	scanf("%d", &monedas);
	while(monedas>0&&b==0&&elec==1){
		monedas=monedas-25;
		premio=premio+25;
		x=rand()%(r2-r1+1)+r1;
		y=rand()%(r2-r1+1)+r1;
		z=rand()%(r2-r1+1)+r1;
		if(x==y&&y==z&&x==z){
			b=1;
			premio=premio*3;
			monedas=monedas+premio;
		}
			if(b==0){
			printf("\nX: %d\nY: %d\nZ: %d", x,y,z);
			printf("\nPerdiste. Tus monedas son: %d.\n¿deseas continuar? 1 para si, 2 para no: ", monedas);
			scanf("%d", &elec);
			}
	}
	
	if(b==1){
		printf("\nX: %d\nY: %d\nZ: %d", x,y,z);
		printf("\nGanaste!!.\nEl premio es de: %d.\nMonedas totales: %d.", premio,monedas);
	} else if(elec==2){
		printf("\nDecidiste no jugar, tus monedas: %d", monedas);
	}
	return 0;
}

