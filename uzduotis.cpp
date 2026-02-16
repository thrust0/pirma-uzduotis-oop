#include <iomanip>
#include <vector>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::left;
using std::right;
using std::setw;
using std::endl;

struct Students {
    string name = "A", last_name = "BB";
    //int *paz jei dinaminis masyvas
    vector <int> grade;
    int exam;
    double result;
};
void input(vector<Students>& group);
void output(vector<Students>& group);

int main() 
{
    vector<Students>group;
    input(group);
    output(group);

}
void input(vector<Students>& group) 
{
    for (int ii = 0; ii < 2; ii++) {
        Students student;
        cout << "Iveskite varda ir pavarde: ";
        cin >> student.name >> student.last_name;
        cout << "Iveskite semestro ivertinimus. Kiek ju bus? ";
        int n, sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++) 
        {
            int temp;
            cout << "Iveskite " << i + 1 << " pazymi is " << n << ":";
            cin >> temp;
            student.grade.push_back(temp); sum += temp;
        }
        cout << "Iveskite egzamina: "; cin >> student.exam;
        student.result = sum * 1.0 / (n * 1.0) * 0.4 + student.exam * 0.6;
        group.push_back(student);
        student.grade.clear();
    }// galima priskirti grupej, kai turime A.rez; pushbackinam studento pavadinima
}
void output(vector<Students>& group) 
{
    for (auto student : group) {
        cout << left << setw(10) << student.name << left << setw(20) << student.last_name;
        //for (auto k : A.paz) cout << setw(3) << k;
        //cout << setw(5) << A.egz;
        cout << setw(10) << student.result << endl;
    }
}
