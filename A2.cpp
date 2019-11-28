#include "A2.h"

void printPartition()
{
	cout << endl << setw (75) 
		 << setfill ('*') << "*" << endl
		 << setfill (' ')
		 << endl;
}

int generateNum ()
{
	int num = rand () % 12;
	
	return num;
}

char displayMainMenu()
{
	char option;
	
	cout << "Welcome to Suhaira Learning Center"
		 << endl << endl 
		 << "\t 0. An example of set" << endl
		 << "\t 1. Union" << endl
		 << "\t 2. Intersection" << endl 
		 << "\t 3. Complement" << endl
		 << "\t 4. Subset of" << endl
		 << "\t 5. Equality" << endl
		 << "\t 6. Difference" << endl
		 << "\t 7. Distributive Law" << endl
		 << "\t 9. Quit" << endl
		 << endl
		 << "\t Your option: ";
		 
	cin  >> option;
	
	return option;
}

void processMainMenu (char option)
{	 
	do
	{
		switch (option)
		{
			case '0' : printPartition();
					   exampleSet ();
					   break;
			
			case '1' : printPartition();
					   unionSet ();
					   break;
					   
			case '2' : printPartition();
					   intersectionSet (); 
					   break;
			
			case '3' : printPartition();
					   complementSet();
					   break;
			
			case '4' : printPartition();
					   subSet();
					   break;
			
			case '5' : printPartition();
					   equality();
					   break;
			
			case '6' : printPartition();
					   differenceSet();
					   break;
			
			case '7' : printPartition();
					   distributiveLaw();
					   break;
			
			case '9' : cout << endl
							<< "Thank you for using Suhaira Learning Center System." << endl;
					   exit (-1);
					   break;
		}
		
		printPartition();
		option = displayMainMenu();
	
	} while (true);
}

void exampleSet ()
{
	VoidPtr *s;
	
	int size = generateNum();
	
	s = new VoidPtr [size];
	
	cout << "Here is an example on set of animals" 
		 << endl << endl;
		 
	constructSet (s, size);
	
	VoidPtr *p = &s[0];
	
	cout << "Set S = ";
	
	printVParray (s, p, size);
	
	cout << endl
		 << "Note that elements in S are distinct and are not in order"
		 << endl;
	
	processSetMenu (displaySetMenu(), s, size);
	   
}

void constructSet (VoidPtr *s, int size)
{	 
	bool ok;
		
	VoidPtr *p = &s[0];
	
	int temp;
	
	for (int i = 0; i < size; i++)
	{
		ok = true;
		while (ok == true)
		{
			temp = generateNum();
			
			ok = checkElement (temp, s, i);
		}
		
		*p = getAnimalVP(temp);
		++p;
	}
}

VoidPtr getAnimalVP (int temp)
{
	Animal a = static_cast <Animal> (temp);
	
	Animal *animalPtr;
	animalPtr = new Animal;
	*animalPtr = a;
	
	VoidPtr vp = animalPtr;
	
	return vp;
}

bool checkElement (int temp, VoidPtr *s, int i)
{	 
	VoidPtr *p = &s[0];
	
	for (int j = 0; j < i; j++)
	{
		if (temp == getVP(*p))
		{
			return true;
		}
		
		++p;
	}
	
	return false;
}

void printVParray (VoidPtr *s, VoidPtr *p, int size)
{
	Animal a;
	
	cout << "{";
	
	for (int i = 0; i < size; i++)
	{
		if (i != size-1)
		{
			a = getVP (*p);
			
			cout << getAnimalStr (a) << ", ";
		}
		else
		{
			a = getVP (*p);
			cout << getAnimalStr (a);
		}	 
		
		++p;
	}
	
	cout << "}"
		 << endl;
}

Animal getVP (VoidPtr vp)
{
	Animal *aPtr = static_cast <Animal *>(vp);
	Animal a = *aPtr;
	
	return a;
}

char * getAnimalStr (Animal a)
{
	char animalStr [][MAX] =  { "Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Sheep", "Monkey", "Rooster", "Dog", "Pig" };
	
	int i = static_cast <int> (a);
	
	char *str = new char [MAX];

	strcpy (str, animalStr [i]);
	
	return str;
}

char displaySetMenu ()
{
	char choice;
	
	cout << endl
		 << "Wish to try the following operations?"
		 << endl
		 << "1. Add an element to the set" << endl
		 << "2. Check an element in set" << endl 
		 << "3. Check the cardinality" << endl
		 << "9. Quit" << endl
		 << endl
		 << "Your choice: ";
		 
	cin  >> choice;
	
	return choice;
}

void processSetMenu (char choice, VoidPtr *s, int size)
{	 
	bool del = false;
	
	do
	{	 
		switch (choice)
		{	 
			case '1' : printPartition();
					   size = addElement(s, size);
					   break;
					   
			case '2' : printPartition();
					   checkElementInSet (s, size);
					   break;
			
			case '3' : printPartition();
					   checkSetSize (s, size);
					   break;
			
			case '9' : printPartition();
					   if (garbageCollection (s, size) == true)
					   {
					   		cout << "Set S deleted" << endl;
					   }
					   printPartition();
					   processMainMenu(displayMainMenu());
					   break;
		}
		
		printPartition();
		choice = displaySetMenu();
	
	} while (true);
}

int addElement (VoidPtr *s, int size)
{
	Animal a;
	
	bool ok;
	
	int aNum, temp;
	
	char animalStr [][MAX] =  {"Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Sheep", "Monkey", "Rooster", "Dog", "Pig"};
	
	VoidPtr *p = &s [0];
	
	char animal [MAX];
	
	cout << "Current Set S = ";
	
	printVParray (s, p, size);
	
	cin.clear();
	cin.ignore(MAX, '\n');
	
	if (size == 12)
	{	 	 
		s = new VoidPtr [generateNum ()];
		
		constructSet (s, size);
		
		cout << "Current Set S = ";
	
		printVParray (s, p, size);
	}
	
	do
	{	 
		cout << endl
			 << "Enter an element: ";
			
		cin.getline (animal, MAX);
			
		int aNum;
		 
		for (int i = 0; i < MAX; i++)
		{	 
			if (strcmp (animal, animalStr[i]) == 0)
			{
				aNum = i;
			}
		}
		
		ok = checkElement(aNum, s, size);
		
		temp = aNum;
		
		if (ok == true)
		{
			cout << endl
				 << "\t Element exists in the set!"
				 << endl;
		}
		
	} while (ok == true);
	
	for (int i = 1; i < size; i++)
	{	 
		++p;
	}

	size += 1;
	++p;
	
	*p = getAnimalVP(temp);
		
	cout << endl
		 << "Set S = ";
		 
	p = &s[0];
			 
	printVParray (s, p, size);
	
	return size;
}

void checkElementInSet (VoidPtr *s, int size)
{
	Animal a;
	
	char animal [MAX];
	
	cout << "Current Set S = ";
	
	VoidPtr *p = &s[0];
	
	printVParray (s, p, size);
	
	if (size > 0)
	{
		cout << endl
			 << "Which element?: ";
			 
		cin.clear();
		cin.ignore(MAX, '\n');	
		
		cin.getline (animal, MAX);
		
		p = &s [0];
		
		for (int i = 0; i < size; i++)
		{
			a = getVP (*p);
			
			if (strcmp (getAnimalStr (a), animal) == 0)
			{
				cout << getAnimalStr (a)
					 << " is in S"
					 << endl;
				return;
			}
			
			++p;
		}
		
		if (strcmp (getAnimalStr (a), animal) != 0)
		{
			cout << animal
			 	 << " is not in S"
			 	 << endl;
		}	
	}
	else
	{
		cout << endl
			 << "Set is empty. Add element into set."
			 << endl;
	}
}

void checkSetSize (VoidPtr *s, int size)
{
	cout << "Current Set S = ";
	
	VoidPtr *p = &s[0];
	
	printVParray (s, p, size);
	
	cout << "S has "
		 << size
		 << " elements"
		 << endl;
}

bool garbageCollection (VoidPtr *s, int size)
{
	VoidPtr *p = &s[0];
	
	cout << "Garbage collection" << endl
		 << setw(18) << setfill ('=') << "=" 
		 << setfill (' ')
		 << endl;
	
	for (int i = 0; i < size; i++)
	{	
		delete [] p;
	}
	
	return true; 
}

void unionSet ()
{	 
	VoidPtr *S1;
	VoidPtr *S2;
	
	int sizeS1 = generateNum();
	
	S1 = new VoidPtr [sizeS1];
	
	constructSet(S1, sizeS1);
	
	cout << "Given the following two sets"
		 << endl << endl
		 << "\t Set S1 = ";
		 
	VoidPtr *p1 = &S1[0];
	
	printVParray (S1, p1, sizeS1);
	
	int sizeS2 = generateNum();
	
	S2 = new VoidPtr [sizeS2];
		
	constructSet(S2, sizeS2);
	
	cout << "\t Set S2 = ";
	
	VoidPtr *p2 = &S2[0];
	
	printVParray (S2, p2, sizeS2);
		 
	VoidPtr *Union;
	
	Union = new VoidPtr [MAX];
	  
	VoidPtr *U = &Union[0];
	
	int size = 0;
	
	bool ok = false;
	
	if (sizeS1 >= sizeS2)
	{
		for (int i = 0; i < sizeS1-1; i++)
		{
			*U = getAnimalVP(getVP(*p1));	 
			
			++p1;
			++U;
			++size;
		}
		
		p2 = &S2[0];
		
		if (sizeS2 == 0)
		{
			++size;
			*U = getAnimalVP(getVP(*p1));
		}
		else
		{
			++size;
			*U = getAnimalVP(getVP(*p1));
			
			for (int i = 0; i < sizeS2-1; i++)
			{	
				p1 = &S1[0];
				
				ok = false;
				
				for (int j = 0; j < sizeS1; j++)
				{
					if (getVP(*p2) == getVP(*p1))
					{
						ok = true;
					}
					
					++p1;
				}
				
				if (ok == false)
				{
					++U;
					++size;
					*U = getAnimalVP(getVP(*p2));
				}
				
				++p2;
			}
			
			//Check p2 pointer to last element of Set 2
			
			p1 = &S1[0];
				
			ok = false;
				
			for (int j = 0; j < sizeS1; j++)
			{
				if (getVP(*p2) == getVP(*p1))
				{
					ok = true;
				}
					
				++p1;
			}
				
			if (ok == false)
			{
				++U;
				++size;
				*U = getAnimalVP(getVP(*p2));
			}
		}
	}
	else
	{
		for (int i = 0; i < sizeS2-1; i++)
		{
			*U = getAnimalVP(getVP(*p2));	
			
			++p2;
			++U;
			++size;
		}
		
		p1 = &S1[0];
		
		if (sizeS1 == 0)
		{
			++size;
			*U = getAnimalVP(getVP(*p2));
		}
		else
		{
			++size;
			*U = getAnimalVP(getVP(*p2));
			
			for (int i = 0; i < sizeS1-1; i++)
			{	
				p2 = &S2[0];
				
				ok = false;
				
				for (int j = 0; j < sizeS2; j++)
				{
					if (getVP(*p1) == getVP(*p2))
					{
						ok = true;
					}
					
					++p2;
				}
				
				if (ok == false)
				{
					++U;
					++size;
					*U = getAnimalVP(getVP(*p1));
				}
				
				++p1;
			}
			
			//Check p1 pointer to last element of Set 1
			
			p2 = &S2[0];
				
			ok = false;
				
			for (int j = 0; j < sizeS2; j++)
			{
				if (getVP(*p1) == getVP(*p2))
				{
					ok = true;
				}
					
				++p2;
			}
				
			if (ok == false)
			{
				++U;
				++size;
				*U = getAnimalVP(getVP(*p1));
			}
		}
	}
	
	cout << endl
		 << "The union is	"
		 << endl << endl
		 << "\t ";
	
	U = &Union[0];
	
	printVParray (Union, U, size);
	
	printPartition();
	if (garbageCollection (S1, sizeS1) == true)
	{
		cout << "Set 1 deleted" 
			 << endl << endl;
	}
	if (garbageCollection (S2, sizeS2) == true)
	{
		cout << "Set 2 deleted" 
			 << endl << endl;
	}
	if (garbageCollection (Union, size) == true)
	{
		cout << "Set 3 (union set) deleted" 
			 << endl << endl;
	}
}

void intersectionSet ()
{
	VoidPtr *S1;
	VoidPtr *S2;
	
	int sizeS1 = generateNum();
	
	S1 = new VoidPtr [sizeS1];
	
	constructSet(S1, sizeS1);
	
	cout << "Given the following two sets"
		 << endl << endl
		 << "\t Set S1 = ";
		 
	VoidPtr *p1 = &S1[0];
	
	printVParray (S1, p1, sizeS1);
	
	int sizeS2 = generateNum();
	
	S2 = new VoidPtr [sizeS2];
		
	constructSet(S2, sizeS2);
	
	cout << "\t Set S2 = ";
	
	VoidPtr *p2 = &S2[0];
	
	printVParray (S2, p2, sizeS2);
		 
	VoidPtr *Intersect;
	
	Intersect = new VoidPtr [MAX];
	  
	VoidPtr *I = &Intersect[0];
	
	int size = 0;
	
	if (sizeS1 >= sizeS2)
	{
		for (int i = 0; i < sizeS1; i++)
		{	
			p2 = &S2[0];
				
			for (int j = 0; j < sizeS2; j++)
			{
				if (getVP(*p1) == getVP(*p2))
				{
					++size;
					*I = getAnimalVP(getVP(*p1));
					++I;
				}
				 	 
				++p2;
			}
					
			++p1;
		}
	}
	else
	{
		for (int i = 0; i < sizeS2; i++)
		{	
			p1 = &S1[0];
				
			for (int j = 0; j < sizeS1; j++)
			{
				if (getVP(*p2) == getVP(*p1))
				{
					++size;
					*I = getAnimalVP(getVP(*p2));
					++I;
				}
				 	 
				++p1;
			}
					
			++p2;
		}
	}
	
	cout << endl
		 << "The intersection is "
		 << endl << endl
		 << "\t ";
	
	I = &Intersect[0];
	
	printVParray (Intersect, I, size);
	
	printPartition();
	if (garbageCollection (S1, sizeS1) == true)
	{
		cout << "Set 1 deleted" 
			 << endl << endl;
	}
	if (garbageCollection (S2, sizeS2) == true)
	{
		cout << "Set 2 deleted" 
			 << endl << endl;
	}
	if (garbageCollection (Intersect, size) == true)
	{
		cout << "Set 3 (intersection set) deleted" 
			 << endl << endl;
	}
}

void complementSet ()
{	 
	char animalStr [][MAX] =  {"Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Sheep", "Monkey", "Rooster", "Dog", "Pig"};
	
	char animal [MAX];
	
	VoidPtr *S1;

	int sizeS1 = generateNum();
	
	S1 = new VoidPtr [sizeS1];
	
	constructSet(S1, sizeS1);
	
	cout << "Given the following set"
		 << endl << endl
		 << "\t Set S = ";
		 
	VoidPtr *p1 = &S1[0];
	
	printVParray (S1, p1, sizeS1);
	
	VoidPtr *Complement;
	
	Complement = new VoidPtr [MAX-sizeS1];
	  
	VoidPtr *C = &Complement[0];
	
	int size = 0;
	
	for (int a = 0; a < MAX; a++)
	{
		strcpy (animal, animalStr[a]);
		
		if (complementCheck(animal, S1, sizeS1) == true)
		{
			*C = getAnimalVP(a);
			++C;
			++size;
		}
	}	
	
	cout << endl
		 << "The complement set"
		 << endl << endl
		 << "\t Set S' = ";
	
	C = &Complement[0];
	
	printVParray (Complement, C, size);
	
	printPartition();
	if (garbageCollection (S1, sizeS1) == true)
	{
		cout << "Set S deleted"
			 << endl << endl;
	}
	if (garbageCollection (Complement, size) == true)
	{
		cout << "Set S' deleted" 
			 << endl << endl;
	}
	
}

bool complementCheck (char animal [], VoidPtr *S1, int sizeS1)
{	 
	VoidPtr *p1 = &S1[0];
	
	int ok = 0;
		
	for (int i = 0; i < sizeS1; i++)
	{
		if (strcmp (animal, getAnimalStr(getVP(*p1))) != 0)
		{
			++ok;
		}
		
		++p1;
		
	}
	
	if (ok == sizeS1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void subSet ()
{
	VoidPtr *S1;
	VoidPtr *S2;
	
	int sizeS1 = generateNum();
	
	S1 = new VoidPtr [sizeS1];
	
	constructSet(S1, sizeS1);
	
	cout << "Given the following two sets"
		 << endl << endl
		 << "\t Set S1 = ";
		 
	VoidPtr *p1 = &S1[0];
	
	printVParray (S1, p1, sizeS1);
	
	int sizeS2 = generateNum();
	
	S2 = new VoidPtr [sizeS2];
		
	constructSet(S2, sizeS2);
	
	cout << "\t Set S2 = ";
	
	VoidPtr *p2 = &S2[0];
	
	printVParray (S2, p2, sizeS2);
	
	cout << endl
		 << "Conclusion: "
		 << endl << endl;
		 
	int ok = 0;
	
	if (sizeS2 >= sizeS1)
	{
		if (sizeS1 == 0)
		{
			cout << "\t S1 is a subset of S2" << endl;
			
			if (sizeS2 == 0)
			{
				cout << "\t S2 is not a subset of S1" << endl;
			}
			else
			{
				cout << "\t S2 is not a subset of S1" << endl;
			}
		}
		else
		{
			for (int i = 0; i < sizeS1; i++)
			{
				p2 = &S2[0];
				
				for (int j = 0; j < sizeS2; j++)
				{
					if (getVP(*p1) == getVP(*p2))
					{
						++ok;
					}
					
					++p2;
				}
				
				++p1;
			}
			
			if (ok == sizeS1)
			{
				if (ok == sizeS2)
				{
					cout << "S1 is a subset of S2" << endl
						 << "S2 is a subset of S1" << endl;
				}
				cout << "\t S1 is a subset of S2" << endl
					 << "\t S2 is not a subset of S1" << endl;
			}
			else
			{
				cout << "\t S1 is not a subset of S2" << endl
					 << "\t S2 is not a subset of S1" << endl;
			}
		}
	}
	else
	{
		if (sizeS2 == 0)
		{
			if (sizeS1 == 0)
			{
				cout << "\t S1 is a subset of S2" << endl;
			}
			else
			{
				cout << "\t S1 is not a subset of S1" << endl;
			}
			
			cout << "\t S2 is a subset of S1" << endl;
		}
		else
		{
			for (int i = 0; i < sizeS2; i++)
			{
				p1 = &S1[0];
				
				for (int j = 0; j < sizeS1; j++)
				{
					if (getVP(*p2) == getVP(*p1))
					{
						++ok;
					}
					
					++p1;
				}
				
				++p2;
			}
			
			if (ok == sizeS2)
			{
				if (ok == sizeS1)
				{
					cout << "\t S1 is a subset of S2" << endl
						 << "\t S2 is a subset of S1" << endl;
				}
				
				cout << "\t S1 is not a subset of S2" << endl
					 << "\t S2 is a subset of S1" << endl;
			}
			else
			{
				cout << "\t S1 is not a subset of S2" << endl
					 << "\t S2 is not a subset of S1" << endl;
			}
		}
	}
	
	printPartition();
	if (garbageCollection (S1, sizeS1) == true)
	{
		cout << "Set 1 deleted" 
			 << endl << endl;
	}
	if (garbageCollection (S2, sizeS2) == true)
	{
		cout << "Set 2 deleted" 
			 << endl << endl;
	}
}

void equality ()
{
	VoidPtr *S1;
	VoidPtr *S2;
	
	int sizeS1 = generateNum();
	
	S1 = new VoidPtr [sizeS1];
	
	constructSet(S1, sizeS1);
	
	cout << "Given the following two sets"
		 << endl << endl
		 << "\t Set S1 = ";
		 
	VoidPtr *p1 = &S1[0];
	
	printVParray (S1, p1, sizeS1);
	
	int sizeS2 = generateNum();
	
	S2 = new VoidPtr [sizeS2];
		
	constructSet(S2, sizeS2);
	
	cout << "\t Set S2 = ";
	
	VoidPtr *p2 = &S2[0];
	
	printVParray (S2, p2, sizeS2);
		 
	int ok = 0;
	
	cout << endl
		 << "Conclusion: "
		 << endl << endl;
	
	if (sizeS2 >= sizeS1)
	{
		if (sizeS1 == 0)
		{	 
			if (sizeS2 == 0)
			{
				cout << "\t S1 is equal to S2" 
					 << endl << endl
				     << "Reasons: "
		 			 << endl << endl
					 << "\t S1 is a subset of S2" << endl
					 << "\t S2 is a subset of S1" << endl;
			}
			else
			{
				cout << "\t S1 is not equal to S2" 
					 << endl << endl
				     << "Reasons: "
		 			 << endl << endl
					 << "\t S1 is a subset of S2" << endl
					 << "\t S2 is not a subset of S1" << endl;
			}
		}
		else
		{
			for (int i = 0; i < sizeS1; i++)
			{
				p2 = &S2[0];
				
				for (int j = 0; j < sizeS2; j++)
				{
					if (getVP(*p1) == getVP(*p2))
					{
						++ok;
					}
					
					++p2;
				}
				
				++p1;
			}
			
			if (ok == sizeS1)
			{
				if (ok == sizeS2)
				{
					cout << "\t S1 is equal to S2" 
					 	 << endl << endl
				     	 << "Reasons: "
		 			 	 << endl << endl
					 	 << "\t S1 is a subset of S2" << endl
					 	 << "\t S2 is a subset of S1" << endl;
				}
				else
				{
					cout << "\t S1 is not equal to S2" 
						 << endl << endl
					     << "Reasons: "
			 			 << endl << endl
						 << "\t S1 is a subset of S2" << endl
						 << "\t S2 is not a subset of S1" << endl;
				}
			}
			else
			{
				cout << "\t S1 is not equal to S2" 
					 << endl << endl
				     << "Reasons: "
		 			 << endl << endl
					 << "\t S1 is not a subset of S2" << endl
					 << "\t S2 is not a subset of S1" << endl;
			}
		}
	}
	else
	{	 	  
		if (sizeS2 == 0)
		{
			if (sizeS1 == 0)
			{
				cout << "\t S1 is equal to S2" 
					 	 << endl << endl
				     	 << "Reasons: "
		 			 	 << endl << endl
					 	 << "\t S1 is a subset of S2" << endl
					 	 << "\t S2 is a subset of S1" << endl;
			}
			else
			{
				cout << "\t S1 is not equal to S2" 
					 << endl << endl
				     << "Reasons: "
		 			 << endl << endl
					 << "\t S1 is not a subset of S1" << endl
				     << "\t S2 is a subset of S1" << endl;
			}
			
			
		}
		else
		{
			for (int i = 0; i < sizeS2; i++)
			{
				p1 = &S1[0];
				
				for (int j = 0; j < sizeS1; j++)
				{
					if (getVP(*p2) == getVP(*p1))
					{
						++ok;
					}
					
					++p1;
				}
				
				++p2;
			}
			
			if (ok == sizeS2)
			{
				if (ok == sizeS1)
				{
					cout << "\t S1 is equal to S2" 
					 	 << endl << endl
				     	 << "Reasons: "
		 			 	 << endl << endl
					 	 << "\t S1 is a subset of S2" << endl
					 	 << "\t S2 is a subset of S1" << endl;
				}
				else
				{
					cout << "\t S1 is not equal to S2" 
					 << endl << endl
				     << "Reasons: "
		 			 << endl << endl
					 << "\t S1 is not a subset of S1" << endl
				     << "\t S2 is a subset of S1" << endl;
				}
			}
			else
			{
				cout << "\t S1 is not equal to S2" 
					 << endl << endl
				     << "Reasons: "
		 			 << endl << endl
					 << "\t S1 is not a subset of S2" << endl
					 << "\t S2 is not a subset of S1" << endl;
			}
		}
	}
	
	printPartition();
	if (garbageCollection (S1, sizeS1) == true)
	{
		cout << "Set 1 deleted" 
			 << endl << endl;
	}
	if (garbageCollection (S2, sizeS2) == true)
	{
		cout << "Set 2 deleted" 
			 << endl << endl;
	}
}

void differenceSet()
{
	VoidPtr *S1;
	VoidPtr *S2;
	
	int sizeS1 = generateNum();
	
	S1 = new VoidPtr [sizeS1];
	
	constructSet(S1, sizeS1);
	
	cout << "Given the following two sets"
		 << endl << endl
		 << "\t Set S1 = ";
		 
	VoidPtr *p1 = &S1[0];
	
	printVParray (S1, p1, sizeS1);
	
	int sizeS2 = generateNum();
	
	S2 = new VoidPtr [sizeS2];
		
	constructSet(S2, sizeS2);
	
	cout << "\t Set S2 = ";
	
	VoidPtr *p2 = &S2[0];
	
	printVParray (S2, p2, sizeS2);
		 
	VoidPtr *S1_S2;
	
	S1_S2 = new VoidPtr [MAX];
	  
	VoidPtr *s1 = &S1_S2[0];
	
	VoidPtr *S2_S1;
	
	S2_S1 = new VoidPtr [MAX];
	  
	VoidPtr *s2 = &S2_S1[0];
	
	int ok, s1s2size = 0, s2s1size = 0;
	
	//For set 1 - set 2
	for (int i = 0; i < sizeS1; i++)
	{	
		p2 = &S2[0];
				
		ok = 0;
			
		for (int j = 0; j < sizeS2; j++)
		{
			if (getVP(*p1) != getVP(*p2))
			{
				++ok;
			}
				 	 
			++p2;
		}
			
		if (ok == sizeS2)
		{
			*s1 = getAnimalVP(getVP(*p1));
			++s1;
			++s1s2size;
		}
					
		++p1;
	}
	
	p2 = &S2[0];
	
	//For set 2 - set 1
	for (int i = 0; i < sizeS2; i++)
	{	
		p1 = &S1[0];
				
		ok = 0;
			
		for (int j = 0; j < sizeS1; j++)
		{
			if (getVP(*p2) != getVP(*p1))
			{
				++ok;
			}
				 	 
			++p1;
		}
			
		if (ok == sizeS1)
		{
			*s2 = getAnimalVP(getVP(*p2));
			++s2;
			++s2s1size;
		}
					
		++p2;
	}
	
	cout << endl
		 << "Conclusion: "
		 << endl << endl;
	
	s1 = &S1_S2[0];
	
	cout << "\t S1 - S2 = ";
	printVParray (S1_S2, s1, s1s2size);
	
	
	s2 = &S2_S1[0];
	
	cout << "\t S2 - S1 = ";
	printVParray (S2_S1, s2, s2s1size);
	
	printPartition();
	
	if (garbageCollection (S1, sizeS1) == true)
	{
		cout << "Set 1 deleted" 
			 << endl << endl;
	}
	if (garbageCollection (S2, sizeS2) == true)
	{
		cout << "Set 2 deleted" 
			 << endl << endl;
	}
	if (garbageCollection (S1_S2, s1s2size) == true)
	{
		cout << "Set S1 - S2 deleted" 
			 << endl << endl;
	}
	if (garbageCollection (S2_S1, s1s2size) == true)
	{
		cout << "Set S2 - S1 deleted" 
			 << endl << endl;
	}
}

void distributiveLaw()
{
	VoidPtr *A;
	VoidPtr *B;
	VoidPtr *C;
	
	VoidPtr *UnionL;
	UnionL = new VoidPtr [MAX];
	
	VoidPtr *IntersectL;
	IntersectL = new VoidPtr [MAX];
	
	VoidPtr *UnionR;
	UnionR = new VoidPtr [MAX];
	
	VoidPtr *IntersectAB;
	IntersectAB = new VoidPtr [MAX];
	
	VoidPtr *IntersectAC;
	IntersectAC = new VoidPtr [MAX];
	
	int sizeA = generateNum();
	
	A = new VoidPtr [sizeA];
	
	constructSet (A, sizeA);
	
	cout << "Given the following three sets"
		 << endl << endl
		 << "\t Set A = ";
		 
	VoidPtr *pA = &A[0];
	
	printVParray (A, pA, sizeA);
	
	int sizeB = generateNum();
	
	B = new VoidPtr [sizeB];
		
	constructSet(B, sizeB);
	
	cout << "\t Set B = ";
	
	VoidPtr *pB = &B[0];
	
	printVParray (B, pB, sizeB);
	
	int sizeC = generateNum();
	
	C = new VoidPtr [sizeC];
		
	constructSet(C, sizeC);
	
	cout << "\t Set C = ";
	
	VoidPtr *pC = &C[0];
	
	printVParray (C, pC, sizeC);
		 
	displayDLmsg();
	
	int sizeLHS, sizeRHS, unionL = 0, interAB = 0, interAC = 0;
	
	sizeLHS = analysisLHS (A, B, C, UnionL, IntersectL, sizeA, sizeB, sizeC, unionL);
	
	sizeRHS = analysisRHS (A, B, C, UnionR, IntersectAB, IntersectAC, sizeA, sizeB, sizeC, interAB, interAC);
	
	checkQED(IntersectL, UnionR, sizeLHS, sizeRHS);
	
	printPartition();
	
	if (garbageCollection (A, sizeA) == true)
	{
		cout << "Set A deleted" 
			 << endl << endl;
	}
	if (garbageCollection (B, sizeB) == true)
	{
		cout << "Set B deleted" 
			 << endl << endl;
	}
	if (garbageCollection (C, sizeC) == true)
	{
		cout << "Set C deleted" 
			 << endl << endl;
	}
	
	printPartition();
	
	cout << "Note that I used some dummy arrays to store the info" 
		 << endl << endl;
	if (garbageCollection (UnionL, unionL) == true)
	{
		cout << "Dummy set 1 deleted" 
			 << endl << endl;
	}
	/*
	if (garbageCollection (IntersectL, sizeLHS) == true)
	{
		cout << "Dummy set 2 deleted" 
			 << endl << endl;
	}
	if (garbageCollection (IntersectAB, interAB) == true)
	{
		cout << "Dummy set 3 deleted" 
			 << endl << endl;
	}
	if (garbageCollection (IntersectAC, interAC) == true)
	{
		cout << "Dummy set 4 deleted" 
			 << endl << endl;
	}
	if (garbageCollection (UnionR, sizeRHS) == true)
	{
		cout << "Dummy set 5 deleted" 
			 << endl << endl;
	}
	*/
}

void displayDLmsg()
{
	printPartition();
	cout << "We wish to prove that the following distributive law"
	     << endl << "\t"
		 << "Note that I stands for intersection and"
		 << endl << "\t \t \t U stands for union"
		 << endl << endl
		 << "\t \t A I (B U C) = (A I B) U (A I C)"
		 << endl;
}

int analysisLHS (VoidPtr *A, VoidPtr *B, VoidPtr *C, VoidPtr *UnionL, 
				 VoidPtr *IntersectL, int sizeA, int sizeB, int sizeC, int& size)
{
	printPartition();
	
	VoidPtr *pA = &A[0];
	VoidPtr *pB = &B[0];
	VoidPtr *pC = &C[0];
	VoidPtr *U = &UnionL[0];
	VoidPtr *I = &IntersectL[0];
	
	bool ok = false;
	
	cout << endl
		 << "Analysis of L.H.S." << endl
		 << setw(18) << setfill ('=') << "=" 
		 << setfill (' ')
		 << endl << endl;
	
	//Union B and C
	if (sizeB >= sizeC)
	{
		for (int i = 0; i < sizeB-1; i++)
		{
			*U = getAnimalVP(getVP(*pB));	 
			
			++pB;
			++U;
			++size;
		}
		
		pC = &C[0];
		
		if (sizeC == 0)
		{
			++size;
			*U = getAnimalVP(getVP(*pB));
		}
		else
		{
			++size;
			*U = getAnimalVP(getVP(*pB));
			
			for (int i = 0; i < sizeC-1; i++)
			{	
				pB = &B[0];
				
				ok = false;
				
				for (int j = 0; j < sizeB; j++)
				{
					if (getVP(*pC) == getVP(*pB))
					{
						ok = true;
					}
					
					++pB;
				}
				
				if (ok == false)
				{
					++U;
					++size;
					*U = getAnimalVP(getVP(*pC));
				}
				
				++pC;
			}
			
			//Check p2 pointer to last element of Set 2
			
			pB = &B[0];
				
			ok = false;
				
			for (int j = 0; j < sizeB; j++)
			{
				if (getVP(*pC) == getVP(*pB))
				{
					ok = true;
				}
					
				++pB;
			}
				
			if (ok == false)
			{
				++U;
				++size;
				*U = getAnimalVP(getVP(*pC));
			}
		}
	}
	else
	{
		for (int i = 0; i < sizeC-1; i++)
		{
			*U = getAnimalVP(getVP(*pC));	
			
			++pC;
			++U;
			++size;
		}
		
		pB = &B[0];
		
		if (sizeB == 0)
		{
			++size;
			*U = getAnimalVP(getVP(*pC));
		}
		else
		{
			++size;
			*U = getAnimalVP(getVP(*pC));
			
			for (int i = 0; i < sizeB-1; i++)
			{	
				pC = &C[0];
				
				ok = false;
				
				for (int j = 0; j < sizeC; j++)
				{
					if (getVP(*pB) == getVP(*pC))
					{
						ok = true;
					}
					
					++pC;
				}
				
				if (ok == false)
				{
					++U;
					++size;
					*U = getAnimalVP(getVP(*pB));
				}
				
				++pB;
			}
			
			//Check p1 pointer to last element of Set 1
			
			pC = &C[0];
				
			ok = false;
				
			for (int j = 0; j < sizeC; j++)
			{
				if (getVP(*pB) == getVP(*pC))
				{
					ok = true;
				}
					
				++pC;
			}
				
			if (ok == false)
			{
				++U;
				++size;
				*U = getAnimalVP(getVP(*pB));
			}
		}
	}
		
	cout << endl
		 << "\tThe union of B and C is "
		 << endl << endl
		 << "\t ";
	
	U = &UnionL[0];
	
	printVParray (UnionL, U, size);
	
	//Set of L.H.S.
	
	int sizeLHS = 0;
	
	if (size >= sizeA)
	{
		for (int i = 0; i < size; i++)
		{	
			pA = &A[0];
				
			for (int j = 0; j < sizeA; j++)
			{
				if (getVP(*U) == getVP(*pA))
				{
					++sizeLHS;
					*I = getAnimalVP(getVP(*U));
					++I;
				}
				 	 
				++pA;
			}
					
			++U;
		}
	}
	else
	{
		for (int i = 0; i < sizeA; i++)
		{	
			U = &UnionL[0];
				
			for (int j = 0; j < size; j++)
			{
				if (getVP(*pA) == getVP(*U))
				{
					++sizeLHS;
					*I = getAnimalVP(getVP(*pA));
					++I;
				}
				 	 
				++U;
			}
					
			++pA;
		}
	}
	
	cout << endl
		 << "\tTherefore the set of the L.H.S."
		 << endl << endl
		 << "\t ";
	
	I = &IntersectL[0];
	
	printVParray (IntersectL, I, sizeLHS);
	
	return sizeLHS;
	
}

int analysisRHS(VoidPtr *A, VoidPtr *B, VoidPtr *C, VoidPtr *UnionR, 
				VoidPtr *IntersectAB, VoidPtr *IntersectAC, int sizeA, 
				int sizeB, int sizeC, int& sizeAB, int& sizeAC)
{
	printPartition();
	
	VoidPtr *pA = &A[0];
	VoidPtr *pB = &B[0];
	VoidPtr *pC = &C[0];
	VoidPtr *U = &UnionR[0];
	VoidPtr *iAB = &IntersectAB[0];
	VoidPtr *iAC = &IntersectAC[0];
	
	bool ok = false;
	
	cout << endl
		 << "Analysis of R.H.S." << endl
		 << setw(18) << setfill ('=') << "=" 
		 << setfill (' ')
		 << endl << endl;
	
	//Intersection of A and B
	
	if (sizeA >= sizeB)
	{
		for (int i = 0; i < sizeA; i++)
		{	
			pB = &B[0];
				
			for (int j = 0; j < sizeB; j++)
			{
				if (getVP(*pA) == getVP(*pB))
				{
					++sizeAB;
					*iAB = getAnimalVP(getVP(*pA));
					++iAB;
				}
				 	 
				++pB;
			}
					
			++pA;
		}
	}
	else
	{
		for (int i = 0; i < sizeB; i++)
		{	
			pA = &A[0];
				
			for (int j = 0; j < sizeA; j++)
			{
				if (getVP(*pB) == getVP(*pA))
				{
					++sizeAB;
					*iAB = getAnimalVP(getVP(*pB));
					++iAB;
				}
				 	 
				++pA;
			}
					
			++pB;
		}
	}
	
	cout << endl
		 << "\tThe intersection of A and B"
		 << endl << endl
		 << "\t ";
	
	iAB = &IntersectAB[0];
	
	printVParray (IntersectAB, iAB, sizeAB);
	
	//Intersection of A and C
	
	pA = &A[0];
	
	if (sizeA >= sizeC)
	{
		for (int i = 0; i < sizeA; i++)
		{	
			pC = &C[0];
				
			for (int j = 0; j < sizeC; j++)
			{
				if (getVP(*pA) == getVP(*pC))
				{
					++sizeAC;
					*iAC = getAnimalVP(getVP(*pA));
					++iAC;
				}
				 	 
				++pC;
			}
					
			++pA;
		}
	}
	else
	{
		for (int i = 0; i < sizeC; i++)
		{	
			pA = &A[0];
				
			for (int j = 0; j < sizeA; j++)
			{
				if (getVP(*pC) == getVP(*pA))
				{
					++sizeAC;
					*iAC = getAnimalVP(getVP(*pC));
					++iAC;
				}
				 	 
				++pA;
			}
					
			++pC;
		}
	}
	
	cout << endl
		 << "\tThe intersection of A and C"
		 << endl << endl
		 << "\t ";
	
	iAC = &IntersectAC[0];
	
	printVParray (IntersectAC, iAC, sizeAC);
	
	//Union A I B and A I C
	
	int sizeRHS = 0;
	
	if (sizeAB >= sizeAC)
	{
		for (int i = 0; i < sizeAB-1; i++)
		{
			*U = getAnimalVP(getVP(*iAB));	  
			
			++iAB;
			++U;
			++sizeRHS;
		}
		
		iAC = &IntersectAC[0];
		
		if (sizeAC == 0)
		{
			++sizeRHS;
			*U = getAnimalVP(getVP(*iAB));
		}
		else
		{
			++sizeRHS;
			*U = getAnimalVP(getVP(*iAB));
			
			for (int i = 0; i < sizeAC-1; i++)
			{	
				iAB = &IntersectAB[0];
				
				ok = false;
				
				for (int j = 0; j < sizeAB; j++)
				{
					if (getVP(*iAC) == getVP(*iAB))
					{
						ok = true;
					}
					
					++iAB;
				}
				
				if (ok == false)
				{
					++U;
					++sizeRHS;
					*U = getAnimalVP(getVP(*iAC));
				}
				
				++iAC;
			}
			
			iAB = &IntersectAB[0];
				
			ok = false;
				
			for (int j = 0; j < sizeAB; j++)
			{
				if (getVP(*iAC) == getVP(*iAB))
				{
					ok = true;
				}
					
				++iAB;
			}
				
			if (ok == false)
			{
				++U;
				++sizeRHS;
				*U = getAnimalVP(getVP(*iAC));
			}
		}
	}
	else
	{
		for (int i = 0; i < sizeAC-1; i++)
		{
			*U = getAnimalVP(getVP(*iAC));	 
			
			++iAC;
			++U;
			++sizeRHS;
		}
		
		iAB = &IntersectAB[0];
		
		if (sizeAB == 0)
		{
			++sizeRHS;
			*U = getAnimalVP(getVP(*iAC));
		}
		else
		{
			++sizeRHS;
			*U = getAnimalVP(getVP(*iAC));
			
			for (int i = 0; i < sizeAB-1; i++)
			{	
				iAC = &IntersectAC[0];
				
				ok = false;
				
				for (int j = 0; j < sizeAC; j++)
				{
					if (getVP(*iAB) == getVP(*iAC))
					{
						ok = true;
					}
					
					++iAC;
				}
				
				if (ok == false)
				{
					++U;
					++sizeRHS;
					*U = getAnimalVP(getVP(*iAB));
				}
				
				++iAB;
			}
			
			//Check p1 pointer to last element of Set 1
			
			iAC = &iAC[0];
				
			ok = false;
				
			for (int j = 0; j < sizeAC; j++)
			{
				if (getVP(*iAB) == getVP(*iAC))
				{
					ok = true;
				}
					
				++iAC;
			}
				
			if (ok == false)
			{
				++U;
				++sizeRHS;
				*U = getAnimalVP(getVP(*iAB));
			}
		}
	}
		
	cout << endl
		 << "\tTherefore the set of R.H.S."
		 << endl << endl
		 << "\t ";
	
	U = &UnionR[0];
	
	printVParray (UnionR, U, sizeRHS);
	
	return sizeRHS;
}

void checkQED(VoidPtr *IntersectL, VoidPtr *UnionR, int sizeLHS, int sizeRHS)
{
	VoidPtr *I = &IntersectL[0];
	VoidPtr *U = &UnionR[0];
	
	int ok = 0;
	
	cout << endl
		 	 << "Conclusion: ";
	
	if ((sizeLHS == 0) && (sizeRHS == 0))
	{
		cout << "L.H.S = R.H.S ==> Q.E.D." << endl;
		
	}
	else
	{
		for (int i = 0; i < sizeLHS; i++)
		{
			U = &UnionR[0];
				
			for (int j = 0; j < sizeRHS; j++)
			{
				if (getVP(*I) == getVP(*U))
				{
					++ok;
				}
					
				++U;
			}
				
			++I;
		}
			
		if (ok == sizeLHS)
		{
			cout << "L.H.S = R.H.S ==> Q.E.D." << endl;
		}
		else
		{
			cout << "L.H.S != R.H.S ==> Q.E.D." << endl;	 
		}
	}
}

