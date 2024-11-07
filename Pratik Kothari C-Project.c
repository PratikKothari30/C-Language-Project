#include<stdio.h>
#include<string.h>

struct PlayerManagement{
	char PlayerName[30];
	int MatchesPlayed;
	int Player_Runs;
	int Player_Wkt;
	int Jersey_Num;
};

void Store();
void Display(struct PlayerManagement *, int);
void AddPlayer();
void SearchPlayer();
void RemovePlayer();
void UpdatePlayer();
void SortPlayer(struct PlayerManagement *, int *);
void Top3Player(struct PlayerManagement *, int *);

struct PlayerManagement *Player = NULL;
int PlayerCount = 10;

void main(){
	printf(" ---------------------------------------------------------------\n");
	printf("|\t\tPlayer Management System\t\t\t|\n");
	printf(" ---------------------------------------------------------------\n\n");
	
	Player = (struct PlayerManagement *)malloc(30 * sizeof(struct PlayerManagement)); // Allocate initial memory
    if (Player == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
	int choice;
	Store();
	do {
        printf("\n\nChoice which operation you want to perform :\n");
        printf("-------------------------------------------\n");
        printf("1. Display Player Details\n");
        printf("2. Add Player Details\n");
        printf("3. search Player by name\n");
        printf("4. Remove Player details\n");
        printf("5. Update Player details\n");
        printf("6. Get top 3 Player details\n");
        printf("7. Sorted Player Details\n");
        printf("8. Exit\n");
        printf("-------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Display(Player, PlayerCount);
                break;
            case 2:
                AddPlayer();
                break;
            case 3:
            	SearchPlayer();
                break;
            case 4:
            	RemovePlayer();
                break;
            case 5:
            	UpdatePlayer();
                break;
            case 6:
            	Top3Player(Player, &PlayerCount);
                break;
            case 7:
            	SortPlayer(Player, &PlayerCount);
                break;   
            case 8:
            	printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 8);
    free(Player); // Free allocated memory
}

void Store(){
	strcpy(Player[0].PlayerName, "Rohit Sharma");
	Player[0].MatchesPlayed = 123;
	Player[0].Player_Runs = 3693;
	Player[0].Player_Wkt = 36;
	Player[0].Jersey_Num = 45;
	
	strcpy(Player[1].PlayerName, "Virat kohli");
	Player[1].MatchesPlayed = 163;
	Player[1].Player_Runs = 4293;
	Player[1].Player_Wkt = 56;
	Player[1].Jersey_Num = 18;
	
	strcpy(Player[2].PlayerName, "MS Dhoni");
	Player[2].MatchesPlayed = 223;
	Player[2].Player_Runs = 5763;
	Player[2].Player_Wkt = 136;
	Player[2].Jersey_Num = 07;
	
	strcpy(Player[3].PlayerName, "Sanju Samson");
	Player[3].MatchesPlayed = 83;
	Player[3].Player_Runs = 1783;
	Player[3].Player_Wkt = 16;
	Player[3].Jersey_Num = 33;
	
	strcpy(Player[4].PlayerName, "Shubman Gill");
	Player[4].MatchesPlayed = 113;
	Player[4].Player_Runs = 2953;
	Player[4].Player_Wkt = 46;
	Player[4].Jersey_Num = 65;
	
	strcpy(Player[5].PlayerName, "jasprit bumrah");
	Player[5].MatchesPlayed = 243;
	Player[5].Player_Runs = 1873;
	Player[5].Player_Wkt = 186;
	Player[5].Jersey_Num = 13;
	
	strcpy(Player[6].PlayerName, "Rururaj Gaikwad");
	Player[6].MatchesPlayed = 73;
	Player[6].Player_Runs = 2043;
	Player[6].Player_Wkt = 6;
	Player[6].Jersey_Num = 24;
	
	strcpy(Player[7].PlayerName, "Hardik Pandya");
	Player[7].MatchesPlayed = 167;
	Player[7].Player_Runs = 4363;
	Player[7].Player_Wkt = 119;
	Player[7].Jersey_Num = 61;
	
	strcpy(Player[8].PlayerName, "Yuzvendra Chahal");
	Player[8].MatchesPlayed = 217;
	Player[8].Player_Runs = 1133;
	Player[8].Player_Wkt = 190;
	Player[8].Jersey_Num = 35;
	
	strcpy(Player[9].PlayerName, "Ravindra Jadeja");
	Player[9].MatchesPlayed = 247;
	Player[9].Player_Runs = 4787;
	Player[9].Player_Wkt = 206;
	Player[9].Jersey_Num = 29;
}

void Display(struct PlayerManagement *Player, int PlayerCount){
	printf("\nPlayer Name\t\tMatches_Played\t   Runs\t     Wickets\tJersey_Num\n");
    for (int i = 0; i < PlayerCount; i++) {
    	printf("---------------------------------------");
        printf("\n%-20s | %-15d | %-10d| %-10d| %-10d|\n", Player[i].PlayerName, Player[i].MatchesPlayed, Player[i].Player_Runs, Player[i].Player_Wkt, Player[i].Jersey_Num);
        printf("-------------------------------------");
    }
}

void AddPlayer(){
	 if (PlayerCount < 13) {
        printf("Enter new Player Name : ");
        scanf("%s", Player[PlayerCount].PlayerName);
        fflush(stdin);
        
		printf("Enter Matches Played by Player : ");
        scanf("%d", &Player[PlayerCount].MatchesPlayed);

        printf("Enter Runs made by player : ");
        scanf("%d", &Player[PlayerCount].Player_Runs);
        
        printf("Enter Wickets taken by player : ");
        scanf("%d", &Player[PlayerCount].Player_Wkt);
        
        printf("Enter Jersey Number : ");
        scanf("%d", &Player[PlayerCount].Jersey_Num);
        
        PlayerCount++;
        printf("Player added successfully.\n");
    } else {
        printf("Cannot add more Players, storage is full.\n");
    }
}

void SearchPlayer(){
	int searchChoice;
    int found = 0;

	do {
        printf("\nSearch Player by:\n");
        printf("1. Name\n");
        printf("2. Jersey Number\n");
        printf("Enter your choice: ");
        scanf("%d", &searchChoice);

        if (searchChoice == 1) {
            char searchName[30];
            getchar();  // To clear the buffer
            printf("Enter the Player name to search: ");
            fgets(searchName, 30, stdin);
            searchName[strcspn(searchName, "\n")] = '\0';  // Remove newline

            found = 0;  // Reset found flag for each iteration
            for (int i = 0; i < PlayerCount; i++) {
                if (strcmp(Player[i].PlayerName, searchName) == 0) {
                    printf("\nPlayer Details Found:\n");
                    printf("\n%-20s | %-15d | %-10d| %-10d| %-10d|\n",
                           Player[i].PlayerName, Player[i].MatchesPlayed,
                           Player[i].Player_Runs, Player[i].Player_Wkt,
                           Player[i].Jersey_Num);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Player details not found. Please try again.\n");
            }
        } else if (searchChoice == 2) {
            int searchJersey;
            printf("Enter the Jersey Number to search: ");
            scanf("%d", &searchJersey);

            found = 0;
            for (int i = 0; i < PlayerCount; i++) {
                if (Player[i].Jersey_Num == searchJersey) {
                    printf("\nPlayer Details Found:\n");
                    printf("\n%-20s | %-15d | %-10d| %-10d| %-10d|\n",
                           Player[i].PlayerName, Player[i].MatchesPlayed,
                           Player[i].Player_Runs, Player[i].Player_Wkt,
                           Player[i].Jersey_Num);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Player details not found. Please try again.\n");
            }
        } else {
            printf("Invalid choice, please enter 1 or 2.\n");
        }

    } while (!found);
}

void RemovePlayer(){
		char RemoveName[30];
		getchar(); // leftover newline character ('\n') in the input
		printf("Enter the Player name to remove: ");
    	fgets(RemoveName, 30, stdin);
    	RemoveName[strcspn(RemoveName, "\n")] = '\0';
    	
    	int flag = 0, i;
    	for (i = 0; i < PlayerCount; i++) {
		if (strcmp(Player[i].PlayerName, RemoveName) == 0) {
            flag = 1;
            for (int j = i; j < PlayerCount - 1; j++) {
                Player[j] = Player[j + 1];
            }
            PlayerCount--;
            printf("\nPlayer '%s' has been removed.\n", RemoveName);
            break;
        }
    }
        if (!flag) {
        printf("Player '%s' not found.\n", RemoveName);
    }
}

void UpdatePlayer(){
	char updateName[30];
    getchar();
    printf("Enter a Player name to update: ");
    fgets(updateName, 30, stdin);
	
	updateName[strcspn(updateName, "\n")] = '\0';
    int found = 0;
    for (int i = 0; i < PlayerCount; i++) {
        if (strcmp(Player[i].PlayerName, updateName) == 0) {
            
            printf("Enter players Matches Played to update: ");
            scanf("%d", &Player[i].MatchesPlayed);
            
            printf("Enter player Runs to update: ");
            scanf("%d", &Player[i].Player_Runs);
            
            printf("Enter player Wickets to update: ");
            scanf("%d", &Player[i].Player_Wkt);
            
            printf("Enter players Jersey number to update: ");
            scanf("%d", &Player[i].Jersey_Num);
            
            printf("Player details updated successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Player not found.\n");
    }
}

void Top3Player(struct PlayerManagement *players, int *PlayerCount) {
    int i, j, SearchChoice;
    struct PlayerManagement temp;

    do {
        printf("\nSearch Top-3 Players by:\n");
        printf("1. Runs\n");
        printf("2. Wickets\n");
        printf("Enter your choice: ");
        scanf("%d", &SearchChoice);

        if (SearchChoice == 1) {
            for (i = 0; i < *PlayerCount - 1; i++) {
                for (j = i + 1; j < *PlayerCount; j++) {
                    if (Player[i].Player_Runs < Player[j].Player_Runs) {
                        temp = Player[i];
                        Player[i] = Player[j];
                        Player[j] = temp;
                    }
                }
            }
            printf("\nTop 3 Players by Runs:\n");
            for (i = 0; i < 3 && i < *PlayerCount; i++) {
                printf("\n-----------------------------------------\n");
                printf("| %s      \t | Runs: %d\t|\n", Player[i].PlayerName, Player[i].Player_Runs);
                printf("-----------------------------------------\n");
            }
            break;
        } else if (SearchChoice == 2) {
            for (i = 0; i < *PlayerCount - 1; i++) {
                for (j = i + 1; j < *PlayerCount; j++) {
                    if (Player[i].Player_Wkt < Player[j].Player_Wkt) {
                        temp = Player[i];
                        Player[i] = Player[j];
                        Player[j] = temp;
                    }
                }
            }
            printf("\nTop 3 Players by Wickets:\n");
            for (i = 0; i < 3 && i < *PlayerCount; i++) {
                printf("\n----------------------------------------\n");
                printf("| %s\t | Wickets: %d\t|\n", Player[i].PlayerName, Player[i].Player_Wkt);
                printf("----------------------------------------\n");
            }
            break;
        } else {
            printf("Invalid choice. Please enter 1 or 2.\n");
        }
    } while (SearchChoice != 1 && SearchChoice != 2);  // Repeat until a valid choice is entered
}


void SortPlayer(struct PlayerManagement *players, int *PlayerCount){
	struct PlayerManagement temp;
	for (int i = 0; i < *PlayerCount - 1; i++) {
            for (int j = 0; j < *PlayerCount - i - 1; j++) {
            	if (Player[j].Player_Runs < Player[j + 1].Player_Runs) {
                    temp = Player[j];
                    Player[j] = Player[j + 1];
                    Player[j + 1] = temp;
                }
            }
            }
            printf("\nSorted Player Details by Player runs: \n\n");
        printf("\nPlayer Name\t\tMatches_Played\t  Runs\t    Wickets\t Jersey_Num\n");
        for (int i = 0; i < *PlayerCount; i++) {
    	printf("---------------------------------------");
        printf("\n%-20s | %-15d | %-10d| %-10d| %-10d|\n", Player[i].PlayerName, Player[i].MatchesPlayed, Player[i].Player_Runs, Player[i].Player_Wkt, Player[i].Jersey_Num);
        printf("-------------------------------------");
    }
}