#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Data
{
  int data_x;
  int data_y;
};


int main()
{
  system("cls");
  int n, korelasi;
  int sigma_x, sigma_y, sigma_xy;
  float sigma_x2, sigma_y2, bagAtas, bagBawahKiri, bagBawahKanan;
  double koefisien;

  cout << "Berapa Data?: ";
  cin >> n;
  double data_xy[n];

  Data dta[n];
  vector<Data> dataa;
  for (int i = 0; i < n; i++)
  {
    Data data;
    cout << "masukkan data X ke-" << i + 1 << " : ";
    cin >> dta[i].data_x;
    while (dta[i].data_x <= 0) {
            cout << "Nilai x tidak boleh kurang dari 0. Masukkan Nilai x: ";
            cin >> dta[i].data_x;
    }
    cout << "masukkan data Y ke-" << i + 1 << " : ";
    cin >> dta[i].data_y;
    while (dta[i].data_y <= 0) {
            cout << "Nilai y tidak boleh kurang dari 0. Masukkan Nilai y: ";
            cin >> dta[i].data_y;
    }
    dataa.push_back(data);

    sigma_x += dta[i].data_x;
    sigma_y += dta[i].data_y;

    data_xy[i] = dta[i].data_x * dta[i].data_y;
    sigma_xy += data_xy[i];

    
  }
  sigma_x2 = pow(sigma_x, 2);
  sigma_y2 = pow(sigma_y, 2);



  bagAtas = (n * sigma_xy) - (sigma_x * sigma_y);
  bagBawahKiri = sqrt((n * sigma_x2) - (pow(sigma_x, 2)));
  bagBawahKanan = sqrt((n * sigma_y2) - (pow(sigma_y, 2)));

  double r = bagAtas / (bagBawahKiri * bagBawahKanan);
  koefisien = pow(r, 2) * (1 / 100);
 

    cout << "=========" << endl;
    
  cout << "sigma x = " << sigma_x << endl;
  cout << "sigma y = " << sigma_y << endl;
  cout << "sigmaXY = " << sigma_xy << endl;
  cout << "sigma x2 = " << sigma_x2 << endl;
  cout << "sigmaY2 = " << sigma_y2 << endl;

    cout << "============" << endl;
    cout << "REKAP OUTPUT" << endl;
    cout << "============" << endl;

  cout << "a. Nilai Korelasi r = " << bagAtas << " / " << bagBawahKiri * bagBawahKanan << " = " << r << endl;
  cout << "b. Nilai koefisien determinasi = " << koefisien << endl;

if (r<=0.09)
 {
 cout << "c. Kekuatan Hubungan dari Nilai Korelasi = diabaikan"; 
 }
 else if (r<=0.29)
 {
 cout << "c. Kekuatan Hubungan dari Nilai Korelasi = rendah"; 
 }
 else if (r<=0.49)
 {
 cout << "c. Kekuatan Hubungan dari Nilai Korelasi = moderat"; 
 }
 else if (r<=0.70)
 {
 cout << "c. Kekuatan Hubungan dari Nilai Korelasi = sedang"; 
 }
 else if (r>0.70)
 {
    cout << "c. Kekuatan Hubungan dari Nilai Korelasi = sangat kuat"; 
 }

  //cout << "c. Kekuatan Hubungan dari Nilai Korelasi = " << korelasi << endl;

    cout << endl;

  if (r == 0)
  {
    cout << "f. Tidak Ada Hubungan Antara variabel X dan Y adalah Positif" << endl;
  }
  else if (r > 0)
  {
    cout << "d. Hubungan Antara variabel X dan Y adalah Positif" << endl;
  }
  else if (r < 0)
  {
    cout << "e. Hubungan Antara variabel X dan Y adalah Negatif" << endl;
  }

  return 0;
}
