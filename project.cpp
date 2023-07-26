 
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define quicky ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rex(n) for(int i = 0; i < n; i++)
#define endl "\n"
#define d 256
#define q 1000
 
int main(){
    vector < int > hash(1000,0);
    string text;
    string ignore;
    float count = 0;
    float tot=0;
    float tat=0;
    bool br = false;
 
    ifstream file("in.txt");              // Source Text
    ifstream bfile("out.txt");            // Plagiarized Text
    ifstream igfile("ignore.txt");        // Ignore Text
 
    while (file >> text)
    {
        int t=0;
        int m = text.length();
 
        if(text[m-1]=='s' || text[m-1] == 'S'){            // omitting s from text (example toys and toy)
            m=m-1;
        }
        
        while(igfile >> ignore){                           // ignoring commen text
            if(text == ignore){
                br = true;
            }
        }
        if(br) continue;

        tot++;   
 
        for (int i = 0; i < m; i++)
        {   
            if(text[i] < 91){
                text[i] = (char)(text[i]+32);             // converting all uppercase to lower case
            }
 
            t = (d * t + text[i]) % q ;                   // calculating hash value of each text
        }
 
        hash[t]++;                                        // incrementing value in hash table
    }
    while(bfile >> text){
        int t=0;
        tat++;
        int m = text.length();
 
 
        if(text[m-1]=='s' || text[m-1] == 'S'){
            m=m-1;
        }
 
 
        for (int i = 0; i < m; i++)
        {
            if(text[i] < 91){
                text[i] = (char)(text[i]+32); 
            }
 
            t = (d * t + text[i]) % q;
        }
 
 
        if(hash[t]>0){                                    // checking the hash table to count the similar words                    
            count++;
        }
    }
 
    cout<<endl<<"percent match = "<<fixed<<setprecision(4)<<(count/max(tot,tat))*100;
} 