#include "pe.h"

VALUE PE;

void
Init_pe() {
    PE = rb_define_module("PE");

    Init_pe_agent();
}
