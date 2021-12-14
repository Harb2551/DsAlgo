#include <stdio.h>

int count;

void enqueue(long long int queue[],int t,int pt,int *rear,int s){
	int temp = *rear;
	*rear = (*rear + 1)%s;
	 if (t <= queue[temp]){
		queue[*rear] = queue[temp] + pt;
	 }
	 else{
		queue[*rear] = t + pt;
	 }
	  count++;
}

int main(){
	int s,p,i,x=0,rear = 0,front = 0;
	scanf("%d %d",&s,&p);
	long long int queue[p];
	int q[p][2];
	long long int ans[p];
	for(i=0;i<p;i++){
		scanf("%d %d",&q[i][0],&q[i][1]);
	}
	count = 1;
	ans[x++] = q[0][0];
	queue[0] = q[0][0] + q[0][1];
	for(i=1;i<p;i++){
	  if (i==1){
	  	if (q[i][0]>queue[rear]){
	  		ans[x++] = q[i][0];
	  		enqueue(queue,q[i][0],q[i][1],&rear,s);
	  		continue;
	  	}
	  }

	  if (count == s){
		 if (queue[front]<=q[i][0]){
			front = (front + 1)%s;
			count--;
			if (q[i][0] > queue[rear]){
				ans[x++] = q[i][0];
				enqueue(queue,q[i][0],q[i][1],&rear,s);
				continue;
			}
			ans[x++] = queue[rear];
			enqueue(queue,q[i][0],q[i][1],&rear,s);
			}
		 else{
			ans[x++] = -1;
		 }
	  }
	  else{
		ans[x++] = queue[rear];
		enqueue(queue,q[i][0],q[i][1],&rear,s);
	  }
    }
	for(i=0;i<p;i++){
		printf("%d\n",ans[i]);
	}
}