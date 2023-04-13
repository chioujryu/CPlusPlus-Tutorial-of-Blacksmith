#include<iostream>
using namespace std;

//build Menu
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1 add contacts  *****" << endl;
	cout << "*****  2 show contacts  *****" << endl;
	cout << "*****  3 delete contacts  *****" << endl;
	cout << "*****  4 find contacts  *****" << endl;
	cout << "*****  5 modify contacts  *****" << endl;
	cout << "*****  6 clean all contacts  *****" << endl;
	cout << "*****  0 shut down machine  *****" << endl;
	cout << "***************************" << endl;
}

//bulid Person structure
struct Person
{
	string m_Name; //name
	int m_Sex; //sex
	int m_Age; //age
	string m_Phone; //phone
	string m_Addr; //address
};

//build Addressbooks structure
#define MAX 1000 //Max number of people
struct Addressbooks
{
    struct Person personArray[MAX]; //The maximum number of contacts that your address book can accommodate
    int m_Size; //the current number of contacts in your address book
};

//1. add contacts
void addContacts(struct Addressbooks * abs)
{
    //Check if address book is full, no more adding. 
    if(abs->m_Size > MAX)
    {
        cout << "Sorry, cannot add. Address book already full." << endl;
		return;
    }
    else
    {
        //name
        string name;
        cout<<"please enter your name"<<endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        //sex
        cout<<"please enter your sex"<<endl;
        cout<<"1 -- male"<<endl;
        cout<<"0 -- female"<<endl;
        int sex = 0;
        while(1)
        {
            cin>>sex;
            if (sex == 1 || sex == 0)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else
            {
                cout<<"Input error, please enter your sex"<<endl;
                cout<<"1 -- male"<<endl;
                cout<<"2 -- female"<<endl;
            }
        }
        
        //age
        cout<<"please enter your age"<<endl;
        int Age;
        cin>>Age;
        abs->personArray[abs->m_Size].m_Age = Age;

        //Phone
        cout<<"please enter your phone"<<endl;
        string Phone;
        cin>>Phone;
        abs->personArray[abs->m_Size].m_Phone = Phone;

        //Address
        cout<<"please enter your address"<<endl;
        string Address;
        cin>>Address;
        abs->personArray[abs->m_Size].m_Addr = Address;

        //update m_Size
        abs->m_Size++;

        cout<<"Great news! You have successfully added a new contact."<<endl;
        system("pause"); //pause terminal
        system("cls"); //clear terminal
    }   
}

//2. show contacts
void showContacts(struct Addressbooks * abs)
{
    if (abs->m_Size == 0)
    {
        cout<<"Your address boos is empty"<<endl;
    }
    else
    {
        for (int i = 0 ; i < abs->m_Size ; i++)
        {
			cout << "Name:" << abs->personArray[i].m_Name << "\t";
			cout << "Sex:" << (abs->personArray[i].m_Sex == 1 ? "male" : "female") << "\t";
			cout << "Age:" << abs->personArray[i].m_Age << "\t";
			cout << "Phone" << abs->personArray[i].m_Phone << "\t";
			cout << "Address:" << abs->personArray[i].m_Addr << endl;
        }
    }
    system("pause"); //pause terminal
    system("cls"); //clear terminal
}

//Checking if contact exists. Return position if exists, else return -1.
int isExist(struct Addressbooks * abs, string name)
{
    for (int i = 0 ; i < abs->m_Size ; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;  //found contact, return his index
        }
    }
    return -1;  //if not found iterating, return `-1`
}

//3. delete contact
void deleteContact(struct Addressbooks * abs)
{
    string name;
    cout<<"enter a name contact you want to delete"<<endl;
    cin>>name;
    int number = isExist(abs, name);
    if (number == -1)
    {
        cout<<"Can't delete, contact not in address book."<<endl;
    }
    else
    {
        //Contact found, delete contact
        for (int i = number ; i < abs->m_Size ; i++)
        {
            //moving data forward
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size--;  //update personnel count in address book
    }
    system("pause"); //pause terminal
    system("cls"); //clear terminal
}

void showContactDetail(struct Addressbooks * abs, int index)
{
    cout << "Name:" << abs->personArray[index].m_Name << "\t";
    cout << "Sex:" << (abs->personArray[index].m_Sex == 1 ? "male" : "female") << "\t";
    cout << "Age:" << abs->personArray[index].m_Age << "\t";
    cout << "Phone" << abs->personArray[index].m_Phone << "\t";
    cout << "Address:" << abs->personArray[index].m_Addr << endl;
}

//4. find contact
void findContact(struct Addressbooks * abs)
{
    cout<<"enter a contact you want to check"<<endl;
    string name;
    cin >> name;

    //Checking if the specified contact is in the address book.
    int index = isExist(abs,name);
    if (index == -1)
    {
        cout<<"can not find the specified contact"<<endl;
    }
    else
    {
        showContactDetail(abs,index);
    }
    system("pause"); //pause terminal
    system("cls"); //clear terminal
}

//5. modify contact
void modifyContact(struct Addressbooks * abs)
{
    cout<<"enter a contact you want to modify"<<endl;
    string name;
    cin >> name;

    //Checking if the specified contact is in the address book.
    int index = isExist(abs,name);
    if (index == -1)
    {
        cout<<"can not find the specified contact"<<endl;
    }
    else
    {
        //modify name
        cout<<"modify the name"<<endl;
        string name;
        cin>>name;
        abs->personArray[index].m_Name = name;

        //modify sex
        cout<<"modify the sex"<<endl;
        cout<<"1 -- male"<<endl;
        cout<<"0 -- female"<<endl;
        int sex;
        cin>>sex;
        while(true)
        {
            if (sex == 0 || sex == 1)
            {
                //valid input, exit the loop
                abs->personArray[index].m_Sex = sex;
                break;
            }
            else
            {
                //invalid input
                cout<<"Invalid input"<<endl;
                break;
            }
        }

        //modify age
        cout<<"modify the age"<<endl;
        int age;
        cin>>age;
        abs->personArray[index].m_Age = age;

        //modify phone
        cout<<"modify the phone"<<endl;
        int phone;
        cin>>phone;
        abs->personArray[index].m_Phone = phone;

        //modify address
        cout<<"modify the address"<<endl;
        string address;
        cin>>address;
        abs->personArray[index].m_Addr = address;
    }
    system("pause"); //pause terminal
    system("cls"); //clear terminal
}

//6. clean all contacts
void cleanAllcontacts(struct Addressbooks * abs)
{
    abs->m_Size = 0;    //Set the number of current recorded contacts to 0 to logically clear them.
    cout<<"The address book has been cleared"<<endl;
    system("pause"); //pause terminal
    system("cls"); //clear terminal
}



int main() {

    //build Addressbooks
    struct Addressbooks abs;
    abs.m_Size = 0;


	int select = 0;

	while (true)
	{
		showMenu();

		cin >> select;
		
		switch (select)
		{
		case 1:  //add contacts
            addContacts(&abs); //Using address passing, you can modify actual parameters.
			break;
		case 2:  //show contacts
            showContacts(&abs);
			break;
		case 3:  //delete contacts 
            deleteContact(&abs);
			break;
		case 4:  //find contacts
            findContact(&abs);
			break;
		case 5:  //modify contacts
            modifyContact(&abs);
			break;
		case 6:  //empty contacts
            cleanAllcontacts(&abs);
			break;
		case 0:  //shut down machine
			cout << "I am happy to serve you" << endl;
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}
