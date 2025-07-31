#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEATS 32
#define NAME_LENGTH 20

struct Bus {
    int number;
    char driver[NAME_LENGTH];
    char from[NAME_LENGTH];
    char to[NAME_LENGTH];
    int departure;
    int arrival;
    char seatNames[SEATS][NAME_LENGTH];
};

struct Bus bus;  // only 1 bus

void setupBus() {
    bus.number = 100;
    strcpy(bus.driver, "bruno");
    strcpy(bus.from, "pkr");
    strcpy(bus.to, "ktm");
    bus.departure = 1;
    bus.arrival = 5;

    // Initialize seats randomly
    srand(time(NULL));
    for (int i = 0; i < SEATS; i++) {
        if (rand() % 2 == 0) {
            strcpy(bus.seatNames[i], "");
        } else {
            strcpy(bus.seatNames[i], "RESERVED");
        }
    }
}

void showAvailableBuses() {
    printf("\nAvailable Buses:\n");
    printf("Bus No: %d | Driver: %s | From: %s | To: %s\n",
           bus.number, bus.driver, bus.from, bus.to);
}

void showBus() {
    printf("*******************************************************************************\n");
    printf("Bus no: %d\n", bus.number);
    printf("Driver: %-10s\tArrival time: %d\tDeparture time: %d\n", bus.driver, bus.arrival, bus.departure);
    printf("From: %-10s\tTo: %s\n", bus.from, bus.to);
    printf("*******************************************************************************\n");

    int availableSeats = 0;
    for (int i = 0; i < SEATS; i++) {
        if (strcmp(bus.seatNames[i], "") == 0) {
            printf("%2d. %-10s", i + 1, "Empty");
            availableSeats++;
        } else {
            printf("%2d. %-10s", i + 1, bus.seatNames[i]);
        }
        if ((i + 1) % 4 == 0) printf("\n");
    }

    printf("\nThere are %d seats empty in Bus No: %d\n", availableSeats, bus.number);
}

void reserveSeat() {
    int seat;
    printf("Enter seat number to reserve (1–32): ");
    scanf("%d", &seat);
    getchar();  // clear newline

    if (seat < 1 || seat > SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    if (strcmp(bus.seatNames[seat - 1], "") != 0) {
        printf("Seat %d is already taken.\n", seat);
        return;
    }

    char name[NAME_LENGTH];
    printf("Enter your name: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;  // remove newline

    strcpy(bus.seatNames[seat - 1], name);
    printf("Seat %d reserved for %s.\n", seat, name);
}

int main() {
    setupBus();  // Preload a bus
    int choice;

    while (1) {
        printf("\n\t\t***SIMPLE BUS RESERVATION SYSTEM***\n");
        printf("\n\t1. Reservation");
        printf("\n\t2. Show");
        printf("\n\t3. Buses Available");
        printf("\n\t4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: reserveSeat(); break;
            case 2: showBus(); break;
            case 3: showAvailableBuses(); break;
            case 4: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
