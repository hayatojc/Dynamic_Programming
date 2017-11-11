#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

//Struct to hold the values required in each array element
struct vector2
{
    int weightSum;
    int dirPath;
};

int main() {

    //file read
    ifstream inFile;
    inFile.open("input-small.txt");
    if (!inFile)
    {
    cerr << "Unable to open file input-small.txt";
    exit(1);
    }
    int row = 0;
    int col = 0;
    inFile >> row >> col;
    int testMatrix[row][col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            inFile >> testMatrix[i][j];

    //declares i and j for all future uses in loops
    int i;
    int j;

    vector2 newMatrix[row][col];

    //Print out Original Matrix
    cout << "Test Matrix:" << endl;
    for (i = 0; i < row; i++)
        {
            for(j = 0; j < col; j++)
            {
                cout << setw(3) << testMatrix[i][j] << "  ";
            }
            cout << endl;
        }

    //New Matrix
    cout << endl << "New Matrix: " << endl;
    for (i = 0; i < row; i++) //Pull in weights for first row of weighted matrix
    {
        for(j = 0; j < col; j++)
        {
            newMatrix[i][j].weightSum = testMatrix[i][j];
            newMatrix[i][j].dirPath = 0;
        }
    }


    for (i = 1; i < row; i++) //Pull in weights for remaining rows of weighted matrix
    {
        for(j = 0; j < col; j++)
        {
            //If in left-most column (only compare up and to right)
            int up = newMatrix[i-1][j].weightSum;
            int right = 0;
            if (j != col) right = ((newMatrix[i - 1][j + 1].weightSum) * 1.4);
            int left = 0;
            if (j != 0) left = ((newMatrix[i - 1][j - 1].weightSum) * 1.4);

            if(j == 0)
            {
                if(up <= right)
                {
                    newMatrix[i][j].weightSum += up;
                    newMatrix[i][j].dirPath = 0;
                }
                else
                {
                    newMatrix[i][j].weightSum += right;
                    newMatrix[i][j].dirPath = 1;
                }
            }
            //If in right-most column (only compare left and up)
            else if(j == col)
            {
                if(up <= left)
                {
                    newMatrix[i][j].weightSum += up;
                    newMatrix[i][j].dirPath = 0;
                }
                else
                {
                    newMatrix[i][j].weightSum += left;
                    newMatrix[i][j].dirPath = -1;
                }
            }
            //Any columns inbeetween
            else
            {
                if(up <= right)
                {
                    if(left < up)
                    {
                        newMatrix[i][j].weightSum += left;
                        newMatrix[i][j].dirPath = -1;
                    }
                    else
                    {
                        newMatrix[i][j].weightSum += up;
                        newMatrix[i][j].dirPath = 0;
                    }
                }
                else
                    if( right < left)
                    {
                    newMatrix[i][j].weightSum += right;
                    newMatrix[i][j].dirPath = 1;
                    }
                    else
                    {
                        newMatrix[i][j].weightSum += left;
                        newMatrix[i][j].dirPath = -1;
                    }

            }
        }
    }

    //Print out the matrix for debugging purposes
    for (i = 0; i < row; i++)   //Print out New Weighted Matrix
    {
        for(j = 0; j < col; j++)
        {
            cout << setw(3) << newMatrix[i][j].weightSum << "  ";
        }
        cout << endl;
    }

        for (i = 0; i < row; i++)   //Print out New Weighted Matrix
    {
        for(j = 0; j < col; j++)
        {
            cout << setw(3) << newMatrix[i][j].dirPath << "  ";
        }
        cout << endl;
    }
    return 0;
}
