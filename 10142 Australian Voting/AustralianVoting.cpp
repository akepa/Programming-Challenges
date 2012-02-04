#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;

#define DEBUG 0

int main(){
    string candidates[21];
    int votes[1000][21];
    int ncandidates;
    int nelectors;
    int ncases;
    bool flag, winner;
    char * tks;
    string aux;
    int k, l;
    float absolutev[21], percentv[21];
    bool isout[21];
    float max, min;
    
    getline(cin, aux);
    ncases = atoi(aux.c_str());
    getline(cin, aux); // blank line
    while(ncases){
                  
                  getline(cin, aux); // num electors
                  ncandidates = atoi(aux.c_str());
                  for(int i = 1; i <= ncandidates; i++)
                          getline(cin, candidates[i]);
                  flag = true;
                  k = 0, l = 0;
                  // votes
                  while(flag&&getline(cin, aux)){
                                 
                                  
                                  if(aux.empty()) flag = false;
                                  else{
                                       // parse input
                                       l = 0;
                                       istringstream iss(aux);
                                       string token;
                                      while(getline(iss, token, ' ')){
                                                         votes[k][l] = atoi(token.c_str());
                                                         l++;
                                       }   
                                  k++; 
                                  }
                                                 
                  }
                  nelectors = k;
                  // DEBUG INPUT
                  if(DEBUG){
                            cout << "Input: " << endl;
                            cout << "\tCandidates: " << endl;
                            for(int i = 1; i <= ncandidates; i++)
                                    cout << "\t\t" << candidates[i] << endl;
                            cout << "\tVotes: " << endl;
                            for(int i = 0; i < nelectors; i++){
                                    for(int j = 0; j < ncandidates; j++){
                                            cout << votes[i][j] << " ";
                                    }
                                    cout << endl;
                            }        
                  }
                  
                  // main program
                  winner = false;
                  for(int i = 1; i <=ncandidates; i++)
                          isout[i] = false; 
                  while(!winner){
                      // initialize
                      for(int i = 1; i <=ncandidates; i++){
                              absolutev[i] = 0;
                              percentv[i] = 0;               
                      }
                      
                      for(int i = 0; i < nelectors; i++){
                              flag = true;
                              for(int j = 0; flag&&(j < ncandidates); j++){ // recorre los votos
                                      if(isout[votes[i][j]]==false){ // el candidatos es válido
                                                                    absolutev[votes[i][j]]++;
                                                                    flag = false;                              
                                      }
                              }
                      }
                      max = -1;
                      min = nelectors+1;
                      winner = false;
                      // statistics
                      
                      for(int i = 1; i <=ncandidates; i++){
                              if(isout[i]==false){
                                  percentv[i] = absolutev[i]/nelectors;
                                  if(absolutev[i] > max) max = absolutev[i];
                                  if(absolutev[i] < min) min = absolutev[i];
                                  if(percentv[i] > 0.5){ 
                                                 winner = true;
                                                 cout << candidates[i] << endl;
                                  }  
                              }      
                      }
                      
                      if(DEBUG){
                                cout << "-----------------------" << endl;
                                cout << "min: " << min << " max: "<< max << endl;
                                cout << "-----------------------" << endl;
                                for(int i = 1; i <= ncandidates; i++){
                                        cout << candidates[i] << " " << absolutev[i] << " " << percentv[i] << endl;              
                                }
                                cout << "-----------------------" << endl;          
                      }
                      
                      if(!winner){

                                  if(max==min){ // remaining are tied

                                                for(int i = 1; i <=ncandidates; i++){
                                                        if(absolutev[i] == max) cout << candidates[i] << endl;        
                                                }
                                                winner = true;                          
                                  }
                                  else{
                                       for(int i = 1; i <=ncandidates; i++){ // eliminate candidates
                                               if(absolutev[i] == min) isout[i] = true;        
                                       }
                                  }                                            
                      }
                      
                  }
                  ncases--;               
                  if(ncases) cout << endl; // blank line between cases
    }    
    
    return 0;   
}
