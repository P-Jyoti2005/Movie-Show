#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

struct Movie {
    int id;
    char name[50];
    float price;
};

void displayMovies(struct Movie movies[], int size) {
    printf("\nAvailable Movies:\n");
    printf("ID\tMovie Name\t\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%-20s ₹%.2f\n", movies[i].id, movies[i].name, movies[i].price);
    }
}

int main() {
    struct Movie movies[MAX] = {
        {1, "Avengers: Endgame", 250.0},
        {2, "Inception", 200.0},
        {3, "Interstellar", 220.0},
        {4, "Jawan", 180.0},
        {5, "3 Idiots", 150.0}
    };

    int choice, tickets;
    float total;

    displayMovies(movies, MAX);

    printf("\nEnter the Movie ID to book: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > MAX) {
        printf("Invalid movie ID.\n");
        return 1;
    }

    printf("Enter number of tickets: ");
    scanf("%d", &tickets);

    total = movies[choice - 1].price * tickets;

    printf("\n✅ Booking Successful!");
    printf("\nMovie: %s", movies[choice - 1].name);
    printf("\nTickets: %d", tickets);
    printf("\nTotal Amount: ₹%.2f\n", total);

    return 0;
}
