# gc_useless_opengl_objects
Some code for study purpose about glut development, such as nurbs modeling, feel free to take a look.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

* To compile you need to have **gcc** (or equivalent) on your machine.  
* You need to have freeglut development package.
```
$ sudo dnf install freeglut-devel
```

### Installing

Type in terminal _(on source folder)_:

```
$ g++ *.cpp -o main -lglut -lGL -lGLU
```

Run the application:

```
$ ./main
```

## Authors

* **Vitor G. Forbrig** - [Forbrig](https://github.com/Forbrig)
