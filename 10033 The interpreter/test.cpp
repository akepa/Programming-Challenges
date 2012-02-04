#include <iostream>
#include <string>

#define DEBUG 0

using namespace std;

char intToChar(int i)
{
   return (char)(i + 48);
}

int wordToInt(int word[])
{
   int r = 0;
   r += word[2];
   r += word[1] * 10;
   r += word[0] * 100;
   return r;
}

void intToWord(int i, int word[])
{
   word[0] = i / 100;
   i = i - (i / 100) * 100;
   word[1] = i / 10;
   i = i - (i / 10) * 10;
   word[2] = i;
}

int main()
{
   int n;
   int pc;
   int instructionCount;
   int ram[1000][3];
   int registers[10][3];
   string sWord;
   int word[3];
   
   cin>>n;
   
   getline(cin, sWord);
   getline(cin, sWord);
   
   while(n--)
   {
      for(int i = 0; i < 1000; i++)
      {
         ram[i][0] = 0;
         ram[i][1] = 0;
         ram[i][2] = 0;
      }
      
      for(int i = 0; i < 10; i++)
      {
         registers[i][0] = 0;
         registers[i][1] = 0;
         registers[i][2] = 0;
      }
      
      for(int i = 0; i < 1000; i++)
      {
         sWord = "";
         getline(cin, sWord);
         if(sWord == "") break;
         
         ram[i][0] = (int)sWord[0] - 48;
         ram[i][1] = (int)sWord[1] - 48;
         ram[i][2] = (int)sWord[2] - 48;
      }
      
      pc = 0;
      instructionCount = 0;
      while(pc < 1000)
      {
         instructionCount++;
         word[0] = ram[pc][0];
         word[1] = ram[pc][1];
         word[2] = ram[pc][2];
         pc++;

         switch (word[0])
         {
            case 1:
               pc = 1000;
            break;
            case 2:
            {
               registers[word[1]][0] = 0;
               registers[word[1]][1] = 0;
               registers[word[1]][2] = word[2];
            }
            break;
            case 3:
            {
               int regval = wordToInt(registers[word[1]]);
               regval += word[2];
               regval %= 1000;
               intToWord(regval, registers[word[1]]);
            }
            break;
            case 4:
            {
               int regval = wordToInt(registers[word[1]]);
               regval *= (int)word[2];
               regval %= 1000;
               intToWord(regval, registers[word[1]]);
            }
            break;
            case 5:
            {
               registers[word[1]][0] = registers[word[2]][0];
               registers[word[1]][1] = registers[word[2]][1];
               registers[word[1]][2] = registers[word[2]][2];
            }
            break;
            case 6:
            {
               int regval = wordToInt(registers[word[2]]);
               regval += wordToInt(registers[word[1]]);
               regval %= 1000;
               intToWord(regval, registers[word[1]]);
            }
            break;
            case 7:
            {
               int regval = wordToInt(registers[word[2]]);
               regval *= wordToInt(registers[word[1]]);
               regval %= 1000;
               intToWord(regval, registers[word[1]]);               
            }
            break;
            case 8:
            {
               int regval = wordToInt(registers[word[2]]);
               registers[word[1]][0] = ram[regval][0];
               registers[word[1]][1] = ram[regval][1];
               registers[word[1]][2] = ram[regval][2];
            }
            break;
            case 9:
            {
               int regval = wordToInt(registers[word[2]]);
               ram[regval][0] = registers[word[1]][0];
               ram[regval][1] = registers[word[1]][1];
               ram[regval][2] = registers[word[1]][2];
            }
            break;
            case 0:
            {
               int regval = wordToInt(registers[word[2]]);
               if(regval)
                  pc = wordToInt(registers[word[1]]);
            }
            break;
         }
      }
      if(DEBUG)
      {
         cout<<"RAM"<<endl;
         for(int i = 0; i < 1000; i++)
         {
            cout<<ram[i][0];
            cout<<ram[i][1];
            cout<<ram[i][2];
            cout<<endl;
         }
       
         cout<<"regs"<<endl;
         for(int i = 0; i < 10; i++)
         {
            cout<<registers[i][0];
            cout<<registers[i][1];
            cout<<registers[i][2];
            cout<<endl;
         }
         cout<<"---------------------------------------"<<endl;
      }
      cout << instructionCount <<endl;
      if(n) cout<<endl;
   }
   
   return 0;
}
