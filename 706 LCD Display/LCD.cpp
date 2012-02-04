#include <iostream>
#include <stdio.h>

/* Solución: array del tamaño que va a tener el display, llenarlo de espacios en blanco y luego dibujar los números.
   Separar los números en patrones.
*/

using namespace std;

char **display;


/**************************************************************/
/**************************************************************/
/**************************************************************/
/**************************************************************/




void printU(int s, int order){
     int startX = order*(s+2)+order;
     int endX = (order+1)*(s+2)+order;
     
     for(int i = startX+1; i < endX-1; i++)
             display[0][i] = '-';
}

void printM(int s, int order){
     int startX = order*(s+2)+order;
     int endX = (order+1)*(s+2)+order;
     int startY = 0;
     int endY = 2*s+3;
     
     int middleY = endY/2;
     
     for(int i = startX+1; i < endX-1; i++)
             display[middleY][i] = '-';
}

void printD(int s, int order){
     int startX = order*(s+2)+order;
     int endX = (order+1)*(s+2)+order;
     int endY = 2*s+3-1;
     
     for(int i = startX+1; i < endX-1; i++)
             display[endY][i] = '-';     
}

void printUL(int s, int order){
     int startX = order*(s+2)+order;
     int endX = (order+1)*(s+2)+order;
     int startY = 1;
     int endY = 2*s+3;
     int middleY = endY/2;
     
     for(int i = startY; i < middleY; i++)
             display[i][startX] = '|';    
}

void printDL(int s, int order){
     int startX = order*(s+2)+order;
     int endX = (order+1)*(s+2)+order;
     int startY = 1;
     int endY = 2*s+3-1;
     int middleY = endY/2+1;
     
     for(int i = middleY; i < endY; i++)
             display[i][startX] = '|';     
}

void printUR(int s, int order){
     int startX = order*(s+2)+order;
     int endX = (order+1)*(s+2)-1+order;
     int startY = 1;
     int endY = 2*s+3;
     int middleY = endY/2;
     
     for(int i = startY; i < middleY; i++)
             display[i][endX] = '|';    
}

void printDR(int s, int order){
     int startX = order*(s+2)+order;
     int endX = (order+1)*(s+2)-1+order;
     int startY = 1;
     int endY = 2*s+3-1;
     int middleY = endY/2+1;
     
     for(int i = middleY; i < endY; i++)
             display[i][endX] = '|';     
}



/**************************************************************/
/**************************************************************/
/**************************************************************/
/**************************************************************/




void print1(int s, int order){
     printUR(s,order);
     printDR(s,order);
}

void print2(int s, int order){
     printU(s,order);
     printD(s,order);
     printM(s,order);
     printUR(s,order);
     printDL(s,order);
}

void print3(int s, int order){
     printU(s,order);
     printD(s,order);
     printM(s,order);
     printUR(s,order);
     printDR(s,order);
}

void print4(int s, int order){
     printM(s,order);
     printUL(s,order);
     printUR(s,order);
     printDR(s,order);
}

void print5(int s, int order){
     printU(s,order);
     printD(s,order);
     printM(s,order);
     printUL(s,order);
     printDR(s,order);
}

void print6(int s, int order){
     printU(s,order);
     printD(s,order);
     printM(s,order);
     printUL(s,order);
     printDL(s,order);
     printDR(s,order);
}

void print7(int s, int order){
     printUR(s,order);
     printDR(s,order);
     printU(s,order);
}

void print8(int s, int order){
     printU(s,order);
     printD(s,order);
     printM(s,order);
     printUL(s,order);
     printUR(s,order);
     printDL(s,order);
     printDR(s,order);
}

void print9(int s, int order){
     printU(s,order);
     printD(s,order);
     printM(s,order);
     printUL(s,order);
     printUR(s,order);
     printDR(s,order);
}

void print0(int s, int order){
     printU(s,order);
     printD(s,order);
     printUL(s,order);
     printUR(s,order);
     printDL(s,order);
     printDR(s,order);
}


/**************************************************************/
/**************************************************************/
/**************************************************************/
/**************************************************************/



int printcase(int s, int number){
     int order;
     if(number > 9){
               order = printcase(s, number/10)+1;          
     }
     else{
          order = 0;     
     }
     // Último número
     number = number%10;
     switch(number){
         case 0:
               print0(s, order);
               break;               
         case 1:
               print1(s, order);
               break;  
         case 2:
               print2(s, order);
               break; 
         case 3:
               print3(s, order);
               break;               
         case 4:
               print4(s, order);
               break;  
         case 5:
               print5(s, order);
               break;
         case 6:
               print6(s, order);
               break;               
         case 7:
               print7(s, order);
               break;  
         case 8:
               print8(s, order);
               break; 
         case 9:
               print9(s, order);
               break; 
         } 
         return order;      
}

int main(){
    int s, number;
    
    while(cin >> s >> number){
             if((s==0)&&(number==0)) return 0;
             
             int len = 1;
             int aux = number;
             while(aux > 9){
                          aux/=10;
                          len++;             
             }
             int lenX = len*(s+2)+len; // len extra para espacios en blanco y \0
             int lenY = 2*s+3;
             display = new char*[lenY]; // rows
             
             for(int i = 0; i < lenY; i++){
                     display[i] = new char[lenX]; // una columna más para el \0
                     display[i][lenX-1] = '\0'; 
             }
             for(int i = 0; i < lenY; i++){
                     for(int j = 0; j < lenX-1; j++){
                             display[i][j] = ' ';
                     }
             }
             printcase(s, number);
             for(int i = 0; i < lenY; i++){
                     cout << display[i] << endl;        
             }
             cout << endl;         
    }
    return 0;
}
