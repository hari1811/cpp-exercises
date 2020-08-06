//Name : K Haripriya , Employee ID : 127349

#include<iostream>
#include<string>
using namespace std;

/**
 * @Class               MyString
 * @data-members        char* stringPtr; int len;
 * @member-functions    ReverseString(), word_count(), FindLongestWord(), findchar()
 */
class MyString {

protected:
    char* stringPtr;
    int len;

public:

    MyString() : stringPtr(NULL), len(0) {}
    MyString(char* inpStr) : stringPtr(inpStr), len(strlen(inpStr)) {}


    /**
     *   @Function       ReverseString
     *   @Description    Reverses contents of the string passed as an argument,
     *                   does not use additional buffer
     *   @retval         none
     **/
    void  ReverseString() {
        char temp;
        int i;
        for (i = 0; i < len / 2; i++) {
            temp = *(stringPtr + i);
            *(stringPtr + i) = *(stringPtr + len - 1 - i);
            *(stringPtr + len - 1 - i) = temp;
        }

    }

    /**
     *   @Function       word_count
     *   @Description    counts number of words in the null terminated string 
     *
     *   @retval         number of words
     *   @Note           Assumed word is separated by a space or tab or newline characters.
     **/
    int  word_count() {
        int count = 0;
        char* p = stringPtr;
        bool prev = true;
        while (*p != '\0') {
            if (*p == ' ' || *p == '\t' || *p == '\n') {
                if (prev == false) {
                    count += 1;
                    prev = true;
                }
            }
            else prev = false;
            p += 1;
        }
        if (prev == false)
            count += 1;
        return count;
    }

    /**
 *   @Function       FindLongestWord
 *   @Description    to find the longest word in the string pointed by pStr
 *                   stores the pointer to the longest word in pWord
 *   @retval         length of the longest word
 *
 *   @Note           Space and tab are considered as word separators.
 **/
    int  FindLongestWord(char** pWord) {

        char* p = (char*)stringPtr;
        int currLen = 0, finalLen = 0;
        char* currWord = NULL;
        bool prev = false; //previous char belongs to a word

        while (*p != '\0') {
            if (*p == ' ' || *p == '\t' || *p == '\n') {
                if (prev == true) {
                    if (currLen > finalLen) {
                        finalLen = currLen;
                        *pWord = currWord; //giving error
                    }
                    currLen = 0;
                    prev = false;
                }
            }
            else {
                if (prev == false) {
                    currWord = p;
                    prev = true;
                }
                currLen += 1;
            }
            p += 1;
        }
        if (prev == true) {
            if (currLen > finalLen) {
                finalLen = currLen;
                *pWord = currWord;
            }
        }
        return finalLen;
    }


     /**
     *   @Function       findchar
     *   @Description    to find the first occurrence of the character specified in the 
     *                   string passed as an argument / data - member
     *   @arguments      str - is null terminated string in which to search
     *                   ch - character to search
     *   @retval         index of the first occurence of char ch in the string str
     *                   -1 if ch doesn't exist in the string
     *
     **/
    int findchar(char ch) {
        int index = 0;
        char* p = stringPtr;
        while (*p != '\0') {
            if (*p == ch)
                break;
            p += 1;
        }
        if (*p != '\0')
            index = p - stringPtr;
        else index = -1;
        return index;
    }
};

/**
 * @Derived Class       MyChar from MyString
 * @data-members        char* stringPtr; int len; 
 * @member-functions    CountZeroBits()
 */
class MyChar : public MyString {
public:
    MyChar() {
        stringPtr = NULL;
        len = 0;
    }

    /**
     *   @Function       CountZeroBits
     *   @retval         the number of zero bits of the character passed as argument
     **/
    int  CountZeroBits(unsigned char  c) {
        int count = 0;
        int i;
        for (i = 0; i < 8; i++) {
            if (c % 2 == 1)
                count++;
            c = c >> 1;
        }
        return 8 - count;
    }
};


//f)Num2Words
//
//Implement the sub - Class Num2Words, with operator-overloading
//that stores the num in words in buffer pointed by str.Str should be null terminated, as shown below,
//Ex.Char str[1024];
//Num2Words(123)->str;  str à "ONE TWO THREE"
//Num2Words(10042)->str;  str à "ONE ZERO ZERO FOUR TWO“
//Test the function in main()

const char* WordNum[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", 
                          "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

/**
 * @Derived Class           Num2Words from MyString
 * @data-members            char* stringPtr; int len;  int Number;  char numString[10];
 * @operator overloading    > 
 */
class Num2Words : public MyString {
    int Number;
    char numString[10];
public:
        Num2Words(int num) {
            _itoa_s(num, numString, 10, 10);
            stringPtr = numString;
            len = strlen(numString);
            Number = num;
        }
    
        void operator > (char* OpStr) {
    
            *OpStr = '\0';

            int i = len-1;
            int temp = Number;

            while (i >= 0) {
                int currInt = temp / int(pow(10, i));
                const char* currWord = WordNum[currInt];
                temp = temp - (currInt * int(pow(10, i)));
                strcat_s(OpStr, 1024, currWord);
                if(i > 0)
                    strcat_s(OpStr, 1024, " ");
                //strcat(OpStr, currWord); //unsafe to use, may lead to memory corruption
                i -= 1;
            }
        }
    
};




void main() {


    cout << "\nReverse String------------------" << endl;
    char testStr[] = "Hello World!";
    cout << "test string : " << testStr << endl;
    MyString(testStr).ReverseString();
    cout << "reversed test string : " << testStr << endl;


    cout << "\nWord Count----------------------" << endl;
    char* testLine = (char*)" \t Hello World!  This is word count. \n";
    cout << "test string : " << testLine;
    cout << "No of words in string : " << MyString(testLine).word_count() << endl;


    cout << "\nFind Longest Word---------------" << endl;
    char* longestWord;
    char* testLine1 = (char*)" \t HelloWorld!  This is Find longest word. \n";
    cout << "test line : " << testLine1;
    cout << "Longest word in string has length: ";
    cout << MyString(testLine1).FindLongestWord(&longestWord) << endl;


    cout << "\nFind char-----------------------" << endl;
    char* testLine2 = (char*)" HelloWorld!  This is find char. \n";
    cout << "test line : " << testLine2;
    int index = MyString(testLine2).findchar('h');
    cout << "char = h" << ", char index in line : " << index << endl;
    index = MyString(testLine2).findchar('o');
    cout << "char = o" << ", char index in line : " << index << endl;
    index = MyString(testLine2).findchar('v');
    cout << "char = v" << ", char index in line : " << index << endl;


    cout << "\nCount zero bits-----------------" << endl;
    cout << "No of zero bits in char A : " << MyChar().CountZeroBits('A') << endl;
    cout << "No of zero bits in char 0x4C : " << MyChar().CountZeroBits(0x4C) << endl;
    cout << "No of zero bits in char 443 : " << MyChar().CountZeroBits(443) << endl;


    cout << "\nNum2Words-----------------------" << endl;
    char str[1024];
    Num2Words(123) > str;  //str à "ONE TWO THREE"
    cout << "Number " << 123 << " in words : " << str << endl;
    Num2Words(10042) > str;  //str à "ONE ZERO ZERO FOUR TWO“
    cout << "Number " << 10042 << " in words : " << str << endl;
    Num2Words(0) > str;  
    cout << "Number " << 0 << " in words : " << str << endl;


}