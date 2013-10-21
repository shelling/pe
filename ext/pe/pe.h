#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cpuid.h>

double *
loadavg() {
    double *load = malloc(3*sizeof(double));
    getloadavg(load, 3);
    return load;
}
