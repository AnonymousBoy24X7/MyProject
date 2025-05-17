#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

char Board[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}};
char user = 'X';
char computer = 'O';
void DisplayBoard()
{
    cout<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<" ";
        for(int j=0;j<3;j++)
        {
            cout<<Board[i][j];
            if(j<2)
            {
                cout<<" | ";
            }
        }
        if(i<2)
        {
            cout<<"\n------------\n";
        }
    }
    cout<<endl;

}
bool checkWin(char player)
{
    for(int i=0;i<3;i++)
    {
        if((Board[i][0] == player && Board[i][1] == player && Board[i][2] == player) || (Board[0][i] == player && Board[1][i] == player && Board[2][i] == player))
            return true;
    }
    if((Board[0][0] == player && Board[1][1] == player && Board[2][2] == player) || (Board[0][2] == player && Board[1][1] == player && Board[2][0] == player)) 
            return true;

    return false;
}

bool checkDraw()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(Board[i][j] != 'X' && Board[i][j] != 'O')
                return false;
    return true;
}

void userMove()
{
    int pos;
    cout<<"\nEnter Your Move (1-9):";
    cin>>pos;
    int row = (pos-1) / 3;
    int col = (pos-1) % 3;
    if(Board[row][col] != 'X' && Board[row][col] != 'O')
        Board[row][col]=user;
    else
    {
        cout<<"Invalid Move! Try Again.\n";
        userMove();
    }
}

void computerMove()
{
    srand(time(0));
    int row,col;
    while(true)
    {
        int pos =rand() % 9;
        row = pos / 3;
        col = pos % 3;
        if(Board[row][col] != 'X' && Board[row][col] != 'O')
        {
            Board[row][col]=computer;
            break;
        } 
    }
}

void resetBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            Board[i][j] = '-';  
}

int main()
{
    int choice;
    do{
        resetBoard();
        while(true)
        {
            DisplayBoard();
            userMove();
            if(checkWin(user))
            {
                DisplayBoard();
                cout<<"\nYou Win!\n";
                break;
            }
            if(checkDraw())
            {
                DisplayBoard();
                cout<<"\nIt's A Draw!";
                break;
            }
            computerMove();
            if(checkWin(computer))
            {
                DisplayBoard();
                cout<<"\nComputer Win!\n";
                break;
            }
            if(checkDraw())
            {
                DisplayBoard();
                cout<<"\nIt's A Draw!";
                break;
            }
        }
        cout << "\nDo You Want To Play Again? (1 - Yes, 2 - No): ";
        cin >> choice;
    }
    while(choice == 1);
    cout<<"\nGame Ended. Thanks For Playing!";
    return 0;
}