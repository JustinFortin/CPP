//DISABLE AUDIO FOR PLEASANT EXPERIENCE ****
//******************************************
//******************************************
#include <nana/gui.hpp>
#include <nana/gui/timer.hpp>
#include <nana/gui/widgets/picture.hpp>
#include <nana/audio/player.hpp>
#include <nana/threads/pool.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/system/platform.hpp>
#include <string>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <fstream>
//Clicked method to display which card was flipped to the console
void clicked(int a) {
	std::cout << "\nI flipped card # : " << a << std::endl;
}

namespace FinalProject {
	using namespace nana;
	//Paint all the image fronts, and the back to add to the vector later
	class Image {
	public:
		paint::image cardBack = paint::image("backs.bmp");
		paint::image cardFront1 = paint::image("red.bmp");
		paint::image cardFront2 = paint::image("blue.bmp");
		paint::image cardFront3 = paint::image("black.bmp");
		paint::image cardFront4 = paint::image("gray.bmp");
		paint::image cardFront5 = paint::image("green.bmp");
		paint::image cardFront6 = paint::image("orange.bmp");
		paint::image cardFront7 = paint::image("pink.bmp");
		paint::image cardFront8 = paint::image("purple.bmp");
		paint::image cardFront9 = paint::image("white.bmp");
		paint::image cardFront10 = paint::image("yellow.bmp");
	};
	class Game {
	public:
		static void cardGame() {
			int prev, curr, flipped = 0, active = 20, turns = 0;
			//yeet for matching, yoink for not matching, beep for clicking a card, and a scream when you finish
			//The sounds make is a long game so disabling for a faster experience might be needed
			audio::player yeet("yeet.wav");
			audio::player yoink("yoink.wav");
			audio::player beep("beep.wav");
			audio::player scream("scream.wav");
			//1 thread
			threads::pool pool(1);

			//aplication window
			form fm{ API::make_center(850,550) };
			fm.caption("Justin C++ Final project");
			place fmPlace(fm);
			//Grid for the placement 
			fmPlace.div("<Mycard grid=[5, 4] margin=[5,110,5,110] gap=20>");

			//restart window
			form restartFm{ API::make_center(300,75) };
			restartFm.caption("Restart or Quit");
			place restartFmPlace(restartFm);
			restartFmPlace.div("<restart><quit>");
			button restart{ restartFm, "Restart" };
			button quit{ restartFm, "Quit" };
			restartFmPlace["restart"] << restart;
			restartFmPlace["quit"] << quit;
			//CLicked event to exit everything, and restart a new cardGame
			restart.events().click([&] {
				API::exit_all();
				Game::cardGame();
				});
			//Clicked event to close everything and quit.
			quit.events().click([&] {
				API::exit_all();
				});

			//enter name window
			form nameFm{ API::make_center(300,75) };
			nameFm.caption("Enter name");
			place nameFmPlace(nameFm);
			nameFmPlace.div("vert<info><name><submit>");
			label info{ nameFm, "..." };
			textbox nameBox{ nameFm, "Name" };
			button submit{ nameFm, "Submit" };
			nameFmPlace["info"] << info;
			nameFmPlace["name"] << nameBox;
			nameFmPlace["submit"] << submit;

			submit.events().click([&] {
				std::ofstream out;
				out.open("highscores.txt", std::ios_base::app);//just sends to file no matter what, no top 5 high scores
				out << (nameBox.text() + " " + std::to_string(turns) + "\n");

				nameFm.close();
				restartFmPlace.collocate();
				restartFm.show();
			});

			fm.events().destroy([&] {
				nameFm.close();
				restartFm.close();
				});

			//Vector of image pointers
			Image images;
			std::vector<paint::image*> fronts{ &images.cardFront1, &images.cardFront1  ,
											   &images.cardFront2, &images.cardFront2  ,
											   &images.cardFront3, &images.cardFront3  ,
											   &images.cardFront4, &images.cardFront4  ,
											   &images.cardFront5, &images.cardFront5  , 
											   &images.cardFront6, &images.cardFront6  , 
											   &images.cardFront7, &images.cardFront7  , 
											   &images.cardFront8, &images.cardFront8  ,
											   &images.cardFront9, &images.cardFront9  ,
											   &images.cardFront10,&images.cardFront10 
											 };
			//Ensures a random shuffle everytime 
			std::srand((unsigned int)(std::time(0)));
			std::random_shuffle(fronts.begin(), fronts.end());

			std::map<char, button*> cards;
			std::list<button> buttons;

			//iterate over all 20 cards
			for (int i = 0; i < 20; i++) {
				buttons.emplace_front((fm).handle());
				auto& cardButton = buttons.front();
				cards[i] = &cardButton;

				//assign icon the image back of the card
				cardButton.icon(images.cardBack);

				//place layout so cards appear as 5,4
				fmPlace["Mycard"] << cardButton;

				//Button clicked 
				cardButton.events().click(pool_push(pool, [&, i]() {
					cardButton.icon(*fronts[i]);
					clicked(i);

					if (i == curr) return;

					prev = curr;
					curr = i;
					//Setting front of card, playing the sound and incrementing flipped so we know that card is flipped
					cardButton.icon(*fronts[i]);
					flipped++;
					beep.play();
					if (!(curr > 19 || curr < 0 || prev > 19 || prev < 0) && flipped == 2) {
						//If the fronts match, hide the cards and decrement the active cards by 2
						if (fronts[prev] == fronts[curr]) {
							std::cout << "Matching";
							cards[prev]->hide();
							cards[curr]->hide();
							active -= 2;
							yeet.play();
						}
						//If the cards dont match, pause for a second since the sound makes it roughly 3 seconds total
						else {
							std::cout << "Not matching";

							nana::system::sleep(1000);
							cards[prev]->icon(images.cardBack);
							cards[curr]->icon(images.cardBack);
							yoink.play();
						}
						//Adds a turn to total and resets flipped 
						turns++;
						flipped = 0;
					}
					//Once Active cards reaches 0 or less, User gets prompted to enter their name, and displays the amount  of turns to the console,
					//then saves the score into a text file
					if (active <= 0) {
						scream.play();
						std::cout << "Game over!";
						info.caption("Turns: " + std::to_string(turns) + "\n");
						std::cout << "That took "<< std::to_string(turns) << "turns" << std::endl;
						nameFmPlace.collocate();
						nameFm.show();
						
					}
					}));
			}

			fmPlace.collocate();
			fm.show();
			exec();
		}
	};
};
//Call to cardGame 
int main() {
	FinalProject::Game::cardGame();
}