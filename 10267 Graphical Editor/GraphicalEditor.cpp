#include <iostream>
#include <stdio.h>

using namespace std;

/* NOTAS: Array de tamaño máximo definido: No usar memoria dinámica
          Formato MSDOS: Falso, tal cual se pone, se imprime
          Controlar la recursión si el nuevo color es igual que el anterior para la función de rellenado
*/

char display[251][251];
int cols = 0;
int rows = 0;



void opI(){
     // New image
     cin >> cols >> rows; 
     int i, j;
     for(i = 0; i < rows; i++){
             for(j = 0; j < cols; j++){
                      display[i][j] = 'O';
             }
             display[i][j] = '\0';
     }     
}

void opC(){
     // Clear
     int i, j;
     for(i = 0; i < rows; i++){
             for(j = 0; j < cols; j++){
                      display[i][j] = 'O';
             }
             display[i][j] = '\0';
     }     
}

void opL(){
     // Colour pixel
     char col;
     int x, y;
     cin >> x >> y >> col;
     x--;
     y--;
     display[y][x] = col;
}

void opS(){
     // Print Name  
     char name[100];
     cin >> name;
     cout << name << endl;
     for(int i = 0; i < rows; i++){
             cout << display[i] << endl;        
     }   
}

void opV(){
     int x, y1, y2;
     char c;
     
     cin >> x >> y1 >> y2 >> c;
     x--;
     y1--;
     y2--;
     if(y1 > y2){ // swap
           int aux = y2;
           y2 = y1;
           y1 = aux;      
     }
     
     if((0<=x)&&(x<cols)){
         if(y1 < 0) y1=0; // minimal
         // maximal
         if(y2 > rows-1) y2=rows-1;
         for(int i = y1; i <=y2; i++)
                 display[i][x] = c;
     }
}

void opH(){
     int x1, x2, y;
     char c;
     
     cin >> x1 >> x2 >> y >> c;
     y--;
     x1--;
     x2--;
     if(x1 > x2){ // swap
           int aux = x2;
           x2 = x1;
           x1 = aux;      
     }
     
     if((0<=y)&&(y<rows)){
         if(x1 < 0) x1=0; // minimal
         // maximal
         if(x2 > cols-1) x2=cols-1;
         for(int i = x1; i <=x2; i++)
                 display[y][i] = c;
     }
}

void opK(){
     int x1, x2, y1, y2;
     char c;
     cin >> x1 >> y1 >> x2 >> y2 >> c;
     x1--;
     x2--;
     y1--;
     y2--;
     if(x1 < 0) x1 = 0;
     if(y1 < 0) y1 = 0;
     if(y2 > rows-1) y2 = rows-1;
     if(x2 > cols-1) x2 = cols-1;
     for(int i = x1; i <= x2; i++){
             for(int j = y1; j <= y2; j++){
                     display[j][i] = c;
             }
     }
}

void opFill(int x, int y, int old, int col){
     if((0<=y)&&(y<rows)){
               if((0<=x)&&(x<cols)){
                                    if(display[y][x]==old){
                                                             display[y][x] = col;
                                                             opFill(x-1, y, old, col);
                                                             opFill(x+1, y, old, col); 
                                                             opFill(x, y-1, old, col); 
                                                             opFill(x, y+1, old, col);                          
                                    }                               
               }
     }     
}

void opF(){
     int x, y;
     char c;
     cin >> x >> y >> c;
     x--;
     y--;
     if((0<=y)&&(y<rows)){
               if((0<=x)&&(x<cols)){
                                    if(c != display[y][x]){
                                         opFill(x,y,display[y][x], c);
                                    }                     
               }
     }           
          
}

int main(){
 char command;
 while(cin >> command){
           switch(command){
                           
                           case 'I':
                                opI();
                                break;
                           case 'C':
                                opC();
                                break;                                               
                           case 'L':
                                opL();
                                break;                           
                           case 'V':
                                opV();
                                break;
                           case 'H':
                                opH();
                                break;
                           case 'K':
                                opK();
                                break;
                           case 'F':
                                opF();
                                break;
                           case 'S':
                                opS();
                                break;
                           case 'X': // end program
                                return 0;
                                break;
                                                                                                                                                                                                                                                         
           }          
           
 }   
 
 return 0;   
}
