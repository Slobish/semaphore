/**
*	\file funciones.c
*	\brief 
*	\details Descripcion detallada del archivo
*	\author Grupo4
*	\date 11-05-2019 13:43:00
*/



#include "funciones.h"
#include "bibliotecaInfoII.h"

//Implementacion Switch-Case

/**
*	\fn void maquina_estado()
*	\brief Implementacion Switch-Case
*	\details 
*	\author Grupo4
*	\date 11-05-2019 13:43:00
*/
#define TIMEOUT_EVENT 1

int timeout = 0;
void maquina_estado()
{
		static int estado = ROJO;
		static int yendo_a = VERDE;
		InitTimer(30);
		
		switch(estado)
		{
			case ROJO:
			
				if((Tick()==TRUE))
				{
					InitTimer(5);
					aRojoOFF();
					aAmarilloON();

					estado = AMARILLO;
					yendo_a = VERDE;
		
				}
				if((ePulsador()==TRUE))
				{
					StopTimer();
					estado = PAUSA;
		
				}

				break;
			
			case AMARILLO:
			
				if(Tick()==TRUE && yendo_a == VERDE)
				{
					aAmarilloOFF();
					aVerdeON();
					InitTimer(20);

					estado = VERDE;
		
				}
				if((ePulsador()==TRUE))
				{
					StopTimer();
					estado = PAUSA;
		
				}
				if(Tick()==TRUE && yendo_a == ROJO)
				{
					aAmarilloOFF();
					aRojoON();
					InitTimer(30);

					estado = ROJO;
		
				}

				break;
			
			case VERDE:
			
				if((ePulsador()==TRUE))
				{
					StopTimer();
					estado = PAUSA;
		
				}
				if((Tick()==TRUE))
				{
					aAmarilloON();
					aVerdeOFF();
					InitTimer(5);

					estado = AMARILLO;
					yendo_a = ROJO;
		
				}

				break;
			
			case PAUSA:
			
				if((ePulsador()==TRUE))
				{
					aVerdeOFF();
					aAmarilloOFF();
					aRojoON();
					InitTimer(30);

					estado = ROJO;
		
				}

				break;
			
			default: estado = ROJO;
		}


}

//Funciones asociadas a los eventos

/**
*	\fn int Tick(void)
*	\brief Resumen
*	\details Detalles
*	\author Grupo4
*	\date 11-05-2019 13:43:00
*/
int Tick(void)
{
	if (timeout){
		timeout=0;
		return 1;
	}
	else return 0;
}

/**
*	\fn int ePulsador(void)
*	\brief Resumen
*	\details Detalles
*	\author Grupo4
*	\date 11-05-2019 13:43:00
*/
int ePulsador(void)
{
	return GetKey() == 1 ? 1 : 0;
}

/**
*	\fn int Tick2(void)
*	\brief Resumen
*	\details Detalles
*	\author Grupo4
*	\date 11-05-2019 13:43:00
*/

//Funciones asociadas a las acciones

/**
*	\fn void aVerdeOFF(void)
*	\brief Resumen
*	\details Detalles
*	\author Grupo4
*	\date 11-05-2019 13:43:00
*/
void aVerdeOFF(void)
{
	Relays(2, 0);
}

/**
*	\fn void aAmarilloOFF(void)
*	\brief Resumen
*	\details Detalles
*	\author Grupo4
*	\date 11-05-2019 13:43:00
*/
void aAmarilloOFF(void)
{
	Relays(1, 0);
}

/**
*	\fn void aRojoOFF(void)
*	\brief Resumen
*	\details Detalles
*	\author Grupo4
*	\date 11-05-2019 13:43:00
*/
void aRojoOFF(void)
{
	Relays(0, 0);
}

/**
*	\fn void aVerdeON(void)
*	\brief Resumen
*	\details Detalles
*	\author Grupo4
*	\date 11-05-2019 13:43:00
*/
void aVerdeON(void)
{
	Relays(2, 1);
}

/**
*	\fn void aAmarilloON(void)
*	\brief Resumen
*	\details Detalles
*	\author Grupo4
*	\date 11-05-2019 13:43:00
*/
void aAmarilloON(void)
{
	Relays(1, 1);
}

/**
*	\fn void aRojoON(void)
*	\brief Resumen
*	\details Detalles
*	\author Grupo4
*	\date 11-05-2019 13:43:00
*/
void aRojoON(void)
{
	Relays(0, 1);
}

void raiseTimeout(void) {
	timeout = 1;
}
void InitTimer(unsigned int segundos)
{
	void (*foo)(int) = raiseTimeout;
	TimerStart(TIMEOUT_EVENT, segundos, foo, SEG);
}

void StopTimer(void) {
	TimerStop(TIMEOUT_EVENT);
}
