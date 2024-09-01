#include <iostream>
#include <Windows.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

unordered_map<string, string> wordToT9
{
    {"бабушка", "2226842"},
    {"морковка", "55645242"},
    {"улица", "84422"},
    {"мама", "5252"},
    {"мыла", "5842"},
    {"раму", "6256"}
};

unordered_map<string, string> t9ToWord;

void initializeT9ToWord() 
{
    for (const auto& pair : wordToT9) 
    {
        t9ToWord[pair.second] = pair.first;
    }
}

// Функция для преобразования чисел в предложения
string numbersToWords(const string& input) 
{
    stringstream ss(input);
    string number;
    string result;

    while (ss >> number) 
    {
        if (t9ToWord.find(number) != t9ToWord.end()) 
        {
            result += t9ToWord[number] + " ";
        }
        else 
        {
            result += "<неизвестно> ";
        }
    }

    return result;
}

// Функция для преобразования предложений в числа
string wordsToNumbers(const string& input) 
{
    stringstream ss(input);
    string word;
    string result;

    while (ss >> word) 
    {
        if (wordToT9.find(word) != wordToT9.end()) 
        {
            result += wordToT9[word] + " ";
        }
        else 
        {
            result += "<неизвестно> ";
        }
    }

    return result;
}
// 2 //
string sortString(const string& str) {
    string sorted = str;
    sort(sorted.begin(), sorted.end());
    return sorted;
}

// Функция для поиска анаграмм
vector<string> findAnagrams(const string& word, const vector<string>& candidates) 
{
    vector<string> result;
    string sortedWord = sortString(word);

    for (const auto& candidate : candidates) 
    {
        if (sortString(candidate) == sortedWord) 
        {
            result.push_back(candidate);
        }
    }

    return result;
}

// 3 // 

void findDuplicates(const vector<int>& arr) 
{
    unordered_map<int, int> elementCount;

    for (const auto& element : arr) 
    {
        elementCount[element]++;
    }

    cout << "Дубликаты: ";
    for (const auto& pair : elementCount) 
    {
        if (pair.second > 1) 
        {
            cout << pair.first << " ";
        }
    }
}

// 4 //

bool isUnique(const std::string& str) 
{
    unordered_set<char> charSet;

    for (const auto& ch : str) 
    {
        if (charSet.find(ch) != charSet.end()) 
        {
            return false;  // найден повторяющийся символ
        }
        charSet.insert(ch);
    }

    return true;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SetConsoleTitle(L"Семестр 2. Практическая работа 6");

    initializeT9ToWord();

    string input1;
    int mode;

    cout << "Выберите режим (1 - числа в предложения, 2 - предложения в числа): ";
    cin >> mode;
    cin.ignore();  // игнорируем оставшийся символ новой строки после ввода числа

    cout << "Введите строку: ";
    getline(cin, input1);

    if (mode == 1) 
    {
        cout << "Результат: " << numbersToWords(input1) << endl;
    }
    else if (mode == 2) 
    {
        cout << "Результат: " << wordsToNumbers(input1) << endl;
    }
    else 
    {
        cout << "Неверный режим." << endl;
    }
    // 2 //
    string word = "listen";

    vector<string> candidates = { "enlists", "google", "inlets", "banana" };

    vector<string> anagrams = findAnagrams(word, candidates);

    cout << "Анаграммы для слова \"" << word << "\": ";

    for (const auto& anagram : anagrams) 
    {
        cout << anagram << " ";
    }
    // 3 //

    vector<int> arr = { 1, 2, 3, 4, 5, 1, 2, 6, 7, 8, 9, 7 };

    findDuplicates(arr);

    // 4 //

    string input2;

    cout << "\nВведите строку: ";
    cin >> input2;

    if (isUnique(input2)) 
    {
        cout << "Все символы в строке уникальны." << endl;
    }
    else 
    {
        cout << "В строке есть повторяющиеся символы." << endl;
    }

    return 0;
}