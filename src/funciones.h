/**
*	\file funciones.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author Grupo4
*	\date 11-05-2019 13:43:00
*/

//Declaracion de constantes
#define TRUE  1
#define FALSE  0

//declaracion de la maquina
void maquina_estado(void);


//Declaracion de estados
#define 	ROJO	0
#define 	AMARILLO	1
#define 	VERDE	2
#define 	PAUSA	3

//Prototipos de los eventos
int Tick(void);
int ePulsador(void);
int Tick2(void);

//Prototipos de las acciones
void aVerdeOFF(void);
void aAmarilloOFF(void);
void aRojoOFF(void);
void aVerdeON(void);
void aAmarilloON(void);
void aRojoON(void);
void InitTimer(unsigned int);
void StopTimer(void);

