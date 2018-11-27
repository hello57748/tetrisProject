//**********************************************************************
// Shape.cpp
// Author: Samuel Peters, David Olivares, Christian Ortiz
// Last Modified: 4/26/18
// Description: This is the base class to help create all seven tetris
//              pieces through inheritance.
//**********************************************************************

#include "Shape.hpp"
#include <cassert>
#include <cstdlib>
#include <ctime>

//CONSTRUCTORS
//**********************************************************************************************
Shape::Shape()
{
    //set up random seed
    srand(static_cast<unsigned int>(time(NULL)));
    
    this->currentRotation = 0;
    setRandomShapeType();
}

//Setters
//**********************************************************************************************
void Shape::setCurrentRotation(int currentRotation)
{
    //error checks
    assert(currentRotation >= 0);
    switch (this->shapeType)
    {
        case 'I':
            assert(currentRotation <= 1);
            break;
        case 'L':
            assert(currentRotation <= 3);
            break;
        case 'J':
            assert(currentRotation <= 3);
            break;
        case 'O':
            assert(currentRotation <= 0);
            break;
        case 'Z':
            assert(currentRotation <= 1);
            break;
        case 'S':
            assert(currentRotation <= 1);
            break;
        case 'T':
            assert(currentRotation <= 3);
            break;
    }
    
    this->currentRotation = currentRotation;
}
//**********************************************************************************************
void Shape::setShapeType(char shapeType)
{
    //error checking
    assert(shapeType == 'I' || shapeType == 'L' || shapeType == 'J' || shapeType == 'O' || shapeType == 'Z' || shapeType == 'S' || shapeType == 'T');
    
    this->shapeType = shapeType;
}

//MEMBER FUNCTIONS
//**********************************************************************************************
void Shape::rotate()
{
    //CHANGING CURRENT ROTATION BASED ON AMOUNT OF ROTATIONS
    switch (this->shapeType)
    {
        case 'I':
            if (this->currentRotation == 1) this->currentRotation = 0;
            else this->currentRotation += 1;
            break;
        case 'L':
            if (this->currentRotation == 3) this->currentRotation = 0;
            else this->currentRotation += 1;
            break;
        case 'J':
            if (this->currentRotation == 3) this->currentRotation = 0;
            else this->currentRotation += 1;
            break;
        case 'O':
            if (this->currentRotation == 0) this->currentRotation = 0;
            break;
        case 'Z':
            if (this->currentRotation == 1) this->currentRotation = 0;
            else this->currentRotation += 1;
            break;
        case 'S':
            if (this->currentRotation == 1) this->currentRotation = 0;
            else this->currentRotation += 1;
            break;
        case 'T':
            if (this->currentRotation == 3) this->currentRotation = 0;
            else this->currentRotation += 1;
            break;
    }
}
//**********************************************************************************************
void Shape::resetShape()
{
    //RESETS SHAPE VALUES WHEN SHAPE HITS THE BOTTOM
    setRandomShapeType();
    this->currentRotation = 0;
}
//**********************************************************************************************
void Shape::setRandomShapeType()
{
    //create random number in between 0 and 6
    int randomNum = rand() % 7;
    
    this->shapeType = this->POSSIBLE_SHAPES[randomNum];
}
//**********************************************************************************************
int Shape::findNextRotation()
{
    int nextRotation;
    switch (this->shapeType)
    {
        case 'I':
            if (this->currentRotation == 0) return (currentRotation + 1);
            else return 0;
            break;
        case 'L':
            if (this->currentRotation != 3) return (currentRotation + 1);
            else return 0;
            break;
        case 'J':
            if (this->currentRotation != 3) return (currentRotation + 1);
            else return 0;
            break;
        case 'O':
            return 0;
            break;
        case 'Z':
            if (this->currentRotation != 1) return (currentRotation + 1);
            else return 0;
            break;
        case 'S':
            if (this->currentRotation != 1) return (currentRotation + 1);
            else return 0;
            break;
        case 'T':
            if (this->currentRotation != 3) return (currentRotation + 1);
            else return 0;
            break;
        default:
            return 200;
    }
}
