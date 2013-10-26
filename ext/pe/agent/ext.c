#include "ext.h"

void Init_ext() {
    VALUE PE       = rb_define_module("PE");
    VALUE PE_Agent = rb_define_class_under(PE, "Agent", rb_cObject);
    rb_define_method(PE_Agent, "load",      load,       0);
    rb_define_method(PE_Agent, "vendor",    vendor,     0);
    rb_define_method(PE_Agent, "cpuname",   cpuname,    0);
    rb_define_method(PE_Agent, "hostname",  hostname,   0);
    rb_define_method(PE_Agent, "cpunumber", cpunumber,  0);
    rb_define_method(PE_Agent, "domainname",domainname, 0);
}

static
VALUE
load(VALUE self) {
    double *load = loadavg();
    VALUE result = rb_ary_new();
    rb_ary_push(result, rb_float_new(load[0]));
    rb_ary_push(result, rb_float_new(load[1]));
    rb_ary_push(result, rb_float_new(load[2]));
    free(load);
    return result;
}

static
VALUE
vendor(VALUE self) {
    char *vendor = get_cpu_vendor();
    VALUE result = rb_str_new2(vendor);
    free(vendor);
    return result;
}

static
VALUE
cpuname(VALUE self) {
    char *cpuname = get_cpu_name();
    VALUE result = rb_str_new2(cpuname);
    free(cpuname);
    return result;
}

static
VALUE
hostname(VALUE self) {
    char *hostname = malloc(1024*sizeof(char));
    gethostname(hostname, 1023);
    hostname[1023] = '\0';
    VALUE result = rb_str_new2(hostname);
    free(hostname);
    return result;
}

static
VALUE
cpunumber(VALUE self) {
    return INT2NUM(get_nprocs());
}

static
VALUE
domainname(VALUE self) {
    char *domainname = malloc(1024*sizeof(char));
    getdomainname(domainname, 1023);
    domainname[1023] = '\0';
    VALUE result = rb_str_new2(domainname);
    free(domainname);
    return result;
}
