#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <conio.h>
#define ll long long
#define endl "\n"
using namespace std;
void Welcome();
void start_program();
void log_sign();
void log_manger();
void log_passenger();
void sign_passenger();
void schedule();
void flight();
void Search_Available_Flights();
void Add_new_reservation();
void Cancel_reservation();
void Modify_reservation();
void Show_reservation_log();
void Add_flight_schedule();
void Delete_flight_schedule();
void Update_flight_schedule();

bool found_flight = false;
bool found_ticket = false;

string s1, s2, s;
stringstream strem;

string date = "7/9/2021";
//Manger Account//
string Manger = "Manger";
string Manger_pass = "1234";

//Passengers Accounts//
string savednames[] = { "verina","marina","martina","carolina","maria" };
string savedpass[] = { "1ab","2ab","3ab","4ab","5ab" };
string savedphone[] = { "012","0122","0123","4343","134" };
string savedaddress[] = { "21b","rhsrhre24","dfsd34","wer44","ETE123" };
string savedid[] = { "203041","24354","45756","5576","32323" };
string cities[100] = { "Paris","Egypt","Canada","London","Greece" };

//flights schedule//
int economyseats[] = { 30,40,20,50 };
int businessseats[] = { 50,50,50,30 };
int firstclassseats[] = { 20,10,30,20 };
string flightcode[] = { "1cd", "2cd", "3cd", "4cd", "5cd" };
string departuredate[] = { "1/1/2021", "2/1/2021", "3/1/2021", "4/1/2021", "5/1/2021" };
string arrivaldate[] = { "2/1/2021", "3/1/2021", "4/1/2021", "5/1/2021", "6/1/2021" };
string departurecity[] = { "Paris","Egypt","Canada","London","Greece" };
string arrialcity[] = { "Egypt", "Paris", "London", "Greece", "Canada" };
long long fareeconomy[] = { 2556, 5588, 6844, 3288, 5688 };
long long farebusiness[] = { 5588, 7588, 8844, 5288, 7688 };
long long farefirstclass[] = { 7588, 9588, 9844, 7288, 9688 };

struct Passenger {
    string name[100];
    string password[100];
    string phone[100];
    string address[100];
    string id[100];

}passenger;
struct flight_struct {
    int economy_seats[100];
    int business_seats[100];
    int firstclass_seats[100];
    string flight_code[100];
    string depature_date[100]; // DD/MM/YYYY
    string depature_city[100];
    string arrival_date[100]; // DD/MM/YYYY
    string arrival_city[100];
    ll fare_economy_seats[100];
    ll fare_business_seats[100];
    ll fare_firstclass_seats[100];
    map<string, bool>visited_code;

}flights;
struct booking {
    int flight_number[100];
    string passenger_id[100];
    string flight_codee[100];
    string reservation_date[100]; // DD/MM/YYYY
    string seat[100];
    ll price[100];
    ll  ticket_number[2000];

}ticket;


int added = 0; //start from 0
int added_flight = 0; //start from 0
int added_tickets = 0; //start from 1
int user = 0;


//LOG IN / SIGN IN//
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    srand(time(0));
    for (int i = 0; i < 5; i++) {
        passenger.name[added] = savednames[i];
        passenger.password[added] = savedpass[i];
        passenger.phone[added] = savedphone[i];
        passenger.address[added] = savedaddress[i];
        passenger.id[added] = savedid[i];
        flights.arrival_city[added_flight] = arrialcity[i];
        flights.arrival_date[added_flight] = arrivaldate[i];
        flights.business_seats[added_flight] = businessseats[i];
        flights.economy_seats[added_flight] = economyseats[i];
        flights.firstclass_seats[added_flight] = firstclassseats[i];
        flights.flight_code[added_flight] = flightcode[i];
        flights.visited_code[flightcode[i]] = 1;
        flights.depature_city[added_flight] = departurecity[i];
        flights.depature_date[added_flight] = departuredate[i];
        flights.fare_business_seats[added_flight] = farebusiness[i];
        flights.fare_economy_seats[added_flight] = fareeconomy[i];
        flights.fare_firstclass_seats[added_flight] = farefirstclass[i];

        added++;
        added_flight++;
    }
    Welcome();
    start_program();

    return 0;
}
void start_program() {
    int x;
    cout << "Welcome to Airline reservation\n";
    cout << "Enter as: 1) Passenger           2) Manger \n";
again:
    while (!(cin >> x)) {
        cout << "Invalid Input, try again :  \n";
        cin.clear();
        cin.ignore(100, '\n');
    }
    if (x == 1) log_sign();
    else if (x == 2) log_manger();
    else {
        cout << "Invalid Number, try again : ";
        goto again;
    }


}
void log_manger() {
    cout << "Enter username: ";
    getline(cin, s); // grabbing "\n" left from cin and putting it into a "s" variable so i can read s1
    getline(cin, s1);
    cout << "Enter Password: ";
    getline(cin, s2);
    cout << '\n';
    if (s1 == Manger && s2 == Manger_pass)
        schedule();
    else {
        cout << "Invalid username or password\n";
        cout << "Enter 1 to try again\n" << "Enter 2 to return to previous page\n";
    again2:
        cin >> s;
        if (s == "1") log_manger();
        else if (s == "2") start_program();
        else {
            cout << "Invalid Number, try again";
            goto again2;
        }
    }
}
void log_sign() {
    cout << "Enter 1 to log in\n" << "Enter 2 to sign up\n";
again3:
    cin >> s;
    if (s == "1") log_passenger();
    else if (s == "2") sign_passenger();
    else {
        cout << "Invalid Number, try again";
        goto again3;
    }
}
void sign_passenger() {
    added++;
    user = added;
    getline(cin, s);
    cout << "Enter Username: ";
    getline(cin, passenger.name[added]);
    cout << "Enter Password: ";
    getline(cin, passenger.password[added]);
    cout << "Enter Phone Number: ";
    getline(cin, passenger.phone[added]);
    cout << "Enter your Address: ";
    getline(cin, passenger.address[added]);
    cout << "Enter your ID: ";
    getline(cin, passenger.id[added]);
    user = added;
    cout << "Welcome " << passenger.name[added] << " to Airline reservation\n";
    cout << "1) Add new Account\n" <<
        "2) Go to reservation list \n";
    cin >> s;
    if (s == "1")sign_passenger();
    else if (s == "2") flight();

}
void log_passenger() {
    getline(cin, s);
    cout << "Enter username: ";
    getline(cin, s1);
    cout << "\nEnter password: ";
    getline(cin, s2);
    for (int i = 0; i <= added; i++) {
        if (s1 == passenger.name[i] && s2 == passenger.password[i]) {
            user = i;
            flight();
            return;
        }
    }
    cout << "Invalid Username or Password\n" << "Press 1 to try again\n" << "Press 2 to return to previous page\n" << "Press 3 to go to main menu \n";
    cin >> s;
    if (s == "1") log_passenger();
    else if (s == "2") log_sign();
    else if (s == "3") start_program();

}
//PASSENGER FUNCTIONALITIES//
void flight() {
    cout << "\nWelcome " << passenger.name[user] << " to Airline reservation \n";
    cout << " List Of Choices " << endl << endl;
    cout << "1.Search Available Flights " << endl;
    cout << "2.Add new reservation    " << endl;
    cout << "3.Cancel reservation     " << endl;
    cout << "4.Modify reservation     " << endl;
    cout << "5.Show reservation log    " << endl;
    cout << "6.Main menu    " << endl;
    cout << "7.Exit program    " << endl << endl;
    cout << "Pleas Enter Your Selection Number..." << endl;
wrong:
    cin >> s;
    if (s == "1")
        Search_Available_Flights();
    else if (s == "2")
        Add_new_reservation();
    else if (s == "3")
        Cancel_reservation();
    else if (s == "4")
        Modify_reservation();
    else if (s == "5")
        Show_reservation_log();
    else if (s == "6")
        start_program();
    else if (s == "7")
        return;
    else {
        cout << "Invalid number, enter your selection number : ";
        goto wrong;
    }

}
void Search_Available_Flights() {
    cout << "      Do you want to search for the available flights by:" << endl;
    cout << "             1.the city you travel from " << endl;
    cout << "             2.the city you travel to " << endl;
    cout << "             3.the month you will travel" << endl;
    int n, p;
    string selection;
    cout << "             Please, enter your selection number... " << endl << endl;
    cin >> n;
    while (n > 3 || n <= 0) {
        cout << "Please, Enter Your Selection Number again : ";
        cin >> n;
    }
    found_flight = false;
    if (n == 1) {
        for (int i = 0; !cities[i].empty(); i++)
            cout << i + 1 << ". " << cities[i] << endl;

        cout << "please enter your selection city" << endl << endl;
        cin >> p;
        selection = cities[p - 1];
        for (int i = 0; i <= added_flight; i++) {
            if (selection == flights.depature_city[i] && (flights.economy_seats[i] > 0 || flights.business_seats[i] > 0 || flights.firstclass_seats[i] > 0)) {
                cout << i + 1 << ". ";
                cout << "Flight code : " << flights.flight_code[i] << endl;
                cout << "Flight Departure date     : " << flights.depature_date[i] << endl;// DD/MM/YYYY
                cout << "Flight Departure city     : " << flights.depature_city[i] << endl;
                cout << "Flight arrival date       : " << flights.arrival_date[i] << endl; // DD/MM/YYYY
                cout << "Flight arrival city       : " << flights.arrival_city[i] << endl;
                cout << "Economy ticket price      : " << flights.fare_economy_seats[i] << endl;
                cout << "Business ticket price     : " << flights.fare_business_seats[i] << endl;
                cout << "First class ticket price  : " << flights.fare_firstclass_seats[i] << endl;
                cout << "             *****" << endl;
                found_flight = true;
            }
        }
        if (!found_flight)
            cout << "No flights available for your requirements \n";

    }
    else if (n == 2) {
        for (int i = 0; !cities[i].empty(); i++)
            cout << i + 1 << ". " << cities[i] << endl;

        cout << "please enter your selection city" << endl << endl;
        cin >> p;
        selection = cities[p - 1];
        for (int i = 0; i <= added_flight; i++) {
            if (selection == flights.arrival_city[i] && (flights.economy_seats[i] > 0 || flights.business_seats[i] > 0 || flights.firstclass_seats[i] > 0)) {
                cout << i + 1 << ". ";
                cout << "Flight code : " << flights.flight_code[i] << endl;
                cout << "Flight Departure date     : " << flights.depature_date[i] << endl;// DD/MM/YYYY
                cout << "Flight Departure city     : " << flights.depature_city[i] << endl;
                cout << "Flight arrival date       : " << flights.arrival_date[i] << endl; // DD/MM/YYYY
                cout << "Flight arrival city       : " << flights.arrival_city[i] << endl;
                cout << "Economy ticket price      : " << flights.fare_economy_seats[i] << endl;
                cout << "Business ticket price     : " << flights.fare_business_seats[i] << endl;
                cout << "First class ticket price  : " << flights.fare_firstclass_seats[i] << endl;
                cout << "             *****" << endl;
                found_flight = true;
            }
        }
        if (!found_flight)
            cout << "No flights available for your requirements \n";
    }
    else if (n == 3) {
        cout << "Enter the Month you want to travel in [MM]: ";
        cin >> p;
        int start = 0;
        while (p > 12 || p < 1) {
            cout << "\n Month [MM]: ";
            cin >> p;
        }

        //to put p in string so i could compare
        strem.str("");
        strem << p;
        s2 = strem.str();

        for (int i = 0; i <= added_flight; i++) {
            string month = flights.depature_date[i];
            string m;
            start = 0;
            for (int j = 0; j < month.size(); j++) {  // to get the month from form
                if (month[j] == '/' && start == 0)start = j;
                if (start != 0) break;
            }

            start++;
            for (int k = start; month[k] != '/'; k++) {
                m.push_back(month[k]);
            }

            if (m == s2 && (flights.economy_seats[i] > 0 || flights.business_seats[i] > 0 || flights.firstclass_seats[i] > 0)) {
                cout << i + 1 << ". ";
                cout << "Flight code : " << flights.flight_code[i] << endl;
                cout << "Flight Departure date     : " << flights.depature_date[i] << endl;// DD/MM/YYYY
                cout << "Flight Departure city     : " << flights.depature_city[i] << endl;
                cout << "Flight arrival date       : " << flights.arrival_date[i] << endl; // DD/MM/YYYY
                cout << "Flight arrival city       : " << flights.arrival_city[i] << endl;
                cout << "Economy ticket price      : " << flights.fare_economy_seats[i] << endl;
                cout << "Business ticket price     : " << flights.fare_business_seats[i] << endl;
                cout << "First class ticket price  : " << flights.fare_firstclass_seats[i] << endl;
                cout << "             *****" << endl;
                found_flight = true;
            }
        }
        if (!found_flight)
            cout << "No flights available for your requirements \n";
    }
    cout << "Do you want to search for any thing else ?(y/n) : ";
    cin >> s;
    if (s == "y") Search_Available_Flights();
    else flight();

}
void Add_new_reservation() {
    int n, b, f, p, i, q;
    string selection, selsction_flight;
    found_flight = false;
    cout << "             Do you want to add a reservation according to: \n";
    cout << "             1.The city you will travel from \n";
    cout << "             2.The city you will travel to \n";
    cout << "             3.The month you will travel \n";
    cout << "             Please Enter Your Selection Number..." << endl << endl;
    cin >> n;
    while (n > 3 || n <= 0) {
        cout << "             Please, Enter Your Selection Number again : "; cin >> n;
    }
    cout << "How many flights do you want to book? \n";
    cin >> q;
    if (n == 1) {
        for (int j = 0; !cities[j].empty(); j++) {
            cout << j + 1 << ". " << cities[j] << endl;
        }
        cout << "             Please Enter Your Selection Number..." << endl << endl;
        cin >> b;
        selection = cities[b - 1];
        int choices[100] = { 0 };
        for (i = 0; i <= added_flight; i++) {

            if (selection == flights.depature_city[i] && (flights.business_seats[i] != 0 || flights.firstclass_seats[i] != 0 || flights.economy_seats[i] != 0)) {
                cout << i + 1 << ". ";
                cout << "Flight code : " << flights.flight_code[i] << endl;
                cout << "Flight Departure date     : " << flights.depature_date[i] << endl;// DD/MM/YYYY
                cout << "Flight Departure city     : " << flights.depature_city[i] << endl;
                cout << "Flight arrival date       : " << flights.arrival_date[i] << endl; // DD/MM/YYYY
                cout << "Flight arrival city       : " << flights.arrival_city[i] << endl;
                cout << "Economy ticket price      : " << flights.fare_economy_seats[i] << endl;
                cout << "Business ticket price     : " << flights.fare_business_seats[i] << endl;
                cout << "First class ticket price  : " << flights.fare_firstclass_seats[i] << endl;
                cout << "             *****" << endl;
                found_flight = true;
                choices[i] = 1;
            }
        }
        if (!found_flight)
            cout << "No flights available for your requirements \n";
        else {
            cout << "             Please Enter flight Selection Number..." << endl << endl;
            cin >> f;
            f = f - 1;
            while (choices[f] != 1)
            {
                cout << "Invalid Number, Please Enter flight Selection Number... " << endl; cin >> f;
            }
            selsction_flight = flights.flight_code[f];
            cout << "There is on this flight:" << endl;
            cout << "We have " << flights.economy_seats[f] << " Economy seats available in this flight ";
            cout << "Economy ticket price : " << flights.fare_economy_seats[f] << endl;
            cout << "We have " << flights.business_seats[f] << " Business seats available in this flight ";
            cout << "Business ticket price : " << flights.fare_business_seats[f] << endl;
            cout << "We have " << flights.firstclass_seats[f] << " First class seats available in this flight ";
            cout << "First class ticket price : " << flights.fare_firstclass_seats[f] << endl << endl;

            cout << "Which ride class would you like to choose:" << endl;
            cout << "1.economy" << endl << "2.business " << endl << "3.first class" << endl;
            cout << "             Please Enter Your Selection Number..." << endl << endl;
            int class_num;
            added_tickets++;

        class_number:
            cin >> class_num;

            //Update ticket //

            if (class_num == 1 && flights.economy_seats[f] >= 1)
            {
                flights.economy_seats[f] -= q; ticket.seat[added_tickets] = "Economy"; ticket.price[added_tickets] = flights.fare_economy_seats[f];
            }
            else if (class_num == 2 && flights.business_seats[f] >= 1)
            {
                flights.business_seats[f] -= q; ticket.seat[added_tickets] = "Business"; ticket.price[added_tickets] = flights.fare_business_seats[f];
            }

            else if (class_num == 3 && flights.firstclass_seats[f] >= 1)
            {
                flights.firstclass_seats[f] -= q; ticket.seat[added_tickets] = "First class"; ticket.price[added_tickets] = flights.fare_firstclass_seats[f];
            }
            else goto class_number;
            for (int i = 0; i < q; i++) {
                ticket.ticket_number[added_tickets + i] = added_tickets;
                ticket.flight_codee[added_tickets + i] = selsction_flight;
                ticket.passenger_id[added_tickets + i] = passenger.id[user];
                ticket.reservation_date[added_tickets + i] = date;
                ticket.flight_number[added_tickets + i] = f;
            }

            cout << "Booking succeeded ";

        }
    }
    else if (n == 2) {
        for (int j = 0; !cities[j].empty(); j++) {
            cout << j + 1 << ". " << cities[j] << endl;
        }
        cout << "             Pleas Enter Your Selection Number..." << endl << endl;
        cin >> b;
        selection = cities[b - 1];
        int choices[100] = { 0 };
        for (i = 0; i <= added_flight; i++) {

            if (selection == flights.arrival_city[i] && (flights.business_seats[i] != 0 || flights.firstclass_seats[i] != 0 || flights.economy_seats[i] != 0)) {
                cout << i + 1 << ". ";
                cout << "Flight code : " << flights.flight_code[i] << endl;
                cout << "Flight Departure date     : " << flights.depature_date[i] << endl;// DD/MM/YYYY
                cout << "Flight Departure city     : " << flights.depature_city[i] << endl;
                cout << "Flight arrival date       : " << flights.arrival_date[i] << endl; // DD/MM/YYYY
                cout << "Flight arrival city       : " << flights.arrival_city[i] << endl;
                cout << "Economy ticket price      : " << flights.fare_economy_seats[i] << endl;
                cout << "Business ticket price     : " << flights.fare_business_seats[i] << endl;
                cout << "First class ticket price  : " << flights.fare_firstclass_seats[i] << endl;
                cout << "             *****" << endl;
                found_flight = true;
                choices[i] = 1;
            }
        }
        if (!found_flight)
            cout << "No flights available for your requirements \n";
        else {
            cout << "             Pleas Enter flight Selection Number..." << endl << endl;
            cin >> f;
            f--;
            while (choices[f] != 1)
            {
                cout << "Invalid Number, Please Enter flight Selection Number... " << endl; cin >> f;
            }
            selsction_flight = flights.flight_code[f];
            cout << "There is on this flight:" << endl;
            cout << "We have " << flights.economy_seats[f] << " Economy seats available in this flight ";
            cout << "Economy ticket price : " << flights.fare_economy_seats[f] << endl;
            cout << "We have " << flights.business_seats[f] << " Business seats available in this flight ";
            cout << "Business ticket price : " << flights.fare_business_seats[f] << endl;
            cout << "We have " << flights.firstclass_seats[f] << " First class seats available in this flight ";
            cout << "First class ticket price : " << flights.fare_firstclass_seats[f] << endl << endl;

        class_number2:
            cout << "Which ride class would you like to choose:" << endl;
            cout << "1.economy" << endl << "2.business " << endl << "3.first class" << endl;
            cout << "             Pleas Enter Your Selection Number..." << endl << endl;
            int class_num;
            added_tickets++;


            cin >> class_num;

            //Update ticket remaining //

            if (class_num == 1 && flights.economy_seats[f] >= 1)
            {
                flights.economy_seats[f] -= q; ticket.seat[added_tickets] = "Economy"; ticket.price[added_tickets] = flights.fare_economy_seats[f];
            }
            else if (class_num == 2 && flights.business_seats[f] >= 1)
            {
                flights.business_seats[f] -= q; ticket.seat[added_tickets] = "Business"; ticket.price[added_tickets] = flights.fare_business_seats[f];
            }

            else if (class_num == 3 && flights.firstclass_seats[f] >= 1)
            {
                flights.firstclass_seats[f] -= q; ticket.seat[added_tickets] = "First class"; ticket.price[added_tickets] = flights.fare_firstclass_seats[f];
            }
            else goto class_number2;
            for (int i = 0; i < q; i++) {
                ticket.ticket_number[added_tickets] = added_tickets;
                ticket.flight_codee[added_tickets] = selsction_flight;
                ticket.passenger_id[added_tickets] = passenger.id[user];
                ticket.reservation_date[added_tickets] = date;
                ticket.flight_number[added_tickets] = f;
            }

            cout << "Booking succeeded \n Your ticket code is:";

        }

    }

    else if (n == 3) {
        cout << "Enter the Month you want to travel in [MM]: "; \
            cin >> p;
        int start = 0;
        while (p > 12 || p < 1) {
            cout << "\n Month [MM]: ";
            cin >> p;
        }
        //to put p in string so i could compare
        strem.str("");
        strem << p;
        s2 = strem.str();
        int choices[100] = { 0 };
        for (int i = 0; i <= added_flight; i++) {
            string month = flights.depature_date[i];
            string m;
            start = 0;
            for (int j = 0; j < month.size(); j++) {  // to get the month from form
                if (month[j] == '/' && start == 0)start = j;
                if (start != 0) break;
            }

            start++;
            for (int k = start; month[k] != '/'; k++) {
                m.push_back(month[k]);
            }
            if (m == s2 && (flights.economy_seats[i] > 0 || flights.business_seats[i] > 0 || flights.firstclass_seats[i] > 0)) {
                cout << i + 1 << ". ";
                cout << "Flight code : " << flights.flight_code[i] << endl;
                cout << "Flight Departure date     : " << flights.depature_date[i] << endl;// DD/MM/YYYY
                cout << "Flight Departure city     : " << flights.depature_city[i] << endl;
                cout << "Flight arrival date       : " << flights.arrival_date[i] << endl; // DD/MM/YYYY
                cout << "Flight arrival city       : " << flights.arrival_city[i] << endl;
                cout << "Economy ticket price      : " << flights.fare_economy_seats[i] << endl;
                cout << "Business ticket price     : " << flights.fare_business_seats[i] << endl;
                cout << "First class ticket price  : " << flights.fare_firstclass_seats[i] << endl;
                cout << "             *****" << endl;
                found_flight = true;
                choices[i] = 1;

            }
        }
        if (!found_flight)
            cout << "No flights available for your requirements \n";
        else {
            cout << "             Pleas Enter flight Selection Number..." << endl << endl;
            cin >> f;
            f--;
            while (choices[f] != 1)
            {
                cout << "Invalid Number, Please Enter flight Selection Number... " << endl; cin >> f;
            }
            selsction_flight = flights.flight_code[f];
            cout << "There is on this flight:" << endl;
            cout << "We have " << flights.economy_seats[f] << " Economy seats available in this flight ";
            cout << "Economy ticket price : " << flights.fare_economy_seats[f] << endl;
            cout << "We have " << flights.business_seats[f] << " Business seats available in this flight ";
            cout << "Business ticket price : " << flights.fare_business_seats[f] << endl;
            cout << "We have " << flights.firstclass_seats[f] << " First class seats available in this flight ";
            cout << "First class ticket price : " << flights.fare_firstclass_seats[f] << endl << endl;

            cout << "Which ride class would you like to choose:" << endl;
            cout << "1.economy" << endl << "2.business " << endl << "3.first class" << endl;
            cout << "             Pleas Enter Your Selection Number..." << endl << endl;
            int class_num;
            added_tickets++;

        class_number3:
            cin >> class_num;

            //Update ticket remaining //

            if (class_num == 1 && flights.economy_seats[f] >= 1)
            {
                flights.economy_seats[f] -= q; ticket.seat[added_tickets] = "Economy"; ticket.price[added_tickets] = flights.fare_economy_seats[f];
            }
            else if (class_num == 2 && flights.business_seats[f] >= 1)
            {
                flights.business_seats[f] -= q; ticket.seat[added_tickets] = "Business"; ticket.price[added_tickets] = flights.fare_business_seats[f];
            }

            else if (class_num == 3 && flights.firstclass_seats[f] >= 1)
            {
                flights.firstclass_seats[f] -= q; ticket.seat[added_tickets] = "First class"; ticket.price[added_tickets] = flights.fare_firstclass_seats[f];
            }
            else goto class_number3;

            ticket.ticket_number[added_tickets] = added_tickets;
            ticket.flight_codee[added_tickets] = selsction_flight;
            ticket.passenger_id[added_tickets] = passenger.id[user];
            ticket.reservation_date[added_tickets] = date;
            ticket.flight_number[added_tickets] = f;


            cout << "Booking succeeded \n Your ticket code is:";

        }
    }
    cout << "Do you want to Add new reservation ?(y/n) : ";
    cin >> s;
    if (s == "y") Add_new_reservation();
    else flight();
}
void Cancel_reservation() {
    found_ticket = false;
    int index_flight, index_ticket, a;
    cout << "Enter Flight code : ";
    cin >> s;
    for (int i = 1; i <= added_tickets; i++) {
        if (passenger.id[user] == ticket.passenger_id[i] && s == ticket.flight_codee[i]) {
            index_flight = ticket.flight_number[i];
            index_ticket = i;
            found_ticket = true;
            cout << index_flight << ". ";
            cout << "Flight code  : " << flights.flight_code[index_flight] << endl;
            cout << "Flight Departure date     : " << flights.depature_date[index_flight] << endl;// DD/MM/YYYY
            cout << "Flight Departure city     : " << flights.depature_city[index_flight] << endl;
            cout << "Flight arrival date       : " << flights.arrival_date[index_flight] << endl; // DD/MM/YYYY
            cout << "Flight arrival city       : " << flights.arrival_city[index_flight] << endl;
            cout << "Your ticket reservation   : " << ticket.seat[index_ticket] << endl;
            cout << "Your ticket price         : " << ticket.price[index_ticket] << endl;
            cout << "Flight Reservation date   : " << ticket.reservation_date[index_ticket] << endl;
            cout << "      *****" << endl << endl;
            cout << "Do you want to cancel this flight? (y,n)\n";
            cin >> s;
            if (s == "y") {
                passenger.id[user] = "-1";
                ticket.ticket_number[i] = -1;
                cout << "Which was your ride class? \n";
                cout << "1.economy" << endl << "2.business " << endl << "3.first class" << endl;
                cin >> a;
                if (a == 1)
                    flights.economy_seats[index_flight]++;
                else if (a == 2)
                    flights.business_seats[index_flight]++;
                else if (a == 3)
                    flights.firstclass_seats[index_flight]++;
            }
            else flight();
        }
    }
    if (!found_ticket) {
        cout << "No Reservation found \n";
    }

    cout << endl << endl << "Reservation has been cancelled sucessfully \n";
    cout << "Do you want to cancel any reservation again ? (y/n)";
    cin >> s;
    if (s == "y") Cancel_reservation();
    else flight();
}
void Modify_reservation() {
    int zz, cc;
    int x = 0, y, z, p = -1;
    int index_ticket;
    char c;
    string b;
codee:
    cout << "Enter flight code: " << endl;
    x++;
    cin >> s1;
    if (flights.visited_code[s1] == 0) {
        cout << "This flight does not exist. \n";
        if (x >= 2) {
            x = 0;
            cout << "Do you want to go to main menu ? (y\n) : ";
            cin >> c;
            if (c == 'y')schedule();
            else {
                goto codee;
            }
        }
        else {
            goto codee;
        }
    }
    for (int i = 0; i <= added_flight; ++i) {
        if (flights.flight_code[i] == s1) {
            zz = i;
            break;
        }
    }
    bool finddd = false;
    for (int i = 0; i <= added_tickets; i++) {
        if (flights.flight_code[zz] == ticket.flight_codee[i] && passenger.id[user] == ticket.passenger_id[i]) {
            index_ticket = i;
            finddd = true;
            break;
        }
    }
    if (!finddd) {
        cout << "You are not reserved in this flight. \n";
        cout << "Press 1 to try again \n";
        string po;
        cin >> po;
        if (po == "1")
            Modify_reservation();
        else
            flight();
    }
    cout << "The data of your current flight : " << endl;
    cout << "Flight code : " << flights.flight_code[zz] << endl;
    cout << "Flight Departure date     : " << flights.depature_date[zz] << endl;// DD/MM/YYYY
    cout << "Flight Departure city     : " << flights.depature_city[zz] << endl;
    cout << "Flight arrival date       : " << flights.arrival_date[zz] << endl; // DD/MM/YYYY
    cout << "Flight arrival city       : " << flights.arrival_city[zz] << endl;
    cout << "Your ticket reservation   : " << ticket.seat[index_ticket] << endl;
    cout << "Your ticket price         : " << ticket.price[index_ticket] << endl;
    cout << "Flight Reservation date   : " << ticket.reservation_date[index_ticket] << endl;
    cout << "             *" << endl << endl;

    cout << "what do you want to modify" << endl;
    cout << "1.seats          2.the whole reservation \n";
    cin >> s;
    int st;
    if (s == "1") {
        cout << "Your ticket reservation   : " << ticket.seat[index_ticket] << endl;
        cout << "Your ticket price         : " << ticket.price[index_ticket] << endl << endl;

        if (ticket.seat[index_ticket] == "Economy") st = 1;
        else if (ticket.seat[index_ticket] == "Business") st = 2;
        else st = 3;

        cout << "There is on this flight:" << endl;
        cout << "We have " << flights.economy_seats[zz] << " Economy seats available in this flight ";
        cout << "Economy ticket price : " << flights.fare_economy_seats[zz] << endl << endl;
        cout << "We have " << flights.business_seats[zz] << " Business seats available in this flight ";
        cout << "Business ticket price : " << flights.fare_business_seats[zz] << endl << endl;
        cout << "We have " << flights.firstclass_seats[zz] << " First class seats available in this flight ";
        cout << "First class ticket price : " << flights.fare_firstclass_seats[zz] << endl << endl;
        int class_num = -1;

    class_number4:
        cout << "Press ..";
        cout << "1. To change to economy.\n";
        cout << "2. To change to business.\n";
        cout << "3. To change to first class. \n";
        cin >> class_num;

        if (class_num == st) {
            cout << "This is already your reservation seat";
            goto class_number4;
        }

        if (class_num == 1 && flights.economy_seats[zz] >= 1) {
            flights.economy_seats[zz]--;
            ticket.seat[added_tickets] = "Economy";
            ticket.price[added_tickets] = flights.fare_economy_seats[zz];
            if (st == 2) flights.business_seats[zz]++;
            else flights.firstclass_seats[zz]++;
        }
        else if (class_num == 2 && flights.business_seats[zz] >= 1) {
            flights.business_seats[zz]--;
            ticket.seat[added_tickets] = "Business";
            ticket.price[added_tickets] = flights.fare_business_seats[zz];
            if (st == 1) flights.economy_seats[zz]++;
            else flights.firstclass_seats[zz]++;
        }

        else if (class_num == 3 && flights.firstclass_seats[zz] >= 1)
        {
            flights.firstclass_seats[zz]--;
            ticket.seat[added_tickets] = "First class";
            ticket.price[added_tickets] = flights.fare_firstclass_seats[zz];
            if (st == 1) flights.economy_seats[zz]++;
            else flights.business_seats[zz]++;
        }

        else {
            cout << "Invalid Number or the seats are Full";
            goto class_number4;
        }
    }
    else if (s == "2") {
        int ar[105] = { 0 };
        for (int i = 0; i <= added_flight; ++i) {
            if (flights.economy_seats[x] == 0 && flights.business_seats[x] == 0 && flights.firstclass_seats[x] == 0)
                continue;
            cout << i + 1 << ")" << endl;
            cout << "Flight code : " << flights.flight_code[i] << endl;
            cout << "Flight Departure date      : " << flights.depature_date[i] << endl;// DD/MM/YYYY
            cout << "Flight Departure city      : " << flights.depature_city[i] << endl;
            cout << "Flight arrival date        : " << flights.arrival_date[i] << endl; // DD/MM/YYYY
            cout << "Flight arrival city        : " << flights.arrival_city[i] << endl;
            cout << "Economy ticket price       : " << flights.fare_economy_seats[i] << endl;
            cout << "Business ticket price      : " << flights.fare_business_seats[i] << endl;
            cout << "First class ticket price   : " << flights.fare_firstclass_seats[i] << endl;
            cout << "             *" << endl << endl;
            ar[i] = 1;
        }
    Again:
        cout << "Choose Number of flight you want to reserve : " << endl;
        cin >> z;
        z--;
        if (ar[z] != 1 || flights.visited_code[flights.flight_code[z]] == 0) {
            cout << "Invalid choice, Enter 1 to try again . \n ";
            cin >> s;
            if (s == "1")
                goto Again;
            else
                flight();
        }

        cout << "Economy :" << flights.economy_seats[z] << endl;
        cout << "Business :" << flights.business_seats[z] << endl;
        cout << "First class :" << flights.firstclass_seats[z] << endl;

        int stt;
        if (ticket.seat[index_ticket] == "Economy") stt = 1;
        else if (ticket.seat[index_ticket] == "Business") stt = 2;
        else stt = 3;
    seatss:
        cout << "Press ... \n";
        cout << "1. To change to economy.\n";
        cout << "2. To change to business.\n";
        cout << "3. To change to first class.\n";

        int class_num;
        cin >> class_num;

        if (class_num == 1 && flights.economy_seats[z] >= 1) {
            flights.economy_seats[z]--;
            ticket.seat[added_tickets] = "Economy";
            ticket.price[added_tickets] = flights.fare_economy_seats[z];
            if (stt == 2) flights.business_seats[z]++;
            else flights.firstclass_seats[z]++;
        }
        else if (class_num == 2 && flights.business_seats[z] >= 1) {
            flights.business_seats[z]--;
            ticket.seat[added_tickets] = "Business";
            ticket.price[added_tickets] = flights.fare_business_seats[z];
            if (stt == 1) flights.economy_seats[z]++;
            else flights.firstclass_seats[z]++;
        }

        else if (class_num == 3 && flights.firstclass_seats[z] >= 1) {
            flights.firstclass_seats[z]--;
            ticket.seat[added_tickets] = "First class";
            ticket.price[added_tickets] = flights.fare_firstclass_seats[z];
            if (stt == 1) flights.economy_seats[z]++;
            else flights.business_seats[z]++;
        }

        else {
            cout << "Invalid Number or the seats are Full . \n";
            cout << "Press 1 to try again." << endl;
            string qqq;
            cin >> qqq;
            if (qqq == "1")
                goto seatss;
            else
                flight();
        }
    }
    else {
        cout << "Invalid choice . \n";
        cout << "Press 1 tp try again : \n ";
        string hh;
        cin >> hh;
        if (hh == "1")
            Modify_reservation();
        else flight();
    }
    cout << "Do you want to update any thing else ?(y/n) : ";
    cin >> c;
    if (c == 'y' || c == 'Y') Modify_reservation();
    else flight();
}
void Show_reservation_log() {
    int index_flight, index_ticket;
    for (int i = 1; i <= added_tickets; i++) {
        if (passenger.id[user] == ticket.passenger_id[i]) { //user>>account index(log or sign)
            index_flight = ticket.flight_number[i];
            index_ticket = i;
            found_ticket = true;
            cout << index_flight << ". ";
            cout << "Flight code : " << flights.flight_code[index_flight] << endl;
            cout << "Flight Departure date     : " << flights.depature_date[index_flight] << endl;// DD/MM/YYYY
            cout << "Flight Departure city     : " << flights.depature_city[index_flight] << endl;
            cout << "Flight arrival date       : " << flights.arrival_date[index_flight] << endl; // DD/MM/YYYY
            cout << "Flight arrival city       : " << flights.arrival_city[index_flight] << endl;
            cout << "Your ticket reservation   : " << ticket.seat[index_ticket] << endl;
            cout << "Your ticket price         : " << ticket.price[index_ticket] << endl;
            cout << "Flight Reservation date   : " << ticket.reservation_date[index_flight] << endl;
            cout << "             *****" << endl << endl;
            found_ticket = true;
        }
    }
    if (!found_ticket) {
        cout << "There is No Reservation yet \n";
    }
    cout << "Do you want to go to reservation menu ? (y/n)";
    cin >> s;
    if (s == "y") flight();
    else return;
}
//FLIGHT SCHEDULE FUNCTIONALITIES//
void schedule() {
    cout << "* Welcome To Airline Reservation System *" << '\n';
    cout << "Airline Reservation System Menu For Host : " << '\n';
    cout << "1. Add	New	flight schedule\n"
        << "2. Delete existing flight schedule\n"
        << "3. Update existing flight schedule\n"
        << "4.  Main menu   \n"
        << "5. Exit program     \n";
sched:
    cout << "Please, Enter Your Selection Number : ";
    cin >> s;
    if (s == "1")
        Add_flight_schedule();
    else if (s == "2")
        Delete_flight_schedule();
    else if (s == "3")
        Update_flight_schedule();
    else if (s == "4")
        start_program();
    else if (s == "5")
        return;

    else {
        cout << "\nInvalid Number .\n";
        goto sched;
    }
}
void Add_flight_schedule() {
    int x, y, z;
    added_flight++;
    cout << "Enter flight code: ";
code:
    cin >> s1;
    if (flights.visited_code[s1] == 0) {
        cout << "code is already existed, try another one. ";
        goto code;
    }
    flights.visited_code[s1] = true; //map
    flights.flight_code[added_flight] = s1;
    cout << "Enter the Date of Journey :\n";
Month:
    cout << "\tMonth [MM] : ";
    cin >> x;
    if (x > 12 || x < 1) {
        cout << "Invalid input, enter between range [1-12]\n";
        goto Month;
    }
day:
    cout << "\tDay [DD] : ";
    cin >> y;
    if (y > 31 || y < 1) {
        cout << "Invalid date, enter between range [1-31]\n";
        goto day;
    }
    else if ((x == 4 || x == 6 || x == 9 || x == 11) && y > 30) {
        cout << "Invalid input, month " << x << " only 30 days\n";
        goto day;
    }
    else if (x == 2 && y > 28) {
        cout << "Invalid input, month " << x << " only 28 days\n";
        goto day;
    }
yearr:
    cout << "\tYear [YYYY] : ";
    cin >> z;
    if (z != 2021) {
        cout << "You can only add reservation for current year.\n";
        goto yearr;
    }
    strem.str("");
    strem << y << "/" << x << "/" << z;
    s1 = strem.str();
    flights.depature_date[added_flight] = s1;

    int i = 0, xx;
    cout << "Choose your departure city number: \n";
    for (i = 0; !cities[i].empty(); i++) {
        cout << i + 1 << ". " << cities[i] << endl;
    }
city:
    cout << "Enter your departure city Number:";
    cin >> xx;
    xx--;
    if (xx > i - 1 || xx < 0) goto city;
    flights.depature_city[added_flight] = cities[xx];


    //Arrival

    y += rand() % 3;
    if (y > 30)y = 1;
    else if (y == 28 && x == 2)y = 1;
    strem.str("");
    strem << y << "/" << x << "/" << z;
    s1 = strem.str();
    flights.arrival_date[added_flight] = s1;
    int j;
    cout << "Choose your arrival city number: \n";
    for (i = 0; !cities[i].empty(); i++) {
        cout << i + 1 << ". " << cities[i] << endl;
    }
acity:
    cout << "Enter your arrival city Number: ";
    cin >> j; j--;
    if (j > i - 1 || j < 0) goto acity;
    if (j == xx) {
        cout << "You can't choose this city.\n";
        goto acity;
    }
    flights.arrival_city[added_flight] = cities[j];

    cout << "No. of Seats for Economy Class : ";
    cin >> flights.economy_seats[added_flight];

    cout << "No. of Seats for Business Class : ";
    cin >> flights.business_seats[added_flight];

    cout << "No. of Seats for First Class : ";
    cin >> flights.firstclass_seats[added_flight];


    cout << "Fare for Economy Class : ";
    cin >> flights.fare_economy_seats[added_flight];

    cout << "Fare for Business Class : ";
    cin >> flights.fare_business_seats[added_flight];

    cout << "Fare for First Class : ";
    cin >> flights.fare_firstclass_seats[added_flight];


    cout << "Your flight is added successfully." << endl;
    cout << "Following are the Flight details that you added ;-\n";
    cout << "Flight Code        Date        Origin          Arrival date         Destination      E    B    F\n";
    cout << " ---------         ----        -------         ------------         ------------    ---  ---  ---\n";
    cout << "    " << flights.flight_code[added_flight] << "        " << flights.depature_date[added_flight] << "        " << flights.depature_city[added_flight]
        << "          " << flights.arrival_date[added_flight] << "         " << flights.arrival_city[added_flight] << "            " << flights.economy_seats[added_flight]
        << "  " << flights.business_seats[added_flight] << "  " << flights.firstclass_seats[added_flight] << endl;
    cout << "Press 1 to go to main menu \n Press any other key to EXIT program";
    cin >> s;
    if (s == "1") schedule();

}
void Delete_flight_schedule() {
    int zz;
codee22:
    cout << "Enter flight code: ";
    cin >> s1;
    if (flights.visited_code[s1] == 0) {
        cout << "This flight does not exist. \n";
        goto codee22;
    }
    for (int i = 0; i <= added_flight; ++i) {
        if (flights.flight_code[i] == s1) {
            zz = i;
            break;
        }
    }
    // make the code unvisited
    flights.visited_code[s1] = false;

    // flight code
    flights.flight_code[zz] = '0';

    // Arrival
    flights.arrival_city[zz] = '0';
    flights.arrival_date[zz] = '0';

    // Departure
    flights.depature_city[zz] = '0';
    flights.depature_date[zz] = '0';

    // seats
    flights.business_seats[zz] = 0;
    flights.economy_seats[zz] = 0;
    flights.firstclass_seats[zz] = 0;

    // price of each class
    flights.fare_business_seats[zz] = 0;
    flights.fare_economy_seats[zz] = 0;
    flights.fare_firstclass_seats[zz] = 0;

    //number of flights
    cout << endl << endl << "This flight has been deleted successfully \n";
    schedule();
}
void Update_flight_schedule() {
    int zz;
    int x = 0, y, z;
    char c;
codee:
    cout << "Enter flight code: ";
    x++;
    cin >> s1;
    if (flights.visited_code[s1] == 0) {
        cout << "This flight does not exist. \n";
        if (x >= 2) {
            x = 0;
            cout << "Do you want to go to main menu ? (y/n) : ";
            cin >> s;
            if (s == "y")schedule();
            else goto codee;
        }
        else {
            goto codee;
        }
    }
    for (int i = 0; i <= added_flight; ++i) {
        if (flights.flight_code[i] == s1) {
            zz = i;
            break;
        }
    }
    int a;
update:
    cout << "what do you want to update ? \n";
    cout << "1.Departure city          2.Arrival city \n";
    cout << "3.Departure date          4.Economy seats \n";
    cout << "5.Business seats          6.first class seats \n";
    cout << "7.Economy fare            8.Business fare \n";
    cout << "9.First class fare        10.Flight code \n";
    cout << endl << "Enter your choice: ";
numb:
    cin >> a;
    if (a > 10 || a < 1) {
        cout << "Invalid input,try again : ";
        goto numb;
    }
    int i = 0;
    switch (a) {
    case 1:
        cout << "Current departure city : " << flights.depature_city[zz] << endl;
        for (i = 0; !cities[i].empty(); i++) {
            cout << i + 1 << ". " << cities[i] << endl;
        }
    citee:
        cout << "Choose a number for the new departure city: ";
        cin >> x;
        x--;
        while (x > i - 1 || x < 0) goto citee;
        if (cities[x] == flights.arrival_city[zz]) {
            cout << "This is the arrival city " << endl;
            goto citee;
        }

        flights.depature_city[zz] = cities[x];
        cout << "New departure city : " << flights.depature_city[zz] << endl;
        cout << "Do you want to update any thing else ?(y/n) : ";
        cin >> s;
        if (s == "y") goto update;
        else schedule();
        break;

    case 2:
        cout << "Current arrival city : " << flights.arrival_city[zz] << endl;
        for (i = 0; !cities[i].empty(); i++) {
            cout << i + 1 << ". " << cities[i] << endl;
        }
    cite:
        cout << "Choose a number for the new arrival city: ";
        cin >> x;
        x--;

        while (x > i - 1 || x < 0) goto cite;
        if (cities[x] == flights.depature_city[zz]) {
            cout << "This is the arrival city " << endl;
            goto citee;
        }
        flights.arrival_city[zz] = cities[x];
        cout << "New arrival city : " << flights.arrival_city[zz] << endl;
        cout << "Do you want to update any thing else ?(y/n) : ";
        cin >> s;
        if (s == "y") goto update;
        else schedule();
        break;

    case 3:
        cout << "Current departure date : " << flights.depature_date[zz] << endl;
        cout << "Enter the Date of Journey :\n";
    Month2:
        cout << "\tMonth [MM] : ";
        cin >> x;
        if (x > 12 || x < 0) {
            cout << "Invalid input, enter between range [1-12]\n";
            goto Month2;
        }
    day2:
        cout << "\tDay [DD] : ";
        cin >> y;
        if (y > 31 || y < 0) {
            cout << "Invalid date, enter between range [1-31]\n";
            goto day2;
        }
        else if ((x == 4 || x == 6 || x == 9 || x == 11) && y > 30) {
            cout << "Invalid input, month " << x << " only 30 days\n";
            goto day2;
        }
        else if (x == 2 && y > 28) {
            cout << "Invalid input, month " << x << " only 28 days\n";
            goto day2;
        }
    yearr2:
        cout << "\tYear [YYYY] : ";
        cin >> z;
        if (z != 2021) {
            cout << "You can only add reservation for current year.\n";
            goto yearr2;
        }
        strem.str("");
        strem << y << "/" << x << "/" << z;
        s1 = strem.str();
        flights.depature_date[zz] = s1;

        //update arrival date
        y += rand() % 3;
        if (y > 30)y = 1;
        else if (y == 28 && x == 2)y = 1;
        strem.str("");
        strem << y << "/" << x << "/" << z;
        s1 = strem.str();
        flights.arrival_date[zz] = s1;

        cout << "New departure date : " << flights.depature_date[zz] << endl;
        cout << "New arrival date : " << flights.arrival_date[zz] << endl;
        cout << "Do you want to update any thing else ?(y/n) : ";
        cin >> s;
        if (s == "y") goto update;
        else schedule();
        break;

    case 4:
        cout << "Current Economy seats : " << flights.economy_seats[zz] << endl;
        cout << "Enter New Number of Economy seats : ";
        cin >> x;
        flights.economy_seats[zz] = x;
        cout << "New Economy seats : " << flights.economy_seats[zz] << endl;
        cout << "Do you want to update any thing else ?(y/n) : ";
        cin >> s;
        if (s == "y") goto update;
        else schedule();
        break;

    case 5:
        cout << "Current Business seats : " << flights.business_seats[zz] << endl;
        cout << "Enter New Number of Business seats : ";
        cin >> x;
        flights.business_seats[zz] = x;
        cout << "New Economy seats : " << flights.business_seats[zz] << endl;
        cout << "Do you want to update any thing else ?(y/n) : ";
        cin >> s;
        if (s == "y") goto update;
        else schedule();
        break;

    case 6:
        cout << "Current First Class seats : " << flights.firstclass_seats[zz] << endl;
        cout << "Enter New Number of First Class seats : ";
        cin >> x;
        flights.firstclass_seats[zz] = x;
        cout << "New First Class seats : " << flights.firstclass_seats[zz] << endl;
        cout << "Do you want to update any thing else ?(y/n) : ";
        cin >> s;
        if (s == "y") goto update;
        else schedule();
        break;

    case 7:
        cout << "Current Economy fare : " << flights.fare_economy_seats[zz] << endl;
        cout << "Enter New Economy fare : ";
        cin >> x;
        flights.fare_economy_seats[zz] = x;
        cout << "New Economy fare : " << flights.fare_economy_seats[zz] << endl;
        cout << "Do you want to update any thing else ?(y/n) : ";
        cin >> s;
        if (s == "y") goto update;
        else schedule();
        break;

    case 8:
        cout << "Current Business fare : " << flights.fare_business_seats[zz] << endl;
        cout << "Enter New Business fare : ";
        cin >> x;
        flights.fare_business_seats[zz] = x;
        cout << "New Economy fare : " << flights.fare_business_seats[zz] << endl;
        cout << "Do you want to update any thing else ?(y/n) : ";
        cin >> s;
        if (s == "y") goto update;
        else schedule();
        break;

    case 9:
        cout << "Current First Class fare : " << flights.fare_firstclass_seats[zz] << endl;
        cout << "Enter New First Class fare : ";
        cin >> x;
        flights.fare_firstclass_seats[zz] = x;
        cout << "New First Class fare : " << flights.fare_firstclass_seats[zz] << endl;
        cout << "Do you want to update any thing else ?(y/n) : ";
        cin >> s;
        if (s == "y") goto update;
        else schedule();
        break;

    case 10:
        string s;
        cout << "Current flight code : " << flights.flight_code[zz] << endl;
        cout << "Enter New flight code : ";
        cin >> s;
        cout << "New flight code : " << flights.flight_code[zz] << endl;
        cout << "Do you want to update any thing else ?(y/n) : ";
        cin >> s;
        if (s == "y") goto update;
        else schedule();
        break;

    }

}
void Welcome() {
    system("clear");
    cout << "\n\n\n\n\n\n\n\n";
    cout << "\t\t\t      //////////////     //////////////       //         //////////////      \n";
    cout << "\t\t\t      //                 //                              //                  \n";
    cout << "\t\t\t      //                 //                   //         //                  \n";
    cout << "\t\t\t      //                 //                   //         //                  \n";
    cout << "\t\t\t      //                 //                   //         //                  \n";
    cout << "\t\t\t      //////////////     //                   //         //////////////      \n";
    cout << "\t\t\t      //                 //                   //                     //      \n";
    cout << "\t\t\t      //                 //                   //                     //      \n";
    cout << "\t\t\t      //                 //                   //                     //      \n";
    cout << "\t\t\t      //                 //////////////       //         //////////////      \n";
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t                              /////////////////////\n";
    cout << "\t\t\t                             //    SP-PROJECT   //\n";
    cout << "\t\t\t                            /////////////////////\n";
    cout << "\n\n";
    cout << "\t\t\t                 //////////////////////////////////////\n";
    cout << "\t\t\t                //    AIRLINE RESERVATION SYSTEM    //\n";
    cout << "\t\t\t               //////////////////////////////////////\n";
    cout << "\n";
    cout << "\t\t\t                     Press Enter to Continue .....\n";
    cin.get();
}