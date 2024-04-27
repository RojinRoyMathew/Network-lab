#include<stdio.h>
#include<stdlib.h>
void main(){
int i,j,no,n,x,x1,x2;
i=1;j=1;
printf("Enter the no of frame to send:");
scanf("%d",&no);
printf("number of frame to send is :%d\n",no);
n=no;
while(n>0){
printf("sending frame is %d\n",i);
x=rand()%no;
if(x%no==0){
for(x2=1;x2<2;x2++){
printf("waiting for %d second\n",x2);
sleep(x2);
}
printf("sending frame is %d\n",i);
x=rand()%no;
}
printf("ack for frame is %d\n",j);
n=n-1;
i++;
j++;
}
printf("Ending of stop and wait protocol\n");
}
