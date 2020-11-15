#include <iostream>


using namespace std;

int main() {

    int row,col;

   cout<<"Enter number of rows"<<endl;
    cin>>row;

    cout<<"Enter number of cols"<<endl;
    cin>>col;

int **p, **q, **s;

    p = new int *[col];// remember this
    q = new int *[col];
    s = new int *[col];

    for (int i = 0; i <row ; ++i) {

        p[i] = new int[col];  // remember this
        q[i] = new int[col];
        s[i] = new int[col];


    }


    for (int i = 0; i <row; ++i) {

        for (int j = 0; j <col ; ++j) {

            cout<<"Enter rows at ["<<i<<"] and col at"<<"["<<j<<"] for matrice 1";
            cin>>p[i][j];

        }

    }


    for (int i = 0; i <row; ++i) {

        for (int j = 0; j <col ; ++j) {

            cout<<"Enter rows at ["<<i<<"] and col at"<<"["<<j<<"] for matrice 2";
            cin>>q[i][j];

        }

    }


    for (int i = 0; i <row; ++i) {

        for (int j = 0; j <col ; ++j) {
            s[i][j] = 0;
           s[i][j] =  s[i][j] + p[i][j] + q[i][j];


        }

    }


    for (int i = 0; i <row; ++i) {

        for (int j = 0; j <col ; ++j) {

            cout<<"addition at rows ["<<i<<"] and col at"<<"["<<j<<"] = ";
            cout<<s[i][j];
            cout<<endl;

        }

    }




    return 0;
}
