#include <iostream>

using namespace std;

char **array;

int main(){
 
    int counter =0;
    int rows, cols, nrows,ncols;
    char input;
    while(cin >> rows >> cols){
              
              // Return
              if((rows==0)&&(cols==0)) return 0;
              
              nrows = rows+2;
              ncols = cols+2;
              counter++;
              // initialize the array
              //delete(array);
              array = new char*[nrows];
              for(int i = 0; i <nrows; i++)
                      array[i] = new char[cols];
              // initialize values
              for(int i = 1; i <=rows; i++)
                      for(int j = 1; j <=cols; j++)
                              array[i][j] = '0';
              // main program
              cout << "llega" << endl;
             for(int i = 1; i <=rows; i++){
                     for(int j = 1; j <=cols; j++){
                             input = getchar();
                             if(input == '*'){
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
             
             // Imprime resultado
             cout << "Field #" << counter << ":" << endl;
             
             for(int i = 1; i <=rows; i++){
                     cout << array[i];                
             }
    }
}
