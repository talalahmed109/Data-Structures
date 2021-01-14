#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>

using namespace std;


struct node
{
	string data;
	int cost;
	node* next;
	node()
	{
		data = " ";
		next = NULL;
		cost = 0;
	}

};

class readData //reads data from file and stores in LL
{
private:
	node* head, * tail;
public:
	readData()
	{
		head = NULL;
		tail = NULL;
	}
	void insert(string name,int price)
	{
		node* temp = new node;

		temp->data = name;
		temp->cost = price;
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

	void read()
	{
		ifstream myfile;
		myfile.open("data.txt");
		if (!myfile)
		{
			cout << "Unable to open file";
		}
		string name;
		int price;
		while(!myfile.eof())
		{
			getline(myfile,name);
			while (name == "")
			{
				getline(myfile, name);
			}

			myfile >> price;
			
			insert(name,price);
		}
	}
	void display()
	{
		node* temp = new node;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "\t\n";
			temp = temp->next;
		}
	}
	void search_byName(string Marquee)
	{

		// Making A Temporary Node (pointing Head Of Linked List)
		node* temp = head;
		// Searching the Speacific 
		while (temp != NULL)
		{
			if (temp->data == Marquee)
			{
				cout << "Marquee Found\nName: " << temp->data << " Price: "<<temp->cost << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "Marquee Not Found" << endl;
		return;
	}
};



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
		while (1)
		{
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
			else if (choice == 2)
			{
				cout << "\t\tUnder Development\n";
			}
			else if (choice == 3)
			{
				cout << "\t\tUnder Development\n";
			}
			else if (choice == 0)
			{
				exit(0);
			}
		}
	}
}

int main()
{
	
	mainMenu();
	
	return 0;
}




