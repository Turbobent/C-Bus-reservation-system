#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEATS 32
#define NAME_LENGTH 20
#define MAX_BUSES 3

struct Bus {
    int number;
    char driver[NAME_LENGTH];
    char from[NAME_LENGTH];
    char to[NAME_LENGTH];
    int departure;
    int arrival;
    char seatNames[SEATS][NAME_LENGTH];
};

struct Bus buses[MAX_BUSES];

// Sample names for random reservations
const char *sampleNames[] = {
    "alex", "maria", "john", "lucy", "daniel", "emma", "chris", "nora"
};
int sampleNameCount = sizeof(sampleNames) / sizeof(sampleNames[0]);

void setupBuses() {
    srand(time(NULL));

    for (int i = 0; i < MAX_BUSES; i++) {
        buses[i].number = 100 + i;
        snprintf(buses[i].driver, NAME_LENGTH, "driver%d", i + 1);
        strcpy(buses[i].from, "pkr");
        strcpy(buses[i].to, "ktm");
        buses[i].departure = 8 + i;
        buses[i].arrival = 10 + i;

        for (int j = 0; j < SEATS; j++) {
            if (rand() % 2 == 0) {
                strcpy(buses[i].seatNames[j], "");  // empty seat
            } else {
                strcpy(buses[i].seatNames[j], sampleNames[rand() % sampleNameCount]);
            }
        }
    }
}

void showAvailableBuses() {
    printf("\nAvailable Buses:\n");
    for (int i = 0; i < MAX_BUSES; i++) {
        int available = 0;
        for (int j = 0; j < SEATS; j++) {
            if (strcmp(buses[i].seatNames[j], "") == 0)
                available++;
        }
        printf("Bus No: %d | Driver: %-10s | From: %-5s | To: %-5s | Available Seats: %d\n",
               buses[i].number, buses[i].driver, buses[i].from, buses[i].to, available);
    }
}
void printBusHeader(struct Bus *bus) {
    printf("*******************************************************************************\n");
    printf("Bus no: %d\n", bus->number);
    printf("Driver: %-10s\tArrival time: %d\tDeparture time: %d\n", bus->driver, bus->arrival, bus->departure);
    printf("From: %-10s\tTo: %s\n", bus->from, bus->to);
    printf("*******************************************************************************\n");
}

void showBus() {
    int busNo;
    printf("Enter bus number to show: ");
    scanf("%d", &busNo);

    for (int i = 0; i < MAX_BUSES; i++) {
        if (buses[i].number == busNo) {
            struct Bus *bus = &buses[i];

            printBusHeader(bus);

            int availableSeats = 0;
            for (int j = 0; j < SEATS; j++) {
                if (strcmp(bus->seatNames[j], "") == 0) {
                    printf("%2d. %-10s", j + 1, "Empty");
                    availableSeats++;
                } else {
                    printf("%2d. %-10s", j + 1, bus->seatNames[j]);
                }
                if ((j + 1) % 4 == 0) printf("\n");
            }

            printf("\nThere are %d seats empty in Bus No: %d\n", availableSeats, bus->number);
            return;
        }
    }

    printf("Bus number %d not found.\n", busNo);
}

void reserveSeat() {
    int busNo;
    printf("Enter bus number to reserve a seat in: ");
    scanf("%d", &busNo);

    for (int i = 0; i < MAX_BUSES; i++) {
        if (buses[i].number == busNo) {
            struct Bus *bus = &buses[i];

            printBusHeader(bus);
            int seat;
            while (1) {
                printf("Enter seat number to reserve (1-32): ");
                scanf("%d", &seat);
                while ((getchar()) != '\n');  // flush newline

                if (seat < 1 || seat > SEATS) {
                    printf("Invalid seat number.\n");
                    continue;
                }

                if (strcmp(bus->seatNames[seat - 1], "") != 0) {
                    printf("Seat %d is already reserved by '%s'. Try again.\n", seat, bus->seatNames[seat - 1]);
                    continue;
                }

                break;
            }

            char name[NAME_LENGTH];
            printf("Enter your name: ");
            fgets(name, NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = 0;

            strcpy(bus->seatNames[seat - 1], name);
            printf("Seat %d reserved for %s in Bus %d.\n", seat, name, bus->number);
            return;
        }
    }

    printf("Bus number %d not found.\n", busNo);
}

int main() {
    setupBuses();  // Load bus data

    int choice;

    while (1) {
        printf("\n\t\t*** SIMPLE BUS RESERVATION SYSTEM ***\n");
        printf("\n\t1. Reservation");
        printf("\n\t2. Show Bus Seats");
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
