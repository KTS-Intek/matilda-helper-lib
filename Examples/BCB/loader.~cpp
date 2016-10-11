#include "loader.h"
#include "functions.h"
#include <stdio.h>

#ifndef WIN32
#include <dlfcn.h>
#else
#include <windows.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

void printString(const char * const s) {
  printf("String from library: %s\n", s);
}

void loadRun(const char * const s) {
   void * lib;
   char* (*fun)(char*,int,int,int,int);
#ifndef WIN32
   lib = dlopen(s, RTLD_LAZY);
#else
   lib = LoadLibrary(s);
#endif
   if (!lib) {
     printf("cannot open library '%s'\n", s);
     return;
   }
#ifndef WIN32
   fun = (char* (*)(char*,int,int,int,int))dlsym(lib, "getHashSumm");
#else
   fun = (char* (*)(char*,int,int,int,int))GetProcAddress((HINSTANCE)lib, "getHashSumm");
#endif
   if (fun == NULL) {
     printf("cannot load function getHashSumm\n");
   } else {
	char *inChar = "hello_world";
	int inCharLen = sizeof(inChar);

       int inFormat = 0; //text
       int outFormat = 1;//base64
       int hsh = 2;//sha1
       

	printf("fun rezult = %s\n", fun(inChar,inCharLen,inFormat,outFormat,hsh));
   }
#ifndef WIN32
   dlclose(lib);
#else
   FreeLibrary((HINSTANCE)lib);
#endif
}

#ifdef __cplusplus
}
#endif
