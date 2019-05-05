typedef struct Lista{
	
	int cantidad_maxima;
	int cantidad_actual;
	int *arreglo;
	
}ListaNumeros;

ListaNumeros *CrearListaNumerosVacia(int tamano){
	
	ListaNumeros *UnaListaNumeros;
	
	UnaListaNumeros = malloc(sizeof(ListaNumeros));  //(Primero se pide memoria a la Lista)
	UnaListaNumeros->cantidad_actual=0;
	UnaListaNumeros->cantidad_maxima=tamano;
	UnaListaNumeros->arreglo = malloc(sizeof(int)*tamano);  //(Y se termina pidiendo memoria esta vez al arreglo con un determinado tamaño)

	return(UnaListaNumeros); //revisar
	
}

ListaNumeros *CrearListaLLena(int tamano, int max){
		
	  ListaNumeros *UnaListaNumeros = CrearListaNumerosVacia(tamano);  //Inicializamos UnaListaNumeros llamando la funcion CrearListaNumerosVacia
	  int i;
	  for(i=0;i < UnaListaNumeros->cantidad_maxima; i++){
	  	UnaListaNumeros->arreglo[i]=rand()%(max+1);
	  }
	   UnaListaNumeros->cantidad_actual = UnaListaNumeros->cantidad_maxima;
	   return(UnaListaNumeros); //revisar

}

int AumentaTamanoLista(ListaNumeros *UnaListaNumeros,int nuevo_tamano){
	
	if(UnaListaNumeros == NULL) return -1;
	if(nuevo_tamano <= UnaListaNumeros->cantidad_maxima) return 0;
	int *aux_lista = malloc(sizeof(int)*nuevo_tamano);
	if(aux_lista == NULL) return -1;
	int i;
	for(i=0;i<UnaListaNumeros->cantidad_actual;i++){
		aux_lista[i] = UnaListaNumeros->arreglo[i];
	}
	free(UnaListaNumeros->arreglo);
	UnaListaNumeros->arreglo=aux_lista;
	UnaListaNumeros->cantidad_maxima=nuevo_tamano;
	
	return 1;
	
}

int EliminarListaNumeros(ListaNumeros *UnaListaNumeros){
	
		UnaListaNumeros->cantidad_actual=0;
		free(UnaListaNumeros->arreglo);
		free(UnaListaNumeros);
		
		return 1;
}
