//**********************************************************************
// Board.hpp
// Author: Samuel Peters, David Olivares, Christian Ortiz
// Last Modified: 4/26/18
// Description: This class is designed to hold a 2d array which acts as
//              as a Tetris board. This board will be manipulated and
//              used to diplay sfml sprites.
//**********************************************************************

#ifndef Board_hpp
#define Board_hpp

#include <sfml/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Shape.hpp"
using namespace std;

class Board
{
protected:
    //X AND Y COORDINATES SHAPE'S CENTER OF ROTATION ON TETRIS BOARD
    int rotationPointX;
    int rotationPointY;
    
    //ARRAY HOLDS ALL OF THE BOARDS INFORMATION TO LATER BE DISPLAYED WITH SFML
    static const int HEIGHT = 28;
    static const int WIDTH = 10;
    int board[HEIGHT][WIDTH];
    
    //THE CURRENT SHAPE THAT THE BOARD IS DEALING WITH
    Shape tetrisShape;
    
    //INFO TO REACH OTHER POINTS ON SHAPE FROM REFERENCE POINTS
    const int I_INFO[2][3][2] =
    {
        //rotation 0
        {
            {0, -2},
            {0, -1},
            {0, 1},
        },
        //rotation 1
        {
            {-1, 0},
            {1, 0},
            {2, 0},
        },
    };
    const int L_INFO[4][3][2] =
    {
        //rotation 1
        {
            {0, -1},
            {0, 1},
            {1, 1},
        },
        //rotation 2
        {
            {-1, 1},
            {-1, 0},
            {1, 0},
        },
        //rotation 3
        {
            {-1, -1},
            {0, -1},
            {0, 1},
        },
        //rotation 4
        {
            {-1, 0},
            {1, 0},
            {1, -1},
        },
    };
    const int J_INFO[4][3][2] =
    {
        //rotation 1
        {
            {0, -1},
            {0, 1},
            {-1, 1},
        },
        //rotation 2
        {
            {-1, -1},
            {-1, 0},
            {1, 0},
        },
        //rotation 3
        {
            {1, -1},
            {0, -1},
            {0, 1},
        },
        //rotation 4
        {
            {-1, 0},
            {1, 0},
            {1, 1},
        }
    };
    const int O_INFO[1][3][2] =
    {
        //rotation 1
        {
            {-1, -1},
            {-1, 0},
            {0, -1},
        },
    };
    const int Z_INFO[2][3][2] =
    {
        //rotation 1
        {
            {-1, 0},
            {0, 1},
            {1, 1},
        },
        //rotation 2
        {
            {1, -1},
            {1, 0},
            {0, 1},
        },
    };
    const int S_INFO[2][3][2] =
    {
        //rotation 1
        {
            {-1, 0},
            {0, -1},
            {1, -1},
        },
        //rotation 2
        {
            {-1, -1},
            {-1, 0},
            {0, 1},
        },
    };
    const int T_INFO[4][3][2] =
    {
        //rotation 1
        {
            {-1, 0},
            {0, -1},
            {1, 0},
        },
        //rotation 2
        {
            {0, -1},
            {1, 0},
            {0, 1},
        },
        //rotation 3
        {
            {-1, 0},
            {1, 0},
            {0, 1},
        },
        //rotation 4
        {
            {0, -1},
            {-1, 0},
            {0, 1},
        }
    };
public:
    //CONSTRUCTORS
    //**********************************************************************************************
    Board();
    // Summary: This constructs the board which is mainly an array that holds the information that is passed to SFML to be displayed.
    // Preconditions:
    // PostConditions: A variable of type Board is created with a Shape variable inside of it.
    //**********************************************************************************************
    
    //GETTERS
    //**********************************************************************************************
    int getRotationPointX()const {return rotationPointX;}
    // Summary: The current X coorinate that the Shape piece rotates around is returned.
    // Preconditions: The X coordinate has been initialized.
    // PostConditions: An integer is returned that corresponds with the X rotation point.
    //**********************************************************************************************
    int getRotationPointY()const {return rotationPointY;}
    // Summary: The current Y coorinate that the Shape piece rotates around is returned.
    // Preconditions: The Y coordinate has been initialized.
    // PostConditions: An integer is returned that corresponds with the Y rotation point.
    //**********************************************************************************************
    int getBoardHeight()const {return HEIGHT;}
    // Summary: The constant variable HEIGHT is returned.
    // Preconditions: HEIGHT has been initialized.
    // PostConditions: HEIGHT of the board is returned.
    //**********************************************************************************************
    int getBoardWidth()const {return WIDTH;}
    // Summary: The constant variable WIDTH is returned.
    // Preconditions: WIDTH has been initialized.
    // PostConditions: WIDTH of the board is returned.
    //**********************************************************************************************
    
    //SETTERS
    //**********************************************************************************************
    void setRotationPointX(int rotationPointX);
    // Summary: This function changes the current rotation point of the tetris shape on the board.
    // Preconditions: Rotation point X must be more than 9 and less than 29.
    // PostConditions: The protected variable rotationPointX is set to the parameter RotationPointX.
    //**********************************************************************************************
    void setRotationPointY(int rotationPointY);
    // Summary: This function changes the current rotation point of the tetris shape on the board.
    // Preconditions: Rotation point Y must be more than 9 and less than 29.
    // PostConditions: The protected variable rotationPointY is set to the parameter RotationPointY.
    //**********************************************************************************************
    
    
    //MEMBER FUNCTIONS
    //**********************************************************************************************
    void fillBoardWithCurrentInfo();
    // Summary: This function fill the board array with current information.
    // Preconditions:
    // PostConditions: The board array is filled with info in reference to the x and y coordinates, the current shape, and the shape's rotation number.
    //**********************************************************************************************
    void moveShapeDown();
    // Summary: This function moves the y coordinate down one place on the screen.
    // Preconditions:
    // PostConditions: the y coordinate is increased by one.
    //**********************************************************************************************
    bool moveShapeLeft();
    // Summary: This function moves the x coordinate left one place on the screen.
    // Preconditions:
    // PostConditions: the x coordinate is decreased by one.
    //**********************************************************************************************
    bool moveShapeRight();
    // Summary: This function moves the x coordinate right one place on the screen.
    // Preconditions:
    // PostConditions: the x coordinate is increased by one.
    //**********************************************************************************************
    void rotateShape();
    // Summary: This function rotates the shape on the scrren.
    // Preconditions:
    // PostConditions: The shape's current rotation number is increased by one.
    //**********************************************************************************************
    void newShapeIfNeeded();
    // Summary: This checks to make sure a piece is not directly on top of another piece and solidifies it if it has reached the bottom.
    // Preconditions:
    // PostConditions: The piece is solidifed and the x and y rotation points are set back to their origin points while a new random shape is assigned if it is on top of another piece. If not, then nothing happens.
    //**********************************************************************************************
    void clearFilledRows();
    // Summary: This function gets rid of a row if that row is filled with pieces.
    // Preconditions: A row on the board variable is completely filled with 2s.
    // PostConditions: All rows containing all 0s are erased, and everything above that row is dropped down one.
    //**********************************************************************************************
    int AccessBoardByXY(int y, int x);
    // Summary: This function retrieves the current number on the board at a certain x and y coordinate.
    // Preconditions:
    // PostConditions: 0, 1, or 2 is returned depending on the value in board[y][x].
    //**********************************************************************************************
    
};
#endif /* Board_hpp */
