/*
 * comunicaciones.h
 *
 *  Created on: 7 de mar. de 2017
 *      Author: jcala
 */

#ifndef COMUNICACION_H_
#define COMUNICACION_H_

typedef enum{true, false} boolean;


int recPacket(char msg[]);
boolean integridadPaquete(char msg[],int *devolver);
boolean checkNode(char nodeMessage);
int checkCmd(char cmd);
int longitudArray(char msg[],int *devolver);

#endif /* COMUNICACION_H_ */
