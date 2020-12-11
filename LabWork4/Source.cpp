#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

class Clock {
public:
	void setClockName(const string &clockName) {
		this->clockName = clockName;
	}

	void setManufacturer(const string &manufacturer) {
		this->manufacturer = manufacturer;
	}

	virtual void setTime(const double &time) = 0;

	const string &getClockName() const {
		return clockName;
	}

	const string &getManufacturer() const {
		return manufacturer;
	}

	virtual const double &getTime() const = 0;

private:
	string clockName;
	string manufacturer;
};

class MechanicalClock : public Clock {
public:
	MechanicalClock() {
		time = 0.0;
	}

	void setTime(const double &time) override {
		this->time = time;
	}

	const double &getTime() const override {
		return time;
	}

private:
	double time;
};

class DigitalClock : public Clock {
public:
	DigitalClock() {
		time = 0.0;
	}

	void setTime(const double &time) override {
		this->time = time;
	}

	const double &getTime() const override {
		return time;
	}

private:
	double time;
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Clock *> clocks;
	while (true) {
		cout << "1. �������� ������\n";
		cout << "2. �������� ������\n";
		cout << "0. ��������� ������\n";

		char ch;
		do {
			ch = _getch();
		} while (!(ch >= '0' && ch <= '2'));
	
		if (ch == '1') {
			Clock *clock;
			string str;

			cout << "\n1. ������������ ����\n";
			cout << "2. �������� ����\n";

			do {
				ch = _getch();
			} while (!(ch >= '1' && ch <= '2'));
		
			if (ch == '1') {
				clock = new MechanicalClock();
			}
			else {
				clock = new DigitalClock();
			}

			cout << "\n�������� �����: ";
			getline(cin, str);
			clock->setClockName(str);

			cout << "�������������: ";
			getline(cin, str);
			clock->setManufacturer(str);

			cout << "������� �����: ";
			getline(cin, str);
			clock->setTime(atof(str.c_str()));
		
			clocks.push_back(clock);
		}
		else if (ch == '2') {
			for (const Clock *clock : clocks) {
				cout << "\n�������� �����: " << clock->getClockName() << endl;
				cout << "�������������: " << clock->getManufacturer() << endl;
				cout << "�����: " << clock->getTime() << endl;
			}
		}
		else {
			for (const Clock *clock : clocks) {
				delete clock;
			}
			return 0;
		}
		cout << endl;
	}
}