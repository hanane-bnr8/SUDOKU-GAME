#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int const col = 9;
bool checkrow(char A[][col], int n, int m)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            for (k = 0; k < m; k++)
            {
                if (k != j && A[i][j] == A[i][k] && A[i][j] != ' ')
                    return false;
            }
        }
    }
    return true;
}

bool checkcolumn(char A[][col], int n, int m)
{
    int i, j, k;
    for (j = 0; j < m; j++)
    {
        for (i = 0; i < n; i++)
        {
            for (k = 0; k < n; k++)
            {
                if (i != k && A[i][j] == A[k][j] && A[i][j] != ' ')
                    return false;
            }
        }
    }
    return true;
}

bool checksub(char A[][9], int row, int col)
{
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = startRow; i < startRow + 3; i++)
        for (int j = startCol; j < startCol + 3; j++)
            if ((i != row || j != col) && A[i][j] == A[row][col] && A[i][j] != ' ')
                return false;

    return true;
}

void printMatrix(char M[][col], int n, int m)
{
    int i, j;
    cout << " |  0| 1|  2|  3|  4|  5|  6|  7|  8| ";
    cout << endl;
    for (i = 0; i < 9; i++)
    {
        if (i == 3 || i == 6)
            cout << endl;
        cout << i << "* ";
        for (j = 0; j < 9; j++)
        {
            cout << M[i][j] << "|  ";
        }
        cout << endl;
    }
}

bool checkwin(char array[][9], int n, int m)
{
    int i, j, srow = 0, scol, srow0 = 0, scol0 = 0;
    for (j = 0; j < 9; j++)
    {
        srow0 += array[0][j]-'0';
    }
    for (int i = 1; i < 9; i++)
    {
        srow = 0;
        for (int j = 0; j < 9; j++)
        {
            srow += array[i][j]-'0';
        }
        if (srow != srow0)
            
        return false;
    }
    for (j = 0; j < 9; j++)
    {
        scol0 += array[j][0]-'0';
    }
    for (int i = 1; i < 9; i++)
    {
        scol = 0;
        for (int j = 0; j < 9; j++)
        {
            scol += array[j][i]-'0';
        }
        if (scol != scol0)
            
        return false;
    }
    if (srow0 != scol0)
        return false;
    return true;
}

void displaygrid(char sudoku[][9])
{
    srand(static_cast<unsigned>(time(0)));
    char col1, col2, col3, row1, row2, row3;
    do
    {
        col1 = rand() % 3  ;
        col2 = rand() % 3;
        col3 = rand() % 3;
    } while (col1 == col2 || col1 == col3 || col2 == col3);
    row1 = rand() % 3;
    row2 = rand() % 3;
    row3 = rand() % 3;
    do
    {
        sudoku[row1][col1] = rand() % 9 + '1';
        sudoku[row2][col2] = rand() % 9 + '1';
        sudoku[row3][col3] = rand() % 9 + '1';
    } while (!checkcolumn(sudoku, 9, 9) || !checkrow(sudoku, 9, 9) || !checksub(sudoku, row1,col1));

    do
    {
        col1 = rand() % 3;
        col2 = rand() % 3;
        col3 = rand() % 3;
    } while (col1 == col2 || col1 == col3 || col2 == col3);
    row1 = rand() % 3 + 3;
    row2 = rand() % 3 + 3;
    row3 = rand() % 3 + 3;
    do
    {
        sudoku[row1][col1] = rand() % 9 + '1';
        sudoku[row2][col2] = rand() % 9 + '1';
        sudoku[row3][col3] = rand() % 9 + '1';
    } while (!checkcolumn(sudoku, 9, 9) || !checkrow(sudoku, 9, 9) || !checksub(sudoku, row1, col1));

    do
    {
        col1 = rand() % 3;
        col2 = rand() % 3;
        col3 = rand() % 3;
    } while (col1 == col2 || col1 == col3 || col2 == col3);
    row1 = rand() % 3 + 6;
    row2 = rand() % 3 + 6;
    row3 = rand() % 3 + 6;
    do
    {
        sudoku[row1][col1] = rand() % 9 + '1';
        sudoku[row2][col2] = rand() % 9 + '1';
        sudoku[row3][col3] = rand() % 9 + '1';
    } while (!checkcolumn(sudoku, 9, 9) || !checkrow(sudoku, 9, 9) || !checksub(sudoku, row1, col1));
    do
    {
        col1 = rand() % 3 + 3;
        col2 = rand() % 3 + 3;
        col3 = rand() % 3 + 3;
    } while (col1 == col2 || col1 == col3 || col2 == col3);
    row1 = rand() % 3;
    row2 = rand() % 3;
    row3 = rand() % 3;
    do
    {
        sudoku[row1][col1] = rand() % 9 + '1';
        sudoku[row2][col2] = rand() % 9 + '1';
        sudoku[row3][col3] = rand() % 9 + '1';
    } while (!checkcolumn(sudoku, 9, 9) || !checkrow(sudoku, 9, 9) || !checksub(sudoku, row1, col1));
    do
    {
        col1 = rand() % 3 + 3;
        col2 = rand() % 3 + 3;
        col3 = rand() % 3 + 3;
    } while (col1 == col2 || col1 == col3 || col2 == col3);
    row1 = rand() % 3 + 3;
    row2 = rand() % 3 + 3;
    row3 = rand() % 3 + 3;
    do
    {
        sudoku[row1][col1] = rand() % 9 + '1';
        sudoku[row2][col2] = rand() % 9 + '1';
        sudoku[row3][col3] = rand() % 9 + '1';
    } while (!checkcolumn(sudoku, 9, 9) || !checkrow(sudoku, 9, 9) || !checksub(sudoku, row1, col1));
    do
    {
        col1 = rand() % 3 + 3;
        col2 = rand() % 3 + 3;
        col3 = rand() % 3 + 3;
    } while (col1 == col2 || col1 == col3 || col2 == col3);
    row1 = rand() % 3 + 6;
    row2 = rand() % 3 + 6;
    row3 = rand() % 3 + 6;
    do
    {
        sudoku[row1][col1] = rand() % 9 + '1';
        sudoku[row2][col2] = rand() % 9 + '1';
        sudoku[row3][col3] = rand() % 9 + '1';
    } while (!checkcolumn(sudoku, 9, 9) || !checkrow(sudoku, 9, 9) ||!checksub(sudoku, row1, col1) );
    do
    {
        col1 = rand() % 3 + 6;
        col2 = rand() % 3 + 6;
        col3 = rand() % 3 + 6;
    } while (col1 == col2 || col1 == col3 || col2 == col3);
    row1 = rand() % 3;
    row2 = rand() % 3;
    row3 = rand() % 3;
    do
    {
        sudoku[row1][col1] = rand() % 9 + '1';
        sudoku[row2][col2] = rand() % 9 + '1';
        sudoku[row3][col3] = rand() % 9 + '1';
    } while (!checkcolumn(sudoku, 9, 9) || !checkrow(sudoku, 9, 9) || !checksub(sudoku, row1, col1));
    do
    {
        col1 = rand() % 3 + 6;
        col2 = rand() % 3 + 6;
        col3 = rand() % 3 + 6;
    } while (col1 == col2 || col1 == col3 || col2 == col3);
    row1 = rand() % 3 + 3;
    row2 = rand() % 3 + 3;
    row3 = rand() % 3 + 3;
    do
    {
        sudoku[row1][col1] = rand() % 9 + '1';
        sudoku[row2][col2] = rand() % 9 + '1';
        sudoku[row3][col3] = rand() % 9 + '1';
    } while (!checkcolumn(sudoku, 9, 9) || !checkrow(sudoku, 9, 9) ||!checksub(sudoku, row1, col1));
    do
    {
        col1 = rand() % 3 + 6;
        col2 = rand() % 3 + 6;
        col3 = rand() % 3 + 6;
    } while (col1 == col2 || col1 == col3 || col2 == col3);
    row1 = rand() % 3 + 6;
    row2 = rand() % 3 + 6;
    row3 = rand() % 3 + 6;
    do
    {
        sudoku[row1][col1] = rand() % 9 + '1';
        sudoku[row2][col2] = rand() % 9 + '1';
        sudoku[row3][col3] = rand() % 9 + '1';
    } while (!checkcolumn(sudoku, 9, 9) || !checkrow(sudoku, 9, 9) || !checksub(sudoku, row1, col1));
    printMatrix(sudoku, 9, 9);
}
int main()
{
    int counter = 0, row, col;
    char number;
    char sudoku[9][9] ;
for (int i = 0; i < 9; i++){{
    for (int j = 0; j < 9; j++)
        sudoku[i][j] = ' ';}}
    

    cout << "welcome to sudoku game " << endl;
    displaygrid(sudoku);
    while (counter < 54)
    {
        do
        {
            cout << "enter the row col the number"<<endl;
            cin >> row >> col >> number;
        } while (!checkcolumn(sudoku, 9, 9) || !checkrow(sudoku, 9, 9) || !checksub(sudoku, row, col) || sudoku[row][col] != ' ');
        sudoku[row][col] = number;
        printMatrix(sudoku, 9, 9);
        counter++;
    }
    if (checkwin(sudoku, 9, 9))
        cout << "CONGRATULATIONS! you won the game ";
} 