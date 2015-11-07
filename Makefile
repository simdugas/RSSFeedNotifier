all:
	g++ -o RSSParser -g RSSParser.cpp tinyxml2.cpp
clean:
	rm -rf a.out a.out* *.o RSSParser RSSParser.dSYM
