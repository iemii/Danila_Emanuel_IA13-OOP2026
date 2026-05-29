#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class ContactType {
	Friend,
	Acquaintance,
	Colleague
};

class Contact { //clasa e abstracta deoarece are cel putin o metoda virtuala (=0)
protected:
	string name;
public:
	Contact(string name):name(name){}
	virtual ~Contact(){} //virtual pt prevenire memory leak
	string GetName() const 
	{
		return name;
	}
	virtual ContactType GetType() const = 0; //abstract/virtual
	virtual void Print() const = 0;
};

class Friend :public Contact {
private:
	string dateOfBirth, phoneNumber, address;
public:
	Friend(string name, string dob, string phone, string addr) :Contact(name), dateOfBirth(dob), phoneNumber(phone), address(addr){}

	ContactType GetType() const override 
	{
		return ContactType::Friend;
	}

	void Print() const override
	{
		cout<< "[Prieten] Nume: " << name << " | Tel: " << phoneNumber
			<< " | Data Nasterii: " << dateOfBirth << " | Adresa: " << address << "\n";
	}
};

class Acquaintance :public Contact {
private:
	string phoneNumber;
public:
	Acquaintance(string name, string phone) :Contact(name), phoneNumber(phone){}

	ContactType GetType() const override
	{
		return ContactType::Acquaintance;
	}

	void Print() const override 
	{
		cout << "[Cunostinta] Nume: " << name << " | Tel: " << phoneNumber << "\n";
	}
};

class Colleague :public Contact {
private:
	string phoneNumber, company, address;
public:
	Colleague(string name, string phone, string comp, string addr) :Contact(name), phoneNumber(phone), company(comp), address(addr){}

	ContactType GetType() const override
	{
		return ContactType::Colleague;
	}

	void Print() const override
	{
		cout << "[Coleg] Nume: " << name << " | Tel: " << phoneNumber
			<< " | Companie: " << company << " | Adresa: " << address << "\n";
	}
};

class AddressBook {
private:
	vector<Contact*> contacts;//pointer permite polimorfismul
public:
	~AddressBook()
	{
		for (Contact* c : contacts)
		{
			delete c;
		}
		contacts.clear();
	}

	void AddContact(Contact* c)
	{
		contacts.push_back(c);
		cout << "Contactul " << c->GetName() << " a fost adaugat cu succes.\n";
	}

	Contact* SearchByName(string name)
	{
		for (Contact* c : contacts)
			if (c->GetName() == name)
				return c;
		return nullptr;
	}

	vector<Friend*> GetFriends()
	{
		//folosim enum pentru a filtra contactele
		vector<Friend*> friendslist;
		for (Contact* c : contacts)
		{
			if (c->GetType() == ContactType::Friend)
			{
				friendslist.push_back((Friend*)c);
			}
		}
		return friendslist;
	}

	bool DeleteContact(string name)
	{
		for (auto it = contacts.begin(); it!=contacts.end();it++)
			if ((*it)->GetName() == name)
			{
				delete* it;//eliber mem alocata cu new
				contacts.erase(it);//scoate pointerul din vector
				cout << "Contactul '" << name << "' a fost sters.\n";
				return true;
			}
		cout << "Eroare: Contactul '" << name << "' nu exista.\n";
		return false;
	}

	void PrintAll()
	{
		cout << "AGENDA TELEFONICA (" << contacts.size() << " contacte)\n";
		for (Contact* c : contacts)
			c->Print();
		cout << "\n\n";
	}
};

int main() {
	AddressBook agenda;

	agenda.AddContact(new Friend("Mihai Popescu", "15-08-1999", "0722111222", "Str. Florilor 4"));
	agenda.AddContact(new Acquaintance("Andrei Vasile", "0744000000"));
	agenda.AddContact(new Colleague("Elena Ionescu", "0733444555", "TechCorp SRL", "Bd. Unirii 10"));
	agenda.AddContact(new Friend("Ana Maria", "22-12-2001", "0755888999", "Str. Lunga 12"));

	agenda.PrintAll();

	//cautam contact dupa name
	cout << "Cautare 'Elena Ionescu':\n";
	Contact* cautat = agenda.SearchByName("Elena Ionescu");
	if (cautat != nullptr) {
		cout << " -> Gasit: ";
		cautat->Print();
	}

	//doar lista de prieteni
	cout << "\nLista doar cu PRIETENI:\n";
	vector<Friend*> prieteni = agenda.GetFriends();
	for (Friend* f : prieteni) {
		f->Print();
	}
	cout << "\n";

	//stergem un contact
	agenda.DeleteContact("Andrei Vasile");
	Contact* sters = agenda.SearchByName("Andrei Vasile");
	if (sters == nullptr) {
		cout << "Contactul Andrei Vasile nu mai exista in agenda.\n";
	}

	agenda.PrintAll();
	return 0;//destructorul AddressBook va curata restul memoriei
}