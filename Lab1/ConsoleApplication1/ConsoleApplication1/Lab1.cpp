//Connor Harber
//9/11/2017
//lab01-cosc2030-01

#include<fstream>
using std::ifstream;

#include<string>
using std::string;

#include<vector>
using std::vector;

#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

string PromptUser()
{
	string filename;
	cout << "Please enter the name of a file containing integers.\n";
	cout << "We'll return the number of integers, as well as the first two and last two Integers in the file.\n\n";
	cin >> filename;
	cout << "\n";

	return filename;
}

double ReadDataTotal(ifstream& in)
{
	double count = 0;
	while (!in.eof())
	{
		int tmp;
		in >> tmp;
		if (!in.eof())
		{
			
			count++;
		}
	}
	return count;
}

void ReadDataFL(ifstream& in, double& first1,double& first2, double& last1, double& last2)
{
	int count = 0;
	while (!in.eof())
	{
		double tmp;
		in >> tmp;
		if (!in.eof())
		{
			if (count == 0)
			{
				first1 = tmp;
				
			}
			else if (count == 1)
			{
				first2 = tmp;
			
			}
			else
			{
				last1 = last2;
				last2 = tmp;
			}
			count++;
		}
	}
}

int main()
{
	double numbers = 0;
	double first1 = 0;
	double first2 = 0;
	double last1 = 0;
	double last2 = 0;
	string filename;
	ifstream infile;

	// while  file is not open prompt again
	while (!infile.is_open())
	{
		filename = PromptUser();
		infile.open(filename);
		if (!infile)
		{
			cout << "Could not open " << filename;
		}
	}

	numbers = ReadDataTotal(infile); // sets "numbers" = total inside file
	infile.close();
	infile.open(filename);
	ReadDataFL(infile, first1, first2, last1, last2);

	







	//Display of data.
	cout << "***************Data***************\n";
	cout << "Numbers in file: " << numbers << "\n";
	cout << "first two numbers: " << first1 << "," << first2 << "\n";
	cout << "last two numbers: " << last1 << "," << last2 << "\n";
	cout << "**********************************\n";
}