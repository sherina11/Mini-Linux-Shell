#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showHelp() {
    printf("\n--- Mini Shell Help ---\n");
    printf("Type any system command (like dir, date, cls)\n");
    printf("Custom commands:\n");
    printf("help - Show help menu\n");
    printf("exit - Exit shell\n");
}

int main() {
    char command[100];

    printf("Welcome to Mini Shell!\n");

    while (1) {
        printf("\n>> ");
        fgets(command, sizeof(command), stdin);

        // remove newline
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }
        else if (strcmp(command, "help") == 0) {
            showHelp();
        }
        else {
            int status = system(command);
            if (status == -1) {
                printf("Command execution failed!\n");
            }
        }
    }

    return 0;
}