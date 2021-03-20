#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<pthread.h>
#include <fstream>
#include <math.h>
#include <ctime>

using namespace std;

void *potencia1(void *data){	// funcion que calcula la potencia 
	int *a = ((int *) data);	// convierte el valor a int
	int potencias[500000];  //se guardan los valores aqui
	for (int j=0;j<500000;j++){
		potencias[j]=pow(a[j],2);//eleva los datos a la 2
		
	}
	
}


int main(){
	
    unsigned t0,t1; //variables para medir el tiempo de ejecucion
    t0=clock();    //inicia la medicion del tiempo
    
    
	const int tamano=500000; // numero de datos en el arreglo
	int numeros[tamano];	
	
	srand(time(0));
	for (int i=0;i<tamano;i++){
		numeros[i]=1 + rand()% 10;	//asigna valores random entre 1 y 10 al arreglo
	}
	
	pthread_t proceso1; //declara el nombre del hilo
	pthread_create(&proceso1,NULL,&potencia1,&numeros);//crea el hilo
	pthread_join(proceso1,NULL);//lo une al main
	
	
	t1=clock();// termina de medir el tiempo
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout<< "tiempo de ejecucion: " << time << endl;//imprime el tiempo
	
system ("pause");
return 0;
}
