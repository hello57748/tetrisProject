//**********************************************************************
// Shape.hpp
// Author: Samuel Peters, David Olivares, Christian Ortiz
// Last Modified: 4/26/18
// Description: This is the base class to help create all seven tetris
//              pieces through inheritance.
//**********************************************************************

#ifndef Shape_hpp
#define Shape_hpp

#include <ctime>
#include <stdio.h>

class Shape
{
protected:
    //CURRENT ROTATION OF SHAPE
    int currentRotation;
    
    //POSSIBLE SHAPES THAT THE TETRIS BOARD CAN TAKE
    const char POSSIBLE_SHAPES[7] = {'I', 'L', 'J', 'O', 'Z', 'S', 'T'};
    char shapeType;
public:
    //CONSTRUCTORS
    //**********************************************************************************************
    Shape();
    // Summary: This constructor creates an object of type Shape.
    // Preconditions:
    // PostConditions:
    //**********************************************************************************************
    
    //GETTERS
    //**********************************************************************************************
    int getCurrentRotation()const {return currentRotation;}
    // Summary: This returns the current rotation of the shape that is being called.
    // Preconditions:
    // PostConditions: 0-3 is returned depending on what type of shape and rotation.
    //**********************************************************************************************
    char getShapeType()const {return shapeType;}
    // Summary: This returns the current shape type of a Shape object ('I', 'L', 'J', 'O', 'Z', 'S', or 'T').
    // Preconditions:
    // PostConditions: 'I', 'L', 'J', 'O', 'Z', 'S', or 'T' is returned depending on the current shape type.
    //**********************************************************************************************
    
    //SETTERS
    //**********************************************************************************************
    void setCurrentRotation(int currentRotation);
    // Summary:
    // Preconditions:
    // PostConditions:
    //**********************************************************************************************
    void setShapeType(char shapeType);
    // Summary: This sets the current shape type to ('I', 'L', 'J', 'O', 'Z', 'S', or 'T').
    // Preconditions:
    // PostConditions: this->shapeType is set equal to 'I', 'L', 'J', 'O', 'Z', 'S', or 'T'.
    //**********************************************************************************************
    
    
    //MEMBER FUNCTIONS
    //**********************************************************************************************
    void rotate();
    // Summary: This function changes a shape's rotation to the next one in a clockwise style.
    // Preconditions:
    // PostConditions: this->currentRotation is set equal to its next rotation.
    //**********************************************************************************************
    void resetShape();
    // Summary: This selects a random shape and resets its attributes.
    // Preconditions:
    // PostConditions: this->shapeType is set to a random number and this->currentRotation is set equal to 0.
    //**********************************************************************************************
    void setRandomShapeType();
    // Summary: This selects a random shape and resets its attributes.
    // Preconditions:
    // PostConditions: this->shapeType is set to a random number and this->currentRotation is set equal to 0.
    //**********************************************************************************************
    int findNextRotation();
    // Summary: This returns the next rotation of the shape that is being called.
    // Preconditions:
    // PostConditions: 0-3 is returned depending on what type of shape and rotation.
    //**********************************************************************************************
    
    
};
#endif /* Shape_hpp */
