#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>

int c=177;//For boarder
int d=167;// For Boarder
int p1_color=10,p2_color=3,blank_color=22;//.....Pawns color........
int color;
char *chr[9];//...........Theme Color..........

void do_you_save();
void error();
void ret_menu();
void highsc();
void record(char player1[20],char player2[20]);
void Exit();
int menu();
void display(int (*position)[3],int name1,int name2,int player1_count,int player2_count);
int shortcut2(int a,int *arr[3][3]);
void shortcut(int a,int *arr[3][3],int player);
void move(int *arr[3][3],int z1,int p1,int player);
void checklala(int i,int j,int *arr[3][3],int player,int *arr2[9][8],int *a);
void loading();
void logo();
void SetColor(int ForgC);


int main()
{
    int position[3][3],player=0,k,l;
    int i,j,mod=0;
    int a;
    char t;
    FILE *info;
    char ccc;
    char name1[30];
    char name2[30];
    char name3[30];
    char name4[30];
    int player1_count=0,player2_count=0;
    logo();
    int menu_item=menu();

    X :
    system("cls");
    getchar();
    switch(menu_item)
    {
        case 1:
            loading();
            system("cls");
            printf("\n\n\n\n\t\t\t\t   ..GUTI-BAJ..\n\n\n");
            //......Getting Player Name..........
            printf("\t\t\t  Enter 1st player name: ");
            gets(name1);
            strcpy(name3,name1);
            printf("\n\t\t\t  Enter 2nd player name: ");
            gets(name2);
            strcpy(name4,name2);
            int length1;
            length1=strlen(name1);
            char str1[30];
            int name_iterator;
            //........Name Space solver for scoreboard..........//
            for(name_iterator=0;name_iterator<13-length1;name_iterator++)
            {
                str1[name_iterator]=' ';
            }
            str1[13-length1]='\0';
            //....Putting Space into name ........
            strcat(name1,str1);
            int length2;
            length2=strlen(name2);
            char str2[30];
            for(name_iterator=0;name_iterator<13-length2;name_iterator++)
            {
                str2[name_iterator]=' ';
            }
            str2[13-length2]='\0';
            strcat(name2,str2);
            //.........Game Started here.......
            for(;;)
            {
                system("cls");
                //........Set Player pawns default.........
                position[0][0]=1;
                position[0][1]=1;
                position[0][2]=1;
                position[1][0]=0;
                position[1][1]=0;
                position[1][2]=0;
                position[2][0]=2;
                position[2][1]=2;
                position[2][2]=2;
                //..........Movement restriction here............
                int    A[9][8] = { { 2,4,5,0,0, 0, 0, 0 },
                { 1,3,5,0,0, 0, 0, 0 },
                { 2,5,6,0,0, 0, 0, 0 },
                { 1,5,7,0,0, 0, 0, 0 } ,
                { 1,2,3,4,6, 7, 8, 9 } ,
                { 3,5,9,0,0, 0, 0, 0 } ,
                { 4,5,8,0,0, 0, 0, 0 } ,
                { 5,7,9,0,0, 0, 0, 0 } ,
                { 5,6,8,0,0, 0, 0, 0 }

                };
                display(position,name1,name2,player1_count,player2_count);
                for(;;)
                {
                   //.... Mod for changing player Turns........
                   //... 1st Player turn........
                    if(a%2==0)
                    {
                        player=1;
                        printf("%s's turn: \n",name3);
                        printf("Move point: ");
                        scanf("%d",&i);
                        system("cls");
                        display(position,name1,name2,player1_count,player2_count);
                        printf("%s's turn: \n",name3);
                        printf("Where to move: ");
                        scanf("%d",&k);
                        checklala(i,k,position,player,A,&a);
                    }
                    else
                        //.....2nd Player turns............
                    {
                        player=2;
                        printf("%s's turn: \n",name4);
                        printf("Move point: ");
                        scanf("%d",&i);
                        system("cls");
                        display(position,name1,name2,player1_count,player2_count);
                        printf("%s's turn: \n",name4);
                        printf("Where to move: ");
                        scanf("%d",&k);
                        checklala(i,k,position,player,A,&a);
                    }
                    display(position,name1,name2,player1_count,player2_count);
                    //......Checking Player's win or not..........

                    if((position[0][0]==1&&position[1][0]==1&&position[2][0]==1)||
                    (position[0][1]==1&&position[1][1]==1&&position[2][1]==1)||
                    (position[0][2]==1&&position[1][2]==1&&position[2][2]==1)||
                    (position[0][0]==1&&position[1][1]==1&&position[2][2]==1)||
                    (position[0][2]==1&&position[1][1]==1&&position[2][0]==1)||
                    (position[2][0]==1&&position[2][1]==1&&position[2][2]==1)||//player one 1st position skip
                    (position[1][0]==1&&position[1][1]==1&&position[1][2]==1))
                    {
                        system("cls");
                        player1_count++;
                        printf("\n\n\n\n\n\n\n\n \t\t\t***  %s you get [ %d ] point ***\n",name3,player1_count);
                        Sleep(3000);
                        //....Reset position of pawns to default..........
                        position[0][0]=1;
                        position[0][1]=1;
                        position[0][2]=1;
                        position[1][0]=0;
                        position[1][1]=0;
                        position[1][2]=0;
                        position[2][0]=2;
                        position[2][1]=2;
                        position[2][2]=2;
                        player=0;
                        mod++;// Changing players turns after win or lose.....
                        a=mod;
                        display(position,name1,name2,player1_count,player2_count);
                        //......After wining 3 times to get victory.......
                        if(player1_count>=3)
                        {
                            a=0;
                            mod=0;
                            player1_count=0;
                            int win1;
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t    The winner is: %s  !!!!\n",name3);
                            Sleep(3000);
                            system("cls");
                            //........Confirming for saving game information...........
                            do_you_save();
                            int yesno1;
                            scanf("%d",&yesno1);
                            if(yesno1==1)
                            {
                                record(name3,name4);
                            }
                            system("cls");
                            //...Showing return menu.........
                            Y: ret_menu();
                            scanf("%d",&win1);
                            system("cls");
                            if(win1==1)
                            {
                                menu_item=menu();//......Menu item show........
                                goto X;
                            }
                            else if(win1==2)
                                Exit();//........For exit...........
                            else
                            {
                                error();
                                system("cls");
                                goto Y;
                            }
                        }

                    }
                    //.........Checking 2nd player win or not..........
                    else if((position[0][0]==2&&position[1][0]==2&&position[2][0]==2)||
                    (position[0][1]==2&&position[1][1]==2&&position[2][1]==2)||
                    (position[0][2]==2&&position[1][2]==2&&position[2][2]==2)||
                    (position[0][0]==2&&position[1][1]==2&&position[2][2]==2)||
                    (position[0][2]==2&&position[1][1]==2&&position[2][0]==2)||
                    (position[0][0]==2&&position[0][1]==2&&position[0][2]==2)||//plyer two 1st postion skip
                    (position[1][0]==2&&position[1][1]==2&&position[1][2]==2))
                    {
                        system("cls");
                        player2_count++;
                        printf("\n\n\n\n\n\n\n\n \t\t\t***  %s you get [ %d ] point ***\n",name4,player2_count);
                        Sleep(3000);
                        position[0][0]=1;
                        position[0][1]=1;
                        position[0][2]=1;
                        position[1][0]=0;
                        position[1][1]=0;
                        position[1][2]=0;
                        position[2][0]=2;
                        position[2][1]=2;
                        position[2][2]=2;
                        player=0;
                        mod++;
                        a=mod;
                        display(position,name1,name2,player1_count,player2_count);
                        if(player2_count>=3)
                        {
                            a=0;
                            mod=0;
                            player2_count=0;
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\t\t\t    The winner is: %s  !!!!\n",name4);
                            Sleep(3000);
                            system("cls");
                            do_you_save();
                            int yesno1;
                            scanf("%d",&yesno1);
                            if(yesno1==1)
                            {
                                record(name4,name3);
                            }
                            system("cls");
                            W: ret_menu();
                            int win2;
                            scanf("%d",&win2);
                            system("cls");
                            if(win2==1)
                            {
                                menu_item=menu();
                                goto X;
                            }
                            else if(win2==2)
                                Exit();
                            else
                            {
                                error();
                                system("cls");
                                goto W;
                            }
                        }
                    }
                }
            }
            break;
            //.... For high score menu.............
            case 2:
                highsc();//.....Showing data........
                M: ret_menu();
                scanf("%c",&t);
                system("cls");
                if(t==49)
                {
                    menu_item=menu();
                    goto X;
                }
                else if(t==50)
                    Exit();
                else
                {
                    error();
                    system("cls");
                    goto M;
                }
                break;
                //........Setting menu............
            case 3:
                system("cls");
                system(*chr);//......changing color.......
                 system("cls");
                 printf("\n\n\n\n\n\t\t\t   ************************\n");
                 printf("\t\t\t   ************************\n");
                 printf("\t\t\t   *                      *\n");
                 printf("\t\t\t   *  1.Theme             *\n");
                 printf("\t\t\t   *                      *\n");
                 printf("\t\t\t   *  2.Player icon color *\n");
                 printf("\t\t\t   *                      *\n");
                 printf("\t\t\t   ************************\n");
                 printf("\t\t\t   ************************\n");
                 int x2;
                 printf("\t\t\t    Choose your Options :");
                 scanf("%d",&x2);
                 //.........Theme Color Change.........
                 if(x2==1)
                 {
                     system("cls");
                     printf("\n\n\n\n\n\t\t\t   ************************\n");
                     printf("\t\t\t   ************************\n");
                     printf("\t\t\t   *                      *\n");
                     printf("\t\t\t   *  1. Black & White    *\n");
                     printf("\t\t\t   *  2. Green            *\n");
                     printf("\t\t\t   *  3. Blue(Default)    *\n");
                     printf("\t\t\t   *  4. Light yellow     *\n");
                     printf("\t\t\t   *                      *\n");
                     printf("\t\t\t   ************************\n");
                     printf("\t\t\t   ************************\n");
                     int select;
                     scanf("%d",&select);
                     //..Selecting color to apply as theme.........
                     switch (select)
                     {
                        case 1:
                             //getchar();
                            *chr="COLOR 07";//....changing color code.......
                            system(*chr);
                            SET: ret_menu();
                            scanf("%c",&t);
                            system("cls");
                            if(t==49)
                            {
                                menu_item=menu();
                                goto X;
                            }
                            else if(t==50)
                                Exit();
                            else
                            {
                                system("cls");
                                goto SET;
                            }
                            break;
                     case 2:
                        *chr="COLOR 2A";
                        system(*chr);
                        SET2: ret_menu();
                        scanf("%c",&t);
                        system("cls");
                        if(t==49)
                        {
                            menu_item=menu();
                            goto X;
                        }
                        else if(t==50)
                            Exit();
                        else
                        {

                            system("cls");
                            goto SET2;
                        }
                        break;
                     case 3:
                        *chr ="COLOR 1A";
                        system(*chr);
                        SET3: ret_menu();
                        scanf("%c",&t);
                        system("cls");
                        if(t==49)
                        {
                            menu_item=menu();
                            goto X;
                        }
                        else if(t==50)
                            Exit();
                        else
                        {

                            system("cls");
                            goto SET3;
                        }
                        break;
                     case 4:
                        system("cls");
                        *chr = "COLOR E3";
                        system(*chr);
                        SET4: ret_menu();
                        scanf("%c",&t);
                        system("cls");
                        if(t==49)
                        {
                            menu_item=menu();
                            goto X;
                        }
                        else if(t==50)
                            Exit();
                        else
                        {

                            system("cls");
                            goto SET4;
                        }
                        break;
                     }
                }
                break;
                //.......TODO.......
            case 4:
                loading();
                system("cls");
                int x3;
                F: ret_menu();
                scanf("%d",&x3);
                system("cls");
                if(x3==1)
                {
                    menu_item=menu();
                    goto X;
                }
                else if(x3==2)
                    Exit();
                else
                {
                    error();
                    system("cls");
                    goto F;
                }
                break;
            case 5:
                loading();
                system("cls");
                int x4;
                Z: ret_menu();
                scanf("%d",&x4);
                system("cls");
                if(x4==1)
                {
                    menu_item=menu();
                    goto X;
                }
                else if(x4==2)
                    Exit();
                else
                {
                    error();
                    system("cls");
                    goto Z;
                }
                break;
            case 6:
                loading();
                system("cls");
                int x5;
                N: ret_menu();
                scanf("%d",&x5);
                system("cls");
                if(x5==1)
                {
                    menu_item=menu();
                    goto X;
                }
                else if(x5==2)
                    Exit();
                else
                {
                    error();
                    system("cls");
                    goto N;
                }
                break;
                //.........Exiting From Game...........
            case 7:
                system("cls");
                Exit();
                break;
            default:
                error();
                system("cls");
                menu_item=menu();
                goto X;

    }
    return 0;
}



void Exit()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n    \t\t\t       ** THANK YOU **\n\n\n");
    Sleep(4000);
    exit(0);
}

int menu()
{
    int menu;
    printf("\n\n\t\t\t  ..WELCOME TO GUTI-BAJ..\n");
    printf("\n\n");
    printf("\t\t\t  ******* M E N U *******\n");
    printf("\t\t\t  %c                     %c\n",c,c);
    printf("\t\t\t  %c   1. New Game       %c\n",c,c);
    printf("\t\t\t  %c   2. High Score     %c\n",c,c);
    printf("\t\t\t  %c   3. Settings       %c\n",c,c);
    printf("\t\t\t  %c   4. Account        %c\n",c,c);
    printf("\t\t\t  %c   5. Instructions   %c\n",c,c);
    printf("\t\t\t  %c   6. About          %c\n",c,c);
    printf("\t\t\t  %c   7. Exit           %c\n",c,c);
    printf("\t\t\t  %c                     %c\n",c,c);
    printf("\t\t\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\t\t\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\t\t\t  Choose your option : ");
    scanf("%d",&menu);

    return menu;
}


void display(int (*position)[3],int name1,int name2,int player1_count,int player2_count)
{
    system(*chr);
    printf("\n");
    if(position[0][0]==1)
    {
        color=p1_color;
    }
    else if(position[0][0]==2)
    {
        color=p2_color;
    }
    else
    {
        color=blank_color;
    }

    SetColor(color);
    printf("     [%d]",position[0][0]);
    SetColor(15);
    printf("%c%c%c%c%c%c%c%c",c,c,c,c,c,c,c,c);
    if(position[0][1]==1)
    {
        color=p1_color;
    }
    else if(position[0][1]==2)
    {
        color=p2_color;
    }
    else
    {
        color=blank_color;
    }

    SetColor(color);
    printf("[%d]",position[0][1]);
    SetColor(15);
    printf("%c%c%c%c%c%c%c%c",c,c,c,c,c,c,c,c);
    if(position[0][2]==1)
    {
        color=p1_color;
    }
    else if(position[0][2]==2)
    {
        color=p2_color;
    }
    else
    {
        color=blank_color;
    }

    SetColor(color);
    printf("[%d]",position[0][2]);
    SetColor(15);
    printf("                              /-----------------\\\n");
    printf("     %c%c         %c%c%c         %c%c",c,c,c,c,c,c,c);
    printf("                              |%s: %d |\n",name1,player1_count);
    printf("     %c %c        %c%c%c        %c %c",c,c,c,c,c,c,c);
    printf("                              |-----------------|\n");
    printf("     %c  %c       %c%c%c       %c  %c",c,c,c,c,c,c,c);
    printf("                              |%s: %d |\n",name2,player2_count);
    printf("     %c   %c      %c%c%c      %c   %c",c,c,c,c,c,c,c);
    printf("                              \\-----------------/\n");
    printf("     %c    %c     %c%c%c     %c    %c\n",c,c,c,c,c,c,c);
    printf("     %c     %c    %c%c%c    %c     %c",c,c,c,c,c,c,c);
    printf("   O********************************************O\n");
    printf("     %c      %c   %c%c%c   %c      %c",c,c,c,c,c,c,c);
    printf("   %c                                            %c\n",176,176);
    printf("     %c       %c  %c%c%c  %c       %c",c,c,c,c,c,c,c);
    printf("   %c  [1]---[2]---[3]                           %c\n",176,176);
    printf("     %c        %c %c%c%c %c        %c",c,c,c,c,c,c,c);
    printf("   %c   |\\    |    /|                            %c\n",176,176);
    printf("     %c         %c%c%c%c%c         %c",c,c,c,c,c,c,c);
    printf("   %c   |  \\  |  /  |                            %c\n",176,176);
    if(position[1][0]==1)
    {
        color=p1_color;
    }
    else if(position[1][0]==2)
    {
        color=p2_color;
    }
    else
    {
        color=blank_color;
    }

    SetColor(color);
    printf("     [%d]",position[1][0]);
    SetColor(15);
    printf("%c%c%c%c%c%c%c%c",c,c,c,c,c,c,c,c);
    if(position[1][1]==1)
    {
        color=p1_color;
    }
    else if(position[1][1]==2)
    {
        color=p2_color;
    }
    else
    {
        color=blank_color;
    }

    SetColor(color);
    printf("[%d]",position[1][1]);
    SetColor(15);
    printf("%c%c%c%c%c%c%c%c",c,c,c,c,c,c,c,c);
    if(position[1][2]==1)
    {
        color=p1_color;
    }
    else if(position[1][2]==2)
    {
        color=p2_color;
    }
    else
    {
        color=blank_color;
    }

    SetColor(color);
    printf("[%d]",position[1][2]);
    SetColor(15);
    printf("   %c   |    \\|/    |                            %c\n",176,176);
    printf("     %c         %c%c%c%c%c         %c",c,c,c,c,c,c,c);
    printf("   %c  [4]---[5]---[6]                           %c\n",176,176);
    printf("     %c        %c %c%c%c %c        %c",c,c,c,c,c,c,c);
    printf("   %c   |    /|\\    |                            %c\n",176,176);
    printf("     %c       %c  %c%c%c  %c       %c",c,c,c,c,c,c,c);
    printf("   %c   |  /  |  \\  |                            %c\n",176,176);
    printf("     %c      %c   %c%c%c   %c      %c",c,c,c,c,c,c,c);
    printf("   %c   |/    |    \\|                            %c\n",176,176);
    printf("     %c     %c    %c%c%c    %c     %c",c,c,c,c,c,c,c);
    printf("   %c  [7]---[8]---[9]                           %c\n",176,176);
    printf("     %c    %c     %c%c%c     %c    %c",c,c,c,c,c,c,c);
    printf("   %c                                            %c\n",176,176);
    printf("     %c   %c      %c%c%c      %c   %c",c,c,c,c,c,c,c);
    printf("   %c     i m a g e                              %c\n",176,176);
    printf("     %c  %c       %c%c%c       %c  %c",c,c,c,c,c,c,c);
    printf("   %c                                            %c\n",176,176);
    printf("     %c %c        %c%c%c        %c %c",c,c,c,c,c,c,c);
    printf("   %c                                            %c\n",176,176);
    printf("     %c%c         %c%c%c         %c%c",c,c,c,c,c,c,c);
    printf("   %c                                            %c\n",176,176);
    if(position[2][0]==1)
    {
        color=p1_color;
    }
    else if(position[2][0]==2)
    {
        color=p2_color;
    }
    else
    {
        color=blank_color;
    }

    SetColor(color);
    printf("     [%d]",  position[2][0]);
    SetColor(15);
    printf("%c%c%c%c%c%c%c%c",c,c,c,c,c,c,c,c);
    if(position[2][1]==1)
    {
        color=p1_color;
    }
    else if(position[2][1]==2)
    {
        color=p2_color;
    }
    else
    {
        color=blank_color;
    }
    SetColor(color);
    printf("[%d]",  position[2][1]);
    SetColor(15);
    printf("%c%c%c%c%c%c%c%c",c,c,c,c,c,c,c,c);
    if(position[2][2]==1)
    {
        color=p1_color;
    }
    else if(position[2][2]==2)
    {
        color=p2_color;
    }
    else
    {
        color=blank_color;
    }
    SetColor(color);
    printf("[%d]",  position[2][2]);
    SetColor(15);
    printf("   O********************************************O\n");

}

int shortcut2(int a,int *arr[3][3])
{
    if(a==1)
    {
        return arr[0][0];
    }
    else if(a==2)
    {
        return arr[0][1];

    }
    else if(a==3)
    {
        return  arr[0][2];
    }
    else if(a==4)
    {
        return  arr[1][0];

    }
    else if(a==5)
    {
        return arr[1][1];
    }
    else if(a==6)
    {
        return arr[1][2];
    }
    else if(a==7)
    {
        arr[2][0];
        return arr[2][0];
    }
    else if(a==8)
    {
        return  arr[2][1];
    }
    else if(a==9)
    {
        return arr[2][2];
    }
}

void shortcut(int a,int *arr[3][3],int player)
{
    if(a==1)
    {
        arr[0][0]=player;
    }
    else if(a==2)
    {
        arr[0][1]=player;
    }
    else if(a==3)
    {
        arr[0][2]=player;
    }
    else if(a==4)
    {
        arr[1][0]=player;
    }
    else if(a==5)
    {
        arr[1][1]=player;
    }
    else if(a==6)
    {
        arr[1][2]=player;
    }
    else if(a==7)
    {
        arr[2][0]=player;
    }
    else if(a==8)
    {
        arr[2][1]=player;
    }
    else if(a==9)
    {
        arr[2][2]=player;
    }
}


void move(int *arr[3][3],int z1,int p1,int player)
{
    shortcut(z1,arr,0);
    shortcut(p1,arr,player);
}


void checklala(int i,int j,int *arr[3][3],int player,int *arr2[9][8],int *a)
{
    if(player==shortcut2(i,arr))// player 2 1 a zete parbena & player 1 2 te zete parbena.
    {
        i=i-1;
        if(i>8||i<0)
        {
            printf("Error..! You have range between 1 to 9\n");
            Beep(250,250);
        }
        else if(i==4)
        {
            if(j==arr2[i][0]||j==arr2[i][1]||j==arr2[i][2]||j==arr2[i][3]||j==arr2[i][4]||j==arr2[i][5]||j==arr2[i][6]||j==arr2[i][7])
            {
                if(shortcut2(j,arr)==0)
                {
                    move(arr,i+1,j,player);
                    printf("A=%d\n",++*a);
                }
                else
                {
                    printf("Error\n");
                    Beep(250,250);
                }
            }
            else
            {
                printf("Error\n");
                Beep(250,250);
            }
        }
        else
        {
            if(j==arr2[i][0]||j==arr2[i][1]||j==arr2[i][2])
            {
                if(shortcut2(j,arr)==0)
                {
                    move(arr,i+1,j,player);
                    printf("A=%d\n",++*a);
                }
                else
                {
                    printf("Error\n");
                    Beep(250,250);
                }
            }
            else
            {
                printf("Error\n");
                Beep(250,250);
            }
        }
    }
    system("cls");
}


void loading()
{
    int p,q;
    printf("\n\n\n\n\n\n\n\n\n\n\t\tLoading....\n");
    printf("\t\t");
    for(p=0;p<=42;p++)
    {
        for(q=0;q<=20000000;q++)
        {
        }
    printf("%c",199);
    }
}


void logo()
{
    *chr="COLOR 1A";
    system(*chr);
    printf("\n\n\n\n\n\n");
    printf("\t        _____           _     _     ____              _\n");
    Sleep(400);
    printf("\t       / ____|         | |   (_)   |  _ \\            (_)\n");
    Sleep(400);
    printf("\t      | |  __   _   _  | |_   _    | |_) |   __ _     _\n");
    Sleep(400);
    printf("\t      | | |_ | | | | | | __| | |   |  _ <   / _` |   | |\n");
    Sleep(400);
    printf("\t      | |__| | | |_| | | |_  | |   | |_) | | (_| |   | |\n");
    Sleep(400);
    printf("\t       \\_____|  \\__,_|  \\__| |_|   |____/   \\__,_|   | |\n");
    Sleep(400);
    printf("\t                                                    _/ |\n");
    Sleep(400);
    printf("\t                                                   |__/ \n\n\n\n");
    Sleep(2500);
    system("cls");
}
//....This function is for using set color from windows header file..........
void SetColor(int ForgC)
{
     WORD wColor;
                          //We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

                           //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                     //Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}


void highsc()
{
    char nplname[20],cha,c;
    int i,j,px;
    FILE *info;
    system("cls");
    info=fopen("record.txt","r");
    do
    {
        putchar(c=getc(info));
    }
    while(c!=EOF);
    fclose(info);
}


void record(char player1[20],char player2[20])
{
    char cha,c;
    int i,j,px;
    FILE *info;
    info=fopen("record.txt","a+");
    system("cls");
    fprintf(info,"Winer was  : %s\n\n",player1);
    fprintf(info,"Looser was : %s\n\n",player2);
    //for date and time
    time_t mytime;
    mytime = time(NULL);
    fprintf(info,"Played Date: %s",ctime(&mytime));
    fprintf(info,"______________________________________\n\n");
    fclose(info);
}

void ret_menu()
{
    printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\t\t\t   %c                      %c\n",c,c);
    printf("\t\t\t   %c  1. Return Main Menu %c\n",c,c);
    printf("\t\t\t   %c                      %c\n",c,c);
    printf("\t\t\t   %c  2. Exit             %c\n",c,c);
    printf("\t\t\t   %c                      %c\n",c,c);
    printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\n");
    printf("\t\t\t    Choose your Options :");
}


void do_you_save()
{
    printf("\n\n\n\n\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\t\t\t   %c                                %c\n",c,c);
    printf("\t\t\t   %c Do you want to save your data? %c\n",c,c);
    printf("\t\t\t   %c                                %c\n",c,c);
    printf("\t\t\t   %c       1. Yes       2.No        %c\n",c,c);
    printf("\t\t\t   %c                                %c\n",c,c);
    printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\t\t\t         Choose your option: ");
}

void error()
{
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t    error !\n\n\n\n\n\n\n");
    Sleep(700);
}
void setting()
{

}
