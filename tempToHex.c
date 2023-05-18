#include <stdio.h>
#include <stdlib.h>

char getNumber(char c);
int getTempValue(char *vec);
void getUni(char *vec, int *uni);
void setBit(int *p, int index, int bitValue);
void setTemp(int *p, int value);
void bin(unsigned n);
void displayBin(int *mask);

int main(){

      int tempValue;
      char input[5];
      int sig = 0;
      int *uni = 0;
      int *mask = 0xA000;

      printf("Enter temperature: \n");
      scanf("%s", &input);

      sig = input[0] == '-' ? 1 : 0;
      getUni(input, &uni);
      tempValue = getTempValue(input);

      setBit(&mask, 9, sig);
      setBit(&mask, 8, uni);
      setTemp(&mask, tempValue);
      displayBin(mask);
      
      return 0;
}

void displayBin(int *mask){
      printf("\n--------------------------------------------------\n");
      printf("protocol    error s  u      temperature\n");
      bin(mask);
      printf("\n--------------------------------------------------\n");
      printf("\n%Xh\n", mask);
}

void bin(unsigned n){
    unsigned i;
    for (i = 1 << 15; i > 0; i = i / 2)
        (n & i) ? printf("1  ") : printf("0  ");
}

void setTemp(int *p, int value){
      *p ^= value;
}

void setBit(int *p, int index, int bitValue){
      *p ^= (bitValue << index);
}

void getUni(char *vec, int *uni){
      for(int i = 0; i<4; i++){
            if(vec[i] == 'F'){
                  *uni = 1;
            }
      }
}

int getTempValue(char *vec){
      char tempValue[2] = "00";
      int n;

      for(int i = 0; i<5; i++){
            char c = getNumber(vec[i]);
            if(c != '\0'){
                  tempValue[i] = c;
            }
      }
      n = atoi(tempValue);
      return n;
}

char getNumber(char n){
      char c;
      switch(n){
            case '0':
                  c = '0';
                  break;
            case '1':
                  c = '1';
                  break;
            case '2':
                  c = '2';
                  break;
            case '3':
                  c = '3';
                  break;
            case '4':
                  c = '4';
                  break;
            case '5':
                  c = '5';
                  break;
            case '6':
                  c = '6';
                  break;
            case '7':
                  c = '7';
                  break;
            case '8':
                  c = '8';
                  break;
            case '9':
                  c = '9';
                  break;
            default:
                  c = '\0';    
      }
      return c;
}
