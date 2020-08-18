#define _USE_MATH_DEFINES
#include <iostream>
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
#include "GUI.h"
#include <time.h>
#include <FL/Fl_Text_Display.H>
using namespace std;

int input1 = 0;
int hour = 0, minutes = 0;

int xmax = 300;
int ymax = 300;


struct Hands : Open_polyline
{
	Hands(Point center, Point end, Fl_Color color)
	{
		add(Point(center));
		add(Point(end));
		c = color;
	}

	void draw_lines() const;
	Fl_Color c;
};

void Hands::draw_lines() const
{
	fl_color(c);
	Open_polyline::draw_lines();
}

struct Analog_clock_window : Window {
	Analog_clock_window(Point xy, int w, int h, const string& title)
		: Window(xy, w, h, title)
	{
		
		while (1!=2) { //vamistiko kolpo gia infinite loop
			Fl::wait();
			Sleep(1000);
			draw_shape();
			Fl::redraw();
		}
	}

	Vector_ref<Shape> s;
	void draw_shape();

	

private:
	time_t rawtime;
	bool button_pushed;


	static void cb_quit(Address, Address addr) { reference_to<Analog_clock_window>(addr).quit(); }
	void quit() { hide(); }
};



void Analog_clock_window::draw_shape()
{
	if (s.size() != 0)
	{
		for (int i = 0; i < s.size(); i++)
		{
			detach(s[i]);
		}
	}

	Point center(xmax / 2, ymax / 2);
	int i = 0;
	while (i < 12)
	{
		Point pt1(0, -100);
		Point pt2(0, -90);
		double rad = ((2 * M_PI) / 12) * i;

		Point rotated_pt1 = Point(cos(rad) * pt1.x - sin(rad) * pt1.y, sin(rad) * pt1.x + cos(rad) * pt1.y);
		Point rotated_pt2 = Point(cos(rad) * pt2.x - sin(rad) * pt2.y, sin(rad) * pt2.x + cos(rad) * pt2.y);

		s.push_back(new Hands(Point(rotated_pt1.x + center.x, rotated_pt1.y + center.y), Point(rotated_pt2.x + center.x, rotated_pt2.y + center.y), Color::black));
		attach(s[s.size() - 1]);
		i++;
	}

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
	time_t rawT;
	time(&rawT);


	struct tm* timeinfo;
	if (input1 == 1) {
		//edw pairnoume tin trexousa wra
		timeinfo = localtime(&rawT);
		asctime(timeinfo);
	}
	else if (input1 == 2) {
		//edw xrhsimopoiw ta inputs
		timeinfo = localtime(&rawT);
		timeinfo->tm_hour = hour;
		timeinfo->tm_min = minutes;
		asctime(timeinfo);
	}
	else {
		return;
	}

	
	// gia ta lepta
	Point origin_Pt2(0, -80);

	double rad = timeinfo->tm_min * ((2 * M_PI) / 60);
	Point rotated_Pt2 = Point(cos(rad) * origin_Pt2.x - sin(rad) * origin_Pt2.y, sin(rad) * origin_Pt2.x + cos(rad) * origin_Pt2.y);

	s.push_back(new Hands(center, Point(rotated_Pt2.x + center.x, rotated_Pt2.y + center.y), Color::blue));
	attach(s[s.size() - 1]);

	// gia tin wra
	Point origin_Pt3(0, -60);

	rad = timeinfo->tm_hour * ((2 * M_PI) / 12) + (timeinfo->tm_min * ((2 * M_PI) / 60)) / 12;
	Point rotated_Pt3 = Point(cos(rad) * origin_Pt3.x - sin(rad) * origin_Pt3.y, sin(rad) * origin_Pt3.x + cos(rad) * origin_Pt3.y);

	s.push_back(new Hands(center, Point(rotated_Pt3.x + center.x, rotated_Pt3.y + center.y), Color::black));
	attach(s[s.size() - 1]);
}

int giouxou() {
	try
	{
		Analog_clock_window win(Point(100, 100), xmax, ymax + 20, "csd4112");

		return gui_main();
	}
	catch (exception & e) {
		cerr << "error: " << e.what() << '\n';
		//keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Unknown exception!\n";
		//keep_window_open();
		return 2;
	}
}

int main() {

	//elegxos 
	cout << "1.Current time." << endl << "2.Your time." << endl;
	cin >> input1;
	if (input1 == 2) {
		cout << "Enter hour and minutes" << endl;
		cout << "Hour" << endl;
		cin >> hour;
		if (hour > 24 || hour < 1) {
			cout << "Ta piame" << endl;
			return 0;
		}
		cout << "Minutes" << endl;
		cin >> minutes;
		if(minutes>60 || minutes < 0){
			cout << "Ta piame" << endl;
			return 0;
		}
	}

	//ekei skr skr 
	return giouxou();

}