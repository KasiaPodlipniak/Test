#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
//using namespace sf;
// jeśli program nie chce się odplić - brak plików dll
int main()
{

    bool przycisk_stop = false;

    sf::Text text;
    sf::Font font;
    font.loadFromFile("arial.ttf");//w nazwiasie nazwa pliku w którym jest czcionka

    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString("YOU WIN");

    // set the character size
    text.setCharacterSize(72); // in pixels, not points!

    text.setOrigin(text.getGlobalBounds().width/2,text.getGlobalBounds().height/2);
    text.setPosition(400, 300);

//to poniżej nie jest potrzebne:
//    // set the color
//    text.setFillColor(sf::Color::Green);

//    // set the text style
//    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::Sprite zdjecie; //to na czym wyświelam zdjęcie
    sf::Texture tekstura; //zdjęcie
    tekstura.loadFromFile("teksturadoQT_2.jpg");
    zdjecie.setTexture(tekstura);
    //zdjecie.setScale(800, 10);


    //**********ROTACJA************

    // 'entity' can be a sf::Sprite, a sf::Text, a sf::Shape or any other transformable class
    sf::Text entity;
    // select the font
    entity.setFont(font); // font is a sf::Font
    // set the string to display
    entity.setString("TEST");
    // set the character size
    entity.setCharacterSize(72); // in pixels, not points!
    entity.setOrigin(text.getGlobalBounds().width/2,text.getGlobalBounds().height/2);
    entity.setPosition(200, 200);

    // set the absolute rotation of the entity
    entity.setRotation(45.f);

    // rotate the entity relatively to its current orientation
    entity.rotate(10.f);

    // retrieve the absolute rotation of the entity
    float rotation = entity.getRotation(); // = 55

    //***********************

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");//rozmiar ekranu - poszukaj takiego zdjecia lub 800 na szerokosc zdjecia i 600 dlugosc
    sf::RectangleShape kwadrat;
    kwadrat.setSize({300, 50});
    kwadrat.setPosition(400, 100);
    kwadrat.setFillColor(sf::Color::Cyan);

    sf::RectangleShape ramka_jeden;
    ramka_jeden.setSize({800, 10});
    ramka_jeden.setPosition(10, 10);
    ramka_jeden.setFillColor(sf::Color::Green);

    sf::RectangleShape ramka_dwa;
    ramka_dwa.setSize({800, 10});
    ramka_dwa.setPosition(10, 590);
    ramka_dwa.setFillColor(sf::Color::Green);

    sf::RectangleShape ramka_trzy;
    ramka_trzy.setSize({10, 590});
    ramka_trzy.setPosition(10, 10);
    ramka_trzy.setFillColor(sf::Color::Yellow);

    sf::RectangleShape ramka_trzy_dwa;
    ramka_trzy_dwa.setSize({10, 40});
    ramka_trzy_dwa.setPosition(10, 280);
    ramka_trzy_dwa.setFillColor(sf::Color::Black);

    sf::RectangleShape ramka_cztery;
    ramka_cztery.setSize({10, 590});
    ramka_cztery.setPosition(790, 10);
    ramka_cztery.setFillColor(sf::Color::Yellow);

    sf::RectangleShape ramka_cztery_dwa;
    ramka_cztery_dwa.setSize({10, 40});
    ramka_cztery_dwa.setPosition(790, 280);
    ramka_cztery_dwa.setFillColor(sf::Color::Black);

    sf::CircleShape punkt_jeden;
    punkt_jeden.setRadius(20);
    punkt_jeden.setPosition(90, 280);
    punkt_jeden.setFillColor(sf::Color::White);

    sf::CircleShape punkt_dwa;
    punkt_dwa.setRadius(10);
    punkt_dwa.setPosition(400, 290);
    punkt_dwa.setFillColor(sf::Color::Cyan);

    sf::CircleShape kolo;
    kolo.setRadius(40);
    kolo.setPosition(100,100);
    kolo.setFillColor(sf::Color::Green);

    sf::CircleShape kolo_dwa;
    kolo_dwa.setRadius(20);
    kolo_dwa.setPosition(20,50);
    kolo_dwa.setFillColor(sf::Color::White);

    sf::RectangleShape kwadrat_win;
    kwadrat_win.setSize({150, 150});
    kwadrat_win.setPosition(325, 225);
    kwadrat_win.setFillColor(sf::Color::Green);

   // sf::VertexArray triangle;
   // triangle.append() dodanie punktów

    window.setFramerateLimit(60);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && kwadrat.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            {
                kolo_dwa.setFillColor(sf::Color::Magenta);
                kolo_dwa.move(50, 0);
            }

            if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && przycisk_stop == false)
            {
                przycisk_stop = true;
            }
            else if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && przycisk_stop == true)
            {
                przycisk_stop = false;
            }

//            if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
//            {
//                kolo.move(0,5);
//            }
//            else if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
//            {
//                kolo.move(0,-5);
//            }
        }

//**********ruch jednostajny**********
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            kolo.move(0,5);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            kolo.move(0,-5);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            kolo.move(-5,0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            kolo.move(5,0);
        }
//********************

        if (punkt_jeden.getPosition().x > 800)
        {
            punkt_jeden.setPosition(0, punkt_jeden.getPosition().y);
        }


        //kolo.move(1,0);

        if (przycisk_stop == false)
        {
            punkt_jeden.move(4,0);
        }



       /* if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
           kolo_dwa.setFillColor(sf::Color::Magenta);
           kolo_dwa.move(50, 0);
        }
       */

        //cout << sf::Mouse::getPosition(window).x << endl;
        //cout << sf::Mouse::isButtonPressed(sf::Mouse::Left) << endl;

//        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//        {
//            kolo_dwa.setFillColor(sf::Color::Magenta);
//            kolo_dwa.move(50, 0);
//        }

        // clear the window with black color
        window.clear(sf::Color::Black);//zresetowanie klatki

        // draw everything here...
        // window.draw(...);

        window.draw(zdjecie);
        //window.draw(kwadrat_win);

        window.draw(kwadrat);
        window.draw(kolo);
        window.draw(kolo_dwa);



        window.draw(ramka_jeden);
        window.draw(ramka_dwa);
        window.draw(ramka_trzy);
        window.draw(ramka_trzy_dwa);
        window.draw(ramka_cztery);
        window.draw(ramka_cztery_dwa);

        window.draw(punkt_jeden);
        window.draw(punkt_dwa);

        window.draw(entity);

        if (przycisk_stop == true)
        {
            if (punkt_jeden.getGlobalBounds().intersects(punkt_dwa.getGlobalBounds()))//pole obiektu
            {
                text.setString("Wygrales");
            }
            else
            {
                text.setString("Przegrales");
            }
            window.draw(text);
        }

        // end the current frame
        window.display();

    }

    return 0;
}

//lewo/prawo i oba naciśnie - stoi w miejscu, naprzemienne guziki mają się niwelować
