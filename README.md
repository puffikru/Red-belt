#Coursera Red belt

Alt-H1
======

Alt-H2
------

```cpp
int main() {
    {
        LOG_DURATION("endl");
        ofstream out("output.txt");
        for (int i = 0; i < 150000; ++i) {
            out << "London is the capital of Great Britain. "
                << "I am travelling down the river"
                << endl;
        }
    }
    {
        LOG_DURATION("'\\n'");
        ofstream out("output.txt");
        for (int i = 0; i < 150000; ++i) {
            out << "London is the capital of Great Britain. "
                << "I am travelling down the river"
                << '\n';
        }
    }
    return 0;
}
```
