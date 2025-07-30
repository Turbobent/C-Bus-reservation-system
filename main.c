#include <stdio.h>
#include <stdlib.h>

void main(){
    int busNumber[] = {62, 1 , 5, 73, 215};
    int ticketPrice = 100;
    char driver[] = "lucas";
    int departureTime[10] = {8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    int arrivalTime[10] =   {9,10, 11, 12, 13, 14, 15, 16, 17, 18};

    // 1 to 50
    int busSeats[] = {1};
    char *ticketsLocations[] = {"nordpolen", "kina", "istergade"};

    int userBusNrInput;

    printf("enter bus number\n");
    scanf("%d",&userBusNrInput);
    int found = 0;

    for (int i = 0; i < 5; i++) {
    if (busNumber[i] == userBusNrInput) {
        found = 1;
        printf("Available departures:\n");
        for (int i = 0; i < 10; i++) {
            printf("[%d] Departure: %d:00 - Arrival: %d:00\n", i, departureTime[i], arrivalTime[i]);
        }

        int choice;
        printf("Choose a departure by entering the number (0-9): ");
        scanf("%d", &choice);

        if (choice >= 0 && choice < 10) {
            //can book a seat and see what seats are avaieble and price
            printf("You chose: Departure at %d:00, Arrival at %d:00\n", departureTime[choice], arrivalTime[choice]);
        } else {
            printf("Invalid choice.\n");
        }   break;
      }
    }
    if (!found) {
        printf("Bus number %d doesn't exist.\n", userBusNrInput);
    }
};