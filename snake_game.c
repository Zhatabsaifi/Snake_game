#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
char name[20];
int foodx,foody,x=5,y=5,gameover=0,score=0,flag,choice,level,i,j,tailx[100]={0},taily[100]={0};
void start()
{
    char a;
    printf("\t\tSnake Game :\n");
    printf("enter the name of user = ");            /*username*/
    gets(name);
    printf("\nInstruction :\n-> w is use for move upword direction\n-> s is use of move downword direction\n-> a is use of move left direction\n-> d is use of move right direction\n");
    printf("->@ denote the food\n->O is a Snake \n");
    printf("press any key for start the game ");
    scanf("%c",&a);
    system("cls");          /*clear screen*/
}
void score_check()
{
    printf("\t\tSnake Game\n");
    printf("Score : %d\n\n",score);
}
void food()
{
    do{
        foodx = rand()%30;          /*x coordinate of food*/
    }while(foodx == 0);
    do{
        foody = rand()%50;         /*y coordinate of food*/
    }while(foody==0);
}
void print()
{
    int k;
    for(i=0;i<31;i++){
        for(j=0;j<51;j++)
        {
            if(i==0||i==30||j==0||j==50)
                printf("#");                /*print boundary of game*/
            else
            {
                if(i==foodx && j==foody)
                    printf("@");            /*print food*/
                else if(i==x && j==y)
                    printf("O");            /*print snake head*/
                else
                {
                      int co=0;
                      for(k=0;k<score;k++)
                      {
                          if(i == tailx[k] && j==taily[k]){
                                printf("o");
                                co =1;
                          }
                      }
                      if(co == 0)
                        printf(" ");
                }
            }
        }
        printf("\n");
    }
}
void check()
{
    if(x==foodx && y==foody)
    {
        score++;
        food();
    }
    if(x==0||x==30||y==0||y==50)
        gameover =1;
    for(i=0;i<score;i++)
    {
        if(x == tailx[i] && y == taily[i])
            gameover =1;
    }
}
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'a':           /*for left move*/
                flag=1;
                break;
            case 'd':           /*for right move*/
                flag=2;
                break;
            case 's':           /*for down move*/
                flag=3;
                break;
            case 'w':           /*for upword move*/
                flag=4;
                break;
        }
    }
    movement();
}
void movement()
{
    int prev2x,prev2y,prevx,prevy;
    prevx = tailx[0];   prevy = taily[0];
    tailx[0] = x;  taily[0] = y;
    for(i=1;i<score;i++)
    {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    switch(flag)
    {
        case 1:
            y--;
            break;
        case 2:
            y++;
            break;
        case 3:
            x++;
            break;
        case 4:
            x--;
            break;
    }
    check();
    system("cls");
}
int main()
{
    system("cls");
    start();
    food();
    while(!gameover)
    {
        score_check();
        print();
        input();
    }
    system("cls");
    printf("\t\tSnake Game :\n\n");
    printf("\tScore : %d\n",score);
    printf("\tNice play %s\n\tI hope you will make better score for next time\n\tThank you for playing",name);
    return 0;
}
