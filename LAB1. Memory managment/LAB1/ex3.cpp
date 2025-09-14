#include <stdio.h>
#include <locale.h>
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <string>
#include "Tasks.h"
#include <cstdio>
#include <cstring>

using namespace std;

char* tasks::my_strcpy(char* dest, const char* src) {
    char* ptr = dest;
    while (*src != '\0') { 
        *dest = *src;      
        dest++;
        src++;
    }
    *dest = '\0';
    return ptr;
}