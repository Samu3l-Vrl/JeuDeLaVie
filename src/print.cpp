#include "../headers/print.hpp"
#include "../headers/grid.hpp"

print::print() {}

void print::displayGrid(int width, int height, int cellSize, Grid& g){// Display the grid using SFML
    sf::RenderWindow window(
        sf::VideoMode(width * cellSize, height * cellSize),
        "Game of Life"
    );// Create the window

    sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));// Cell rectangle

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }// Event handling

        window.clear(sf::Color::Black);// Clear the window 

        auto& grid = g.getGrid();// Get the grid

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {

                if (grid[y][x]->getObs() == 2) {
                    cell.setFillColor(sf::Color(150, 150, 150)); // obstacle grey
                }
                else if (grid[y][x]->getState() == true) {
                    cell.setFillColor(sf::Color::White);
                }
                else {
                    continue; // dead -> do not draw
                }

                cell.setPosition(x * cellSize, y * cellSize);// Set position
                window.draw(cell);  // Draw the cell
            }
        }

        window.display();

        g.stepGrid();
        sf::sleep(sf::milliseconds(100));
    }
}
