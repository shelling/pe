#include <ruby.h>
#include <unistd.h>

extern VALUE PE;

VALUE
hostname(VALUE self) {
    char *hostname = malloc(1024*sizeof(char));
    gethostname(hostname, 1023);
    hostname[1023] = '\0';
    VALUE result = rb_str_new2(hostname);
    free(hostname);
    return result;
}

void Init_pe_agent() {
    VALUE PE_Agent = rb_define_class_under(PE, "Agent", rb_cObject);
    rb_define_method(PE_Agent, "hostname",  hostname,   0);
}
