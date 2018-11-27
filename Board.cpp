//**********************************************************************
// Board.cpp
// Author: Samuel Peters, David Olivares, Christian Ortiz
// Last Modified: 4/26/18
// Description: This class is designed to hold a 2d array which acts as
//              as a Tetris board. This board will be manipulated and
//              used to diplay sfml sprites.
//**********************************************************************

#include "Board.hpp"
#include <cassert>
#include <vector>
#include <cmath>

//CONSTRUCTORS
//**********************************************************************************************
Board::Board()
{
    //makes blank board
    for (int y = 0; y < this->HEIGHT; y++)
    {
        for (int x = 0; x < this->WIDTH; x++)
        {
            if (y == (HEIGHT - 1) ) this->board[y][x] = 2;
            else this->board[y][x] = 0;
        }
    }
    
    //set rotation points
    setRotationPointX(4);
    setRotationPointY(2);
    
    //update board
    fillBoardWithCurrentInfo();
}

//SETTERS
//**********************************************************************************************
void Board::setRotationPointX(int rotationPointX)
{
    //error checking
    assert(rotationPointX >= 0);
    assert(rotationPointX <= 9);
    
    this->rotationPointX = rotationPointX;
}
//**********************************************************************************************
void Board::setRotationPointY(int rotationPointY)
{
    //error checking
    assert(rotationPointY >= 0);
    assert(rotationPointY <= 27);
    
    this->rotationPointY = rotationPointY;
}

//MEMBER FUNCTIONS
//**********************************************************************************************
void Board::fillBoardWithCurrentInfo()
{
    //erasing the board
    for (int y = 0; y < this->HEIGHT; y++)
    {
        for (int x = 0; x < this->WIDTH; x++)
        {
            if (board[y][x] == 1) this->board[y][x] = 0;
        }
    }
    
    //filling the board
    for (int y = 0; y < this->HEIGHT; y++)
    {
        for (int x = 0; x < this->WIDTH; x++)
        {
            if (this->rotationPointX == x && this->rotationPointY == y)
            {
                this->board[y][x] = 1;
                switch (this->tetrisShape.getShapeType())
                {
                    case 'I':
                        this->board[ y + I_INFO[tetrisShape.getCurrentRotation()][0][1] ][ x + I_INFO[tetrisShape.getCurrentRotation()][0][0] ] = 1;
                        this->board[ y + I_INFO[tetrisShape.getCurrentRotation()][1][1] ][ x + I_INFO[tetrisShape.getCurrentRotation()][1][0] ] = 1;
                        this->board[ y + I_INFO[tetrisShape.getCurrentRotation()][2][1] ][ x + I_INFO[tetrisShape.getCurrentRotation()][2][0] ] = 1;
                        break;
                    case 'L':
                        this->board[ y + L_INFO[tetrisShape.getCurrentRotation()][0][1] ][ x + L_INFO[tetrisShape.getCurrentRotation()][0][0] ] = 1;
                        this->board[ y + L_INFO[tetrisShape.getCurrentRotation()][1][1] ][ x + L_INFO[tetrisShape.getCurrentRotation()][1][0] ] = 1;
                        this->board[ y + L_INFO[tetrisShape.getCurrentRotation()][2][1] ][ x + L_INFO[tetrisShape.getCurrentRotation()][2][0] ] = 1;
                        break;
                    case 'J':
                        this->board[ y + J_INFO[tetrisShape.getCurrentRotation()][0][1] ][ x + J_INFO[tetrisShape.getCurrentRotation()][0][0] ] = 1;
                        this->board[ y + J_INFO[tetrisShape.getCurrentRotation()][1][1] ][ x + J_INFO[tetrisShape.getCurrentRotation()][1][0] ] = 1;
                        this->board[ y + J_INFO[tetrisShape.getCurrentRotation()][2][1] ][ x + J_INFO[tetrisShape.getCurrentRotation()][2][0] ] = 1;
                        break;
                    case 'O':
                        this->board[ y + O_INFO[tetrisShape.getCurrentRotation()][0][1] ][ x + O_INFO[tetrisShape.getCurrentRotation()][0][0] ] = 1;
                        this->board[ y + O_INFO[tetrisShape.getCurrentRotation()][1][1] ][ x + O_INFO[tetrisShape.getCurrentRotation()][1][0] ] = 1;
                        this->board[ y + O_INFO[tetrisShape.getCurrentRotation()][2][1] ][ x + O_INFO[tetrisShape.getCurrentRotation()][2][0] ] = 1;
                        break;
                    case 'Z':
                        this->board[ y + Z_INFO[tetrisShape.getCurrentRotation()][0][1] ][ x + Z_INFO[tetrisShape.getCurrentRotation()][0][0] ] = 1;
                        this->board[ y + Z_INFO[tetrisShape.getCurrentRotation()][1][1] ][ x + Z_INFO[tetrisShape.getCurrentRotation()][1][0] ] = 1;
                        this->board[ y + Z_INFO[tetrisShape.getCurrentRotation()][2][1] ][ x + Z_INFO[tetrisShape.getCurrentRotation()][2][0] ] = 1;
                        break;
                    case 'S':
                        this->board[ y + S_INFO[tetrisShape.getCurrentRotation()][0][1] ][ x + S_INFO[tetrisShape.getCurrentRotation()][0][0] ] = 1;
                        this->board[ y + S_INFO[tetrisShape.getCurrentRotation()][1][1] ][ x + S_INFO[tetrisShape.getCurrentRotation()][1][0] ] = 1;
                        this->board[ y + S_INFO[tetrisShape.getCurrentRotation()][2][1] ][ x + S_INFO[tetrisShape.getCurrentRotation()][2][0] ] = 1;
                        break;
                    case 'T':
                        this->board[ y + T_INFO[tetrisShape.getCurrentRotation()][0][1] ][ x + T_INFO[tetrisShape.getCurrentRotation()][0][0] ] = 1;
                        this->board[ y + T_INFO[tetrisShape.getCurrentRotation()][1][1] ][ x + T_INFO[tetrisShape.getCurrentRotation()][1][0] ] = 1;
                        this->board[ y + T_INFO[tetrisShape.getCurrentRotation()][2][1] ][ x + T_INFO[tetrisShape.getCurrentRotation()][2][0] ] = 1;
                        break;
                }
            }
        }
    }
}
//**********************************************************************************************
void Board::moveShapeDown()
{
    //move down
    this->rotationPointY++;
    
    //update the board
    fillBoardWithCurrentInfo();
}
//**********************************************************************************************
bool Board::moveShapeLeft()
{
    //original x value
    int originalX = rotationPointX;
    
    //check if shape will be out of bounds
    bool willBeOutOfBounds = false;
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (board[y][x] == 1)
            {
                if (x == 0 || board[y][x - 1] == 2) willBeOutOfBounds = true;
            }
        }
    }
    
    if (willBeOutOfBounds == false)
    {
        //move left
        this->rotationPointX--;
        
        //update the board
        fillBoardWithCurrentInfo();
    }
    
    if (originalX == rotationPointX) return false;
    else return true;
}
//**********************************************************************************************
bool Board::moveShapeRight()
{
    //original x value
    int originalX = rotationPointX;
    
    //check if shape will be out of bounds
    bool willBeOutOfBounds = false;
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (board[y][x] == 1)
            {
                if (x == 9 || board[y][x + 1] == 2) willBeOutOfBounds = true;
            }
        }
    }
    
    if (willBeOutOfBounds == false)
    {
        //move right
        this->rotationPointX++;
        
        //update the board
        fillBoardWithCurrentInfo();
        
    }
    
    if (originalX == rotationPointX) return false;
    else return true;
}
//**********************************************************************************************
void Board::rotateShape()
{
    //find points to check
    int nextRotation = this->tetrisShape.findNextRotation();
    int pointsToCheckX[3];
    switch (this->tetrisShape.getShapeType())
    {
        case 'I':
            pointsToCheckX[0] = I_INFO[nextRotation][0][0];
            pointsToCheckX[1] = I_INFO[nextRotation][1][0];
            pointsToCheckX[2] = I_INFO[nextRotation][2][0];
            break;
        case 'L':
            pointsToCheckX[0] = L_INFO[nextRotation][0][0];
            pointsToCheckX[1] = L_INFO[nextRotation][1][0];
            pointsToCheckX[2] = L_INFO[nextRotation][2][0];
            break;
        case 'J':
            pointsToCheckX[0] = J_INFO[nextRotation][0][0];
            pointsToCheckX[1] = J_INFO[nextRotation][1][0];
            pointsToCheckX[2] = J_INFO[nextRotation][2][0];
            break;
        case 'O':
            pointsToCheckX[0] = O_INFO[nextRotation][0][0];
            pointsToCheckX[1] = O_INFO[nextRotation][1][0];
            pointsToCheckX[2] = O_INFO[nextRotation][2][0];
            break;
        case 'Z':
            pointsToCheckX[0] = Z_INFO[nextRotation][0][0];
            pointsToCheckX[1] = Z_INFO[nextRotation][1][0];
            pointsToCheckX[2] = Z_INFO[nextRotation][2][0];
            break;
        case 'S':
            pointsToCheckX[0] = S_INFO[nextRotation][0][0];
            pointsToCheckX[1] = S_INFO[nextRotation][1][0];
            pointsToCheckX[2] = S_INFO[nextRotation][2][0];
            break;
        case 'T':
            pointsToCheckX[0] = T_INFO[nextRotation][0][0];
            pointsToCheckX[1] = T_INFO[nextRotation][1][0];
            pointsToCheckX[2] = T_INFO[nextRotation][2][0];
            break;
    }

    //checks if move is valid
    int xCorrection = 0;
    for (int i = 0; i < 3; i++)
    {
        pointsToCheckX[i] += this->rotationPointX;
        if (pointsToCheckX[i] > 9)
        {
            if (abs(xCorrection) < abs(9 - pointsToCheckX[i])) xCorrection = (9 - pointsToCheckX[i]);
        }
        else if (pointsToCheckX[i] < 0)
        {
            if (abs(xCorrection) < abs(0 - pointsToCheckX[i])) xCorrection = (0 - pointsToCheckX[i]);
        }
    }

    //rotate shape
    bool shapeMoved;
    if (xCorrection == 0) this->tetrisShape.rotate();
    else if (xCorrection > 0)
    {
        for (int i = 0; i < xCorrection; i++)
        {
            shapeMoved = moveShapeRight();
        }
        if (shapeMoved == true) this->tetrisShape.rotate();
    }
    else if (xCorrection < 0)
    {
        for (int i = 0; i > xCorrection; i--)
        {
            shapeMoved = moveShapeLeft();
        }
        if (shapeMoved == true) this->tetrisShape.rotate();
    }
    
    //update the board
    fillBoardWithCurrentInfo();
}
//**********************************************************************************************
void Board::newShapeIfNeeded()
{
    //does piece need to be solidified
    bool solidifyOldShape = false;
    for (int y = 0; y < this->HEIGHT; y++)
    {
        for (int x = 0; x < this->WIDTH; x++)
        {
            if (board[y][x] == 1)
            {
                if (board[y + 1][x] == 2)
                    solidifyOldShape = true;
            }
        }
    }
    
    
    //solidify old shape into board
    if (solidifyOldShape == true)
    {
        for (int y = 0; y < this->HEIGHT; y++)
        {
            for (int x = 0; x < this->WIDTH; x++)
            {
                if (this->board[y][x] == 1)
                    this->board[y][x] = 2;
            }
        }
        
        //resets rotation points and makes tetrisShape update to random shape
        setRotationPointX(4);
        setRotationPointY(2);
        this->tetrisShape.resetShape();
    }
}
//**********************************************************************************************
void Board::clearFilledRows()
{
    //check individual rows to see if they are full of 2s
    int fullRow[WIDTH] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    bool rowsAreEqual;

    //sets full rows of 2 all equal to 0
    for (int y = (HEIGHT - 2); y > 0; y--)
    {
        rowsAreEqual = true;
        while (rowsAreEqual == true)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                if (fullRow[x] != this->board[y][x]) rowsAreEqual = false;
            }
            if (rowsAreEqual == true)
            {
                for (int yN = y; yN > 0; yN--)
                {
                    for (int x = 0; x < WIDTH; x++)
                    {
                        this->board[yN][x] = this->board[yN - 1][x];
                    }
                }
            }
            
        }
    }
}
//**********************************************************************************************
int Board::AccessBoardByXY(int y, int x)
{
    return this->board[y][x];
}












