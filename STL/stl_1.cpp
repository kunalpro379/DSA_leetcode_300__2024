#include <iostream>
#include <utility> 
using namespace std;

int main() {
    
    pair<pair<string, int>, pair<string, int>> crushPairs;

    
    crushPairs = make_pair(make_pair("kunal", 2003), make_pair("sneha", 2003));

    
    crushPairs.first.first = "kunal";  
    crushPairs.first.second = 2003;    
    crushPairs.second.first = "shravani";
    crushPairs.second.second = 2005;

    cout << crushPairs.first.first << " " << crushPairs.first.second << endl;
    cout << crushPairs.second.first << " " << crushPairs.second.second << endl;

    return 0;
}
