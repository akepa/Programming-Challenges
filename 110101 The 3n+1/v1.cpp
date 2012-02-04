#include <iostream>
#include <stdio.h>
using namespace std;

/*
Guarda los resultados intermedios, de forma que si para un número,su resultado ya está calculado lo usa, en vez de calcularlo otra vez.
Tamaño array muy grande. Como es con memoria estática, no hace falta inicializar a 0!!
IMPORTANTE: COMPROBAR SI I <J O J < I!!!

*/

#define INITIALSIZE  3000000 // si excede el array, no guarda los resultados!

static int resultados_intermedios[INITIALSIZE];

int current_size = INITIALSIZE;


// Caso
int calculo(int i){
    
    int resultado;
    if(i == 1) return 1;
    else{
         // Comprueba si está en el array
         if((i < current_size)&&(resultados_intermedios[i]))
                  return resultados_intermedios[i];
         else{ // NO está en el array de resultados intermedios
             if( i%2==0){ // es par
                 resultado = calculo(i/2)+1;
             }
             else{ // es impar
                 resultado = calculo(i*3+1)+1;
             }      
         }
         if(i < INITIALSIZE)
          resultados_intermedios[i] = resultado;
         return resultado;    
    }
}

// Caso leído por entrada estandar
int maximo(int i, int j){
    int currentMax = -1;
    for(int x = i; x <= j; x++){
            int res = calculo(x);
            if(res > currentMax)
                  currentMax = res;        
    }
    return currentMax;
}


int main(){
    // Inicializa vector
  /*  
    resultados_intermedios = new int[current_size];
    calculado = new bool[current_size];
    for(int i = 0; i < current_size; i++){
            calculado[i] = false;       
    }*/
    int i, j;
    // Casos
    int count = 0;
    while(cin >> i >> j){
              //if(count > 0) cout << endl;
              if(i < j)
                   cout << i << " " << j << " " << maximo(i,j) << endl;
              else 
                   cout << i << " " << j << " " << maximo(j,i) << endl;
            //  count++;                       
    } 
    return 0;  
}
