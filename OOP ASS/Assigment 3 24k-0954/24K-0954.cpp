#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>
#include<ctime>
#include<vector>
using namespace std;

template<typename T>
class EntityList{
protected:
    vector<T>items;
public:
    void add(T item){items.push_back(item);}
    T get(int index){
        if(index>=items.size())throw out_of_range("Index out of bounds");
        return items[index];}
    T findById(string id){
        for(auto&item:items)
            if(item->getId()==id)return item;
        throw runtime_error("Entity not found");}
    int size(){return items.size();}};

class User{
public:
    User(string id="",string name=""):id(id),name(name),paymentStatus(false),lastBooking(0){}
    virtual float getFare(bool isAC)=0;
    void makePayment(){paymentStatus=true;}
    bool canBook(){
        time_t now=time(0);
        tm*current=localtime(&now);
        tm*last=localtime(&lastBooking);
        return(current->tm_mon!=last->tm_mon||lastBooking==0);}
    void updateBookingTime(){lastBooking=time(0);}
    bool hasPaid(){return paymentStatus;}
    string getId(){return id;}
    string getName(){return name;}
protected:
    string id,name;
    bool paymentStatus;
    time_t lastBooking;};

class Student:public User{
public:
    Student(string id="",string name=""):User(id,name){}
    float getFare(bool AC){return AC?7000:5000;}};

class Faculty:public User{
public:
    Faculty(string id="",string name=""):User(id,name){}
    float getFare(bool AC){return AC?6000:4000;}};

class Seat{
public:
    int seatNo;
    bool isBooked;
    string userType;
    Seat():seatNo(0),isBooked(false),userType(""){}
    Seat(int no,string type):seatNo(no),userType(type),isBooked(false){}};

class Driver{
public:
    string name,licenseNo;
    bool assigned;
    Driver(string name="",string licenseNo=""):name(name),licenseNo(licenseNo),assigned(false){}};

class Route{
public:
    string start,end;
    int distance;
    Route(string s="",string e="",int d=0):start(s),end(e),distance(d){}
    bool isLong(){return distance>30;}
    void display(){
        cout<<start<<" to "<<end<<" ("<<distance<<"km)"
        <<(isLong()?" [Long Route]":"")<<endl;}};

class Vehicle{
public:
    string id,type;
    bool isAC;
    Route*route;
    Driver*driver;
    Seat seats[52];
    int totalSeats;
    Vehicle(string id="",string type="",bool ac=false,Route*r=nullptr,Driver*d=nullptr)
        :id(id),type(type),isAC(ac),route(r),driver(d){
        totalSeats=(type=="Bus")?52:32;
        for(int i=0;i<totalSeats;i++){
            seats[i]=Seat(i+1,(i<totalSeats/2)?"Student":"Faculty");}}
    Seat*getAvailableSeat(string userType){
        for(int i=0;i<totalSeats;i++){
            if(!seats[i].isBooked&&seats[i].userType==userType)
                return &seats[i];}
        throw runtime_error("No available "+userType+" seats");}
    void displaySeats(){
        cout<<"\nSeat Map for "<<id<<" ("<<type<<"):\n";
        for(int i=0;i<totalSeats;i++){
            cout<<(seats[i].isBooked?"[X]":"[ ]")<<" "
            <<seats[i].seatNo<<":"<<seats[i].userType<<"\t";
            if((i+1)%4==0)cout<<endl;}}};

class Transporter{
public:
    string name;
    EntityList<Vehicle*>vehicles;
    EntityList<Driver*>drivers;
    EntityList<Route*>routes;
    Transporter(string name=""):name(name){}
    void addVehicle(Vehicle*v){
        if(v->driver->assigned)throw runtime_error("Driver already assigned");
        v->driver->assigned=true;
        vehicles.add(v);}
    void addDriver(Driver*d){drivers.add(d);}
    void addRoute(Route*r){routes.add(r);}
    void displayRoutes(){
        cout<<"\nAvailable Routes:\n";
        for(int i=0;i<routes.size();i++){
            cout<<i+1<<". ";
            routes.get(i)->display();}}};

class Booking{
public:
    User*user;
    Vehicle*vehicle;
    Seat*seat;
    Route*route;
    Booking(User*u=nullptr,Vehicle*v=nullptr,Seat*s=nullptr,Route*r=nullptr)
        :user(u),vehicle(v),seat(s),route(r){}};

class BookingManager{
public:
    EntityList<Booking*>bookings;
    void bookSeat(User*user,Vehicle*vehicle){
        if(!user->hasPaid())throw runtime_error("Payment pending");
        if(!user->canBook())throw runtime_error("Monthly limit reached");
        string userType=dynamic_cast<Student*>(user)?"Student":"Faculty";
        Seat*seat=vehicle->getAvailableSeat(userType);
        seat->isBooked=true;
        user->updateBookingTime();
        bookings.add(new Booking(user,vehicle,seat,vehicle->route));}
    void saveBookings(string filename){
        ofstream fout(filename);
        for(int i=0;i<bookings.size();i++){
            Booking*b=bookings.get(i);
            fout<<"UserID:"<<b->user->getId()<<",Name:"<<b->user->getName()
            <<",Vehicle:"<<b->vehicle->id<<",Seat:"<<b->seat->seatNo
            <<",Route:"<<b->route->start<<"-"<<b->route->end
            <<",Fare:"<<b->user->getFare(b->vehicle->isAC)<<"\n";}
        fout.close();}
    void loadBookings(string filename){
        ifstream fin(filename);
        string line;
        cout<<"\nBooking History:\n";
        while(getline(fin,line))cout<<line<<endl;
        fin.close();}};

int main(){
    cout<<"\t\tTransport Management System\n";
    cout<<"\t\tName: Sanaullah\n\t\tRoll No: 24k-0954\n\n";
    vector<Transporter*>transporters={
        new Transporter("Nadeem Transporter"),
        new Transporter("Zulfiqar Transporter")};
    Route*routes[]={
        new Route("Gulshan","FAST Campus",35),
        new Route("DHA","FAST Campus",25),
        new Route("Bahria Town","FAST Campus",40),
        new Route("Clifton","FAST Campus",15),
        new Route("Malir","FAST Campus",45)};
    Driver*drivers[]={
        new Driver("Vivek kumar","LIC-001"),
        new Driver("kazim Mehdi","LIC-002"),
        new Driver("Muhmmad Areb","LIC-003"),
        new Driver("Danish Masood","LIC-004")};
    Vehicle*vehicles[]={
        new Vehicle("VH01","Bus",true,routes[0],drivers[0]),
        new Vehicle("VH02","Coaster",false,routes[1],drivers[1]),
        new Vehicle("VH03","Bus",true,routes[2],drivers[2]),
        new Vehicle("VH04","Coaster",true,routes[3],drivers[3]),
        new Vehicle("VH05","Bus",false,routes[4],new Driver("New Driver","LIC-005"))};
    transporters[0]->addRoute(routes[0]);
    transporters[0]->addRoute(routes[1]);
    transporters[0]->addVehicle(vehicles[0]);
    transporters[0]->addVehicle(vehicles[1]);
    transporters[0]->addDriver(drivers[0]);
    transporters[0]->addDriver(drivers[1]);
    transporters[1]->addRoute(routes[2]);
    transporters[1]->addRoute(routes[3]);
    transporters[1]->addRoute(routes[4]);
    transporters[1]->addVehicle(vehicles[2]);
    transporters[1]->addVehicle(vehicles[3]);
    transporters[1]->addVehicle(vehicles[4]);
    transporters[1]->addDriver(drivers[2]);
    transporters[1]->addDriver(drivers[3]);
    BookingManager bm;
    EntityList<User*>users;
    int choice;
    do{
        cout<<"\nMain Menu:\n1.Register User\n2.Book Seat\n3.Save Bookings\n"
            <<"4.Load Bookings\n5.View Routes\n6.View Vehicles\n0.Exit\nChoice:";
        cin>>choice;cin.ignore();
        if(choice==1){
            cout<<"1.Student\n2.Faculty\nChoice:";
            int type;cin>>type;cin.ignore();
            string id,name;
            cout<<"Enter ID:";getline(cin,id);
            cout<<"Enter Name:";getline(cin,name);
            User*u=(type==1)?(User*)new Student(id,name):new Faculty(id,name);
            users.add(u);
            cout<<"Make payment? (1=Yes/0=No):";
            int pay;cin>>pay;
            if(pay)u->makePayment();}
        else if(choice==2){
            try{
                cout<<"Enter User ID:";
                string uid;getline(cin,uid);
                User*u=users.findById(uid);
                cout<<"Available Transporters:\n";
                for(int i=0;i<transporters.size();i++)
                    cout<<i+1<<". "<<transporters[i]->name<<endl;
                cout<<"Select Transporter:";
                int tchoice;cin>>tchoice;cin.ignore();
                Transporter*t=transporters[tchoice-1];
                cout<<"Available Vehicles:\n";
                for(int i=0;i<t->vehicles.size();i++){
                    Vehicle*v=t->vehicles.get(i);
                    cout<<i+1<<". "<<v->id<<" ("<<v->type<<") - "
                        <<v->route->start<<" to "<<v->route->end
                        <<" ("<<v->route->distance<<"km)"
                        <<(v->isAC?" AC":"")<<endl;}
                cout<<"Select Vehicle:";
                int vchoice;cin>>vchoice;cin.ignore();
                Vehicle*v=t->vehicles.get(vchoice-1);
                v->displaySeats();
                bm.bookSeat(u,v);
                cout<<"\nBooking successful! Seat allocated.\n";
                v->displaySeats();}
            catch(exception&e){
                cout<<"Error:"<<e.what()<<endl;}}
        else if(choice==3){
            bm.saveBookings("bookings.txt");
            cout<<"Bookings saved!\n";}
        else if(choice==4){
            bm.loadBookings("bookings.txt");}
        else if(choice==5){
            cout<<"\nAll Routes:\n";
            for(int i=0;i<5;i++)routes[i]->display();}
        else if(choice==6){
            cout<<"\nAll Vehicles:\n";
            for(int i=0;i<5;i++){
                cout<<i+1<<". "<<vehicles[i]->id<<" ("<<vehicles[i]->type<<") - "
                    <<vehicles[i]->route->start<<" to "<<vehicles[i]->route->end<<endl;}}}
    while(choice!=0);
    for(auto t:transporters)delete t;
    for(auto r:routes)delete r;
    for(auto d:drivers)delete d;
    for(auto v:vehicles){
        if(v->driver->licenseNo!="LIC-005")delete v->driver;
        delete v;}
    return 0;}

