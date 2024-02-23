 #include "BitcoinExchange.hpp"

//--------------------------------------------------------------------------//
//                      - CONSTRUCTORS & DESTRUCTORS -                      //
//--------------------------------------------------------------------------//

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{

}

//--------------------------------------------------------------------------//
//                               - OPERATORS -                              //
//--------------------------------------------------------------------------//



//--------------------------------------------------------------------------//
//                           - GETTERS & SETTERS -                          //
//--------------------------------------------------------------------------//



//--------------------------------------------------------------------------//
//                           - MEMBER FUNCTIONS -                           //
//--------------------------------------------------------------------------//

std::map<std::string, long double> BitcoinExchange::createBtcMap()
{
    std::ifstream file("./data.csv");
    std::map<std::string, long double> btc;

    if (file.is_open())
    {
        std::string tmp;
        getline(file, tmp);
        
        while (std::getline(file, tmp))
        {
            std::string date = tmp.substr(0, 10);

            char *end;
            long double rate = strtod(tmp.substr(11).c_str(), &end);
            btc.insert(std::make_pair(date, rate));
        }
        return (btc);
    }
    else
        throw std::runtime_error("Error: Can' t open file data.csv, maybe it doesn' t exist ?\n");
    file.close();
    return (btc);
}

void    BitcoinExchange::evaluateInputWithBtc(std::string inputLine, std::map<std::string, long double> &btc)
{
    std::string date = inputLine.substr(0, 10);

    regex_t     regex;

    const char  *pattern("^[0-9]{4}-[0-9]{2}-[0-9]{2}");

    if (regcomp(&regex, pattern, REG_EXTENDED) != 0)
        throw std::runtime_error("Error: Regex compilation failed.");
    
    int status = regexec(&regex, date.c_str(), 0, NULL, 0);

    regfree(&regex);
    if (status == REG_NOMATCH)
        throw std::runtime_error("Error: bad input " + inputLine + ".");

    std::tm timeinfo;

    timeinfo.tm_year = atoi(inputLine.substr(0, 4).c_str()) - 2000;
    timeinfo.tm_mon = atoi(inputLine.substr(5, 2).c_str()) - 1;
    timeinfo.tm_mday = atoi(inputLine.substr(8, 2).c_str());

    time_t  rawtime = mktime(&timeinfo);
    std::cout << atoi(inputLine.substr(0, 4).c_str()) - 2000 << " " << atoi(inputLine.substr(5, 2).c_str()) - 1 << " " << atoi(inputLine.substr(8, 2).c_str()) << std::endl;
    std::cout << timeinfo.tm_year << " " << timeinfo.tm_mon << " " << timeinfo.tm_mday << std::endl;
    if (rawtime == -1)
        throw std::runtime_error("Error: bad date format " + inputLine + ".");

    if (inputLine.substr(10, 3) != " | ")
        throw std::runtime_error("Error: bad delimiter " + inputLine + ".");

    float value = atof(inputLine.substr(13).c_str());
    if (value < 0)
        throw std::runtime_error("Error: not a positive number");
    else if (value > 1000)
        throw std::out_of_range("Error: value out of range.");
    
    std::map<std::string, long double>::const_iterator it = btc.find(date);
    if (it != btc.end())
    {
        std::cout << date << " => " << value << " = " << it->second * value << std::setprecision(2) <<std::endl;
    }
    else
        throw std::out_of_range("Error: TODO.");
}

void    BitcoinExchange::exec(std::string input)
{
    std::map<std::string, long double> btc = createBtcMap();
    std::ifstream file(input.c_str());

    if (file.is_open())
    {
        std::string inputLine;

        getline(file, inputLine);
        if (inputLine != "date | value")
            throw std::runtime_error("Error: Wrong header' s input, it should start exactly with \"date | value\".\n");
        while(std::getline(file, inputLine))
        {
            try
            {
                evaluateInputWithBtc(inputLine, btc);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
    else
        throw std::runtime_error("Error: Can' t open file " + input + ", maybe it doesn' t exist ?\n");
}