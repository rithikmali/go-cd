%{
	#include<stdio.h>
    #include "cdgolanghead.h"
%}


%%

\/\/.* ;
"/*"[^*]*"*"+([^*/][^*]*"*"+)*"/"  ;
. printf("unexpected character");
%%
int yywrap(void)
{
    return 1;
}
