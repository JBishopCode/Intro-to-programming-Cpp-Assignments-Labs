#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

/*
PRELAB QUESTIONS 

1. What is the difference between a protected class member and a private class member? 
    - A protected class member is basically the same thing as a private member except it can be used in derived classes.
    - In a private member, you are not able to access the member outside of the class (subclases)
    - In a protected member, you are able to access the member outside outside of the class (subclasses)

2. What is the difference between member access specification and class access specification? 
    - A member access specifier is the keywords inside of a class (eg public, private, protected)
    - A class access specifier is the access used when declaring inheritance (eg class derived : public Base, : protected Base, : priavate Base)
    - Also, a member access specifier gets declared inside the class body where as the class access specifier is written as part of the inheritance decleration

3. Explain the difference between overloading a function and redefining a function.
    - Overloading functions have the same name but different parameter types or counts (must be in same scope)
        The compiler decides which one to call at compile time (polymorphism)
    - Redefining functions have the same name, same parameters, same return type
        The derived version replaces the base version when called on a derived object
*/



//Task 1
class Restaurant{
    protected:
        string name_; // restaurant name //protected so that we can use it in derived class
        string year_; // years, assuming >0
    public:
        Restaurant() : name_(""), year_("") {} // constructor 
        Restaurant(const string& name, const string& year )  : name_(name), year_(year) {} // copy constructor (not sure why i made this)


        const string& getName() const {return name_; } //accessors
        const string& getYear() const {return year_; }

        void setName(const string& name) {name_ = name; } // mutators
        void setYear(const string& year) {year_ = year; }

        virtual void print() const{ //print function
            cout << name_ << " (EST. " << year_ << ")" << endl;
        }

        virtual ~Restaurant() = default;

};


//Task 2
class EatInRestaurant : public Restaurant {
    private: 
        int max_patrons_; // maximum number of patrons

    public:   
        EatInRestaurant() : Restaurant(), max_patrons_(0) {} //constructor
        EatInRestaurant(const string& name, const string& year, int max_patrons) : Restaurant(name, year), max_patrons_(max_patrons) {}

        int getPatrons() const {return max_patrons_; } //accesor

        void setPatrons(int max_patrons) {max_patrons_ = max_patrons; } //mutator

        void print() const override { // overrided print function
            cout << name_ << "'s maximum number of patrons allowed: " << std::to_string(max_patrons_) << endl;
        }
};


//Task 3
class DeliveryRestaurant : public Restaurant {
    private: 
        int max_delivery_; //maximum delivery distance (in kms)
    public:
        DeliveryRestaurant() : Restaurant(), max_delivery_(0) {} //constructor 
        DeliveryRestaurant(const string& name, const string& year, int max_delivery) : Restaurant(name, year), max_delivery_(max_delivery) {}

        int getDelivery() const {return max_delivery_; } //accessor

        void setDelivery(int max_delivery) {max_delivery_ = max_delivery; }  //mutators

        void print() const override {  //overrided print function 
            cout << name_ << "'s maximum delivery distance is: " << std::to_string(max_delivery_)  << " km" << endl;
        }
};


//Bonus

// This is possible but not with the current classes we have. We need to have multiple inheritance or shared subclasses.
class comboRestaurant : public Restaurant {
    private: 
        EatInRestaurant EatInPart;
        DeliveryRestaurant DeliveryPart; //creating objects of other subclasses

    public: 
        comboRestaurant(const string& name, const string& year, int max_patrons, int max_delivery) //constructor 
        : Restaurant(name, year), EatInPart(name, year, max_patrons), DeliveryPart(name, year, max_delivery) {}

        void print() const override {       //overrided print function
            cout << "Combo Restaurant: " << name_ << "Est. " << year_ << endl
            << "Max Patrons: " << EatInPart.getPatrons() << endl
            << "Max Delivery Distance: " << DeliveryPart.getDelivery() << " km" << endl;
        }

};


//Task 4
int main() {
    const int SIZE = 3;

    Restaurant* restaurants[SIZE];

    // Dynamically allocate one of each type
    restaurants[0] = new Restaurant("Plain Place", "1999");
    restaurants[1] = new EatInRestaurant("TableTop", "2010", 80);
    restaurants[2] = new DeliveryRestaurant("FastBites", "2018", 15);

    // Polymorphic calls
    for (int i = 0; i < SIZE; ++i) {
        restaurants[i]->print();
    }

    // Clean up
    for (int i = 0; i < SIZE; ++i) {
        delete restaurants[i];
    }

    return 0;
}


