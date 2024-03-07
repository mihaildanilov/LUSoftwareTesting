/***************************************
    Autori:
        Mihails Daņilovs, md22039
        Rolands Pučeta, rp22046
        Kristofers Semjonovs, ks22110
        Aleksis Volrāts, av22110
        Ralfs Čipāns, rc22007
***************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>

using namespace std;

// Nosaka kļūdu kodus un atbilstošos kļūdu ziņojumus
enum ErrorCode
{
    SUCCESS,
    ERROR_001,
    ERROR_002,
    ERROR_004,
    ERROR_009,
    ERROR_011,
};

string getErrorMessage(ErrorCode error)
{
    switch (error)
    {
    case ERROR_001:
        return "Lūdzu aizpildiet visus obligātos laukus!";
    case ERROR_002:
        return "Kļūda ievadē! Pārliecinieties, vai ievadītie dati ir pareizi!";
    case ERROR_004:
        return "Attēls ir lielāks par maksimālo atļauto izmēru!";
    case ERROR_009:
        return "Ievadītais teksts pārsniedz atļauto simbolu skaitu!";
    case ERROR_011:
        return "Attēlam jābūt formātā JPEG, JPG vai PNG!";
    default:
        return "Nezināma kļūda.";
    }
}

bool validatePrice(const string &input)
{
    if (input.empty())
        return false;

    // Pārbauda vai ievade sastāv tikai no cipariem un viena decimālpunkta
    bool dotFound = false;
    for (char c : input)
    {
        if (!isdigit(c))
        {
            if (c == '.' && !dotFound)
            {
                dotFound = true;
            }
            else
            {
                return false;
            }
        }
    }

    // Pārbauda vai decimālpunkts nav sākumā vai beigās
    if (input.front() == '.' || input.back() == '.' || input.find('.') != input.rfind('.'))
    {
        return false;
    }

    // Sadala ievadu veselā un decimāldaļā
    string integerPart, fractionalPart;
    size_t dotPos = input.find('.');
    if (dotPos == string::npos)
    {
        integerPart = input;
    }
    else
    {
        integerPart = input.substr(0, dotPos);
        fractionalPart = input.substr(dotPos + 1);
    }

    // Datu validācija
    if (integerPart.size() > 4 || fractionalPart.size() > 2)
    {
        return false;
    }

    // Pievieno trukstošās nulles decimāldaļai, ja nepieciešams
    if (fractionalPart.empty())
    {
        fractionalPart = "00";
    }
    else if (fractionalPart.size() == 1)
    {
        fractionalPart += "0";
    }

    // Pārveido uz skaitli datu validācijai
    int integer = stoi(integerPart);
    int fractional = stoi(fractionalPart);

    // Pārbauda vai cena ir lielāka par 0
    if (integer == 0 && fractional == 0)
    {
        return false;
    }

    return true;
}
// Maketa struktūra, kas raksturo attēlu
struct Image
{
    string format; // "JPEG", "JPG", "PNG"
    size_t size;   // Attēla izmērs baitos
};

// Funkcija, lai izveidotu kursu
ErrorCode createCourse(const string &courseName, const string &courseCategory, const Image &previewImage, const string &courseDescription, const string coursePrice)
{
    // Pārbauda obligātos laukus
    if (courseName.empty() || courseCategory.empty() || courseDescription.empty() || coursePrice.empty())
    {
        return ERROR_001;
    }
    if (!validatePrice(coursePrice))
    { // Pārbauda cenas formātu
        return ERROR_002;
    }
    if (previewImage.size > 3 * 1024 * 1024)
    { // Pārbauda attēla izmēru (maksimālais izmērs 3MB)
        return ERROR_004;
    }
    // Pārbauda ievades garumu un formātus
    if (courseName.length() > 100 || courseCategory.length() > 100 || courseDescription.length() > 1000)
    {
        return ERROR_009;
    }
    // Pārbauda attēla formātu
    if (previewImage.format != "JPEG" && previewImage.format != "JPG" && previewImage.format != "PNG")
    {
        return ERROR_011;
    }

    // Simulē kursa saglabāšanu datu bāzē
    cout << "Kurss izveidots!" << endl;
    cout << "Kursa nosaukums: " << courseName << ", Kategorija: " << courseCategory << ", Cena: " << coursePrice << endl;

    return SUCCESS;
}
int main()
{
    try
    { /// Pārbaudes nolūkiem (datu testēšanai) mainiet vērtības "Image courseImage" un "ErrorCode result"
        /// Formāts priekšskatījuma attēlam(courseImage): {string formāts, size_t izmērs_baitos}
        /// Atļautie formāti: "JPEG", "JPG", "PNG"
        Image courseImage = {"PNG", 3 * 1024 * 1024};
        /// Formāts kursa izveidnei(result): {string nosaukums, string kategorija, Image priekšskatījuma_attēls, string apraksts, string cena}
        ErrorCode result = createCourse("Ievads programmēšanā", "Datorzinātnes", courseImage, "Šis kurss piedāvā ievadu programmēšanā ar C++.", "99.99");
        if (result != SUCCESS)
        {
            throw getErrorMessage(result);
        }
    }
    catch (string error)
    {
        cout << error << endl;
    }

    return 0;
}