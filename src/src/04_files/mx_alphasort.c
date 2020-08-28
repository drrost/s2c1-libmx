//
// Created by Rostyslav Druzhchenko on 25.08.2020.
//

#include <libmx.h>

int mx_alphasort(const struct dirent **d1, const struct dirent **d2) {
    return mx_strcmp((*d1)->d_name, (*d2)->d_name);
}
