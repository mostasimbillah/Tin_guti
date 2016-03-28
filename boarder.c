#include<stdio.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>
#include <stdlib.h>
#include <conio.h>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib") //Winsock Library
struct coordinate{
    int x;
    int y;
    int direction;
};

typedef struct coordinate coordinate;

coordinate head, bend[500],food,body[30];
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
 }
void Boarder()
{
    system("cls");

    int i,j;

    GotoXY(19,2);   /*displaying food*/
        printf("F");


    for(i=1;i<=20;i++)
    {
        GotoXY(i,1);
            printf("%c",177);//Upper Boarder
        GotoXY(i,20);
            printf("%c",177);// Lower Boarder
        GotoXY(i,10);
            printf("%c",177);
    }

    for(i=1;i<=20;i++)
    {

        GotoXY(1,i);
             printf("%c",177);// Left Side
        GotoXY(20,i);
           printf("%c",177);//Right side
        GotoXY(10,i);
            printf("%c",177);// Middle side Y axis
    }

    for(i=1,j=1;i<=20,j<=20;j++)
    {
         GotoXY(i,j);
            printf("%c",176); // Diagonal side

       i=i+1;
    }
     system("COLOR 3A");
    for(i=20,j=1;i>=1,j<=20;j++)
    {
         GotoXY(i,j);
            printf("%c",176); // Diagonal side



       i=i-1;
    }

}


int main(int argc , char *argv[])
{

    Boarder();


    printf("\n\nHello World;");

    return 0;

}
