SFML_HOME = /c/SFML-3.0.2
LIBS_3D  := -lsfml-window -lsfml-system -lopengl32 -lglu32
CXXFLAGS := -std=c++17

all: 2d 3d

2d: 2ds.exe
2ds.exe: main.cpp vector2D.hpp Physics.hpp initialValues.hpp
	g++ main.cpp vector2D.hpp Physics.hpp initialValues.hpp -o 2ds.exe \
		-I$(SFML_HOME)/include \
		-L$(SFML_HOME)/lib \
		-lsfml-graphics -lsfml-window -lsfml-system

	cp $(SFML_HOME)/bin/*.dll .

3d: 3ds.exe
3ds.exe: main3d.cpp vector3D.hpp initialValues3D.hpp immediateC.hpp Physics3D.hpp
	g++ main3d.cpp vector3D.hpp initialValues3D.hpp immediateC.hpp Physics3D.hpp -o 3ds.exe \
		-I$(SFML_HOME)/include \
		-L$(SFML_HOME)/lib \
		$(CXXFLAGS) \
		$(LIBS_3D)

clean:
	rm -f *.exe