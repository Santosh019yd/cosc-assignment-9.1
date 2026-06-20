//
// Name: Santu Yadav
// Date: 06/19/2026
// Course: COSC 1437 C++ Programming Fundamentals II
// Desc: Chapter 9 Lab - Student Grade Report System using Records (structs)
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Struct definition
struct studentType
{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// Function prototypes
void readStudentsData(ifstream& inFile, studentType roster[], int size);
void assignGrades(studentType roster[], int size);
int findHighestScore(const studentType roster[], int size);
void printHighestScorers(ostream& out,
                         const studentType roster[],
                         int size,
                         int highestScore);
void printGradeReport(ostream& out,
                      const studentType roster[],
                      int size);

int main()
{
    const int CLASS_SIZE = 20;
    studentType studentRoster[CLASS_SIZE];

    ifstream inFile;
    ofstream outFile;

    string inFileName;
    string outFileName;

    cout << "Enter input file name: ";
    cin >> inFileName;

    inFile.open(inFileName);

    if (!inFile)
    {
        cout << "Error: Unable to open input file." << endl;
        return 1;
    }

    cout << "Enter output file name: ";
    cin >> outFileName;

    outFile.open(outFileName);

    if (!outFile)
    {
        cout << "Error: Unable to create output file." << endl;
        return 1;
    }

    readStudentsData(inFile,
                     studentRoster,
                     CLASS_SIZE);

    assignGrades(studentRoster,
                 CLASS_SIZE);

    int highestScore =
        findHighestScore(studentRoster,
                         CLASS_SIZE);

    printGradeReport(outFile,
                     studentRoster,
                     CLASS_SIZE);

    printHighestScorers(outFile,
                        studentRoster,
                        CLASS_SIZE,
                        highestScore);

    inFile.close();
    outFile.close();

    cout << "Grade report generated successfully." << endl;

    return 0;
}

void readStudentsData(ifstream& inFile,
                      studentType roster[],
                      int size)
{
    for (int i = 0; i < size; i++)
    {
        if (!(inFile >> roster[i].studentFName
                     >> roster[i].studentLName
                     >> roster[i].testScore))
        {
            cout << "Error reading student data." << endl;
            exit(1);
        }
    }
}

void assignGrades(studentType roster[],
                  int size)
{
    for (int i = 0; i < size; i++)
    {
        if (roster[i].testScore >= 90)
            roster[i].grade = 'A';
        else if (roster[i].testScore >= 80)
            roster[i].grade = 'B';
        else if (roster[i].testScore >= 70)
            roster[i].grade = 'C';
        else if (roster[i].testScore >= 60)
            roster[i].grade = 'D';
        else
            roster[i].grade = 'F';
    }
}

int findHighestScore(const studentType roster[],
                     int size)
{
    int highestScore = roster[0].testScore;

    for (int i = 1; i < size; i++)
    {
        if (roster[i].testScore > highestScore)
        {
            highestScore = roster[i].testScore;
        }
    }

    return highestScore;
}

void printGradeReport(ostream& out,
                      const studentType roster[],
                      int size)
{
    out << "---------------------------------------------" << endl;
    out << "            ANNUAL CLASS GRADE REPORT" << endl;
    out << "---------------------------------------------" << endl;

    out << left
        << setw(35) << "Student Name"
        << setw(12) << "Test Score"
        << "Grade" << endl;

    out << "---------------------------------------------" << endl;

    for (int i = 0; i < size; i++)
    {
        string fullName =
            roster[i].studentLName +
            ", " +
            roster[i].studentFName;

        out << left
            << setw(35) << fullName
            << setw(12) << roster[i].testScore
            << roster[i].grade
            << endl;
    }

    out << "---------------------------------------------" << endl;
}

void printHighestScorers(ostream& out,
                         const studentType roster[],
                         int size,
                         int highestScore)
{
    out << endl;
    out << "Highest Test Score: "
        << highestScore
        << endl;

    out << endl;
    out << "Students with the Highest Score:" << endl;

    for (int i = 0; i < size; i++)
    {
        if (roster[i].testScore == highestScore)
        {
            out << "- "
                << roster[i].studentLName
                << ", "
                << roster[i].studentFName
                << endl;
        }
    }
}
