
make.x : main.o DepGraph.o GraphNode.o MakeTree.o systemInterface.o Token.o Tokenizer.o TreeNode.o
	g++ -std=c++17 main.o DepGraph.o GraphNode.o MakeTree.o systemInterface.o Token.o Tokenizer.o TreeNode.o -o make.x

main.o: main.cpp DepGraph.hpp
	g++ -std=c++17 main.cpp -o main.o -c

DepGraph.o: DepGraph.cpp DepGraph.hpp MakeTree.hpp Tokenizer.hpp systemInterface.hpp
	g++ -std=c++17 DepGraph.cpp -o DepGraph.o -c

MakeTree.o: MakeTree.cpp MakeTree.hpp TreeNode.hpp
	g++ -std=c++17 MakeTree.cpp -o MakeTree.o -c

Tokenizer.o: Tokenizer.cpp Tokenizer.hpp Token.hpp
	g++ -std=c++17 Tokenizer.cpp -o Tokenizer.o -c

Token.o: Token.cpp Token.hpp
	g++ -std=c++17 Token.cpp -o Token.o -c

systemInterface.o: systemInterface.cpp systemInterface.hpp
	g++ -std=c++17 systemInterface.cpp -o systemInterface.o -c

TreeNode.o: TreeNode.cpp TreeNode.hpp GraphNode.hpp
	g++ -std=c++17 TreeNode.cpp -o TreeNode.o -c

GraphNode.o: GraphNode.cpp GraphNode.hpp systemInterface.hpp
	g++ -std=c++17 GraphNode.cpp -o GraphNode.o -c

clean:
	rm -f main.o DepGraph.o GraphNode.o MakeTree.o systemInterface.o Token.o Tokenizer.o TreeNode.o make.x
