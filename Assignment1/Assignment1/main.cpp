/*Name: Vladimir Tretyakov
Student ID : 20082073
Date : 10 / 12 / 2016
Class : CS2B
Assignment : 1
Project Purpose : Use 2 classes to create an online theater ticket dispenser
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "lab6finalheaderh.h"

using namespace std;

float MovieTicketMaster::tax_rate_ = 0.085;

void pause() {
	long count = 0;
	while (isspace(cin.peek()) && count != 30000000) {
		count++;
	}
}

Movie::~Movie() {
	cout << "Movie Deconstructed " << movie_name_ << "   " << weight_ << "    " << unit_price_ << endl;
}
Movie& Movie::set_mname(string name) {
	movie_name_ = name;
	return *this;
}
string Movie::get_mname() const {
	return movie_name_;
}
Movie& Movie::set_seats(int seats) {
	theater_seats_ = seats;
	return *this;
}
float Movie::get_seats() const {
	return seats_;
}
Movie& Movie::set_price(float price) {
	ticket_price_ = price;
	return *this;
}
float Movie::get_price() const {
	return unit_price_;
}

void Movie::Display() {
	cout << setw(10) << this->get_name();
	cout << setw(7) << fixed << "$" << setprecision(2) << this->get_seats();
	cout << setw(7) << fixed << setprecision(2) << this->get_price() << endl;
}


MovieTicketMaster::~MovieTicketMaster() {
	cout << "Theater" << get_tname() << "at " << get_location() << " is closed ..." << endl;
	for (int i = 0; i < 8; i++) {
		delete movie_list_[i];
	}
}
void MovieTicketMaster::set_tname(string name) {
	theater_name_ = name;
}
string MovieTicketMaster::get_tname()const {
	return theater_name_;
}
void MovieTicketMaster::set_address(string address) {
	theater_location_ = address;
}
string MovieTicketMaster::get_address()const {
	return theater_location_;
}

//price = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
void MovieTicketMaster::Init() {
	float price, rand_weight;
	//made an array holding LO and HI to ease this function
	string names[8] = { "Banana", "Strawberry", "Orange", "Grapes", "Watermelon", "Apple", "Blueberry", "Mango" };
	int seats[8] = { 30,30,30,25,25,25,20,20 };
	float prices[8] = { 10.00,10.00,10.00,10.00,14.50,14.50,14.50,14.50 };
	for (int i = 0; i < 8; i++) {
	movie_list_[i] = new Movie();
	movie_list_[i]->set_mname(names[i]).set_seats_(seats[i]).set_price(prices[i]);
	}
}
void MovieTicketMaster::Menu() {
	cout << "MOVIE TICKET MASTER" << endl;
	cout << "Theater: " << theater_name_ << " at " << theater_location_ << endl;
	cout << "Where you come to see the cutting edge in Cinema" << endl;
	cout << "1. View all movies" << endl;
	cout << "2. Search a movie" << endl;
	cout << "3. Purchase a ticket" << endl;
	cout << "4. Quit" << endl;
	cout << "Please enter an option: ";
}

void MovieTicketMaster::Run() {
	int option;
	while (true) {
		Menu();
		cin >> option;
		switch (option) {
		case 1:
			p_movie = new Movie();
			p_movie = &movie_list[0];
			for (int i = 0; i < 8; i++) {
				p_movie->Display();
				p_movie++;
			}
			continue;
		case 2:
			string m_name;
			cout << "Please enter a movie name: ";
			cin >> m_name;
			SearchMovie(m_name);
			continue;
		case 3:;
		case 4:;


		}
	}
	string movie_name;
	int temp_index = 0;
	float temp_weight = 0;
	while (true) {
		cout << "Enter a movie name or XXX to end :";
		cin >> movie_name;
		if (movie_name == "XXX") {
			break;
		}
		temp_index = Find(movie_name);
		if (temp_index == -1) {
			cout << "Invalid Movie Entered." << endl;
			continue;
		}

		Movie* movie = movie_list_[temp_index];

		cout << "Enter weight in lbs : ";
		cin >> temp_weight;
		if (movie->Order(temp_weight) < 0) {
			cout << "Not enough movie available." << endl;
			continue;
		}
		cout << "Total cost : " << ((movie_list_[temp_index]->get_price()*temp_weight) + ((movie_list_[temp_index]->get_price()*temp_weight)* get_tax_rate())) << "  (tax included)" << endl;
	}
	Quit();
}
int MovieTicketMaster::Find(string name) {
	for (int i = 0; i < 8; i++) {
		if (name == movie_list_[i]->get_name()) {
			return i;
		}
	}
	return -1;
}
void MovieTicketMaster::Quit() {
	cout << "Thanks for your visit and come again." << endl;
}
/*void MovieTicketMaster::ShowAll() {
	for (int i = 0; i < 8; i++) {
		movie_list_[i]->Display();
	}
}*/
int main() {
	MovieTicketMaster * my_ptr = NULL;
	MovieTicketMaster * p = new MovieTicketMaster("MortMart", "www.MortMart.com");
	my_ptr = p;
	my_ptr->Init();
	my_ptr->Sort();
	my_ptr->ShowAll();
	my_ptr->Run();

	delete my_ptr;
	pause();

	return 0;

}
