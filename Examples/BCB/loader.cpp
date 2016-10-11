#include "loader.h"
#include <stdio.h>

#include <windows.h>


#ifdef __cplusplus
extern "C" {
#endif

void printString(const char * const s) {
  printf("String from library: %s\n", s);
}

void loadRun(const char * const s) {
   void * lib;
   char* (*fun)(char*,int,int,int,int);

   lib = LoadLibrary(s);

   if (!lib) {
     printf("cannot open library '%s'\n", s);
     return;
   }

   fun = (char* (*)(char*,int,int,int,int))GetProcAddress((HINSTANCE)lib, "getHashSumm");

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

   FreeLibrary((HINSTANCE)lib);

}

#ifdef __cplusplus
}
#endif
