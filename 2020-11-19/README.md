### Learnings

1. Structure of a C++ Program and The Compilation Mechanism
2. Abstract Data Types vs Data Structures
3. Stack and It's Implementation in C++
4. Problem: Determine if parantheses in a string are balanced or not. (C++)

---

#### Structure of a C++ Program

A C++ Program is typically composed of three distinct parts:
* Headers (.h, .hpp, etc.)
* Source Files (.c, .cpp, .cxx, .C etc.)
* Resource Files (.res, .ico, .rc, i18n encoding etc)

Headers need not be stored in a file, but they usually are stored for ease of use and maintenance. They usually contain declarations and definitions (if needed) of C++ entities. They can be used multiple times in a translation unit (Preprocessor + Compilation + Linking).
Source Files contain the implementation of your program, including the special main function that let's you create an executable. They are typically used once in a single translation unit.
Resource files are all other files, which don't contain the programmatic logic but instead might contain the configurations, images, i18n translations and so on.

e.g. A typical hello program can be organized as follows:

1. hello.h
```#ifndef HELLO_H_INC
#define HELLO_H_INC
#include <iostream>

void printHello();
#endif
```

2. hello.cpp
```#include "hello.h"

void printHello()
{
	std::cout << "Hello!" << std::endl;
}
```

3. main.cpp
```#include "hello.h"

int main()
{
	printHello();
	return 0;
}
```

In this example the declaration for the printHello() function is stored in hello.h header file. The actual definition of the function is provided in corresponding source file hello.cpp, and the function is invoked in another source file named main.cpp .

#### Compilation Mechanism of the C++ Program (using g++)

The build process of a C++ program is majorly two parts: compilation & linking. It could be said that there are three steps inluding Pre-Processor.
The Compilation Step on a high level view is four individual steps: Lexical Analysis, Syntactic Analysis, Semantic Analysis and Code Generation. The output of this is object code/files.
These object files are linked together along with any other third-party libraries to produce final executables/libraries.

To dive deeper into this build process, it's typically referred as Translation Unit which explains these steps in more detail and providing a uniform picture of the entire build process. It has 9 Phases.

>Phase 1: Mapping of individual bytes to 96 base character set.

>Phase 2: removal of backslash followed by newline character (splicing of physical new line from source code to logical source code line)

>Phase 3: Decomposition into preprocessing tokens, sequences of whitespaces and comments. Comments are subsequently replaced with single whitespace.

>Phase 4: Macro Expansion and Preprocessing Directives' execution. Additionally recursive follow-up of steps 1 through 4 for each file found in include directive. Finally all the preprocessing directives are removed. (Macros are text replacement in simpler terms.)

>Phase 5: Character and String literals, escape sequences and universal characters in source code are converted to execution character set (it could be UTF-8 or Unicode, constraint being that this character set should support 96 base characters)

>Phase 6: Adjacent strings are concatenated.

>Phase 7: Each preprocessing token is syntactically and semantically analyzed for correctness of program. It is transalted as single translation unit.

>Phase 8: Translated translation unit from phase 7 is typically an object file and it'c converted as instantiation unit.

>Phase 9: All external entity references are resolved. All these are converted together into an executable image.

Phase 1 through 6 are cosidered as part of Preprocessor. In g++ the output after step 6 can be observed using -E flag.
	e.g. g++ -std=c++14 -E main.cpp | egrep -v '#' | tee main.i
Phase 7 & 8 as Compilation.
Phase 9 is part of Linker's responsibility.

#### Abstract Data Types (ADT) vs Data Structures
The difference between ADT and DS is in the way they are comprehended and who the target audience are. ADT is abstract model for user, which allows them to view the data in terms of what data it contains, what operations are permitted and how these operations behave.

Data structures on the other hand are seen from the implementer's POV, in how the data has to be represented, what methods you will be writing to provide these operations, how will these operations interact and modify the data.

E.g. Stack is an ADT. It has Push and Pop operations. From a user's perspective he only needs to know that these are the data stored and these operations are what will let me access or modify this data. In the implementer's hands it becomes a Data Structure because he needs to consider the internal representation of the data storage. The details that will actual allow the functionality of push and pop.

#### Stack

Linear Structured Data Arranged in a LIFO (Last In First Out) or First In Last Out fashion which additionally provides compulsory operations of PUSH and POP. It might also provide helper operations such as IsEmpty, or Peek, that allow user to either check whether the list is empty or Look at the top most item in the stack respectively.
e.g. Stack of Books Placed on top of each other in a vertical fashion with the constraint being that you can place/remove one book at a time and only at/from the top.


#### Solution to The Problem of checking whether the Parantheses in a string are balanced or not.
Create a stack to hold the parantheses.
Loop through the string.
Each iteration pick one parantheses at a time, if it's closing parantheses, pop the stack and check if it's the corresponding opening paratheses or not.
If the popped parantheses is not the opening parantheses, the string in unbalanced.
If the popped paranthese is matching, but the string iteration has completed and the stack still has items remaining, it's unbalanced.
Else The string is balanced.
