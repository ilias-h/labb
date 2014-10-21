/* Program som simulerar olika algoritmer för diskarmsrörelser
   Se Silberschatz/Galvin/Gagne sid 493 och framåt */

/*   För alla funktionewr gäller:
     pre: size är storleken av vector och större än 0. size < 100.
     post: returnerar summan av rörelserna från parked genom hela vektorn */
#include <limits.h>
#include<stdio.h>
#include"scan.h"
#include"cscan.h"
#include"look.h"
#include"clook.h"

int FCFS(int parked, int vector[],int size){
    int i, now, sum;
    sum= abs(vector[0]-parked);
    now= vector[0];
    for(i=1;i<size;i++){
        sum= sum+abs(vector[i]-now);
        now= vector[i];
    }
    return sum;
}

int SSTF(int parked, int vector[],int size){
    int i, now, sum, beenthere[100]={0};    /* beenthere =0, vi har inte varit där än */
    int ready= 0, distance, nearest;
    sum=0;
    now= parked;
    while(!ready){
        /* look up the nearest among the ones we have not visited */
        distance= INT_MAX;
        for(i=0;i<size;i++){
                if(!beenthere[i]){
                        if(distance>abs(now-vector[i])){
                                distance=abs(now-vector[i]);
                                nearest= i;
                        }
                }
        }
        /* move */
        now= vector[nearest];
        //printf("visit %d\n",now);
        /* sum travel */
        sum= sum+ distance;
        /* set beenthere */
        beenthere[nearest]=1;
        /* ready yet? */
        ready= 1;
        for(i=0;i<size;i++){
                if(beenthere[i]==0){
                        ready= 0;
                }
        }
    }
    return sum;
}





main(){
	int v1[]={98,183,37,122,14,124,65,67};
	int v2[]={183,37,122,14,124,65,67,98};
	int v3[]={37,122,14,124,65,67,98,182};
	int v4[]={122,14,124,65,67,98,183,38};
	int v5[]={98,183,37,122,14,124,65,199};
	
	//printf("Kö 1 CLOOK = %d\n\n ", );
	printf("\n\n\n");
	printf("             ______________________________________________________________________\n");
	printf("            /                                                                     /|\n");
	printf("  _________/_____________________________________________________________________//\n");
	printf(" /         |__FCFS___|___SSTF___|___SCAN___|___C-SCAN___|___LOOK___|___C-LOOK___|//|  \n");
	printf("/________________________________________________________________________________/ |\n");
	printf("|___Kö_1___|___%d___|____%d___|____%d___|_____%d____|____%d___|_____%d____|  | \n",FCFS(53,v1,sizeof(v1)/sizeof(int)), SSTF(53,v1,sizeof(v1)/sizeof(int)), SCAN(53,v1,sizeof(v1)/sizeof(int)), CSCAN(53,v1,sizeof(v1)/sizeof(int)), LOOK(53,v1,sizeof(v1)/sizeof(int)), CLOOK(53,v1,sizeof(v1)/sizeof(int)));
	printf("|___Kö_2___|___%d___|____%d___|____%d___|_____%d____|____%d___|_____%d____|  |\n",FCFS(98,v2,sizeof(v2)/sizeof(int)), SSTF(98,v2,sizeof(v2)/sizeof(int)), SCAN(98,v2,sizeof(v2)/sizeof(int)), CSCAN(98,v2,sizeof(v2)/sizeof(int)), LOOK(98,v2,sizeof(v2)/sizeof(int)), CLOOK(98,v2,sizeof(v2)/sizeof(int)));
	printf("|___Kö_3___|___%d___|____%d___|____%d___|_____%d____|____%d___|_____%d____|  |\n",FCFS(183,v3,sizeof(v3)/sizeof(int)),SSTF(183,v3,sizeof(v3)/sizeof(int)),SCAN(183,v3,sizeof(v3)/sizeof(int)),CSCAN(183,v3,sizeof(v3)/sizeof(int)),LOOK(183,v3,sizeof(v3)/sizeof(int)),CLOOK(183,v3,sizeof(v3)/sizeof(int)));	
	printf("|___Kö_4___|___%d___|____%d___|____%d___|_____%d____|____%d___|_____%d____| / \n",FCFS(37,v4,sizeof(v4)/sizeof(int)), SSTF(37,v4,sizeof(v4)/sizeof(int)), SCAN(37,v4,sizeof(v4)/sizeof(int)), CSCAN(37,v4,sizeof(v4)/sizeof(int)), LOOK(37,v4,sizeof(v4)/sizeof(int)), CLOOK(37,v4,sizeof(v4)/sizeof(int)));
	printf("|___Kö_5___|___%d___|____%d___|____%d___|_____%d____|____%d___|_____%d____|/   \n\n\n\n",FCFS(122,v5,sizeof(v5)/sizeof(int)),SSTF(122,v5,sizeof(v5)/sizeof(int)),SCAN(122,v5,sizeof(v5)/sizeof(int)),CSCAN(122,v5,sizeof(v5)/sizeof(int)),LOOK(122,v5,sizeof(v5)/sizeof(int)),CLOOK(122,v5,sizeof(v5)/sizeof(int)));

	


}	
