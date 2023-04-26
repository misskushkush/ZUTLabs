#include "TrainStation.h"
#include <random>;
#include <iostream>;
#include <locale>;
#include <string>;

int GenerateRand(int begin, int end)
{
    random_device seed;     
    mt19937 engine(seed()); 
    uniform_int_distribution<int> uniformDist(begin, end);
    return uniformDist(engine);
}


void Create_Random_Ticket(Ticket* ticket) {
    ticket->setHour(GenerateRand(0, 23));
    ticket->setMinute(GenerateRand(0, 59));
    ticket->setPrice(GenerateRand(50, 350));
    string cities[] = { "New York", "Washington D.C.", "Los Angeles", "San Francisco", "Chicago", "Houston" };
    int depindex = GenerateRand(0, 5);
    int arrindex = GenerateRand(0, 5);
    while (depindex == arrindex) {
        arrindex = GenerateRand(0, 5);
    }
    ticket->setCityofDeparture(cities[depindex]);
    ticket->setCityofArrival(cities[arrindex]);
}


void Init_Ticket_Array(Ticket** tickets, int size) {
    for (int i = 0; i < size; i++) {
        Create_Random_Ticket(tickets[i]);
    }
}

void Create_Ticket(Ticket*& ticket) {
    ticket = new Ticket;
}

void Create_Train(Train*& train) {
    train = new Train;
}


void Create_Ticket_Array(Ticket**& tickets, int size) {
    tickets = new Ticket * [size];
    for (int i = 0; i < size; i++)
        Create_Ticket(tickets[i]);
}

void Create_Train_Array(Train**& trains, int size) {
    
    trains = new Train * [size];
    for (int i = 0; i < size; i++)
        Create_Train(trains[i]);
}


void Delete_Ticket_Array(Ticket**& tickets, int& size) {
    for (int i = 0; i < size; i++) {
        delete tickets[i];
        cout << "Ticket" << i + 1 << "deleted\n";
    }
    delete[] tickets;
    tickets = nullptr;
    size = 0;
}

void Delete_Train_Array(Train**& trains, int& size) {
    for (int i = 0; i < size; i++) {
        delete trains[i];
        cout << "Train" << i + 1 << "deleted\n";
    }
    delete[] trains;
    trains = nullptr;
    size = 0;
}

void Delete_Train_From_Array(Train**& trains, int& size, int index) {
    if (index < 0 || index >= size) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    delete trains[index];
    for (int i = index; i < size - 1; i++) {
        trains[i] = trains[i + 1];
    }
    trains[size - 1] = new Train();
    size--;
}

void Edit_Ticket(Ticket** tickets, int size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid ticket index." << endl;
        return;
    }

    int hour, minute;
    double price;
    string arrive, depart;

    cout << "Enter the details for the new ticket:" << endl;
    cin.ignore();
    // Get input for hour and minute
    string timeInput;
    getline(cin, timeInput);
    size_t timePos = timeInput.find(":");
    hour = stoi(timeInput.substr(0, timePos));
    minute = stoi(timeInput.substr(timePos + 1));

    // Get input for price
    string priceInput;
    getline(cin, priceInput);
    price = stod(priceInput);

    // Get input for depart and arrive
    getline(cin, depart);
    getline(cin, arrive);

    if (tickets[index] == nullptr) {
        tickets[index] = new Ticket(hour, minute, price, depart, arrive);
    }
    else {
        tickets[index]->setHour(hour);
        tickets[index]->setMinute(minute);
        tickets[index]->setPrice(price);
        tickets[index]->setCityofDeparture(depart);
        tickets[index]->setCityofArrival(arrive);
    }
}

void Edit_Train(Train**& trains, int size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid train index." << endl;
        return;
    }
    int per_num;
    cout << "Enter new personal number for Train: ";
    cin >> per_num;
    trains[index]->setPersonalNumber(to_string(per_num));

    int index_ticket;
    cout << "Enter ticket index to edit: ";
    cin >> index_ticket;
    Edit_Ticket(trains[index]->getTickets(), trains[index]->getNumTickets(), index_ticket);
}


void Add_Train(Train**& trains, int& size) {
    Train** newTrains = new Train * [size + 1];
    for (int i = 0; i < size; i++) {
        newTrains[i] = trains[i];
    }

    Create_Train(newTrains[size]);
    delete[] trains;
    trains = newTrains;
    size++;
}

void Print_Train_Array(Train** trains, int size) {
    cout << "Train Station with " << size << " trains:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Train " << i + 1 << ":" << endl;
        trains[i]->print();
    }
}

void Print_Ticket_Array(Ticket** tickets, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Ticket " << i + 1 << ":" << endl;
        tickets[i]->print();
    }
}

void menu()
{

    TrainStation station;
    
    Ticket ticket1;
    Ticket ticket2;

    ticket2 = ticket1;

    int choice;
    do{
        cout << "Welcome to Train Station #1" << endl;
        cout << "Choose an option:" << endl;
        cout << "1. Add train " << endl;
        cout << "2. Delete train" << endl;
        cout << "3. Edit train" << endl;
        cout << "4. Print train" << endl;
        cout << "5. Show ticket 1" << endl;
        cout << "6. Change ticket 1 and copy" << endl;
        cout << "7. Clear screen" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1: { // add train

            station.addTrain();
            station.print();
            break;
        }
        case 2: { // delete train
            int index;
            cout << "Enter the index of the train to delete: " << endl;
            cin >> index;
            station.deleteTrain(index);
            cout << "Train deleted." << endl;

            station.print();
            break;
        }
        case 3: { // edit train
            int index;
            cout << "Enter the index of the train to edit: " << endl;
            cin >> index;
            station.editTrain(index);
            station.print();
            break;
        }
        case 4: {
            station.print();
            break;
        }
        case 5: {
            cout << "Ticket 1 before change" << endl;
            ticket1.print();
            break;
        }

        case 6:
        {   ticket1.setCityofArrival("AAAAAAA");
            ticket1.setCityofDeparture("BBBBBBB");  
            cout << "Ticket 1 changed"<<endl;
            ticket1.print();
            cout << "Tikcet 2 copy did not change" << endl;
            ticket2.print();
            break;
        }

        case 7:
        {
            system("CLS");
            break;
        }
        case 0:
        {
            system("CLS");
            break;
        }

        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }while (choice != 0);

}