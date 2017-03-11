#include "comunicacion.h"
#include <stdio.h>
#include <stdlib.h>

#define MY_NODE 0x45

int recPacket(char msg[]) {
	int devolver = 0;
	if (integridadPaquete(msg, &devolver) == false) {
		printf("Paquete Erroneo");
		return 0;
	}
	if(checkNode(msg[0]) == false){
		printf("No es para mi, pero es valido");
		return 20;
	}
	return devolver;
}

boolean integridadPaquete(char msg[], int *devolver) {
	//Probamos a calcular la longitud del array
	int longArray = longitudArray(msg);
	if (longArray != -1){
		//Comprovamos que la info en cmd tenga sentido
		*devolver = checkCmd(msg[1]);
		if (*devolver != -1)
			return true;
	}
	return false;
}

int longitudArray(char msg[]) {
	int l = 0;
	while (1) {
		if (msg[l] == 0x0F && l >= 3 && l <= 14) {
			printf("Paquete Bueno, con final y longitud aceptable( %d )", l+1);
			return l;
		}
		if (msg[l] == 0x0F && l < 3) {
			printf("Paquete Erroneo, demasiado corto para ser bueno");
			return -1;
		}
		if (l >= 14){
			printf("Paquete Erroneo, demasiado largo para ser bueno");
			return -1;
		}
		l++;
	}
}

boolean checkNode(char nodeMessage) {
	if (nodeMessage == MY_NODE)
		return true;
	return false;
}

int checkCmd(char cmd) {
	switch (cmd) {
	case 't':
		return 11;
	case 'l':
		return 12;
	case 'p':
		return 13;
	case 'r':
		return 14;
	default:
		printf("CMD Incorrecto");
		return -1;
	}
}

