#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>
void Exit();
int menu();
void display(int (*position)[3],int name1,int name2,int player1_count,int player2_count);
int shortcut2(int a,int *arr[3][3]);
void shortcut(int a,int *arr[3][3],int player);
void move(int *arr[3][3],int z1,int p1,int player);
void checklala(int i,int j,int *arr[3][3],int player,int *arr2[9][8],int *a);
void loading();
void record();
void logo();


int main()
{
    int position[3][3],player=0,k,l;
    int i,j,mod=0;
    int a;
    char name1[30];
    char name2[30];
    char name3[30];
    char name4[30];
    int player1_count=0,player2_count=0;
    system("COLOR 1A");
    logo();

    //printf("\t\t\t..WELCOME TO GUTI-BAJ..\n\n");

    //loading();
    system("cls");
    int menu_item=menu();



X :
    system("cls");
    getchar();
    switch(menu_item)
    {
    case 1:
        loading();
        system("cls");
        printf("\t\t\t..GUTI-BAJ..\n\n\n");
        printf("Enter 1st player name: ");
        gets(name1);
        strcpy(name3,name1);
        printf("Enter 2nd player name: ");
        gets(name2);
        strcpy(name4,name2);
        int length1;
        length1=strlen(name1);
        char str1[30];
        int fuc;
        for(fuc=0;fuc<13-length1;fuc++)
        {
            str1[fuc]=' ';

        }
        str1[13-length1]='\0';
        strcat(name1,str1);
        int length2;
        length2=strlen(name2);
        char str2[30];
        for(fuc=0;fuc<13-length2;fuc++)
        {
            str2[fuc]=' ';
        }
        str2[13-length2]='\0';
        strcat(name2,str2);

        for(;;)
        {
            system("cls");
            position[0][0]=1;
            position[0][1]=1;
            position[0][2]=1;
            position[1][0]=0;
            position[1][1]=0;
            position[1][2]=0;
            position[2][0]=2;
            position[2][1]=2;
            position[2][2]=2;



            int A[9][8] = { { 2,4,5,0,0, 0, 0, 0 },
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



           /* printf("\n\n");
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    printf("%d ",position[i][j]);
                }
                printf("\n\n");
            }
            */
            for(;;)
            {


                if(a%2==0)
                {
                    player=1;
                    printf("%s's turn: \n",name3);
                    printf("Move point: ");
                    scanf("%d",&i);
                    system("cls");
                    //shortcut(i,position);
                    display(position,name1,name2,player1_count,player2_count);
                    printf("%s's turn: \n",name3);
                    printf("Where to move: ");
                    scanf("%d",&k);
                    //shortcut(k,position);
                    checklala(i,k,position,player,A,&a);

                }
                else
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


                // system("cls");

                display(position,name1,name2,player1_count,player2_count);
          /*   for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    printf("%d ",position[i][j]);
                }
                printf("\n\n");
            }
            */

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
               printf("\n\n\n\n\n\t\t\t%s you gain %d point\n",name3,player1_count);
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
               if(player1_count>=0)
                {
                   a=0;
                   mod=0;
                   player1_count=0;
                   int win1;
                   system("cls");
                   printf("\n\n\n\n\n\t\t\t%s you are win !!!!!!!\n",name3);
                   printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
                  printf("\t\t\t   %c                                %c\n",177,177);
                  printf("\t\t\t   %c Do you want to save your data? %c\n",177,177);
                  printf("\t\t\t   %c                                %c\n",177,177);
                  printf("\t\t\t   %c       1. Yes       2.No        %c\n",177,177);
                  printf("\t\t\t   %c                                %c\n",177,177);
                  printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
                 int yesno1;
                 scanf("%d",&yesno1);
                if(yesno1==1)
                {
                    record();
                }

                printf("\n\n\n\n\n\t\t\t%s you are win !!!!!!!\n",name3);
                printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
                printf("\t\t\t   %c                      %c\n",177,177);
                printf("\t\t\t   %c  1. Return Main Menu %c\n",177,177);
                printf("\t\t\t   %c                      %c\n",177,177);
                printf("\t\t\t   %c  2. Exit             %c\n",177,177);
                printf("\t\t\t   %c                      %c\n",177,177);
                printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
                printf("\n");
                printf("\t\t\t    Choose your Options :");
                scanf("%d",&win1);
                system("cls");
             if(win1==1)
             {
                menu_item=menu();
                goto X;
             }
             else if(win1==2)
             Exit();
           }

       }
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
           printf("\n\n\n\n\n\n\t\t\t  %s you gain %d point\n",name4,player2_count);
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
           printf("\n\n\n\n\n\t\t\t%s you are win !!!!!!!\n",name4);
           printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
             printf("\t\t\t   %c                      %c\n",177,177);
             printf("\t\t\t   %c  1. Return Main Menu %c\n",177,177);
             printf("\t\t\t   %c                      %c\n",177,177);
             printf("\t\t\t   %c  2. Exit             %c\n",177,177);
             printf("\t\t\t   %c                      %c\n",177,177);
             printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
             printf("\n");
             printf("\t\t\t    Choose your Options :");
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

          }
       }
    }




}

break;
    case 2:
             loading();
             system("cls");
             int x1;
             printf("\n\n\t\t\t\t  1.BILLAH\n\t\t\t\t  2.Joy\n\t\t\t\t  3.Rajib\n");
             printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
             printf("\t\t\t   %c                      %c\n",177,177);
             printf("\t\t\t   %c  1. Return Main Menu %c\n",177,177);
             printf("\t\t\t   %c                      %c\n",177,177);
             printf("\t\t\t   %c  2. Exit             %c\n",177,177);
             printf("\t\t\t   %c                      %c\n",177,177);
             printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
             printf("\n");
             printf("\t\t\t    Choose your Options :");
             scanf("%d",&x1);
             system("cls");
             if(x1==1)
             {
                menu_item=menu();
                goto X;
             }
             else if(x1==2)
             Exit();
             break;
    case 3:
            loading();
            system("cls");
             int x2;
             printf("\n\n\n\n\n\t\t\t   ************************\n");
             printf("\t\t\t   ************************\n");
             printf("\t\t\t   *                      *\n");
             printf("\t\t\t   *  1. Return Main Menu *\n");
             printf("\t\t\t   *  2. Exit             *\n");
             printf("\t\t\t   *                      *\n");
             printf("\t\t\t   ************************\n");
             printf("\t\t\t   ************************\n");
             printf("\t\t\t    Choose your Options :");
             scanf("%d",&x2);
             system("cls");
             if(x2==1)
             {
                menu_item=menu();
                goto X;
             }
             else if(x2==2)
             Exit();
             break;
    case 4:
            loading();
            system("cls");
             int x3;
             printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
             printf("\t\t\t   %c                      %c\n",177,177);
             printf("\t\t\t   %c  1. Return Main Menu %c\n",177,177);
             printf("\t\t\t   %c                      %c\n",177,177);
             printf("\t\t\t   %c  2. Exit             %c\n",177,177);
             printf("\t\t\t   %c                      %c\n",177,177);
             printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
             printf("\n");
             printf("\t\t\t    Choose your Options :");
             scanf("%d",&x3);
             system("cls");
             if(x3==1)
             {
                menu_item=menu();
                goto X;
             }
             else if(x3==2)
             Exit();
             break;
    case 5:
            loading();
            system("cls");
             int x4;
             printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
             printf("\t\t\t   %c                      %c\n",177,177);
             printf("\t\t\t   %c  1. Return Main Menu %c\n",177,177);
             printf("\t\t\t   %c                      %c\n",177,177);
             printf("\t\t\t   %c  2. Exit             %c\n",177,177);
             printf("\t\t\t   %c                      %c\n",177,177);
             printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
             printf("\n");
             printf("\t\t\t    Choose your Options :");
             scanf("%d",&x4);
             system("cls");
             if(x4==1)
             {
                menu_item=menu();
                goto X;
             }
             else if(x4==2)
             Exit();
             break;
    case 6:
            loading();
            system("cls");
             int x5;
            printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
             printf("\t\t\t   %c                      %c\n",177,177);
             printf("\t\t\t   %c  1. Return Main Menu %c\n",177,177);
             printf("\t\t\t   %c                      %c\n",177,177);
             printf("\t\t\t   %c  2. Exit             %c\n",177,177);
             printf("\t\t\t   %c                      %c\n",177,177);
             printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
             printf("\n");
             printf("\t\t\t    Choose your Options :");
             scanf("%d",&x5);
             system("cls");
             if(x5==1)
             {
                menu_item=menu();
                goto X;
             }
             else if(x5==2)
             Exit();
             break;
    case 7:
             system("cls");
             Exit();
             break;


}

return 0;
}

void record(){
   char plname[20],nplname[20],cha,c;
   int i,j,px;
   FILE *info;
   info=fopen("record.txt","a+");
   getch();
   system("cls");
   printf("Enter your name\n");
   scanf("%[^\n]",plname);
   //************************
   for(j=0;plname[j]!='\0';j++){ //to convert the first letter after space to capital
   nplname[0]=toupper(plname[0]);
   if(plname[j-1]==' '){
   nplname[j]=toupper(plname[j]);
   nplname[j-1]=plname[j-1];}
   else nplname[j]=plname[j];
   }
   nplname[j]='\0';
   //*****************************
   //sdfprintf(info,"\t\t\tPlayers List\n");
   fprintf(info,"Player Name :%s\n",nplname);
    //for date and time

   time_t mytime;
  mytime = time(NULL);
  fprintf(info,"Played Date:%s",ctime(&mytime));
     //**************************
    fprintf(info,"Score:%d\n",px=hi());//call score to display score
     //fprintf(info,"\nLevel:%d\n",10);//call level to display level
   for(i=0;i<=50;i++)
   fprintf(info,"%c",'_');
   fprintf(info,"\n");
   fclose(info);
   printf("wanna see past records press 'y'\n");
   cha=getch();
   system("cls");
   if(cha=='y'){
   info=fopen("record.txt","r");
   do{
       putchar(c=getc(info));
       }while(c!=EOF);}
     fclose(info);
}

void hi()
{
    printf("Hey guys ");
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
printf("\t\t\t  %c                     %c\n",177,177);
printf("\t\t\t  %c   1. New Game       %c\n",177,177);
printf("\t\t\t  %c   2. High Score     %c\n",177,177);
printf("\t\t\t  %c   3. Settings       %c\n",177,177);
printf("\t\t\t  %c   4. Account        %c\n",177,177);
printf("\t\t\t  %c   5. Instructions   %c\n",177,177);
printf("\t\t\t  %c   6. About          %c\n",177,177);
printf("\t\t\t  %c   7. Exit           %c\n",177,177);
printf("\t\t\t  %c                     %c\n",177,177);
printf("\t\t\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
printf("\t\t\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
printf("\t\t\t  Choose your option : ");
scanf("%d",&menu);

return menu;
}

void display(int (*position)[3],int name1,int name2,int player1_count,int player2_count)
{

      printf("\n");
printf("          [%d]%c%c%c%c%c%c%c%c[%d]%c%c%c%c%c%c%c%c[%d]",position[0][0],177,177,177,177,177,177,177,177,position[0][1],177,177,177,177,177,177,177,177,position[0][2]);
printf("                         -----------------\n");
printf("          %c%c         %c%c%c         %c%c",177,177,177,177,177,177,177);
printf("                        |%s| %d |\n",name1,player1_count);
printf("          %c %c        %c%c%c        %c %c",177,177,177,177,177,177,177);
printf("                        |-----------------|\n");

printf("          %c  %c       %c%c%c       %c  %c",177,177,177,177,177,177,177);
printf("                        |%s| %d |\n",name2,player2_count);
printf("          %c   %c      %c%c%c      %c   %c",177,177,177,177,177,177,177);
printf("                         -----------------\n");

printf("          %c    %c     %c%c%c     %c    %c\n",177,177,177,177,177,177,177);

printf("          %c     %c    %c%c%c    %c     %c\n",177,177,177,177,177,177,177);
printf("          %c      %c   %c%c%c   %c      %c\n",177,177,177,177,177,177,177);
printf("          %c       %c  %c%c%c  %c       %c\n",177,177,177,177,177,177,177);
printf("          %c        %c %c%c%c %c        %c\n",177,177,177,177,177,177,177);
printf("          %c         %c%c%c%c%c         %c\n",177,177,177,177,177,177,177);
printf("          [%d]%c%c%c%c%c%c%c%c[%d]%c%c%c%c%c%c%c%c[%d]\n",position[1][0],177,177,177,177,177,177,177,177,position[1][1],177,177,177,177,177,177,177,177,position[1][2]);
printf("          %c         %c%c%c%c%c         %c\n",177,177,177,177,177,177,177);
printf("          %c        %c %c%c%c %c        %c\n",177,177,177,177,177,177,177);
printf("          %c       %c  %c%c%c  %c       %c\n",177,177,177,177,177,177,177);
printf("          %c      %c   %c%c%c   %c      %c\n",177,177,177,177,177,177,177);
printf("          %c     %c    %c%c%c    %c     %c\n",177,177,177,177,177,177,177);
printf("          %c    %c     %c%c%c     %c    %c\n",177,177,177,177,177,177,177);
printf("          %c   %c      %c%c%c      %c   %c\n",177,177,177,177,177,177,177);
printf("          %c  %c       %c%c%c       %c  %c\n",177,177,177,177,177,177,177);
printf("          %c %c        %c%c%c        %c %c\n",177,177,177,177,177,177,177);
printf("          %c%c         %c%c%c         %c%c\n",177,177,177,177,177,177,177);
printf("          [%d]%c%c%c%c%c%c%c%c[%d]%c%c%c%c%c%c%c%c[%d]\n",position[2][0],177,177,177,177,177,177,177,177,position[2][1],177,177,177,177,177,177,177,177,position[2][2]);
}
int shortcut2(int a,int *arr[3][3])
{
    if(a==1)
    {
        return arr[0][0];
    }else if(a==2)
    {
        return arr[0][1];

    }else if(a==3)
    {
       return  arr[0][2];

    }else if(a==4)
    {
        return  arr[1][0];

    }else if(a==5)
    {

         return arr[1][1];
    }else if(a==6)
    {

         return arr[1][2];
    }else if(a==7)
    {
        arr[2][0];
         return arr[2][0];
    }else if(a==8)
    {

         return  arr[2][1];
    }else if(a==9)
    {

         return arr[2][2];
    }

}
void shortcut(int a,int *arr[3][3],int player)
{
    if(a==1)
    {
        arr[0][0]=player;
    }else if(a==2)
    {
        arr[0][1]=player;
    }else if(a==3)
    {
        arr[0][2]=player;
    }else if(a==4)
    {
        arr[1][0]=player;
    }else if(a==5)
    {
        arr[1][1]=player;
    }else if(a==6)
    {
        arr[1][2]=player;
    }else if(a==7)
    {
        arr[2][0]=player;
    }else if(a==8)
    {
        arr[2][1]=player;
    }else if(a==9)
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
    }else{

        if(j==arr2[i][0]||j==arr2[i][1]||j==arr2[i][2]){


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

        }   else
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
   for(q=0;q<=20000000;q++){


}

printf("%c",199);
}
}
void logo()
{
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
}
