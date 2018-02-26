#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;
string to_string(int n);
string Compress(string input);
string decompress(string Output);
int main()
{
    ifstream inFile;
    ofstream outFile;
    ifstream inFileComp;
    ofstream outFilede;
    string str;
    string str2;
    outFilede.open("Decompressed.txt");
    outFile.open("PhoneListCompressed.txt");
    inFile.open("PhoneList.txt");
    inFileComp.open("comp.txt");
    if (!inFile.is_open())
    {
        exit(EXIT_FAILURE) ;

    }
    //compress from infile to outfile

    while( getline(inFile,str))
    {
        cout<<Compress(str)<<endl;
        outFile<<Compress(str);
    }

    //decompress from infilecomp to outfilede


    while(getline(inFileComp,str2))
    {
        cout<< decompress(str2);
        outFilede<<decompress(str2);


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
                Count++,i++;
            if(Count>2)
            {
                encoding += '@'+to_string(Count) + input[i];
            }

            else if(Count==2)
            {

                encoding += input[i];
                encoding += input[i];
            }
            else
                encoding += input[i];
        }
    }
    return encoding;

}
string decompress(string Output)
{
    int z;
    string decoding="";
    for (int i=0 ; i<Output.length() ; i++)
    {
        if ( Output[i] == '@')
        {
            z =Output[i+1] - '0' ;
            while (z>0)
            {
                decoding += Output[i+2] ;
                z--;

            }
            i+=2;
        }
        else
        {
            decoding += Output[i] ;
        }

    }
    return decoding;


}
string to_string ( int n )
{
    stringstream ss;
    ss << n;
    return ss.str();
}
