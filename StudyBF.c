//
//  main.c
//  studyBF
//
//  Created by 刘洪普 on 15/3/18.
//  Copyright (c) 2015年 liuii. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define LengthOfRAM 30000
#define LengthOfROM 400

/* Declare Data Memory */
char DataMemory[LengthOfRAM];
int Dptr;

/* Declare Code Memory */
char CodeMemory[LengthOfROM];
int PC;

/* Operate the Data Memory */
void MoveLeft();
void MoveRight();
void IncreaseOne();
void DecreaseOne();
void OutputData();
void InputData();
void ResetMemeoy();

/* Operate the Code Memory */
void ReadCommands();
void ExecuteCommands();

int main(int argc, const char * argv[]) {
    while (1) {
        ReadCommands();
        if (strcmp(CodeMemory,"quit\n") == 0) {
            break;
        } else if (strcmp(CodeMemory,"version\n") == 0) {
            puts("BF Virtual Machine v0.1\nAuthor LiuII");
        } else if (strcmp(CodeMemory,"reset\n") == 0) {
            ResetMemeoy();
        }
        ExecuteCommands();
    }
    return 0;
}


/* Begin Of Operate the Data Memory */
void MoveLeft() {
    if (Dptr == 0) {
        Dptr = LengthOfRAM - 1;
    } else {
        Dptr --;
    }
}

void MoveRight() {
    if (Dptr == LengthOfRAM - 1) {
        Dptr = 0;
    } else {
        Dptr ++;
    }
}

void IncreaseOne(){
    DataMemory[Dptr] ++;
}

void DecreaseOne(){
    DataMemory[Dptr] --;
}

void OutputData() {
    putchar(DataMemory[Dptr]);
}

void InputData(){
    DataMemory[Dptr] = getchar();
}

void ResetMemeoy() {
    Dptr = 0; // Reset Data Pointer
    /* Reset Memory */
    for(int index = 0; index < LengthOfRAM; index ++) {
        DataMemory[index] = 0;
    }
    puts("All Data Memory Cleared.");
}
/* End Of Operate the Data Memory */

/* Begin of Operate the Code Memory */
void ReadCommands() {
    printf("\nBF>");
    fgets(CodeMemory,LengthOfROM,stdin);
}

void ExecuteCommands() {
    PC = 0;
    while (CodeMemory[PC] != '\0') {
        switch (CodeMemory[PC]) {
            case '>':
                MoveRight();
                PC ++;
                break;
            case '<':
                MoveLeft();
                PC ++;
                break;
            case '+':
                IncreaseOne();
                PC ++;
                break;
            case '-':
                DecreaseOne();
                PC ++;
                break;
            case '.':
                OutputData();
                PC ++;
                break;
            case ',':
                InputData();
                PC ++;
                break;
            default:
                PC ++;
        }
    }
}
/* End of Operate the Code Memory */











