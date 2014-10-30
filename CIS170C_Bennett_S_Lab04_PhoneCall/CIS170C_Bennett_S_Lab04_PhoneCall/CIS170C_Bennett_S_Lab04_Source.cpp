/* Developer: Steven Bennett
	Assignment: Week 4 Lab 4 Phone Call
	Date: March 30, 2013 */

#include <iostream>
#include <cctype>
using namespace std;

//function prototypes
int ReadDials(char &d1, char &d2, char &d3, char &d4, char &d5, char &d6, char &d7, char &d8);
int ToDigit(char &d);
void AcknowledgeCall(char d1, char d2, char d3, char d4, char d5, char d6, char d7, char d8);

int main()
{
	//variable declaration
	char d1, d2, d3, d4, d5, d6, d7, d8 = ' ';
	int errorCode = 0;

	while (errorCode != -5)
	{
		/*call ReadDials() pass by reference
		ReadDials() returns error code by value and assign to error code*/
		errorCode = ReadDials(d1, d2, d3, d4, d5, d6, d7, d8);

		switch (errorCode)
		{
		case -1: cout << "ERROR--An invalid character was entered.\n\n" << endl;
			break;
		case -2: cout << "ERROR--Phone number cannot begin with 0.\n\n" << endl;
			break;
		case -3: cout << "ERROR--Phone number cannot begin with 555.\n\n" << endl;
			break;
		case -4: cout << "ERROR--Hyphen is not in the correct position.\n\n" << endl;
			break;
		case -5:
			break;
		default: AcknowledgeCall(d1, d2, d3, d4, d5, d6, d7, d8);
		}
	}

	return 0;
}

/*definition of function ReadDials(). ReadDials() accepts 8 characters and tests
if format entered is correct*/
int ReadDials(char &d1, char &d2, char &d3, char &d4, char &d5, char &d6, char &d7, char &d8)
{
	cout << "Enter a phone number (Q to quit): ";
	cin >> d1;
	if (d1 == 'q' || d1 == 'Q') //perform check to see if user wants to quit
		return -5;
	else
	{
		cin >> d2 >> d3 >> d4 >> d5 >> d6 >> d7 >> d8; //continue entering rest of phone number
		if (ToDigit(d1) == -1 || ToDigit(d2) == -1 || ToDigit(d3) == -1 || ToDigit(d5) == -1 || 
			ToDigit(d6) == -1 || ToDigit(d7) == -1 || ToDigit(d8) == -1)
			return -1;
		else if (d4 != '-')
			return -4;
		else if (d1 == '0')
			return -2;
		else if (d1 == '5' && d2 == '5' && d3 == '5')
			return -3;
		else
			return 0;
	}
}


/*definition of function ToDigit(). ToDigit() accepts char, 
converts to uppercase, and determines corresponding digit on phone pad for given letter*/
int ToDigit(char &d)
{
	d = toupper(d);
	switch (d)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		break;
	case 'A': case 'B': case 'C': d = '2';
		break;
	case 'D': case 'E': case 'F': d = '3';
		break;
	case 'G': case 'H': case 'I': d = '4';
		break;
	case 'J': case 'K': case 'L': d = '5';
		break;
	case 'M': case 'N': case 'O': d = '6';
		break;
	case 'P': case 'Q': case 'R': case 'S': d = '7';
		break;
	case 'T': case 'U': case 'V': d = '8';
		break;
	case 'W': case 'X': case 'Y': case 'Z': d = '9';
		break;
	default: return -1;
	}

	return 0;
}

//definition of function AcknowledgeCall()
void AcknowledgeCall(char d1, char d2, char d3, char d4, char d5, char d6, char d7, char d8)
{
	cout << "Phone number dialed: " << d1 << d2 << d3 << d4 << d5 << d6 << d7 << d8 << "\n\n" << endl;
}