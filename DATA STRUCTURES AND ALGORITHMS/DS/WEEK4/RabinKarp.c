#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int x = 1;
long long int p = 1000000007;

int are_equal(char text[],char pattern[],long long int j){
	int i;
	for(i=0;i<strlen(pattern);i++){
       if(text[j++] == pattern[i]){
       	  continue;
       }
       else
       	 return 0;
    }
    return 1;
}


long long int compute_hash(char str[]){
	long long int hash = 0,i;
	for(i=strlen(str)-1;i>=0;i--){
		hash = (hash*x + str[i]) % p;
	}
    return hash;
}
// long long int compute_hash(char str[]){
//    int i=0,j;
//    double hash = 0;
//    long long int y = hash;
//    for(i=0;i<strlen(str);i++){
//    	  long long int power = 1;
//    	  for(j=0;j<i;j++){
//    	  	power *= x;
//    	  	power = power % p;
//    	  }
//       hash += (str[i] * power); 
//       y = hash;
//       y = y % p;
//       hash = y;
//    }
//    y = (y % p);
//    return y;
// }

void pre_compute_hash(char text[],char pattern[],long long int hash[]){
    long long int last = strlen(text) - strlen(pattern),i,j,c=0;
    char *str;
    str = (char*)(malloc(sizeof(char)*10000000));
    for(i=last;i<strlen(text);i++){
       str[c++] = text[i];
    }
    hash[last] = compute_hash(str);
    long long int power = 1;
   	for(j=0;j<strlen(pattern);j++){
   	  	power *= x;
   	  	power = power % p;
   	}
    for(i=last-1;i>=0;i--){
      hash[i] = ((x*hash[i+1]) % p) + text[i] - ((text[i + strlen(pattern)]*power) % p);  
      hash[i] = hash[i] % p;
    }
}

long long int RabinKarp(long long int ans[],char text[],char pattern[]){
    long long int *hash,w=0;
    long long int last = strlen(text) - strlen(pattern),i,j;
    hash = (long long int*)(malloc(sizeof(long long int)*100000000));
    pre_compute_hash(text,pattern,hash);
	long long int phash = compute_hash(pattern);
    for(i=0;i<=last;i++){
		if (phash != hash[i])
			continue;
		else{
           if(are_equal(text,pattern,i)){
           	  ans[w++] = i;
           }
		}
	}
    return w; 
}

int main(){
	char *pattern,*text;
	pattern = (char*)(malloc(sizeof(char)*100000000));
	text = (char*)(malloc(sizeof(char)*100000000));
	long long int *ans,i;
	ans = (long long int*)(malloc(sizeof(long long int)*1000000000));
	scanf("%s",pattern);
	scanf("%s",text);
	long long int h = RabinKarp(ans,text,pattern);	
	for(i=0;i<h;i++){
		printf("%lld ",ans[i]);
	}
}