#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Let's Play");
    sf::Texture background;
    if (!background.loadFromFile("/home/joseandres216/Escritorio/Jose Andres/TEC/Semestre V/Datos II/Proyecto II - Games/Client/Proyecto_II_Client_CE2103-/content/MenuBackground.png"))
        return EXIT_FAILURE;
    sf::Sprite backgroundSprite(background);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(backgroundSprite);
        window.display();


        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(backgroundSprite);
            window.display();
        }
    }

    return 0;
}