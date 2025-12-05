#include "../headers/file.hpp"

int main() {
    file f;

    std::vector<std::vector<int>> grid;
    f.readFile("fichier.txt", grid);

    int gridWidth  = 100;
    int gridHeight = 100;
    const int cellSize = 10;

    sf::RenderWindow window(
        sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize),
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
                if (grid[x][y] == 1) {
                    cell.setPosition(x * cellSize, y * cellSize);
                    window.draw(cell);
                }
            }
        }

        window.display();
    }

    return 0;
}
