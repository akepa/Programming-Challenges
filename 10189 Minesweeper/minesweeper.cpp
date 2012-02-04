#include <iostream>
#include <stdio.h>

using namespace std;

char **array;

int main(){
 
    int counter =0;
    int rows, cols, nrows,ncols;
    char *input;
    while(cin >> rows >> cols){
              
              // Return
              if((rows==0)&&(cols==0)) return 0;
              
              nrows = rows+2;
              ncols = cols+2;
              counter++;
              
              // imprime enline para separar fields
              if(counter >1) cout << endl;
              
              // initialize the array
              //delete(array);
              array = new char*[nrows];
              for(int i = 0; i <nrows; i++)
                      array[i] = new char[cols];
              // initialize values
              for(int i = 1; i <=rows; i++)
                      for(int j = 1; j <=cols; j++)
                              array[i][j] = '0';
                              
              // input array
              input = new char[ncols+1];    
                              
              // main program
             for(int i = 1; i <=rows; i++){
                     cin >> input;
                     // cout << " - " << input;
                     for(int j = 1; j <=cols; j++){
                            // input = getchar();
                             //cout << input << endl;
                             if(input[j-1] == '*'){
                                      // Añade mina al tablero
                                      array[i][j] = '*';
                                      // Establece campos contiguos
                                      if(array[i-1][j-1] != '*') array[i-1][j-1]++;
                                      if(array[i][j-1] != '*') array[i][j-1]++; 
                                      if(array[i+1][j-1] != '*') array[i+1][j-1]++; 
                                      if(array[i-1][j] != '*') array[i-1][j]++; 
                                      if(array[i+1][j] != '*') array[i+1][j]++; 
                                      if(array[i-1][j+1] != '*') array[i-1][j+1]++; 
                                      if(array[i][j+1] != '*') array[i][j+1]++; 
                                      if(array[i+1][j+1] != '*') array[i+1][j+1]++;          
                             }        
                     }
                     getchar(); // para el \n
             }
             
             for(int i = 1; i <= rows; i++)
                     array[i][cols+1] = '\0';         
             
             // Imprime resultado
             cout << "Field #" << counter << ":" << endl;
    
             int x;
             for(x = 1; x <=rows; x++){
                     cout << array[x]+1 << endl; // corre una posición el puntero                
             }
            // cout << array[x]+1; // sin endl
    }
}
