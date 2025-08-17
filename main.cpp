#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double degToRad(double deg) {
    return deg * M_PI / 180.0;
}

double radToDeg(double rad) {
    return rad * 180.0 / M_PI;
}

int main() {
    int julianDate = 219;
    double latitude = 31.95;
    double hourAngle = 15.0;

    double declination = 23.45 * sin(degToRad((360.0 / 365.25) * (284 + julianDate)));

    double L = degToRad(latitude);
    double H = degToRad(hourAngle);
    double delta = degToRad(declination);

    double sinBeta = cos(L) * cos(delta) * cos(H) + sin(L) * sin(delta);
    double beta = asin(sinBeta);

    double sinPhi = (cos(delta) * sin(H)) / cos(beta);
    double phi = asin(sinPhi);

    cout << "\nJulian Date: " << julianDate << endl;
    cout << "Latitude: " << latitude << " degrees" << endl;
    cout << "Hour Angle: " << hourAngle << " degrees" << endl;

    cout << "\nSolar Declination (δ): " << declination << " degrees" << endl;
    cout << "Solar Elevation Angle (β): " << radToDeg(beta) << " degrees" << endl;
    cout << "Solar Azimuth Angle (φ): " << radToDeg(phi) << " degrees" << endl;
    cout << " Dana Almomani " << endl;
    return 0;
}