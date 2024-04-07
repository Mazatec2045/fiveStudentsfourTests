#include <iostream>
#include <string>

using namespace std;

// Constants
const int NUM_STUDENTS = 5;
const int NUM_TESTS = 4;

// Function prototypes
void getStudentData(string studentNames[], double testScores[][NUM_TESTS], int studentIndex);
double calculateAverage(const double testScores[], int numTests);
char determineLetterGrade(double averageScore);
void displayResults(const string studentNames[], const double testScores[][NUM_TESTS], const char letterGrades[], int numStudents);

int main() {
    // Arrays for storing data
    string studentNames[NUM_STUDENTS];
    double testScores[NUM_STUDENTS][NUM_TESTS];
    char letterGrades[NUM_STUDENTS];

    // Get student data
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        getStudentData(studentNames, testScores, i);
    }

    // Calculate averages and letter grades
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        double average = calculateAverage(testScores[i], NUM_TESTS);
        char grade = determineLetterGrade(average);
        letterGrades[i] = grade;
    }

    // Display results
    displayResults(studentNames, testScores, letterGrades, NUM_STUDENTS);

    return 0;
}

// Function to get data for a single student
void getStudentData(string studentNames[], double testScores[][NUM_TESTS], int studentIndex) {
    cout << "Enter the name of student #" << studentIndex + 1 << ": ";
    cin >> studentNames[studentIndex];

    for (int i = 0; i < NUM_TESTS; ++i) {
        double score;
        do {
            cout << "Enter test score #" << i + 1 << " for "
                << studentNames[studentIndex] << ": ";
            cin >> score;
            if (score < 0 || score > 100) {
                cout << "Invalid score. Please enter a score between 0 and 100.\n";
            }
        } while (score < 0 || score > 100);
        testScores[studentIndex][i] = score;
    }
}

// Function to calculate average score
double calculateAverage(const double testScores[], int numTests) {
    double total = 0;
    for (int i = 0; i < numTests; ++i) {
        total += testScores[i];
    }
    return total / numTests;
}

// Function to determine the letter grade
char determineLetterGrade(double averageScore) {
    if (averageScore >= 90) {
        return 'A';
    }
    else if (averageScore >= 80) {
        return 'B';
    }
    else if (averageScore >= 70) {
        return 'C';
    }
    else if (averageScore >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
}

// Function to display the results 
void displayResults(const string studentNames[], const double testScores[][NUM_TESTS], const char letterGrades[], int numStudents) {
    cout << "\nStudent Results:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << studentNames[i] << ": Average Score = "
            << testScores[i][0] << ", Letter Grade = "
            << letterGrades[i] << endl;
    }
}
