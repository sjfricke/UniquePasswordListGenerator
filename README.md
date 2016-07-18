# UniquePasswordListGenerator

This is a simple password generator written in C

**REQUIRES GCC** - only tested compiler

The idea behind this is to generate a list of passwords really fast that are all unqiue and can vary in length

## Parameters

- ```<outputFileName>``` 
  - This is where you name the file you want to output
- ```[numberOfPasswords]``` (optional)
  - enter the number of passwords you want between 1 and 1,000,000
  - default is at 256
- ```[PasswordLength]``` (optional)
  - Enter the length of each password from 1 - 9
  - default is 6

**NOTE** errors will be thrown if the combination of passwords and length are impossible

## Current Support list

-JSON

### How to use JSON
First thing to do is download the JSON_generator along with makefile and open up a terminal or command line

**FOR LINUX**

```
cd to/the/path/of/files
make
./JSON_generator <outputFileName> [numberOfPasswords] [PasswordLength]
```

**FOR WINDOWS**

```
cd to/the/path/of/files
mingw32-make
JSON_generator.exe <outputFileName> [numberOfPasswords] [PasswordLength]
```

**EXAMPLE**

``` JSON_generator.exe passwordList.json 1024 7 ```
This will create 1024 passwords of 7 digits long in a file called passwordList.json
