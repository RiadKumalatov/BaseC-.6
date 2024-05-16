#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Address
{
private:
	std::string city = "empty";
	std::string street = "empty";
	std::string houseNumber = "empty";
	std::string apartmentNumber = "empty";

public:
	Address(std::string city, std::string street, std::string houseNumber, std::string apartmentNumber)
		: city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}

	std::string get_output_adress();
};

std::string Address::get_output_adress() 
{
	return city + ", " + street + ", " + houseNumber + ", " + apartmentNumber;
}

int main() 
{
	std::ifstream input("D:\\in.txt");
	std::ofstream output("D:\\out.txt");

	if (!input.is_open()) 
	{
		std::cerr << "Error opening input file." << std::endl;
		return 1;
	}

	int n;
	input >> n;
	input.ignore();

	std::vector<Address> addresses;
	addresses.reserve(n);

	for (size_t i = 0; i < n; i++) 
	{
		std::string city, street, houseNumber, apartmentNumber;

		std::getline(input, city);
		std::getline(input, street);
		std::getline(input, houseNumber);
		std::getline(input, apartmentNumber);

		addresses.emplace_back(city, street, houseNumber, apartmentNumber);
	}

	output << n << std::endl;
	for (int i = n - 1; i >= 0; i--) 
	{
		output << addresses[i].get_output_adress() << std::endl;
	}

	input.close();
	output.close();

	return 0;
}