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
    char* weather;
    Track track;
    int numSponsors;
    int sponsorsAmount;
    double ticketPrice;
    int ticketsSold;

public:
    //Constructors

    Race(const char* date, const char* weather, Track track, int numSponsors, int sponsorsAmount, double ticketPrice, int ticketsSold){
        this->date = new char[strlen(date) + 1];
        strcpy(this->date, date);
        this->weather = new char[strlen(weather) + 1];
        strcpy(this->weather, weather);
        this->track = track;
        this->numSponsors = numSponsors;
        this->sponsorsAmount = sponsorsAmount;
        this->ticketPrice = ticketPrice;
        this->ticketsSold = ticketsSold;
    }

    Race(const char* date, const char* weather, Track track){
        this->date = new char[strlen(date) + 1];
        strcpy(this->date, date);
        this->weather = new char[strlen(weather) + 1];
        strcpy(this->weather, weather);
        this->track = track;
        numSponsors = 0;
        sponsorsAmount = 0;
        ticketPrice = 0;
        ticketsSold = 0;
    }

    Race(const char* date, Track track){
        this->date = new char[strlen(date) + 1];
        strcpy(this->date, date);
        this->weather = new char[1];
        weather[0] = '\0';
        this->track = track;
        numSponsors = 0;
        sponsorsAmount = 0;
        ticketPrice = 0;
        ticketsSold = 0;
    }

    Race(const Race& race){         //Copy constructor
        this->date = new char[strlen(race.date) + 1];
        strcpy(this->date, race.date);
        this->weather = new char[strlen(race.weather) + 1];
        strcpy(this->weather, race.weather);
        track = race.track;
        sponsorsAmount = race.sponsorsAmount;
        numSponsors = race.numSponsors;
        ticketPrice = race.ticketPrice;
        ticketsSold = race.ticketsSold;
    }

    Race(){
        this->date = new char[1];
        date[0] = '\0';
        this->weather = new char[1];
        weather[0] = '\0';
        numSponsors = 0;
        sponsorsAmount = 0;
        ticketPrice = 0;
        ticketsSold = 0;
    }

    //Destructor

    ~Race(){
        delete[] date;
        delete[] weather;
    }

    Race& operator=(const Race& race){        // "=" operator overload
        if (this != &race){
            delete[] this->date;
            this->date = new char[strlen(race.date) + 1];
            strcpy(this->date, race.date);
            delete[] this->weather;
            this->weather = new char[strlen(race.weather) + 1];
            strcpy(this->weather, race.weather);
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
        out << "Weather: " << race.weather << endl;
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

    void set_weather(const char* weather){
        delete[] this->weather;
        this->weather = new char[strlen(weather) + 1];
        strcpy(this->weather, weather);
    }

    void set_track(const Track& track) { this->track = track; }

    void set_sponsorsAmount(int sponsorsAmount) { this->sponsorsAmount = sponsorsAmount; }

    void set_numSponsors(int numSponsors) { this->numSponsors = numSponsors; }

    void set_ticketPrice(double ticketPrice) { this->ticketPrice = ticketPrice; }

    void set_ticketsSold(int ticketsSold) { this->ticketsSold = ticketsSold; }

    //Getters

    const char* get_date() const { return this->date; }

    const char* get_weather() const { return this->weather; }

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


class Rider{
    char* name;
    char* nationality;
    int age;
    int noWins;
    int totalChampionships;
    Team team;
    Motorcycle bike;

public:
    //Constructors

    Rider(const char* name, const char* nationality, int age, int noWins, int totalChampionships, Team team, Motorcycle bike){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->nationality = new char[strlen(nationality) + 1];
        strcpy(this->nationality, nationality);
        this->age = age;
        this->noWins = noWins;
        this->totalChampionships = totalChampionships;
        this->team = team;
        this->bike = bike;
    }

    Rider(const char* name, const char* nationality, int age, Team team){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->nationality = new char[strlen(nationality) + 1];
        strcpy(this->nationality, nationality);
        this->age = age;
        noWins = 0;
        totalChampionships = 0;
        this->team = team;
    }

    Rider(const char* name, const char* nationality, int age){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->nationality = new char[strlen(nationality) + 1];
        strcpy(this->nationality, nationality);
        age = 0;
        noWins = 0;
        totalChampionships = 0;
    }

    Rider(const Rider& rider){          //Copy constructor
        name = new char[strlen(rider.name) + 1];
        strcpy(name, rider.name);
        nationality = new char[strlen(rider.nationality) + 1];
        strcpy(nationality, rider.nationality);
        age = rider.age;
        noWins = rider.noWins;
        totalChampionships = rider.totalChampionships;
        team = rider.team;
        bike = rider.bike;
    }

    Rider(){
        name = new char[1];
        name[0] = '\0';
        nationality = new char[1];
        nationality[0] = '\0';
        age = 0;
        noWins = 0;
        totalChampionships = 0;
    }

    //Destructor

    ~Rider(){
        delete[] name;
        delete[] nationality;
    }

    Rider& operator=(const Rider& rider){       // "=" operator overload
        if (this != &rider){
            delete[] name;
            name = new char[strlen(rider.name) + 1];
            strcpy(name, rider.name);
            delete[] nationality;
            nationality = new char[strlen(rider.nationality) + 1];
            age = rider.age;
            noWins = rider.noWins;
            totalChampionships = rider.totalChampionships;
            team = rider.team;
            bike = rider.bike;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Rider& rider){       // "<<" operator overload
        out << "Name: " << rider.name << endl;
        out << "Nationality: " << rider.nationality << endl;
        out << "Age: " << rider.age << endl;
        out << "Number of wins: " << rider.noWins << endl;
        out << "Total championships won: " << rider.totalChampionships << endl;
        out << "TEAM \n" << rider.team << endl;
        out << "BIKE \n" << rider.bike << endl;
        return out;
    }

    //Setters

    void set_name(const char* name){
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void set_nationality(const  char* nationality){
        delete[] this->nationality;
        this->nationality = new char[strlen(nationality) + 1];
        strcpy(this->nationality, nationality);
    }

    void set_age(int age) { this->age = age; }

    void set_noWins(int noWins) { this->noWins = noWins; }

    void set_totalChampionships(int totalChampionships) { this->totalChampionships = totalChampionships; }

    void set_team(const Team& team) { this->team = team; }

    void set_bike(const Motorcycle& bike) { this->bike = bike; }

    //Getters

    const char* get_name() const { return this->name; }

    const char* get_nationality() const { return this->nationality; }

    int get_age() const { return this->age; }

    int get_noWins() const { return this->noWins; }

    int get_totalChampionships() const { return this->totalChampionships; }

    Team get_team() const { return this->team; }

    Motorcycle get_bike() const { return this->bike; }


};


class Team{
    char* name;
    Rider rider1;
    Rider rider2;
    double points;

public:
    //Constructors

    Team(const char* name, Rider rider1, Rider rider2, double points){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->rider1 = rider1;
        this->rider2 = rider2;
        this->points = points;
    }

    Team(const char* name, Rider rider1, Rider rider2){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->rider1 = rider1;
        this->rider2 = rider2;
        points = 0;
    }

    Team(const Team& team){         //Copy constructors
        name = new char[strlen(team.name) + 1];
        strcpy(name, team.name);
        rider1 = team.rider1;
        rider2 = team.rider2;
        points = team.points;
    }

    Team(){
        name = new char[1];
        name[0] = '\0';
        points = 0;
    }

    //Destructor

    ~Team(){
        delete[] name;
    }

    Team& operator=(const Team& team){      // "=" operator overload
        if (this != &team){
            delete[] this->name;
            name = new char[strlen(team.name) + 1];
            strcpy(name, team.name);
            rider1 = team.rider1;
            rider2 = team.rider2;
            points = team.points;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Team& team){     // "<<" operator overload
        out << "Name: " << team.name << endl;
        out << "FIRST RIDER \n" << team.rider1 << endl;
        out << "SECOND RIDER \n" << team.rider2 << endl;
        out << "Points " << team.points << endl;
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

    void set_rider1(const Rider& rider1) { this->rider1 = rider1; }

    void set_rider2(const Rider& rider2) { this->rider2 = rider2; }

    void set_points(double points) { this->points = points; }

    //Getters

    const char* get_name() { return name; }

    Rider get_rider1() { return rider1; }

    Rider get_rider2() { return rider2; }

    double get_points() { return points; }


};


int main(){

    //Motorcycles

    Motorcycle(250, 1000, 350, "Ducati", "Desmosedici GP");
    Motorcycle(255, 1000, 350, "Aprilia", "RS-GP");
    Motorcycle(240, 1000, 350, "Yamaha", "YZR-M1");
    Motorcycle(250, 1000, 350, "Honda", "RC213V");
    Motorcycle(265, 1000, 355, "KTM", "RC16");

    //Sponsors

    Sponsor("Pertamina", "Money and drinks", 575000);
    Sponsor("Michelin", "Money and tires", 525000);
    Sponsor("Red Bull", "Money and drinks", 700000);
    Sponsor("Guru by Gryfyn", "Money", 675000);
    Sponsor("Tissot", "Money and watches", 590000);
    Sponsor("Shark", "Money and helmets", 475000);
    Sponsor("Oakley", "Money and equipment", 500000);
    Sponsor("Monster Energy", "Money and drinks", 700000);
    Sponsor("Liqui Moly", "Money and oil", 540000);
    Sponsor("Motul", "Money and oil", 545000);
    Sponsor("CryptoData", "Money", 750000);
    Sponsor("Animoca Brands", "Money", 775000);
    Sponsor("OR", "Money, oil and fuel", 450000);
    Sponsor("Petronas", "Money and lubricants", 50000);

    //Tracks

    Track("GRANDE PRÉMIO TISSOT DE PORTUGAL", "Portugal", 4.6, 15, 13000);
    Track("GRAN PREMIO MICHELIN® DE LA REPÚBLICA ARGENTINA", "Argentina", 4.8, 14, 11500);
    Track("RED BULL GRAND PRIX OF THE AMERICAS", "America", 5.5, 20, 15000);
    Track("GRAN PREMIO MOTOGP™ GURU BY GRYFYN DE ESPAÑA", "Spain", 4.4, 13, 13700);
    Track("SHARK GRAND PRIX DE FRANCE", "France", 4.2, 12, 12750);
    Track("GRAN PREMIO D’ITALIA OAKLEY", "Italy", 5.2, 15, 13500);
    Track("LIQUI MOLY MOTORRAD GRAND PRIX DEUTSCHLAND", "Germany", 3.7, 13, 15250);
    Track("MOTUL TT ASSEN", "Netherlands", 4.5, 18, 12100);
    Track("GRAND PRIX OF KAZAKHSTAN", "Kazakhstan", 4.4, 13, 10300);
    Track("MONSTER ENERGY BRITISH GRAND PRIX", "Great Britain", 5.9, 18, 17200);
    Track("CRYPTODATA MOTORRAD GRAND PRIX VON ÖSTERREICH", "Austria", 4.3, 11, 14000);
    Track("GRAN PREMI MONSTER ENERGY DE CATALUNYA", "Spain-Catalunya", 4.7, 14, 14300);
    Track("GRAN PREMIO RED BULL DI SAN MARINO E DELLA RIVIERA DI RIMINI", "San Marino", 4.2, 16, 9900);
    Track("GRAND PRIX OF INDIA", "India", 5, 16, 10500);
    Track("MOTUL GRAND PRIX OF JAPAN", "Japan", 4.8, 14, 18000);    
    Track("PERTAMINA GRAND PRIX OF INDONESIA", "Indonesia", 4.3, 17, 11200);
    Track("ANIMOCA BRANDS AUSTRALIAN MOTORCYCLE GRAND PRIX", "Australia", 4.4, 12, 13400);
    Track("OR THAILAND GRAND PRIX", "Thailand", 4.6, 12, 10900);
    Track("PETRONAS GRAND PRIX OF MALAYSIA", "Malaysia", 5.5, 15, 9500);
    Track("QATAR AIRWAYS GRAND PRIX OF QATAR", "Qatar", 5.4, 16, 19300);
    Track("GRAN PREMIO MOTUL DE LA COMUNITAT VALENCIANA", "Valencia", 4, 14, 12400);


    //Races

    

}