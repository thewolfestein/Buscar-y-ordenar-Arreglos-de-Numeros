#include "lista.h"
// (1) Insertar al final y buscar secuencialmente:

int InsertarAlFinal(ListaNumeros *UnaListaNumeros,int nuevo_tamano){
	
	int i;
	int MAX=50000;
	if(UnaListaNumeros==NULL) return -1;
	for(i=nuevo_tamano;i>=0; i--){ 
		UnaListaNumeros->arreglo[i]=rand()%(MAX+1);	
		UnaListaNumeros->cantidad_actual++;
	}
	UnaListaNumeros->cantidad_actual=UnaListaNumeros->cantidad_maxima;
	
	return 1;
	
}

int BuscarEnOrden(ListaNumeros *UnaListaNumeros,int numero){
	
	int i;
	for(i=0;i<UnaListaNumeros->cantidad_maxima;i++){	
		if(UnaListaNumeros->arreglo[i]==numero){
			return numero;
		}
	}
	
	return 0 ;
	
}

// (2) Insertar en orden y usar búsqueda binaria:

int InsertarEnOrden(ListaNumeros *UnaListaNumeros,int nuevo_tamano){
	
	int i,j,x,aux;
	int MAX=50000;
	for(x=0;x<=nuevo_tamano;x++){
	  	UnaListaNumeros->arreglo[x]=rand()%(MAX+1);	
	  	UnaListaNumeros->cantidad_actual++;
	}
	//Ordenar lista ascendentemente (Necesario para utilizar la búsqueda binaria)
	for(i=0;i<=nuevo_tamano;i++){	
		for(j=i+1;j<nuevo_tamano;j++){
			if(UnaListaNumeros->arreglo[j]<UnaListaNumeros->arreglo[i]){
				aux=UnaListaNumeros->arreglo[j];
				UnaListaNumeros->arreglo[j]=UnaListaNumeros->arreglo[i];
				UnaListaNumeros->arreglo[i]=aux;
			}
		} 	
	}

	UnaListaNumeros->cantidad_actual=UnaListaNumeros->cantidad_maxima;
	
	return 1;
	
}

int BusquedaBinaria(ListaNumeros *UnaListaNumeros, int nuevo_tamano,int numero){
	
	int indice,minimo,maximo;
	minimo=0;
	maximo=nuevo_tamano;
	indice=((minimo+maximo)/2);
	
	while(maximo>minimo){	
		if(UnaListaNumeros->arreglo[indice]<numero){
			minimo=indice+1;
			indice=(((minimo)+maximo)/2);	
		}else{
				if(UnaListaNumeros->arreglo[indice]>numero){	
					maximo=indice-1;
					indice=((minimo+maximo)/2);
				}else{
						if(UnaListaNumeros->arreglo[indice]==numero){
							return numero;
						}
				}	
		}
	}
	return 0;
}

// (3) Insertar siempre al final, ordenar con 'quicksort' después de cada inserción y usar búsqueda binaria:


int Comparar(const void * a, const void * b){
	int x,y;
	x= *(int *) a;
	y= *(int *) b;
	if (x < y)
	return -1;
		if (x == y)
		return 0;
	return 1;	
	
}

int InsertarAlFinalQuickSort(ListaNumeros *UnaListaNumeros,int nuevo_tamano){
	
	int i,a,b;
	int MAX=50000;
	for(i=nuevo_tamano;i>=0; i--){ 
		UnaListaNumeros->arreglo[i]=rand()%(MAX+1);	
		qsort(UnaListaNumeros->arreglo,nuevo_tamano, sizeof(int),&Comparar);
		UnaListaNumeros->cantidad_actual++;
	}
	
	UnaListaNumeros->cantidad_actual=UnaListaNumeros->cantidad_maxima;
	
	return 1;
	
}




	


