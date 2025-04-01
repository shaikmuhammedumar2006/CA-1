#include <stdio.h>

int main() {
    int choice;

    printf("Select an engineering course by entering the corresponding number:\n");
    printf("1. Computer Engineering\n");
    printf("2. Electrical Engineering\n");
    printf("3. Mechanical Engineering\n");
    printf("4. Civil Engineering\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You selected: Computer Engineering\n");
            break;
	    
	case 2:
            printf("You selected: Electrical Engineering\n");
            break;

	case 3:
            printf("You selected: Mechanical Engineering\n");
            break;
	    
	case 4:
            printf("You selected: Civil Engineering\n");
            break;

	      }

    return 0;
}
