#ifndef MOVIEINFO_H
#define MOVIEINFO_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

typedef struct
{
  long ID;
  string name;
  double ratings;
} movie_info;

class ID
{
public:
  int ID;
  void set_ID(long a)
  {
    ID = a;
  }
};

class Movie_Name
{
public:
  string Movie_Name;
  void set_movie_name(string name)
  {
    Movie_Name = name;
  }
};

class ratings
{
public:
  double ratings;
  void set_ratings(double r)
  {
    ratings = r;
  }
};

class Movie : public ID, public Movie_Name, public ratings
{
public:
  Movie(long a = 0, string b = "", double c = 0)
  {
    set_ID(a);
    set_movie_name(b);
    set_ratings(c);
  }

  long get_id()
  {
    return ID;
  }

  string get_movie_name()
  {
    return Movie_Name;
  }

  double get_ratings()
  {
    return ratings;
  }

  void add_info(void)
  {
    ofstream file;
    ofstream ID_sort;
    file.open("info.txt", ofstream::out | ofstream::app);
    file << get_id() << " "
         << get_ratings() << " "
         << get_movie_name() << endl;
    file.close();
  }

  void delete_info(void)
  {
    int line_delete;
    show_info("info.txt");

    int q = sort_ID.size();

    for (int i = 0; i < q; i++)
    {
      set_ID(sort_ID[i]);
      set_ratings(sort_ratings[i]);
      set_movie_name(sort_movies[i]);

      print();
    }
    cout << "\n\t\tWhich movie do you want to remove: ";
    cin >> line_delete;
    int count = 1;

    string getcontent;

    ifstream file("info.txt");

    if (file.is_open())
    {
      while (!file.eof())
      {
        getline(file, getcontent);

        if (count != line_delete)
        {
          ofstream temp("temp.txt", ofstream ::app | ofstream ::out);

          if (getcontent.length() == 0)
          {
            continue;
          }
          temp << getcontent << endl;
        }

        count++;
      }
    }

    file.close();
    remove("info.txt");
    rename("temp.txt", "info.txt");
  }

  void print()
  {

    cout << "\t\tID: " << get_id() << endl;
    cout << "\t\tName: " << get_movie_name() << endl;
    cout << "\t\tRatings: " << get_ratings() << "\n\n"
         << endl;
  }

  void show_rating_sorted()
  {
    show_info("ratings_sorting.txt");

    int q = sort_ID.size();

    for (int i = 0; i < q; i++)
    {
      set_ID(sort_ID[i]);
      set_ratings(sort_ratings[i]);
      set_movie_name(sort_movies[i]);

      print();
    }
  }
  //reads and prints info sortd by names

  void show_name_sorting()
  {
    show_info("movie_name_sorting.txt");

    int q = sort_ID.size();

    for (int i = 0; i < q; i++)
    {
      set_ID(sort_ID[i]);
      set_ratings(sort_ratings[i]);
      set_movie_name(sort_movies[i]);

      print();
    }
  }

  vector<double> sort_ratings;
  vector<long> sort_ID;
  vector<string> sort_movies;
  string line;

  void show_info(string a)
  {

    ifstream in;

    in.open(a);

    for (line; getline(in, line);)
    {
      istringstream input(line);

      long ID01;

      double ratings01;

      string movie_names01;

      input >> ID01;

      sort_ID.push_back(ID01);

      input >> ratings01;

      sort_ratings.push_back(ratings01);

      getline(input, movie_names01);

      sort_movies.push_back(movie_names01);
    }
    in.close();
  }

  //reads and prints info sorted by ratings
};

#endif
