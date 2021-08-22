#include <iostream>
#include <string>

//THIS IS BROKEN AF FAM 
//I HAVEN'T FIXED THE BUGS YET

char smol_alphabets[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int Index(char arr[], char a) {
	for (int i = 0; i < 26; i++) {
		if (arr[i] == a) {
			return i;
		}
		else if (i == 26) {
			return -1;
		}
	}
}


std::string CaeserEncoder(std::string str, int shift) {
	for (int i = 0; i < str.length(); i++) {
     	int index = Index(smol_alphabets, str.at(i)) + shift;

		if (index >= 26) {
			index %= 26;
		}

		std::cout << ((index - shift)) << '\n';

		if ((index - shift) != -1) {
			str.at(i) = smol_alphabets[index];
		}
		else {
			str.at(i) = str.at(i);
		}
	}

	return str;
}


void CaeserDecoder(std::string str) {
	for (int shift = 1; shift < 26; shift++) {
		std::string new_str = str;

		for (int i = 0; i < new_str.length(); i++) {
			int index = Index(smol_alphabets, new_str.at(i)) + shift;

			if (index >= 26) {
				index %= 26;
			}

			new_str.at(i) = smol_alphabets[index];
		}
		
		std::cout << "Shift: " << shift << ' ' << "message: " << new_str << '\n' << '\n';
	}
}


int main() {
	
	std::string user_input;
	std::string input;
	std::string type_check = "string";

	int shift_number;

	while (true) {
		std::cout << "(type \"-\" to exit)";
		std::cout << '\n' << "Do you want to Encode or Decode using Caeser cipher?: ";
		std::getline(std::cin, user_input);

		if (typeid(user_input).name() == typeid(type_check).name()) {
			if (user_input == "encode") {
				while (true) {
					std::cout << '\n' << '\n' << "Enter a sentence: ";
					std::getline(std::cin, input);

					std::cout << "Enter the amount to shift it by: ";
					std::cin >> shift_number;

					if ((typeid(input).name() == typeid(type_check).name()) and (typeid(shift_number).name() == typeid(0).name())) {
						std::cout << '\n' << CaeserEncoder(input, shift_number);
					}
					else if (user_input == "-") {
						break;
					}
				}
			} 
			if (user_input == "decode") {
				while (true) {
					std::cout << '\n' << '\n' << "Enter a sentence to decode: ";
					std::getline(std::cin, input);

					if ((typeid(input).name() == typeid(type_check).name()) and (typeid(shift_number).name() == typeid(0).name())) {
						std::cout << '\n';

						CaeserDecoder(input);
					}
					else if (user_input == "-") {
						break;
					}
				}
				}
			else if (user_input == "-") {
				break;
			}
		}
	}
}
