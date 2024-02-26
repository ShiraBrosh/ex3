#include "StrList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

// Define the structure of Node
typedef struct Node {
    char* data;
    struct Node* next;
} Node;

// Define the structure of StrList
typedef struct _StrList {
    Node* head;
    size_t size;
} StrList;

// Allocates memory for a new empty StrList
StrList* StrList_alloc() {
    StrList* newList = (StrList*)malloc(sizeof(StrList));
        newList->head = NULL;
        newList->size = 0;
    return newList;
}

Node* Node_alloc(const char* data, Node* next){
    Node *node = (Node*)malloc(sizeof(Node));
    if(node!=NULL){
        node-> data = strdup(data);
        node-> next = next;
    }
    return node;
}

// Frees the memory allocated for the node
void Node_free(Node* node){
    free(node->data);
    free(node);
}

// Frees the memory allocated for the StrList
void StrList_free(StrList* StrList){
    Node* preset= StrList->head;
    while(preset != NULL){
        Node* next= preset->next;
        Node_free(preset);
        preset=next;
    }
    free(StrList);
    StrList = NULL;
}

// Returns the number of elements in the StrList
size_t StrList_size(const StrList* StrList) {
    return StrList->size;
}


void StrList_insertLast(StrList* list, const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));                
    if (newNode == NULL) {                                       //Memory allocation failed
        return;
    }
        
    newNode->data = strdup(data);                               // Allocate memory for the string data and copy it
    if (newNode->data == NULL) {                                //Memory allocation failed
        free(newNode);
        return;
    }

    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } 
    else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;                                 // Insert the new node after the last node
    }
    list->size++;
}



// Inserts an element at the specified index in the StrList
void StrList_insertAt(StrList* StrList, const char* data, int index) {
    if(index < 0 || index > StrList->size){ 
        return; 
    }
    if(index == 0 ){
        Node* newNode = Node_alloc(data, StrList->head);
        StrList-> head = newNode;
    }
    else{
        Node* current = StrList-> head;
        int count=0;
        while (count<index-1){    
            current = current-> next;
            count++;
        }
        Node* newNode = Node_alloc(data, current-> next);
        current-> next = newNode;
    }
    StrList-> size++;
}

// Returns the first element in the StrList
char* StrList_firstData(const StrList* StrList) {
    if (StrList != NULL && StrList->size > 0){
        return StrList-> head -> data;    
    }
    else {
        return NULL;
    } 
}

// Prints all elements of the StrList to the standard output
void StrList_print(const StrList* StrList) {
    if (StrList != NULL) {
        Node* current = StrList-> head;
        for (size_t i = 0; i < StrList->size-1; ++i) {
            printf("%s ", current -> data);
            current = current-> next;
        }
            printf("%s", current-> data);
    }
}


// Prints the word at the given index to the standard output
void StrList_printAt(const StrList* Strlist, int index) {
     if(index < 0 || index > Strlist->size){ 
        return; 
    }
    
    Node* current = Strlist->head;
    int i = 0;
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }
    if (current != NULL) {
        printf("%s\n", current->data);
    }
}

// Returns the number of characters in the list
int StrList_printLen(const StrList* Strlist) {
    int totalLen = 0;
    Node* current = Strlist->head;
    while (current != NULL) {
        totalLen += strlen(current->data);
        current = current->next;
    }
    return totalLen;
}

// Returns the number of times the given string exists in the list
int StrList_count(StrList* StrList, const char* data) {
    int count = 0;
    Node* current = StrList->head;
    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// Removes all occurrences of the given string from the list
void StrList_remove(StrList* StrList, const char* data) {
    Node* current = StrList->head;
    Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            if (prev == NULL) {
                StrList->head = current->next;
            } else {
                prev->next = current->next;
            }
            Node* temp = current;
            current = current->next;
            free(temp->data);
            free(temp);
            StrList->size--;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

// Removes the string at the given index from the list
void StrList_removeAt(StrList* StrList, int index) {
    if (index < 0 || index >= StrList->size) {
        return;
    }

    Node* current = StrList->head;
    Node* prev = NULL;
    int i = 0;

    while (current != NULL && i < index) {
        prev = current;
        current = current->next;
        i++;
    }

    if (prev == NULL) {
        StrList->head = current->next;
    } else {
        prev->next = current->next;
    }

 /* in this function we dont need to know who is the current 
     after the deleted. this is the reason why we dont do a temp*/
    free(current->data);                       
    free(current);
    StrList->size--;
}

// Checks if two StrLists have the same elements
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2) {
    if (StrList1->size != StrList2->size) {
        return 0;
    }

    Node* current1 = StrList1->head;
    Node* current2 = StrList2->head;

    while (current1 != NULL) {
        if (strcmp(current1->data, current2->data) != 0) {
            return 0;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return 1;
}

// Clones the given StrList
StrList* StrList_clone(const StrList* Strlist){
    StrList* clone = StrList_alloc();
    Node* current = Strlist->head;
    while(current != NULL){
        StrList_insertLast(clone, current->data);
        current = current->next;
    }
    return clone;
}

// Helper function to swap two strings
void swapStrings(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

// Reverces the given StrList
void StrList_reverse(StrList* StrList) {
    Node* prev = NULL;
    Node* current = StrList->head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;  
        current->next = prev;  
        prev = current;        
        current = next;        
    }
    StrList->head = prev; 
}


// Helper function to calculate the Husky code for a character
int huskyCode(char c) {
    if (isupper(c)) {
        return c - 'A';
    } else {
        return c - 'a' + 26; 
    }
}

// Helper function to compare two strings based on their Husky code of the first letter
int compareStrings(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;

    int huskyCode1 = huskyCode(str1[0]);
    int huskyCode2 = huskyCode(str2[0]);

    if (huskyCode1 < huskyCode2) {
        return -1;
    } else if (huskyCode1 > huskyCode2) {
        return 1;
    } else {
        return strcmp(str1, str2);
    }
}

// Sorts the given list in lexicographical order 
void StrList_sort(StrList* StrList) {
    size_t count = StrList_size(StrList);

    char* strings[count];
    size_t index = 0;
    Node* current = StrList->head;

    while (current != NULL) {
        strings[index++] = current->data;
        current = current->next;
    }

    // Sort the array of strings
    qsort(strings, count, sizeof(char*), compareStrings);

    index = 0;
    current = StrList->head;
    while (current != NULL) {
        current->data = strdup(strings[index++]);
        current = current->next;
    }
}


// Checks if the given list is sorted in lexicographical order
// returns 1 for sorted, 0 otherwise
int StrList_isSorted(StrList* StrList) {
    Node* current = StrList->head;
    while (current != NULL && current->next != NULL) {
        if (strcmp(current->data, current->next->data) > 0) {
            return 0; // Not sorted
        }
        current = current->next;
    }
    return 1; // Sorted
}