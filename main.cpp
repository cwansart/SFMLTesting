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
        std::cout << "key pressed: " << event.key.code << std::endl;
      }
    }

    window.clear();
    window.draw(shape);
    window.display();
  }
  return 0;
}
