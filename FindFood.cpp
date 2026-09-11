#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <tuple>

struct cPos
{
  std::string chartacter;
  std::vector<size_t> pos = {};
};

std::vector<cPos> positions;

struct chCount
{
  size_t row;
  size_t column;
  size_t count;
};

std::vector<chCount> scanning;

int main()
{

  std::map<std::string, std::string> mymap = {
      {"sıfır", "0"},
      {"bir", "1"},
      {"iki", "2"},
      {"üç", "3"},
      {"dört", "4"},
      {"beş", "5"},
      {"altı", "6"},
      {"yedi", "7"},
      {"sekiz", "8"},
      {"dokuz", "9"},
      {"on", "(10)"},
      {"yirmi", "(20)"},
      {"otuz", "(30)"},
      {"kırk", "(40)"},
      {"elli", "(50)"},
      {"altmış", "(60)"},
      {"yetmiş", "(70)"},
      {"seksen", "(80)"},
      {"doksan", "(90)"}

      /*
            {"yüz", 100},
            {"bin", 1000},
            {"milyon", 1000000},
            {"milyar", 1000000000},
            {"trilyon", 1000000000000}
      */

  };

  std::unordered_map<std::string, int> basamak = {
      {"milyar", 1000000000},
      {"milyon", 1000000},
      {"bin", 1000},
      {"yüz", 100}

  };

  std::list<std::tuple<std::string, int, std::string>> basamaklar = {
      std::make_tuple("milyar", 1000000000, "~"),
      std::make_tuple("milyon", 1000000, "$"),
      std::make_tuple("bin", 1000, "&"),
      //      std::make_tuple("yüz", 100, "%"),

      std::make_tuple("yüz", 100, "*")

  };

  std::list<std::tuple<std::string, std::string, int>> digits = {
      {"sıfır", "0", 0},
      {"bir", "1", 1},
      {"iki", "2", 2},
      {"üç", "3", 3},
      {"dört", "4", 4},
      {"beş", "5", 5},
      {"altı", "6", 6},
      {"yedi", "7", 7},
      {"sekiz", "8", 8},
      {"dokuz", "9", 9},
      {"on", "(10)", 10},
      {"yirmi", "(20)", 20},
      {"otuz", "(30)", 30},
      {"kırk", "(40)", 40},
      {"elli", "(50)", 50},
      {"altmış", "(60)", 60},
      {"yetmiş", "(70)", 70},
      {"seksen", "(80)", 80},
      {"doksan", "(90)", 90}};

  size_t pos = 0;

  std::string numberForecast = {};

  std::getline(std::cin >> std::ws, numberForecast);

  int numberIntFormat = 0;

  for (auto &x : basamaklar)
  {
    std::cout << std::get<0>(x) << std::endl;
  }

  //    while (1)
  //    {

  for (auto &x : basamaklar)
  {

    while (1)
    {
      auto findPos = numberForecast.find(std::get<0>(x), pos);
      if (findPos != std::string::npos)
      {
        numberForecast.replace(findPos, std::get<0>(x).length(), std::get<2>(x));
        pos = findPos + 1;
      }
      else
      {
        break;
      }
    }

    //    if (std::get<2>(x) == "%")
    if (std::get<2>(x) == "&")
    {
      pos = 0;
    }
  }

  for (auto &x : digits)
  {
    pos = 0;
    while (1)
    {
      auto findPos = numberForecast.find(std::get<0>(x), pos);
      if (findPos != std::string::npos)
      {
        numberForecast.replace(findPos, std::get<0>(x).length(), std::get<1>(x));
        pos = findPos + 1;
      }
      else
      {
        break;
      }
    }
  }

  std::cout << numberForecast << std::endl;

  std::string buffer = {};

  size_t bufferInt1 = 0;
  size_t bufferInt2 = 0;
  size_t bufferInt3 = 0;

  // note: explicitly specifying this returns a double
  auto getAvailableBuffer{[bufferInt1, bufferInt2, bufferInt3](size_t &x, size_t &y, size_t &z) -> size_t *
                          {
                            if (x == 0)
                              return &x;
                            else if (y == 0)
                              return &y;
                            else if (z == 0)
                              return &z;
                          }

  };

  // * ( getAvailableBuffer (bufferInt1, bufferInt2, bufferInt3 ) )  = 10;
  // * ( getAvailableBuffer (bufferInt1, bufferInt2, bufferInt3 ) )  = 20;
  // * ( getAvailableBuffer (bufferInt1, bufferInt3, bufferInt3 ) )  = 30;

  size_t intForecast = 0;
  size_t calc = 0;

  for (size_t index = 0; index < numberForecast.length(); ++index)
  {

    if ((numberForecast[index] == '(') || (numberForecast[index] == ' '))
    {
      continue;
    }
    else if (numberForecast[index] == ')')
    {

      *(getAvailableBuffer(bufferInt1, bufferInt2, bufferInt3)) = std::stoi(buffer);

      /*
      if (bufferInt1 == 0)
      {
        bufferInt1 = std::stoi(buffer);
      }
      else if (bufferInt2 == 0)
      {
        bufferInt2 = std::stoi(buffer);
      }
      else if (bufferInt3 == 0)
      {
        bufferInt3 = std::stoi(buffer);
      }
*/

      buffer = {};
    }
    else if (numberForecast[index] == '~')
    {

      if ((buffer.length() != 0))
      {

        /*
                if (bufferInt1 == 0)
                {
                  bufferInt1 = std::stoi(buffer);
                }
                else if (bufferInt2 == 0)
                {
                  bufferInt2 = std::stoi(buffer);
                }
                else if (bufferInt3 == 0)
                {
                  bufferInt3 = std::stoi(buffer);
                }
        */

        *(getAvailableBuffer(bufferInt1, bufferInt2, bufferInt3)) = std::stoi(buffer);
      }

      if ((bufferInt1 == 0) && (bufferInt2 == 0) && (bufferInt3 == 0))
        bufferInt1 = 1;

      intForecast += (bufferInt1 + bufferInt2 + bufferInt3) * 1000000000;
      buffer = {};

      bufferInt1 = 0;
      bufferInt2 = 0;
      bufferInt3 = 0;
    }

    else if (numberForecast[index] == '*')
    {

      size_t hundreds = 0;

      if ((buffer.length() == 0))
      {
        hundreds = 100;
      }
      else
      {
        hundreds = 100 * std::stoi(buffer);
      }

      /*
            if (bufferInt1 == 0)
            {
              bufferInt1 = hundreds;
            }
            else if (bufferInt2 == 0)
            {
              bufferInt2 = hundreds;
            }
            else if (bufferInt3 == 0)
            {
              bufferInt3 = hundreds;
            }
      */
      *(getAvailableBuffer(bufferInt1, bufferInt2, bufferInt3)) = hundreds;

      buffer = {};
    }

    else if (numberForecast[index] == '$') // milyonlar
    {

      if ((buffer.length() != 0))
      {

        *(getAvailableBuffer(bufferInt1, bufferInt2, bufferInt3)) = std::stoi(buffer);
        /*
                if (bufferInt1 == 0)
                {
                  bufferInt1 = std::stoi(buffer);
                }
                else if (bufferInt2 == 0)
                {
                  bufferInt2 = std::stoi(buffer);
                }
                else if (bufferInt3 == 0)
                {
                  bufferInt3 = std::stoi(buffer);
                }
        */
      }

      if ((bufferInt1 == 0) && (bufferInt2 == 0) && (bufferInt3 == 0))
        bufferInt1 = 1;

      intForecast += (bufferInt1 + bufferInt2 + bufferInt3) * 1000000;
      buffer = {};

      bufferInt1 = 0;
      bufferInt2 = 0;
      bufferInt3 = 0;
    }
    else if (numberForecast[index] == '&') // binler
    {

      if ((buffer.length() != 0))
      {
        /*
                if (bufferInt1 == 0)
                {
                  bufferInt1 = std::stoi(buffer);
                }
                else if (bufferInt2 == 0)
                {
                  bufferInt2 = std::stoi(buffer);
                }
                else if (bufferInt3 == 0)
                {
                  bufferInt3 = std::stoi(buffer);
                }
        */

        *(getAvailableBuffer(bufferInt1, bufferInt2, bufferInt3)) = std::stoi(buffer);
      }

      if ((bufferInt1 == 0) && (bufferInt2 == 0) && (bufferInt3 == 0))
        bufferInt1 = 1;

      intForecast += (bufferInt1 + bufferInt2 + bufferInt3) * 1000;
      buffer = {};

      bufferInt1 = 0;
      bufferInt2 = 0;
      bufferInt3 = 0;
    }

    /*
        else if (numberForecast[index] == '%') // yüzler
        {

          calc = 0;
          if ((buffer.length() != 0))
          {
            calc = std::stoi(buffer);

            if (bufferInt1 == 0)
            {
              bufferInt1 = std::stoi(buffer);
            }
            else if (bufferInt2 == 0)
            {
              bufferInt2 = std::stoi(buffer);
            }
            else if (bufferInt3 == 0)
            {
              bufferInt3 = std::stoi(buffer);
            }
          }

          intForecast += (bufferInt1 + bufferInt2 + bufferInt3) * 100;
          buffer = {};

          bufferInt1 = 0;
          bufferInt2 = 0;
          bufferInt3 = 0;
        }

    */

    else
    {
      buffer.append(1, numberForecast[index]);
    }
  }

  /*
  calc = 0;
  if ((buffer.length() != 0))
  {
    calc = std::stoi(buffer);

    if (bufferInt1 == 0)
    {
      bufferInt1 = std::stoi(buffer);
    }
    else if (bufferInt2 == 0)
    {
      bufferInt2 = std::stoi(buffer);
    }
    else if (bufferInt3 == 0)
    {
      bufferInt3 = std::stoi(buffer);
    }
  }
*/

  if ((buffer.length() != 0))
  {
    *(getAvailableBuffer(bufferInt1, bufferInt2, bufferInt3)) = std::stoi(buffer);
  }

  intForecast += (bufferInt1 + bufferInt2 + bufferInt3);
  std::cout << intForecast << std::endl;

  //    }

  return 0;

  while (1)
  {

    for (auto &x : mymap)
    {
      std::cout << x.first << ": " << x.second << '\n';
      auto findPos = numberForecast.find_first_of(x.first, pos);
      if (findPos != std::string::npos)
      {
        pos = findPos + 1;
      }
      else
      {
      }
    }
  }

  return 0;

  std::string foodSource = "gözde simit";
  std::array<std::string, 12> trCharacters = {"ç", "Ç", "ğ", "Ğ", "ı", "I", "ö", "Ö", "ş", "Ş", "ü", "Ü"};

  const char *test = "simit";

  // test stringeki karakterlerin foodSource daki yerlerini bul pozisyonlarını kaydet
  // daha sonra test stringi foodSource daki gibimi dizilmiş kontrol et!

  std::string trCh = {};
  std::string searchCh = {};
  setlocale(LC_ALL, "Turkish");

  //  test stringiden karakter katakter kaynak string deki pozisyonlarını bul
  // pozisyonlar  kaynak metindeki gibi küçükten büyüğe olmalı
  while (*test)
  {
    bool foundTrCh = false;

    trCh = {};
    trCh.append(1, *(test));
    trCh.append(1, *(test + 1));
    for (auto it = trCharacters.begin(); it != trCharacters.end(); it++)
    {
      if (*it == trCh)
      {
        foundTrCh = true;
        break;
      }
    }

    searchCh = {};
    if (foundTrCh)
    {
      test++;
      searchCh = trCh;
    }
    else
    {
      searchCh = trCh[0];
    }

    test++;

    cPos chr = {};

    chr.chartacter = searchCh;

    std::size_t found = 0;
    while (1)
    {

      auto foundPos = foodSource.find(searchCh, found);
      if (foundPos == std::string::npos)
        break;

      chr.pos.push_back(foundPos);
      found = foundPos + 1;
    }
    if (chr.pos.size() > 0)
    {
      positions.push_back(chr);
    }

    /*

        if (trCh == "ö" or trCh == "Ö")
        {
          std::wcout << "ö harfi" << std::endl;
          test++;
        }
        else if (trCh == "ş")
        {
          std::cout << "ş harfi" << std::endl;
          test++;
        }
        else if (trCh == "ç")
        {
          std::cout << "ç harfi" << std::endl;
          test++;
        }
        else if (trCh == "ğ")
        {
          std::cout << "ğ harfi" << std::endl;
          test++;
        }
        else if (trCh == "ı")
        {
          std::cout << "ı harfi" << std::endl;
          test++;
        }
        else if (trCh == "ö")
        {
          std::cout << "ö harfi" << std::endl;
          test++;
        }
        else if (trCh == "ş")
        {
          std::cout << "ş harfi" << std::endl;
          test++;
        }
        else if (trCh == "ü")
        {
          std::cout << "ü harfi" << std::endl;
          test++;
        }
        else
        {
          std::cout << trCh[0] << " harfi" << std::endl;
        }
        test++;
        */
  }

  /*




  */

  for (size_t i = 0; i < positions.size(); ++i)
  {
    std::cout << "----------" << std::endl;
    std::cout << positions[i].chartacter << std::endl;

    for (int j = 0; j < positions[i].pos.size(); ++j)
    {
      std::cout << positions[i].pos[j] << std::endl;
    }
    std::cout << "----------" << std::endl;
  }

  std::cout << "scanning begin" << std::endl;
  std::cout << "------";

  size_t row = 0;
  size_t coloumn = 0;
  size_t lastPosition = 0;

  size_t value1 = 0;
  size_t value2 = 0;

  for (size_t row1 = 0; row1 < positions.size(); ++row1)
  {

    for (size_t column1 = 0; column1 < positions[row1].pos.size(); ++column1)
    {

      chCount ch = {};
      ch.count = 1;
      ch.row = row1;
      ch.column = column1;

      value1 = positions[row1].pos[column1];

      for (size_t row2 = (row1 + 1); row2 < positions.size(); ++row2)
      {

        for (size_t column2 = 0; column2 < positions[row2].pos.size(); column2++)
        {
          value2 = positions[row2].pos[column2];

          if (value1 < value2)
          {
            value1 = value2;
            ch.count++;
            break;
          }
          else
          {
          }
        }
      }
      scanning.push_back(ch);
      // tarama bitiyor
    }
  }

  return 0;
}
