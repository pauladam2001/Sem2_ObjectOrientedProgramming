//
// Created by paul on 3/4/2021.
//

#include "validators.h"
#include <string.h>
#include <ctype.h>


int validate_string(char name[]) {
    int i;
    for (i=0; i < strlen(name); i++) {
        if (isdigit(name[i])) {
            return 0;
        }
    }
    return 1;
}

int validate_int(char param[]) {
    int i;
    for (i=0; i < strlen(param); i++) {
        if (isalpha(param[i])) {
            return 0;
        }
    }
    return 1;
}
