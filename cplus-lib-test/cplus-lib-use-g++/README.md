## use static library

```shell
g++ main.cpp -I include -L lib -lmylib -o run_static
```

## use dynamic library

```shell
 g++ main.cpp -I include -L libso -lmylib -o run_dynamic
```



## need to set ld path before running

##### on mac:

```shell
export DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:/path/to/cplus-lib-use-base/libso
```

#### on linux

```shell
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/cplus-lib-use-base/libso
```

Then run ./run_dynamic

