#pragma once
#include <Windows.H>
#include <stdio.h>			// fprintf()
#include <stdlib.h>			// exit()
#include <string.h>			// strcmp()
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/filename.H>

class Menu
{
public:
	static void MyMenuCallback(Fl_Widget *w, void *);
	static void DiffCallback(Fl_Widget *w, void *);
	int size = 0;
};