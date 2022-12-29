#include <locale.h> 
#include <iostream>
#include <optional>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

class Person
{
private:	
	string firstName, lastName;
	optional<string> middleName;

public:
	Person(const string& _lName, const string& _fName, const optional<string>& _mName) : 
        lastName(_lName), firstName(_fName), middleName(_mName) {};
    ~Person() = default;

    string First () const {return firstName;};
    string Last () const {return lastName;};
    string Middle () const {return middleName.value_or("");};

	friend ostream& operator<< (ostream&, const Person&);
	friend bool operator< (const Person&, const Person&);
	friend bool operator== (const Person&, const Person&);
}; 

ostream& operator << (ostream& out, const Person& obj) {
    ios oldState(nullptr);
    oldState.copyfmt(out);
	out << setfill (' ') << right << setw(14) << obj.lastName << setw(12) << obj.firstName << setw(16) << obj.middleName.value_or("");
    out.copyfmt(oldState);
	return out;
}

bool operator < (const Person& obj1, const Person& obj2) {
	return tie(obj1.lastName, obj1.firstName, obj1.middleName) < tie(obj2.lastName, obj2.firstName, obj2.middleName);
}

bool operator == (const Person& obj1, const Person& obj2) {
    // return
	return tie(obj1.lastName, obj1.firstName, obj1.middleName) == tie(obj2.lastName, obj2.firstName, obj2.middleName);
}

using uint = unsigned int;

struct PhoneNumber
{
	uint countryCode, cityCode;
	string number;
	optional<uint> extNumber;

	PhoneNumber(const uint& _countryCode, const uint& _cityCode, const string& _number, const optional<uint>& _extNumber) : 
        countryCode(_countryCode), cityCode(_cityCode), number(_number), extNumber(_extNumber) {};
    PhoneNumber () = default;
    ~PhoneNumber() = default;
    void Clear ();


    friend ostream& operator << (ostream&, const PhoneNumber&);
	friend bool operator < (const PhoneNumber&, const PhoneNumber&);
}; 

void PhoneNumber::Clear () {
    countryCode= NULL;
    cityCode = NULL;
    number.clear();
    extNumber = nullopt;
}

ostream& operator << (ostream& out, const PhoneNumber& obj) {
    ios oldState(nullptr);
    oldState.copyfmt(out);
    out << left << showpos << (int)obj.countryCode << noshowpos << " (" << obj.cityCode << ") " << obj.number;
    if (obj.extNumber.has_value())
        out << " " << obj.extNumber.value();
    out.copyfmt(oldState);

	return out;
}

bool operator < (const PhoneNumber& obj1, const PhoneNumber& obj2) {
	return (tie(obj1.countryCode, obj1.cityCode, obj1.number, obj1.extNumber) < tie(obj2.countryCode, obj2.cityCode, obj2.number, obj2.extNumber));
}

class ByName
{
public:
    bool operator() (const pair<Person, PhoneNumber>& _left, const pair<Person, PhoneNumber>& _right) {
      
        return (_left.first < _right.first);
    };
}; 

class ByPhone
{
public:
    bool operator() (const pair<Person, PhoneNumber>& _left, const pair<Person, PhoneNumber>& _right) {
        
        return (_left.second < _right.second);
    };
}; 

class PhoneBook
{
private:
	vector <pair <Person, PhoneNumber>> db;

public:
	PhoneBook (ifstream&);
    ~PhoneBook() = default;

	void SortByName();
	void SortByPhone();
	tuple <string, PhoneNumber> GetPhoneNumber(const string&);
	void ChangePhoneNumber(const Person&, const PhoneNumber&);

	friend ostream& operator << (ostream&, PhoneBook);
};

PhoneBook::PhoneBook(ifstream& fstr) {
	string firstName, lastName, middleName, extNumber;

	if (fstr.is_open())	{
        PhoneNumber _phone;
		while (fstr >> lastName >> firstName >> middleName
                    >> _phone.countryCode >> _phone.cityCode >> _phone.number >> extNumber)
		{
            auto _mName = (middleName.empty () || middleName == "-") ? nullopt : optional<string> (middleName);
			Person _person(lastName, firstName, _mName);

            _phone.extNumber = (extNumber.empty () || extNumber == "-") ? nullopt : optional<int> (stoi(extNumber));
			db.push_back(make_pair(_person, _phone));
            _phone.Clear();
		}
	}
	fstr.close();
}

tuple <string, PhoneNumber> PhoneBook::GetPhoneNumber(const string& _lastName) {
	PhoneNumber phone{};
	uint found {};

	for_each(db.begin(), db.end(),
        [&](const auto& record) {
			if (record.first.Last() == _lastName) {
				phone = record.second;
				++found;
		    }
        });
    
    string answer {};
	if (!found) 
        answer = "not found";
	else if (found > 1) 
        answer = "found more than 1";
    // return
	return make_tuple(answer, phone);
}

void PhoneBook::ChangePhoneNumber(const Person& _person, const PhoneNumber& _newPhone) {
	auto found = find_if(db.begin(), db.end(), 
		[_person](const auto& record) {
			return (record.first == _person);
		});
	if (found != db.end()) 
        found->second = _newPhone;
}

ostream& operator << (ostream& out, PhoneBook obj) {	
	for (const auto& [person, phone] : obj.db)
		out << person << string (5, ' ') << phone << endl;
    // return
	return out;
}

void PhoneBook::SortByName() {
	sort(db.begin(), db.end(), ByName{});
}

void PhoneBook::SortByPhone() {
	sort(db.begin(), db.end(), ByPhone {});
}


void endFunction (void)
{

    puts ("\nthe work is completed!");
} 


int main (void) {


    setlocale (LC_ALL, "");


    if (atexit (endFunction)) {

        puts ("post- function registration error!");
    }


    ifstream file("PhoneBook.txt");

    PhoneBook book(file);
    cout << book;

    book.SortByPhone();
    cout << book;

    book.SortByName();
    cout << book;


    auto print_phone_number = [&book](const string& surname) {
        cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
            cout << get<1>(answer);
        else
            cout << get<0>(answer);
        cout << endl;
    };

    print_phone_number("Ivanov");
    print_phone_number("Petrov");
    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
    PhoneNumber{7, 123, "15344458", nullopt});
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
    PhoneNumber{ 16, 465, "9155448", 13 });
    cout << book;


    return 0;
} 
