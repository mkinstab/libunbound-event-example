ACLOCAL_AMFLAGS = -I m4

MAINTAINERCLEANFILES = $(srcdir)/Makefile.in \
  $(srcdir)/configure

AM_CFLAGS = -I$(srcdir) \
  $(libunbound_CFLAGS)

bin_PROGRAMS = libunbound-event-example

libunbound_event_example_SOURCES = main.c
libunbound_event_example_LDADD = $(libunbound_LIBS)
