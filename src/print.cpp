// print.cpp — remplacement complet de displayGrid pour debug
#include "../headers/print.hpp"
#include "../headers/grid.hpp"
#include <SFML/Graphics.hpp>

print::print(){}

void print::displayGrid(int width, int height, int cellSize, Grid& g)
{

    sf::RenderWindow window(
        sf::VideoMode(width * cellSize, height * cellSize),
        "Game of Life"
    );

    sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        auto& grid = g.getGrid();

        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                if (grid[x][y]->getState()) {
                    cell.setPosition(x * cellSize, y * cellSize);
                    window.draw(cell);
                }
            }
        }

        window.display();

        // On fait évoluer la grille ici
        g.stepGrid();
        sf::sleep(sf::milliseconds(100));
    }
}
