#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Experimento.h"

int main() {
	
	int tamano=20000;
	int numero=30648;
	
	ListaNumeros *UnaListaNumeros;
	printf("COMIENZO DEL EXPERIMENTO 1");
	UnaListaNumeros = CrearListaNumerosVacia(tamano);
	Experimento(UnaListaNumeros,tamano,numero); 
	printf("COMIENZO DEL EXPERIMENTO 2"); 
	UnaListaNumeros = CrearListaNumerosVacia(tamano);
	ExperimentoDos(UnaListaNumeros,tamano,numero);
	printf("COMIENZO DEL EXPERIMENTO 3"); 
	UnaListaNumeros = CrearListaNumerosVacia(tamano);
	ExperimentoTres(UnaListaNumeros, tamano,numero);

}

