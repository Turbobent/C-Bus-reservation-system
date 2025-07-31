#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void main(){
     int busSeats[50];
    
    // Seed the random number generator
    srand(time(NULL));

    int busNumber[] = {62, 1 , 5, 73, 215};
    int ticketPrice = 100;
    char driver[] = "lucas";
    int departureTime[10] = {8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    int arrivalTime[10] =   {9,10, 11, 12, 13, 14, 15, 16, 17, 18};

  
    char *ticketsLocations[] = {"nordpolen", "kina", "istergade"};


    // Fill seats randomly: 0 = available, 1 = taken
    for (int i = 0; i < 50; i++) {
        busSeats[i] = rand() % 2;  // 0 or 1 randomly
    }

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
            // Show available seats
            printf("Available seats:\n");
            for (int i = 0; i < 50; i++) {
            if (busSeats[i] == 0) {
            printf("Seat %d\n", i + 1);
        }
    }
        } else {
            printf("Invalid choice.\n");
        }   break;
      }
    }
    if (!found) {
        printf("Bus number %d doesn't exist.\n", userBusNrInput);
    }
};