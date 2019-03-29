# Algorithms

```shell
echo "# algorithms" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/puffikru/algorithms.git
git push -u origin master;
```


###Сложность алгоритмов

```cpp
vector<string> strings = ReadStrings();
string joined_string =
    accumulate(begin(strings), end(strings), string());
```
- N = strings.size()
- L — ограничение на длину строк