# sorting-algorithms
Collection of some sorting algorithms in C

clone the repo, ```cd sorting-algorithms && make```
run the executable ```./bin/main -s bubble -n 100 -m 100```

### All arguments option
```
  Usage program [-s algorithm name] [-n array_size] [-m <max number>]
  Options:
  -s <algorithm name> -> bubble || merge || quick
  -n <number>         -> any number greater than 10
  -m <number>         -> any  number greater than 10

```

> [!WARNING]
> When you declare values greater than 100 for n, the terminal might get messy because of the array size it'll print.

- [x] A better command line argument
- [x] Merge Sort
- [x] Quick Sort
- [ ] Supress array printing through command line
