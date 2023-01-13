#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <conio.h>

#include "movieinfo.h"
#include "sort_functions.h"

void sort_by_ID();
void sort_by_name();
void sort_by_ratings();

int main(void)
{
  int a = 0;

  while (a == 0)
  {
    system("CLS");
    Movie ob1;
    movie_info info;

    int x;
    x = menu();
    string name;

    switch (x)
    {
    case (1):
      cout << "\nEnter ID: ";
      cin >> info.ID;
      ob1.set_ID(info.ID);

      cout << "Enter movie name: ";
      cin.ignore();
      getline(cin, info.name);
      ob1.set_movie_name(info.name);

      cout << "Enter ratings: ";
      cin >> info.ratings;
      ob1.set_ratings(info.ratings);
      ob1.add_info();
      getch();
      break;

    case (2):

      sort_by_movie_name();
      ob1.show_name_sorting();
      getch();

      break;

    case (3):

      //ob1.show_info("info.txt");
      cout << "check";
      sort_by_ratings();
      ob1.show_rating_sorted();
      getch();
      break;

    case (4):
      ob1.delete_info();
      getch();
      break;

    case (5):
      return 0;
    }
  }

  return 0;
}
