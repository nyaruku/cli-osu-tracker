#pragma once
#include "ext.h"

void con_moveCursorUp(int lines) {
	std::cout << "\033[" << lines << "A" << std::flush;
}
void con_clear() {
	std::cout << "\033[2J\033[H" << std::flush;
}

// ansi console color codes
enum conCol {
	f_black = 30,
	f_red = 31,
	f_green = 32,
	f_yellow = 33,
	f_blue = 34,
	f_mangenta = 35,
	f_cyan = 36,
	f_white = 37,
	f_defaultColor = 39,
	b_black = 40,
	b_red = 41,
	b_green = 42,
	b_yellow = 43,
	b_blue = 44,
	b_mangenta = 45,
	b_cyan = 46,
	b_white = 47,
	b_defaultColor = 49
};


void setColor(conCol bg = conCol::b_defaultColor, conCol fg = conCol::f_defaultColor) {
	std::cout << "\033[" << bg << ";" << fg << "m";
}

void resetColor() {
	std::cout << "\033[0m";
}

int drawMenu(bool head, std::vector<std::string> menu) {
	for (int i = 0; i < menu.size(); i++) {
		setColor(b_defaultColor, f_white);
		std::cout << "[";
		setColor(b_defaultColor, f_green);
		std::cout << i;
		setColor(b_defaultColor, f_white);
		std::cout << "] - ";
		setColor(b_defaultColor, f_cyan);
		std::cout << menu[i];
		resetColor();
		std::cout << "\n";
	}

	std::cout << ">";
	std::string index;
	std::cin >> index;
	if (!isNumeric(index)) {
		con_clear();
		drawMenu(head,menu);
	}
	else {
		int i_index = std::stoi(index);
		return i_index;
	}
}