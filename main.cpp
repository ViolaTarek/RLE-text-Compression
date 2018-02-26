#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;
string to_string(int n);
string Compress(string input);
int main()
{

    ifstream inFile;
    ofstream outFile;
    string str;
    outFile.open("PhoneListCompressed.txt");
    inFile.open("PhoneList.txt");
    if (!inFile.is_open())
    {
        exit(EXIT_FAILURE) ;

    }

    while( getline(inFile,str))
    {

        cout<<Compress(str)<<endl;
        outFile<<Compress(str);
    }

    inFile.close();

    return 0;
}

string Compress(string input)
{
    int Count;
    string encoding="";
    for (int i = 0; input[i]; i++)
    {
        Count = 1;
        if(input[i]!=' ')
        {
            while (input[i] == input[i + 1])
                Count++, i++;
            if(Count>2)
                encoding += '@'+to_string(Count) + input[i];

            else
                encoding += input[i];
        }
    }
    return encoding;

}

string to_string ( int n )
{
    stringstream ss;
    ss << n;
    return ss.str();
}
