// #include<bits/stdc++.h>
// using namespace std;
namespace io{
template<typename T, typename S> string to_string(pair<T, S>);
    template<typename T> string to_string(vector<T>);
    template<typename other> string to_string(other);
    static bool space = 0;

    // to_string tepmlate

    using std::to_string;
    string to_string(bool x){
        return x ? "true" : "false";
    }

    string to_string(const string s){
        return "\"" + s + "\"";
    }
    string to_string(const char&c){
        string res;
        res += c;
        return "\'" + res + "\'";
    }
    // string to_string(const char*c) {return "\'" + string(c) + "\'";}
    template<typename T, typename S> string to_string(pair<T, S> p){
        return "{" + to_string(p.ff) + ", " + to_string(p.ss) + "}";
    }
    template<typename T> string to_string(vector<T>a){
        string res = "[";
        bool sep = 0;
        for(T i : a){
            if(sep) res += ", ";
            sep=1;
            res += to_string(i);
        }
        res += "]";
        return res;
    }
    template<typename other> string to_string(other oth){
        string res = "[";
        bool spac = 0;
        for(auto i : oth) {
            if(spac) res += ", ";
            spac = 1;
            res += to_string(i);
        }
        return res + "]";
    }
    void print(){
        cout << '\n';
        space = 0;
    }
    template<typename main, typename... sec> void print(main m, sec... oth){
        if(space) cout << " | ";
        space = 1;
        cout << to_string(m);
        print(oth...);
    }
}
using namespace io;
#define print(x...) cout << "{" << #x << "}: ";io::print(x);