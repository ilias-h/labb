#include<limits.h>
#include<stdio.h>
#include"cscan.h"

int CSCAN(int parked, int vector[],int size){

	int ready = 0,i,now=parked,j=-1,next=0, checked[100]={0}, diff=INT_MAX,sum=0;

	while(!ready){
		for(i=0;i<size;i++){
			
			if(vector[i]>=now && checked[i]==0 && abs(vector[i]-now)<diff){
				diff = abs(vector[i]-now);
				j=i;
			}
		}
		if(checked[j]==1 || j==-1){
			if(next==1)
				ready = 1;
			else{
				sum += abs(now-199);
				sum += 199;
				now=0;
				next=1;
			}
		}else{
			sum += diff;
			now = vector[j];
			diff = INT_MAX;
			checked[j]=1;
		}
	}
	return sum;
}
