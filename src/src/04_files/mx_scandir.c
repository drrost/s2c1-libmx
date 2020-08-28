//
// Created by Rostyslav Druzhchenko on 25.08.2020.
//

#include <libmx.h>
#include <stdlib.h>

static void swap_dirent(struct dirent **d1, struct dirent **d2) {
    struct dirent *temp = *d1;
    *d1 = *d2;
    *d2 = temp;
}

// TODO: replace array with linked list
//
int
mx_scandir(const char *dirname, struct dirent ***namelist,
           int (*select)(const struct dirent *),
           int (*compar)(const struct dirent **, const struct dirent **)) {
    // Open dir
    DIR *dir = opendir(dirname);

    // Allocate memory
    struct dirent **work = malloc(sizeof(struct dirent) * 1024);

    // Read dir's content
    int n = 0;
    struct dirent *dirent = 0;
    while ((dirent = readdir(dir))) {
        if (select(dirent)) {
            work[n] = dirent;
            n++;
        }
    }

    // Sort
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (compar((const struct dirent **)&(work[i]),
                       (const struct dirent **)&(work[j])) > 0) {
                swap_dirent(&(work[i]), &(work[j]));
            }
        }
    }

    // Close dir
    closedir(dir);

    *namelist = work;

    return 0;
}
