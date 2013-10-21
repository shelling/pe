require "mkmf"

have_header     "cpuid.h"
dir_config      "pe/pe"
create_makefile "pe/pe"
