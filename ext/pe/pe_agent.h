#include "pe.h"

double *
loadavg() {
    double *load = malloc(3*sizeof(double));
    getloadavg(load, 3);
    return load;
}

void
cpuid(unsigned int level, unsigned int buffer[4]) {
    __cpuid(level, buffer[0], buffer[1], buffer[2], buffer[3]);
}

char *
get_cpu_vendor() {
    unsigned int buffer[4];

    cpuid(0, buffer);

    char *vendor = malloc(13*sizeof(char));

    *(unsigned int *)&vendor[0] = buffer[1];
    *(unsigned int *)&vendor[4] = buffer[3];
    *(unsigned int *)&vendor[8] = buffer[2];
    vendor[12] = '\0';

    return vendor;
}

char *
get_cpu_name() {
    unsigned int buffer[4];

    char *cpuname = malloc(49*sizeof(char));

    cpuid(0x80000000U, buffer);
    cpuid(0x80000002U, (unsigned int *)&cpuname[0]);
    cpuid(0x80000003U, (unsigned int *)&cpuname[16]);
    cpuid(0x80000004U, (unsigned int *)&cpuname[32]);

    cpuname[48] = '\0';

    return cpuname;
}

static VALUE load(VALUE self);
static VALUE vendor(VALUE self);
static VALUE cpuname(VALUE self);
static VALUE hostname(VALUE self);
