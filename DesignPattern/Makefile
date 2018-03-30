cc=g++

DesignPattern.exe: DesignPattern.o Singleton.o\
					SimpleFactory.o FactoryMethod.o AbstractFactory.o Builder.o\
					Profession.o\
					Mouse.o Keyboard.o Host.o Monitor.o Computer.o
	$(cc) -o DesignPattern.exe DesignPattern.o Singleton.o\
					SimpleFactory.o FactoryMethod.o AbstractFactory.o Builder.o\
					Profession.o\
					Mouse.o Keyboard.o Host.o Monitor.o Computer.o

DesignPattern.o: DesignPattern.cpp Singleton.h FactoryMethod.h Builder.h
	$(cc) -c DesignPattern.cpp

Builder.o: Builder.cpp Builder.h
	$(cc) -c Builder.cpp

Singleton.o: Singleton.cpp Singleton.h
	$(cc) -c Singleton.cpp 

Profession.o: Profession.cpp Profession.h
	$(cc) -c Profession.cpp

SimpleFactory.o: SimpleFactory.cpp SimpleFactory.h Profession.h
	$(cc) -c SimpleFactory.cpp

FactoryMethod.o: FactoryMethod.cpp FactoryMethod.h Profession.h
	$(cc) -c FactoryMethod.cpp

AbstractFactory.o: AbstractFactory.cpp AbstractFactory.h
	$(cc) -c AbstractFactory.cpp

Mouse.o: Mouse.cpp Mouse.h
	$(cc) -c Mouse.cpp

Keyboard.o: Keyboard.cpp Keyboard.h
	$(cc) -c Keyboard.cpp

Monitor.o: Monitor.cpp Monitor.h
	$(cc) -c Monitor.cpp

Host.o: Host.cpp Host.h
	$(cc) -c Host.cpp

Computer.o: Computer.cpp Computer.h
	$(cc) -c Computer.cpp

clean: 
	rm *.o 


