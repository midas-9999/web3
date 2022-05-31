#include<iostream>
#include<conio.h>  //for getchr
#include<math.h>
#include<windows.h> //for system clear better view 

using namespace std;
//creating a class loan 
class LOAN {
    private:
        int total, Cash;
    string id;
    struct person {
        string name, ID, address;
        long int contact, cash, time_for_deposition;
        double intrest_rate;
    }
    person[100];
    public:
        LOAN() {
            total = 0;
        }
    void choice();
    void perData();
    void searchbyid();
    void searchbycash();
    void intrest();
    void intrest(int);
};

// main function (nothing much inside it as it is not a logical paradigm)
int main() {
    LOAN b;
    b.choice();
    return 0;
}
///main user interface with the choices we can give 

void LOAN::choice() {
    char ch, ch2;
    while (1) {
        system("CLS");
        cout << "Welcome to Aryan exchange system\n" << endl;
        cout << "Please choose your identity" << endl;
        cout << "1. Lender" << endl;
        cout << "2. Borrower" << endl;
        cin >> ch2;

        // thsi is made for the lenders 
        if (ch2 == '1') {
            system("CLS");
            cout << "Hello Lender choose the sevice you want\n" << endl;
            cout << "1. Create new account" << endl;
            cout << "2. Check the details of an existing account by ID" << endl;
            cout << "3. Check the details of other lenders whome you want to compare your money with" << endl;
            cout << "4. check how much intrest you are getting" << endl;
            cout << "5. Exit" << endl;
            cin >> ch;
            system("CLS");
            switch (ch) {
            case '1':
                LOAN::perData();
                break;
            case '2':
                if (total == 0)
                    cout << "No data is entered" << endl;
                else
                    LOAN::searchbyid();
                break;
            case '3':
                LOAN::searchbycash();
                break;
            case '4':
                LOAN::intrest();
                LOAN::intrest(1);
                break;
            case '5':
                exit(0);
                break;
            default:
                cout << "Invalid input" << endl;
                break;
            }
        } 
        // this is ment for borrowers 

        else if (ch2 == '2') {
            system("CLS");
            cout << "Hello Borrower choose the sevice you want\n" << endl;
            cout << "1. Check the details of a Lender's account who can lend you cash" << endl;
            cout << "2. Exit" << endl;
            cin >> ch;
            system("CLS");
            switch (ch) {
            case '1':
                LOAN::searchbycash();
                break;
            case '2':
                exit(0);
                break;
            default:
                cout << "Invalid input" << endl;
                break;
            }

        }

    }

}
// taking the data of each person or the lenders 

void LOAN::perData() {
    cout << "Enter data of person " << total + 1 << endl;
    cout << "Enter name: ";
    cin >> person[total].name;
    cout << "ID: ";
    cin >> person[total].ID;
    cout << "Address: ";
    cin >> person[total].address;
    cout << "Contact: ";
    cin >> person[total].contact;
    cout << "Total Cash: ";
    cin >> person[total].cash;
    cout << "Intrest rate you are seeking: ";
    cin >> person[total].intrest_rate;
    cout << "Total time in years for which you have deposited: ";
    cin >> person[total].time_for_deposition;
    total++;

}
//calculating the compound intrest 

void LOAN::intrest() {

    cout << "Enter your ID for viewing Compound intrest" << endl;
    cin >> id;
    for (int i = 0; i < total; i++) {
        if (id == person[i].ID) {
            cout << "Hello " << person[i].name << " you are getting " << endl;

            int p = person[i].cash;
            double r = person[i].intrest_rate;
            int t = person[i].time_for_deposition;
            double cal = 1 + r / 100;    // compound intrest is p-p(1+r/100)^t
            double val = pow(cal, t);
            double amount = p * val;
            double intr = amount - p;
            cout << "Compond Intrest = " << intr << endl;
            cout << "Amount = " << amount << endl;
            cout << "Press enter to view Simple intrest" << endl;
            getch();
            break;
        }
        if (i == total - 1) {
            cout << "Wrong User ID" << endl;
        }
    }

}
// use of polymorphism and calculating simple intrest

void LOAN::intrest(int) {
    system("CLS");
    cout << "Enter your ID for viewing Simple intrest" << endl;
    cin >> id;
    for (int i = 0; i < total; i++) {
        if (id == person[i].ID) {
            cout << "Hello " << person[i].name << " you are getting " << endl;

            int p = person[i].cash;
            double r = person[i].intrest_rate;
            int t = person[i].time_for_deposition;
            double intr = (p * t * r) / 100;  // simple intrest =p*r*t/100
            double amount = p + intr;
            cout << "Simple Intrest = " << intr << endl;
            cout << "Amount = " << amount << endl;
            cout << "Press enter to go to home page" << endl;
            getch();
            continue;
        }
        if (i == total - 1) {
            cout << "Wrong User ID" << endl;
        }
    }

}
// here we can search the lenders using cash they have 

void LOAN::searchbycash() {
    cout << "Enter the cash amount you want " << endl;
    cin >> Cash;
    cout << "These are the lenders who have cash more than you want" << endl;
    for (int i = 0; i < total; i++) {
        if (Cash <= person[i].cash) {
            cout << "\nName: " << person[i].name << endl;
            cout << "ID: " << person[i].ID << endl;
            cout << "Address: " << person[i].address << endl;
            cout << "Contact: " << person[i].contact << endl;
            cout << "Cash: " << person[i].cash << endl;
            cout << "Intrest rate he is seeking: " << person[i].intrest_rate << endl;
            cout << "Total time for which he has deposited: " << person[i].time_for_deposition << endl;
            cout << "Press enter to go to home page" << endl;
            getch();
            break;
        }

        if (i == total - 1) {
            cout << "No such lender exit demand some less money" << endl;
        }
    }

}
// searching the lenders from their id

void LOAN::searchbyid() {
    cout << "Enter id of lender those data you want to search" << endl;
    cin >> id;
    for (int i = 0; i < total; i++) {
        if (id == person[i].ID) {
            cout << "Name: " << person[i].name << endl;
            cout << "ID: " << person[i].ID << endl;
            cout << "Address: " << person[i].address << endl;
            cout << "Contact: " << person[i].contact << endl;
            cout << "Cash: " << person[i].cash << endl;
            cout << "Intrest rate he is seeking: " << person[i].intrest_rate << endl;
            cout << "Total time for which he has deposited: " << person[i].time_for_deposition << endl;
            cout << "Press enter to go to home page" << endl;
            getch();
            break;
        }
        if (i == total - 1) {
            cout << "No such record found" << endl;
        }
    }
}
 