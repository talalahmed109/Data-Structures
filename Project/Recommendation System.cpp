#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>

using namespace std;


// Making Node OF MArquee

struct node
{

	/*
	Discount

	
	*/
	string data;
	int price;
	string location;
	int Capacity;
	node* next;

	node()
	{
		data = " ";
		next = NULL;
		price = 0;
		location = "";
		Capacity = 0;
	}

};



class readData //reads data from file and stores in LL
{
private:
	node* head, *tail;
public:
	readData()
	{
		head = NULL;
		tail = NULL;
	}
	void insert(string name, int price, string Location, int Capacity)
	{
		node* temp = new node;

		temp->data = name;
		temp->price = price;
		temp->location = Location;
		temp->Capacity = Capacity;
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

	// Reading the Data From the FILE
	void read()
	{
		ifstream myfile;
		string name;
		int price;
		string location;
		int capacity;

		myfile.open("Marquee.txt");
		if (!myfile)
		{
			cout << "Unable to Open the File " << endl;
		}
		while (!myfile.eof())
		{
			getline(myfile, name);
			getline(myfile, location);
			myfile >> price;
			myfile >> capacity;
			insert(name, price, location, capacity);
			myfile.ignore();
		}
		myfile.close();
	}

	// Displaying Whole Linked List 
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

	void Display_By_Location(string Location)
	{
		node* temp = new node;
		temp = head;
		cout << "\t\tWe Find the Marquees According to Your Location" << endl << endl;
		while (temp != NULL)
		{
			if (temp->location == Location)
			{
				cout << temp->data << "\t\n";
			}
			temp = temp->next;
		}
	}

	void Display_By_Price(int min, int max)
	{
		node* temp = new node;
		temp = head;
		cout << "\t\tWe Find the Marquees According to Your Price Range" << endl << endl;
		while (temp != NULL)
		{
			if (temp->price >= min && temp->price <= max  )
			{
				cout << temp->data << "\t\n";
			}
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
				cout << "\t\tMarquee Found\n\t\tName: " << temp->data <<endl<< "\t\t Price: " << temp->price << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "\n\t\tMarquee Not Found" << endl;
		return;
	}
};



void mainMenu()
{

	readData obj;
	obj.read();
	sf::RenderWindow window(sf::VideoMode(1020, 720), "Marquee Recommendation System", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	sf::Font font;
	font.loadFromFile("Pinkerston.ttf");
	//throw("Could not load Font\n");

	sf::Texture Tex;
	Tex.loadFromFile("E:\Mutton.jpg");	
	sf::Sprite sprite(Tex);
		
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(35);
	text.setFillColor(sf::Color::White);
	text.setString("\t\t\t\t\tMARQUEE RECOMMENDATION SYSTEM\n\n");
	text.setPosition(105, 25);

	sf::Text text1;
	text1.setFont(font);
	text1.setCharacterSize(35);
	text1.setFillColor(sf::Color::Cyan);
	text1.setString("1- Search Marquee by Name\n\n2- Search by Location\n\n3- Search by Price Range\n\n4- Show All Murquees\n\n0- TO EXIT");
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

		do
		{
			cout << "\n\t\tChoice: ";
			cin >> choice;
			if (choice == 1)
			{
				string marqeeName;
				obj.display();
				cin.ignore();
				cout << "\n\t\tEnter the Marqee Name = ";
				getline(cin, marqeeName);
				obj.search_byName(marqeeName);
			}
			else if (choice == 2)
			{
				int opt;
				cout << "\n\n\t\t\tSelect city: \n";
				cout << "\n\t\t\t1. Islamabad\n"
					"\t\t\t2. Lahore\n"
					"\t\t\t3. Karachi\n"
					"\t\t\t4. Multan\n"
					"\t\t\t5. Murree\n"
					"\t\t\tChoice: ";
				cin >> opt;
				if (opt == 1)
					obj.Display_By_Location("ISLAMABAD");
				else if (opt == 2)
					obj.Display_By_Location("LAHORE");
				else if (opt == 3)
					obj.Display_By_Location("KARACHI");
				else if (opt == 4)
					obj.Display_By_Location("MULTAN");
				else if (opt == 5)
					obj.Display_By_Location("MURREE");
				else
					cout << "Wrong INPUT" << endl;
			}
			else if (choice == 3)
			{
				int minPrice;
				int maxPrice;
				cout << "Enter Minimum Price = ";
				cin >> minPrice;
				cout << "Enter Maximum Price = ";
				cin >> maxPrice;
				obj.Display_By_Price(minPrice, maxPrice);
			}
			else if (choice == 4)
			{
				cout << "\n\n\t\t All Marquees Are \n\n";
				obj.display();
			}
			else if (choice == 0)
				exit(0);

		}while (choice != 0);
	}
}

int main()
{
	mainMenu();
	return 0;
}
