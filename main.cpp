#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gamerOver;
const int width=20;
const int height=20;
int tailX[100],tailY[100],nTail;

int x,y, fruitX, fruitY,score;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void setup()
{
    gamerOver=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitX = rand()% width;
    fruitY = rand()% height;
    score=0;
}

void draw()
{
    system("cls");
    cout<<"score: "<<score<<endl;
    for(int i=0;i<width+2;i++)
        cout<<"#";
    cout<<endl;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
                cout<<"#";
            if(i==y && j==x)
                cout<<"O";
            else if(i==fruitY && j==fruitX)
                cout<<"F";
            else
            {
                bool print=false;
                for(int k=0;k<nTail;k++)
                {
                    if(tailX[k]==j && tailY[k]==i)
                    {
                        cout<<"o";
                        print=true;
                    }
                }
                if(!print)
                        cout<<" ";

            }
            if(j==width-1)
                cout<<"#";

        }
        cout<<endl;

    }
    for(int i=0;i<width+2;i++)
        cout<<"#";
    cout<<endl;

}
void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            dir=LEFT;
            break;
        case'w':
            dir=UP;
            break;
        case 's':
            dir=DOWN;
            break;
        case 'd':
            dir=RIGHT;
            break;
        case 'x':
            gamerOver=true;
            break;
        }

    }
}
void logic()
{
    int prvX=tailX[0];
    int prvY=tailY[0];
    int prvX2,prvY2;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<=nTail;i++)
    {
        prvX2=tailX[i];
        prvY2=tailY[i];
        tailX[i]=prvX;
        tailY[i]=prvY;
        prvX=prvX2;
        prvY=prvY2;
    }
    switch(dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    //if(x==0 || x>width || y>height || y<0)
       // gamerOver=true;
    if(x>=width)x=0;else if(x<0)x=width-1;
    if(y>=height)y=0;else if(y<0)y=height-1;

    for(int i=0;i<nTail;i++)if(tailX[i]==x && tailY[i]==y)gamerOver=true;
    if(x==fruitX && y==fruitY)
    {
         score+=10;
         fruitX = rand()% width;
         fruitY = rand()% height;
          nTail++;
    }

}
int main()
{
    cout << "Hello world!" << endl;
    setup();
    while (!gamerOver)
    {

        draw();
        input();
        logic();
        Sleep(20);
    }
    system("cls");
    cout<<"               GAME OVER        "<<endl;

    cout<<"your score: "<<score<<endl;
    cout<<"Don't press any key "<<endl;
    cout<<"Game will stop auto"<<endl;
    Sleep(5000);
    return 0;
}
