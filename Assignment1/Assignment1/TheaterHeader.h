#pragma onc#pragma once
/*Name: Vladimir Tretyakov
Student ID : 20082073
Date : 10 / 12 / 2016
Class : CS2B
Assignment : 1
Project Purpose : Use 2 classes to make an online store
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;


class Movie {
private:
	string movie_name_;
	int seats_;
	float ticket_price_;
public:
	//construct & dstruct
	Movie();
	Movie(string movie, float weight, float price) : movie_name_(movie), movie_seats_(seats), ticket_price_(price) { cout << "Movie Constructed" << endl; }
	~Movie();

	//getters and mutators
	Movie& set_mname(string name);
	string get_mname() const;

	Movie& set_seats(int seats);
	int get_seats() const;

	Movie& set_price(float price);
	float get_price() const;

	//other functions
	float PurchaseTicket(int ticket_number);
	void Display();
	//void Display();

};

class MovieTicketMaster {
private:
	Movie* movie_list_[8];
	string theater_name_;
	string theater_location_;

public:
	//constructor & dstructor
	MovieTicketMaster();
	MovieTicketMaster(string theater_name, string theater_location) : theater_name_(theater_name), theater_location_(theater_location) {}
	~MovieTicketMaster();

	//Accessor and mutator
	void set_tname(string name);
	string get_tname() const;

	void set_location(string location);
	string get_location() const;


	//Other
	void Init();
	void Run();
	int Find(string name);
	void Quit();
	void Menu();
	//void ShowAll();
};
