#include <stdio.h>  
#include <iostream>  
#include <cstring>  
#include <string.h>  
#include <sstream>  
  
using namespace std;  
  
char input[100];  
char tmp[100];  
char tmpSymbol[100];  
char symbol[100][100];  
int symbolLoc[100];  
int loc;
int symbolIndex;
  
char* toHexString(int afhex)  
{  
    int i;  
  
    char* ou = new char[5];  
    sprintf(ou, "%x", afhex);  
  
    for (i = 0; ou[i] != '\0'; i++)  
    {  
        if (ou[i] >= 'a' && output[i] <= 'z')  
        {  
            ou[i] -= 32;  
        }  
    }  
  
    for (int j = 0; j < 4 - i; j++)  
    {  
        printf("0");  
    }  
    return ou;  
}  
  
void doPrint()  
{  
    printf("%s %s\n", toHexString(loc), input);  
}  
  
int getLength(char* stmp)  
{  
    int output;  
    char ttmp[100];  
    char bytetmp[100];  
    string op(stmp);  
  
    if (stmp[0] == '+')  
    {  
        return 4;  
    }  
  
    if (op == "ADDR")  
    {  
        output = 2;  
    }  
    else if (op == "CLEAR")  
    {  
        output = 2;  
    }  
    else if (op == "COMPR")  
    {  
        output = 2;  
    }  
    else if (op == "DIVR")  
    {  
        output = 2;  
    }  
    else if (op == "FIX")  
    {  
        output = 1;  
    }  
    else if (op == "FLOAT")  
    {  
        output = 1;  
    }  
    else if (op == "HIO")  
    {  
        output = 1;  
    }  
    else if (op == "MULR")  
    {  
        output = 2;  
    }  
    else if (op == "NORM")  
    {  
        output = 1;  
    }  
    else if (op == "RMO")  
    {  
        output = 2;  
    }  
    else if (op == "SHIFTL")  
    {  
        output = 2;  
    }  
    else if (op == "SHIFTR")  
    {  
        output = 2;  
    }  
    else if (op == "SIO")  
    {  
        output = 1;  
    }  
    else if (op == "SUBR")  
    {  
        output = 2;  
    }  
    else if (op == "SVC")  
    {  
        output = 2;  
    }  
    else if (op == "TIO")  
    {  
        output = 1;  
    }  
    else if (op == "TIXR")  
    {  
        output = 2;  
    }  
    else if (op == "BASE")  
    {  
        output = 0;  
    }  
    else if (op == "START")  
    {  
        output = 0;  
        sscanf(input, "%s %s %x", ttmp, ttmp, &loc);  
    }  
    else if (op == "END")  
    {  
        output = -2;  
    }  
    else if (op == "BYTE")  
    {  
        int front = -1;  
        int back = -1;  
  
        sscanf(input, "%s %s %s", ttmp, ttmp, bytetmp);  
  
        for (int i = 0; bytetmp[i] != '\0'; i++)  
        {  
            if (bytetmp[i] == '\'')  
            {  
                front = i;  
                for (int j = i + 1; bytetmp[j] != '\0'; j++)  
                {  
                    if (bytetmp[j] == '\'')  
                    {  
                        back = j;  
                        break;  
                    }  
                }  
                break;  
            }  
        }  
  
        if (front != -1 && back != -1)  
        {  
            output = (back - front - 1);  
  
            if (bytetmp[0] == 'X')  
            {  
                output /= 2;  
            }  
            else if (bytetmp[0] == 'C')  
            {  
  
            }  
            else  
            {  
                output = -1;  
            }  
        }  
        else  
        {  
            output = -1;  
        }  
    }  
    else if (op == "WORD")  
    {  
        output = 3;  
    }  
    else if (op == "RESB")  
    {  
        sscanf(input, "%s %s %d", ttmp, ttmp, &output);  
    }  
    else if (op == "RESW")  
    {  
        sscanf(input, "%s %s %d", ttmp, ttmp, &output);  
        output *= 3;  
    }  
    else  
    {  
        if (op == "ADD") output = 3;  
        else if (op == "ADDF") output = 3;  
        else if (op == "AND") output = 3;  
        else if (op == "COMP") output = 3;  
        else if (op == "COMPF") output = 3;  
        else if (op == "DIV") output = 3;  
        else if (op == "DIVF") output = 3;  
        else if (op == "J") output = 3;  
        else if (op == "JEQ") output = 3;  
        else if (op == "JGT") output = 3;  
        else if (op == "JLT") output = 3;  
        else if (op == "JSUB") output = 3;  
        else if (op == "LDA") output = 3;  
        else if (op == "LDB") output = 3;  
        else if (op == "LDCH") output = 3;  
        else if (op == "LDF") output = 3;  
        else if (op == "LDL") output = 3;  
        else if (op == "LDS") output = 3;  
        else if (op == "LDT") output = 3;  
        else if (op == "LDX") output = 3;  
        else if (op == "LPS") output = 3;  
        else if (op == "MUL") output = 3;  
        else if (op == "MULF") output = 3;  
        else if (op == "OR") output = 3;  
        else if (op == "RD") output = 3;  
        else if (op == "RSUB") output = 3;  
        else if (op == "SSK") output = 3;  
        else if (op == "STA") output = 3;  
        else if (op == "STB") output = 3;  
        else if (op == "STCH") output = 3;  
        else if (op == "STF") output = 3;  
        else if (op == "STI") output = 3;  
        else if (op == "STL") output = 3;  
        else if (op == "STS") output = 3;  
        else if (op == "STSW") output = 3;  
        else if (op == "STT") output = 3;  
        else if (op == "STX") output = 3;  
        else if (op == "SUB") output = 3;  
        else if (op == "SUBF") output = 3;  
        else if (op == "TD") output = 3;  
        else if (op == "TIX") output = 3;  
        else if (op == "WD") output = 3;  
        else output = -1;  
    }  
  
    return output;  
}  
  
bool dupSymbol()  
{  
    char ttmp[100];  
    sscanf(input, "%s", ttmp);  
  
    for (int i = 0; i < symbolIndex; i++)  
    {  
        if (strcmp(ttmp, symbol[i]) == 0)  
        {  
            return true;  
        }  
    }  
    return false;  
}  
  
void renderSymbolTable()  
{  
    cout << "==========\n";  
  
    for (int i = 0; i < symbolIndex; i++)  
    {  
        //cout << symbol[i] << " " << toHexString(symbolLoc[i]) << endl;  
        cout << symbol[i] << " ";  
        printf("%s\n", toHexString(symbolLoc[i]));  
    }  
}  
  
int main()  
{  
    int spaceCounter;  
    int locPre;  
    symbolIndex = 0;  
    loc = -1;  
    while (gets(input))  
    {  
        //判斷為何種輸入  
        spaceCounter = 0;  
        for (int i = 0; input[i] != '\0'; i++)  
        {  
            if (input[i] == ' ') spaceCounter++;  
        }  
  
        //如果與table有相衝...  
        if (dupSymbol())  
        {  
            cout << "ERROR DUPSYM:";  
            printf(" %s\n", input);  
            break;  
        }  
  
        //開始進行對於每種輸入的運行  
        if (spaceCounter == 0)  
        {  
            locPre = getLength(input);  
        }  
        else if (spaceCounter == 1)  
        {  
            sscanf(input, "%s", tmp);  
            locPre = getLength(tmp);  
        }  
        else if (spaceCounter == 2)  
        {  
            sscanf(input, "%s %s", tmpSymbol, tmp);  
            locPre = getLength(tmp);  
            symbolLoc[symbolIndex] = loc;  
            strcat(symbol[symbolIndex], tmpSymbol);  
            symbolIndex++;  
        }  
        else  
        {  
            locPre = -1;  
        }  
  
        if (input[0] == '.')  
        {  
            locPre = 0;  
        }  
  
        if (locPre == -1)  
        {  
            cout << "ERROR INVALIDOP:";  
            printf(" %s\n", input);  
            break;  
        }  
  
        doPrint();  
  
        if (locPre == -2)  
        {  
            renderSymbolTable();  
            break;  
        } 
        loc += locPre;  
        memset(input, 0, sizeof(input));  
        memset(tmp, 0, sizeof(tmp));  
        memset(tmpSymbol, 0, sizeof(tmpSymbol));  
    }  
    return 0;  
}  
