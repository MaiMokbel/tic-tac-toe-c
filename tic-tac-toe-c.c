#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
         //colores 
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define WHITE   "\033[37m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int body(char B[3][3])
{
 for(int i=0;i<3;i++)
 {
  for(int j=0;j<3;j++)
  {
    printf(BLUE"| %c |"RESET,B[i][j]);
  }
  printf(BLUE"\n________________\n"RESET);
 }
}
char player (char B[3][3] , char p)
{
    int count =0;
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
        if(B[i][j]!=' ')     //checking for empty places
        {
          count++;
        }
        if(count == 9)
        {
          return 1;
        }
      }
    }    
  int r,c ;
  printf(GREEN"please enter where do you want to play (> "RESET);
  printf(GREEN"\nrow & colume"RESET);
scanf("%d%d",&r,&c);
while(B[r][c]!=' ')
{
printf(RED"you can't play here try again :)"RESET);
scanf("%d%d",&r,&c);
}
for(int i=0; i<3 ;i++)
{
  for(int j=0;j<3;j++)
  {
    if(r==i && c==j)
    {
      B[i][j]=p;
    }
  }
}
}

char player2 (char B[3][3] , char p)
{
    int count =0;
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
        if(B[i][j]!=' ')     //checking for empty places
        {
          count++;
        }
        if(count == 9)
        {
          return 1;
        }
      }
    }    
  int r,c ;
  printf(GREEN"please enter where do you want to play (> "RESET);
  printf(GREEN"\nrow & colume"RESET);
scanf("%d%d",&r,&c);
while(B[r][c]!=' ')
{
printf(RED"you can't play here try again :)"RESET);
scanf("%d%d",&r,&c);
}
for(int i=0; i<3 ;i++)
{
  for(int j=0;j<3;j++)
  {
    if(r==i && c==j)
    {
      B[i][j]=p;
    }
  }
}
}

int compE(char B[3][3],char p)
{
srand(time(0));

int rc,cc ;
do
{
rc =rand()%3;
cc =rand()%3;
int count=0;
    for(int i=0 ;i<3;i++)
     {
       for(int j=0;j<3;j++)
       {
        if(B[i][j]=='x' || B[i][j]=='o')
        {
          count++;
        }
       }
     }
     if(count==9) //cheking empty places
     {
      printf(RED"\n no places are empty to play \n"RESET);
      return 1;
     }
}while(B[rc][cc]!=' '); //checking that the random num are not in rebeat
for(int i=0;i<3;i++)    //   comp move
{
  for(int j=0;j<3;j++)
  {
    if(rc==i && cc==j)
    {
      B[i][j]=p;
    }
  }
}
}

int compNI (char B[3][3], char k , int flag[28])
{

int count=0;
    for(int i=0 ;i<3;i++)
     {
       for(int j=0;j<3;j++)
       {
        if(B[i][j]=='x' || B[i][j]=='o')
        {
          count++;
        }
       }
     }
     if(count==9) //cheking empty places
     {
      printf(RED"\n no places are empty to play \n"RESET);
      return 1;
     }
 if(B[1][1]==' ')
    {
      B[1][1]=k;
     return 1;
    }
else if(B[0][0]==B[2][0] && flag[1]==1 && B[1][0]==' ')//[1][0]c1
    {
      B[1][0]=k;
      flag[1]+=1;
      return 1;
    }
else if(B[0][0]==B[1][0] && flag[2]==2 && B[2][0]==' ')//[2][0]c1
    {
      B[2][0]=k;
      flag[2]+=1;
      return 1;
    }
else if(B[1][0]==B[2][0] && flag[3]==3 && B[0][0]==' ')//[0][0]c1
    {
      B[0][0]=k;
      flag[3]+=1;
      return 1;
    }
else if(B[0][1]==B[2][1] && flag[4]==4 && B[1][1]==' ')//[1][1]c2
    {
      B[1][1]=k;
      flag[4]+=1;
      return 1;
    }
else if(B[0][1]==B[1][1] && flag[5]==5 && B[2][1]==' ')//[2][1]c2
    {
      B[2][1]=k;
      flag[5]+=1;
      return 1;
    }
else if(B[1][1]==B[2][1] && flag[6]==6 && B[0][1]==' ')//[0][1]c2
    {
      B[0][1]=k;
      flag[6]+=1;
      return 1;
    }
else if(B[0][2]==B[2][2] && flag[7]==7 && B[1][2]==' ')//[1][2]c3
    {
      B[1][2]=k;
      flag[7]+=1;
      return 1;
    }
else if(B[0][2]==B[1][2] && flag[8]==8 && B[2][2]==' ')//[2][2]c3
    {
      B[2][2]=k;
      flag[8]+=1;
      return 1;
    }
else if(B[1][2]==B[2][2] && flag[9]==9 && B[0][2]==' ')//[0][2]c3
    {
      B[0][2]=k;
      flag[9]+=1;
      return 1;
    }
else if(B[0][0]==B[0][1] && flag[10]==10 && B[0][2]==' ')//[0][2]r1
    {
      B[0][2]=k;
      flag[10]+=1;
      return 1;
    }
else if(B[0][0]==B[0][2] && flag[11]==11 && B[0][1]==' ')//[0][1]r1
    {
      B[0][1]=k;
      flag[11]+=1;
      return 1;
    }
else if(B[0][1]==B[0][2] && flag[12]==12 && B[0][0]==' ')//[0][0]r1
    {
      B[0][0]=k;
      flag[12]+=1;
      return 1;
    }
else if(B[1][0]==B[1][1] && flag[13]==13 && B[1][2]==' ')//[1][2]r2
    {
      B[1][2]=k;
      flag[13]+=1;
      return 1;
    }
else if(B[1][0]==B[1][2] && flag[14]==14 && B[1][1]==' ')//[1][1]r2
    {
      B[1][1]=k;
      flag[14]+=1;
      return 1;
    }
else if(B[1][1]==B[1][2] && flag[15]==15 && B[1][0]==' ')//[1][0]r2
    {
      B[1][0]=k;
      flag[15]+=1;
      return 1;
    }
else if(B[2][0]==B[2][1] && flag[16]==16 && B[2][2]==' ')//[2][2]r3
    {
      B[2][2]=k;
      flag[16]+=1;
      return 1;
    }
else if(B[2][0]==B[2][2] && flag[17]==17 && B[2][1]==' ')//[2][1]r3
    {
      B[2][1]=k;
      flag[17]+=1;
      return 1;
    }
else if(B[2][1]==B[2][2] && flag[18]==18 && B[2][0]==' ')//[2][0]r3
    {
      B[2][0]=k;
      flag[18]+=1;
      return 1;
    }
else if(B[0][2]==B[2][0] && flag[19]==19 && B[1][1]==' ')//([1][1]/)
    {
      B[1][1]=k;
      flag[19]+=1;
      return 1;
    }
else if(B[0][2]==B[1][1] && flag[20]==20 && B[2][0]==' ')//([2][0]/)
    {
      B[2][0]=k;
      flag[20]+=1;
      return 1;
    }
else if(B[1][1]==B[2][0] && flag[21]==21 && B[0][2]==' ')//([0][2]/)
    {
      B[0][2]=k;
      flag[21]+=1;
      return 1;
    }
else if(B[0][0]==B[2][2] && flag[22]==22 && B[1][1]==' ')//([1][1]\)
    {
      B[1][1]=k;
      flag[22]+=1;
      return 1;
    }
else if(B[0][0]==B[1][1] && flag[23]==23 && B[2][2]==' ')//([2][2]\)
    {
      B[2][2]=k;
      flag[23]+=1;
      return 1;
    }
else if(B[1][1]==B[2][2] && flag[24]==24 && B[0][0]==' ')//([0][0]\)
    {
      B[0][0]=k;
      flag[24]+=1;
      return 1;
    }
    
    else if(B[0][0] == ' ')
    {
      B[0][0]=k;
     return 1;
    }
    else if(B[2][0] == ' ')
    {
      B[2][0]=k;
     return 1;
    }
   else if(B[2][2] == ' ')
    {
      B[2][2]=k;
     return 1;
    }
     else if(B[0][2] == ' ')
    {
      B[0][2]=k;
      return 1;
    }


}

int wining(char B[3][3])
{
  for (int i=0;i<3;i++) //check rows
  {
    if(B[i][0]==B[i][1] &&  B[i][0]==B[i][2]&& B[i][0]=='x')
    {
        printf(YELLOW"\nplayer x won\n"RESET);
        return 1;
    }
    else if(B[i][0]==B[i][1] && B[i][0]==B[i][2]&& B[i][0]=='o')
    {
        printf(YELLOW"\nplayer o won\n"RESET);
        return 1;
    }
  }
  for (int j=0 ; j<3 ;j++ ) //check columns
  {
     if(B[0][j]==B[1][j] && B[0][j]==B[2][j]&&B[0][j]=='x')
     {
      printf(YELLOW"\nplayer x won\n"RESET);
      return 1;
     }
     else if(B[0][j]==B[1][j] && B[0][j]==B[2][j] && B[0][j]=='o')
     {
      printf(YELLOW"\nplayer o won\n"RESET);
      return 1;
     }
  }
    if(B[0][0]==B[1][1] && B[0][0]==B[2][2] && B[0][0]=='x')
    {
       printf(YELLOW"\nplayer x won\n"RESET);
       return 1;
    }
    else if(B[0][0]==B[1][1] && B[0][0]==B[2][2] && B[0][0]=='o')
    {
       printf(YELLOW"\nplayer o won\n"RESET);
       return 1;
    }
    else if(B[0][2]==B[1][1] && B[0][2]==B[2][0] && B[0][2]=='x')
    {
       printf(YELLOW"\nplayer x won\n"RESET);
       return 1;
    }
    else if(B[0][2]==B[1][1] && B[0][2]==B[2][0] && B[0][2]=='o')
    {
       printf(YELLOW"\nplayer o won\n"RESET);
       return 1;
    }
    int count=0;
    for(int i=0 ;i<3;i++)
     {
       for(int j=0;j<3;j++)
       {
        if(B[i][j]=='x' || B[i][j]=='o')
        {
          count++;
        }
       }
     }
     if(count==9) //cheking empty places
     {
      printf(RED"\nit's a tie\n no places are empty to play \n"RESET);
      return 1;
     }
}  

int main()
{     char B[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' ',};
      int flag[28]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25.26,27,28};
      int num;
    char symx='x';
    char symo='o';
    char p,k;
    int w;
     printf(MAGENTA"\nwelcome to XO\n"RESET);
     printf(MAGENTA"press [0] for easy [1] for normal & [2] for impossible :()\n"RESET);//choosing level
     printf(MAGENTA"\nfor two players mode press [3]\n"RESET);
     int D;
     scanf("%d",&D);
     if(D==0)
{
    printf(CYAN"\nwelcom to easy level :)\n"RESET);  //easy mode
     printf(CYAN"\nplease choose x or o\n"RESET);
    printf(CYAN"for x press 0 for o press 1\n"RESET);
    scanf("%d",&num);   //choosing x or y
 if(num==0)
 {
     p=symx;
        k=symo;
    int w, z=1;
   while(z==1 && w!=1)
   {
   body(B);
    player(B,p);
     if(wining(B)==1)
     {
      body(B);
      w=wining(B);
      break;
     }
     compE(B,k);
   }
 }
 else if(num ==1)
{
        p=symo;
        k=symx;
         int w, z=1;
   while(z==1 && w!=1)
   {
    
   body(B);
    player(B,p);
     if(wining(B)==1)
     {
      body(B);
      w=wining(B);
      break;
     }
     compE(B,k);
   }
}
}
     if(D==1)
{
    printf(CYAN"\nwelcome to normal level :)\n"RESET);  //normal mode
    printf(CYAN"\nplease choose x or o\n"RESET);
    printf(CYAN"for x press 0 for o press 1\n"RESET);
    scanf("%d",&num);//choosing x or y
    int x;
    if(num==0)
    {
        p=symx;
        k=symo;
        while(x!=1)
      { 
        body(B);
        player(B,p);
        if(wining(B)==1)
        {
        body(B);
        w=wining(B);
        break;
        }
        compNI(B,k,flag);
      }
    } 
    else if(num ==1)
    {
        p=symo;
        k=symx;
        while (x!=1)
        {
         body(B);
        player(B,p);
        if(wining(B)==1)
        {
         body(B);
         w=wining(B);
         break;
        }  
        compNI(B,k,flag);

        }
    }
}
    if (D==2)          //  impossible mode   
    {
         p=symx;
        k=symo;
        printf(CYAN"\nwelcome to impossible level :(\n"RESET);
        int x;
    while(x!=1)
    {
    compNI(B,k,flag);
    body (B);
    if(  wining(B)==1)
    {
      body (B);
     break;
    }
    player(B,p);     
    }
    }

    if(D==3)
{
       printf(CYAN"\nwelcom to two players mode :)\n"RESET);  //player vs player
     printf(CYAN"\nplease choose x or o for the first player\n"RESET);
    printf(CYAN"for x press 0 for o press 1\n"RESET);
    scanf("%d",&num);   //choosing x or y
    int x;
    if(num==0)
    {
      p=symx;
      k=symo;
        while(x!=1)
        {
          body(B);
          player(B,p);
     if(wining(B)==1)
     {
      body(B);
      w=wining(B);
      break;
     }
          body(B);
          player2(B,k);
      if(wining(B)==1)
     {
      body(B);
      w=wining(B);
      break;
     }
        }
    }
    if(num==1)
    {
      p=symo;
      k=symx;
        while(x!=1)
        {
          body(B);
          player(B,p);
     if(wining(B)==1)
     {
      body(B);
      w=wining(B);
      break;
     }
          body(B);
          player2(B,k);
      if(wining(B)==1)
     {
      body(B);
      w=wining(B);
      break;
     }
        }
    }
}
                    int a;
                    printf("\ndo you want to play again ?????????\n");
                        printf("press 1 if yes & 0 for noooo\n");
                    scanf("%d",&a);
                       if(a ==1)
                       {
                          main();
                       }
    getch(); 
}