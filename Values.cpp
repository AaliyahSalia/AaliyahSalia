//Inputting Decimal, Octal and Hexadecimal Values


//Writing a program to test the inputting of integer values in decimal, octal and hexadecimal formats. 


#include <iostream>
#include <stack>
using namespace std;

// To convert and print the given number in decimal format using stack
void toDecimal(int num){
    // Create a stack
    stack<int>st;
    // Run a while loop to convert given number in decimal format
    while(num > 0){
        st.push(num%10);
        num /= 10;
    }
    cout << "Number " << num << " in octal format is "; 
    // To print the number in decimal format
    while(!st.empty()){
        cout << st.top() << "";
        st.pop();
    }
    cout << endl;
    
}

// To convert and print the given number in octal format using stack
void toOctal(int num){
    
    stack<int>st;
    while(num > 0){
        st.push(num%8);
        num /= 8;
    }
    cout << "Number " << num << " in octal format is "; 
    while(!st.empty()){
        cout << st.top() << "";
        st.pop();
    }
    cout << endl;
}

// To convert and print the given number in hexadecimal format using stack
void toHexadecimal(int num){
    stack<int>st;
    while(num > 0){
        st.push(num%16);
        num /= 16;
    }
    cout << "Number " << num << " in octal format is "; 
    while(!st.empty()){
        cout << st.top() << "";
        st.pop();
    }
    cout << endl;
}

// main function
int main(){
    int num;
    // Read the number from user and call & test all the three methods
    for(int i = 0; i < 5; i++){
        cout << "Enter number: ";
        cin >> num;
        toDecimal(num);
        toOctal(num);
        toHexadecimal(num);
        cout << endl;
    }
    return 0;

}
