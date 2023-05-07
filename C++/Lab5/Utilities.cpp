#include "TrainStation.h"
#include <random>;
#include <iostream>;
#include <locale>;
#include <string>;
#include <fstream>

int GenerateRand(int begin, int end)
{
    random_device seed;     
    mt19937 engine(seed()); 
    uniform_int_distribution<int> uniformDist(begin, end);
    return uniformDist(engine);
}

void Create_Train(Train*& train) {
    train = new Train;
}


void Create_Train_Array(Train**& trains, int size) {
    
    trains = new Train * [size];
    for (int i = 0; i < size; i++)
        Create_Train(trains[i]);
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
    if (index_ticket < 0 || index_ticket >= trains[index]->getNumTickets()) {
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

    trains[index_ticket]->getTickets()[index_ticket]->setHour(hour);
    trains[index_ticket]->getTickets()[index_ticket]->setMinute(minute);
    trains[index_ticket]->getTickets()[index_ticket]->setPrice(price);
    trains[index_ticket]->getTickets()[index_ticket]->setCityofDeparture(depart);
    trains[index_ticket]->getTickets()[index_ticket]->setCityofArrival(arrive);
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


void menu()
{

    TrainStation station;
    Train train2(*station.getTrain(0));
    Train train3;

    int choice;
    do {
        cout << "Welcome to Train Station #1" << endl;
        cout << "Choose an option:" << endl;
        cout << "1. Add train " << endl;
        cout << "2. Delete train" << endl;
        cout << "3. Edit train" << endl;
        cout << "4. Print train" << endl;
        cout << "5. Show train 1 and its copy train 2" << endl;
        cout << "6. Use operator '='" << endl;
        cout << "7. Use operator '[]'" << endl;
        cout << "8. Use operator '<<'" << endl;
        cout << "9. Use operator '>>'" << endl;
        cout << "10. Clear screen" << endl;
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
            cout << "Train 1" << endl;
            station.getTrain(0)->print();
            cout << "Train COPY 2" << endl;
            train2.print();
            break;
        }

        case 6:
        {
            train2 = train3;
            cout << "Train COPY 2" << endl;
            train2.print();
            break;
        }

        case 7:
        {
            if (train2[0] != NULL) cout << *train2[0];

            break;
        }
        case 8:
        {
            cout << train2;
            ofstream outfile("train_data.txt");

            // Write the contents of myTrain to the output file
            outfile << train2;

            outfile.close();

            break;
        }
        
        case 9:
        {
            Train train4;
            train4.print();

            ifstream infile("train_data.txt");
            infile >> train4;

            // Print the contents of the new Train object to verify that it was read correctly
            train4.print();

            infile.close();
            break;
        }

        case 10:
        {
            system("CLS");
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
    } while (choice != 0);

}