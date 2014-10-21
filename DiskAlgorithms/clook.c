#include<limits.h>
#include<stdio.h>
#include"look.h"


int CLOOK(int parked, int vector[],int size){

	int ready = 0,i,now=parked,j=-1,next=0, checked[100]={0},diff=INT_MAX,sum=0,temp;
	int tp=199;
	while(!ready){
		for(i=0;i<size;i++){
			//printf("now = %d vector = %d", now, vector[i]);
			if(vector[i]>=now && checked[i]==0 && abs(vector[i]-now)<diff){
				diff = abs(vector[i]-now);
				j=i;
			}
			//printf("\tdiff = %d\n",diff);
		}

		if(checked[j]==1 || j==-1){
			if(next==1){
				ready = 1;
			}else{
				for(i=0;i<size;i++){
					if(vector[i]<=tp){
						tp = vector[i];
						j=i;
					}
				}
				checked[j]=1;
				sum += abs(now-tp);
				now = tp;
				//printf("\nnow = %d \tsum = %d\n\n",now,sum);
				next=1;
			}
		}else{
			sum += diff;
			//printf("diff = %d och sum = %d\n\n",diff,sum);
			now = vector[j];
			diff = INT_MAX;
			checked[j]=1;
		}
	}
	return sum;
}
