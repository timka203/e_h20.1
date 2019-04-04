#include <iostream>
#include< Windows.h>
using namespace std;


class clock
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	void set_hours()
	{
		do
		{
			cout << "set hours" << endl;
			cin >> hours;
		} while (hours < 0 || hours >= 23);
	}
	void set_hours(int a)
	{
		if (hours >= 0 || hours < 24)
			hours = a;
		else
			hours = 0;
	}
	void set_minutes(int a)
	{
		if (minutes >= 0 || minutes < 60)
			minutes = a;
		else
			minutes = 0;
	}
	void set_seconds(int a)
	{
		if (seconds >= 0 || seconds < 60)
			seconds = a;
		else
			seconds = 0;
	}
	int get_hours()
	{
		return hours;
	}
	int get_minutes()
	{
		return minutes;
	}
	int get_seconds()
	{
		return seconds;
	}
	void print() {
		if (hours < 10) cout << "0";
		cout << hours << ":";
		if (minutes < 10) cout << "0";
		cout << minutes << ":";
		if (seconds < 10) cout << "0";
		cout << seconds << endl;
	}
	void addHours()
	{
		if (hours >= 23)
		{
			hours = 0;
		}
		else hours++;
	}
	void addMinutes()
	{
		minutes++;
		if (minutes == 60)
		{
			minutes = 0;
			addHours();
		}

	}
	void addSeconds()
	{
		if (seconds == 59)
		{
			seconds = 0;
			addMinutes();
		}
		else seconds++;
	}
	void addManyseconds(int g)
	{
		for (int i = 0; i <g; i++)
		{
			addSeconds();

		}

	}
	void addManyminutes(int g)
	{
		g *= 60;
		addManyseconds(g);
	}
	void addManyhours(int g)
	{
		g *= 60;
		addManyminutes(g);
	}

};
void main()
{
	clock a;
	a.set_hours(23);
	a.set_minutes(59);
	a.set_seconds(40);
	int g;
	cout << "Сколько минут добавить?(minutes)" << endl;
	cin >> g;
	a.addManyminutes(g);
	cout << "Сколько секунд добавить?(seconds)" << endl;
	cin >> g;
	a.addManyseconds(g);
	cout << "Сколько часов добавить?(hours)" << endl;
	cin >> g;
	a.addManyhours(g);

	a.print();
	/*while (1) {
		a.print();
		a.addSeconds();
		Sleep(1000);
		system("cls");
	}*/

	system("pause");
}