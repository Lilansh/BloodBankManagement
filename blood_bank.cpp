#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Donor
{
public:
    string name;
    int age;
    string bloodGroup;
    string contact;

    Donor(string n, int a, string bg, string c)
    {
        name = n;
        age = a;
        bloodGroup = bg;
        contact = c;
    }
};

vector<Donor> donors;

map<string, int> bloodStock = {
    {"A+", 0},
    {"A-", 0},
    {"B+", 0},
    {"B-", 0},
    {"AB+", 0},
    {"AB-", 0},
    {"O+", 0},
    {"O-", 0}};

void addDonor()
{
    string name, bg, contact;
    int age;

    cout << "\nEnter Donor Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Age:";
    cin >> age;

    if (age < 18 || age > 65)
    {
        cout << "Donor age must be between 18 and 65." << endl;
        return;
    }

    cout << "Enter Blood Group: ";
    cin >> bg;

    if (bloodStock.find(bg) == bloodStock.end())
    {
        cout << "Invalid Blood Group." << endl;
        return;
    }

    cout << "Enter Contact Number: ";
    cin >> contact;

    donors.push_back(Donor(name, age, bg, contact));
    bloodStock[bg]++;

    cout << "Donor added successfully!" << endl;
}

void displayDonors()
{
    if (donors.empty())
    {
        cout << "No donors available." << endl;
        return;
    }

    cout << "\n------------ Donor List --------------\n";
    for (int i = 0; i < donors.size(); i++)
    {
        cout << "\nDonor" << i + 1 << endl;
        cout << "Name:" << donors[i].name << endl;
        cout << "Age:" << donors[i].age << endl;
        cout << "Blood Group:" << donors[i].bloodGroup << endl;
        cout << "Contact:" << donors[i].contact << endl;
    }
}

void searchByBloodGroup()
{
    string bg;
    cout << "\nEnter Blood Group to Search: ";
    cin >> bg;

    bool found = false;
    for (auto &donor : donors)
    {
        if (donor.bloodGroup == bg)
        {
            cout << "\nName:" << donor.name << endl;
            cout << "Age:" << donor.age << endl;
            cout << "Contact:" << donor.contact << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No donors found with Blood Group " << bg << endl;
    }
}

void viewBloodStock()
{
    cout << "\n------- Blood Stock -------\n";
    for (auto &entry : bloodStock)
    {
        cout << "Blood Group: " << entry.first << " | Units Available: " << entry.second << endl;
    }
}

void issueBloodStock()
{
    string bg;
    int units;

    cout << "\nEnter Blood Group to Issue: ";
    cin >> bg;
    cout << "Enter Units to Issue: ";
    cin >> units;

    if (bloodStock.find(bg) == bloodStock.end())
    {
        cout << "Invalid Blood Group." << endl;
        return;
    }

    if (bloodStock[bg] < units)
    {
        cout << "Insufficient stock for Blood Group " << bg << endl;
        return;
    }

    bloodStock[bg] -= units;
    cout << "Issued " << units << " units of Blood Group " << bg << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n\n===== Blood Bank Management System =====\n";
        cout << "1. Add Donor\n";
        cout << "2. Display All Donors\n";
        cout << "3. Search Donor by Blood Group\n";
        cout << "4. View Blood Stock\n";
        cout << "5. Issue Blood\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addDonor();
            break;
        case 2:
            displayDonors();
            break;
        case 3:
            searchByBloodGroup();
            break;
        case 4:
            viewBloodStock();
            break;
        case 5:
            issueBloodStock();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}