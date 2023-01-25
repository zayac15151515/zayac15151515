

#include <locale.h>  
#include <iostream>

#include <fstream>
#include <sstream>
#include <vector>
#include <optional>
#include <algorithm>

#include "Exercise-02.pb.h"

using namespace std;


namespace Exercise_2 {

    const string f_name {"Exercise-02.dat"};


    void PromptForStudent (lesson07::Student* student) {

        cin.ignore(256, '\n');

        auto *full_name =  student->mutable_fio();

        cout << "\nenter first name: ";
        getline (cin, *full_name->mutable_firstname());

        cout << "enter last name: ";
        getline (cin, *full_name->mutable_lastname());

        cout << "enter second name: ";
        getline (cin, *full_name->mutable_patronymic());

        float _total {0.0};
        while (true) {
            cout << "enter a grade (or leave blank to finish): ";
            string _str_value;
            getline (cin, _str_value);
            if (_str_value.empty ()) {
                break;
            }
            stringstream _ss {_str_value};
            int _number;
            _ss >> _number;

            student->add_grades (_number);
            _total += static_cast <float> (_number);
        }

        student->set_avggrade (_total / static_cast <float> (student->grades_size()));

    } 

  
    void ListStudents (const lesson07::StudentsGroup &students_group) {
        for (int i = 0; i < students_group.students_size(); i++) {
            const lesson07::Student& student = students_group.students (i);

            cout << "\n#" << i + 1 << endl;
            cout << "first name: " << student.fio().firstname() << endl;
            cout << "last name: " << student.fio().lastname() << endl;

            if (student.fio().has_patronymic())
                cout << "second name: " << student.fio().patronymic() << endl;

            cout << "avg.grade: " << student.avggrade() << endl;

            cout << "grades: ";
            for (int j = 0; j < student.grades_size (); j++)
                cout << student.grades (j) << " ";
            cout << endl;
        }
    } 

} 

namespace Exercise_3 {

    const string f_name {"Exercise-03.dat"};

    struct FullName;

    

    class IRepository
    {
        public:
           
            virtual auto Open (ifstream &) -> size_t = 0;
          
            virtual auto Save (ofstream &) -> size_t = 0; 

            IRepository() = default;
            ~IRepository() = default;
    }; 

  

    class IMethods
    {
        public:
            virtual optional <double> GetAverageScore (const FullName &) = 0;
            virtual optional <string> GetAllInfo (const FullName &) = 0;
            virtual string GetAllInfo () = 0;

            IMethods() = default;
            ~IMethods() = default;
    }; 



    class FullName : public IRepository
    {
        public :
            string firstName;
            string lastName;
            string patronymic;

            auto Open (ifstream &) -> size_t override; 
            auto Save (ofstream &) -> size_t override; 

            FullName (const string& _firstName, const string& _lastName,const string& _patronymic)
            : firstName (_firstName), lastName (_lastName) , patronymic (_patronymic)
            {};
            FullName ()
            : firstName (""), lastName ("") , patronymic ("")
            {};
            ~FullName () = default;

    }; 

    auto FullName::Open (ifstream &in)  -> size_t
    {
        const auto pos = in.tellg ();
        size_t sz{};
        char *buf;

        
        in.read (reinterpret_cast <char*> (&sz), sizeof (sz));
        firstName.clear();
        if (sz) {
            buf = new char [sz];
            in.read (buf, sz);
            firstName.append (buf, 0, sz);
           
            delete []buf;
        }

        
        lastName.clear();
        in.read (reinterpret_cast <char*> (&sz), sizeof (sz));
        if (sz) { 
            buf = new char [sz];
            in.read (buf, sz);
            lastName.append (buf, 0, sz);
           
            delete []buf;
        }

        
        patronymic.clear();
        in.read (reinterpret_cast <char*> (&sz), sizeof (sz));
        if (sz) {
            buf = new char [sz];
            in.read (buf, sz);
            patronymic.append (buf, 0, sz);
           
            delete []buf;
        }

        
        return static_cast <ssize_t> (in.tellg () - pos);

    } 

    auto FullName::Save (ofstream &out) -> size_t
    {
        const auto pos = out.tellp ();

       
        size_t sz = firstName.length ();
        out.write (reinterpret_cast <const char*> (&sz), sizeof (sz));
        out.write (firstName.c_str(), firstName.length());
        
     
        sz = lastName.length ();
        out.write (reinterpret_cast <const char*> (&sz), sizeof (sz));
        out.write (lastName.c_str (), lastName.length());
        
       
        sz = patronymic.length ();
        out.write (reinterpret_cast <const char*> (&sz), sizeof (sz));
        out.write (patronymic.c_str (), patronymic.length());

    
        return static_cast <ssize_t> (out.tellp () - pos);

    } 

    
    class Student : public IRepository
    {
        public:
            FullName FIO;
            vector <uint16_t> grades;
            float avgGrade;

            
            auto Open (ifstream &) -> size_t override; 
            auto Save (ofstream &) -> size_t override; 
            Student() : avgGrade (0.0f) {};
            ~Student() = default;

    }; 

    auto Student::Open (ifstream &in) -> size_t
    {
        const auto pos = in.tellg ();

       
        FIO.Open (in);

     
        in.read (reinterpret_cast <char*> (&avgGrade), sizeof (avgGrade));

   
        grades.clear();
        grades.shrink_to_fit();
        size_t sz{};
        in.read (reinterpret_cast <char*> (&sz), sizeof (sz));
        grades.resize (sz);
        in.read (reinterpret_cast <char*> (&grades[0]), sizeof (uint16_t) * sz);

      
        return static_cast <ssize_t> (in.tellg () - pos);

    } 

    auto Student::Save (ofstream &out) -> size_t
    {
        const auto pos = out.tellp ();

        
        FIO.Save (out);

        
        out.write (reinterpret_cast <const char*> (&avgGrade), sizeof (avgGrade));

       
        size_t sz = grades.size ();
        out.write (reinterpret_cast <const char*> (&sz), sizeof (sz));
        out.write (reinterpret_cast <const char*> (&grades[0]), sizeof (uint16_t) * sz);

       
        return static_cast <ssize_t> (out.tellp () - pos);

    } 

    

    class StudentsGroup : public IRepository, public IMethods
    {
        public:
            
            auto Open (ifstream &) -> size_t override; 
            auto Save (ofstream &) -> size_t override;
            
            optional <double> GetAverageScore (const FullName& name) override;
            optional <string> GetAllInfo (const FullName& name) override;
            string GetAllInfo () override;

            void addStudent (Student* _student) {
                if (_student != nullptr)
                    students.emplace_back (*_student);
            };

            StudentsGroup () = default;
            ~StudentsGroup() = default;

        private:
            vector <Student> students;

    }; 

    auto StudentsGroup::Open (ifstream &in) -> size_t
    {
        const auto pos = in.tellg ();

       
        students.clear();
        students.shrink_to_fit();
        size_t sz{};
        in.read (reinterpret_cast <char*> (&sz), sizeof (sz));
        for (size_t i = 0; i < sz; ++i)
        {
            Student iobj;
            iobj.Open (in);
            students.emplace_back (iobj);
        }

       
        return static_cast <ssize_t> (in.tellg () - pos);

    } 

    auto StudentsGroup::Save (ofstream &out) -> size_t
    {
        const auto pos = out.tellp ();

        
        size_t sz = students.size ();
        out.write (reinterpret_cast <const char*> (&sz), sizeof (sz));
        for (size_t i = 0; i < sz; ++i) {
            auto& iobj = students [i];
            iobj.Save (out);
        }

        
        return static_cast <ssize_t> (out.tellp () - pos);

    } 

    optional <double> StudentsGroup::GetAverageScore (const FullName& name) {
        auto it = find_if (students.begin(), students.end(),
                    [&] (const auto& value) {
                        return (tie (value.FIO.firstName, value.FIO.lastName, value.FIO.patronymic) ==
                                tie (name.firstName, name.lastName, name.patronymic));
                    });

        if (it == students.end())
            return nullopt; 

       
        return it->avgGrade;

    } 

    optional <string> StudentsGroup::GetAllInfo (const FullName& name) {
        
        auto it = find_if (students.begin(), students.end(),
                    [&] (const auto& value) {
                        return (tie (value.FIO.firstName, value.FIO.lastName, value.FIO.patronymic) ==
                                tie (name.firstName, name.lastName, name.patronymic));
                    });

        if (it == students.end())
            return nullopt;

        stringstream _ss {};

        
        _ss << "first name: " << it->FIO.firstName << endl;
        _ss << "last name: "  << it->FIO.lastName << endl;

        if (!it->FIO.patronymic.empty())
            _ss << "second name: " << it->FIO.patronymic << endl;

        _ss << "avg.grade: " << it->avgGrade << endl;

        _ss << "grades: ";
        for (size_t j = 0; j < it->grades.size (); ++j)
            _ss << it->grades [j] << " ";
        _ss << endl;

        
        return _ss.str();

    } 

    string StudentsGroup::GetAllInfo () {

        stringstream _ss;
        int count {};

        for (size_t i = 0; i < students.size(); ++i) {
            auto info = GetAllInfo (students [i].FIO);
            if (!info.has_value ())
                continue;
            _ss << "\n#" << count + 1 << endl;
            _ss << info.value ();
        }
            
        // return
        return _ss.str();

    } 

    
    void PromptForStudent (Student* student) {

        cin.ignore(256, '\n');

        
        auto &full_name =  student->FIO;

        cout << "\nenter first name: ";
        getline (cin, full_name.firstName);

        cout << "enter last name: ";
        getline (cin, full_name.lastName);

        cout << "enter second name: ";
        getline (cin, full_name.patronymic);

        
        float _total{};
        while (true) {
            cout << "enter a grade (or leave blank to finish): ";
            string _str_value;
            getline (cin, _str_value);
            if (_str_value.empty ()) {
                break;
            }
            stringstream _ss {_str_value};
            int _number;
            _ss >> _number;

            student->grades.emplace_back (static_cast <uint16_t> (_number));
            _total += static_cast <float> (_number);
        }

        student->avgGrade = _total / static_cast <float> (student->grades.size ());

    } 

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

    cout << "Lesson 07. Namespace and binary serialization.\n\n";

  
    cout << "Exercise #1.\n";
    cout << "see the explanations in file «SetUp_Google_protobuf_in_MSYS2.pdf»" << endl;

   
    cout << "\nExercise #2.\n";

    GOOGLE_PROTOBUF_VERIFY_VERSION;
    
    lesson07::StudentsGroup proto_students_group;

   
    cout << "\nproceed to serialize?(Y/N): ";
    char answer = getchar ();
    if (answer == 'Y' || answer == 'y') {
        fstream out;
        out.open (Exercise_2::f_name, ios::out | ios::trunc | ios::binary);
        if (!out.is_open ()) {
            cout << "failed to open «" << Exercise_2::f_name << "»!" << endl;
            return EXIT_FAILURE;
        }
       
        do {
            Exercise_2::PromptForStudent (proto_students_group.add_students());
            cout << "proceed the next?(Y/N): ";
            answer = getchar ();
            if (answer != 'Y' && answer != 'y')
                break;
        } while (true);
        
        if (!proto_students_group.SerializeToOstream (&out)) {
            cout << "failed to write «"<< Exercise_2::f_name << "»!" << endl;
            
        } else {
            cout << "file «" << Exercise_2::f_name << "» was successfully written." << endl;
        }
        
        if (out.is_open ())
            out.close ();
    }

    
    cin.ignore(256, '\n');
    cout << "\nproceed to deserialize?(Y/N): ";
    answer = getchar ();
    if (answer == 'Y' || answer == 'y') {
        fstream in;
        in.open (Exercise_2::f_name, ios::in | ios::binary);
        if (!in.is_open ()) {
            cout << "failed to open «" << Exercise_2::f_name << "»!" << endl;
            
        } else {
            if (!proto_students_group.ParseFromIstream(&in)) {
                cout << "failed to parse from «"<< Exercise_2::f_name << "»!" << endl;
               
            } else
                Exercise_2::ListStudents (proto_students_group);
        }
        // close
        if (in.is_open ())
            in.close ();
    }
    
   
    google::protobuf::ShutdownProtobufLibrary ();

 
    cout << "\nExercise #3.\n";

    Exercise_3::StudentsGroup obj_students_group;

  
    cin.ignore(256, '\n');
    cout << "\nproceed to serialize?(Y/N): ";
    answer = getchar ();
    if (answer == 'Y' || answer == 'y') {
        ofstream out;
        out.open (Exercise_3::f_name, ios::out | ios::trunc | ios::binary);
        if (!out.is_open ()) {
            cout << "failed to open «" << Exercise_3::f_name << "»!" << endl;
            return EXIT_FAILURE;
        }
   
        do {
            Exercise_3::Student _student{};
            Exercise_3::PromptForStudent (&_student);
            obj_students_group.addStudent (&_student);
            cout << "proceed the next?(Y/N): ";
            answer = getchar ();
            if (answer != 'Y' && answer != 'y')
                break;
        } while (true);
    
        if (!obj_students_group.Save (out)) {
            cout << "failed to write «"<< Exercise_3::f_name << "»!" << endl;
     
        } else {
            cout << "file «" << Exercise_3::f_name << "» was successfully written." << endl;
        }
  
        if (out.is_open ())
            out.close ();
    }


    cin.ignore(256, '\n');
    cout << "\nproceed to deserialize?(Y/N): ";
    answer = getchar ();
    if (answer == 'Y' || answer == 'y') {
        ifstream in;
        in.open (Exercise_3::f_name, ios::in | ios::binary);
        if (!in.is_open ()) {
            cout << "failed to open «" << Exercise_3::f_name << "»!" << endl;

        } else {
            if (!obj_students_group.Open (in)) {
                cout << "failed to parse from «"<< Exercise_3::f_name << "»!" << endl;
       
            } else
                cout << obj_students_group.GetAllInfo ();
        }

        if (in.is_open ())
            in.close ();
    }


    return EXIT_SUCCESS;
} 
