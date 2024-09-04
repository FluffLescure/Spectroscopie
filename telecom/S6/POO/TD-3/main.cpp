#include "Semester.h"
#include "Subject.h"

#include <iostream>
#include <string>

void menu(void) {
    short choice;
    Semester sem;

    std::string name;
    float grade;
    int weight;

    while (true) {
        printf("\n\t== MENU ==");
        printf("\n\t1. Add subject");
        printf("\n\t2. Remove subject");
        printf("\n\t3. Semester Average");
        printf("\n\t4. Show Semester");
        printf("\n\t5. Exit\n");

        while (!(std::cin >> choice) && choice > 0 && choice < 6)
            printf("\n\tError selecting, try again.");

        switch (choice) {
        case 1:
            printf("\n Enter subject Name");
            while (!(std::cin >> name))
                printf("\n\tError, try again.");

            printf("\n Enter Grade");
            while (!(std::cin >> grade))
                printf("\n\tError, try again.");

            printf("\n Enter Weight");
            while (!(std::cin >> weight))
                printf("\n\tError, try again.");

            sem.addSubject(new Subject(name, grade, weight));
            break;
        case 2:
            printf("\n Enter subject Name");
            while (!(std::cin >> name))
                printf("\n\tError, try again.");

            sem.removeSubject(name);
            break;
        case 3:
            printf("\nAverage of semester: %f", sem.Average());
            break;
        case 4:
            sem.print();
            break;
        case 5:
            exit;
            break;
        }
    }
}

int main() {

    menu();

    return 0;
}