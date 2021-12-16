#include <stdio.h>
#include <stdlib.h>

typedef struct e {
    double value;
    struct e *next;
} *list_t, elem_t;

list_t add(list_t lista, double inval) {
    elem_t *nowy = malloc(sizeof *nowy);
    nowy->value = inval;
    nowy->next = NULL;
    if (lista == NULL)
        lista = nowy;
    else {
        elem_t *temp = lista;
        if (temp->value > nowy->value) {
            nowy->next = temp;
            return nowy;
        } else {
            while (temp->next != NULL && temp->next->value < nowy->value)
                temp = temp->next;

            nowy->next = temp->next;
            temp->next = nowy;

        }
    }

    return lista;
}

int main() {
    list_t lista = NULL;
    lista = add(lista, 1.1);
    lista = add(lista, 2.2);
    lista = add(lista, 1.5);
    lista = add(lista, 3.3);
    lista = add(lista, -2);
    lista = add(lista, 2);

    return 0;
}
