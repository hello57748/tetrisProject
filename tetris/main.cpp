//**********************************************************************
// main.cpp
// Author: Samuel Peters, David Olivares, Christian Ortiz
// Last Modified: 4/26/18
// Description: This is the main file to run the sfml display.
//**********************************************************************
#include "Board.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

int main(int, char const**)
{
    //starting timer
    time_t start = time(0);
    double seconds_since_start = difftime( time(0), start);
    //create tetris board
    Board newBoard;
    int boardSizePixelMultiple = 50;
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(( newBoard.getBoardWidth() * boardSizePixelMultiple ), ( (newBoard.getBoardHeight() - 4) * boardSizePixelMultiple)), "Tetris");
    
    //create booleans for keyboard presses
    
    
    //create all tiles
    sf::Texture blackTile;
    blackTile.loadFromFile("/Users/hello57748/Desktop/computer_science_stuff/css2a/tetris/images/black.jpg");
    sf::Texture redTile;
    redTile.loadFromFile("/Users/hello57748/Desktop/computer_science_stuff/css2a/tetris/images/red.jpg");

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            //down key pressed
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
            {
                newBoard.moveShapeDown();
            }
            
            //left key pressed
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
            {
                newBoard.moveShapeLeft();
            }
            
            //right key pressed
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
            {
                newBoard.moveShapeRight();
            }
            
            //up key pressed
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
            {
                newBoard.rotateShape();
            }
        }
        
        //check time to move shape down
        if ((seconds_since_start + 1) < difftime( time(0), start))
        {
            seconds_since_start++;
            newBoard.moveShapeDown();
        }
        
        //clear rows that are complete
        newBoard.clearFilledRows();
        
        //check if pieces need to be solidified
        newBoard.newShapeIfNeeded();
        
        // Clear screen
        window.clear();
        
        //Set and draw Sprites
        sf::Sprite redTileSprites[ ( newBoard.getBoardHeight() ) ][newBoard.getBoardWidth()];
        sf::Sprite blackTileSprites[ ( newBoard.getBoardHeight() ) ][newBoard.getBoardWidth()];
        for (int y = 0; y < ( newBoard.getBoardHeight() - 1 ); y++)
        {
            for (int x = 0; x < newBoard.getBoardWidth(); x++)
            {
                redTileSprites[y][x].setTexture(redTile);
                redTileSprites[y][x].setPosition(sf::Vector2f( (x*boardSizePixelMultiple), (y*boardSizePixelMultiple) ));
                blackTileSprites[y][x].setTexture(blackTile);
                blackTileSprites[y][x].setPosition(sf::Vector2f( (x*boardSizePixelMultiple), (y*boardSizePixelMultiple) ));
                if (newBoard.AccessBoardByXY(y+3, x) == 0)
                    window.draw(blackTileSprites[y][x]);
                else
                    window.draw(redTileSprites[y][x]);
            }
        }

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}

