#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "busquedas.h"

struct timespec tInicio , tFin;
//////////////EXPERIMENTO UNO ///////////

int Experimento(ListaNumeros *UnaListaNumeros, int tamano,int numero){

	int lista,i,nuevo_tamano;
	double duracion_ns=0;
	char experimento1[30]="EXPERIMENTO 1";
	nuevo_tamano=0;
	
	FILE *archivo;
	archivo =fopen("datos.csv","a");
	if(archivo==NULL) return -1;
	fprintf(archivo,"\n");fprintf(archivo,"\n");
	fputs(experimento1,archivo);
	fprintf(archivo,"\n");fprintf(archivo,"\n");
	
	while(nuevo_tamano<tamano){
		clock_gettime(CLOCK_REALTIME,&tInicio);
		InsertarAlFinal(UnaListaNumeros,nuevo_tamano);
		lista=BuscarEnOrden(UnaListaNumeros,numero);
		lista=BuscarEnOrden(UnaListaNumeros,-1); //PERO CASO, EL NUMERO NO ESTÁ
		clock_gettime(CLOCK_REALTIME,&tFin);
		if ((tFin.tv_nsec-tInicio.tv_nsec)<0){ 
            
			duracion_ns = 1000000000+tFin.tv_nsec - tInicio.tv_nsec;
			printf("\n Duracion en Nanosegundos -> %f \n\n",duracion_ns);
    			
		}else{
            
			duracion_ns = tFin.tv_nsec - tInicio.tv_nsec;
			printf("\n Duracion en Nanosegundos -> %f \n\n",duracion_ns);
		
		}
		nuevo_tamano=nuevo_tamano+50;
		AumentaTamanoLista(UnaListaNumeros,nuevo_tamano);
		fprintf(archivo,"%f \n",duracion_ns);
		
	}
	fclose(archivo);	
	EliminarListaNumeros(UnaListaNumeros);
}

////////EXPERIMENTO DOS/////////////////
int ExperimentoDos(ListaNumeros *UnaListaNumeros, int tamano,int numero){
	
	int lista,i,nuevo_tamano;
	double duracion_ns=0;
	char experimento2[30]="EXPERIMENTO 2";
	nuevo_tamano=0;
	
	FILE *archivo;
	archivo =fopen("datos.csv","a");
	if(archivo==NULL) return -1;
	fprintf(archivo,"\n");fprintf(archivo,"\n");
	fputs(experimento2,archivo);
	fprintf(archivo,"\n");fprintf(archivo,"\n");
	
	while(nuevo_tamano<tamano){
		clock_gettime(CLOCK_REALTIME,&tInicio);
		InsertarEnOrden(UnaListaNumeros,nuevo_tamano);
		lista=BusquedaBinaria(UnaListaNumeros,tamano,numero);
		lista=BusquedaBinaria(UnaListaNumeros,tamano,-1);//PERO CASO EL NUMERO NO ESTA
		clock_gettime(CLOCK_REALTIME,&tFin);
		if ((tFin.tv_nsec-tInicio.tv_nsec)<0){ 
            
			duracion_ns = 1000000000+tFin.tv_nsec - tInicio.tv_nsec;
			printf("\n Duracion en Nanosegundos -> %f \n\n",duracion_ns);
    			
		}else{
            
			duracion_ns = tFin.tv_nsec - tInicio.tv_nsec;
			printf("\n Duracion en Nanosegundos -> %f \n\n",duracion_ns);
			
		}
		nuevo_tamano=nuevo_tamano+50;
		AumentaTamanoLista(UnaListaNumeros,nuevo_tamano);
		fprintf(archivo,"%f \n",duracion_ns);
	}
	fclose(archivo);
	EliminarListaNumeros(UnaListaNumeros);
}
///////////EXPERIMENTO TRES ////////////////////////
int ExperimentoTres(ListaNumeros *UnaListaNumeros, int tamano,int numero){
	
	int lista,i,nuevo_tamano;
	double duracion_ns;
	nuevo_tamano=0;
	char experimento3[30]="EXPERIMENTO 3";
	
	FILE *archivo;
	archivo =fopen("datos.csv","a");
	if(archivo==NULL) return -1;
	fprintf(archivo,"\n");fprintf(archivo,"\n");
	fputs(experimento3,archivo);
	fprintf(archivo,"\n");fprintf(archivo,"\n");
		
	while(nuevo_tamano<tamano){
		
		clock_gettime(CLOCK_REALTIME,&tInicio);
		InsertarAlFinalQuickSort(UnaListaNumeros,nuevo_tamano);
		lista=BusquedaBinaria(UnaListaNumeros,nuevo_tamano,numero);
		lista=BusquedaBinaria(UnaListaNumeros,nuevo_tamano,-1);//PERO CASO EL NUMERO NO ESTA
		clock_gettime(CLOCK_REALTIME,&tFin);
		if ((tFin.tv_nsec-tInicio.tv_nsec)<0){ 
            
			duracion_ns = 1000000000+tFin.tv_nsec - tInicio.tv_nsec;
			printf("\n Duracion en Nanosegundos -> %f \n\n",duracion_ns);
    			
		}else{
            
			duracion_ns = tFin.tv_nsec - tInicio.tv_nsec;
			printf("\n Duracion en Nanosegundos -> %f \n\n",duracion_ns);
			
		}
		nuevo_tamano=nuevo_tamano+50;
		AumentaTamanoLista(UnaListaNumeros,nuevo_tamano);
		fprintf(archivo,"%f \n",duracion_ns);
	}		
		EliminarListaNumeros(UnaListaNumeros);
}

