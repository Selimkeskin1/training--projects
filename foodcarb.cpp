
#include <iostream>
#include <string>
#include <vector>

class Food
{
private:
    int carbValue;
    std::string name;

public:
    Food()
    {
        std::cout << "cons. food" << std::endl;
    }
    ~Food()
    {
        std::cout << "decons. food" << std::endl;
    }
};

struct cPos
{
    char chartacter;
    std::vector<size_t> pos = {};
};

std::vector<cPos> positions;

int main()
{

    setlocale(LC_ALL, "Turkish");


/*
ç --> \u00E7
ğ --> \u011F
ı --> \u0131
ö --> \u00F6
ş --> \u015F
ü --> \u00FC

Ç --> \u00C7
İ --> \u0130
Ğ --> \u011E
Ö --> \u00D6
Ş --> \u015E
Ü --> \u00DC
*/

    const  char * foodTypeC =  "çorba";

//    char8_t test = 'ç';

     

    
  

  


   

    std::string food1 = "çorba";
 


    std::string favFood = {};
    std::cout << "what is your favorite foood" << std::endl;

    std::getline(std::cin >> std::ws, favFood);

    if (favFood == food1)
    {
        std::cout << "wonderful choise" << std::endl;
    }
    else
    {
        std::cout << "bad choice" << std::endl;
    }
    

    for( auto it = food1.begin(); it!= food1.end(); ++ it ){
        std::cout << *it << std::endl;
    }

    return 0;

    for (size_t i = 0; i < favFood.length(); i++)
    {

        //        std::cout << favFood[i] << std::endl;

        cPos chr = {};

        chr.chartacter = favFood[i];

        std::size_t found = 0;
        while (1)
        {

            auto foundPos = food1.find(favFood[i], found);
            if (foundPos == std::string::npos)
                break;

            chr.pos.push_back(foundPos);
            found = foundPos + 1;
        }
        //        if (chr.pos.size() > 1 )
        positions.push_back(chr);
    }

    for (size_t i = 0; i < positions.size(); ++i)
    {
        std::cout << positions.at(i).chartacter << std::endl;

        for (size_t j = 0; j < positions[i].pos.size(); ++j)
        {
            std::cout << positions[i].pos[j] << std::endl;
        }
        std::cout << "--------" << std::endl;
    }
}
