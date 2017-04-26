// Alanna McEachen
// traversals.cpp

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
	// adjacency matrix
	std::vector<std::vector<bool>> Graph;
	std::vector<char> edges;
	std::string line, srcs, dsts;
	char src, dst;
	int c, edgenum, test, srci, dsti;

	c = std::cin.peek();
	while ( c != EOF )
	{
		getline(std::cin, line);
		edgenum = std::stoi(line);
		std::cout << "third\n";
		for (int i=edgenum; i > 0; i--)
		{
			std::vector<char>::iterator et = edges.begin();
			getline(std::cin, line);
			std::istringstream iss(line);
			getline(iss, srcs, ' ');
			getline(iss, dsts, ' ');
			src = srcs[0];
			dst = dsts[0];
			//srci = src[0]-'A'; // convert to ints
			//dsti = dst[0]-'A';
			//std::cout << i << " here " << edgenum << std::endl;
			if (i == edgenum)
			{
				if (src > dst)
				{
					edges.push_back(dst);
					edges.push_back(src);
				} else if (src < dst) {
					edges.push_back(src);
					edges.push_back(dst);
				}
			} else {
				bool match=false;
				//std::cout << d << " second " << srci << std::endl;
				std::vector<char>::iterator et = edges.begin();
				while (!match && et != edges.end())
				{
					std::cout << *et << " et " << src << " src\n";
					if (src == *et){
						match=true;
					}
					else if (src < *et) 
					{
						edges.insert(et, src);
//						std::cout << *et << " et " << src << " src\n";
						match=true;
					}
					std::advance(et,1);
				}
				std::cout << match << " match and " << src << "\n";
				if (!match) {
					std::cout << "when is this true\n";
					edges.push_back(src);
					
				}
			}
		}
		std::vector<char>::iterator et = edges.begin();
		while (et != edges.end())
		{
			std::cout << *et << " ";
			std::advance(et,1);
		}
		std::cout << "\n";
		getline(std::cin, line);
		test = std::stoi(line);
		for (int i=test; i > 0; i--)
		{
			getline(std::cin, line);
			std::istringstream iss(line);
			getline(iss, srcs, ' ');
			getline(iss, dsts, ' ');
		}
		getline(std::cin, line); // should just be whitespace
		c = std::cin.peek();
		
	}
	return 0;
}
