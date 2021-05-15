#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Let's Play");

    sf::Texture menuBackground;
    if (!menuBackground.loadFromFile("/home/joseandres216/Escritorio/Jose Andres/TEC/Semestre V/Datos II/Proyecto II - Games/Client/Proyecto_II_Client_CE2103-/content/MenuBackground.png"))
        return EXIT_FAILURE;
    sf::Sprite menuBackgroundprite(menuBackground);

    sf::Font font;
    if (!font.loadFromFile("/home/joseandres216/Escritorio/Jose Andres/TEC/Semestre V/Datos II/Proyecto II - Games/Client/Proyecto_II_Client_CE2103-/Fonts/Games/Games-Italic.ttf"))
    {
        window.close();
    }

    sf::Text bpGametext;
    bpGametext.setFont(font);
    bpGametext.setString("Press A to play BP Game");
    bpGametext.setCharacterSize(50);
    bpGametext.setFillColor(sf::Color::Red);
    bpGametext.setOutlineColor(sf::Color::White);
    bpGametext.setOutlineThickness(5);
    bpGametext.setPosition(50, 800);

    sf::Text geneticPuzzletext;
    geneticPuzzletext.setFont(font);
    geneticPuzzletext.setString("Press B to play Genetic Puzzle");
    geneticPuzzletext.setCharacterSize(45);
    geneticPuzzletext.setFillColor(sf::Color::Red);
    geneticPuzzletext.setOutlineColor(sf::Color::White);
    geneticPuzzletext.setOutlineThickness(5);
    geneticPuzzletext.setPosition(825, 800);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::A){

                }
            }
            if(event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::B){

                }
            }
        }
        window.clear();
        window.draw(menuBackgroundprite);
        window.draw(bpGametext);
        window.draw(geneticPuzzletext);
        window.display();
    }

    return 0;
}