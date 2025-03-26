#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double getRainfall(double[], int);
double averageRainfall(int, double, double[]);
double driestMonth(double[], int, int, string[]);
double wettestMonth(double[], int, int, string[]);
void displayReport(double, double[], int, double, double, double, string[], double, double);

int main()
{
	const int SIZE = 12;
	double rainFall[SIZE];
	double total = 0;
	double average = 0;
	double driest = 0;
	double wettest = 0;
	int dryMonth = 0;
	int wetMonth = 0;

	string least, most;
	string months[SIZE] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	for (int count = 0; count < SIZE; count++)
	{
		cout << "Enter the rainfall inches for the month of " << months[count] << ": ";
		cin >> rainFall[count];
		while (rainFall[count] < 0)
		{
			cout << "Number must be positive! " << endl;
			cout << "Enter the rainfall for the month of " << months[count] << ": ";
			cin >> rainFall[count];
		}

	}

	displayReport(total, rainFall, SIZE, average, driest, dryMonth, months, wettest, wetMonth);


	return 0;
}

double getRainfall(double rainFall[], int SIZE)
{
	double total = 0;
	for (int count = 0; count < SIZE; count++)
	{
		total += rainFall[count];
	}

	cout << "Total rainfall: " << total << " inches" << endl;

	return total;
}

double averageRainfall(int SIZE, double total, double rainFall[])
{
	double average = 0;
	for (int count = 0; count < SIZE; count++)
	{
		average = total / rainFall[count];
	}

	cout << "Average monthly rainfall: " << average << " inches" << endl;

	return average;
}

double driestMonth(double rainFall[], int SIZE, int dryMonth, string months[])
{
	double driest = 0;
	double wettest = 0;
	driest = wettest = rainFall[0];
	dryMonth = 0;

	for (int count = 0; count < SIZE; count++)
	{
		if (rainFall[count] < driest)
		{
			driest = rainFall[count];
			dryMonth = count;
		}
	}
	cout << "The least rain fell in " << months[dryMonth] << " with " << driest << " inches." << endl;

	return driest;
}

double wettestMonth(double rainFall[], int SIZE, int wetMonth, string months[])
{
	double driest = 0;
	double wettest = 0;
	driest = wettest = rainFall[0];
	wetMonth = 0;

	for (int count = 0; count < SIZE; count++)
	{
		if (rainFall[count] > wettest)
		{
			wettest = rainFall[count];
			wetMonth = count;
		}
	}
	cout << "The most rain fell in " << months[wetMonth] << " with " << wettest << " inches." << endl;

	return wettest;
}

void displayReport(double total, double rainFall[], int SIZE, double average, double driest, double dryMonth, string months[], double wettest, double wetMonth)
{
	total = getRainfall(rainFall, SIZE);
	average = averageRainfall(SIZE, total, rainFall);
	driest = driestMonth(rainFall, SIZE, dryMonth, months);
	wettest = wettestMonth(rainFall, SIZE, wetMonth, months);
}
