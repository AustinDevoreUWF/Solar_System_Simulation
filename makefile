SFML_HOME = /c/SFML-3.0.2
LIBS_3D  := -lsfml-window -lsfml-system -lopengl32 -lglu32
CXXFLAGS := -std=c++17

all: 2d 3d

2d: physics_sim.exe
physics_sim.exe: main.cpp vector2D.hpp Physics.hpp initialValues.hpp
	g++ main.cpp vector2D.hpp Physics.hpp initialValues.hpp -o physics_sim.exe \
		-I$(SFML_HOME)/include \
		-L$(SFML_HOME)/lib \
		-lsfml-graphics -lsfml-window -lsfml-system

	cp $(SFML_HOME)/bin/*.dll .

3d: extra_dimension.exe
extra_dimension.exe: main3d.cpp
	g++ main3d.cpp -o extra_dimension.exe \
		-I$(SFML_HOME)/include \
		-L$(SFML_HOME)/lib \
		$(CXXFLAGS) \
		$(LIBS_3D)

clean:
	rm -f *.exe