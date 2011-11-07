#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <unistd.h>
#include <ruby.h>

void
rb_raise(unsigned long exc, const char *fmt, ...)
{
  static void (*libruby_rb_raise)
    (unsigned long exc, const char *fmt, ...) = NULL;

  void * handle;
  char * error;

  if (!libruby_rb_raise) {
    handle = dlopen("/home/john/.rvm/rubies/ruby-1.9.2-p180/lib/libruby.so",
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

  //printf("calling old rb_raise()");
  fflush(stdout);
//  libruby_rb_raise(exc, "i want to see you naked, especially from the back.");
  rb_funcall(rb_cObject, rb_intern("raise"), 2, exc, rb_str_new2("hello baby"));
//  printf("finished calling old rb_raise()\n");
  fflush(stdout);
}

