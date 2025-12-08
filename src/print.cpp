#include "../headers/print.hpp"
#include "../headers/grid.hpp"
#include <SFML/Graphics.hpp>

print::print(){}

void print::displayGrid(int width, int height, int cellSize, Grid& g)
{

    sf::RenderWindow window(
        sf::VideoMode(width * cellSize, height * cellSize),
        "Game of Life"
    );// Create the main window 

    sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));// Create a square shape for cells
    cell.setFillColor(sf::Color::White);// Set cell color

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }// keep open until the window is closed

        window.clear(sf::Color::Black);// Clear the window with black color

        auto& grid = g.getGrid();// Get the grid from the Grid object

        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                if (grid[x][y]->getState()) {// If the cell is alive
                    cell.setPosition(x * cellSize, y * cellSize);// Set cell position
                    window.draw(cell);// Draw alive cells
                }
            }
        }

        window.display();// Display the contents of the window

        g.stepGrid();// Update the grid to the next generation
        sf::sleep(sf::milliseconds(1000));// Pause for a short duration to control the speed of the simulation
    }
}
