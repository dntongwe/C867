#pragma once
class Student {
public:
    int* k;


    Student(int a[4]) {
        k = a;
        cout << "student created" << endl << endl;
    };

    void setK(int a[4]) {
        k = a;
    };

    int getK() {

        for (int i = 0; i < 4; i++) {
            cout << "Array element " << i << " = ";
            cout << *(k + i) << endl << endl;

        }
        cout << "{" << *(k + 0) << " " << *(k + 1) << " " << *(k + 2) << "}" << endl << endl;
        return 0;
    }

};
