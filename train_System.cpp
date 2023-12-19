#include <iostream>
using namespace std;
class Person
{
public:
    string Name;
    int Age;
    char Gender;
};
class Adult : public Person
{
    string Occupation;
    string Qualification;
    string NIC;
  public:Adult()
    {
        cout << 'Enter passenger Name:' << endl;
        cin >> this->Name;
        cout << 'Enter passenger Age:' << endl;
        cin >> this->Age;
        cout << 'Enter passenger Gender:' << endl;
        cin >> this->Gender;
        cout << 'Enter passenger Occupation:' << endl;
        cin >> this->Occupation;
        cout << 'Enter passenger Qualification:' << endl;
        cin >> this->Qualification;
        cout << 'Enter passenger NIC:' << endl;
        cin >> this->NIC;
    }
};
class Kid : public Person
{
    string B_form_number;

public:
   public: Kid()
    {
        cout << 'Enter passenger Name:' << endl;
        cin >> this->Name;
        cout << 'Enter passenger Age:' << endl;
        cin >> this->Age;
        cout << 'Enter passenger Gender:' << endl;
        cin >> this->Gender;
        cout << 'Enter passenger B_Form Number:' << endl;
        cin >> this->B_form_number;
    }
};
class Bogie
{
public:
    int Bogie_ID;
    Bogie *next;
    Person *Adults[6];
    Person *Kids[4];
    string familyName;

public:
    Bogie(int id)
    {
        this->next = nullptr;
        this->Bogie_ID = id;

        for (int i = 0; i < 6; i++)
        {
            this->Adults[i] = nullptr;
        }

        for (int i = 0; i < 4; i++)
        {
            this->Kids[i] = nullptr;
        }
    }
    bool AddPassengers()
    {
        char temp;
        cout << "Press K for Kid and A for Adult:";
        cin >> temp;
        bool isAdultAdd, isKidAdd = false;
         Adult  *newPasenger = new Adult();
        if (temp == 'A')
        {
          
            for (int i = 0; i < 6; i++)
            {
                if (Adults[i] == nullptr)
                {
                    Adults[i] = newPasenger;
                    isAdultAdd = true;
                }
            }
        }
        else if (temp == 'K')
        {
            Kid *newPassenger = new Kid();
            for (int i = 0; i < 6; i++)
            {
                if (Kids[i] == nullptr)
                {
                    Kids[i] = newPassenger;
                    isKidAdd = true;
                }
            }
        }

        if (!isAdultAdd && !isKidAdd)
        {
            cout << "fuking boogie is full" << endl;
            return false;
        }
        else
        {
            return true;
        }

    } // should add adults and kids information etc
    void Print();
    ~Bogie();
};
class Train
{
    Bogie *engine;

public:
    Train()
    {
        engine = nullptr;
    }
    void addBogie(int ID)
    {

        if (engine == nullptr)
        {
            engine = new Bogie(ID);
            
        }
        else
        {
            Bogie *current = engine;
            if (current->AddPassengers())
            {
                cout << "Passenger Added to Boogie Number:" << current->Bogie_ID;
                cout << "Passenger Name:" <<current->Adults[0]->Name; 
                
            }

            while (current != nullptr)
            {
                current = current->next;
            }
            Bogie *newBogie = new Bogie(ID);
            newBogie->next = nullptr;
            current = newBogie;
        }

    }                         // add bogie at the end of the train
    bool removeBogie(int ID); // search the bogie and delete it
    void printTrain();        // print only the Bogie_ID of all bogies
    bool SearchBogie(int ID); // search the particular bogie
    ~Train();
};
int main()
{
    Train train;
    train.addBogie(123);
    return 0;
}