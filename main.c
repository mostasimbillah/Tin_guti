#include<stdio.h>
int shortcut2(int a,int (*arr)[3])
{
    if(a==1)
    {

    return (int)arr[0][0];
    }else if(a==2)
    {
        return (int)arr[0][1];

    }else if(a==3)
    {
       return  (int)arr[0][2];

    }else if(a==4)
    {
        return  (int)arr[1][0];

    }else if(a==5)
    {

         return (int)arr[1][1];
    }else if(a==6)
    {

         return (int)arr[1][2];
    }else if(a==7)
    {
        arr[2][0];
         return (int)arr[2][0];
    }else if(a==8)
    {

         return  (int)arr[2][1];
    }else if(a==9)
    {

         return (int)arr[2][2];
    }

}
void shortcut(int a,int (*arr)[3],int player)
{
    if(a==1)
    {
        arr[0][0]=(int *)player;
    }else if(a==2)
    {
        arr[0][1]=(int *)player;
    }else if(a==3)
    {
        arr[0][2]=(int *)player;
    }else if(a==4)
    {
        arr[1][0]=(int *)player;
    }else if(a==5)
    {
        arr[1][1]=(int *)player;
    }else if(a==6)
    {
        arr[1][2]=(int *)player;
    }else if(a==7)
    {
        arr[2][0]=(int *)player;
    }else if(a==8)
    {
        arr[2][1]=(int *)player;
    }else if(a==9)
    {
        arr[2][2]=(int *)player;
    }
}
void move(int *arr[3][3],int z1,int p1,int player)
{

    shortcut(z1,arr,0);

    shortcut(p1,arr,player);


}

void checklala(int i,int j,int *arr[3],int player,int *arr2[9][8],int *a)
{
    if(player==shortcut2(i,arr))// player 2 1 a zete parbena & player 1 2 te zete parbena.
    {



    i=i-1;

    if(i>8||i<0)
    {
        printf("Error..! You have range between 1 to 9\n");

    }
    else if(i==4)
    {
        if(j==(int)arr2[i][0]||j==(int)arr2[i][1]||j==(int)arr2[i][2]||j==(int)arr2[i][3]||j==(int)arr2[i][4]||j==(int)arr2[i][5]||j==(int)arr2[i][6]||j==(int)arr2[i][7])
        {
            if(shortcut2(j,arr)==0)
            {
                 move(arr,i+1,j,player);
                printf("A=%d\n",++*a);
            }
            else
            {
                printf("Error\n");
            }
        }
    else
    {
            printf("Error\n");
    }
    }else{

        if(j==(int)arr2[i][0]||j==(int)arr2[i][1]||j==(int)arr2[i][2]){


             if(shortcut2(j,arr)==0)
            {
                 move(arr,i+1,j,player);
                 printf("A=%d\n",++*a);


            }
            else
            {
                printf("Error\n");
            }

        }   else
    {
            printf("Error\n");

    }
    }

    }
    //system("cls");
}
int main()
{
    int position[3][3],player=0,k,l;
    int i,j,a=0;
    char name1[30];
    char name2[30];
    printf("Enter 1st player name: ");
    scanf("%s",&name1);
    printf("Enter 2ns player name: ");
    scanf("%s",&name2);

    position[0][0]=1;
    position[0][1]=1;
    position[0][2]=1;
    position[1][0]=0;
    position[1][1]=0;
    position[1][2]=0;
    position[2][0]=2;
    position[2][1]=2;
    position[2][2]=2;



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
printf("%d........................%d........................%d\n..                       .                       ..\n. .                      .                      . .\n.  .                     .                     .  .\n.   .                    .                    .   .\n.    .                   .                   .    .\n.     .                  .                  .     .\n.      .                 .                 .      .\n.       .                .                .       .\n.        .               .               .        .\n.         .              .              .         .\n.          .             .             .          .\n.           .            .            .           .\n.            .           .           .            .\n.             .          .          .             .\n.              .         .         .              .\n.               .        .        .               .\n.                .       .       .                .\n.                 .      .      .                 .\n.                  .     .     .                  .\n.                   .    .    .                   .\n.                    .   .   .                    .\n.                     .  .  .                     .\n.                      . . .                      .\n.                       ...                       .\n%d........................%d........................%d\n.                       ...                       .\n.                      . . .                      .\n.                     .  .  .                     .\n.                    .   .   .                    .\n.                   .    .    .                   .\n.                  .     .     .                  .\n.                 .      .      .                 .\n.                .       .       .                .\n.               .        .        .               .\n.              .         .         .              .\n.             .          .          .             .\n.            .           .           .            .\n.           .            .            .           .\n.          .             .             .          .\n.         .              .              .         .\n.        .               .               .        .\n.       .                .                .       .\n.      .                 .                 .      .\n.     .                  .                  .     .\n.    .                   .                   .    .\n.   .                    .                    .   .\n.  .                     .                     .  .\n. .                      .                      . .\n..                       .                       ..\n%d........................%d........................%d",position[0][0],position[0][1],position[0][2],position[1][0],position[1][1],position[1][2],position[2][0],position[2][1],position[2][2]);
    printf("\n\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",position[i][j]);
        }
        printf("\n\n");
    }
    for(;;)
    {
        if(a%2==0)
        {
            player=1;
            printf("%s's turn: \n",name1);
            printf("Move point: ");
            scanf("%d",&i);
            //shortcut(i,position);


            printf("Where to move: ");
            scanf("%d",&k);
            //shortcut(k,position);
            checklala(i,k,position,player,A,&a);





        }
        else
        {
            player=2;
            printf("%s's turn: \n",name2);
            printf("Which point you want to move: ");
            scanf("%d",&i);


            printf("Which point you want to shift that: ");
            scanf("%d",&k);
            checklala(i,k,position,player,A,&a);





        }


   // system("cls");
    printf("%d........................%d........................%d\n..                       .                       ..\n. .                      .                      . .\n.  .                     .                     .  .\n.   .                    .                    .   .\n.    .                   .                   .    .\n.     .                  .                  .     .\n.      .                 .                 .      .\n.       .                .                .       .\n.        .               .               .        .\n.         .              .              .         .\n.          .             .             .          .\n.           .            .            .           .\n.            .           .           .            .\n.             .          .          .             .\n.              .         .         .              .\n.               .        .        .               .\n.                .       .       .                .\n.                 .      .      .                 .\n.                  .     .     .                  .\n.                   .    .    .                   .\n.                    .   .   .                    .\n.                     .  .  .                     .\n.                      . . .                      .\n.                       ...                       .\n%d........................%d........................%d\n.                       ...                       .\n.                      . . .                      .\n.                     .  .  .                     .\n.                    .   .   .                    .\n.                   .    .    .                   .\n.                  .     .     .                  .\n.                 .      .      .                 .\n.                .       .       .                .\n.               .        .        .               .\n.              .         .         .              .\n.             .          .          .             .\n.            .           .           .            .\n.           .            .            .           .\n.          .             .             .          .\n.         .              .              .         .\n.        .               .               .        .\n.       .                .                .       .\n.      .                 .                 .      .\n.     .                  .                  .     .\n.    .                   .                   .    .\n.   .                    .                    .   .\n.  .                     .                     .  .\n. .                      .                      . .\n..                       .                       ..\n%d........................%d........................%d",position[0][0],position[0][1],position[0][2],position[1][0],position[1][1],position[1][2],position[2][0],position[2][1],position[2][2]);
    printf("\n\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",position[i][j]);
        }
        printf("\n\n");
    }
    if((position[0][0]==1&&position[1][0]==1&&position[2][0]==1)||
       (position[0][1]==1&&position[1][1]==1&&position[2][1]==1)||
       (position[0][2]==1&&position[1][2]==1&&position[2][2]==1)||
       (position[0][0]==1&&position[1][1]==1&&position[2][2]==1)||
       (position[0][2]==1&&position[1][1]==1&&position[2][0]==1)||
       (position[2][0]==1&&position[2][1]==1&&position[2][2]==1)||//player one 1st position skip
       (position[1][0]==1&&position[1][1]==1&&position[1][2]==1))
       {
           system("cls");
           printf("\nHey %s,you are win...!! \n",name1);
           printf("Congrats..\n\n");
           printf("\n %s, you the looser.. Better luck next time..!! ",name2);
         // system("D:\\hello.mp3");
           break;

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
           printf("\nHey %s,you are win...!! \n ",name2);
           printf("Congrats..\n\n");
           printf("\n %s, you the looser.. Better luck next time..!! ",name1);
          // system("D:\\hello.mp3");
           break;
       }
    }

}


