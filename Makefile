__start__: obj libs __lines_for_space__ interp __plugin__
	export LD_LIBRARY_PATH="./libs";

obj:
	mkdir obj

libs:
	mkdir libs

__lines_for_space__:
	@echo
	@echo
	@echo
	@echo
	@echo


__plugin__:
	cd plugin; make

CPPFLAGS=-Wall -pedantic -std=c++17 -Iinc
LDFLAGS=-Wall




interp: obj/Set4LibInterfaces.o obj/LibInterface.o obj/xmlinterp.o\
		obj/main.o obj/FileHandler.o obj/Scene.o
	g++ ${LDFLAGS} -o interp  obj/main.o obj/Set4LibInterfaces.o\
					obj/LibInterface.o obj/xmlinterp.o\
					obj/FileHandler.o obj/Scene.o\
					-ldl -lxerces-c

obj/Set4LibInterfaces.o: inc/LibInterface.hh inc/Set4LibInterfaces.hh\
					src/Set4LibInterfaces.cpp
	g++ -c ${CPPFLAGS} -o obj/Set4LibInterfaces.o src/Set4LibInterfaces.cpp

obj/LibInterface.o: inc/LibInterface.hh inc/Interp4Command.hh\
					src/LibInterface.cpp
	g++ -c ${CPPFLAGS} -o obj/LibInterface.o src/LibInterface.cpp

obj/xmlinterp.o: inc/xmlinterp.hh src/xmlinterp.cpp
	g++ -c ${CPPFLAGS} -o obj/xmlinterp.o src/xmlinterp.cpp

obj/FileHandler.o: inc/FileHandler.hh src/FileHandler.cpp
	g++ -c ${CPPFLAGS} -o obj/FileHandler.o src/FileHandler.cpp

obj/Scene.o: inc/Scene.hh src/Scene.cpp
	g++ -c ${CPPFLAGS} -o obj/Scene.o src/Scene.cpp

obj/main.o: src/main.cpp inc/Interp4Command.hh inc/LibInterface.hh\
			inc/xmlinterp.hh
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/* interp core*


clean_plugin:
	cd plugin; make clean

cleanall: clean
	cd plugin; make cleanall
	cd dox; make cleanall
	rm -f libs/*
	find . -name \*~ -print -exec rm {} \;

help:
	@echo
	@echo "  Lista podcelow dla polecenia make"
	@echo 
	@echo "        - (wywolanie bez specyfikacji celu) wymusza"
	@echo "          kompilacje i uruchomienie programu."
	@echo "  clean    - usuwa produkty kompilacji oraz program"
	@echo "  clean_plugin - usuwa plugin"
	@echo "  cleanall - wykonuje wszystkie operacje dla podcelu clean oraz clean_plugin"
	@echo "             oprocz tego usuwa wszystkie kopie (pliki, ktorych nazwa "
	@echo "             konczy sie znakiem ~)."
	@echo "  help  - wyswietla niniejszy komunikat"
	@echo
	@echo " Przykladowe wywolania dla poszczegolnych wariantow. "
	@echo "  make           # kompilacja i uruchomienie programu."
	@echo "  make clean     # usuwa produkty kompilacji."
	@echo
 
