#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "pimStr.h"



int main()
{
    setlocale(LC_CTYPE,"RUSSIAN");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("¬ведите выражение: ");
    char* s = readLine();
    printf("|%s|",delSpace(s));
    return 0;
}
