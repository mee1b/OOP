#include <iostream>
#include <vector>
#include <fstream>

class address
{
private:
	int numberOfRecord{};
	std::string city{};
	std::string street{};
	std::string houseNumber{};
	std::string flatNumber{};
	std::string allRecord{};
	std::string buff{};
	const std::string COMMA{ ", " };
	std::vector<std::string> allRecordToOut{};
public:
	address()
	{
		numberOfRecord = 150;
		city = "Unknow";
		street = "Unknow";
		houseNumber = "Unknow";
		flatNumber = "Unknow";
		allRecord = "Unknow";
		buff = " ";
		allRecordToOut = {};
	}
	void setRecord();
	void sortAddress();
	void getRecord();
};

int main()
{
	setlocale(LC_ALL, "rus");
	address a;
	a.setRecord();
	a.sortAddress();
	a.getRecord();

	return EXIT_SUCCESS;
}

void address::setRecord()
{
	std::ifstream read("in.txt");
	if (read)
	{
		read >> numberOfRecord;
		for (int i = 0; i < numberOfRecord; ++i)
		{
			read >> city >> street >> houseNumber >> flatNumber;
			allRecord = city + COMMA + street + COMMA + houseNumber + COMMA + flatNumber;
			allRecordToOut.push_back(allRecord);
		}

	}
	else
	{
		std::cout << "Open error!" << std::endl;
	}
	read.close();
}

void address::sortAddress()
{
	for (int i = 0; i < numberOfRecord; ++i)
	{
		for (int j = 0; j < numberOfRecord; ++j)
		{
			if (allRecordToOut[i][0] < allRecordToOut[j][0])
			{
				buff = allRecordToOut[i];
				allRecordToOut[i] = allRecordToOut[j];
				allRecordToOut[j] = buff;
			}
		}
	}
}

void address::getRecord()
{
	std::ofstream record("out.txt");
	if (record)
	{
		record << numberOfRecord << std::endl;
		for (int i = 0; i < numberOfRecord; ++i)
		{
			record << allRecordToOut[i] << std::endl;
		}
	}
	else
	{
		std::cout << "Open error!" << std::endl;
	}
	record.close();
}