#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int x = 263;
long long int p = 1000000007;

struct table{
  char s[20];
  struct table *link;
};

int compute_hash(char str[],int m){
   int i=0,j;
   double hash = 0;
   long long int y = hash;
   for(i=0;i<strlen(str);i++){
   	  long long int power = 1;
   	  for(j=0;j<i;j++){
   	  	power *= x;
   	  	power = power % p;
   	  }
      hash += (str[i] * power); 
      y = hash;
      y = y % p;
      hash = y;
   }
   y = (y % p) % m;
   return y;
}

void add_to_hash(char str[],int m,struct table* hash[]){
  int key;
  struct table *temp,*curr;
  key = compute_hash(str,m);
  if (hash[key] == NULL){
     temp = (struct table*)malloc(sizeof(struct table));
     strcpy(temp->s,str);
     temp->link = NULL;
     hash[key] = temp;
     return;
  }
  else if (hash[key]->link == NULL){
  	if(!strcmp(hash[key]->s,str))
  		return;
  	temp = (struct table*)malloc(sizeof(struct table));
    strcpy(temp->s,str);
    temp->link = hash[key];
    hash[key] = temp;
    return;
  }
  else{
  	 curr = hash[key];
     while(curr != NULL){
     	if (!strcmp(curr->s,str)){
           return;
     	}
        curr = curr->link;
     }
     	temp = (struct table*)malloc(sizeof(struct table));
        strcpy(temp->s,str);
        temp->link = hash[key];
        hash[key] = temp;
  }
} 

void delete_from_hash(struct table* hash[],char str[],int m){
   int key,i;
   key = compute_hash(str,m);
   struct table *temp,*prev;
   prev = hash[key];
   if (prev == NULL)
   	 return;
   if (!strcmp(prev->s,str)){
   	 hash[key] = prev->link;
   	 return;
   }
   temp = prev->link;
   while(temp != NULL){
   	  if (!strcmp(temp->s,str)){
          prev->link = temp->link;
   	      free(temp);
   	      return;
      }
   	  prev = temp;
   	  temp = temp->link;
   }
}

int find(char str[],int m,struct table* hash[]){
   struct table *temp;
   int key;
   key = compute_hash(str,m);
   if (hash[key] == NULL){
     return 0;
   }
   else{
   	  temp = hash[key];
   	  while(temp != NULL){
   	  	 if (!strcmp(temp->s,str)){
   	  	 	return 1;
   	  	 }
   	  	 temp = temp -> link;
   	  }
   	  return 0;
   }
}

void check(int key,struct table* hash[]){
   if (hash[key] == NULL){
   	  printf("\n");
   	  return;
   }
   struct table *temp;
   temp = hash[key];
   while(temp != NULL){
   	  printf("%s ",temp->s);
   	  temp = temp->link;
   }
   printf("\n");
}

int main(){
	int i,m,n;
	scanf("%d",&m);
	scanf("%d",&n);
	char q1[n+1][20],q2[n+1][20];
	struct table *hash[m+1];
	for(i=0;i<m;i++){
		hash[i] = NULL;
	}
	for(i=0;i<n;i++){
      scanf("%s %s",q1[i],q2[i]);
	}
	for(i=0;i<n;i++){
		if(!strcmp(q1[i],"add")){
            add_to_hash(q2[i],m,hash);
		}
		else if(!strcmp(q1[i],"del")){
            delete_from_hash(hash,q2[i],m);
		}
		else if(!strcmp(q1[i],"check")){
           check(atoi(q2[i]),hash);
		}
		else if(!strcmp(q1[i],"find")){
           int y = find(q2[i],m,hash);
           if (y)
           	  printf("yes\n");
           else
           	  printf("no\n");
		}
	}
}