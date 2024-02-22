#include "StrList.h"
#include <stdio.h>

void insertStrings(StrList* list);
void insertStringAtIndex(StrList* list);
void printList(const StrList* list);
void printListLength(const StrList* list);
void printStringAtIndex(const StrList* list);
void printTotalCharCount(const StrList* list);
void printStringOccurrences(StrList* list);
void removeStringOccurrences(StrList* list);
void removeStringAtIndex(StrList* list);
void clearList(StrList* list);
void sortList(StrList* list);
void checkSorted(StrList* list);

int main (){
int choice = 20;  // Initialize choice to any non 0 value
StrList* list = StrList_alloc();

    while(choice != 0){
        scanf(" %d",&choice);
        
        if(choice == 1) {
            insertStrings(list);
        }
        else if(choice == 2) {
            insertStringAtIndex(list);
        }
        else if(choice == 3) {
            printList(list);
        }
        else if(choice == 4) {
            printListLength(list);
        }
        else if(choice == 5) {
            printStringAtIndex(list);
        }
        else if(choice == 6) {
            printTotalCharCount(list);
        }
        else if(choice == 7) {
            printStringOccurrences(list);
        }
        else if(choice == 8) {
            removeStringOccurrences(list);
        }
        else if(choice == 9) {
            removeStringAtIndex(list);
        }
        else if(choice == 10) {
            clearList(list);
        }
        else if(choice == 11) {
            sortList(list);
        }
        else if(choice == 12) {
            checkSorted(list);
        }
    }

    StrList_free(list);
    return 0;
}


void insertStrings(StrList* list) {
    int numStrings;
    printf("Enter the number of words you want to insert: ");
    scanf("%d", &numStrings);

    for (int i = 0; i < numStrings; i++) {
        char word[100];
        printf("Enter word %d: ", i + 1);
        scanf("%s", word);
        StrList_insertLast(list, word);
    }
}

void insertStringAtIndex(StrList* list) {
    int index;
    char word[100];
    printf("Enter the index to insert the word: ");
    scanf("%d", &index);
    printf("Enter the word to insert: ");
    scanf("%s", word);
    StrList_insertAt(list, word, index);
}

void printList(const StrList* list) {
    printf("List contents:\n");
    StrList_print(list);
}

void printListLength(const StrList* list) {
    printf("Length of the list: %zu\n", StrList_size(list));
}

void printStringAtIndex(const StrList* list) {
    int index;
    printf("Enter the index of the string to print: ");
    scanf("%d", &index);
    StrList_printAt(list, index);
}

void printTotalCharCount(const StrList* list) {
    printf("Total number of characters in the list: %d\n", StrList_printLen(list));
}

void printStringOccurrences(StrList* list) {
    char word[100];
    printf("Enter the word to count occurrences: ");
    scanf("%s", word);
    printf("Occurrences of '%s': %d\n", word, StrList_count(list, word));
}

void removeStringOccurrences(StrList* list) {
    char word[100];
    printf("Enter the word to remove occurrences: ");
    scanf("%s", word);
    StrList_remove(list, word);
}

void removeStringAtIndex(StrList* list) {
    int index;
    printf("Enter the index of the string to remove: ");
    scanf("%d", &index);
    StrList_removeAt(list, index);
}

void clearList(StrList* list) {
    StrList_free(list);
    printf("List cleared.\n");
}

void sortList(StrList* list) {
    StrList_sort(list);
    printf("List sorted in lexicographical order.\n");
}

void checkSorted(StrList* list) {
    if (StrList_isSorted(list)) {
        printf("The list is arranged in lexicographical order.\n");
    } else {
        printf("The list is not arranged in lexicographical order.\n");
    }
}