#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<pthread.h>
#include <fstream>
#include <math.h>
#include <ctime>

using namespace std;
// de 0 a 125 000
void *potencia1(void *data){	// funcion que calcula la potencia 
	int *a = ((int *) data);	//convierte el valor a int
	int potencias[500000];//aqui se guardan los valores nuevos
	for (int j=0;j<125000;j++){
		potencias[j]=pow(a[j],2); //se eleva lso valores a la 2
		//cout<<potencias[j]<<" ";
	}
	//cout<<endl;
}
// de 125 000 a 250 000
void *potencia2(void *data){
	int *b = ((int *) data);
	int potencias[500000];
	for (int j=125000;j<250000;j++){
		potencias[j]=pow(b[j],2);
		//cout<<potencias[j]<<" ";
	}
	//cout<<endl;
}
//de 250 000 a 375 000
void *potencia3(void *data){
	int *c = ((int *) data);
	int potencias[500000];
	for (int j=250000;j<375000;j++){
		potencias[j]=pow(c[j],2);
		//cout<<potencias[j]<<" ";
	}
	//cout<<endl;
}
//de 375 000 a 500 000
void *potencia4(void *data){
	int *d = ((int *) data);
	int potencias[500000];
	for (int j=375000;j<500000;j++){
		potencias[j]=pow(d[j],2);
		//cout<<potencias[j]<<" ";
	}
	//cout<<endl;
}


int main(){
	
    unsigned t0,t1; //variables para medir el tiempo de ejecucion
    t0=clock();    //se inicia la medicion del tiempo
    
    
	const int tamano=500000;//tamaño del arreglo 
	int numeros[tamano];	
	
	srand(time(0));
	for (int i=0;i<tamano;i++){
		numeros[i]=1 + rand()% 10;	//se asignan valores random de 1 a 10 al arreglo
	}
	
	pthread_t proceso1;//declara el nombre del hilo
	pthread_create(&proceso1,NULL,&potencia1,&numeros);//crea el hilo 1
	
	pthread_t proceso2;
	pthread_create(&proceso2,NULL,&potencia2,&numeros);//hilo 2
	
	pthread_t proceso3;
	pthread_create(&proceso3,NULL,&potencia3,&numeros);//hilo3
	
	pthread_t proceso4;	
	pthread_create(&proceso4,NULL,&potencia4,&numeros);//hilo 4
	
	
	pthread_join(proceso1,NULL);//se unen al main
	pthread_join(proceso2,NULL);
	pthread_join(proceso3,NULL);
	pthread_join(proceso4,NULL);
	
	t1=clock();//termina de medir el tiempo de ejecucion
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout<< "tiempo de ejecucion: " << time << endl;
	
system ("pause");
return 0;
}
