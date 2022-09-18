
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Address
{
public:
  string name;
  string address;
  string phone;
  string dob;
  Address *next;

Address (string n, string a, string p, string d)
  {
    name = n;
    address = a;
    phone = p;
    dob = d;
    next = NULL;
  }
};

class AddressBook
{
public:
  Address * list;

  AddressBook ()
  {
    list = NULL;
  }

  void add ()
  {
    cout << endl;
    string name;
    string address;
    string phone;
    string dob;

    cout << "Please enter below details of new entry:" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Please enter Address(enter ',' instead of space): ";
    cin >> address;
    cout << "Please enter Phone number: ";
    cin >> phone;
    cout << "Please enter Date of Birth in (DD/MM/YYYY) format): ";
    cin >> dob;

    Address *taddr = new Address (name, address, phone, dob);

    if (list == NULL)
      {
	list = taddr;
      }
    else
      {
	taddr->next = list;
	list = taddr;
      }
  }

  void delet ()
  {
    cout << endl;
    if (list == NULL)
      {
	cout << "The Address book is empty!\n";
	return;
      }

    string name;
    cout << "Please enter the name of the person: ";
    cin >> name;

    Address *paddr = NULL;
    Address *caddr = list;
    while (caddr != NULL)
      {
	if (caddr->name == name)
	  {
	    break;
	  }
	paddr = caddr;
	caddr = caddr->next;
      }

    if (caddr == NULL)
      {
	cout << "Contact not found in address book!" << endl;
      }
    else
      {
	if (paddr == NULL)
	  {
	    list = caddr->next;
	  }
	else
	  {
	    paddr->next = caddr->next;
	  }
	cout << "Contact deleted!" << endl;
      }
  }

  void display ()
  {				
    cout << endl;
    if (list == NULL)
      {
	cout << "The Address book is empty!\n";
	return;
      }

    cout << left << setw (15) << "NAME"
      << left << setw (30) << "ADDRESS"
      << left << setw (15) << "PHONE" << left << setw (12) << "DOB" << endl;
    Address *taddr = list;
    while (taddr != NULL)
      {
	cout << left << setw (15) << taddr->name
	  << left << setw (30) << taddr->address
	  << left << setw (15) << taddr->phone
	  << left << setw (12) << taddr->dob << endl;
	taddr = taddr->next;
      }
  }

  void save ()
  {				
    cout << endl;
    ofstream fout;
    fout.open ("addressbook.txt");

    if (list == NULL)
      {
	fout.close ();
	cout << "Address book is empty!\n\n";
	return;
      }

    fout << left << setw (15) << "NAME"
      << left << setw (30) << "ADDRESS"
      << left << setw (12) << "PHONE" << left << setw (12) << "DOB" << endl;
    Address *taddr = list;
    while (taddr != NULL)
      {
	fout << left << setw (15) << taddr->name
	  << left << setw (30) << taddr->address
	  << left << setw (15) << taddr->phone
	  << left << setw (12) << taddr->dob << endl;
	taddr = taddr->next;
      }

    fout.close ();
    cout << "Address book has been saved into the file addressbook.txt" <<
      endl << endl;
  }
};

int
main ()
{
  AddressBook book;		
  int ch = 0;

  while (ch != 4)
    {				
      cout << endl;

      cout << "1. Add entry to the address book" << endl
	<< "2. Delete entry from address book" << endl
	<< "3. Display the address book" << endl
	<< "4. Save address book and exit" << endl
	<< "Please enter your choice: ";
      cin >> ch;

      switch (ch)
	{
	case 1:		
	  book.add ();
	  break;
	case 2:		
	  book.delet ();
	  break;
	case 3:		
	  book.display ();
	  break;
	case 4:		
	  book.save ();
	  break;
	}
    }
  return 0;
}
