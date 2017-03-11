#include "comunicacion.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	char a[5] = {0x45,'l','a',0x0F};

	printf("%d \n",recPacket(a));

	int result;

	char msg[11] = {0x45, 't', '0','0','0','0','0','0','0','0',0x0F};

	result = recPacket(msg);

	printf("recPacket devuelve %d\n", result);

	char msgA[11] = {0x55, 't', '0','0','0','0','0','0','0','0',0x0F};

	result = recPacket(msgA);
	printf("recPacket devuelve %d\n", result);


	return 0;
}
