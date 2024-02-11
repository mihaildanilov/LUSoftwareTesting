/***************************************
    Autori:
        Mihails Daņilovs, md22039
        Rolands Pučeta, rp22046
        Kristofers Semjonovs, ks22110
        Aleksis Volrāts, av22110
        Ralfs Čipāns, rc22007
***************************************/

#include <iostream>
#include <string>

using namespace std;

// Define error codes and corresponding error messages
enum ErrorCode
{
    SUCCESS,
    ERROR_001,
    ERROR_002,
    ERROR_004,
    ERROR_009,
    ERROR_011,
    ERROR_012
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
    case ERROR_012:
        return "Kļūda! Lūdzu atkārtojiet darbību!";
    default:
        return "Nezināma kļūda.";
    }
}

// Dummy structure to represent an image
struct Image
{
    string format; // "JPEG", "JPG", "PNG"
    size_t size;   // Size in bytes
};

// Function to create a course
ErrorCode createCourse(const string &courseName, const string &courseCategory, const Image &previewImage, const string &courseDescription, double coursePrice)
{
    // Validate mandatory fields
    if (courseName.empty() || courseCategory.empty() || courseDescription.empty() || coursePrice < 0)
    {
        return ERROR_001;
    }
    // Validate input lengths and formats
    if (courseName.length() > 100 || courseCategory.length() > 100 || courseDescription.length() > 1000)
    {
        return ERROR_009;
    }
    if (previewImage.size > 3 * 1024 * 1024)
    { // Image size exceeds 3 MB
        return ERROR_004;
    }
    if (previewImage.format != "JPEG" && previewImage.format != "JPG" && previewImage.format != "PNG")
    {
        return ERROR_011;
    }

    // Simulate storing the course in a database
    cout << "Kurss izveidots!" << endl;
    cout << "Kursa nosaukums: " << courseName << ", Kategorija: " << courseCategory << ", Cena: " << coursePrice << endl;

    return SUCCESS;
}
int main()
{
    Image courseImage = {"PNG", 2500 * 1024};
    ErrorCode result = createCourse("Ievads programmēšanā", "Datorzinātnes", courseImage, "Šis kurss piedāvā ievadu programmēšanā ar C++.", 99.99);

    if (result != SUCCESS)
    {
        cout << getErrorMessage(result) << endl;
    }

    return 0;
}