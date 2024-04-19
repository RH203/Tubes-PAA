#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include "knapsack.h"
using namespace std;

// Fungsi untuk algoritma greedy
void greedy(int amount, vector<int> &coins)
{
  std::sort(coins.begin(), coins.end(), greater<int>());
  map<int, int> count;
  for (int i = 0; i < coins.size(); i++)
  {
    while (amount >= coins[i])
    {
      amount -= coins[i];
      count[coins[i]]++;
    }
  }
  for (auto &coin : coins)
  {
    cout << coin << " = " << count[coin] << endl;
  }
}

// Fungsi untuk algoritma brute force
void bruteForce(int amount, vector<int> &coins, vector<int> &result, vector<int> &temp, int &min, int start = 0)
{
  if (amount == 0)
  {
    if (temp.size() < min)
    {
      min = temp.size();
      result = temp;
    }
    return;
  }
  for (int i = start; i < coins.size(); i++)
  {
    if (coins[i] <= amount)
    {
      temp.push_back(coins[i]);
      bruteForce(amount - coins[i], coins, result, temp, min, i);
      temp.pop_back();
    }
  }
}

// Fungsi untuk menu pertukaran koin
void exchangeCoin()
{

  int n, amount;
  cout << "Masukkan jumlah koin: ";
  cin >> n;
  vector<int> coins(n);
  cout << "Masukkan nilai koin: ";
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }
  cout << "Masukkan jumlah yang akan ditukar: ";
  cin >> amount;

  int choice;
  cout << "Pilih algoritma pertukaran koin:" << endl;
  cout << "1. Greedy" << endl;
  cout << "2. Brute Force" << endl;
  cout << "3. Keluar\n"
       << endl;
  cout << "Masukkan pilihan: ";
  cin >> choice;

  switch (choice)
  {
  case 1:
  {
    cout << "Hasil algoritma greedy: " << endl;
    greedy(amount, coins);
    cout << "\n"
         << endl;
    break;
  }
  case 2:
  {
    vector<int> result, temp;
    int min = INT_MAX;
    bruteForce(amount, coins, result, temp, min);
    map<int, int> count;
    for (int i = 0; i < result.size(); i++)
    {
      count[result[i]]++;
    }
    cout << "Hasil algoritma brute force: " << endl;
    for (auto &coin : coins)
    {
      cout << coin << " = " << count[coin] << endl;
    }
    cout << "\n"
         << endl;
    break;
  }
  case 3:
    return;
  default:
    cout << "Pilihan tidak valid!" << endl;
    break;
  }
}

int main()
{
  while (true)
  {
    int choice;
    cout << "Menu Utama:" << endl;
    cout << "1. Pertukaran Koin" << endl;
    cout << "2. Job Scheduling" << endl;
    cout << "3. Knapsack Problem" << endl;
    cout << "4. Keluar\n"
         << endl;
    cout << "Masukkan pilihan: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      exchangeCoin();
      break;
    case 2:
      // TODO: Job schedule
      break;
    case 3:
      run();
      break;
    case 4:
      return 0; // Keluar dari program
    default:
      cout << "Pilihan tidak valid!" << endl;
      break;
    }
  }
}
