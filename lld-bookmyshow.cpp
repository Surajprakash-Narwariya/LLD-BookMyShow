#include <bits/stdc++.h>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;

// Design book my show
// DESIGN OBJECTIVE ->
(i) A booking app to book movie show.
(ii) Choose user, theatre, movie to book the show.
(iii) Calculate bill for the booked ticket
(iv) If seat is already booked, show booked details and if not then book
(v) Compare the ticket prices with all the theatres.
(vi) Show the empty and booked seats with their name.


class User {
	public:
		string name;
		int age;
		string mobileNo;

		User(string name, int age, string mobileNo){
			this->age = age;
			this->name = name;
			this->mobileNo = mobileNo;
		}

		void getInformation(){
			cout << "------------USERINFO---------------" << endl;
			cout << "Name : " << name << endl;
			cout << "Age : " << age << endl;
			cout << "Mobile No : " << mobileNo << endl;
			cout <<endl;
		}
};

class Movie {
public:
	string name; 
	int year;
	int price;
	Movie(string name, int year, int price){
		this->name = name;
		this->year = year;
		this->price = price;
	}
};


class Theatre {
	public:
		string name;
		vector<Movie> movieList; // 
		vector<vector<User>> seats;
		int percentage;; // seat matrix for theatre
		// here the index of movieList match with ith index of seats, 
		// whereas jth store the user object who booked it;

		Theatre(string name, vector<Movie> movieList, int percentage) {
			this->name = name;
			this->movieList = movieList;
			User u("0", 0, "");
			vector<vector<User>> s(movieList.size(), vector<User>(10, u));
			this->seats = s;
			this->percentage = percentage;
		}

		void printBill(User user1, Movie m1, int seat){
			// bill logic here
			int ticketPrice = m1.price;
			double tax = ticketPrice/4;
			int premiumTax = 0;
			int serviceCharge = ticketPrice/percentage;
			if(seat == 7 || seat == 8 || seat == 9){
				premiumTax = ticketPrice/10;
			}
			int total = ticketPrice + tax + premiumTax+ serviceCharge;

			

			cout << "BILL No."  << rand()%100007 << endl;
			cout << "User - Ms/Mr." << user1.name << endl; 
			cout << m1.name << "  Seat No." << seat << endl; 
			cout << "Ticket Price    => " << ticketPrice << endl;
			cout << "Tax             => " << tax << endl;
			cout << "Balcony         => " << premiumTax << endl;
			cout << "Service Charges => " << serviceCharge << endl;
			cout << "Total Amt       => Rs." << total << endl;
			cout << "-----------------------------------";
			cout << endl;
		}

		int getBillEstimate(Movie m1, int seat){
			int ticketPrice = m1.price;
			double tax = ticketPrice/4;
			int serviceCharge = ticketPrice/percentage;
			int total = ticketPrice + tax + serviceCharge;
			return total;
		}

		void bookMovieShow(User user1, Movie m1, int seat){
			// check if the seat is empty or not;
			// get the index of the movie
			int index = 0;
			for(; index<movieList.size(); index++){
				if(m1.name == movieList[index].name){
					break;
				}
			}

			for(int i=0; i<seats.size(); i++){

			}
			if(seats[index][seat].name == "0"){
				seats[index][seat] = user1;
				cout << "Seat is booked successfully" << endl;
				cout << endl;
				printBill(user1, m1, seat);
			}else{
				cout << "Seat is already booked" << endl;
				cout << "Seat is booked by " << endl;
				seats[index][seat].getInformation();
			}

		}

		void getSeatMatrix(){
			for(int i=0; i<seats.size(); i++){
				cout << movieList[i].name << " ";
				for(int j=0; j<seats[0].size(); j++){
					cout << seats[i][j].name << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

		void showAllMovies(){
			for(int i=0; i<movieList.size(); i++){
				cout << movieList[i].name << " " ;
				cout << getBillEstimate(movieList[i], 0);
				cout << endl;
			}
			cout << endl;
		}
};



int main() {

	// freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
 
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    // USERS
    User Suraj("Suraj", 23, "9009477686");
    User Aakash("Aakash", 22, "7867877394");
    User Rakesh("Rakesh", 27, "8959404918");
    User Chandan("Chandan", 19, "9876612928");

    // MOVIE
    Movie m1("PK", 2017, 150);
    Movie m2("Drishyam", 2023, 200);
    Movie m3("Robot", 2011, 120);
    Movie m4("KGF", 2021, 130);
    vector<Movie> movieList = {m1, m2, m3, m4};

    // Theatres
    Theatre PVR("PVR", movieList, 21);
    Theatre INOX("C21", movieList, 16);

    PVR.bookMovieShow(Suraj, m4, 9);
    PVR.bookMovieShow(Aakash, m1, 2);
    PVR.bookMovieShow(Rakesh, m2, 8);
    PVR.bookMovieShow(Chandan, m3, 7);
    PVR.getSeatMatrix();
    INOX.bookMovieShow(Suraj, m4,9);
    INOX.getSeatMatrix();
    PVR.showAllMovies();
    INOX.showAllMovies();
    
    return 0;
}





