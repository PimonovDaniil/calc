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
    printf("������� ���������: ");
    char* s = readLine();
    s = delSpace(s); //������� ��� �������, ����� �� ������
    if(checkSymStr(s)){//���� � ������ ���������� �������

    }
    return 0;
}
