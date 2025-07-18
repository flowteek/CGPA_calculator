// We include necessary header files for input/output, vectors, strings, formatting, and file operations
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// ===== Course Class (Encapsulation) =====
// This class stores details about each course and provides methods to access them.
class Course {
private:
    string code, type;
    int unit, grade;
public:
    // Constructor to initialize course details
    Course(string c, string t, int u, int g)
        : code(c), type(t), unit(u), grade(g) {}

    // Returns the score for the course (unit * grade)
    int getScore() const { return unit * grade; }
    int getUnit() const { return unit; }
    int getGrade() const { return grade; }
    string getCode() const { return code; }
    string getType() const { return type; }

    // Outputs course details to the file in a formatted way
    void display(ofstream& outFile) const {
        outFile << left << setw(10) << code
                << setw(6) << unit
                << setw(8) << type
                << setw(10) << grade
                << setw(10) << getScore() << endl;
    }
};

// ===== SemesterResult Base Class (Abstraction) =====
// This class manages the input of courses, GPA calculation, and saving results for a semester.
class SemesterResult {
protected:
    string studentName, level, semester;
    vector<Course> courses;

public:
    // Constructor to initialize semester details
    SemesterResult(const string& name, const string& lvl, const string& sem)
        : studentName(name), level(lvl), semester(sem) {}

    // Collects course details from the user for the semester
    virtual void inputCourses() {
        int num;
        cout << "Enter student name: ";
        cin >> ws;
        getline(cin, studentName);
        cout << "Enter number of courses: ";
        cin >> num;

        for (int i = 0; i < num; ++i) {
            string code, type;
            int unit, grade;

            cout << "\nCourse " << i + 1 << ":\n";
            cout << "Course Code: ";
            cin >> ws;
            getline(cin, code);
            cout << "Course Unit: ";
            cin >> unit;
            cout << "Course Type (C = Compulsory, E = Elective, R = Required): ";
            cin >> type;
            cout << "Grade Point (0 - 5): ";
            cin >> grade;

            // Store course details
            courses.emplace_back(code, type, unit, grade);
        }
    }

    // Calculates GPA for the semester
    virtual double calculateGPA() const {
        int totalUnits = 0, totalPoints = 0;

        for (const auto& course : courses) {
            totalUnits += course.getUnit();
            totalPoints += course.getScore();
        }

        return totalUnits == 0 ? 0.0 : static_cast<double>(totalPoints) / totalUnits;
    }

    // Determines and prints the academic standing based on GPA
    virtual void printStanding(double gpa) const {
        if (gpa >= 4.5) cout << "Standing: First Class\n";
        else if (gpa >= 3.5) cout << "Standing: Second Class Upper\n";
        else if (gpa >= 2.5) cout << "Standing: Second Class Lower\n";
        else if (gpa >= 1.5) cout << "Standing: Third Class\n";
        else cout << "Standing: Probation\n";
    }

    // Saves semester results to the output file in a readable format
    virtual void saveToFile(ofstream& outFile) const {
        outFile << "\n\n===== " << level << " Level, " << semester << " Semester =====\n";
        outFile << "Student Name: " << studentName << '\n';
        outFile << left << setw(10) << "Code"
                << setw(6) << "Unit"
                << setw(8) << "Type"
                << setw(10) << "Grade"
                << setw(10) << "Score" << '\n';

        int totalUnits = 0, totalCreditPoints = 0;
        for (const auto& course : courses) {
            course.display(outFile);
            totalUnits += course.getUnit();
            totalCreditPoints += course.getScore();
        }

        double gpa = calculateGPA();
        outFile << "\nTNU (Total Units): " << totalUnits;
        outFile << "\nTCP (Total Credit Points): " << totalCreditPoints;
        outFile << "\nGPA: " << fixed << setprecision(2) << gpa << " / 5.00";
        // Print standing to file
        outFile << "\nStanding: ";
        if      (gpa >= 4.5) outFile << "First Class";
        else if (gpa >= 3.5) outFile << "Second Class Upper";
        else if (gpa >= 2.5) outFile << "Second Class Lower";
        else if (gpa >= 1.5) outFile << "Third Class";
        else                 outFile << "Probation";
        outFile << "\n";
    }

    vector<Course> getCourses() const { return courses; }

    virtual ~SemesterResult() {}
};

// ===== Inheritance and Polymorphism =====
// Allows different semester types to customize how they display results while sharing core logic.
// The derived classes (FirstSemesterResult and SecondSemesterResult) inherit common behavior from SemesterResult and override specific methods (like printStanding) to provide custom output.
class FirstSemesterResult : public SemesterResult {
public:
    FirstSemesterResult(const string& name, const string& lvl) : SemesterResult(name, lvl, "First") {}

    // Prints a header for first semester results and the standing
    void printStanding(double gpa) const override {
        cout << "First Semester Result\n";
        SemesterResult::printStanding(gpa);
    }
};

class SecondSemesterResult : public SemesterResult {
public:
    SecondSemesterResult(const string& name, const string& lvl) : SemesterResult(name, lvl, "Second") {}

    // Prints a header for second semester results and the standing
    void printStanding(double gpa) const override {
        cout << "Second Semester Result\n";
        SemesterResult::printStanding(gpa);
    }
};

// ===== Main Function =====
int main() {
    // Main program loop: allows user to enter multiple semesters
    vector<SemesterResult*> semesters;
    char another;

    do {
        // Get semester information from user
        string studentName, level, sem;
        cout << "\nEnter student name: ";
        cin >> ws;
        getline(cin, studentName);
        cout << "Enter level (e.g., 100, 200, 300): ";
        cin >> level;
        cout << "Enter semester (first/second): ";
        cin >> sem;

        // Create appropriate semester result object
        SemesterResult* result;
        if (sem == "first")
            result = new FirstSemesterResult(studentName, level);
        else
            result = new SecondSemesterResult(studentName, level);

        // Collect course details and calculate GPA
        result->inputCourses();
        double gpa = result->calculateGPA();

        // Print GPA and standing to screen
        cout << "\nGPA: " << fixed << setprecision(2) << gpa << " / 5.00\n";
        result->printStanding(gpa);

        // Store semester result for later processing
        semesters.push_back(result);

        // Ask user if they want to enter another semester
        cout << "\nDo you want to enter another semester? (y/n): ";
        cin >> another;

    } while (another == 'y' || another == 'Y');

    // Save all semester results to file and calculate cumulative CGPA
    ofstream outFile("cgpa_results.txt", ios::app);
    int grandUnits = 0, grandPoints = 0;

    for (auto s : semesters) {
        s->saveToFile(outFile);
        for (auto& c : s->getCourses()) {
            grandUnits += c.getUnit();
            grandPoints += c.getScore();
        }
        delete s;
    }

    // Output cumulative CGPA and standing to file
    if (grandUnits > 0) {
        double cgpa = static_cast<double>(grandPoints) / grandUnits;
        outFile << "\n=========== CUMULATIVE CGPA ===========\n";
        outFile << "TNU (Total Units): " << grandUnits << "\n";
        outFile << "TCP (Total Credit Points): " << grandPoints << "\n";
        outFile << "Cumulative CGPA: " << fixed << setprecision(2) << cgpa << " / 5.00\n";
        outFile << "Standing: ";
        if      (cgpa >= 4.5) outFile << "First Class";
        else if (cgpa >= 3.5) outFile << "Second Class Upper";
        else if (cgpa >= 2.5) outFile << "Second Class Lower";
        else if (cgpa >= 1.5) outFile << "Third Class";
        else                 outFile << "Probation";
        outFile << "\n";
    }

    outFile.close();
    cout << "\nAll results saved to 'cgpa_results.txt'.\n";
    return 0;
}