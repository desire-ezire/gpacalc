#include <iostream>
#include <string>
#include <fstream> //understand file handling using fstream
using namespace std;

string name;
float score,grade_point,creditUnit, GradePoint, gpa, cgpa;
float total_gpa, total_cgpa, total_creditUnit;
int num_classes = 0;
ofstream outFile("GPABreakdown.txt");

void moduleScore()
{
    int i;
    char grade;

    outFile << "GPA Breakdown for " << name << "." << endl;

    for (i=1;i<=10;i++)
    {
        cout << "Please enter your score for module " << i << ": ";

        /*Always ask if they would like to enter another grade to update the file*/
        cin >> score;
        
        if (score == -1)
        {
            break;
        }

        cout << "Enter the credit unit for module " << i << ": ";
        cin >> creditUnit;
        
        if (score >= 0 && score <= 100)
        {
            cout << "Your grade is ";

            if (creditUnit >= 0 && creditUnit <= 3)
            {
                if (score>=70)
                {
                    cout << "A" << endl;
                    grade_point = 4.0;
                    grade = 'A';
                    cout << "The gradepoint for this grade is " << grade_point << endl;
                }

                else if (score>=60)
                {
                    cout << "B" << endl;
                    grade_point = 3.0;
                    grade = 'B';
                    cout << "The gradepoint for this grade is " << grade_point << endl;
                }

                else if (score>=50)
                {
                    cout << "C" << endl;
                    grade_point = 2.0;
                    grade = 'C';
                    cout << "The gradepoint for this grade is " << grade_point << endl;
                }

                else if (score>=45)
                {
                    cout << "D" << endl;
                    grade = 'D';
                    grade_point = 1.0;
                    cout << "The gradepoint for this grade is " << grade_point << endl;
                }

                else
                {
                    cout << "F" << endl;
                    grade = 'F';
                    grade_point = 0.0;
                    cout << "The gradepoint for this grade is " << grade_point << endl;
                }
            }

            else
            {
                cout << "The value you entered is invalid." << endl;
                return;
            }

        
        GradePoint = grade_point * creditUnit;
        cout << "Your grade point for this course is " << GradePoint << endl << endl;
        }

        else
        {
            cout << "This score is invalid";
            return;
        }

        total_gpa += GradePoint;
        total_creditUnit += creditUnit;

        gpa = total_gpa/total_creditUnit;
        outFile << "Module   " << i << "     : " 
        << grade_point << " | " << grade << " | " << score << endl;
    }

    cout << "Your gpa is " << gpa << endl;
    outFile << "Your gpa is " << gpa << endl;

}

int main()
{

    /*
    The code should allow you to enter your name;
    The code store name of classes you enter once your grade
    > it shows the grade with score and computes grade point average
    
    The program should loop through the class grades a maximum of ten times
    The program should export your grade in a txt file
    > The program should read a txt files with grades like it is uploaded unto the program
    */
    
    cout << "Please enter your name: ";
    cin >> name;
    cout << endl;
    cout << "Hello " << name << "." << endl;

    moduleScore();
    return 0;
}