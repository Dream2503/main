#include<stdio.h>
#include <string.h>

main() {
    char s1[] = "NEW DELHI";
    char s2[] = " BANGALORE";
    strncpy(s1,s2,3);
    printf("%s",s1);
    printf("%s",s2);
}