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
	const std::string COMMA{ ", " };
	std::vector<std::string> allRecordToOut{};
public:
	address()
	{
		numberOfRecord = 0;
		city = "Unknow";
		street = "Unknow";
		houseNumber= "Unknow";
		flatNumber = "Unknow";
		allRecord = "Unknow";
		allRecordToOut = {};
	}
	void setRecord()
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
	void getRecord()
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
};

int main()
{
	address a;
	a.setRecord();
	a.getRecord();

	return EXIT_SUCCESS;
}