#include <iostream>
#include <limits>
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::seconds


using namespace std;

void pauseGame()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}

void validateChoice(int& i)
{
	while (!(std::cin >> i) || i < 1 || i > 4)
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Invalid choice. Please enter 1 through 4: \n";
	}
}

void validateAcceptJob(int& j)
{
	while (!(std::cin >> j) || j < 1 || j > 2)
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Invalid choice. Please enter 1 through 2: \n";
	}
}

void clearScreen()
{
	system("cls");
}

void mainTitle()
{
	std::cout << "-----------------------\n";
	std::cout << " Night City Adventures \n";
	std::cout << "-----------------------\n";
}

void mainMenu(int& choice)
{
	std::cout << "-----------------------\n";
	std::cout << " Welcome to Night City \n";
	std::cout << "-----------------------\n";
	std::cout << "1. New Game\n";
	std::cout << "2. Load Game\n";
	std::cout << "3. Credits\n";
	std::cout << "4. Exit\n";

	validateChoice(choice);
}

void nightCityIntro()
{
	cout << "GOOD MORNING NIGHT CITY!!!!\n\n"
		 << "Night City never sleeps.\n\n"
		 << "Neon signs flicker overhead.\n"
		 << "A siren wails somewhere in the distance.\n"
		 << "Rain taps against cracked concrete.\n\n"
		 << "Just another night in Watson.\n\n";		
}

void streetKidIntro(const string name)
{
	nightCityIntro();
	pauseGame();
	clearScreen();
	cout << "You're a Street Kid.\n"
		 << "Going by the name " << name << endl << endl;
    cout << "No corporate connections.\n"
		 << "No fancy implants.\n"
		 << "No reputation.\n\n"
		 << "Just another face trying to survive in Night City.\n\n"
		 << "Eddies have been hard to come by lately.\n"
		 << "The last few jobs barely paid enough to cover rent.\n"
		 << "You need work.\n\n";
}

void incomingCall()
{
	cout << "Your holo suddenly buzzes.\n\n"
		 << "UNKNOWN CONTACT\n\n"
		 << "Incoming Message...\n\n";		
}

void fixerIntro(const string name)
{
	cout << "MESSAGE RECEIVED\n\n"
		 << "To: " << name << endl << endl
		 << "Heard you're looking for work.\n\n"
		 << "Got a simple pickup job.\n"
		 << "Easy eddies.\n\n"
		 << "Meet me at Lizzie's Bar if you're interested.\n\n"
		 << "- Regina Jones - \n\n";
}

int main()
{
	int choice = 0;
	string name;
	int acceptJob = 0;

	mainTitle();
	pauseGame();
	clearScreen();
	mainMenu(choice);
	clearScreen();

	switch (choice)
	{
	case 1:
		
		cout << "Enter your charactor's name\n";
		cin >> name;
		clearScreen();
		streetKidIntro(name);
		pauseGame();
		clearScreen();
		incomingCall();
		pauseGame();
		clearScreen();
		fixerIntro(name);
		cout << "1. Meet Regina\n"
			 << "2. Ignore the call\n";
		//cin >> acceptJob;
		validateAcceptJob(acceptJob);
		clearScreen();
		if (acceptJob == 1)
		{
			cout << "You throw on your jacket and head toward Lizzie's.\n\n"
				 << "The neon glow of Watson reflects off the wet pavement.\n\n"
				 << "Time to find out what Regina wants.\n\n";
			pauseGame();
			clearScreen();
		}
		else
		{
			cout << "You ignore the message.\n\n"
				 << "Regina's offer disappears from your holo.\n\n"
				 << "Fixers remember which mercs answer the call.\n"
				 << "And which ones don't.\n\n"
				 << "The rent still needs paying.\n"
				 << "The eddies still aren't there.\n\n";
			
			//firstGig();

			pauseGame();
			clearScreen();
			std::this_thread::sleep_for(std::chrono::seconds(2));
			
			cout << "-----------\n"
			     << " GAME OVER \n"
				 << "-----------\n";
		}
	}


	return 0;
}