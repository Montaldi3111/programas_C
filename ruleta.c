#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define r1 0
#define r2 100
int main() {
	char colorNum,colorBola;
	int num,bola,b,conta;
	srand(time(NULL));
	b=0;
	conta=0;
	printf("\nIngresar número: ");
	scanf("%d", &num);
	if(num%2==0&&num!=0){
		colorNum='R';
	} else if(num%2==1) {
		colorNum='N';
	} else if (num==0){
		colorNum='V';
	}
	while(b==0){
		bola=rand()%(r2-r1+1)+r1;
		if(bola%2==0&&bola!=0){
			colorBola='R';
		} else if(bola%2==1) {
			colorBola='N';
		} else if(bola==0) {
			colorBola='V';
		}
		if(num==bola&&colorNum==colorBola){
			b=1;
		}
		else{
			conta++;
		}
	}
	if(b==1){
		printf("\nGanaste!\nCantidad de veces que se jugó: %d\nNúmero elegido: %d\nColor del número: %c\nBola: %d\nColor bola: %c", conta,num,colorNum,bola,colorBola);
	}
	return 0;
}

