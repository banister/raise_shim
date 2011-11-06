#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <unistd.h>

void
rb_raise(unsigned long exc, const char *fmt, ...)
{
  static void (*libruby_rb_raise)
    (unsigned long exc, const char *fmt, ...) = NULL;

  void * handle;
  char * error;

  if (!libruby_rb_raise) {
    handle = dlopen("/Users/john/.rvm/src/ruby-1.9.3-p0/libruby.1.9.1.dylib",
                    RTLD_LAZY);
    if (!handle) {
      fputs(dlerror(), stderr);
      exit(1);
    }
    libruby_rb_raise = dlsym(handle, "rb_raise");
    if ((error = dlerror()) != NULL) {
      fprintf(stderr, "%s\n", error);
      exit(1);
    }
  }

  printf("calling old rb_raise()");
  libruby_rb_raise(exc, fmt);
  printf("finished calling old rb_raise()\n");
}
