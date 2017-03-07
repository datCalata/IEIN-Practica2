#include "comunicacion.h"
#include <stdio.h>
#include <stdlib.h>

#define MY_NODE 0x45


int recPacket(char msg[]){
	if(integridadPaquete(msg) == false){
		printf("Paquete Erroneo");
		return 0;
	}else if(checkNode(msg[0]) == false){
		printf("Nodo Incorrecto (Pq valido)");
		return 20;
	}else{
		return checkCmd(msg[1]);
	}
}

boolean integridadPaquete(char msg[]){
	//Probamos a calcular la longitud del array
	int longArray = longitudArray(msg);
	if(longArray != -1)
		return true;
	return false;
}

int longitudArray(char msg[]){
	int l = 0;
	while(true){
		l++;
		if(msg[l] == 0x0F && l>3 && l<=14)
			printf("Paquete Bueno, con final y longitud aceptable");
			return l;
		if(msg[l] == 0x0F && l <= 3){
			printf("Paquete Erroneo, demasiado corto para ser bueno");
			return -1;
		}
		if(l >= 14)
			printf("Paquete Erroneo, demasiado largo para ser bueno");
			return -1;
	}
}

boolean checkNode(char nodeMessage){
	if(nodeMessage == MY_NODE)
		return true;
	return false;
}

int checkCmd(char cmd){
	switch(cmd){
		case 't':
			return 11;
		case 'l':
			return 12;
		case 'p':
			return 13;
		case 'r':
			return 14;
		default:
			printf("No deberia estar aqui");
			return 20;
	}
}



