#include "StrList.h"
#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for the exit function
#include <string.h> // Add this line to include the string.h header file

void insertStrings(StrList* list, char **input);
void insertStringAtIndex(StrList* list);
void printList(const StrList* list);
void printListLength(const StrList* list);
void printStringAtIndex(const StrList* list);
void printTotalCharCount(const StrList* list);
void printStringOccurrences(StrList* list);
void removeStringOccurrences(StrList* list);
void removeStringAtIndex(StrList* list);
void reverseList(StrList* list);
void clearList(StrList** list);
void sortList(StrList* list);
void checkSorted(StrList* list);

int main (){
    int choice = 20;  // Initialize choice to any non-0 value
    StrList* list = StrList_alloc();
    char *input = NULL;   // Initialize input pointer to NULL

    while (1) {
        scanf(" %d",&choice);
        switch (choice) {
            case 1:
                insertStrings(list, &input);
                break;
            case 2:
                insertStringAtIndex(list);
                break;
            case 3:
                printList(list);
                break;
            case 4:
                printListLength(list);
                break;
            case 5:
                printStringAtIndex(list);
                break;
            case 6:
                printTotalCharCount(list);
                break;
            case 7:
                printStringOccurrences(list);
                break;
            case 8:
                removeStringOccurrences(list);
                break;
            case 9:
                removeStringAtIndex(list);
                break;
            case 10:
                reverseList(list);
                break;
            case 11:
                clearList(&list);
                break;
            case 12:
                sortList(list);
                break;
            case 13:
                checkSorted(list);
                break;
            case 0:
                StrList_free(list);
                free(input); // Free memory allocated for input
                exit(0);
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}


void insertStrings(StrList* list, char **input) {
    int num_words;
    scanf(" %d", &num_words);
    
    // Allocate memory for input buffer
    *input = (char *)malloc(1000 * sizeof(char));
    
    while (getchar() != '\n');  // waits for user to input enter

    // Read the entire line of input to accommodate multiple words with spaces:
    fgets(*input, 1000, stdin);  // Use sizeof(input) instead of hardcoding size

    // Newline is also included, so we will replace it with null terminator
    int len = strlen(*input);
    if ((*input)[len - 1] == '\n') {
        (*input)[len - 1] = '\0'; 
    }

    // Extract individual words from the input line, validate word length, and insert:
    char *token = strtok(*input, " "); // Get first word (or NULL if none)

    while (token != NULL) {
        // Insert the word at the end of the list using StrList_insertLast:
        StrList_insertLast(list, token);
        // Get the next word:
        token = strtok(NULL, " ");
    }
}


void insertStringAtIndex(StrList* list) {
    int index;
    char word[100];
    scanf("%d", &index);
    scanf("%s", word);
    StrList_insertAt(list, word, index);
}

void printList(const StrList* list) {
    if (list == NULL) {
        return;
    }
    StrList_print(list);
    printf("\n");
}

void printListLength(const StrList* list) {
    printf("%zu\n", StrList_size(list));
}

void printStringAtIndex(const StrList* list) {
    int index;
    scanf("%d", &index);
    StrList_printAt(list, index);
}

void printTotalCharCount(const StrList* list) {
    printf("%d\n", StrList_printLen(list));
}

void printStringOccurrences(StrList* list) {
    char word[100];
    scanf("%s", word);
    printf("%d\n", StrList_count(list, word));
}

void removeStringOccurrences(StrList* list) {
    char word[100];
    scanf("%s", word);
    StrList_remove(list, word);
}

void removeStringAtIndex(StrList* list) {
    int index;
    scanf("%d", &index);
    StrList_removeAt(list, index);
}

void reverseList(StrList* list) {
    StrList_reverse(list); 
}

void clearList(StrList** list) {
    StrList_free(*list);
    *list = NULL;
}
void sortList(StrList* list) {
    StrList_sort(list);
}

void checkSorted(StrList* list) {
    if (StrList_isSorted(list)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}