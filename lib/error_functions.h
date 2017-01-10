#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

void errMsg(const char *format,...);

#ifdef __GNUC__

#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif

void errExit(const char *format,...);

void err_exit(const char *format,...);

void errExitEN(int errnum,const char *format,...);

void fatal(const char *format,...) NORETURN;

void usageErr(const char *format,...) NORETURN;

void cmdLineErr(const char *format,...) NORETURN;

#endif



