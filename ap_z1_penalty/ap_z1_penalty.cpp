#include <iostream>

using namespace std;

//oblicza najblizsza potege 2
long long int teams_increased(long long int teams_knockout_stage) {
    unsigned  int teams = 1;
    while (teams < teams_knockout_stage)
        teams <<= 1;
    return teams;
}

int main()
{
    long long int g, t, a, d, x, y;

    cin >> g;
    cin >> t;
    cin >> a;
    cin >> d;

    while (g != -1) {

        //liczba meczow grupowych
        long long int games_group = g * t * (t - 1) / 2;

        //liczba druzyn w fazie pucharowej (bez dodanych porzez program)
        long long int teams_knockout_stage = g * a + d;
        
        //sprawdza czy liczba druzyn jest potega 2 i oblicza y
        if (teams_knockout_stage & (teams_knockout_stage - 1))
            y = teams_increased(teams_knockout_stage) - teams_knockout_stage;
        else
            y = 0;

        //ostateczna liczba druzyn w fazie pucharowej
        teams_knockout_stage += y;

        //liczba wszystkich meczów
        x = games_group + teams_knockout_stage - 1;

        cout << g << '*' << a << '/' << t << '+' << d << '=' << x << '+' << y;

        cin >> g;
        cin >> t;
        cin >> a;
        cin >> d;

        if (g != -1)
            cout << '\n';
    }
}