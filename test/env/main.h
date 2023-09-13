#ifndef _STRCMP
#define _STRCMP
int _strcmp(char *s1, char *s2);
#endif

#ifndef _STRCCMP
#define _STRCCMP
int _strccmp(char *s1, const char *s2, char c);
#endif

#ifndef _GETENV_VAL
#define _GETENV_VAL
char *getenv_val(char *env, const char *name);
#endif

#ifndef _GETENV
#define _GETENV
char *_getenv(const char *name);
#endif
