#include<iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;
char fill[3][3];
void printresult()
{
    int count=0,flag=0,i,j;
    cout<<"\n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(flag==1)
            {
                cout<<"\t|\t"<<::fill[i][j];
            }
            else
            {
                cout<<"\t"<<::fill[i][j];
                flag=1;
            }
        }
            cout<<"\n";
            if(count<2)
            {
                cout<<"    -------------------------------------------\n";
                count++;
            }
            flag=0;
    }
}
int smartmove(iint input[],int n)
{

}
void insertchar(int a,char c)
{
    switch(a)
    {
        case 1: ::fill[0][0]=c;
                break;
        case 2: ::fill[0][1]=c;
                break;
        case 3: ::fill[0][2]=c;
                break;
        case 4: ::fill[1][0]=c;
                break;
        case 5: ::fill[1][1]=c;
                break;
        case 6: ::fill[1][2]=c;
                break;
        case 7: ::fill[2][0]=c;
                break;
        case 8: ::fill[2][1]=c;
                break;
        case 9: ::fill[2][2]=c;
                break;
    }
}
int check()
{
    if(::fill[0][0]=='0'&&::fill[0][1]=='0'&&::fill[0][2]=='0'||::fill[0][0]=='X'&&::fill[0][1]=='X'&&::fill[0][2]=='X')
        return 1;
    else if(::fill[1][0]=='0'&&::fill[1][1]=='0'&&::fill[1][2]=='0'||::fill[1][0]=='X'&&::fill[1][1]=='X'&&::fill[1][2]=='X')
        return 1;
    else if(::fill[2][0]=='0'&&::fill[2][1]=='0'&&::fill[2][2]=='0'||::fill[2][0]=='X'&&::fill[2][1]=='X'&&::fill[2][2]=='X')
        return 1;
    else if(::fill[0][0]=='0'&&::fill[1][1]=='0'&&::fill[2][2]=='0'||::fill[0][0]=='X'&&::fill[1][1]=='X'&&::fill[2][2]=='X')
        return 1;
    else if(::fill[0][2]=='0'&&::fill[1][1]=='0'&&::fill[2][0]=='0'||::fill[0][2]=='X'&&::fill[1][1]=='X'&&::fill[2][0]=='X')
        return 1;
    else
        return 0;
}
main()
{
    cout<<"\nTIC TAC TOE\n"<<"\nPlayer have to enter position\n";
    int count=49,i,j,k,temp,input[9],p1win=0,p2win=0,mode,breakflag=0;
    srand(time(0));
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            ::fill[i][j]=count;
            count++;
        }
    }
    cout<<"\n !! Mode !! \n   1) 1 vs Computer \n   2) 1 vs 1 \n\nEnter :";
    cin>>mode;
    cout<<"\n Game Started \n";
    switch(mode)
    {
        case 1: cout<<"\nYou : X AND Computer : O\n";
                for(i=0;i<9;i++)
                {
                    printresult();
                    if(i==0||i==2||i==4||i==6||i==8)
                    {
                        cout<<"\nYour turn : ";
                        cin>>input[i];
                        insertchar(input[i],'X');
                        p1win=check();
                        if(p1win==1)
                            break;
                    }
                    else
                    {
                        cout<<"\n Computer turn !\n";
                        /*for(k=0;k<9;k++)
                        {
                            breakflag=0;
                            temp=rand()%10+1;
                            for(j=0;j<9;j++)
                            {
                                if(temp==input[i])
                                    continue;
                                else
                                {
                                    input[i]=temp;
                                    breakflag=1;
                                    break;
                                }
                                if(breakflag==1)
                                    break;
                            }
                        }*/
                        input[i]=smartmove(intput[],i);
                        insertchar(input[i],'O');
                        p2win=check();
                        if(p2win==1)
                            break;
                    }
                }
                if(p1win==1)
                {
                    cout<<"\n        ** Player 1 Wins **\n";
                }
                else if(p2win==1)
                {
                    cout<<"\n        ** Computer Wins **\n";
                }
                else
                    cout<<"\n        ** Game TIE Wins **\n";
                break;
        case 2: cout<<"\nPlayer 1 : X AND Player 2 : O\n";
                for(i=0;i<9;i++)
                {
                    printresult();
                    if(i==0||i==2||i==4||i==6||i==8)
                    {
                        cout<<"\nPlayer 1 turn : ";
                        cin>>input[i];
                        insertchar(input[i],'X');
                        p1win=check();
                        if(p1win==1)
                            break;
                    }
                    else
                    {
                        cout<<"\nPlayer 2 turn : ";
                        cin>>input[i];
                        insertchar(input[i],'O');
                        p2win=check();
                        if(p2win==1)
                            break;
                    }
                }
                if(p1win==1)
                {
                    cout<<"\n        ** Player 1 Wins **\n";
                }
                else if(p2win==1)
                {
                    cout<<"\n        ** Player 2 Wins **\n";
                }
                else
                    cout<<"\n        ** Game TIE Wins **\n";
                break;
    }
}
