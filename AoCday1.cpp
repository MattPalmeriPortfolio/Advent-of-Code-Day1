#include <iostream>
#include <fstream>

int main()
{
	using namespace std;
	//initialize variables
	ifstream inStream;
	int size = 0;
	int next, previous, increased = 0;
	//Part 1: Count the number of times a number in the input data is larger than the previous number
	inStream.open("input1.txt");
	if (inStream.fail())
		exit(1);
	inStream >> previous;
	while (inStream >> next)
	{
		if (next > previous)
			increased++;
		previous = next;
		size++; //determining size for creation of array in part 2
	}
	inStream.close();
	cout << "Part 1: increased " << increased << " times\n";
	//Part 2: consider sums in a three-measurement sliding window, and determine if they are larger than the previous sum
	//initialize variables
	increased = 1;
	int currentIndex = 1, newSum, oldSum;
	int* values;
	//create array to hold values
	values = new int[size];
	//open stream, read in values
	inStream.open("input1.txt");
	if (inStream.fail())
		exit(1);
	for (int i = 0; inStream >> next && i < size; i++)
	{
		values[i] = next;
	}
	inStream.close();
	//calculate times increased
	oldSum = values[0] + values[1] + values[2];
	for (currentIndex; currentIndex + 2 < size; currentIndex++)
	{
		newSum = values[currentIndex] + values[currentIndex + 1] + values[currentIndex + 2];
		if (newSum > oldSum)
			increased++;
		oldSum = newSum;
	}
	delete[] values;
	//output
	cout << "Part 2: increased " << increased << " times\n";
	return 0;
}