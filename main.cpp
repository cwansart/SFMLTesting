#include <SFML/Graphics.hpp>
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
        std::cout << "key pressed: ";
        if (event.key.code == sf::Keyboard::Left) {
          std::cout << "left";
          shape.move(-5.0f, 0.0f);
        }

        if (event.key.code == sf::Keyboard::Right) {
          std::cout << "right";
          shape.move(5.0f, 0.0f);
        }

        if (event.key.code == sf::Keyboard::Up) {
          std::cout << "up";
          shape.move(0.0f, -5.0f);
        }

        if (event.key.code == sf::Keyboard::Down) {
          std::cout << "down";
          shape.move(0.0f, 5.0f);
        }

        if(event.key.code == sf::Keyboard::Escape) {
          window.close();
        }

        std::cout << std::endl;
      }
    }

    window.clear();
    window.draw(shape);
    window.display();
  }
  return 0;
}
