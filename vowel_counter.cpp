#include <iostream>
#include <string>

// The Wikipedia game program in c++, like putting stuff in a graph and stuff


void numOfVowels(std::string str) {
	int num_vowels = 0;

	int check[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < 10; j++) {
			if (str.at(i) == check[j]) {
				num_vowels++;
			}
		}
	}

	std::cout << "Number of vowels in the given input: " << num_vowels << '\n' << '\n';
}


int main() {
	std::string user_input = "0";
	std::string condition = "exit";

	while (true) {

		std::cout << "Enter an input: ";
		std::getline(std::cin, user_input);

		if (typeid(user_input).name() == typeid(condition).name()) {
			numOfVowels(user_input);
		}
		else if (user_input == condition) {
			break;
		}

	}
}

