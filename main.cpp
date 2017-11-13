/*Group 5, Dynamic Programming */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>

using namespace std;
const int MAXR = 50;
const int MAXC = 50;

//Struct to hold the values required in each array element
struct vector2
{
    int weightSum;
    int dirPath;
};


void pathFinder(vector2 newMatrix[][MAXC], int row, int col, string outArray[])
{   int curPath = newMatrix[row][col].dirPath;
    int counter = row;
    if (row < 0)
        return;
    if (counter == 0)
    {
        ostringstream str1;
        str1 << col;
        string converts = str1.str();
        outArray[0] = converts;
        cout << col <<  " ";
        return;
    }

    if(curPath == -1)
    {
        outArray[counter] = "SE";
        cout << "SE :";
        pathFinder(newMatrix,counter-1,col-1,outArray);
    }
    else if(curPath == 0)
    {
        outArray[counter] = "S";
        cout << "S :";
        pathFinder(newMatrix,counter-1,col,outArray);
    }
    else if(curPath == 1)
    {
        outArray[counter] = "SW";
        cout << "SW :";
        pathFinder(newMatrix,counter-1,col+1,outArray);
    }

    else
    {
        cout << "Failed" << endl;
        return;
    }
}

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

    vector2 newMatrix[MAXR][MAXC];
    memset(newMatrix, 999, sizeof(testMatrix[0][0]) * row * col);

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

    //This solution iterates through the matrix storing the lowest optimal weights in
    //each cell. As well as it's dependant direction.
    for (i = 1; i < row; i++) //Pull in weights for remaining rows of weighted matrix
    {
        for(j = 0; j < col; j++)
        {
            //If in left-most column (only compare up and to right)
            int up = newMatrix[i-1][j].weightSum;
            int right = 0;
            if (j != col-1) right = ((newMatrix[i - 1][j + 1].weightSum) * 1.4);
            int left = 0;
            if (j != 0) left = ((newMatrix[i - 1][j - 1].weightSum) * 1.4);

            if(j == 0)
            {
                if(up < right)
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
            else if(j == col-1)
            {
                if(up < left)
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
                if(up < right)
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

    string outArray[row];
    for (int k = 0; k < row; k++)
    {
        outArray[k] = " ";
    }

    ofstream outFile;
    outFile.open("output.txt");

    //Print out short path of each bottom element.
    for (int j = 0; j < col;j++)
    {
        cout << endl;
        pathFinder(newMatrix,row-1,j, outArray);
        for (int j = 0;j<row;j++)
        {
            outFile << outArray[j] << " ";
        }
        outFile << endl;
    }
    outFile.close();
    return 0;

}


