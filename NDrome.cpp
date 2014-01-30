#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

class Nd
{
public:
    void parseText(string s, string &str, int &n)
    {
         str = s.substr(0, s.find('|'));
         stringstream ss(s.substr(s.find('|') + 1));
         ss >> n;

         //cout << str <<  endl;
         //cout << n << endl;
    }    

    //bool isNd(string s, int n)
    bool isNd(string str)
    {
        string s = "";
        int n = 0;
        parseText(str, s, n);

        if(s == "") 
            return false;
        else
        {
            //record index on test string
            int i = 0;
            int j = s.size();
            while(i <= j )
            {
                string frd = s.substr(i, n);
                string rev = s.substr(j - n, n);
                if(frd != rev)
                    return false;
                else
                {
                    i = i + n;
                    j = j - n;
                }
            }
            return true;
        }
    }
};

int main()
{
    //string ss= "abc|abc";
    //cout << ss.substr(0,3) << endl;
    //cout << ss.substr(ss.size() - 3, 3) << endl;

    Nd nd;
    cout << nd.isNd("abc|1") << endl;
    cout << nd.isNd("abcdedcba|1") << endl;   
    cout << nd.isNd("121212|3") << endl; 
    cout << nd.isNd("123456123456|6") << endl;

    //cout << ss.substr(0, ss.find('|')) << endl;
    //cout << ss.substr(ss.find('|')) << endl;
    return 0;
} 
