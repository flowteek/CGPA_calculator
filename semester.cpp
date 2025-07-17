#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    //  Get semester information from user
    string level, semester;
    cout << "Enter your level (e.g., 100, 200, 300 etc): ";
    cin >> level; //collecting level of study

    cout << "Enter semester (first or second): ";
    cin >> semester;//collecting semester type

    int numCourses;
    cout << "Enter number of courses: ";
    cin >> numCourses;//collecting number of courses

    // we create vectors to hold user course details
    vector<string> courseCodes(numCourses);
    vector<int>    courseUnits(numCourses);
    vector<string> courseTypes(numCourses); // C, E, R
    vector<int>    gradePoints(numCourses); // 0–5
    vector<int>    courseScores(numCourses); // unit * gradePoint

    int totalUnits = 0;
    int totalCreditPoints = 0;

    cout << "\nEnter details for each course:\n";

    for (int i = 0; i < numCourses; ++i) {
        cout << "\nCourse " << i + 1 << ":\n";

        cout << "Course Code: ";
        cin >> ws;
        getline(cin, courseCodes[i]);

        cout << "Course Unit: ";
        cin >> courseUnits[i];

        cout << "Course Type (C = Compulsory, E = Elective, R = Required): ";
        cin >> courseTypes[i];

        cout << "Grade Point (0 - 5): ";
        cin >> gradePoints[i];

        //we Compute per-course credit points
        courseScores[i] = courseUnits[i] * gradePoints[i];
        totalUnits      += courseUnits[i];
        totalCreditPoints += courseScores[i];
    }

    // GPA calculation takes place here 
    double gpa = (totalUnits > 0)
        ? static_cast<double>(totalCreditPoints) / totalUnits
        : 0.0;

    // we determine standing accordingly first class, second class upper, etc.
    string standing;
    if      (gpa >= 4.5) standing = "First Class";
    else if (gpa >= 3.5) standing = "Second Class Upper";
    else if (gpa >= 2.5) standing = "Second Class Lower";
    else if (gpa >= 1.5) standing = "Third Class";
    else                 standing = "Probation";

    //  Print to screen 
    cout << "\n\n===== " << level << " Level, " << semester << " Semester =====\n";
    cout << left << setw(10) << "Code"
         << setw(6)  << "Unit"
         << setw(8)  << "Type"
         << setw(10) << "Grade"
         << setw(10) << "Score" << '\n';

//here we Print course details
    for (int i = 0; i < numCourses; ++i) {
        cout << left << setw(10) << courseCodes[i]
             << setw(6)  << courseUnits[i]
             << setw(8)  << courseTypes[i]
             << setw(10) << gradePoints[i]
             << setw(10) << courseScores[i] << '\n';
    }
    //here we output total units, credit points, GPA, and standing
    cout << "\nTNU (Total Units): " << totalUnits;
    cout << "\nTCP (Total Credit Points): " << totalCreditPoints;
    cout << "\nGPA: " << fixed << setprecision(2) << gpa << " / 5.00";
    cout << "\nStanding: " << standing << "\n";

    // here we Save to file (append) cgpa_result.txt
    ofstream outFile("cgpa_result.txt", ios::app);
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return 1;
    }

    outFile << "\n\n===== " << level << " Level, " << semester << " Semester =====\n";
    outFile << left << setw(10) << "Code"
            << setw(6)  << "Unit"
            << setw(8)  << "Type"
            << setw(10) << "Grade"
            << setw(10) << "Score" << '\n';

    for (int i = 0; i < numCourses; ++i) {
        outFile << left << setw(10) << courseCodes[i]
                << setw(6)  << courseUnits[i]
                << setw(8)  << courseTypes[i]
                << setw(10) << gradePoints[i]
                << setw(10) << courseScores[i] << '\n';
    }

    outFile << "\nTNU (Total Units): " << totalUnits;
    outFile << "\nTCP (Total Credit Points): " << totalCreditPoints;
    outFile << "\nGPA: " << fixed << setprecision(2) << gpa << " / 5.00";
    outFile << "\nStanding: " << standing << "\n";
    outFile.close();

    return 0;
}
