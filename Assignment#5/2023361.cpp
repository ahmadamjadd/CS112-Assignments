#include<iostream>
using namespace std;

class CMyString{
    char *Array1;
    int string_size;

public:
    // Constructors and Destructor
    CMyString(); // Default Constructor
    CMyString(const char *Array2);
    CMyString(int string_size);
    ~CMyString();

    // Member functions
    int get_size_of_string();
    void display();

    // Overloaded operators
    CMyString operator+(CMyString &other);
    CMyString operator+=(CMyString &other);
    char& operator[](int index);
    bool operator==(const CMyString &other);
    bool operator!=(const CMyString &other);
    bool operator>(const CMyString &other);
    bool operator<(const CMyString &other);
    CMyString operator()(int start, int end);
    friend ostream &operator<<(ostream &output, CMyString &a);
    friend istream &operator>>(istream &input, CMyString &a);
    CMyString operator=(const CMyString other);
    friend CMyString operator<<(CMyString &other, int n);
    friend CMyString operator>>(CMyString &other, int n);
};

int main()
{
    //original strings
    CMyString a("ABCDEFG");
    CMyString b("1234567");
    cout << "Displaying the original strings:\n";
    cout<<"a: ";
    a.display();
    cout<<endl;
    cout<<"b: ";
    b.display();
    cout<<endl<<endl;

    // Test operator+
    cout << "1: Test operator+: " << endl;
    cout << "a + b: ";
    CMyString c(50); // Create a temporary CMyString object to hold the result
    c = a + b; // Concatenate a and b
    c.display();
    cout << endl<<endl;

    // Test operator+=
    cout << "2: Test operator+=: " << endl;
    cout << "a += b: ";
    (a += b).display(); // Concatenate b to a and display the result
    cout << endl<<endl;

    // Test operator[]
    cout << "3: Test operator[]: " << endl;
    char ch = a[1];
    cout << "ch = a[1] : " << ch << endl<<endl;

    // Test modifying with operator[]
    cout << "4: Modify b with operator[]: " << endl;
    b[4] = '1';
    cout<<"b[4] = '1' : ";
    b.display();
    cout << endl <<endl;

    // Test operator==
    cout << "5: Test operator==: " << endl;
    if (a == b)
        cout << "a is equal to b" << endl<<endl;
    else
        cout << "a is not equal to b" << endl <<endl;

    // Test operator!=
    cout << "6: Test operator!=: " << endl;
    if (a != b)
        cout << "a is not equal to b" << endl<<endl;
    else
        cout << "a is equal to b" << endl<<endl;

    // Test operator>
    cout << "7: Test operator>: " << endl;
    if (a > b)
        cout << "a is greater than b" << endl<<endl;
    else
        cout << "a is not greater than b" << endl<<endl;

    // Test operator<
    cout << "8: Test operator<: " << endl;
    if (a < b)
        cout << "a is less than b" << endl<<endl;
    else
        cout << "a is not less than b" << endl<<endl;

    // Test operator()
    cout << "9: Test operator(): " << endl;
    CMyString p(50);
    p = a(0, 3); // Get a substring of a
    cout << "Substring of a(0, 3): ";
    p.display();
    cout << endl<<endl;

    // Test operator<<
    cout << "10: Test operator<<(cout): " << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl<<endl;

    // Test operator>>
    cout << "11: Test operator>>(cin):\nEnter a string: ";
    CMyString f;
    cin >> f;
    cout << "You entered: " << f << endl<<endl;

    // Test operator=
    cout << "12: Test operator=:" << endl;;
    CMyString e(50);
    e = a;
    cout << "a: " << a << endl;
    cout << "e (assigned from a): " << e<<endl<<endl;

    // Test operator>>
    cout << "13: Test operator>>: " << endl;
    cout<<"w = a >> 1 "<<endl;
    CMyString w = a >> 1;
    cout << "w: " << w << endl;
    cout << "a: " << a << endl<<endl;

    // Test operator<<
    cout << "14: Test operator<<: " << endl;
    cout<<"w = b << 1 "<<endl;
    CMyString z = b << 1;
    cout << "z: " << z << endl;
    cout << "b: " << b << endl<<endl;

    return 0;
}

// Default Constructor
CMyString :: CMyString(){
    string_size = 0;
    Array1 = new char[50];
    Array1[0] = '\0';
}

// Constructor with a character array
CMyString :: CMyString(const char *Array2){
    string_size = 0;
    while (Array2[string_size] != '\0') {
        string_size++;
    }
    Array1 = new char[string_size + 1];
    for (int i = 0; i < string_size; i++) {
        Array1[i] = Array2[i];
    }
    Array1[string_size] = '\0';
}

// Constructor with a specified size
CMyString :: CMyString(int size){
    string_size = size;
    Array1 = new char[size + 1];
    for (int i = 0; i < size; i++) {
        Array1[i] = '\0';
    }
    Array1[size] = '\0';
}

// Destructor
CMyString :: ~CMyString(){
    delete[] Array1;
}

// Get the size of the string
int CMyString :: get_size_of_string(){
    return string_size;
}

// Display the string
void CMyString :: display(){
    int i = 0;
    while(Array1[i] != '\0'){
        cout<<Array1[i];
        i++;
    }
}

// Overloaded operator +
CMyString CMyString :: operator+(CMyString &other){
    int new_size = string_size + other.string_size;
    CMyString Result(new_size);
    int i = 0;
    for (; i < string_size; i++) {
        Result.Array1[i] = Array1[i];
    }
    for (int j = 0; j < other.string_size; j++, i++) {
        Result.Array1[i] = other.Array1[j];
    }
    return Result;
}

// Overloaded operator +=
CMyString CMyString :: operator+=(CMyString &other){
    int new_size = string_size + other.string_size;
    CMyString Result(new_size);
    int i = 0;
    for (; i < string_size; i++) {
        Result.Array1[i] = Array1[i];
    }
    for (int j = 0; j < other.string_size; j++, i++) {
        Result.Array1[i] = other.Array1[j];
    }
    return Result;
}

// Overloaded operator []
char& CMyString :: operator[](int index){
    return Array1[index];
}

// Overloaded operator ==
bool CMyString :: operator==(const CMyString &other){
    for(int i = 0; i<string_size; i++){
        if(Array1[i] != other.Array1[i]){
            return false;
        }
    }
    return true;
}

// Overloaded operator !=
bool CMyString :: operator!=(const CMyString &other){
    for(int i = 0; i<string_size; i++){
        if(Array1[i] != other.Array1[i]){
            return true;
        }
    }
    return false;
}

// Overloaded operator >
bool CMyString :: operator>(const CMyString &other){
    int i = 0;
    while(Array1[i] != '\0' && other.Array1[i] != '\0' && Array1[i] == other.Array1[i]){
        i++;
    }
    if(Array1[i] == '\0' && other.Array1[i] == '\0'){
        return false;
    }
    else if(Array1[i] > other.Array1[i]){
        return true;
    }
    return false;
}

// Overloaded operator <
bool CMyString :: operator<(const CMyString &other){
    int i = 0;
    while(Array1[i] != '\0' && other.Array1[i] != '\0' && Array1[i] == other.Array1[i]){
        i++;
    }
    if(Array1[i] == '\0' && other.Array1[i] == '\0'){
        return false;
    }
    else if(Array1[i] > other.Array1[i]){
        return false;
    }
    return true;
}

// Overloaded operator ()
CMyString CMyString::operator()(int start, int end) {
    // Calculate the length of the substring
    int subLength = end - start + 1;

    // Allocate memory for the substring
    char* subArray = new char[subLength + 1];

    // Copy characters from the original string to the substring
    for (int i = 0; i < subLength; i++) {
        subArray[i] = Array1[start + i];
    }

    // Add null terminator to create a valid C-style string
    subArray[subLength] = '\0';

    // Create a new CMyString object with the substring
    CMyString subString(subArray);

    // Deallocate memory for the substring
    delete[] subArray;

    return subString;
}

// Overloaded operator <<
ostream &operator<<(ostream &output, CMyString &a){
    output << a.Array1;
    return output;
}

// Overloaded operator >>
istream &operator>>(istream &input, CMyString &a){
    input >> a.Array1;
    return input;
}

// Overloaded operator =
CMyString CMyString :: operator=(const CMyString other){
    for(int i = 0; i<string_size; i++){
        Array1[i] = other.Array1[i];
    }
    return *this;
}

// Overloaded operator <<
CMyString operator<<(CMyString& other, int n) {
    // Ensure n is not greater than the size of the string
    if (n >= other.get_size_of_string()) {
        // If n is greater than or equal to the size of the string, return the original string
        return other;
    }
    // Extract the first n characters from source
    CMyString result = other(0, n - 1);

    // Update source by removing the first n characters
    other = other(n, other.get_size_of_string() - 1);

    return result;
}

// Overloaded operator >>
CMyString operator>>(CMyString& other, int n) {
    // Ensure n is not greater than the size of the string
    if (n >= other.get_size_of_string()) {
        // If n is greater than or equal to the size of the string, return the original string
        return other;
    }

    // Extract the last n characters from other to create result
    CMyString result = other(other.get_size_of_string() - n, other.get_size_of_string() - 1);

    // Update other by removing the last n characters
    other = other(0, other.get_size_of_string() - n - 1);

    return result;
}


