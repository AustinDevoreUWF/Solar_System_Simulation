SFML_HOME = /c/SFML-3.0.2

physics_sim.exe: main.cpp vector2D.hpp Physics.hpp
	g++ main.cpp vector2D.hpp Physics.hpp -o physics_sim.exe \
		-I$(SFML_HOME)/include \
		-L$(SFML_HOME)/lib \
		-lsfml-graphics -lsfml-window -lsfml-system

	cp $(SFML_HOME)/bin/*.dll .
