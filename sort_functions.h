#ifndef SORT_FUNCTIONS_H
#define SORT_FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<double> sort_ratings;
vector<long> sort_ID;
vector<string> sort_movies;
string line;

int menu(void)
{
    int a;

    cout << "\n\t\tChoose an option: \n";
    cout << "\t\t1. Add a movie \n"
         << "\t\t2. Sort movies by name \n"
         << "\t\t3. Sort movies by ratings\n"
         << "\t\t4. Delete an entry\n"
         << "\t\t5. Exit"
         << endl;

    cin >> a;
    return a;
}

void VectorPushBacks(string a)
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

void sort_by_ratings()
{
    sort_ID.clear();
    sort_movies.clear();
    sort_ratings.clear();
    VectorPushBacks("info.txt");

    int q = sort_movies.size();

    //temporary string
    vector<double> temp_ratings = sort_ratings;

    //sorting algorithms

    sort(temp_ratings.begin(), temp_ratings.end(), greater<>());

    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < q; j++)
        {
            if (temp_ratings[i] == sort_ratings[j])
            {
                swap(sort_movies[i], sort_movies[j]);
                swap(sort_ID[i], sort_ID[j]);
            }
        }
    }

    //rewrite function

    sort_ratings = temp_ratings;
    ofstream out("temp01.txt", ofstream::app | ofstream::out);

    for (int i = 0; i < q; i++)
    {
        out << sort_ID[i] << " " << sort_ratings[i] << " " << sort_movies[i] << endl;
    }

    out.close();
    remove("ratings_sorting.txt");
    rename("temp01.txt", "ratings_sorting.txt");
}

void sort_by_movie_name()
{
    sort_ID.clear();
    sort_movies.clear();
    sort_ratings.clear();

    VectorPushBacks("info.txt");

    int q = sort_movies.size();

    //temporary string
    vector<string> temp_name = sort_movies;

    //sorting algorithms

    sort(temp_name.begin(), temp_name.end());

    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < q; j++)
        {
            if (temp_name[i] == sort_movies[j])
            {
                swap(sort_ratings[i], sort_ratings[j]);
                swap(sort_ID[i], sort_ID[j]);
            }
        }
    }

    //rewrite function

    sort_movies = temp_name;

    ofstream out("temp02.txt", ofstream::app | ofstream::out);

    for (int i = 0; i < q; i++)
    {

        out << sort_ID[i] << " " << sort_ratings[i] << " " << sort_movies[i] << endl;
    }

    out.close();
    remove("movie_name_sorting.txt");
    rename("temp02.txt", "movie_name_sorting.txt");
}

#endif