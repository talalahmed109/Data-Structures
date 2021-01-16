						//M Zaeem Nasir 19F-0355
						//Talal Ahmed	19F-0245	
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<stdlib.h>
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


class graphMatrix
{
private:
	int N;//vertix
	int M;//edgesss
	int** matrix;
public:
	graphMatrix()
	{
		N = 0;
		M = 0;
	}
	void insert(int n)
	{
		N = n;
		matrix = new int* [N];
		for (int i = 0; i < N; i++)
		{
			matrix[i] = new int[N];
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	void distance(int opt, string location)
	{
		if (opt == 1)
		{
			if (location == "ISLAMABAD")
				cout << "\tThe Marquee is in your City\n";
			else if (location == "LAHORE")
				cout << "Distance from your current Location: " << matrix[0][1]<<" Kilometers\n";
			else if(location == "KARACHI")
				cout << "Distance from your current Location: " << matrix[0][2]<<" Kilometers\n";
			else if(location == "MULTAN")
				cout << "Distance from your current Location: " << matrix[0][3]<<" Kilometers\n";
			else if(location=="MURREE")
				cout << "Distance from your current Location: " << matrix[0][4]<<" Kilometers\n";
		}
		else if (opt == 2)
		{
			if (location == "ISLAMABAD")
				cout << "Distance from your current Location: " << matrix[1][0] << " Kilometers\n";
			else if (location == "LAHORE")
				cout << "\tThe Marquee is in your City\n";
			else if (location == "KARACHI")
				cout << "Distance from your current Location: " << matrix[1][2] << " Kilometers\n";
			else if (location == "MULTAN")
				cout << "Distance from your current Location: " << matrix[1][3] << " Kilometers\n";
			else if (location == "MURREE")
				cout << "Distance from your current Location: " << matrix[1][4] << " Kilometers\n";
		}
		else if (opt == 3)
		{
			if (location == "ISLAMABAD")
				cout << "Distance from your current Location: " << matrix[2][0] << " Kilometers\n";
			else if (location == "LAHORE")
				cout << "Distance from your current Location: " << matrix[2][1] << " Kilometers\n";
			else if (location == "KARACHI")
				cout << "\tThe Marquee is in your City\n";
			else if (location == "MULTAN")
				cout << "Distance from your current Location: " << matrix[2][3] << " Kilometers\n";
			else if (location == "MURREE")
				cout << "Distance from your current Location: " << matrix[2][4] << " Kilometers\n";
		}
		else if (opt == 4)
		{
			if (location == "ISLAMABAD")
				cout << "Distance from your current Location: " << matrix[3][0] << " Kilometers\n";
			else if (location == "LAHORE")
				cout << "Distance from your current Location: " << matrix[3][1] << " Kilometers\n";
			else if (location == "KARACHI")
				cout << "Distance from your current Location: " << matrix[3][2] << " Kilometers\n";
			else if (location == "MULTAN")
				cout << "\tThe Marquee is in your City\n";
			else if (location == "MURREE")
				cout << "Distance from your current Location: " << matrix[3][4] << " Kilometers\n";
		}
		else if (opt == 5)
		{
			if (location == "ISLAMABAD")
				cout << "Distance from your current Location: " << matrix[4][0] << " Kilometers\n";
			else if (location == "LAHORE")
				cout << "Distance from your current Location: " << matrix[4][1] << " Kilometers\n";
			else if (location == "KARACHI")
				cout << "Distance from your current Location: " << matrix[4][2] << " Kilometers\n";
			else if (location == "MULTAN")
				cout << "Distance from your current Location: " << matrix[4][3] << " Kilometers\n";
			else if (location == "MURREE")
				cout << "\tThe Marquee is in your City\n";
		}
		else
			cout << "Wrong INPUT" << endl;

	}
	void addEdge(int a, int b, int w)
	{

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= N; j++)
			{
				matrix[a][b] = w;
				matrix[b][a] = w;
			}
		}
	}
};


class readData //reads data from file and stores in LL
{
private:
	node* head, * tail;
	int size;
public:
	readData()
	{
		head = NULL;
		tail = NULL;
		size = 0;
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
		size++;
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
			cout<<"\t\t" << temp->data << "\t\n";
			temp = temp->next;
		}
	}

	void Display_By_Location(string Location)
	{
		system("cls");
		node* temp = new node;
		temp = head;
		graphMatrix G;
		int i = 1;
		string select;
		cout << "\t\tWe Find the Marquees According to Your Location" << endl << endl;
		while (temp != NULL)
		{
			
			if (temp->location == Location)
			{
				cout<<"\t\t"<<i<<"- "<< temp->data << "\t\n";
				i++;
			}
			temp = temp->next;	
		}
		cin.ignore();
		cout << "\t\tEnter name of marquee to select: ";
		getline(cin, select);
		Select(select);
		int opt;
		cout << "\n\n\t\t\tSelect Your current Location: \n";
		cout << "\n\t\t\t1. Islamabad\n"
			"\t\t\t2. Lahore\n"
			"\t\t\t3. Karachi\n"
			"\t\t\t4. Multan\n"
			"\t\t\t5. Murree\n"
			"\t\t\tChoice: ";
		cin >> opt;
		G.insert(5);
		G.addEdge(0, 0, 1);
		G.addEdge(0, 1, 375);
		G.addEdge(0, 2, 1410);
		G.addEdge(0, 3, 537);
		G.addEdge(0, 4, 64);
		G.addEdge(1, 2, 1200);
		G.addEdge(1, 3, 337);
		G.addEdge(1, 4, 438);
		G.addEdge(2, 3, 883);
		G.addEdge(2, 4, 1470);
		G.addEdge(3, 4, 601);
		G.distance(opt,Location);
	}
	void Display_By_Price(int min, int max)
	{
		system("cls");
		node* temp = new node;
		temp = head;
		int i = 1;
		string select;
		cout << "\t\tWe Find the Marquees According to Your Price Range" << endl << endl;
		while (temp != NULL)
		{
			if (temp->price >= min && temp->price <= max)
			{
				cout << "\t\t"<<i<<"- "  << temp->data <<"\tPrice: "<<temp->price<< " per person\n";
			}
			temp = temp->next;
			i++;
		}
		cin.ignore();
		cout << "\t\tEnter name of marquee to select: ";
		getline(cin, select);
		Select(select);
	}
	bool search_byName(string Marquee)
	{
		// Making A Temporary Node (pointing Head Of Linked List)
		node* temp = head;
		// Searching the Speacific

		while (temp != NULL)
		{
			if (temp->data == Marquee)
			{
				cout << "\n\t\t\tMarquee Details: ";
				cout << "\n\t\tName: " << temp->data << "\t Price: " << temp->price<<" per person" << "\t Location: " <<temp->location<<"\tCapacity: "<<temp->Capacity<< endl;
				return 1;
			}
			temp = temp->next;
		}
		return 0;
	}

	void Select(string Marquee)
	{
		int guests = 0, total = 0;
		string loc;
		graphMatrix G;
		node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == Marquee)
			{
				cout << "\n\t\t\tMarquee Details: ";
				cout << "\n\t\tName: " << temp->data << "\t Price: " << temp->price << " per person" << "\t Location: " << temp->location << "\tCapacity: " << temp->Capacity << endl;
				cout << "\t\tEnter the number of guests:  "; cin >> guests;
				total = guests * temp->price;
				cout << "\n\t\tYour Total Bill: " << total;
				return;
			}
			temp = temp->next;
		}
		return;
	}
};

void mainMenu()
{

	readData obj;
	obj.read();
	sf::RenderWindow window(sf::VideoMode(900, 520), "Marquee Recommendation System", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	sf::Font font;
	font.loadFromFile("Pinkerston.ttf");

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
			cout << "\n\t\tChoice from Menu: ";
			cin >> choice;
			if (choice == 1)
			{
				string marqeeName;
				obj.display();
				cin.ignore();
				cout << "\n\t\tEnter the Marqee Name = ";
				getline(cin, marqeeName);
				if(obj.search_byName(marqeeName))
				{
					cout << "\n\t\tMarquee Found" << endl;
				}
				else
					cout << "\n\t\tMarquee Not Found" << endl;
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

		} while (choice != 0);
	}
}

int main()
{
	system("Color 09");
	mainMenu();
	return 0;
}
