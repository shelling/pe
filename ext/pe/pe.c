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

void
Init_pe() {
    PE = rb_define_module("PE");
    rb_define_method(PE, "load", load, 0);
}
