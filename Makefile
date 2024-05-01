PROJECTNAME = boogleProject
OUTPUT_DIR = build

SRC = main.cpp extrafunctions.cpp trienode.cpp listnode.cpp

default:
	g++ $(SRC) -o $(OUTPUT_DIR)/$(PROJECTNAME)
