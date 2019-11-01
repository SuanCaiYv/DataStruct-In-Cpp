#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
class String
{
private:
    ull _size = 0;
    char *s = nullptr;
public:
    String() = default;
    String(const char *str) {
        ull n = strlen(str);
        this->_size = n;
        this->s = new char(n+1);
        for (ull i = 0; i < n; ++ i) {
            this->s[i] = str[i];
        }
        this->s[n] = '\0';
    }
    String(const String &str) {
        ull n = str._size;
        this->_size = n;
        this->s = new char(n+1);
        for (ull i = 0; i < n; ++ i) {
            this->s[i] = str.s[i];
        }
        this->s[n] = '\0';
    }
    ull size() {
        return this->_size;
    }
    bool empty() {
        return this->_size == 0;
    }
    bool operator<(const String &str) {
        ull len1 = this->_size;
        ull len2 = str._size;
        ull i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (this->s[i] == str.s[j]) {
                ++ i;
                ++ j;
            }
            else return this->s[i] < str.s[j];
        }
        return len1 < len2;
    }
    bool operator>(const String &str) {
        ull len1 = this->_size;
        ull len2 = str._size;
        ull i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (this->s[i] == str.s[j]) {
                ++ i;
                ++ j;
            }
            else return this->s[i] > str.s[j];
        }
        return len1 > len2;
    }
    bool operator==(const String &str) {
        ull len1 = this->_size;
        ull len2 = str._size;
        if (len1 != len2) return false;
        ull i = 0;
        while (i < len1) {
            if (this->s[i] != str.s[i])
                return false;
            ++ i;
        }
        return true;
    }
    friend ostream & operator<<(ostream &os, const String &str) {
        os << str.s;
        return os;
    }
    friend istream & operator >> (istream &is, String &str) {
        char *_s = new char[INT_MAX];
        is >> _s;
        ull n = strlen(_s);
        str._size = n;
        str.s = new char(n+1);
        for (ull i = 0; i < n; ++ i) {
            str.s[i] = _s[i];
        }
        str.s[n] = '\0';
        delete[] _s;
        return is;
    }
    String operator+(const String &str) {
        ull n1 = this->_size;
        ull n2 = str._size;
        char *s = new char(n1+n2+1);
        for (ull i = 0; i < n1; ++ i) {
            s[i] = this->s[i];
        }
        for (ull i = n1; i < n1+n2; ++ i) {
            s[i] = str.s[i-n1];
        }
        s[n1+n2] = '\0';
        String _str(s);
        return _str;
    }
    String operator+=(const String &str) {
        ull n1 = this->_size;
        ull n2 = str._size;
        char *s = new char(n1+n2+1);
        for (ull i = 0; i < n1; ++ i) {
            s[i] = this->s[i];
        }
        for (ull i = n1; i < n1+n2; ++ i) {
            s[i] = str.s[i-n1];
        }
        s[n1+n2] = '\0';
        String _str(s);
        this->s = s;
        this->_size = n1+n2;
        return _str;
    }
    String operator=(const String &str) {
        ull n = str._size;
        this->_size = n;
        this->s = new char(n+1);
        for (ull i = 0; i < n; ++ i) {
            this->s[i] = str.s[i];
        }
        this->s[n] = '\0';
        return *this;
    }
    String substr(ull from, ull len) {
        ull n = this->_size;
        if (from >= n) {
            cerr << "Index Out Of Bound";
        }
        if (len+from-1 >= n) {
            char *s = new char(len+1);
            for (ull i = from; i < n; ++ i) {
                s[i-from] = this->s[i];
            }
            s[n-from] = '\0';
            String string1(s);
            return string1;
        }
        else {
            char *s = new char(len+1);
            for (ull i = from; i < len+from; ++ i) {
                s[i-from] = this->s[i];
            }
            s[len] = '\0';
            String string1(s);
            return string1;
        }
    }
    String substr(ull from) {
        ull n = this->_size;
        if (from >= n) {
            cerr << "Index Out Of Bound";
        }
        char *s = new char(n-from+1);
        for (ull i = from; i < n; ++ i) {
            s[i-from] = this->s[i];
        }
        s[n-from] = '\0';
        String string1(s);
        return string1;
    }
    //字符串查找算法由Sunday算法提供支持
    ull find_index(String &substr) {
        ull len1 = this->_size;
        ull len2 = substr.size();
        ull i = 0, j = 0, k, l, pos = 0;
        while (i < len1 && j < len2) {
            if (this->s[i] != substr.s[j]) {
                k = i+len2;
                for (l = len2-1; l >= 0; -- l) {
                    if (substr.s[l] == this->s[k]) break;
                }
                if (l == -1) {
                    pos = i = k+1;
                    j = 0;
                }
                else {
                    j = 0;
                    pos = i = k-l;
                }
            }
            else {
                ++ i;
                ++ j;
            }
            //cout << i << ' ' << j << endl;
        }
        if (i > len1) return -1;
        return pos;
    }
    //以下由读者自行实现
    bool replace(const String &old_str, const String &new_str) {
        ;
    }
    bool insert(ull index, const String &str) {
        ;
    }
    bool delete_str(const String &str) {
        ;
    }
    bool delete_str(const String &str, ull n) {
        ;
    }
};
int main()
{
    char a[9999];
    String str1;
    String str2;
    cin >> str1 >> str2;
    String str3(str1+str2);
    return 0;
}

