#include <stdio.h>
#include <stdlib.h>

char getNumber(char c);
int getTempValue(char *vec);

int main(){

      int tempValue;
      char input[5];
      
      printf("Digite o valor da temperatura: \n");
      scanf("%s", &input);
      tempValue = getTempValue(input);
      
      printf("%d", tempValue);

      return 0;
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