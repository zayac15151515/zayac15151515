#include <locale.h>
#include <iostream>

#include <unordered_set>
#include <array>
#include <iterator>
#include <random>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;


template <typename T, typename It>
void displayUnique (const It& begin, const It& end) {
	unordered_set <T> atoms;
	copy (begin, end, inserter (atoms, atoms.end ()));

    cout << "result <" << atoms.size() << ">: ";
	copy (atoms.begin (), atoms.end (), ostream_iterator <T> (cout, " "));
	cout << endl;
}


void clearPhrase (string& phrase) {
    
    const string chars (" \n\t\r");
    replace_if (phrase.begin(), phrase.end(),
                            [&chars](const char &c)
                            {
                            return chars.find(c) != string::npos;
                            },
                            ' ');

	const auto begin = phrase.find_first_not_of (' ');
	const auto end   = phrase.find_last_not_of  (' ');

    phrase = (begin != string::npos) ? phrase.substr(begin, end - begin + 1) : string{};
}

uint32_t countWords (string const& phrase) {
    stringstream stream;


    stream.rdbuf()->pubsetbuf ((char*)phrase.c_str(), phrase.length() );
    return distance (istream_iterator <string> (stream), istream_iterator<string>());
}

void calcValues (const string& source, multimap <uint32_t, string>& res) {

    auto itBegin = begin (source);
	auto itEnd   = end   (source);

    auto if_phrase = [] (const char& c)
                        {
                        const string chars = ".!?"+'\0';
                        return (chars.find(c) != string::npos);
                        };

    auto itSrc = find_if(itBegin, itEnd, if_phrase);

	while (itBegin < itEnd && distance (itBegin, itSrc)) {

        string phrase = {itBegin, itSrc};

        clearPhrase(phrase);

        uint32_t count = countWords (phrase);
        if (count)
            res.insert ({countWords (phrase), move (phrase)});

		itBegin = next (itSrc, 1);
		itSrc   = find_if (itBegin, itEnd, if_phrase);
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

    cout << "Lesson 05. Associative STL containers.\n\n";


    cout << "Exercise #1.\n";

    const size_t MAX_SIZE = 10;

    array <string, MAX_SIZE> example_1;

    uniform_int_distribution <int> RNG_INT(0, 5);

    mt19937 gen {random_device()()};


    for_each (begin(example_1), end(example_1),
        [&RNG_INT, &gen] (string &value)
        {
        char buf[5];
        sprintf (buf, "%02d", RNG_INT(gen));
        value = buf;}
        );

    cout << "source array <" << example_1.size() << ">: ";
    copy (begin(example_1), end(example_1), ostream_iterator<string> (cout, " "));
    cout << endl;

    displayUnique <string> (example_1.begin(), example_1.end());


    stringstream example_2;
    copy (begin(example_1), end(example_1), ostream_iterator<string> (example_2, " "));
    cout << "source strstream <the same data> ... " << endl;
    displayUnique <string> (istream_iterator<string>{example_2}, {});


    cout << "input text: ";
    string source;
    cin.unsetf(ios::skipws);

    getline (cin, source, '\n');

    multimap <uint32_t, string> result;

    calcValues (source, result);

    cout << "top 5 longest sentences:" << endl;
    int count = 5;
    for (auto item = result.rbegin(); item != result.rend() && count > 0; item++, count--) {
        cout << item->first << " word[s] =>> " << item->second << endl;
    }
    
    // return o.k.
    return EXIT_SUCCESS;
} 
