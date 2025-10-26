// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
    //1
    cout 
        << "int: " << sizeof(int) << "\n"
        << "short int: " << sizeof(short int) << "\n"
        << "long int: " << sizeof(long int) << "\n"
        << "float: " << sizeof(float) << "\n"
        << "double: " << sizeof(double) << "\n"
        << "long double: " << sizeof(long double) << "\n"
        << "char: " << sizeof(char) << "\n"
        << "bool: " << sizeof(bool) << "\n";


    //2
    cout << endl << "enter int nomber ";
    
    int intNumber;
	cin >> intNumber;
    int musk = 1;
    int order = sizeof(int) * 8;
    
	cout << "\n";

    cout << "intNumber: " << &intNumber << " : " << intNumber << endl;
    //for (int i = 0; i < order; i++) {
    for (int i = order-1; i >= 0; i--) {
        if (intNumber & (musk << i)) {
            cout << '1';
        }
        else {
            cout << '0';
        }

        if (i == order - 1) {
            cout << '_';
        }
        //if ((i + 1) % 8 == 0) {
        if ((i) % 8 == 0) {
            cout << ' ';
        }
    }
    cout << endl;

    


    //3
    union {
        float floatNumber;
        int intNumber;
    } c; 
	cout << "\n\nenter float nomber ";
	cin >> c.floatNumber;

    cout 
        << "\nfloatNumber: " << &(c.floatNumber) << " : " << c.floatNumber << endl
        << "intNumber: " << &(c.intNumber) << " : " << c.intNumber << endl;
    
    
    int orderF = sizeof(float) * 8;
    //int muskF = 1 << (orderF - 1);
    int muskF = 1;

    // число: 101011
    // маска: 100000
    // резул: 100000

    for (int i = orderF - 1; i >= 0; i--) {
        if (c.intNumber & (muskF << i)) {
            cout << '1';
        }
        else {
            cout << '0';
        }

        if (i == orderF - 1) {
            cout << '_';
        }
        if (i == orderF - 1 - 8) {
            cout << '_';
        }
        //if ((i + 1) % 8 == 0) {
        if ((i) % 8 == 0) {
            cout << ' ';
        }
    }


    //4
    union {
        double doubleNumber;
        int intNumber[2];
        long long int longNumber;
    } d;

	cout << "\n\nenter double nomber ";
	cin >> d.doubleNumber;

    cout
        << "\n\ndoubleNumber: " << &(d.doubleNumber) << " : " << d.doubleNumber << endl
        << "intNumber[0]: " << &(d.intNumber[0]) << " : " << d.intNumber[0] << endl
        << "intNumber[1]: " << &(d.intNumber[1]) << " : " << d.intNumber[1] << endl
        << "longNumber:   " << &(d.longNumber) << " : " << d.longNumber << endl;


    int orderD = sizeof(double) * 8;
    long long int muskD = 1;

    // -3.14
    // double: 11000000 00001001 00011110 10111000    01010001 11101011 10000101 00011111
    // int[0]: 01010001 11101011 10000101 00011111
    // int[1]: 11000000 00001001 00011110 10111000
    // маска : 10000000 00000000 00000000 00000000
    // резул : 10000000 00000000 00000000 00000000

    cout << "int[]: ";
    for (int i = orderD - 1; i >= 0; i--) {
        if (i >= orderF) {
            if (d.intNumber[1] & (muskF << (i-orderF))) {
                cout << '1';
            }
            else {
                cout << '0';
            }
        }
        else {
            if (d.intNumber[0] & (muskF << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }
        }

        if (i == orderD - 1) {
            cout << "_";
        }
        if (i == orderD - 1 - 11) {
            cout << "_";
        }
        //if ((i + 1) % 8 == 0) {
        if ((i) % 8 == 0) {
            cout << ' ';
        }
    }
    cout << endl;

    cout << "long:  ";
    for (int i = orderD - 1; i >= 0; i--) {
        if (d.longNumber & (muskD << i)) {
            cout << '1';
        }
        else {
            cout << '0';
        }

        if (i == orderD - 1) {
            cout << "_";
        }
        if (i == orderD - 1 - 11) {
            cout << "_";
        }
        //if ((i + 1) % 8 == 0) {
        if ((i) % 8 == 0) {
            cout << ' ';
        }
    }
    cout << endl;

//    for (int i = 0; i < orderF; i++) {
//        putchar(c.intNumber & muskF >> i ? '1' : '0');
//        if ((i + 1) % 8 == 0) {
//            cout << ' ';
//        }
//        }

    
    //5
    cout << endl;

    int type;

    cout << "enter a type number (int = 1, float = 2, double or long double = 3, short int = 4, char = 5, bool = 6): ";
    cin >> type;

    switch (type) 
    {
    case 1: {
        int bitToChange;
        int intNumberToChange;

        cout << "\nenter a number (int): ";
        cin >> intNumberToChange;

        for (int i = order - 1; i >= 0; i--) {
            if (intNumberToChange & (musk << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == order - 1) {
                cout << '_';
            }
            
            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;

        cout << "\nbit to change (0 - no change): ";
        cin >> bitToChange;
        cout << endl;

        int maskToChange = 1;
        if (bitToChange > 0) {
            intNumberToChange = intNumberToChange ^ (maskToChange << (bitToChange - 1));
        }
        cout << "intNumberToChange: " << &intNumberToChange << " : " << intNumberToChange << endl;

        for (int i = order - 1; i >= 0; i--) {
            if (intNumberToChange & (musk << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == order - 1) {
                cout << '_';
            }
            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
		cout << endl;
        break;
    }
    
    case 2: {
        union {
            float floatNumberToChange;
            int intNumber;
        } c1;

        int bitToChange;

        cout << "\nenter a number (float): ";
        cin >> c1.floatNumberToChange;

        for (int i = orderF - 1; i >= 0; i--) {
            if (c1.intNumber & (muskF << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == orderF - 1) {
                cout << '_';
            }
            if (i == orderF - 1 - 8) {
                cout << '_';
            }
            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;


        cout << "\nbit to change (0 - no change): ";
        cin >> bitToChange;
        cout << endl;

        int maskToChange = 1;
        if (bitToChange > 0) {
            c1.intNumber = c1.intNumber ^ (maskToChange << (bitToChange - 1));
        }
        cout << "floatNumberToChange: " << &c1.floatNumberToChange << " : " << c1.floatNumberToChange << endl;


        for (int i = orderF - 1; i >= 0; i--) {
            if (c1.intNumber & (muskF << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == orderF - 1) {
                cout << '_';
            }
            if (i == orderF - 1 - 8) {
                cout << '_';
            }
            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
		cout << endl;
        break;
    }
    case 3: {
        union {
            double doubleNumberToChange;
            int intNumber[2];
        } d1;

        int bitToChange;
        int maskToChange = 1;

        cout << "\nenter a number (double): ";
        cin >> d1.doubleNumberToChange;

        for (int i = orderD - 1; i >= 0; i--) {
            if (i >= orderF) {
                if (d1.intNumber[1] & (muskF << (i - orderF))) {
                    cout << '1';
                }
                else {
                    cout << '0';
                }
            }
            else {
                if (d1.intNumber[0] & (muskF << i)) {
                    cout << '1';
                }
                else {
                    cout << '0';
                }
            }

            if (i == orderD - 1) {
                cout << "_";
            }
            if (i == orderD - 1 - 11) {
                cout << "_";
            }

            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;

        cout << "\nbit to change (0 - no change): ";
        cin >> bitToChange;
        cout << endl;
        
        if (bitToChange > 0) {
            if (bitToChange > orderF) {
                d1.intNumber[1] = d1.intNumber[1] ^ (maskToChange << (bitToChange - 1));
            }
            else {
                d1.intNumber[0] = d1.intNumber[0] ^ (maskToChange << (bitToChange - 1));
            }
                
        }

        

        for (int i = orderD - 1; i >= 0; i--) {
            if (i >= orderF) {
                if (d1.intNumber[1] & (muskF << (i - orderF))) {
                    cout << '1';
                }
                else {
                    cout << '0';
                }
            }
            else {
                if (d1.intNumber[0] & (muskF << i)) {
                    cout << '1';
                }
                else {
                    cout << '0';
                }
            }

            if (i == orderD - 1) {
                cout << "_";
            }
            if (i == orderD - 1 - 11) {
                cout << "_";
            }
            
            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;
        break;
    }
    case 4: {
        short int bitToChange;
        short int intNumberToChange;
        short int shortMuskToChange = 1;

        cout << "\nenter a number (short int): ";
        cin >> intNumberToChange;

        for (short int i = 16 - 1; i >= 0; i--) {
            if (intNumberToChange & (shortMuskToChange << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == order - 1) {
                cout << '_';
            }

            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;

        cout << "\nbit to change (0 - no change): ";
        cin >> bitToChange;
        cout << endl;

        short int maskToChange = 1;
        if (bitToChange > 0) {
            intNumberToChange = intNumberToChange ^ (maskToChange << (bitToChange - 1));
        }
        cout << "intNumberToChange: " << &intNumberToChange << " : " << intNumberToChange << endl;

        for (short int i = 16 - 1; i >= 0; i--) {
            if (intNumberToChange & (shortMuskToChange << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == order - 1) {
                cout << '_';
            }
            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
		cout << endl;
        break;
    }
    
    case 5: {
        int bitToChange;
        char intNumberToChange;
        char shortMuskToChange = 1;

        cout << "\nenter a number (char): ";
        cin >> intNumberToChange;

        for (char i = 8 - 1; i >= 0; i--) {
            if (intNumberToChange & (shortMuskToChange << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == order - 1) {
                cout << '_';
            }

            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;

        cout << "\nbit to change (0 - no change): ";
        cin >> bitToChange;
        cout << endl;

        char maskToChange = 1;
        if (bitToChange > 0) {
            intNumberToChange = intNumberToChange ^ (maskToChange << (bitToChange - 1));
        }
        cout << "charNumberToChange: " << intNumberToChange << endl;

        for (char i = 8 - 1; i >= 0; i--) {
            if (intNumberToChange & (shortMuskToChange << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == order - 1) {
                cout << '_';
            }
            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        break;
        cout << endl;
    }
    case 6: {
        int bitToChange;
        bool intNumberToChange;
        char shortMuskToChange = 1;

        cout << "\nenter a number (bool): ";
        cin >> intNumberToChange;

        for (char i = 8 - 1; i >= 0; i--) {
            if (intNumberToChange & (shortMuskToChange << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == order - 1) {
                cout << '_';
            }

            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;

        cout << "\nbit to change (0 - no change): ";
        cin >> bitToChange;
        cout << endl;

        char maskToChange = 1;
        if (bitToChange > 0) {
            intNumberToChange = intNumberToChange ^ (maskToChange << (bitToChange - 1));
        }
        cout << "boolNumberToChange: " << intNumberToChange << endl;

        for (char i = 8 - 1; i >= 0; i--) {
            if (intNumberToChange & (shortMuskToChange << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == order - 1) {
                cout << '_';
            }
            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        break;
        cout << endl;
    }
    /*case 7: {
        union {
            double doubleNumberToChange;
            int intNumber[3];
        } d2;

        int bitToChange;
        int maskToChange = 1;
        int orderLD = 12;

        cout << "\nenter a number (long double): ";
        cin >> d2.doubleNumberToChange;

        for (int i = orderLD - 1; i >= 0; i--) {
            if (i >= orderD) {
                if (d2.intNumber[2] & (muskF << (i - orderF))) {
                    cout << '1';
                }
                else {
                    cout << '0';
                }
            }
            if ((i >= orderF) && (i < orderD)) {
                if (d2.intNumber[1] & (muskF << (i - orderF))) {
                    cout << '1';
                }
                else {
                    cout << '0';
                }
            }
            else {
                if (d2.intNumber[0] & (muskF << i)) {
                    cout << '1';
                }
                else {
                    cout << '0';
                }
            }

            if (i == orderLD - 1) {
                cout << "_";
            }
            if (i == orderLD - 1 - 11) {
                cout << "_";
            }

            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;

        cout << "\nbit to change (0 - no change): ";
        cin >> bitToChange;
        cout << endl;

        if (bitToChange > 0) {
            if (bitToChange > orderD) {
                d2.intNumber[2] = d2.intNumber[2] ^ (maskToChange << (bitToChange - 1));
            }
            if ((bitToChange > orderF) && (bitToChange <= orderD)) {
                d2.intNumber[1] = d2.intNumber[1] ^ (maskToChange << (bitToChange - 1));
            }
            else {
                d2.intNumber[0] = d2.intNumber[0] ^ (maskToChange << (bitToChange - 1));
            }

        }



        for (int i = orderLD - 1; i >= 0; i--) {
            if (i >= orderD) {
                if (d2.intNumber[2] & (muskF << (i - orderF))) {
                    cout << '1';
                }
                else {
                    cout << '0';
                }
            }
            if ((i >= orderF) && (i < orderD)) {
                if (d2.intNumber[1] & (muskF << (i - orderF))) {
                    cout << '1';
                }
                else {
                    cout << '0';
                }
            }
            else {
                if (d2.intNumber[0] & (muskF << i)) {
                    cout << '1';
                }
                else {
                    cout << '0';
                }
            }

            if (i == orderLD - 1) {
                cout << "_";
            }
            if (i == orderLD - 1 - 11) {
                cout << "_";
            }

            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;
        break;
    }*/
    default:
        cout << "\nyou entered not 1, 2, 3, 4, 5 or 6" << endl;
        
    }

    


    //ИДЗ 18

    union {
        double double18Number = 0.0;
        int int18Number[2];
    } z;

    cout
        << "\n\ndouble18Number: " << &(z.double18Number) << " : " << z.double18Number << endl;
    
    for (int i = orderD - 1; i >= 0; i--) {
        if (i >= orderF) {
            if (z.int18Number[1] & (muskF << (i - orderF))) {
                cout << '1';
            }
            else {
                cout << '0';
            }
        }
        else {
            if (z.int18Number[0] & (muskF << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }
        }

        if (i == orderD - 1) {
            cout << "_";
        }
        if (i == orderD - 1 - 11) {
            cout << "_";
        }
        if ((i) % 8 == 0) {
            cout << ' ';
        }
    }
    cout << endl;

    int mask18 = 1;

    
    for (int i = orderD - 1; i >= 0; i--) {
        if ((i >= 62) || (i < 51)) {
            z.int18Number[1] = z.int18Number[1] ^ (mask18 << i);
        }
        

    }

    cout
        << "\ndouble18Number: " << &(z.double18Number) << " : " << z.double18Number << endl;

    for (int i = orderD - 1; i >= 0; i--) {
        if (i >= orderF) {
            if (z.int18Number[1] & (muskF << (i - orderF))) {
                cout << '1';
            }
            else {
                cout << '0';
            }
        }
        else {
            if (z.int18Number[0] & (muskF << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }
        }

        if (i == orderD - 1) {
            cout << "_";
        }
        if (i == orderD - 1 - 11) {
            cout << "_";
        }
        if ((i) % 8 == 0) {
            cout << ' ';
        }
    }
    cout << endl;
    

    return 0;
}