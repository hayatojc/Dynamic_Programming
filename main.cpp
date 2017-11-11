#include <iostream>
using namespace std;

//Struct to hold the values required in each array element
struct vector2
{
    int weightSum;
    int dirPath;
};

int main() {

    //Dummy data for original matrix
    const int row = 2;
    const int col = 4;

    int testMatrix[row][col] =
    {
        {2,6,1,2},
        {5,6,7,8}
    };

    int i;
    int j;

    vector2 newMatrix[row][col];

    //Fills Original Matrix with Dummy Data above
    cout << "Test Matrix:" << endl; //Print out Original Matrix

    for (i = 0; i < row; i++)
        {
            for(j = 0; j < col; j++)
            {
                cout << testMatrix[i][j] << "  ";
            }
            cout << endl;
        }

    cout << "New Matrix: " << endl;

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
            int up = testMatrix[i-1][j];
            int right = 0;
            if (j != col) right = ((testMatrix[i - 1][j + 1]) * 1.4);
            int left = 0;
            if (j != 0) left = ((testMatrix[i - 1][j - 1]) * 1.4);

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
            else if(j == col)
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
                        newMatrix[i][j].weightSum = up;
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
            cout << newMatrix[i][j].weightSum << "  ";
        }
        cout << endl;
    }

        for (i = 0; i < row; i++)   //Print out New Weighted Matrix
    {
        for(j = 0; j < col; j++)
        {
            cout << newMatrix[i][j].dirPath << "  ";
        }
        cout << endl;
    }
    return 0;
}
