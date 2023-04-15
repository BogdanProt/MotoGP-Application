#include <iostream>
#include <cstring>
using namespace std;

class Motorcycle{
    int hp;
    int engineCapacity;
    int topSpeed;
    char *manufacturer;
    char *model;

public:
    //Constructors

    Motorcycle(int hp, int engineCapacity, int topSpeed, const char* manufacturer, const char* model){
        this->hp = hp;
        this->engineCapacity = engineCapacity;
        this->topSpeed = topSpeed;
        this->manufacturer = new char[strlen(manufacturer) + 1];
        strcpy(this->manufacturer, manufacturer);
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
    }

    Motorcycle(int hp, int engineCapacity, const char* manufacturer, const char* model){
        this->hp = hp;
        this->engineCapacity = engineCapacity;
        this->topSpeed = 0;
        this->manufacturer = new char[strlen(manufacturer) + 1];
        strcpy(this->manufacturer, manufacturer);
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
    }
    
    Motorcycle(const char* manufacturer, const char* model){
        this->hp = 0;
        this->engineCapacity = 0;
        this->topSpeed = 0;
        this->manufacturer = new char[strlen(manufacturer) + 1];
        strcpy(this->manufacturer, manufacturer);
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
    }

    Motorcycle(const Motorcycle& motorcycle){               //Copy constructor
        this->hp = motorcycle.hp;
        this->engineCapacity = motorcycle.engineCapacity;
        this->topSpeed = motorcycle.topSpeed;
        this->manufacturer = new char[strlen(motorcycle.manufacturer) + 1];
        strcpy(this->manufacturer, motorcycle.manufacturer);
        this->model = new char[strlen(motorcycle.model) + 1];
        strcpy(this->model, motorcycle.model);
    }

    Motorcycle(Motorcycle&& motorcycle){                //Move constructor
        this->hp = motorcycle.hp;
        this->engineCapacity = motorcycle.engineCapacity;
        this->topSpeed = motorcycle.topSpeed;
        this->manufacturer = new char[strlen(motorcycle.manufacturer) + 1];
        strcpy(this->manufacturer, motorcycle.manufacturer);
        this->model = new char[strlen(motorcycle.model) + 1];
        strcpy(this->model, motorcycle.model);

        motorcycle.hp = 0;
        motorcycle.engineCapacity = 0;
        motorcycle.topSpeed = 0;
        delete[] motorcycle.manufacturer;
        delete[] motorcycle.model;
        motorcycle.manufacturer = new char[1];
        motorcycle.manufacturer[0] = '\0';
        motorcycle.model = new char[1];
        motorcycle.model[0] = '\0';
    }

    Motorcycle(){
        this->hp = 0;
        this->engineCapacity = 0;
        this->topSpeed = 0;
        manufacturer = new char[1];
        manufacturer[0] = '\0';
        model = new char[1];
        model[0] = '\0';
    }

    //Destructor

    ~Motorcycle(){
        delete[] this->manufacturer;
        delete[] this->model;
    }

    Motorcycle& operator=(const Motorcycle& motorcycle){        // "=" operator overload
        if (this != &motorcycle){
            this->hp = motorcycle.hp;
            this->engineCapacity = motorcycle.engineCapacity;
            this->topSpeed = motorcycle.topSpeed;
            delete[] this->manufacturer;
            this->manufacturer = new char[strlen(motorcycle.manufacturer) + 1];
            strcpy(this->manufacturer, motorcycle.manufacturer);
            delete[] this->model;
            this->model = new char[strlen(motorcycle.model) + 1];
            strcpy(this->model, motorcycle.model);
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Motorcycle& motorcycle){     // "<<" operator overload
        out << "Horsepower: " << motorcycle.hp << endl;
        out << "Engine capacity: " << motorcycle.engineCapacity << endl;
        out << "Top speed: " << motorcycle.topSpeed << endl;
        out << "Manufacturer: " << motorcycle.manufacturer << endl;
        out << "Model: " << motorcycle.model << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Motorcycle& motorcycle){    // ">>" operator overload
        cout << "Horsepower: ";
        in >> motorcycle.hp;

        cout << "Engine capacity: ";
        in >> motorcycle.engineCapacity;

        cout << "Top speed: ";
        in >> motorcycle.topSpeed;

        return in;
    }

    //Setters

    void set_hp(int hp) { this->hp = hp; }

    void set_engineCapacity(int engineCapacity) { this->engineCapacity = engineCapacity; }

    void set_topSpeed(int topSpeed) { this->topSpeed = topSpeed; }

    void set_manufacturer(const char* manufacturer){
        delete[] this->manufacturer;
        this->manufacturer = new char[strlen(manufacturer) + 1];
        strcpy(this->manufacturer, manufacturer);
    }

    void set_model(const char* model){
        delete[] this->model;
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
    }

    //Getters

    int get_hp() const { return this->hp; }

    int get_engineCapacity() const { return this->engineCapacity; }

    int get_topSpeed() const { return this->topSpeed; }

    const char* get_manufacturer() const { return this->manufacturer; }

    const char* get_model() const { return this->model; }
};


class Track{
    char* name;
    char* location;
    double length;
    int noTurns;
    int noSeats;

public:
    //Constructors

    Track(const char* name, const char* location, double length, int noTurns, int noSeats){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->location = new char[strlen(location) + 1];
        strcpy(this->location, location);
        this->length = length;
        this->noTurns = noTurns;
        this->noSeats = noSeats;
    }

    Track(const char* name, const char* location, double length){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->location = new char[strlen(location) + 1];
        strcpy(this->location, location);
        this->length = length;
        this->noTurns = 0;
        this->noSeats = 0;
    }

    Track(const char* name, const char* location){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->location = new char[strlen(location) + 1];
        strcpy(this->location, location);
        this->length = 0;
        this->noTurns = 0;
        this->noSeats = 0;
    }

    Track(const Track& track){                  //Copy constructor
        this->name = new char[strlen(track.name) + 1];
        strcpy(this->name, track.name);
        this->location = new char[strlen(track.location) + 1];
        strcpy(this->location, track.location);
        this->length = track.length;
        this->noTurns = track.noTurns;
        this->noSeats = track.noSeats;
    }

    Track(Track&& track){                   //Move constructor
        this->name = new char[strlen(track.name) + 1];
        strcpy(this->name, track.name);
        this->location = new char[strlen(track.location) + 1];
        strcpy(this->location, track.location);
        this->length = track.length;
        this->noTurns = track.noTurns;
        this->noSeats = track.noSeats;

        delete[] track.name;
        delete[] track.location;
        track.name = new char[1];
        track.name[0] = '\0';
        track.location = new char[1];
        track.location[0] = '\0';
        track.length = 0;
        track.noTurns = 0; 
        track.noSeats = 0;
    }

    Track(){
        name = new char[1];
        name[0] = '\0';
        location = new char[1];
        location[0] = '\0';
        this->length = 0;
        this->noTurns = 0;
        this->noSeats = 0;
    }

    //Destructor

    ~Track(){
        delete[] this->name;
        delete[] this->location;
    }

    Track& operator=(const Track& track){        // "=" operator overload
        if (this != &track){
            delete[] this->name;
            this->name = new char[strlen(track.name) + 1];
            strcpy(this->name, track.name);
            delete[] this->location;
            this->location = new char[strlen(track.location) + 1];
            strcpy(this->location, track.location);
            this->length = track.length;
            this->noTurns = track.noTurns;
            this->noSeats = track.noSeats;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Track& track){       // "<<" operator overload
        out << "Name: " << track.name << endl;
        out << "Location: " << track.location << endl;
        out << "Length: " << track.length << endl;
        out << "Number of turns: " << track.noTurns << endl;
        out << "Number of seats: " << track.noSeats;
        return out;
    }

    friend istream& operator>>(istream& in, Track& track){          // ">>" operator overload
        cout << "Length: ";
        in >> track.length;

        cout << "Number of turns: ";
        in >> track.noTurns;

        cout << "Number of seats: ";
        in >> track.noSeats;

        return in;
    }

    //Setters

    void set_name(const char* name){
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void set_location(const char* location){
        delete[] this->location;
        this->location = new char[strlen(location) + 1];
        strcpy(this->location, location);
    }

    void set_length(double length) { this->length = length; }

    void set_noTurns(int noTurns) { this->noTurns = noTurns; }

    void set_noSeats(int noSeats) { this->noSeats = noSeats; }

    //Getters

    const char* get_name() const { return this->name; }

    const char* get_location() const { return this->location; }

    double get_length() const { return this->length; }

    int get_noTurns() const { return this->noTurns; }

    int get_noSeats() const { return this->noSeats; }

};


class Sponsor{
    char *name;
    char *services;
    int sponsorshipAmount;

public:
    //Constructors

    Sponsor(const char* name, const char* services, int sponsorshipAmount){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->services = new char[strlen(services) + 1];
        strcpy(this->services, services);
        this->sponsorshipAmount = sponsorshipAmount;
    }

    Sponsor(const char* name, const char* services){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->services = new char[strlen(services) + 1];
        strcpy(this->services, services);
        this->sponsorshipAmount = 0;
    }

    Sponsor(const Sponsor& sponsor){            //Copy constructor
        this->name = new char[strlen(sponsor.name) + 1];
        strcpy(this->name, sponsor.name);
        this->services = new char[strlen(sponsor.services) + 1];
        strcpy(this->services, sponsor.services);
        this->sponsorshipAmount = sponsor.sponsorshipAmount;
    }

    Sponsor(Sponsor&& sponsor){                 //Move constructor
        this->name = new char[strlen(sponsor.name) + 1];
        strcpy(this->name, sponsor.name);
        this->services = new char[strlen(sponsor.services) + 1];
        strcpy(this->services, sponsor.services);
        this->sponsorshipAmount = sponsor.sponsorshipAmount;

        delete[] sponsor.name;
        delete[] sponsor.services;
        sponsor.name = new char[1];
        sponsor.name[0] = '\0';
        sponsor.services = new char[1];
        sponsor.services[0] = '\0';
        sponsor.sponsorshipAmount = 0;
    }

    Sponsor(){
        name = new char[1];
        name[0] = '\0';
        services = new char[1];
        services[0] = '\0';
        this->sponsorshipAmount = 0;
    }

    //Destructor

    ~Sponsor(){
        delete[] this->name;
        delete[] this->services;
    }

    Sponsor& operator=(const Sponsor& sponsor){        // "=" operator overload
        if (this != &sponsor){
            delete[] this->name;
            this->name = new char[strlen(sponsor.name) + 1];
            strcpy(this->name, sponsor.name);
            delete[] this->services;
            this->services = new char[strlen(sponsor.services) + 1];
            strcpy(this->services, sponsor.services);
            this->sponsorshipAmount = sponsor.sponsorshipAmount;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Sponsor& sponsor){       // "<<" operator overload
        out << "Name: " << sponsor.name << endl;
        out << "Services: " << sponsor.services << endl;
        out << "Sponsorship Level: " << sponsor.sponsorshipAmount;
        return out;
    }

    //Setters

    void set_name(const char* name){
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void set_services(const char* services){
        delete[] this->services;
        this->services = new char[strlen(services) + 1];
        strcpy(this->services, services);
    }

    void set_sponsorshipAmount(int sponsorshipAmount) { this->sponsorshipAmount = sponsorshipAmount; }

    //Getters

    const char* get_name() const { return this->name; }

    const char* get_services() const { return this->services; }

    int get_sponsorshipAmount() const { return this->sponsorshipAmount; }

};

class Race{
    char* date;
    char* name;
    Track track;
    int numSponsors;
    int sponsorsAmount;
    double ticketPrice;
    int ticketsSold;

public:
    //Constructors

    Race(const char* date, const char* name, Track track, int numSponsors, int sponsorsAmount, double ticketPrice, int ticketsSold){
        this->date = new char[strlen(date) + 1];
        strcpy(this->date, date);
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->track = track;
        this->numSponsors = numSponsors;
        this->sponsorsAmount = sponsorsAmount;
        this->ticketPrice = ticketPrice;
        this->ticketsSold = ticketsSold;
    }

    Race(const char* date, const char* name, Track track){
        this->date = new char[strlen(date) + 1];
        strcpy(this->date, date);
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->track = track;
        numSponsors = 0;
        sponsorsAmount = 0;
        ticketPrice = 0;
        ticketsSold = 0;
    }

    Race(const char* date, Track track){
        this->date = new char[strlen(date) + 1];
        strcpy(this->date, date);
        this->name = new char[1];
        name[0] = '\0';
        this->track = track;
        numSponsors = 0;
        sponsorsAmount = 0;
        ticketPrice = 0;
        ticketsSold = 0;
    }

    Race(const Race& race){         //Copy constructor
        this->date = new char[strlen(race.date) + 1];
        strcpy(this->date, race.date);
        this->name = new char[strlen(race.name) + 1];
        strcpy(this->name, race.name);
        track = race.track;
        sponsorsAmount = race.sponsorsAmount;
        numSponsors = race.numSponsors;
        ticketPrice = race.ticketPrice;
        ticketsSold = race.ticketsSold;
    }

    Race(){
        this->date = new char[1];
        date[0] = '\0';
        this->name = new char[1];
        name[0] = '\0';
        numSponsors = 0;
        sponsorsAmount = 0;
        ticketPrice = 0;
        ticketsSold = 0;
    }

    //Destructor

    ~Race(){
        delete[] date;
        delete[] name;
    }

    Race& operator=(const Race& race){        // "=" operator overload
        if (this != &race){
            delete[] this->date;
            this->date = new char[strlen(race.date) + 1];
            strcpy(this->date, race.date);
            delete[] this->name;
            this->name = new char[strlen(race.name) + 1];
            strcpy(this->name, race.name);
            this->track = race.track;
            this->sponsorsAmount = race.sponsorsAmount;
            this->numSponsors = race.numSponsors;
            this->ticketPrice = race.ticketPrice;
            this->ticketsSold = race.ticketsSold;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Race& race){         // "<<" operator overload
        out << "Date: " << race.date << endl;
        out << "Name: " << race.name << endl;
        out << "TRACK \n" << race.track << endl;
        out << "Sponsors amount: " << race.sponsorsAmount << endl;
        out << "Number of sponsors: " << race.numSponsors << endl;
        out << "Ticket price: " << race.ticketPrice << endl;
        out << "Tickets sold: " << race.ticketsSold << endl;
        return out;
    }

    void add_sponsor(const Sponsor& sponsor){       //Adds new sponsor
        sponsorsAmount+=sponsor.get_sponsorshipAmount();
        numSponsors++;
    }

    void sell_ticket(){                 //Sells one ticket
        if (ticketsSold < track.get_noSeats())
            ticketsSold++;
        else
            cout << "We cannot sell any more tickets! There are no seats left.";
    }

    void sell_tickets(int n){           //Sells a given number of tickets
        if (ticketsSold + n <= track.get_noSeats())
            ticketsSold+=n;
        else if (ticketsSold + 1 <= track.get_noSeats())
            cout << "We have only sold " << track.get_noSeats() - ticketsSold << " tickets from the total of " << n << " tickets as there are no more seats left.";
            else cout << "We cannot sell any more tickets! There are no seats left.";
    }

    //Setters

    void set_date(const char* date){
        delete[] this->date;
        this->date = new char[strlen(date) + 1];
        strcpy(this->date, date);
    }

    void set_name(const char* name){
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void set_track(const Track& track) { this->track = track; }

    void set_sponsorsAmount(int sponsorsAmount) { this->sponsorsAmount = sponsorsAmount; }

    void set_numSponsors(int numSponsors) { this->numSponsors = numSponsors; }

    void set_ticketPrice(double ticketPrice) { this->ticketPrice = ticketPrice; }

    void set_ticketsSold(int ticketsSold) { this->ticketsSold = ticketsSold; }

    //Getters

    const char* get_date() const { return this->date; }

    const char* get_name() const { return this->name; }

    Track get_track() const { return this->track; }

    int get_sponsorsAmount() const { return this->sponsorsAmount; }

    int get_numSponsors() const { return this->numSponsors; }

    double get_ticketPrice() const { return this->ticketPrice; }

    int get_ticketsSold() const { return this->ticketsSold; }

};


double calculate_race_profit(const Race& race){         //Calculates a given race's total profit from sponsorships and tickets sold
    int ticketsSold = race.get_ticketsSold();
    double ticketPrice = race.get_ticketPrice();
    int sponsorsAmount = race.get_sponsorsAmount();
    double totalRaceProfit;
    totalRaceProfit = ticketsSold * ticketPrice + sponsorsAmount;
    return totalRaceProfit;
}

class Team{
    char* name;
    char* rider1name;
    char* rider2name;
    double points;

public:
    //Constructors

    Team(const char* name, const char* rider1name, const char* rider2name, double points){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->rider1name = new char[strlen(rider1name) + 1];
        strcpy(this->rider1name, rider1name);
        this->rider2name = new char[strlen(rider2name) + 1];
        strcpy(this->rider2name, rider2name);
        this->points = points;
    }

    Team(const char* name, const char* rider1name, const char* rider2name){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->rider1name = new char[strlen(rider1name) + 1];
        strcpy(this->rider1name, rider1name);
        this->rider2name = new char[strlen(rider2name) + 1];
        strcpy(this->rider2name, rider2name);
        points = 0;
    }

    Team(const Team& team){         //Copy constructors
        name = new char[strlen(team.name) + 1];
        strcpy(name, team.name);
        rider1name = new char[strlen(team.rider1name) + 1];
        strcpy(rider1name, team.rider1name);
        rider2name = new char[strlen(team.rider2name) + 1];
        strcpy(rider2name, team.rider2name);
        points = team.points;
    }

    Team(){
        name = new char[1];
        name[0] = '\0';
        rider1name = new char[1];
        rider1name[0] = '\0';
        points = 0;
    }

    //Destructor

    ~Team(){
        delete[] name;
        delete[] rider1name;
        delete[] rider2name;
    }

    Team& operator=(const Team& team){      // "=" operator overload
        if (this != &team){
            delete[] this->name;
            name = new char[strlen(team.name) + 1];
            strcpy(name, team.name);
            delete[] rider1name;
            rider1name = new char[strlen(team.rider1name) + 1];
            strcpy(rider1name, team.rider1name);
            delete[] rider2name;
            rider2name = new char[strlen(team.rider2name) + 1];
            strcpy(rider2name, team.rider2name);
            points = team.points;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Team& team){     // "<<" operator overload
        out << "Name: " << team.name << endl;
        out << "First rider: " << team.rider1name << endl;
        out << "Second rider: " << team.rider2name << endl;
        out << "Points: " << team.points << endl;
        return out;
    }

    void add_points(double n){      //Adds points to the team
        points+=n;
    }

    //Setters

    void set_name(const char* name){
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void set_rider1name(const char* rider1name) {
        delete[] this->rider1name;
        this->rider1name = new char[strlen(rider1name) + 1];
        strcpy(this->rider1name, rider1name);
    }

    void set_rider2name(const char* rider2name) {
        delete[] this->rider2name;
        this->rider2name = new char[strlen(rider2name) + 1];
        strcpy(this->rider2name, rider2name);
    }

    void set_points(double points) { this->points = points; }

    //Getters

    const char* get_name() const { return name; }

    const char* get_rider1name() const { return rider1name; }

    const char* get_rider2name() const { return rider2name; }

    double get_points() const { return points; }


};


class Rider{
    char *riderName;
    char *nationality;
    char *teamName;
    int age;
    int totalWins;
    int championshipsWon;
    Motorcycle riderBike;

public:
    //Constructors

    Rider(const char* riderName, const char* nationality, const char* teamName, int age, int totalWins, int championshipsWon, Motorcycle riderBike){
        this->riderName = new char[strlen(riderName) + 1];
        strcpy(this->riderName, riderName);
        this->nationality = new char[strlen(nationality) + 1];
        strcpy(this->nationality, nationality);
        this->teamName = new char[strlen(teamName) + 1];
        strcpy(this->teamName, teamName);
        this->age = age;
        this->totalWins = totalWins;
        this->championshipsWon = championshipsWon;
        this->riderBike = riderBike;
    }

    Rider(const char* riderName, const char* nationality, const char* teamName, int age){
        this->riderName = new char[strlen(riderName) + 1];
        strcpy(this->riderName, riderName);
        this->nationality = new char[strlen(nationality) + 1];
        strcpy(this->nationality, nationality);
        this->teamName = new char[strlen(teamName) + 1];
        strcpy(this->teamName, teamName);
        this->age = age;
        totalWins = 0;
        championshipsWon = 0;
    }

    Rider(const char* riderName, const char* nationality, int age){
        this->riderName = new char[strlen(riderName) + 1];
        strcpy(this->riderName, riderName);
        this->nationality = new char[strlen(nationality) + 1];
        strcpy(this->nationality, nationality);
        teamName = new char[1];
        teamName[0] = '\0';
        this->age = age;
        totalWins = 0;
        championshipsWon = 0;
    }

    Rider(){
        this->riderName = new char[1];
        riderName[0] = '\0';
        this->nationality = new char[1];
        nationality[0] = '\0';
        this->teamName = new char[1];
        teamName[0] = '\0';
        age = 0;
        totalWins = 0;
        championshipsWon = 0;
    }

    //Destructor

    ~Rider(){
        delete[] riderName;
        delete[] nationality;
        delete[] teamName;
    }

    Rider& operator=(const Rider& rider){       // "=" operator overload
        if (this != &rider){
            delete[] this->riderName;
            this->riderName = new char[strlen(rider.riderName) + 1];
            strcpy(this->riderName, rider.riderName);
            delete[] this->nationality;
            this->nationality = new char[strlen(rider.nationality) + 1];
            strcpy(this->nationality, rider.nationality);
            delete[] this->teamName;
            this->teamName = new char[strlen(rider.teamName) + 1];
            strcpy(this->teamName, rider.teamName);
            age = rider.age;
            totalWins = rider.totalWins;
            championshipsWon = rider.championshipsWon;
            riderBike = rider.riderBike;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Rider& rider){       // "<<" operator overload
        out << "Name: " << rider.riderName << endl;
        out << "Nationality: " << rider.nationality << endl;
        out << "Team: " << rider.teamName << endl;
        out << "Age: " << rider.age << endl;
        out << "Total wins: " << rider.totalWins << endl;
        out << "Championships won: " << rider.championshipsWon << endl;
        out << "BIKE \n" << rider.riderBike << endl;
        return out;
    }

    //Setters

    void set_riderName(const char* riderName){
        delete[] this->riderName;
        this->riderName = new char[strlen(riderName) + 1];
        strcpy(this->riderName, riderName);
    }

    void set_nationality(const char* nationality){
        delete[] this->nationality;
        this->nationality = new char[strlen(nationality) + 1];
        strcpy(this->nationality, nationality);
    }

    void set_teamName(const char* teamName){
        delete[] this->teamName;
        this->teamName = new char[strlen(teamName) + 1];
        strcpy(this->teamName, teamName);
    }

    void set_age(int age) { this->age = age; }

    void set_totalWins(int totalWins) { this->totalWins = totalWins; }

    void set_championshipsWon(int championshipsWon) { this->championshipsWon = championshipsWon; }

    void set_riderBike(const Motorcycle& riderBike) { this->riderBike = riderBike; }

    //Getters

    const char* get_riderName() const { return this->riderName; }

    const char* get_nationality() const { return this->nationality; }

    const char* get_teamName() const { return this->teamName; }

    int get_age() const { return this->age; }

    int get_totalWins() const { return this->totalWins; }

    int get_championshipsWon() const { return this->championshipsWon; }

    const Motorcycle& get_riderBike() const { return this->riderBike; }


};

void sort_leaderboards(double teamLeaderboards[11], int indexTeamLB[11]){
    for (int i=0; i<11; i++)
        indexTeamLB[i] = i;

    for (int i=0; i<10; i++)
        for (int j=i+1; j<11; j++)
            if (teamLeaderboards[i] < teamLeaderboards[j]){
                double aux = teamLeaderboards[i];
                teamLeaderboards[i] = teamLeaderboards[j];
                teamLeaderboards[j] = aux;
                aux = indexTeamLB[i];
                indexTeamLB[i] = indexTeamLB[j];
                indexTeamLB[j] = aux;
            }
}




int main(){

    //Motorcycles

    Motorcycle desmosedici(250, 1000, 350, "Ducati", "Desmosedici GP");
    Motorcycle rsgp(255, 1000, 350, "Aprilia", "RS-GP");
    Motorcycle yzrm1(240, 1000, 350, "Yamaha", "YZR-M1");
    Motorcycle rc213v(250, 1000, 350, "Honda", "RC213V");
    Motorcycle rc16(265, 1000, 355, "KTM", "RC16");

    //Sponsors

    Sponsor pertamina("Pertamina", "Money and drinks", 575000);
    Sponsor michelin("Michelin", "Money and tires", 525000);
    Sponsor redbull("Red Bull", "Money and drinks", 700000);
    Sponsor guru("Guru by Gryfyn", "Money", 675000);
    Sponsor tissot("Tissot", "Money and watches", 590000);
    Sponsor shark("Shark", "Money and helmets", 475000);
    Sponsor oakley("Oakley", "Money and equipment", 500000);
    Sponsor monster("Monster Energy", "Money and drinks", 700000);
    Sponsor liquimoly("Liqui Moly", "Money and oil", 540000);
    Sponsor motul("Motul", "Money and oil", 545000);
    Sponsor cryptodatasp("CryptoData", "Money", 750000);
    Sponsor animocabrands("Animoca Brands", "Money", 775000);
    Sponsor OR("OR", "Money, oil and fuel", 450000);
    Sponsor petronas("Petronas", "Money and lubricants", 50000);

    //Tracks

    Track trackPortugal("Autódromo Internacional do Algarve", "Portugal", 4.6, 15, 13000);
    Track trackArgentina("Termas de Río Hondo", "Argentina", 4.8, 14, 11500);
    Track trackAmerica("Circuit of The Americas", "America", 5.5, 20, 15000);
    Track trackSpain("Circuito de Jerez - Angel Nieto", "Spain", 4.4, 13, 13700);
    Track trackFrance("Le Mans", "France", 4.2, 12, 12750);
    Track trackItaly("Autodromo Internazionale del Mugello", "Italy", 5.2, 15, 13500);
    Track trackGermany("Sachsenring", "Germany", 3.7, 13, 15250);
    Track trackNetherlands("TT Circuit Assen", "Netherlands", 4.5, 18, 12100);
    Track trackKazakhstan("Sokol International Circuit", "Kazakhstan", 4.4, 13, 10300);
    Track trackBritain("Silverstone Circuit", "Great Britain", 5.9, 18, 17200);
    Track trackAustria("Red Bull Ring - Spielberg", "Austria", 4.3, 11, 14000);
    Track trackCatalunya("Circuit de Barcelona-Catalunya", "Spain-Catalunya", 4.7, 14, 14300);
    Track trackSanMarino("Misano World Circuit Marco Simoncelli", "San Marino", 4.2, 16, 9900);
    Track trackIndia("Buddh International Circuit", "India", 5, 16, 10500);
    Track trackJapan("Mobility Resort Motegi", "Japan", 4.8, 14, 18000);    
    Track trackIndonesia("Pertamina Mandalika Circuit", "Indonesia", 4.3, 17, 11200);
    Track trackAustralia("Phillip Island", "Australia", 4.4, 12, 13400);
    Track trackThailand("Chang International Circuit", "Thailand", 4.6, 12, 10900);
    Track trackMalaysia("Sepang International Circuit", "Malaysia", 5.5, 15, 9500);
    Track trackQatar("Lusail International Circuit", "Qatar", 5.4, 16, 19300);
    Track trackValencia("Circuit Ricardo Tormo", "Valencia", 4, 14, 12400);

    //Races
    
    Race racePortugal("26-03-2023", "Grande Prémio TISSOT de Portugal",trackPortugal);
    Race raceArgentina("02-04-2023", "Gran Premio Michelin® de la República Argentina", trackArgentina);
    Race raceAmerica("16-04-2023", "Red Bull Grand Prix of The Americas", trackAmerica);
    Race raceSpain("30-04-2023", "Gran Premio MotoGP™ Guru by Gryfyn de España", trackSpain);
    Race raceFrance("14-05-2023", "SHARK Grand Prix de France", trackFrance);
    Race raceItaly("11-06-2023", "Gran Premio d’Italia Oakley", trackItaly);
    Race raceGermany("18-06-2023", "Liqui Moly Motorrad Grand Prix Deutschland", trackGermany);
    Race raceNetherlands("25-06-2023", "Motul TT Assen", trackNetherlands);
    Race raceKazakhstan("09-07-2023", "Grand Prix of Kazakhstan", trackKazakhstan);
    Race raceBritain("06-08-2023", "Monster Energy British Grand Prix", trackBritain);
    Race raceAustria("20-08-2023", "CryptoDATA Motorrad Grand Prix von Österreich", trackAustria);
    Race raceCatalunya("03-09-2023", "Gran Premi Monster Energy de Catalunya", trackCatalunya);
    Race raceSanMarino("10-09-2023", "Gran Premio Red Bull di San Marino e della Riviera di Rimini", trackSanMarino);
    Race raceIndia("24-09-2023", "Grand Prix of India", trackIndia);
    Race raceJapan("01-10-2023", "Motul Grand Prix of Japan", trackJapan);
    Race raceIndonesia("15-10-2023", "Pertamina Grand Prix of Indonesia", trackIndonesia);
    Race raceAustralia("22-10-2023", "Animoca Brands Australian Motorcycle Grand Prix", trackAustralia);
    Race raceThailand("29-10-2023", "OR Thailand Grand Prix", trackThailand);
    Race raceMalaysia("12-11-2023", "PETRONAS Grand Prix of Malaysia", trackMalaysia);
    Race raceQatar("19-11-2023", "Qatar Airways Grand Prix of Qatar", trackQatar);
    Race raceValencia("26-11-2023", "Gran Premio Motul de la Comunitat Valenciana", trackValencia);

    //Teams

    Team apriliaRacing("Aprilia Racing", "Maverick Vinales", "Aleix Espargaro", 44);
    Team cryptoData("CryptoDATA RNF MotoGP™ Team", "Raul Fernandez", "Miguel Oliveira", 5);
    Team ducatiLenovo("Ducati Lenovo Team", "Francesco Bagnaia", "Enea Bastianini", 41);
    Team gasgasFactory("GASGAS Factory Racing Tech3", "Augusto Fernandez", "Pol Espargaro", 8);
    Team gresiniRacing("Gresini Racing MotoGP™", "Fabio Di Giannantonio", "Alex Marquez", 39);
    Team lcrHonda("LCR Honda", "Takaaki Nakagami", "Alex Rins", 20);
    Team monsterYamaha("Monster Energy Yamaha MotoGP™", "Fabio Quartararo", "Franco Morbidelli", 39);
    Team mooneyVR46("Mooney VR46 Racing Team", "Luca Marini", "Marco Bezzecchi", 65);
    Team primaPramac("Prima Pramac Racing", "Johann Zarco", "Jorge Martin", 57);
    Team redbullKTM("Red Bull KTM Factory Racing", "Brad Binder", "Jack Miller", 47);
    Team repsolHonda("Repsol Honda Team", "Joan Mir", "Marc Marquez", 12);

    //Riders

    Rider FrancescoBagnaia("Francesco Bagnaia", "Italy", "Ducati Lenovo Team", 26, 22, 2, desmosedici);
    Rider JohannZarco("Johann Zarco", "France", "Prima Pramac Racing", 32, 16, 2, desmosedici);
    Rider StefanBradl("Stefan Bradl", "Germany", "Repsol Honda Team", 33, 7, 1, rc213v);
    Rider LucaMarini("Luca Marini", "Italy", "Mooney VR46 Racing Team", 24, 6, 0, desmosedici);
    Rider MaverickVinales("Maverick Vinales", "Spain", "Aprilia Racing", 28, 25, 1, rsgp);
    Rider FabioQuartararo("Fabio Quartararo", "France", "Monster Energy Yamaha MotoGP™", 22, 12, 1, yzrm1);
    Rider FrancoMorbidelli("Franco Morbidelli", "Italy", "Monster Energy Yamaha MotoGP™", 28, 11, 1, yzrm1);
    Rider EneaBastianini("Enea Bastianini", "Italy", "Ducati Lenovo Team", 24, 10, 1, desmosedici);
    Rider RaulFernandez("Raul Fernandez", "Spain", "CryptoDATA RNF MotoGP Team", 22, 10, 0, rsgp);
    Rider TakaakiNakagami("Takaaki Nakagami", "Japan", "LCR Honda", 31, 2, 0, rc213v);
    Rider BradBinder("Brad Binder", "South Africa", "Red Bull KTM Factory Racing", 27, 17, 1, rc16);
    Rider JoanMir("Joan Mir", "Spain", "Repsol Honda Team", 25, 12, 2, rc213v);
    Rider AugustoFernandez("Augusto Fernandez", "Spain", "GASGAS Factory Racing Tech3", 25, 7, 1, rc16);
    Rider AleixEspargaro("Aleix Espargaro", "Spain", "Aprilia Racing", 33, 1, 0, rsgp);
    Rider AlexRins("Alex Rins", "Spain", "LCR Honda", 27, 17, 0, rc213v);
    Rider JackMiller("Jack Miller", "Australia", "Red Bull KTM Factory Racing", 28, 10, 0, rc16);
    Rider PolEspargaro("Pol Espargaro", "Spain", "GASGAS Factory Racing Tech3", 31, 15, 1, rc16);
    Rider FabioDiGiannantonio("Fabio Di Giannantonio", "Italy", "Gresini Racing MotoGP™", 24, 3, 0, desmosedici);
    Rider MichelePirro("Michele Pirro", "Italy", "Ducati Lenovo Team", 36, 1, 0, desmosedici);
    Rider MarcoBezzecchi("Marco Bezzecchi", "Italy", "Mooney VR46 Racing Team", 24, 7, 0, desmosedici);
    Rider AlexMarquez("Alex Marquez", "Spain", "Gresini Racing MotoGP™", 26, 12, 2, desmosedici);
    Rider MiguelOliveira("Miguel Oliveira", "Portugal", "CryptoDATA RNF MotoGP Team", 28, 17, 0, rsgp);
    Rider JorgeMartin("Jorge Martin", "Spain", "Prima Pramac Racing", 25, 11, 1, desmosedici);
    Rider MarcMarquez("Marc Marquez", "Spain", "Repsol Honda Team", 30, 85, 8, rc213v);
    Rider JonasFolger("Jonas Folger", "Germany", "GASGAS Factory Racing Tech3", 29, 5, 0, rc16);
 
    racePortugal.add_sponsor(tissot);
    racePortugal.set_ticketPrice(225);
    racePortugal.sell_tickets(11523);
    cout << "Portugal race profit: " << calculate_race_profit(racePortugal) << endl;

    raceArgentina.add_sponsor(michelin);
    raceArgentina.set_ticketPrice(170);
    raceArgentina.sell_tickets(9733);
    cout << "Argentina race profit: " << calculate_race_profit(raceArgentina) << endl;

    double teamLeaderboards[11];

    

    //Add points to the winning teams above ^^
    teamLeaderboards[0] = apriliaRacing.get_points();
    teamLeaderboards[1] = cryptoData.get_points();
    teamLeaderboards[2] = ducatiLenovo.get_points();
    teamLeaderboards[3] = gasgasFactory.get_points();
    teamLeaderboards[4] = gresiniRacing.get_points();
    teamLeaderboards[5] = lcrHonda.get_points();
    teamLeaderboards[6] = monsterYamaha.get_points();
    teamLeaderboards[7] = mooneyVR46.get_points();
    teamLeaderboards[8] = primaPramac.get_points();
    teamLeaderboards[9] = redbullKTM.get_points();
    teamLeaderboards[10] = repsolHonda.get_points();

    int indexTeamLB[11];

    sort_leaderboards(teamLeaderboards, indexTeamLB);

    cout << "TEAM LEADERBOARDS" << endl;
    for (int i=0; i<10; i++)
    {
        cout << teamLeaderboards[i] << " ";
        if (indexTeamLB[i] == 0) cout << apriliaRacing.get_name() << " ";
        if (indexTeamLB[i] == 1) cout << cryptoData.get_name() << " ";
        if (indexTeamLB[i] == 2) cout << ducatiLenovo.get_name() << " ";
        if (indexTeamLB[i] == 3) cout << gasgasFactory.get_name() << " ";
        if (indexTeamLB[i] == 4) cout << gresiniRacing.get_name() << " ";
        if (indexTeamLB[i] == 5) cout << lcrHonda.get_name() << " ";
        if (indexTeamLB[i] == 6) cout << monsterYamaha.get_name() << " ";
        if (indexTeamLB[i] == 7) cout << mooneyVR46.get_name() << " ";
        if (indexTeamLB[i] == 8) cout << primaPramac.get_name() << " ";
        if (indexTeamLB[i] == 9) cout << redbullKTM.get_name() << " ";
        if (indexTeamLB[i] == 10) cout << repsolHonda.get_name() << " ";
        cout << endl;         
    }


    Motorcycle newBike;
    cin >> newBike;
    newBike.set_manufacturer("BMW");
    newBike.set_model("S1000RR");
    cout << "New bike has been added: \n" << newBike << endl;

    Track newArgentinaTrack = move(trackArgentina);
    newArgentinaTrack.set_noSeats(21000);
    newArgentinaTrack.set_length(5.7);

    cout << "New Argentina track has been upgraded: \n" << newArgentinaTrack << endl;
    
}