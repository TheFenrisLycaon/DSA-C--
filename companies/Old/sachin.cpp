#include <bits/stdc++.h>

char board[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

int checkwin()
{

    if (board[0] == board[1] && board[1] == board[2])
        return (board[0] == 'X') ? 1 : 2;

    else if (board[3] == board[4] && board[4] == board[5])
        return (board[3] == 'X') ? 1 : 2;

    else if (board[6] == board[7] && board[7] == board[8])
        return (board[6] == 'X') ? 1 : 2;

    else if (board[0] == board[3] && board[3] == board[6])
        return (board[0] == 'X') ? 1 : 2;

    else if (board[1] == board[4] && board[4] == board[7])
        return (board[1] == 'X') ? 1 : 2;

    else if (board[2] == board[5] && board[5] == board[8])
        return (board[2] == 'X') ? 1 : 2;

    else if (board[0] == board[4] && board[4] == board[8])
        return (board[0] == 'X') ? 1 : 2;

    else if (board[2] == board[4] && board[4] == board[6])
        return (board[2] == 'X') ? 1 : 2;

    else if (board[0] == board[3] && board[3] == board[6])
        return (board[0] == 'X') ? 1 : 2;

    else
        return 0;
}

void mark(int player, int box)
{
    if (player == 1)
        board[box] = 'X';
    else
        board[box] = 'O';
}

void display()
{
    for (int i = 0; i < 9; i++)
    {
        std ::cout << board[i] << "\t";
        if (i == 2 || i == 5 || i == 8)
            std ::cout << "\n";
    }
}

int main()
{
    int player1 = 1, player2 = 2;

    int box, result = 0, flag = 0;

    for (int i = 1; i < 5; i++)
    {

        std ::cout << "\nPlayer " << player1 << "\nEnter the Box :: \t";
        std ::cin >> box;

        mark(player1, box);

        display();

        result = checkwin();
        if (result == 1)
        {
            std ::cout << "\nCongratualtions! player " << player1 << " has Won ";
            flag = 1;
            break;
        }
        else if (result == 2)
        {
            std ::cout << "\nCongratualtions! player " << player2 << " has Won ";
            flag = 1;
            break;
        }

        std ::cout << "\nPlayer " << player2 << "\nEnter the Box :: \t";
        std ::cin >> box;

        mark(player2, box);
        display();

        result = checkwin();
        if (result == 1)
        {
            std ::cout << "\nCongratualtions! player " << player1 << " has Won ";
            flag = 1;
            break;
        }
        else if (result == 2)
        {
            std ::cout << "\nCongratualtions! player " << player2 << " has Won ";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        std ::cout << " \nSorry, The game is a draw ";

    return 0;
}