#include <iostream>
#include <stdio.h>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int ram[1001][3];
int reg[10][3]; 


int getRam(int pos){
    return ram[pos][0]*100+ram[pos][1]*10+ram[pos][2];     
}

int getReg(int pos){
    return reg[pos][0]*100+reg[pos][1]*10+reg[pos][2];     
}

void setRam(int value, int pos){
     int v0 = value/100; 
     int v1 = (value/10)%10;
     int v2 = value%10;
     ram[pos][0] = v0;
     ram[pos][1] = v1;
     ram[pos][2] = v2;
}

void setReg(int value, int pos){
     int v0 = value/100; 
     int v1 = (value/10)%10;
     int v2 = value%10;
     reg[pos][0] = v0;
     reg[pos][1] = v1;
     reg[pos][2] = v2;  
}

int main(){
    int ncases, nwords, instructions, pc, param1, param2, command;
    bool flag, end;
    string aux;
    
    
    getline(cin, aux); // num cases
    ncases = atoi(aux.c_str());  // conversion to int
    
    getline(cin, aux); // blank line
    while(ncases){
              flag = true;
              nwords = 0;
              
              // initially, the registers are empty
              
              for(int i = 0; i < 10; i++)
                      for(int j = 0; j < 3; j++)
                              reg[i][j] = 0;
              
              // load ram
              while(flag&&getline(cin, aux)){
                         
                          stringstream ss;
                          if(aux.compare("")!=0){
                               ss << setfill('0') << setw(3) << aux;
                               
                               ram[nwords][0] = ss.str()[0]-'0';
                               ram[nwords][1] = ss.str()[1]-'0';
                               ram[nwords][2] = ss.str()[2]-'0';
                              // cout << ram[nwords][0] << ram[nwords][1] << ram[nwords][2] << endl;
                               nwords++;
                          }             
                          else
                              flag = false;
              }    
              // run program
              end = false;
              pc = 0; // program counter
              instructions = 0; // executed instructions
              while(!end){
                          command = ram[pc][0];
                          param1 = ram[pc][1]; 
                          param2 = ram[pc][2];
                         /* cout << "Value of PC: " << pc << endl;
                          cout << "Operation: " << command << endl;
                          cout << "Value of n: " << param1 << endl;
                          cout << "Value of d: " << param2 << endl;*/
                          
                          instructions++;
                          switch(command){
                                          case 1:
                                               end = true;
                                               break;
                                          case 2:
                                               setReg(param2, param1);
                                               pc++;
                                               break;                                          
                                          case 3:
                                               setReg((getReg(param1)+param2)%1000, param1);
                                               pc++;
                                               break; 
                                          case 4:
                                               setReg((getReg(param1)*param2)%1000, param1);
                                               pc++;
                                               break;
                                          case 5:
                                               setReg(getReg(param2), param1);
                                               pc++;
                                               break;                                          
                                          case 6:
                                               setReg((getReg(param1)+getReg(param2))%1000, param1);
                                               pc++;
                                               break;                                                
                                          case 7:
                                               setReg((getReg(param1)*getReg(param2))%1000, param1);
                                               pc++;
                                               break;
                                          case 8:
                                               setReg(getRam(getReg(param2)),param1);
                                               pc++;
                                               break;                                          
                                          case 9:
                                               setRam(getReg(param1),getReg(param2));
                                               pc++;
                                               break; 
                                          case 0:
                                               if(getReg(param2)==0) pc++;
                                               else pc = getReg(param1);
                                               break;                                                                                                                                                         
                          }
                      }
                          
                
              ncases--;
              cout << instructions << endl;
              if(ncases > 0) cout << endl;              
    }
    
    return 0;   
}
