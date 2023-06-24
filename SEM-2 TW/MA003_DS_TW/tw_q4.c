/*Write a program to implement a phone directory using a singly circular linked list with
following operations. Node has info like cust_id, name, phone_number.
● Insert from first
● Insert from last
● Insert at specific position
● Delete from specific position
● Delete from first
● Delete from last
● Display in sorted order
● Search by name
● Search by cust_id
● Search by phone_number
● Delete by name
● Delete by cust_id
● Delete by phone_number*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME 100
#define MAX_PHONE_NUMBER 100

typedef struct node {
    int cust_id;
    char name[MAX_NAME];
    char phone_number[MAX_PHONE_NUMBER];
    struct node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;

void insertFromFirst(int cust_id, char name[], char phone_number[]) {
    Node* newNode = ( Node*) malloc(sizeof( Node));
    newNode->cust_id = cust_id;
    strcpy(newNode->name, name);
    strcpy(newNode->phone_number, phone_number);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    printf("\nNode with customer ID %d inserted at the beginning.", cust_id);
}

void insertFromLast(int cust_id, char name[], char phone_number[]) {
     Node* newNode = ( Node*) malloc(sizeof( Node));
    newNode->cust_id = cust_id;
    strcpy(newNode->name, name);
    strcpy(newNode->phone_number, phone_number);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    printf("\nNode with customer ID %d inserted at the end.", cust_id);
}

void insertAtPosition(int position, int cust_id, char name[], char phone_number[]) {
    if (head == NULL) {
        printf("\nList is empty. Cannot insert at position %d.", position);
        return;
    }

    int i;
     Node* temp = head;
     Node* prev = NULL;

    for (i = 0; i < position-1; i++) {
        prev = temp;
        temp = temp->next;

        if (temp == head && i != position-2) {
            printf("\nInvalid position. Cannot insert at position %d.", position);
            return;
        }
    }

     Node* newNode = ( Node*) malloc(sizeof( Node));
    newNode->cust_id = cust_id;
    strcpy(newNode->name, name);
    strcpy(newNode->phone_number, phone_number);

    if (prev == NULL) {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    } else if (temp == head && i == position-1) {
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    } else {
        prev->next = newNode;
        newNode->next = temp;
    }

    printf("\nNode with customer ID %d inserted at position %d.", cust_id, position);
}

void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("\nList is empty. Cannot delete from position %d.", position);
        return;
    }

    int i;
     Node* temp = head;
     Node* prev = NULL;

    for (i = 0; i < position-1; i++) {
        prev = temp;
        temp = temp->next;

        if (temp == head && i!= position-2) {
            printf("\nInvalid position. Cannot delete from position %d.", position);
            return;
        }
    }

    if (prev == NULL) {
        head = temp->next;
        tail->next = head;
        free(temp);
    } else if (temp == tail) {
        prev->next = head;
        tail = prev;
        free(temp);
    } else {
        prev->next = temp->next;
        free(temp);
    }
    printf("\nNode deleted from position %d.", position);
}

void deleteFromFirst() {
    if (head == NULL) {
        printf("\nList is empty. Cannot delete from first.");
        return;
    }
     Node* temp = head;

    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
        tail->next = head;
    }

    free(temp);
    printf("\nNode deleted from the beginning.");
}

void deleteFromLast() {
    if (head == NULL) {
        printf("\nList is empty. Cannot delete from last.");
        return;
    }
     Node* temp = head;
     Node* prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        head = NULL;
        tail = NULL;
    } else {
        prev->next = head;
        tail = prev;
    }

    free(temp);
    printf("\nNode deleted from the end.");
}

void displaySorted() {
    if (head == NULL) {
    printf("\nList is empty. Cannot display sorted.");
    return;
    }

     Node* current = head;
     Node* index = NULL;
    int tempCustId;
    char tempName[50];
    char tempPhoneNumber[20];

    if (head == tail) {
        printf("\nCustomer ID: %d, Name: %s, Phone Number: %s", head->cust_id, head->name, head->phone_number);
    } else {
        do {
            index = current->next;

            while (index != head) {
                if (strcmp(current->name, index->name) > 0) {
                    tempCustId = current->cust_id;
                    strcpy(tempName, current->name);
                    strcpy(tempPhoneNumber, current->phone_number);

                    current->cust_id = index->cust_id;
                    strcpy(current->name, index->name);
                    strcpy(current->phone_number, index->phone_number);

                    index->cust_id = tempCustId;
                    strcpy(index->name, tempName);
                    strcpy(index->phone_number, tempPhoneNumber);
                }

                index = index->next;
            }

            printf("\nCustomer ID: %d, Name: %s, Phone Number: %s", current->cust_id, current->name, current->phone_number);
            current = current->next;
        } while (current != head);
    }
}

void searchByName(char name[]) {
    if (head == NULL) {
        printf("\nList is empty. Cannot search by name.");
        return;
    }

     Node* current = head;
    int found = 0;

    do {
        if (strcmp(current->name, name) == 0) {
            printf("\nCustomer ID: %d, Name: %s, Phone Number: %s", current->cust_id, current->name, current->phone_number);
            found = 1;
        }
        current = current->next;
    } while (current != head);

    if (!found) {
        printf("\nCustomer with name %s not found.", name);
    }
}

void searchByCustId(int cust_id) {
    if (head == NULL) {
        printf("\nList is empty. Cannot search by customer ID.");
        return;
    }

    Node* current = head;
    int found = 0;

    do {
        if (current->cust_id == cust_id) {
            printf("\nCustomer ID: %d, Name: %s, Phone Number: %s", current->cust_id, current->name, current->phone_number);
            found = 1;
        }

        current = current->next;
    } while (current != head);

    if (!found) {
        printf("\nCustomer with ID %d not found.", cust_id);
    }
}

void searchByPhoneNumber(char* phone_number) {
    if (head == NULL) {
        printf("\nList is empty. Cannot search by phone number.");
        return;
    }

    Node* current = head;
    int found = 0;

    do {
        if (strcmp(current->phone_number, phone_number) == 0) {
            printf("\nCustomer ID: %d, Name: %s, Phone Number: %s", current->cust_id, current->name, current->phone_number);
            found = 1;
        }

        current = current->next;
    } while (current != head);

    if (!found) {
        printf("\nCustomer with phone number %s not found.", phone_number);
    }
}


void deleteByName(char name[]) {
    if (head == NULL) {
        printf("\nList is empty. Cannot delete by name.");
        return;
    }
     Node* temp = head;
     Node* prev = NULL;
    int found = 0;

    do {
        if (strcmp(temp->name, name) == 0) {
            found = 1;
            break;
        }

        prev = temp;
        temp = temp->next;
    } while (temp != head);

    if (found) {
        if (prev == NULL) {
            head = temp->next;
            tail->next = head;
            free(temp);
        } else if (temp == tail) {
            prev->next = head;
            tail = prev;
            free(temp);
        } else {
            prev->next = temp->next;
            free(temp);
        }

        printf("\nNode deleted with name %s.", name);
    } else {
        printf("\nCustomer with name %s not found.", name);
    }

}

void deleteByCustId(int cust_id) {
    if (head == NULL) {
        printf("\nList is empty. Cannot delete by customer ID.");
        return;
    }
     Node* temp = head;
     Node* prev = NULL;
    int found = 0;

    do {
        if (temp->cust_id == cust_id) {
            found = 1;
            break;
        }

        prev = temp;
        temp = temp->next;
    } while (temp != head);

    if (found) {
        if (prev == NULL) {
            head = temp->next;
            tail->next = head;
            free(temp);
        } else if(temp == tail) {
            prev->next = head;
            tail = prev;
            free(temp);
            } else {
                prev->next = temp->next;
                free(temp);
            }    
            printf("\nNode deleted with customer ID %d.", cust_id);
            } else {
        printf("\nCustomer with customer ID %d not found.", cust_id);
    }
}

void deleteByPhoneNumber(char phone_number[]) {
    if (head == NULL) {
        printf("\nList is empty. Cannot delete by phone number.");
        return;
    }

     Node* temp = head;
     Node* prev = NULL;
    int found = 0;

    do {
        if (strcmp(temp->phone_number, phone_number) == 0) {
            found = 1;
            break;
        }

        prev = temp;
        temp = temp->next;
    } while (temp != head);

    if (found) {
        if (prev == NULL) {
            head = temp->next;
            tail->next = head;
            free(temp);
        } else if (temp == tail) {
            prev->next = head;
            tail = prev;
            free(temp);
        } else {
            prev->next = temp->next;
            free(temp);
        }

        printf("\nNode deleted with phone number %s.", phone_number);
    } else {
        printf("\nCustomer with phone number %s not found.", phone_number);
    }
}

int main() {
int choice, cust_id, pos;
char name[MAX_NAME];
char phone_number[MAX_PHONE_NUMBER];

while (1) {
    printf("\n------------------------------------------------------\n");
    printf("PHONE DIRECTORY USING SINGLY CIRCULAR LINKED LIST\n");
    printf("------------------------------------------------------\n");
    printf("1. Insert from first\n");
    printf("2. Insert from last\n");
    printf("3. Insert at specific position\n");
    printf("4. Delete from specific position\n");
    printf("5. Delete from first\n");
    printf("6. Delete from last\n");
    printf("7. Display in sorted order\n");
    printf("8. Search by name\n");
    printf("9. Search by customer ID\n");
    printf("10. Search by phone number\n");
    printf("11. Delete by name\n");
    printf("12. Delete by customer ID\n");
    printf("13. Delete by phone number\n");
    printf("14. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nEnter customer ID: ");
            scanf("%d", &cust_id);
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter phone number: ");
            scanf("%s", phone_number);
            insertFromFirst(cust_id, name, phone_number);
            break;

        case 2:
            printf("\nEnter customer ID: ");
            scanf("%d", &cust_id);
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter phone number: ");
            scanf("%s", phone_number);
            insertFromLast(cust_id, name, phone_number);
            break;

        case 3:
            printf("\nEnter customer ID: ");
            scanf("%d", &cust_id);
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter phone number: ");
            scanf("%s", phone_number);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtPosition(pos,cust_id, name, phone_number);
            break;

        case 4:
            printf("\nEnter position: ");
            scanf("%d", &pos);
            deleteFromPosition(pos);
            break;

        case 5:
            deleteFromFirst();
            break;

        case 6:
            deleteFromLast();
            break;

        case 7:
            displaySorted();
            break;

        case 8:
            printf("\nEnter name to search: ");
            scanf("%s", name);
            searchByName(name);
            break;

        case 9:
            printf("\nEnter customer ID to search: ");
            scanf("%d", &cust_id);
            searchByCustId(cust_id);
            break;

        case 10:
            printf("\nEnter phone number to search: ");
            scanf("%s", phone_number);
            searchByPhoneNumber(phone_number);
            break;

        case 11:
            printf("\nEnter name to delete: ");
            scanf("%s", name);
            deleteByName(name);
            break;

        case 12:
            printf("\nEnter customer ID to delete: ");
            scanf("%d", &cust_id);
            deleteByCustId(cust_id);
            break;

        case 13:
            printf("\nEnter phone number to delete: ");
            scanf("%s", phone_number);
            deleteByPhoneNumber(phone_number);
            break;

        case 14:
            printf("\nExiting program...");
            exit(0);
            break;

        default:
            printf("\nInvalid choice. Please try again.");
    }
}

return 0;
}