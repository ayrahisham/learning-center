#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>
using namespace std;

const int MAX = 12; // 12 animals

typedef void* VoidPtr;

enum Animal { Rat, Ox, Tiger, Rabbit, Dragon, Snake, Horse, Sheep, Monkey, Rooster, Dog, Pig };

void printPartition();

int getnerateNum ();

char displayMainMenu();

void processMainMenu (char);

void exampleSet ();

void constructSet (VoidPtr*, int);

VoidPtr getAnimalVP (int);

bool checkElement (int, VoidPtr*, int);

void printVParray (VoidPtr *, VoidPtr *, int);

Animal getVP (VoidPtr);

char * getAnimalStr (Animal);

char displaySetMenu ();

void processSetMenu (char, VoidPtr *, int);

int addElement (VoidPtr *, int);

void checkElementInSet (VoidPtr *, int);

void checkSetSize (VoidPtr *, int);

bool garbageCollection (VoidPtr *, int);

void unionSet ();

void intersectionSet ();

void complementSet ();

bool complementCheck (char [], VoidPtr *, int);

void subSet ();

void equality ();

void differenceSet();

void distributiveLaw();

void displayDLmsg();

int analysisLHS(VoidPtr *, VoidPtr *, VoidPtr *, VoidPtr *, VoidPtr *, int, int, int, int&);

int analysisRHS(VoidPtr *, VoidPtr *, VoidPtr *, VoidPtr *, VoidPtr *, VoidPtr*, int, int, int, int&, int&);

void checkQED(VoidPtr*, VoidPtr*, int, int);

