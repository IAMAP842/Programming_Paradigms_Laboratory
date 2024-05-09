#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
private:
    double Price;
    string Manufacturer;

public:
    Vehicle() : Price(0.0), Manufacturer("") {}

    Vehicle(double p, string s) : Price(p), Manufacturer(s) {}

    Vehicle(const Vehicle &other) : Price(other.Price), Manufacturer(other.Manufacturer) {}

    Vehicle &operator=(const Vehicle &other)
    {
        if (this != &other)
        {
            Price = other.Price;
            Manufacturer = other.Manufacturer;
        }
        return *this;
    }

    void readData()
    {
        cout << "Enter price: ";
        cin >> Price;
        cout << "Enter manufacturer: ";
        cin >> Manufacturer;
    }

    void Display()
    {
        cout << "Price : " << Price << endl;
        cout << "Manufacturer : " << Manufacturer << endl;
    }
};

class Car : public Vehicle
{
private:
    string Color;
    int NumberOfSeats;
    string Model;

public:
    Car() : Color(""), NumberOfSeats(0), Model("") {}

    Car(string c, int num, string m) : Vehicle(0, ""), Color(c), NumberOfSeats(num), Model(m) {}

    Car(const Car &other) : Vehicle(other), Color(other.Color), NumberOfSeats(other.NumberOfSeats), Model(other.Model) {}

    Car &operator=(const Car &other)
    {
        if (this != &other)
        {
            Vehicle::operator=(other);
            Color = other.Color;
            NumberOfSeats = other.NumberOfSeats;
            Model = other.Model;
        }
        return *this;
    }

    void readData()
    {
        Vehicle::readData();
        cout << "Enter color: ";
        cin >> Color;
        cout << "Enter number of seats: ";
        cin >> NumberOfSeats;
        cout << "Enter model: ";
        cin >> Model;
    }

    void Display()
    {
        Vehicle::Display();
        cout << "Color : " << Color << endl;
        cout << "NumberOfSeats : " << NumberOfSeats << endl;
        cout << "Model : " << Model << endl;
    }
};

int main()
{
    cout << "Vehicle:\n";
    Vehicle vehicle1;
    cout << "\nDisplaying Vehicle information:\n";
    vehicle1.Display();

    cout << "\nSetting Vehicle information\n";
    vehicle1.readData();
    cout << "\nDisplaying Vehicle information:\n";
    vehicle1.Display();
    cout << "\nCreating a Vehicle using copy constructor\n";
    Vehicle vehicle2(vehicle1);
    cout << "\nDisplaying Vehicle information for vehicle2 (created using copy constructor):\n";
    vehicle2.Display();

    cout << "\nCreating a Vehicle using assignment operator\n";
    Vehicle vehicle3;
    vehicle3 = vehicle1;
    cout << "\nDisplaying Vehicle information for vehicle3 (created using assignment operator):\n";
    vehicle3.Display();

    cout << "\nCreating a Car\n";
    Car car1;
    cout << "\nDisplaying Car information:\n";
    car1.Display();

    cout << "\nSetting Car information\n";
    car1.readData();
    cout << "\nDisplaying Car information:\n";
    car1.Display();

    cout << "\nCreating a Car using copy constructor\n";
    Car car2 = car1;
    cout << "\nDisplaying Car information for car2 (created using copy constructor):\n";
    car2.Display();

    cout << "\nCreating a Car using assignment operator\n";
    Car car3;
    car3 = car1;
    cout << "\nDisplaying Car information for car3 (created using assignment operator):\n";
    car3.Display();

    return 0;
}