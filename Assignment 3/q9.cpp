#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

class Screen
{
    vector<vector<char>> pixels;

public:
    Screen() {}
    Screen(vector<vector<char>> p) : pixels(p) {}
    void EraseScreen();
    void DrawLine(int x1, int y1, int x2, int y2);
    void DrawPattern();
    void Display();
};

void Screen::EraseScreen()
{
    for (int i = 0; i < pixels.size(); i++)
    {
        for (int j = 0; j < pixels[i].size(); j++)
        {
            pixels[i][j] = ' ';
        }
    }
}

void Screen::DrawLine(int x1, int y1, int x2, int y2)
{
    if (x1 == x2)
    {
        for (int i = y1; i <= y2; i++)
        {
            pixels[i][x1] = '*';
        }
    }
    else if (y1 == y2)
    {
        for (int i = x1; i <= x2; i++)
        {
            pixels[y1][i] = '*';
        }
    }
    else
    {
        double m = (y2 - y1) / (x2 - x1);
        double c = y1 - m * x1;
        for (int i = x1; i <= x2; i++)
        {
            int j = m * i + c;
            pixels[j][i] = '*';
        }
    }
}

void Screen::DrawPattern()
{
    for (int i = 0; i < pixels.size(); i++)
    {
        for (int j = 0; j < pixels[i].size(); j++)
        {
            if (i == j)
                pixels[i][j] = '*';
        }
    }
}

void Screen::Display()
{
    for (int i = 0; i < pixels.size(); i++)
    {
        for (int j = 0; j < pixels[i].size(); j++)
        {
            cout << pixels[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<char>> pixels(10, vector<char>(10, ' '));
    Screen s(pixels);
    s.EraseScreen();
    s.DrawLine(0, 0, 9, 9);
    s.Display();
    s.EraseScreen();
    s.DrawPattern();
    s.Display();
    return 0;
}