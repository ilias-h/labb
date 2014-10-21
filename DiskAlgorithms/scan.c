#include<limits.h>
#include<stdio.h>
#include"scan.h"

int SCAN(int parked, int vector[],int size){
	int i, ready=0,now=parked,diff=INT_MAX,j,sum=0,checked[100]={0};

	while(!ready){
		for(i=0;i<size;i++){
			if(vector[i]<=now && abs(vector[i]-now)<diff && checked[i]==0){
				diff=abs(vector[i]-now);
				j=i;
			}
		}
		if(checked[j]==1){
			ready = 1;
		 	sum += abs(now-0);
			now = 0;
			diff=INT_MAX;
		}else{
			sum += diff;
			now = vector[j];
			diff=INT_MAX;
			checked[j]=1;
		}
	}
	while(ready){
		for(i=0;i<size;i++){
			if(vector[i]>now && checked[i]==0 && abs(vector[i]-now)<diff){
				diff=abs(vector[i]-now);
				j=i;
			}
		}
		if(checked[j]==1){
			ready = 0;
		}else{
			sum += diff;
			now = vector[j];
			diff=INT_MAX;
			checked[j]=1;
		}	
	}
	return sum;
}
