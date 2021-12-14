#include <stdio.h>
#include <conio.h>

struct segment{
	int start;
	int end;
};

void bubble_sort(struct segment s[],int size){
     int i,j;
     for (i=0;i<size-1;i++){
         for (j=0;j<size-i-1;j++){
         	if (s[j].end>s[j+1].end){
         		struct segment temp = s[j];
         		s[j] = s[j+1];
         		s[j+1] = temp;
         		}
         }
     }
}

void points(struct segment s[],int size){
	int p[size],index = 0,i,j,point;
	point = s[0].end;
	p[index] = point;
    for (i=1;i<size;i++){
    	if (s[i].start > point || s[i].end < point){
    		index++;
            point = s[i].end;
            p[index] = point;
           }
    	}
    printf("%d\n",index+1);
    for(i=0;i<=index;i++){
    	printf("%d ",p[i]);
    }
}

int main(){
	int size,i;
	scanf("%d",&size);
	struct segment s[size];
	for(i=0;i<size;i++){
		scanf("\n%d %d",&s[i].start,&s[i].end);
	}
	bubble_sort(s,size);
    points(s,size);
    getch();
}