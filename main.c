#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Experimento.h"

int main() {
	
	int tamano=100000000;
	int numero=30000;
	
	ListaNumeros *UnaListaNumeros;
	printf("COMIENZO DEL EXPERIMENTO 1 \n");
	UnaListaNumeros = CrearListaNumerosVacia(tamano);
	Experimento(UnaListaNumeros,tamano,numero); 
	printf("COMIENZO DEL EXPERIMENTO 2 \n"); 
	UnaListaNumeros = CrearListaNumerosVacia(tamano);
	ExperimentoDos(UnaListaNumeros,tamano,numero);
	printf("COMIENZO DEL EXPERIMENTO 3 \n"); 
	UnaListaNumeros = CrearListaNumerosVacia(tamano);
	ExperimentoTres(UnaListaNumeros,tamano,numero);

}
