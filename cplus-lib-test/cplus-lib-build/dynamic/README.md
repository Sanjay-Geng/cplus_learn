## build step
```shell
g++ -c -fPIC test.cpp -o mylib.o
g++ -shared mylib.o -o libmylib.so
```

## 带版本号

```shell
g++ -shared -Wl,-soname,libmylib.so.1 -o libmylib.so.1 mylib.o
ln -s libmylib.so.1 libmylib.so
```

