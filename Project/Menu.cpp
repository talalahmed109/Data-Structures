//Main menu
#include"Menu.h"
#include<string>
#include<iomanip>

void mainMenu()
{
	sf::RenderWindow window(sf::VideoMode(750, 512), "Marquee Recommendation System", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	sf::Font font;
	font.loadFromFile("Pinkerston.ttf");
	//throw("Could not load Font\n");

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(35);
	text.setFillColor(sf::Color::White);
	text.setString("MARQUEE RECOMMENDATION SYSTEM\n");
	text.setPosition(105, 25);

	sf::Text text1;
	text1.setFont(font);
	text1.setCharacterSize(35);
	text1.setFillColor(sf::Color::Cyan);
	text1.setString("1- Search Marquee by Name\n\n2- Search by Location\n\n3- Search by Price Range\n");
	text1.setPosition(125, 100);

	while (window.isOpen())
	{

		window.clear(sf::Color::Black);
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
			{
				window.close();
			}
		}
		window.draw(text);
		window.draw(text1);
		window.display();
		int choice;
		readData obj;
		cout << "\n\t\tChoice: ";
		cin >> choice;
		if (choice == 1)
		{
			string marqeeName;
			obj.read();
			obj.display();
			cin.ignore();
			cout << "Enter the Marqee Name = ";
			getline(cin, marqeeName);
			obj.search_byName(marqeeName);
		}
	}
}

//void input()
//{
//    int opt;
//    std::cin >> opt;
//    std::stringstream ss;
//    ss << opt;
//
//    std::string choice = ss.str();
//
//    sf::Text input;
//    input.setFont(font);
//    input.setCharacterSize(35);
//    input.setFillColor(sf::Color::Cyan);
//    input.setPosition(205, 55);
//    input.setString(choice);
//
//    window.draw(input);
//    window.display();
//}
node::node()
{
	data = " ";
	next = NULL;
}

readData::readData()
{
	head = NULL;
	tail = NULL;
}
void readData::insert(string name)
{
	node* temp = new node;

	temp->data = name;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

void readData::read()
{
	ifstream myfile("data.txt");
	if (!myfile.is_open())
	{
		std::cout << "Unable to open file";
	}
	string line = "";
	while (getline(myfile, line))
	{
		insert(line);
	}
}
void readData::display()
{
	node* temp = new node;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "\t\n";
		temp = temp->next;
	}
}
void readData::search_byName(string Marquee)
{

	// Making A Temporary Node (pointing Head Of Linked List)
	node* temp = head;
	// Searching the Speacific 
	while (temp != NULL)
	{
		if (temp->data == Marquee)
		{
			cout << "Marquee Found" << endl;
			return;
		}
		temp = temp->next;
	}
	cout << "Marquee Not Found" << endl;
	return;
}
