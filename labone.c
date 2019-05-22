#include <stdio.h>
#include "datfile.h"

float sumTotal(const float a[][7][10]);
float sumWeekday(const float a[][7][10]);
float sumLane(const float a[][7][10], int n);

int main(int argc, char *argv[]){
	int sel;
	int lanenum;

	while(1){				
		fprintf(stderr,"MENU\n");
		fprintf(stderr,"------\n");
		fprintf(stderr,"\t1. Total for the entire year\n");
		fprintf(stderr,"\t2. Weekday totals for the year\n");
		fprintf(stderr,"\t3. Lane totals for the year\n");
		fprintf(stderr,"\t4. Exit\n");
		fprintf(stderr,"Enter Selection: ");
		sel = getchar(); 
		getchar(); //take away '\n' from sel input
		
		switch(sel){
			case '1' :
				fprintf(stderr,"%f\n",sumTotal(cashIN));		
				goto endwhile;				//end loop
			case '2' :
				fprintf(stderr,"%f\n",sumWeekday(cashIN));
				goto endwhile;
			case '3' :
				fprintf(stderr,"Enter lane number(1 - 7): ");
				scanf("%d",&lanenum);
				start: while(lanenum > 7 ){			// Error case: user input > 7
					fprintf(stderr,"Reenter lane number(1 - 7): ");  //reenter lane number
					scanf("%d",&lanenum);
					if(lanenum > 7){
						goto start;
					}else{}

				} 
				fprintf(stderr,"%f\n",sumLane(cashIN, lanenum));				
				goto endwhile;
			case '4' :
				goto endwhile;
			default :
				fprintf(stderr,"Error. Please select one of the cases 1 - 4\n");
				fprintf(stderr,"MENU\n");
				fprintf(stderr,"------\n");
				fprintf(stderr,"\t1. Total for the entire year\n");
				fprintf(stderr,"\t2. Weekday totals for the year\n");
				fprintf(stderr,"\t3. Lane totals for the year\n");
				fprintf(stderr,"\t4. Exit\n");
				fprintf(stderr,"Enter Selection: ");
				sel = getchar(); 
				getchar(); //take away '\n' from sel input					
				goto endwhile;				
				
		}
	endwhile: break;		//case to end loop from 'goto'
	}
	
	return 0;
}

//FUNCTIONS Defined
float sumTotal(const float a[][7][10]){ //Sum all three dimensions
	float tot = 0;			//total
	for(int i = 0; i < 12; i++){	//i continue through all 2d arrays
		for(int j = 0; j < 7; j++){		//j continue through all 7 rows
			for(int k = 0; k < 10; k++){	// k continue through all 10 columns
				tot+=a[i][j][k]; 			
			}			
		}
	}
	return tot;		//return sum total
}

float sumWeekday(const float a[][7][10]){
	float wkdaytot = 0;
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 10; k++){
				wkdaytot+=a[i][j][k];
			}
		}
	}
	return wkdaytot;
}

float sumLane(const float a[][7][10], int n){
	float lanetot = 0;
	for(int i = 0; i < 12; i++){
		for(int k = 0; k < 10; k++){
			lanetot+=a[i][n-1][k];
		}
	}
	return lanetot;
}
