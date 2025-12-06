#include "../headers/print.hpp"
#include "../headers/alivecell.hpp"


print::print(){}
    void print::displayGrid(int width, int height,const std::vector<std::vector<Cell*>>& grid) { 

        int gridWidth  = width;
        int gridHeight = height;
        const int cellSize = 5;

        sf::RenderWindow window(
            sf::VideoMode(gridWidth , gridHeight),
            "Game of Life"
        );

        window.setVerticalSyncEnabled(false);

        sf::RectangleShape cell(sf::Vector2f(cellSize - 1.f, cellSize - 1.f));

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();

            for (int x = 0; x < gridWidth; ++x) {
                for (int y = 0; y < gridHeight; ++y) {
                    if (grid[x][y]->getState()==true) {
                        cell.setPosition(x * cellSize, y * cellSize);
                        window.draw(cell);
                    }
                }
            }
            sf::sleep(sf::milliseconds(100));
            window.display();
        }
}