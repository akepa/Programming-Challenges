#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip>
/*
NOTAS: No existe función de redondeo para doubles. Para floats, existe floorf que quita los decimales
iomanip.h necesaria para setprecision de los floats
al hacer el redondeo, hay que calcular 2 cosas, por la pérdida de precisión.

*/

using namespace std;

double round(double num){
       double aux2 = num*100.00; // de esta forma depende todo del 3º decimal
       int aux = aux2; // pasa a entero para coger solo 2 decimales
       double aux3 = aux2-aux;
       if(aux3 < 0.5) // el redondeo se hace dependiendo del tercer decimal
               return ((double)aux)/100; // redondeo para abajo
       else
           return ((double)(aux+1))/100; // redondeo para arriba
}

int main(){
    int input;
    int aux;
    double money[1000];
    double average;
    double exchangeUP;
    double exchangeDOWN;
    while(1){
            // header
            cin >> input;
            // end program
            if(input == 0) return 0;
            
            // read data && calculate average
            average = 0.0;
            
            for(int i = 0; i < input; i++){
                    cin >> money[i];
                    average+=money[i];        
            }
            average/=input;
            //average = floorf(average*100)/100; // round to 2 decimals
            average=round(average);
            exchangeUP = 0.0;
            exchangeDOWN = 0.0;
            // esto se hace debido a la pérdida de precisión. ambos exchanges serán iguales, o uno será 0.01 mayor que el otro.
            for(int i = 0 ; i < input; i++){
                    if(money[i] < average){
                                exchangeUP+=(average-money[i]);            
                    }
                    else{
                                exchangeDOWN+=(money[i]-average);
                    }                                 
            }
            cout << fixed;
            cout << setprecision(2) << "$" << min(exchangeDOWN,exchangeUP) << endl;     
    }
    
 return 0;   
}
