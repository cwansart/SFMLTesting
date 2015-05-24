#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

int main(int argc, char const *argv[]) {
  sf::RenderWindow window(sf::VideoMode(800,600), "SFML App");

  sf::CircleShape shape;

  shape.setRadius(20.0f);
  shape.setPosition(100.0f, 100.0f);
  shape.setFillColor(sf::Color::Blue);

  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed) {
        window.close();
      }

      if(event.type == sf::Event::KeyPressed) {
        sf::Vector2f movement;
        std::cout << "key pressed: ";

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
          std::cout << "left";
          movement.x -= 5.f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
          std::cout << "right";
          movement.x += 5.f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
          std::cout << "up";
          movement.y -= 5.f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
          std::cout << "down";
          movement.y += 5.f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
          window.close();
        }

        std::cout << std::endl;
        shape.move(movement);
      }
    }

    window.clear();
    window.draw(shape);
    window.display();
  }
  return 0;
}
