    
    void print::displayGrid(const vector<vector<cell>>& grid) { 

        int gridWidth  = 1000;
        int gridHeight = 1000;
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
                    aliveCell c;
                    if (grid[x][y]==c) {
                        cell.setPosition(x * cellSize, y * cellSize);
                        window.draw(cell);
                    }
                }
            }

            window.display();
        }
}