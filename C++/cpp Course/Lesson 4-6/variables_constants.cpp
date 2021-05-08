#include <iostream>

using namespace std;

int main()
{
	const double price_per_sqft = 2.32;
	int length = 0;
	int width = (0); // Constructor initialization
	int area = 0;

	cout << "Enter dimension of room as \"l w\": ";
	cin >> length >> width;
	area = length*width;
	cout << "Room is " << area << endl;

	cout << "Size of width (int): " << sizeof(width) << " bytes" << endl;
	cout << "Price to carpet entire room: $" << area*price_per_sqft;

	return 0;
}