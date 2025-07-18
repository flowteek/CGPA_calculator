# CGPA Calculator Project (Group 9)

This project contains a C++ program to calculate the Cumulative Grade Point Average (CGPA) for a student based on their semester results. The program now collects the student name for each record and saves it in the output file.

## Files
- `semester.cpp`: Main C++ source file containing the logic to input student name, semester grades, calculate the CGPA, and display/save the result.
- `cgpa_result.txt`: Output file where the calculated CGPA and student details are saved after running the program.
- `README.md`: This documentation file.

## How to Use
1. Compile the C++ source file:
   ```bash
   g++ semester.cpp -o cgpa
   ```
2. Run the program:
   ```bash
   ./cgpa
   ```
3. Follow the prompts to enter your name, level, semester, and course details.
4. The calculated CGPA and your details will be displayed and saved to `cgpa_result.txt`.

## Requirements
- C++ compiler (e.g., g++)
- Linux environment (e.g., Ubuntu 24.04)
- Optional: WSL with VS Code to have a Linux environment on Windows

## How to Install WSL (Ubuntu 24.04) on Windows
1. Press the Windows key + X
2. Open Terminal (Admin) or Command Prompt
3. Type:
   ```bash
   wsl --install
   ```
4. Wait for installation to complete
5. Download and install VS Code
6. Open VS Code and go to Extensions to download the WSL extension
7. Open a new window and connect to WSL by typing `>WSL` in the search bar
8. Click on "Connect to WSL"
9. Open the terminal in VS Code and install the Ubuntu distribution if prompted

## Terms Explained
- **Student Name**: The name of the student whose results are being recorded.
- **Level**: The academic level (e.g., 100, 200, 300) of the student.
- **Semester**: The semester type (first or second).
- **Course Code**: The code identifying each course (e.g., MTH101).
- **Course Unit**: The credit unit for each course (usually an integer).
- **Course Type**: Indicates if the course is Compulsory (C), Elective (E), or Required (R).
- **Grade Point**: The grade earned in the course, on a scale from 0 to 5.
- **Score**: Calculated as Course Unit × Grade Point for each course.
- **TNU (Total Units)**: The sum of all course units taken in the semester.
- **TCP (Total Credit Points)**: The sum of all scores (unit × grade point) for the semester.
- **GPA**: Grade Point Average for the semester, calculated as TCP ÷ TNU.
- **Standing**: Academic standing based on GPA:
  - First Class (GPA ≥ 4.5)
  - Second Class Upper (GPA ≥ 3.5)
  - Second Class Lower (GPA ≥ 2.5)
  - Third Class (GPA ≥ 1.5)
  - Probation (GPA < 1.5)

## How the Code Works
- **Encapsulation**: The program uses a 'Course' class to keep all course details together and protected, so only specific methods can access or change them. This makes the code safer and easier to manage.
- **Inheritance**: There are special classes for First Semester and Second Semester results. These classes inherit (reuse) common features from a general 'SemesterResult' class, so we don't repeat code.
- **Polymorphism**: The program can treat different semester types (first or second) in a similar way, but each can have its own custom behavior when needed. This makes the program flexible and easy to extend.
- **Main Function**: This is where the program starts. It asks the user for their name, level, semester, and course details, calculates the GPA, and saves everything to a file. It also allows entering results for multiple semesters.
- **File Output**: After entering your details, the program saves all your results in a text file (`cgpa_result.txt`) so you can keep a record.
- **User Prompts**: The program guides you step-by-step, asking for all necessary information and explaining what each input means.

## Group 9 Members
1. Oguntoye Bidemi 230591302
2. ⁠Balogun Ahmed 230591344
3. Buhari Al-ameen 230591269
4. Adebisi Kayode Precious 230115065
5. ⁠HAASTRUP ADETUMILARA RAPHEAL 230591224
6. Onochie Emmanuel Chinedu 230115031
7. Disu Qomarudeen Temiloliwa 230591219
8. Umoh Joy Zion 230591179
9. Adisa abdulgafar 230115007
10. Sanya Kamaldeen Olatunji 240115143
11. Daso Emmanuel Oluwarotimi 240115119
12. Shofolu Oladapo 230591253
13. Akpan Samuel Augustine 230115133
14. ⁠Pelujo shukurat Mojisola 240591431
15. Ogunbanjo Samuel Babatunde 190591185
16. ⁠Olorunfunmi Samuel damilola 230591241
17. ⁠Afod omiayo toluwalase 230591020
18. Oyathelemhi Stephanie 230591246
19. IGOCHE PRAISE OJOCHIDE 220115041
20. Taiwo alameen olasubomi 230591279
21. Adedokun Adedayo Tobiloba 230591261
22. Akinjeji Oluwaferanmi Samuel 230591031
23. Agboola Victor Ifedolapo 230591024
24. Eletu ireayotomiwa Adeshina 230591271
25. ⁠Name: Turner Nelson Akinpelumi 230591178
26. Lawal Abdulwahab Olaniyi 240591437
