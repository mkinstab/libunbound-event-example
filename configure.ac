AC_PREREQ(2.64)
AC_INIT([libunbound-event-example], [0.1.0])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O

PKG_CHECK_MODULES([libunbound], [libunbound >= 1.9.0],, [AC_MSG_ERROR([libunbound not found])])

# Output Makefiles
AC_CONFIG_FILES([
  Makefile
])
AC_OUTPUT
