#include <iostream>
#include <SFML/Graphics.hpp>
int main()
{
	sf::VideoMode vm(1920, 1080);
	sf::RenderWindow window(vm, "Flappy bird");


	while (window.isOpen())
	{
		//매 프레임 초기화

		//이벤트
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				switch (ev.key.code)
				{
				case sf::Keyboard::Escape:
					window.close();
					break;
				default:
					break;
				}
				break;

			default:
				break;
			}
		}


		//업데이트

		window.clear();
		//드로우
		window.display();
	}
	return 0;
}