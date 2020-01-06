
	// Project: Code A Thon 2018
	//			Intro Level
	// Atuhors: Joe wilson, Ken Lee, Shujaullah Ahsan
	//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;



int time24hour(int, char);
int timeDifference(int, int);

int main()
{
	int bTrainHour, cTrainHour, dTrainHour, eTrainHour;
	int bTrainMin, cTrainMin, dTrainMin, eTrainMin;
	char bAmPm, cAmPm, dAmPm, eAmPm;

	// Time information from http://www.dreamincode.net/forums/topic/50727-convert-current-time-into-seconds/

//JOE
	cout << "Enter the time for the following trains (ex. 1 35 p) " << endl;
	cout << "B: ";
	cin >> bTrainHour >> bTrainMin >> bAmPm;
	cout << "C: ";
	cin >> cTrainHour >> cTrainMin >> cAmPm;
	cout << "D: ";
	cin >> dTrainHour >> dTrainMin >> dAmPm;
	cout << "E: ";
	cin >> eTrainHour >> eTrainMin >> eAmPm;

//KEN
	bTrainHour = time24hour(bTrainHour, bAmPm);
	cTrainHour = time24hour(cTrainHour, cAmPm);
	dTrainHour = time24hour(dTrainHour, dAmPm);
	eTrainHour = time24hour(eTrainHour, eAmPm);

	int bDifference = timeDifference(bTrainHour, bTrainMin);
	int cDifference = timeDifference(cTrainHour, cTrainMin);
	int dDifference = timeDifference(dTrainHour, dTrainMin);
	int eDifference = timeDifference(eTrainHour, eTrainMin);

	/*if (bDifference > cDifference && bDifference > dDifference && bDifference > eDifference)
	{
		cout << "B Train in " << bDifference << "mintues" << endl;
		if (cDifference > dDifference && cDifference > eDifference)
			cout << "C Train in " << cDifference << "mintues" << endl;
		else if (dDifference > eDifference)
			cout << "D Train in " << dDifference << "mintues" << endl;
		else 
			cout << "E Train in " << eDifference << "mintues" << endl;
	}
	else if (cDifference > dDifference && cDifference > eDifference)
	{
		cout << "C Train in " << cDifference << "mintues" << endl;
	}*/

	//if (bDifference > cDifference)
	//{
	//	if (bDifference > dDifference)
	//	{
	//		if (bDifference > eDifference)
	//			cout << "B Train in " << bDifference << "mintues" << endl;
	//		else
	//		{
	//			cout << "E Train in " << eDifference << "mintues" << endl;
	//			cout << "B Train in " << bDifference << "mintues" << endl;
	//			if (cDifference > dDifference)
	//			{
	//				cout << "C Train in " << cDifference << "mintues" << endl;
	//				cout << "D Train in " << dDifference << "mintues" << endl;
	//			}

	//			else
	//			{
	//				cout << "D Train in " << dDifference << "mintues" << endl;
	//				cout << "C Train in " << cDifference << "mintues" << endl;
	//			}

	//		}


	//	}
	//	else if (dDifference > eDifference)
	//	{
	//		cout << "D Train in " << dDifference << "mintues" << endl;
	//		if ()
	//	}
	//}

	cout << "\nTrain Schedule: " << endl;
	cout << "B Train in " << bDifference << "mintues" << endl;
	cout << "C Train in " << cDifference << "mintues" << endl;
	cout << "D Train in " << dDifference << "mintues" << endl;
	cout << "E Train in " << eDifference << "mintues" << endl;

	return 0;
}

int
	timeDifference(int thour, int tmin)
{
	int totalDifference;
	int minDifference;
	int hourDifference;
	int hour, min;

//Shujaullah
// Time information from http://www.dreamincode.net/forums/topic/50727-convert-current-time-into-seconds/

	time_t rawTime;
	struct tm * timeinfo;

	time(&rawTime);
	timeinfo = localtime(&rawTime);
	hour = timeinfo->tm_hour;
	min = timeinfo->tm_min;

	//cout << hour << " and " << min;
	minDifference = tmin - min;
	hourDifference = thour - hour;
	//cout << hourDifference << " and " << minDifference;

	totalDifference = hourDifference * 60 + minDifference;

	return (totalDifference);
}

//JOE
int
	time24hour(int hour, char amPm)
{
	if (amPm == 'p')
		hour = hour + 12;

	return (hour);
}
