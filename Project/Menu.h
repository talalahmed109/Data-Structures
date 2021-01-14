#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
using namespace std;

void mainMenu();

struct node
{
	string data;
	node* next;
	node();
};

class readData //reads data from file and stores in LL
{
private:
	node* head, *tail;
public:
	readData();
	void insert(string name);
	void read();
	void display();
	void search_byName(string Marqee);
};
