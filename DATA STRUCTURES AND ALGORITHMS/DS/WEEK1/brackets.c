#include <stdio.h>
#include <string.h>

char counter(char x){
	if (x == '}')
		return '{';
	if (x == ')')
		return '(';
	if (x == ']')
		return '[';
}

void push(char x,char stack[],int *top){
   *top = *top + 1;
   stack[*top] = x;
}

char pop(char stack[],int *top){
   if (*top == -1){
      return '#';
   }
   int k = *top;
   *top = *top - 1;
   return stack[k];
}

void brackets(char str[]){
  int i,temp,top = -1,index_last;
  char stack[strlen(str)];
  for(i=0;i<strlen(str);i++){
    if (str[i] == '(' || str[i] == '[' || str[i] == '{'){
    	if (top == -1){
    		index_last = i; 
    	}
        push(str[i],stack,&top);
    } 	 
    else if (str[i] == '}' || str[i] == ']' || str[i] == ')'){
       temp = pop(stack,&top);
       if (temp != counter(str[i])){
       	 printf("%d",i+1);
       	 return;
       }
    }
  } 
  if (top != -1)
  	printf("%d",index_last + 1);
  else
  	printf("Success");
}

int main(){
	char str[1000000];
	scanf("%s",str);
	brackets(str);
}