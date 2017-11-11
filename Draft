//
//  main.cpp
//  Project_2
//
//  Created by Anthony Accomando on 11/11/17.
//  Copyright © 2017 Anthony Accomando. All rights reserved.
//

#include <iostream>
using namespace std;

struct vector2
{
    int weightSum;
    int dirPath;
};

// 2 4 (Rows, Columns)
// 1 2 3 4
// 5 6 7 8
int main() {
    
    const int row = 2;
    const int col = 4;
    
    int testMatrix[row][col] =
    {
        {2,6,3,4},
        {5,6,7,8}
    };
    
    int i;
    int j;
    
//    int left = (testMatrix[i - 1][j - 1]) * 1.4;
//    int up = testMatrix[i - 1][j];
//    int right = (testMatrix[i - 1][j + 1]) * 1.4;

    int newMatrix[row][col];
    
//    int testMatrix[row][col] = {0};
//    for (int i = 1; i <= row; i++)
//    {
//        for( int j = 0; j<= col; j++)
//        {}
//    }
    
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
            newMatrix[i][j] = testMatrix[i][j];
        }
    }

    
    for (i = 1; i <= row; i++) //Pull in weights for remaining rows of weighted matrix
    {
        
        for(j = 0; j < col; j++)
        {
            //If in left-most column (only compare up and to right)
            int up = testMatrix[i - 1][j];
            int right = ((testMatrix[i - 1][j + 1]) * 1.4);
            int left = ((testMatrix[i - 1][j - 1]) * 1.4);
            
            
            if(j == 0)
            {
                if(up < right)
                {
                    newMatrix[i][j] += up;
                }
                else newMatrix[i][j] += right;
            }
            //If in right-most column (only compare left and up)
            if(j == col)
            {
                if(up < left)
                {
                    newMatrix[i][j] += up;
                }
                else newMatrix[i][j] += left;
            }
            //Any columns inbetween
            else
            {
                if(up < right)
                {
                    if(left < up)
                    {
                        newMatrix[i][j] += left;
                    }
                    else newMatrix[i][j] += up;
                }
                else newMatrix[i][j] += right;
            }
        }
    }
    
    for (i = 0; i < row; i++)   //Print out New Weighted Matrix
    {
        for(j = 0; j < col; j++)
        {
            cout << newMatrix[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}
