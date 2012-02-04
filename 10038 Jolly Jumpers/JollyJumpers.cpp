#include <iostream>
#include <stdio.h>

using namespace std;

void jolly(){
     cout << "Jolly" << endl;     
}

void notJolly(){
     cout << "Not jolly" << endl;
}

int main(){
    int num, current, previous, pos, flag;
    bool set[3001];
    while(cin >> num){
              flag = true;
              // initialization
              for(int i = 1; i < num; i++) set[i] = false;
              
              cin >> previous;
              for(int i = 1; (i <num); i++){
                    cin >> current;
                    if(flag){ // consume input
                        if(current > previous)
                                   pos = current - previous;
                        else
                                   pos = previous - current;
                        if((pos >= num)||(set[pos] == true)){ // out of range [1..n-1] -> not jolly
                               flag = false;
                               notJolly();
                        }
                        else{
                             set[pos] = true;
                        }
                        previous = current; 
                    }     
              }
              if(flag) jolly();
    }
    
    return 0;   
}
