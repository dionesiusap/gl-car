CC = g++
LIBPATH = glut32.dll
LIB = -lopengl32 -lglu32 -lglut32
MAIN = src/main.cpp

ellen: $(MAIN)
	$(CC) -Wall $(MAIN) $(LIBPATH) $(LIB) -o main

nic: $(MAIN)
	D:\Programs\MinGW\bin\g++ -Wall $(MAIN) $(LIBPATH) $(LIB) -o main