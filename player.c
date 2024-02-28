#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct player {
    char pname[30];				  
    int jer_no;						 
    int wickets;				  
    int runs;		    
    int matches;				   
} player;																				//30+4+20+8+4=Total 66B

void display(player* , int );
void update(player* , int );
void add(player*,int*);
void search(player* ,int);
void top_3(player* , int);
void remove_player(player*,int*);
//void store(player* , int* );

void main() {
	    int n=0;
	 
    //    printf("Enter number of players:");
	//    scanf("%d", &n);
	
	    player p[100]; 
	    store(p,&n);
		
    printf("\n|----Menu----|\n");
	
    int choice;
    do{
    	printf("\nEnter choice:\n\n 1.Display\n\n 2.Update\n\n 3.Add\n\n 4.Search\n\n 5.TOP 3 players\n\n 6.Delete \n\n 7.Quit \n\n");
    	scanf(" %d", &choice);
			
		    switch (choice) {		
		        
		        case 1:
		        	{
		            printf("You selected option 1.\n");
		            display(p,n);
		        	}
		            break;
		        case 2:
		            printf("You selected option 2.\n");
		            update(p, n);
		            break;
	            case 3:
		            printf("You selected option 3.\n");
		            add(p, &n);
	            	break;
				case 4:
		            printf("You selected option 4.\n");
		            search(p, n);
		            break;
				case 5:
		            printf("You selected option 5.\n");
		            top_3(p, n);
		            break;
		        case 6:
		        	printf("You selected option 6.\n");
		            remove_player(p, &n);
		            break;
		        case 7:
		        	printf("Quiting.... \n");
		        	break;
		        default:
		            printf("Invalid choice.\n");
		    }
    	}while(choice!=7);		//The loop will continue until user enters 7 ,if user enter 7 as a choice, it will make this condition false and terminate the loop->Quit the menu

	}
	
//------------------------------------------Stored entries-----------------------------------------------------//
void store(player* p,int* n){
	
	strcpy(p[*n].pname, "Sachin Tendulkar");
	p[*n].jer_no = 10;
	p[*n].wickets = 154;
	p[*n].runs = 15006;
	p[*n].matches = 200;
	(*n)++;
	
	strcpy(p[*n].pname, "Virat Kohli");
	p[*n].jer_no = 18;
	p[*n].wickets = 280;
	p[*n].runs = 7434;
	p[*n].matches = 254;
	(*n)++;
	
	strcpy(p[*n].pname, "Rahul Dravid");
	p[*n].jer_no = 19;
	p[*n].wickets = 196;
	p[*n].runs = 13288;
	p[*n].matches = 164;
	(*n)++;
	
	strcpy(p[*n].pname, "Kapil Dev");
	p[*n].jer_no = 4;
	p[*n].wickets = 434;
	p[*n].runs = 5248;
	p[*n].matches = 225;
	(*n)++;
	
	strcpy(p[*n].pname, "Sunil Gavaskar");
	p[*n].jer_no = 1;
	p[*n].wickets = 1;
	p[*n].runs = 10122;
	p[*n].matches = 125;
	(*n)++;

		
}

//---------------------------------------------1)Display------------------------------------------------------//
void display(player* p, int n) {
	
    
    printf("\n-------------------------------------------------------------------------------------------------\n");
    printf("%-20s | %-30s | %-20s | %-8s | %-6s\n", "Jersey Number", "Player Name", "Runs", "Wickets", "Matches");
    printf("\n-------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20d | %-30s | %-20d | %-8d | %-6d\n",
               p[i].jer_no, p[i].pname, p[i].runs, p[i].wickets, p[i].matches);
    }
    printf("\n");
}


//----------------------------------2.Update------------------------------------------------------------------//

void update(player* p, int n) {
    int jno;

    printf("Enter the jersey number of player you want to update: ");
    scanf("%d", &jno);

    int found = 0;

    for (int i = 0; i < n; i++) {
        if (jno==p[i].jer_no) {		//comparing jno with p[i].jer_no all in list 
             found = 1;			//found the player name,,  to update
            printf("Enter if you want to update:\n1) runs\n2) wickets :\n ");
            int choice;
            scanf("%d", &choice);

            if (choice == 1) {				
                printf("Enter runs: ");		//update runs
                scanf("%d", &p[i].runs);
                
            } else if (choice == 2) {		//update wickets
                printf("Enter wickets: ");
                scanf("%d", &p[i].wickets);
            } else {
                printf("Invalid choice!\n");
            }
        }
        
    }

    if (!found) {		//found =zero
        printf("\Player not found... Can't update.\n");
    } 
	else {					//found= non zero(1 here)
        printf("\n----------Updated player details:---------\n");
        display(p, n);
    }
}

    
//------------------------------------------Add new entry----------------------------------------------------//

void add(player* p, int* n) {
	if (*n >= 100) {
        printf("Maximum number of entries reached. Cannot add more entries.\n");
        return;
    }

    printf("\n\n---------Enter the details for the new player entry--------:\n\n");

    printf("Enter player Name: ");
    scanf("%s", p[*n].pname);

    printf("Enter Jersey Number: ");
    scanf("%d", &p[*n].jer_no);

    printf("Enter Runs made:");
    scanf("%d",& p[*n].runs);

   	printf("Enter wickets taken:");
    scanf("%d", &p[*n].wickets);

    printf("Enter matches played :");
    scanf("%d",& p[*n].matches);

    (*n)++;  // Update the total number of players

    printf("\nNew entry added successfully!!!\n");
    display(p,*n);
}


//-----------------------------------------Search-------------------------------------------------------------//

void search(player* p, int n) {
    int choice;
    printf("Search 1. By Jersey no. \n 2. By Name: \n ");
    scanf("%d", &choice);

    if (choice == 1) {					//search by id
        int j_no;
        printf("Enter the jersey no. of player to search: ");
        scanf("%d", &j_no);

        int found = 0; 

        for (int i = 0; i < n; i++) {			 
            if (j_no==p[i].jer_no) {		//comparing yser id with all the p[i].id in array
                found = 1; 			// 1 represents "found"
                printf("PLayer found!!:\n");
                printf("\n-------------------------------------------------------------------------------------------------\n");
    			printf("%-20s | %-30s | %-20s | %-8s | %-6s\n", "Jersey Number", "Player Name", "Runs", "Wickets", "Matches");
    			printf("\n-------------------------------------------------------------------------------------------------\n");
    
        		printf("%-20d | %-30s | %-20d | %-8d | %-6d\n",
              	p[i].jer_no, p[i].pname, p[i].runs, p[i].wickets, p[i].matches);
    
    			printf("\n");
			    break;
				
            }
        }

        if (!found) {
            printf("\PLayer not found with jersey number %d\n", j_no);
        }
    } else if (choice == 2) {					//search by name
        char name[30];
        printf("Enter the Name of the player to search: ");
//        scanf("%s",name);
		gets(name);

        int found = 0;

        for (int i = 0; i < n; i++) {
            if (strcmp(p[i].pname, name) == 0) {
                found = 1;
                printf("\PLayer found!!:\n");
                printf("\n-------------------------------------------------------------------------------------------------\n");
    			printf("%-20s | %-30s | %-20s | %-8s | %-6s\n", "Jersey Number", "Player Name", "Runs", "Wickets", "Matches");
    			printf("\n-------------------------------------------------------------------------------------------------\n");
    
        		printf("%-20d | %-30s | %-20d | %-8d | %-6d\n",
              	p[i].jer_no, p[i].pname, p[i].runs, p[i].wickets, p[i].matches);
    
    			printf("\n"); 
				break;
            }
        }

        if (!found) {
            printf("\nPlayer not found with name  %s\n", name);
        }
    }
}
	 
//-------------------------------------Top3 PLayers ------------------------------------------------//

void top_3(player* p, int n) {
    player sortedstructurearray[n];    // Creating an array for this function to copy the original array into it

    player tempstructure;			// Declaring a single temporary structure for swapping


	// Copy all the values from the parent structure array for sorting
    for (int i = 0; i < n; i++) {
        strcpy(sortedstructurearray[i].pname, p[i].pname);
        sortedstructurearray[i].jer_no = p[i].jer_no;
        sortedstructurearray[i].runs = p[i].runs;
        sortedstructurearray[i].wickets = p[i].wickets;
        sortedstructurearray[i].matches = p[i].matches;
    }

    int choice;
    printf("Enter If you want Top3 players According to:\n1. Runs\n2. Wickets\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\n----------TOP 3 Players with Highest Runs----------\n");

		// Swap elements in the sortedstructurearray
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sortedstructurearray[j].runs > sortedstructurearray[i].runs) {
                    tempstructure = sortedstructurearray[j];
                    sortedstructurearray[j] = sortedstructurearray[i];
                    sortedstructurearray[i] = tempstructure;
                }
            }
        }

        printf("\n-------------------------------------------------------------------------------------------------\n");
        printf("%-20s | %-30s | %-20s | %-8s | %-6s\n", "Jersey Number", "Player Name", "Runs", "Wickets", "Matches");
        printf("\n-------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < 3; i++) {
            printf("%-20d | %-30s | %-20d | %-8d | %-6d\n",
                   sortedstructurearray[i].jer_no, sortedstructurearray[i].pname,
                   sortedstructurearray[i].runs, sortedstructurearray[i].wickets,		
                   sortedstructurearray[i].matches);
        }

        printf("\n");
    } else if (choice == 2) {
        printf("\n----------TOP 3 Players with Highest Wickets----------\n");
		// Swap elements in the sortedstructurearray
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sortedstructurearray[j].wickets > sortedstructurearray[i].wickets) {
                    tempstructure = sortedstructurearray[j];
                    sortedstructurearray[j] = sortedstructurearray[i];
                    sortedstructurearray[i] = tempstructure;
                }
            }
        }

        printf("\n-------------------------------------------------------------------------------------------------\n");
        printf("%-20s | %-30s | %-20s | %-8s | %-6s\n", "Jersey Number", "Player Name", "Runs", "Wickets", "Matches");
        printf("\n-------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < 3; i++) {
            printf("%-20d | %-30s | %-20d | %-8d | %-6d\n",
                   sortedstructurearray[i].jer_no, sortedstructurearray[i].pname,
                   sortedstructurearray[i].runs, sortedstructurearray[i].wickets,
                   sortedstructurearray[i].matches);
        }

        printf("\n");
    } else {
        printf("\nEnter valid choice\n");
    }
}


//-----------------------------------------------Delete---------------------------------------------------------//

void remove_player(player* p, int* n){
	
        int jno;
        printf("Enter the jersey number of Player to Delete: ");
        scanf("%d", &jno);

        int found = 0; 

        for (int i = 0; i < *n; i++) {			 
            if (p[i].jer_no==jno) {		//comparing yser id with all the b[i].id in array
                found = 1; 			// 1 represents "found"
               
				for(int j=i;j<(*n)-1;j++){
					p[j]=p[j+1];
				}
				(*n)--;
				printf("Record deleted successfully...");
                break;
                
            }
		}

        if (!found) {
            printf("\PLayer not found with Jersey number %d\n", jno);	
		} else{
			printf("Updated List of players:\n");
        	display(p, *n);
		}
        
    }


//----------------------------------------store--------------------------------------------------------------//

//void store(player* p, int *n) {
//    for (int i = 0; i < *n; i++) {
//        printf("Enter Player Name: ");
//        scanf("%s", p[i].pname);
//
//        printf("Enter Jersey number: ");
//        scanf("%d", &p[i].jer_no);
//
//        printf("Enter Runs made : ");
//        scanf("%d", p[i].runs);
//
//        printf("Enter wickets taken : ");
//        scanf("%d", p[i].wickets);
//
//        printf("Enter matches played : ");
//        scanf("%d", p[i].matches);
//
//        printf("Data stored successfully...\n");
//	(*n)++;
//    }
//}
