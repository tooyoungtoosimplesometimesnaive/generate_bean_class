## Auto generate bean class for java.

This is 2018 now and there are still lots of applications runnning out there using Bean class for java. You have to create lots of getters and setters. that would be so much pain. With this tool, you'll generate the bean class with comment just instantly.

## Usage.
Sample command:
```
./generate_bean_class test names _l date setting -Setting
```
./generate_bean_class
then first argument is the class name, in the example above, it is `test` (First letter does not need to be uppercase.
then following the class property list, the type of property is `String` by default, if it is another type, then use `-<type_name>`. 
Some shortcuts for some basic types:
-b -boolean -Boolean for `Boolean` type,
-i -int -Integer for `Integer` type,
-d -double -Double for `Double` type,
-s -string -String for `String` type.

If the type is a list of some other type, then add `_l` or `_L` or `_List` to the type. if the type is String, then don't need to write the type name.

so, the sample command read as:
Create a bean class name `Test`, in which have a property `name` of `List<String>` type, and a property `date` with `String` type and property `setting` with type `Setting`.

## Compile.
I think any command that compiles c++11 could work.
I use this:
```
clang++ -Wall -std=c++11 generate_bean_class.cpp -o generate_bean_class
```

## Todo.
Make option that could load specs from a file.
Make error message hints.
