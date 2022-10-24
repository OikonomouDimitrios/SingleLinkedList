#include <stdio.h>
#include <stdlib.h>

typedef struct tf *tp;
struct tf {
    int am;
    double grade;
    tp next;
};
tp head, tail, temp, aux;


void insertRecord(tp *h, tp t);

void printRecords(tp h);

void deleteRecord(tp *h, tp t);

char handleInput(char input);

int main(void) {
    head = NULL;
    int num1 = 0;
    char input;
    printf("\nselect action: ");
    printf("\ngive i/d/p for insert,delete,print: ");
    fflush(stdin);
    input = getchar();

    while (input != 'q') {
        handleInput(input);
        printf("\nselect action: ");
        printf("\ngive i/d/p for insert,delete,print: ");
        fflush(stdin);
        input = getchar();
    }

    printf("");
    return 0;
}

char handleInput(char input) {
    if (input == 'i') {
        insertRecord(&head, tail);
    } else if (input == 'p') {
        printRecords(head);
    } else if (input == 'q') {
        printf("\nexiting program!");
    } else if (input == 'd') {
        deleteRecord(&head, tail);
    } else {
        printf("\ninvalid input!");
    }
    return input;
}

void insertRecord(tp *h, tp t) {
    tp te, a;
    int am;
    double grade;
    printf("give me an AM");
    scanf("%d", &am);
    printf("give me a grade");
    scanf("%lf", &grade);
    te = (tp) malloc(sizeof(struct tf));
    te->am = am;
    te->grade = grade;
    te->next = NULL;
    //case when head is null
    if ((*h) == NULL) {
        *h = te;
        t = te;
    } else {
        if ((*h)->next == NULL) {
            //case when temp am is less than header am
            if ((*h)->am > te->am) {
                //next of temp points to previously header
                te->next = *h;
                //header points now to temp
                *h = te;
            } else {
                //case when next of head is null and head is less than temp
                (*h)->next = te;
            }
        } else {
            //case when temp is bigger than head and more than 1 records exist
            if (*h != NULL && (*h)->next != NULL && te->am > (*h)->am) {
                a = *h;
                while (a->next != NULL && a->next->am < te->am) {
                    a = a->next;
                }
                //pointer of temp points to previous next record of aux
                te->next = a->next;
                //new next record of aux points to temp
                a->next = te;
            }
        }

    }
}

void deleteRecord(tp *h, tp t) {
    tp te, a;
    int am;
    printf("give me an AM to delete");
    scanf("%d", &am);
    if (*h == NULL) {
        printf("\nlist is empty!");
    } else {
        if ((*h)->next != NULL) {
            printf("\n list has more than one element(s)");
        }
        if ((*h)->am == am) {
            a = *h;
            *h = (*h)->next;
            free(a);
            if (*h == NULL) {
                printf("\n list is now empty");
            }
        } else {
            a = *h;
            while (a->next != NULL && a->next->am != am) {
                a = a->next;
            }
            if (a->next == NULL) {
                printf("\n record not found");
            } else {
                temp = a->next;
                a->next = temp->next;
                free(temp);
            }
        }
    }
}

void printRecords(tp h) {
    tp a;
    a = h;
    while ((a) != NULL) {
        printf("\nam is: %d , grade is : %lf", a->am, a->grade);
        a = a->next;
    }
}
