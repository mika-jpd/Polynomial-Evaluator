#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"
#include "polyterm.h"
#include "poly.h"

struct PolyTerm *head;

int addPolyTerm (int coef, int pow)
{
    // Dynamic programming WowoWOoWoWOWO
    // I use malloc to create space for the toAdd pointer
    struct PolyTerm *toAdd = malloc(sizeof(struct PolyTerm));

    if (toAdd == NULL) {
        printf("Failed to add");
        return -1;
    }
    toAdd->next = NULL;
    toAdd->coeff = coef;
    toAdd->expo = pow;

    // If there is no head I create one
    if (head == NULL) {
        head = toAdd;
        return 0;
    }

    struct PolyTerm *temp = head;
    struct PolyTerm *before = head;

    // I iterate through the LinkedList.
    // After the first iteration, temp will be one ahead of before, I use before to
    // help me insert nodes inside a LinkedList
    while (temp != NULL) {
  
        if (temp->expo == toAdd->expo) {
            temp->coeff = temp->coeff + toAdd->coeff;
            free(toAdd);
            toAdd == NULL;
            return 0;
        }
        else if (temp->expo > toAdd->expo) {
            if (head == temp) {
                head = toAdd;
                toAdd->next = temp;
                return 0;
            }
            toAdd->next = temp;
            before->next = toAdd;
            return 0;
        }

        if (temp->next == NULL) {
            temp->next = toAdd;
            return 0;
        }

        if (temp == head) {
            temp = temp->next;
        }
        else {
            temp = temp->next;
            before = before->next;
        }
    }
    return 0;
}

void displayPolynomial ()
{
    struct PolyTerm *temp = head;
    int i = 0;
    while (temp != NULL) {
        i++;
        temp = temp->next;
    }
    /* I use sprintf to create a string for the entire polynomial.
    since sprintf cannot account for negative numbers, I multiply any number by negative one
    and add it with a '-' in front of it!
    */
    char *string = malloc(i*sizeof(struct PolyTerm));
    temp = head;
    while (temp != NULL) {
        char *coeff1 = calloc(temp->coeff*temp->coeff, sizeof(int));
        char *expo1 = calloc(temp->expo, sizeof(int));
        if (temp->coeff < 0) {
            int toAdd = (-1)*temp->coeff;
            sprintf(coeff1, "-%d", toAdd);
            sprintf(expo1, "x%d", temp->expo);
        }
        else {

            sprintf(coeff1, "+%d", temp->coeff);
            sprintf(expo1, "x%d", temp->expo);
        }
        
        strcat(string, coeff1);
        strcat(string, expo1);

        free(coeff1);
        free(expo1);
        temp = temp->next;
    }
    printf("%s\n", string);
}
