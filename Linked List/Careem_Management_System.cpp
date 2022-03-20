#include <iostream>

using namespace std;

struct Ride
{
    int ride_id;
    string rider_name;
    int km;
    int charges;
    Ride *next_ride = NULL;
};

struct Car
{
    int car_id;
    string driver_name;
    string car_name;
    string reg_number;
    int car_type;
    Car *car_next = NULL;
    Car *car_pre = NULL;
    Ride *ride_first = NULL;
    Ride *ride_last = NULL;
};

Car *first = NULL;
Car *last = NULL;

void display_cars();
void display_rides();
void display_type2();
void display_earning();
void display_earning_all();
void add_car();
void add_ride();

int main()
{
    int exit;

    do
    {
        cout << "Enter number to perform task\n"
             << "1. Register a new car\n"
             << "2. Display details of all cars\n"
             << "3. Display type 2 cars\n"
             << "4. Add new ride\n"
             << "5. Display rides with details\n"
             << "6. Total earning of a specific car\n"
             << "7. Display earnings of all cars\n"
             << "0. Exit\n";
        cin >> exit;
        switch (exit)
        {
        case 1:
            add_car();
            break;
        case 2:
            display_cars();
            break;
        case 3:
            display_type2();
            break;
        case 4:
            add_ride();
            break;
        case 5:
            display_rides();
            break;
        case 6:
            display_earning();
            break;
        case 7:
            display_earning_all();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "INVALID INPUT\n";
            break;
        }
    } while (exit != 0);
}

void add_car()
{
    cout << "\n";
    Car *p = new Car;
    cout << "Enter Driver name: ";
    cin >> p->driver_name;
    cout << "Enter car name: ";
    cin >> p->car_name;
    cout << "Enter car type: ";
    cin >> p->car_type;
    cout << "Enter Reg number: ";
    cin >> p->reg_number;
    cout << "\n";

    if (first == NULL)
    {
        p->car_id = 1;
        first = last = p;
    }
    else
    {
        p->car_id = last->car_id + 1;
        last->car_next = p;
        p->car_pre = last;
        last = p;
    }
}

void display_cars()
{
    Car *p = first;
    while (p != NULL)
    {
        cout << "\n";
        cout << "Car ID: " << p->car_id << "\n"
             << "Car Name: " << p->car_name << "\n"
             << "Driver Name: " << p->driver_name << "\n"
             << "Car Type: " << p->car_type << "\n"
             << "Reg Number: " << p->reg_number << "\n";
        p = p->car_next;
    }
    cout << "\n";
}

void display_type2()
{
    Car *p = first;
    while (p != NULL)
    {
        if (p->car_type == 2)
        {
            cout << "\n";
            cout << "Car ID: " << p->car_id << "\n"
                 << "Car Name: " << p->car_name << "\n"
                 << "Driver Name: " << p->driver_name << "\n"
                 << "Car Type: " << p->car_type << "\n"
                 << "Reg Number: " << p->reg_number << "\n";
        }
        p = p->car_next;
    }
    cout << "\n";
}

void add_ride()
{
    cout << "\n";
    int id;
    cout << "Enter car id: ";
    cin >> id;
    cout << "\n";
    Car *p = first;
    while (p->car_id != id && p != NULL)
    {
        p = p->car_next;
    }
    if (p == NULL)
    {
        cout << "Car not found\n";
        return;
    }
    else
    {
        Ride *r = new Ride;
        cout << "Enter Rider name: ";
        cin >> r->rider_name;
        cout << "Enter km: ";
        cin >> r->km;
        cout << "Enter Charges: ";
        cin >> r->charges;
        cout << "\n";

        if (p->ride_first == NULL)
        {
            r->ride_id = 1;
            p->ride_first = p->ride_last = r;
        }
        else
        {
            r->ride_id = p->ride_last->ride_id + 1;
            p->ride_last->next_ride = r;
            p->ride_last = r;
        }
    }
}

void display_rides()
{
    cout << "\n";
    int id;
    cout << "Enter car id: ";
    cin >> id;
    cout << "\n";
    Car *p = first;
    while (p->car_id != id && p != NULL)
    {
        p = p->car_next;
    }
    if (p == NULL)
    {
        cout << "Car not found\n";
        return;
    }
    else
    {
        Ride *r = p->ride_first;
        while (r != NULL)
        {
            cout << "\n";
            cout << "Ride ID: " << r->ride_id << "\n"
                 << "Rider Name: " << r->rider_name << "\n"
                 << "Ride Charges: " << r->charges << "\n"
                 << "km driven: " << r->km << "\n";
            r = r->next_ride;
        }
    }
    cout << "\n";
}

void display_earning()
{
    int earning = 0;
    cout << "\n";
    int id;
    cout << "Enter car id: ";
    cin >> id;
    cout << "\n";
    Car *p = first;
    while (p->car_id != id && p != NULL)
    {
        p = p->car_next;
    }
    if (p == NULL)
    {
        cout << "Car not found\n";
        return;
    }
    else
    {
        Ride *r = p->ride_first;
        while (r != NULL)
        {
            earning += r->charges;
            r = r->next_ride;
        }
    }
    cout << "Total earning of this car is Rs " << earning << "\n\n";
}

void display_earning_all()
{
    int earning = 0;
    Car *c = first;
    Ride *r = c->ride_first;
    while (c != NULL)
    {
        while (r != NULL)
        {
            earning += r->charges;
            r = r->next_ride;
        }
        c = c->car_next;
        if (c != NULL)
        {
            r = c->ride_first;
        }
    }
    cout << "\nTotal earnings are Rs " << earning << "\n\n";
}