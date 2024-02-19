#include "BitcoinExchange.hpp"
#include <sstream>
//--------------------------------------------------------------------------//
//                           - MEMBER FUNCTIONS -                           //
//--------------------------------------------------------------------------//

std::map<std::string, float> getData(void)
{
    std::ifstream   			    input;
    std::string     			    database;
    std::map<std::string, float>	data;

    input.open("./data.csv");
    while (!input.eof())
    {
        input >> database;
        std::string fulldate = database.substr(0,10).erase(4,1).erase(6,1);
        float      rate = 0.0;
        std::stringstream convert;
        convert << database.substr(11);
        convert >> rate;
        data.insert(std::make_pair(fulldate,rate));
    }
    input.close();
    return (data);
}

int Parsing(int year, int month, int day, std::string raate ,float rate, std::string line)
{
    size_t idx = line.find("|");
    if (line[idx + 1] != ' ' || line[idx - 1] != ' ')
    {
        std::cerr << "Invalid separator" << std::endl;
        return (-1);
    }

    if (line.substr(4,1) != "-" && line.substr(7,1) != "-")
    {
        std::cerr << "Invalid date format" << std::endl;
        return (-1);
    }

    int count = 0;
    for (size_t i = 0; i < raate.length(); i++)
    {
        if (raate[0] == '.')
        {
            std::cerr << "Invalid rate format" << std::endl;
            return (-1);
        }
        if (raate[i] == '.')
            count++;
        if (!(isdigit(raate[i])) && raate[i] != '.' && (count == 1 || count == 0))
        {
            std::cerr << "Invalid rate format" << std::endl;
            return (-1);
        }
    }

    int month_limits[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year < 2009 || month < 1 || month > 12 || day < 1
        || (month == 2 && day == 29 && year % 4 != 0) || day > month_limits[month - 1] )
    {
        std::cerr << "Error: bad input => " << year << "-" << month << "-" << day << std::endl;
        return (-1);
    }
    if (rate <= 0)
    {
        std::cerr << "Error: not a positive number" << std::endl;
        return (-1);
    }
    if (rate >= 2147483648)
    {
        std::cerr << "Error: invalid value" << std::endl;
        return (-1);
    }
    return (0);
}

void    PrintOuput(std::string inputdate, float bitcoins, std::map<std::string, float> database)
{
    std::map<std::string, float>::iterator itb = database.begin();
    std::map<std::string, float>::iterator ite = database.end();
    bool    flag = false;

    for (; itb != ite; itb++)
    {
        if (itb->first == inputdate)
        {
            flag = true;
            break;
        }
    }
    if (flag == true)
    {
        std::cout << inputdate.insert(4,"-").insert(7,"-") << " => " << bitcoins << " = " << bitcoins * itb->second << "\n";
        flag = false;
    }
    else
    {
        ite = database.lower_bound(inputdate);
        ite--;
        std::cout << inputdate.insert(4,"-").insert(7,"-") << " => " << bitcoins << " = " << bitcoins * ite->second << "\n";
    }
}

void    ReadInput(std::string file, std::map<std::string, float> database)
{
    std::ifstream   input;
    std::string     line;

    input.open(file.c_str());

    if (input.fail())
    {
        std::cerr << "Cannot Open File" << std::endl;
        input.close();    
        return ;
    }
    std::getline(input, line);
    if (line != "date | value")
    {
        std::cerr << "Error: invalid input file format" << std::endl;
        input.close();
        return ;
    }

    while (std::getline(input, line))
    {
        if (line.empty())
        {
	    	std::cerr << "Error: Empty line in input file" << std::endl;
            continue ;
        }
        if (line.size() < 5 || line.size() < 8)
        {
            std::cerr << "Invalid date format" << std::endl;
            continue ;
        }
        std::string         fulldate;
        std::ostringstream  buffer;

        int year, month, day = 0;
        std::stringstream y, m, d;
        y << line.substr(0,4);
        m << line.substr(5,2);
        d << line.substr(8,2);
        y >> year;
        m >> month;
        d >> day;

        if (line.length() < 14)
        {
            std::cerr << "Invalid format" << std::endl;
            continue ;
        }
        std::string rate = line.substr(13, line.find('\0'));

        float   bitcoins = 0.00;
        std::stringstream bit(rate);
        bit >> bitcoins;

        if (month < 10 && day < 10)
            fulldate = static_cast<std::ostringstream&> (buffer << year * 10 << month * 10 << day).str();
        else if (day < 10)
            fulldate = static_cast<std::ostringstream&> (buffer << year << month * 10 << day).str();
        else if (month < 10)
            fulldate = static_cast<std::ostringstream&> (buffer << year * 10 << month << day).str();
        else
            fulldate = static_cast<std::ostringstream&> (buffer << year << month << day).str();
        if (Parsing(year, month, day, rate, bitcoins, line) == 0)
            PrintOuput(fulldate, bitcoins, database);
    }
    input.close();
}
