/*
Group Assignment # 3:
Muhammad Ahmad Amjad-2023361
Abdullah Ejaz Janjua-2023038
Spinning Donut
*/

#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

#define RESET_COLOR "\033[0m"
#define BLUE_COLOR "\033[1;34m"

#define Width 50  // defining screen width
#define Height 25 // defining screen height


// function for clearing screen
void clear_screen()
{
    COORD coord = {0};
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, coord);
}

// creating Donut Class
class Donut
{
private:
    // initializing variables
    const int R1 = 10, R2 = 20;
    int K2;
    int K1;
    float A, B;
    char donut[Height * Width];
    float zBuffer[Height * Width];
    string SHADE = ".,-~:;=!*#$@";

public:
    Donut()
    {
        cout << "\033[?25l"; // hiding the cursor
        K2 = 150;
        K1 = Height * K2 * 3 / (8 * (R1 + R2));
        A = B = 0;
    }

    // Function to calculate the coordinates of the points on the donut
    void XYZ();

    // Function to print the donut on the screen
    void printDonut();
};

int main()
{
    Donut D;
    while (true)
    {
        clear_screen();
        D.XYZ();
        D.printDonut();
    }
}

void Donut::XYZ()
{
    // Initializing donut and zBuffer arrays
    for (int i = 0; i < Height * Width; i++)
    {
        donut[i] = ' ';
        zBuffer[i] = 0;
    }

    // Loop to calculate the coordinates of the points on the donut
    for (float theta = 0; theta < 2 * M_PI; theta += 0.08)
    {
        for (float phi = 0; phi < 2 * M_PI; phi += 0.02)
        {
            // Calculating various trigonometric values
            float cosA = cos(A);
            float sinA = sin(A);
            float cosB = cos(B);
            float sinB = sin(B);
            float costheta = cos(theta);
            float sintheta = sin(theta);
            float cosphi = cos(phi);
            float sinphi = sin(phi);

            // Calculating 3D coordinates of the points on the donut
            float circlex = R2 + R1 * costheta;
            float circley = R1 * sintheta;
            float x = circlex * (cosB * cosphi + sinA * sinB * sinphi) - circley * cosA * sinB;
            float y = circlex * (sinB * cosphi - sinA * cosB * sinphi) + circley * cosA * cosB;
            float z = K2 + cosA * circlex * sinphi + circley * sinA;
            float ooz = 1 / z;

            // Converting 3D coordinates to 2D screen coordinates
            int xp = int(Width / 2 + K1 * ooz * x);
            int yp = int(Height / 2 - K1 * ooz * y);

            // Updating the donut array based on luminance and depth
            if (xp >= 0 && xp < Width && yp >= 0 && yp < Height)
            {
                int position = xp + Width * yp;
                float luminance_index = cosphi * costheta * sinB - cosA * costheta * sinphi - sinA * sintheta + cosB * (cosA * sintheta - costheta * sinA * sinphi);
                if (luminance_index > 0)
                {
                    if (ooz > zBuffer[position])
                    {
                        zBuffer[position] = ooz;
                        int luminance = 8 * luminance_index;
                        donut[position] = SHADE[luminance];
                    }
                }
            }
        }
    }

    // Incrementing rotation angles for animation
    A += 0.1;
    B += 0.2;
}

void Donut::printDonut()
{
    // Printing the donut on the screen
    for (int i = 0; i < Width * Height; i++)
    {
        if (i % Width == 0)
            cout << "\n";
        else
            cout << BLUE_COLOR <<donut[i];
    }

    // Introducing a delay for smoother animation
    Sleep(20);
}
