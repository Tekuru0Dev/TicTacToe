#include <iostream>
using namespace std;

string n1;
string n2;
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
bool tie = false;
int column;
char token = 'x';


void Draw()
{
    cout << "   |     |   \n";
    cout << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << "  \n";
    cout << "___|_____|___\n";
    cout << "   |     |   \n";
    cout << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << "  \n";
    cout << "___|_____|___\n";
    cout << "   |     |   \n";
    cout << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << "  \n";
    cout << "   |     |   \n";
}

void Turns()
{
    int digit;

    if(token == 'x')
    {
        cout << n1 << " Please enter position : ";
        cin >> digit;
    }
    else if(token == 'O')
    {
        cout << n2 << " Please enter position : ";
        cin >> digit;
    }
    else if(digit == 1)
    {
        row = 0;
        column = 0;
    }
    else if(digit == 2)
    {
        row = 0;
        column = 1;
    }
    else if(digit == 3)
    {
        row = 0;
        column = 2;
    }
    else if(digit == 4)
    {
        row = 1;
        column = 0;
    }
    else if(digit == 5)
    {
        row = 1;
        column = 1;
    }
    else if(digit == 6)
    {
        row = 1;
        column = 2;
    }
    else if(digit == 7)
    {
        row = 2;
        column = 0;
    }
    else if(digit == 8)
    {
        row = 2;
        column = 1;
    }
    else if(digit == 9)
    {
        row = 2;
        column = 2;
    }
    else if(digit < 1 || digit > 9)
    {
        cout << "Invalid!!!" << endl;
    }

    if(token == 'x' && space[row][column] != 'x' && space[row][column] != 'O')
    {
        space[row][column] = 'x';
        token = 'O';
    }
    else if(token == '0' && space[row][column] != 'x' && space[row][column] != 'O')
    {
        space[row][column] = 'O';
        token = 'x';
    }
    else
    {
        cout << "Invalid choice!!!!" << endl;
        Turns();
    }
}

bool hasWon()
{
    for(int i = 0; i < 3; i++)
    {
        if((space[i][0] == space[i][1] && space[i][0] == space[i][2]) || (space[0][i] == space[1][i] && space[0][i] == space[2][i]))
        {
            return true;
        }
    }
    if((space[0][0] == space[1][1] && space[0][0] == space[2][2]) || (space[0][2] == space[1][1] && space[0][2] == space[2][0]))
    {
        return true;
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(space[i][j] != 'x' && space[i][j] != 'O')
            {
                return false;
            }
        }
    }

    tie = true;

    return false;
}

int main()
{
    cout << "Enter name of player 1 : " << endl;
    getline(cin,n1);
    cout << "Second player name : " << endl;
    getline(cin,n2);

    cout << n1 << " will play first " << " and " << n2 << " plays second" << endl;
    while(!hasWon())
    {
        Draw();
        Turns();
    }

    if (tie) {
        cout << "It's a draw!\n";
    } else {
        cout << ((token == 'x') ? n2 : n1) << " has won!\n";
    }

    return 0;
}
