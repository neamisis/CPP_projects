#include <iostream>


void k2p(float user_input) {
	std::cout << "Enter your weight in Kg" << std::endl;
	std::cin >> user_input;
	std::cout << "Your weight in pounds is " << user_input * 2.205 << std::endl;
}


void p2k(float user_input) {
	std::cout << "Enter your weight in pounds" << std::endl;
	std::cin >> user_input;
	std::cout << "Your weight in kg is " << user_input * (1/2.205) << std::endl;
}


int main() {
	float user_input = 0;
	
	while (true) {
		std::cout << "Do you want to convert kg to lbs or lbs to kg? (0 for kg to lbs, 1 for lbs to kg, 2 for exiting)" << std::endl;

		std::cin >> user_input;
		
		if (user_input == 2) {
			break;
		}
		else if (user_input) {
			p2k(user_input);
		}
		else if (!user_input) {
			k2p(user_input);
		}
	}
}