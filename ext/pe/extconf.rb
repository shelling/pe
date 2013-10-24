require "mkmf"

have_header     "cpuid.h"
have_header     "sys/sysinfo.h"
create_makefile "pe/pe"
