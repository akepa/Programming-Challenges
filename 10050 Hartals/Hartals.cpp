#include <iostream>
#include <stdio.h>

using namespace std;

#define MAXHARTALS 3651

int main(){
    
    int testcases, days, parties, hparam, nhartals;
    int hartals[MAXHARTALS];
    
    cin >> testcases;
    
    for(int i = 0; i < testcases; i++){ // for each tescase
                    cin >> days;
                    cin >> parties;
                    
                    // initialize array
                    for(int j = 0; j < MAXHARTALS; j++){
                            hartals[j] = 0;
                    }
                    
                    for(int j = 0; j < parties; j++){ // for each partie
                            cin >> hparam;
                            for(int k = hparam; k <= days; k+=hparam)
                                    hartals[k]++;
                    }
                    // count hartals
                    nhartals = 0;
                    for(int j = 1; j <= days; j+=7){
                            if((days-j+1)>=5){ // at least 5 days more
                                               for(int k = j; k < j+5; k++){
                                                     if(hartals[k]) nhartals++;      
                                               }                  
                            }
                            else{ // less than 5days more
                                 for(int k = j; k <= days; k++){
                                       if(hartals[k]) nhartals++;     
                                 }      
                            }        
                    }
                    cout << nhartals << endl;        
    }
    
    return 0;   
}
