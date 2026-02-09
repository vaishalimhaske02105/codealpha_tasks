#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    vector<float> grades(n), credits(n);
    float totalCredits = 0, totalGradePoints = 0;

    // Input grades and credits
    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << endl;
        cout << "Enter grade (out of 10): ";
        cin >> grades[i];
        cout << "Enter credit hours: ";
        cin >> credits[i];

        totalCredits += credits[i];
        totalGradePoints += grades[i] * credits[i];
    }

    // GPA / CGPA calculation
    float cgpa = totalGradePoints / totalCredits;

    // Display individual course details
    cout << "\n--- Course Details ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Course " << i + 1
             << " | Grade: " << grades[i]
             << " | Credits: " << credits[i] << endl;
    }

    // Final CGPA
    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Final CGPA: " << cgpa << endl;

    return 0;
}
