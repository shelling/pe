#include <ruby.h>
#include "pe.h"

VALUE PE = Qnil;

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

VALUE
vendor(VALUE self) {
    char *vendor = get_cpu_vendor();
    VALUE result = rb_str_new2(vendor);
    free(vendor);
    return result;
}

VALUE
cpuname(VALUE self) {
    char *cpuname = get_cpu_name();
    VALUE result = rb_str_new2(cpuname);
    free(cpuname);
    return result;
}

void
Init_pe() {
    PE = rb_define_module("PE");
    rb_define_method(PE, "load",        load,       0);
    rb_define_method(PE, "vendor",      vendor,     0);
    rb_define_method(PE, "cpuname",     cpuname,    0);
}
