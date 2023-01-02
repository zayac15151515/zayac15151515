

#include <locale.h> 
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stdint.h>
#include "timer.h"

using namespace std;


template<typename T>
void Swap(T** lPtr, T** rPtr) {
    // check
    if (*lPtr == *rPtr)
        return;
    // do
	T *tValue = *lPtr;
	*lPtr = *rPtr;
	*rPtr = tValue;
}


template<typename T>
void SortPointers(vector<T*>& vec) {
	sort(vec.begin(), vec.end(),
		[](T* lValue, T* rValue) {
			return (*lValue < *rValue);
		});
}


uint16_t Count_if_find(const string& source, const string& search) {
    string_view wSource = source, wSearch = search;
	return count_if(wSource.begin(), wSource.end(),
		[&wSearch](const char& c) {
			return (wSearch.find(c) != string::npos);
		});
}

uint16_t Count_if_for(const string& source, const string& search) {
    string_view wSource = source, wSearch = search;
	return count_if(wSource.begin(), wSource.end(),
		[&wSearch](const char& c) {
			for (const auto& element : wSearch)
				if (c == element)
                    return true;
			return false;
		});
}

uint16_t For_find(const string& source, const string& search) {
    string_view wSource = source, wSearch = search;
	uint16_t count{};
	for (const auto& c : wSource)
		if (wSearch.find(c) != string::npos)
            count++;
    // return
	return count;
}

uint16_t x2_For(const string& source, const string& search) {
    string_view wSource = source, wSearch = search;
	uint16_t count{};
	for (const auto& c : wSource)
		for (const auto& element : wSearch)
			if (c == element) {
				++count;
				break;
			}
    // return
	return count;
}



int* RandomNumber () {
    int *Number = new int (rand() % 100);
    return Number;
}


void endFunction (void)
{
    // Output of the shutdown message
    puts ("\nthe work is completed!");
} 

int main (void) {

    
    setlocale (LC_ALL, "");

     
    if (atexit (endFunction)) {
        
        puts ("post- function registration error!");
    }

    cout << "Lesson 02. Memory model and execution time.\n\n";

  
    cout << "Exercise #1.\n";

    int *A = new int (10);
    int *B = new int (200);
    
    cout << "initial (before swapping):" << endl;
    cout << "A = " << *A << ", &A = " << A << "; B = " << *B << ", &B = " << B << "." << endl;
	
    Swap(&A, &B);

    cout << "result (after swapping):" << endl;
    cout << "A = " << *A << ", &A = " << A << "; B = " << *B << ", &B = " << B << "." << endl;

    delete A;
    delete B;


    cout << "\nExercise #2.\n";

    const size_t MAX_COUNT = 10;
	vector<int *> ptrVector(MAX_COUNT);

    srand (unsigned (time(0)));
    generate (ptrVector.begin(), ptrVector.end(), RandomNumber);


    auto display = [&]() {
        cout << "{address, value}: ";
		for (const auto &elem : ptrVector)
			cout << "{" << elem << "->" << *elem << "} ";
		cout << endl;
	};
    cout << "vector before sorting..." << endl;
    display();

    SortPointers<int>(ptrVector);

    cout << "vector after sorting..." << endl;
    display();


	for (auto &elem : ptrVector)
		delete elem;

    cout << "\nExercise #3.\n";

    ifstream file;
    file.open("voina-i-mir.txt", ios::in);
    if (!file.is_open()) {
        cerr << "can't open source file!" << endl; 
        return EXIT_FAILURE;
    };
    
    file.seekg(0, ios::end);
    size_t fSize = file.tellg();
    file.seekg(0);
    string source(fSize, ' ');
    file.read(&source[0], fSize);

    const string vowels = "АОИЕЁЭЫУЮЯаоиеёэыуюя";


	Timer timer("Count_if + find");
    uint16_t res = Count_if_find(source, vowels);
    timer.print();
    cout <<	res << " vowel letters." << endl;


    timer.start("Count_if + for");
    res = Count_if_for(source, vowels);
    timer.print();
    cout <<	res << " vowel letters." << endl;

    timer.start("For + find");
    res = For_find(source, vowels);
    timer.print();
    cout <<	res << " vowel letters." << endl;


    timer.start("2 x For");
    res = x2_For(source, vowels);
    timer.print();
    cout <<	res << " vowel letters." << endl;
	
    if (file.is_open())
        file.close();


    return EXIT_SUCCESS;
}
